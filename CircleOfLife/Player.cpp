#include "Player.h"
#include <iostream>
#include <fstream>
#include "Utils.h"
#include <ctime>
#include <chrono>
#include <thread>
using namespace std::this_thread;
using namespace std::chrono_literals;
using namespace std;

// Constants for initial value ranges
const int MIN_AGE = 1;
const int MAX_AGE = 20;
const int MIN_STAT = 0;
const int MAX_STAT = 100000;
const int MIN_PRIDE_POINTS = 0;

// Default constructor
Player::Player()
{
    _name = "";
    _strength = MIN_STAT;
    _stamina = MIN_STAT;
    _wisdom = MIN_STAT;
    _pride_points = MIN_PRIDE_POINTS;
    _age = MIN_AGE;
    _advisor = 0;
    _advisorName = "";
}

// Parameterized constructor
Player::Player(string name, int strength, int stamina, int wisdom)
{
    _name = name;

    // Initialize strength
    if (strength >= MIN_STAT && strength <= MAX_STAT)
        _strength = strength;
    else
        _strength = MIN_STAT;

    // Initialize stamina
    if (stamina >= MIN_STAT && stamina <= MAX_STAT)
        _stamina = stamina;
    else
        _stamina = MIN_STAT;

    // Initialize wisdom
    if (wisdom >= MIN_STAT && wisdom <= MAX_STAT)
        _wisdom = wisdom;
    else
        _wisdom = MIN_STAT;

    _pride_points = MIN_PRIDE_POINTS;
    _age = MIN_AGE;
}

// Getter Functions

string Player::getName()
{
    return _name;
}

int Player::getStrength()
{
    return _strength;
}

int Player::getStamina()
{
    return _stamina;
}

int Player::getWisdom()
{
    return _wisdom;
}

int Player::getPridePoints()
{
    return _pride_points;
}

int Player::getAge()
{
    return _age;
}

int Player::getAdvisor() const
{

    return _advisor;
}

// Setter Functions

void Player::setName(string name)
{
    _name = name;
}

void Player::setStrength(int strength)
{
    _strength = (strength >= 0) ? strength : 0;
}

void Player::setStamina(int stamina)
{
    _stamina = (stamina >= 0) ? stamina : 0;
}

void Player::setWisdom(int wisdom)
{
    _wisdom = (wisdom >= 0) ? wisdom : 0;
}

void Player::setPridePoints(int pride_points)
{
    _pride_points = (pride_points >= 0) ? pride_points : 0;
}

void Player::setAge(int age)
{
    if (age >= MIN_AGE && age <= MAX_AGE)
        _age = age;
    else if (age < MIN_AGE)
        _age = MIN_AGE;
    else
        _age = MAX_AGE;
}

void Player::setAdvisor(int advisor)
{
    _advisor = advisor;
    ifstream advisors("advisors.txt");

    int choice;
    string getLine;
    string tempLine = {};
    string lineAdvisors[5][1] = {};

    int indexY = 0;

    if (advisors.fail())
    {
        cout << "Error opening advisors file" << endl;
    }
    while (getline(advisors, getLine))
    {
        lineAdvisors[indexY][0] = getLine;
        indexY++;
    }
    _advisorName = lineAdvisors[advisor - 1][0];
}

// Other Member Functions

void Player::trainCub(int strength, int stamina, int wisdom)
{
    _strength += strength;
    _stamina += stamina;
    _wisdom += wisdom;

    _pride_points -= 5000;
    if (_pride_points < 0)
        _pride_points = 0;
}

void Player::toPrideLands()
{
    _pride_points += 5000;

    _strength -= 2000;
    if (_strength < 0)
        _strength = 0;

    _wisdom -= 2000;
    if (_wisdom < 0)
        _wisdom = 0;

    _stamina -= 1000;
    if (_stamina < 0)
        _stamina = 0;
}

void Player::printStats()
{
    cout << "Player Stats:" << endl;
    cout << "Name: " << _name << endl;
    cout << "Age: " << _age << endl;
    cout << "Strength: " << _strength << endl;
    cout << "Stamina: " << _stamina << endl;
    cout << "Wisdom: " << _wisdom << endl;
    cout << "Pride Points: " << _pride_points << endl;
}

void Player::changePride(int pride)
{
    _pride_points += pride;
    if (_pride_points < MIN_PRIDE_POINTS)
    {
        _pride_points = MIN_PRIDE_POINTS;
    }
    if (_pride_points > MAX_STAT)
    {
        _pride_points = MAX_STAT;
    }
}

void Player::addStamina(int stamina)
{
    _stamina += stamina;
}
void Player::displayMenu()
{

    cout << "Main Menu: Select an option to continue\n"
         << "1. Check Player Progress (1)\n"
         << "2. Review Character (2)\n"
         << "3. Check Position (3)\n"
         << "4. Review your Advisor (4)\n"
         << "5. Move Forward (5)\n"
         << endl;
}

