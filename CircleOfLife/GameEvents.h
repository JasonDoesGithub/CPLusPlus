#ifndef GAME_EVENTS_H
#define GAME_EVENTS_H

#include <string>
#include <vector>
#include <fstream>

using namespace std;

class GameEvents
{
private:
    vector<int> event_path_types;    // 0 = cub training, 1 = pride lands, 2 = either
    vector<int> event_advisor_types; // 0 = none, 1-5 = specific advisor
    vector<int> event_point_changes; // points lost or gained
    string lineRiddles[3][2] = {};
    string lineEvents[5][4] = {};
    int riddleIndex = 0;
    int riddleCounter = 0;
    int eventIndex = 0;
    int eventCounter = 0;

public:
    GameEvents();

    bool didItLoad;

    // File loading functions
    bool loadRiddlesFromFile(string filename);
    bool loadEventsFromFile(string filename);

    // Riddle functions
    string getRandomRiddle();
    bool checkRiddleAnswer(string answer);
    int getRiddleIndex(); // Returns random valid index for riddles

    // Event functions
    int getRandomEvent();
    int returnPrideChangeFromEvent();
    // Helper functions
    int getNumRiddles() const;
    int getNumEvents() const;
    bool shouldEventAffectPlayer(int playerPath, int playerAdvisor);
};

#endif