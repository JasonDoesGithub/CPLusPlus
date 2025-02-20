//accel from gravity calc written by Jason lester 2/19/25
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double gravity(double latitude_degs, double altitude_meters)
{
    
    const double DEG2RAD = 3.14159265358979323846 / 180.0;
    double phi = latitude_degs * DEG2RAD;

    
    double sinphi   = sin(phi);
    double sin2phi  = sin(2.0 * phi);

    
    double g0 = 9.780356 * (1.0 + 0.0052884 * (sinphi * sinphi) - 0.0000059 * (sin2phi * sin2phi));

    
    double g = g0 - 3.086e-6 * altitude_meters;

    return g;
}

int main(){

    double lat = 0;
    double alt = 0;
    double grav = 0;
    cout << "Welcome to the gravitational Accel Calculator.\n\nWritten by Jason Lester to do his calc HW\n\n" << endl;

    system("pause");
    system("CLS");

    cout << "Enter the Latitude (in degrees) and the alitude above sea level (in meters)" <<endl;
    cout << "Latitude:" <<endl;
    cin >> lat;
    cout << "Altitude:" <<endl; 
    cin >> alt;

    grav = gravity(lat,alt);

    cout << "Acceleration from gravity at given inputs: " << setprecision(9999999) << grav << " m/s^2" << endl;





}