void Player::chooseCharacter()
{

    ifstream characters("characters.txt");

    int choice;
    string getLine;
    string tempLine[6] = {};
    string lineCharacters[5][6] = {};
    bool correctChoice = false;

    int indexY = 0;

    if (characters.fail())
    {
        cout << "Error opening characters file" << endl;
    }
    while (getline(characters, getLine))
    {
        split(getLine, '.', tempLine, 6);
        for (int i = 0; i < 6; i++)
        {
            lineCharacters[indexY][i] = tempLine[i];
        }
        indexY++;
    }

    while (!correctChoice)
    {
        cout << "   | Name:  |  Age:   | Strength: | Stamina: | Wisdom:   | PridePoints: |" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << ": ";
            for (int j = 0; j < 6; j++)
            {

                cout << lineCharacters[i][j] << "     ";
            }
            cout << endl;
        }
        cout << "\n Make a Selection" << "\n"
             << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            setName(lineCharacters[choice - 1][0]);
            setAge(stoi(lineCharacters[choice - 1][1]));
            setStrength(stoi(lineCharacters[choice - 1][2]));
            setStamina(stoi(lineCharacters[choice - 1][3]));
            setWisdom(stoi(lineCharacters[choice - 1][4]));
            setPridePoints(stoi(lineCharacters[choice - 1][5]));
            correctChoice = true;
            break;
        case 2:
            setName(lineCharacters[choice - 1][0]);
            setAge(stoi(lineCharacters[choice - 1][1]));
            setStrength(stoi(lineCharacters[choice - 1][2]));
            setStamina(stoi(lineCharacters[choice - 1][3]));
            setWisdom(stoi(lineCharacters[choice - 1][4]));
            setPridePoints(stoi(lineCharacters[choice - 1][5]));
            correctChoice = true;
            break;
        case 3:
            setName(lineCharacters[choice - 1][0]);
            setAge(stoi(lineCharacters[choice - 1][1]));
            setStrength(stoi(lineCharacters[choice - 1][2]));
            setStamina(stoi(lineCharacters[choice - 1][3]));
            setWisdom(stoi(lineCharacters[choice - 1][4]));
            setPridePoints(stoi(lineCharacters[choice - 1][5]));
            correctChoice = true;
            break;
        case 4:
            setName(lineCharacters[choice - 1][0]);
            setAge(stoi(lineCharacters[choice - 1][1]));
            setStrength(stoi(lineCharacters[choice - 1][2]));
            setStamina(stoi(lineCharacters[choice - 1][3]));
            setWisdom(stoi(lineCharacters[choice - 1][4]));
            setPridePoints(stoi(lineCharacters[choice - 1][5]));
            correctChoice = true;
            break;
        case 5:
            setName(lineCharacters[choice - 1][0]);
            setAge(stoi(lineCharacters[choice - 1][1]));
            setStrength(stoi(lineCharacters[choice - 1][2]));
            setStamina(stoi(lineCharacters[choice - 1][3]));
            setWisdom(stoi(lineCharacters[choice - 1][4]));
            setPridePoints(stoi(lineCharacters[choice - 1][5]));
            correctChoice = true;
            break;
        default:
            cout << "Invalid Choice" << endl;
            sleep_for(500ms);
            system("CLS");
            correctChoice = false;

            break;
        }
    }
}

void Player::removeStats(int removeBy)
{
    _stamina -= removeBy;
    if (_stamina < MIN_STAT)
    {
        _stamina = MIN_STAT;
    }
    _strength -= removeBy;
    if (_strength < MIN_STAT)
    {
        _strength = MIN_STAT;
    }
    _wisdom -= removeBy;
    if (_wisdom < MIN_STAT)
    {
        _wisdom = MIN_STAT;
    }
}
void Player::addStats(int addBy)
{
    _stamina += addBy;
    if (_stamina > MAX_STAT)
    {
        _stamina = MAX_STAT;
    }
    _strength += addBy;
    if (_strength > MAX_STAT)
    {
        _strength = MAX_STAT;
    }
    _wisdom += addBy;
    if (_wisdom > MAX_STAT)
    {
        _wisdom = MAX_STAT;
    }
}

void Player::displayAdvisors()
{
    ifstream advisors("advisors.txt");

    int advisorchoice;
    bool correctChoice = false;
    string getLine;
    string tempLine = {};
    string lineAdvisors[5][1] = {};

    int indexY = 0;

    if (advisors.fail())
    {
        cout << "Error opening advisors file" << endl;
    }
    while (getline(advisors, getLine))
    {
        lineAdvisors[indexY][0] = getLine;
        indexY++;
    }
    system("CLS");

    correctChoice = false;
    while (!correctChoice)
    {
        cout << "Choose your advisor:\n"
             << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << lineAdvisors[i][0] << endl;
        }
        cout << "\nEnter your Choice" << endl;
        cin >> advisorchoice;
        switch (advisorchoice)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            setAdvisor(advisorchoice);
            correctChoice = true;
            break;
        default:
            cout << "Invalid Choice. " << endl;

            sleep_for(800ms);
            // system("Pause");
            system("CLS");

            correctChoice = false;
            break;
        }
    }
}

int Player::menuChoice(int _choice)
{
    int choice = _choice;

    switch (choice)
    {
    case 1:
        system("CLS");
        printStats();
        system("pause");
        return 1;
        break;
    case 2:
        system("CLS");
        cout << "Your name: " << _name << "\nYour age: " << _age << endl;
        return 2;
        break;
    case 3:
        return 3;
        break;
    case 4:
        if (_advisor != 0)
        {
            cout << "Your Advisor is: " << _advisorName << "\n\n"<<endl;
        }
        else
        {
            cout << "You Dont have an Advisor." << endl;
            
            system("Pause");
            return 6;
        }
        // system("pause");
        return 4;
        break;
    case 5:
        return 5;
        break;
    default:
        return 0;
        break;
    }
}

void Player::addWisdom(int changeInwisdom)
{
    if (_wisdom + changeInwisdom > MAX_STAT)
    {
        _wisdom = MAX_STAT;
    }
    else if (_wisdom + changeInwisdom < MIN_STAT)
    {
        _wisdom = MIN_STAT;
    }
    else
    {
        _wisdom += changeInwisdom;
    }
}
