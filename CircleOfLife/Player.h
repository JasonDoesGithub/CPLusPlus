
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
using namespace std;

class Player
{
private:
    // Data Members
    string _name;
    int _strength;
    int _stamina;
    int _wisdom;
    int _pride_points;
    int _age;
    int _advisor = 0;
    int _abilityUsed = 0;

    string _advisorName;

public:
    bool extraTurn = false;
    int age = _age;
    int abilityUsed = _abilityUsed;
    int advisor = _advisor;
    Player();
    Player(string name, int strength, int stamina, int wisdom);

    string getName();
    int getStrength();
    int getStamina();
    int getWisdom();
    int getPridePoints();
    int getAge();
    int getAdvisor() const;

    void setName(string name);
    void setStrength(int strength);
    void setStamina(int stamina);
    void setWisdom(int wisdom);
    void setPridePoints(int pride_points);
    void setAge(int age);
    void setAdvisor(int advisor);

    void trainCub(int strength, int stamina, int wisdom);
    void toPrideLands();
    void printStats();

    void changePride(int pride);
    void addStamina(int stamina);
    int menuChoice(int _choice);
    void addWisdom(int changeInwisdom);
    void displayMenu();
    void chooseCharacter();
    void removeStats(int removeBy);
    void addStats(int addBy);
    void displayAdvisors();
};

#endif