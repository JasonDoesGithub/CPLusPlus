#include "GameEvents.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cctype>
#include <iostream>
#include "Utils.h"
#include <fstream>
#include "Player.h"

GameEvents::GameEvents()
{

    srand(time(0));
}

bool GameEvents::loadRiddlesFromFile(string filename)
{
    ifstream riddles(filename);

    int choice;
    string getLine;
    string tempLine[2] = {};

    int indexY = 0;

    if (riddles.fail())
    {
        cout << "Error opening riddles file" << endl;
        system("pause");
        return false;
    }
    while (getline(riddles, getLine))
    {
        split(getLine, '|', tempLine, 2);
        for (int i = 0; i < 2; i++)
        {
            lineRiddles[indexY][i] = tempLine[i];
        }
        indexY++;
    }
    return true;
}

bool GameEvents::loadEventsFromFile(string filename)
{
    ifstream event(filename);

    int choice;
    string getLine;
    string tempLine[4] = {};

    int indexY = 0;

    if (event.fail())
    {
        cout << "Error opening event file" << endl;
        return false;
    }
    getline(event, getLine);
    while (getline(event, getLine))
    {
        split(getLine, '|', tempLine, 4);
        for (int i = 0; i < 4; i++)
        {
            lineEvents[indexY][i] = tempLine[i];
        }
        indexY++;
    }
    return true;
}

string GameEvents::getRandomRiddle()
{
    string riddletoReturn;
    riddleIndex = rand() % 3;
    riddletoReturn = lineRiddles[riddleIndex][0];
    riddleCounter++;
    return riddletoReturn;
}

bool GameEvents::checkRiddleAnswer(string answer)
{
    cout << "You said: " << answer << " The answer was: " << lineRiddles[riddleIndex][1] << endl;
    system("pause");
    if (answer == lineRiddles[riddleIndex][1])
    {
        return true;
    }
    else
    {
        return false;
    }
}

int GameEvents::getRiddleIndex()
{
    return riddleIndex;
}

int GameEvents::getRandomEvent()
{
    eventIndex = rand() % 4;

    eventCounter++;
    int eventPathType = stoi(lineEvents[eventIndex][1]);
    string description = lineEvents[eventIndex][0];
    int requiredAdvisor = stoi(lineEvents[eventIndex][2]);
    int prideChange = stoi(lineEvents[eventIndex][3]);
    cout << "\n"
         << description << endl;
    return prideChange;
}

bool GameEvents::shouldEventAffectPlayer(int playerPath, int playerAdvisor)
{
    int eventPathType = stoi(lineEvents[eventIndex][1]);
    int requiredAdvisor = stoi(lineEvents[eventIndex][2]);
    bool pathMatches = ((eventPathType == 2) || (eventPathType == playerPath));
    if (!pathMatches)
    {
        return false;
    }
    if (playerAdvisor == requiredAdvisor)
    {
        cout << "Your advisor helped you avoid this situation!" << endl;
        return false;
    }
    return true;
}

int GameEvents::returnPrideChangeFromEvent()
{

    return stoi(lineEvents[eventIndex][3]);
}

int GameEvents::getNumRiddles() const
{
    return riddleCounter;
}

int GameEvents::getNumEvents() const
{
    return eventCounter;
}