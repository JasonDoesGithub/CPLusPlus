
#include "Board.h"
#include "Player.h"
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
// color definitions
#define RED "\033[48;2;230;10;10m"
#define GREEN "\033[48;2;34;139;34m"
#define BLUE "\033[48;2;10;10;230m"
#define PINK "\033[48;2;255;105;180m"
#define BROWN "\033[48;2;139;69;19m"
#define PURPLE "\033[48;2;128;0;128m"
#define ORANGE "\033[48;2;230;115;0m"
#define GREY "\033[48;2;128;128;128m"
#define RESET "\033[0m"
using namespace std::this_thread;
using namespace std::chrono_literals;

// PLAYER HANDELING STUFF BECAUSE WE CANNOT USE GLOBAL VARIABLES AND PASS BY REFRENCE AND POINTERS (IM not Salty) :'( -EDIT: APPARENTLY GLOBAL VARIABLES ARE A CODING NO-NO so im not salty anymore...
Player Board::getPlayer(int index) const
{
    return _players[index];
}

void Board::updatePlayer(int index, Player updated_player)
{
    _players[index] = updated_player;
}

void Board::calculateFinalScores()
{
    cout << "\n=== FINAL SCORES ===\n"
         << endl;
    ofstream outputFile("game_results.txt");
    if (!outputFile.is_open())
    {
        cout << "Could not open output file." << endl;
        return;
    }
    outputFile << "=== THE CIRCLE OF LIFE - GAME RESULTS ===\n"
               << endl;

    int finalScores[_MAX_PLAYERS];
    for (int i = 0; i < _player_count; i++)
    {
        Player currentPlayer = _players[i];
        int strengthBonus = (currentPlayer.getStrength() / 100) * 1000;
        int staminaBonus = (currentPlayer.getStamina() / 100) * 1000;
        int wisdomBonus = (currentPlayer.getWisdom() / 100) * 1000;
        int totalScore = currentPlayer.getPridePoints() + strengthBonus + staminaBonus + wisdomBonus;
        finalScores[i] = totalScore;
        outputFile << "Player " << (i + 1) << " (" << currentPlayer.getName() << "):" << endl;
        outputFile << "Base Pride Points: " << currentPlayer.getPridePoints() << endl;
        outputFile << "Strength Bonus: " << strengthBonus << " (from " << currentPlayer.getStrength() << " Strength)" << endl;
        outputFile << "Stamina Bonus: " << staminaBonus << " (from " << currentPlayer.getStamina() << " Stamina)" << endl;
        outputFile << "Wisdom Bonus: " << wisdomBonus << " (from " << currentPlayer.getWisdom() << " Wisdom)" << endl;
        outputFile << "Total Score: " << totalScore << "\n"
                   << endl;
        cout << "Player " << (i + 1) << " (" << currentPlayer.getName() << "):" << endl;
        cout << "Base Pride Points: " << currentPlayer.getPridePoints() << endl;
        cout << "Strength Bonus: " << strengthBonus << " (from " << currentPlayer.getStrength() << " Strength)" << endl;
        cout << "Stamina Bonus: " << staminaBonus << " (from " << currentPlayer.getStamina() << " Stamina)" << endl;
        cout << "Wisdom Bonus: " << wisdomBonus << " (from " << currentPlayer.getWisdom() << " Wisdom)" << endl;
        cout << "Total Score: " << totalScore << "\n"
             << endl;
    }
    int maxScore = finalScores[0];
    int winnerIndex = 0;
    bool tie = false;

    for (int i = 1; i < _player_count; i++)
    {
        if (finalScores[i] > maxScore)
        {
            maxScore = finalScores[i];
            winnerIndex = i;
            tie = false;
        }
        else if (finalScores[i] == maxScore)
        {
            tie = true;
        }
    }

    string finalResult = "\n=== FINAL RESULTS ===\n\n";
    if (tie)
    {
        finalResult += "The game ends in a tie!\n";
    }
    else
    {
        finalResult += "The winner is " + _players[winnerIndex].getName() +
                       " with " + to_string(maxScore) + " Pride Points!\n";
    }
    finalResult += "\nThank you for playing The Circle of Life!\n";

    cout << finalResult;
    outputFile << finalResult;
     
    time_t now = time(0);

    
    tm* localtm = localtime(&now);

    
    outputFile << "Current date and time: " << asctime(localtm) << std::endl;

    outputFile.close();
}

// initializes the board by initializing tiles for each path
void Board::initializeBoard()
{
    // Initialize both paths
    for (int i = 0; i < 2; i++)
    {                       // forloop looping through both players
        initializeTiles(i); // calls initializeTiles function
    }
}
// initialize tiles function
void Board::initializeTiles(int path_index)
{                                                  // uses an int value for the pass index.
    Tile temp;                                     // tile object created to be a temp tile until it is loaded into the array
    int special_count = 0;                         // a int for special tiles used later to make sure there isnt more than max specified special tiles
    int total_tiles = _BOARD_SIZE;                 // total tiles integer set to the previously decided board size
    int max_special = (path_index == 0) ? 20 : 29; // Cub Training: 20 special tiles, Pride Lands: 29 special tiles

    // First tile is always grey (start)
    temp.color = 'Y';             // the object of tiles color is set to grey
    _tiles[path_index][0] = temp; // sets the tile array as the first tile to be temp which is the starter tile

    // Last tile is always orange (Pride Rock)
    temp.color = 'O';                           // same thing as before but for the ending tile
    _tiles[path_index][total_tiles - 1] = temp; // sets the end tile as orange

    // Fill middle tiles
    for (int i = 1; i < total_tiles - 1; i++)
    {
        int random_val = rand() % 100; // Generate number between 0-99

        // Different distribution rules for each path
        if (path_index == 0)
        { // Cub Training Path
            if (special_count < max_special && random_val < 40)
            { // 40% chance for special tile
                int special_type = rand() % 8;
                switch (special_type)
                {
                case 0:
                    temp.color = 'B';
                    break; // Blue - Oasis
                case 1:
                    temp.color = 'B';
                    break; // Blue - Oasis
                case 2:
                    temp.color = 'P';
                    break; // Pink - Counseling
                case 3:
                    temp.color = 'R';
                    break; // Red - Graveyard
                case 4:
                    temp.color = 'R';
                    break; // Red - Graveyard
                case 5:
                    temp.color = 'N';
                    break; // Brown - Hyenas
                case 6:
                    temp.color = 'N';
                    break; // Brown - Hyenas
                case 7:
                    temp.color = 'U';
                    break; // Purple - Challenge
                case 8:
                    temp.color = 'U';
                    break; // Purple - Challenge
                }
                special_count++;
            }
            else
            {
                temp.color = 'G'; // Green - Regular tile
            }
        }
        else
        { // Pride Lands Path more special tiles
            if (special_count < max_special && random_val < 55)
            { // 55% chance for special tile
                int special_type = rand() % 5;
                switch (special_type)
                {
                case 0:
                    temp.color = 'B';
                    break;
                case 1:
                    temp.color = 'P';
                    break;
                case 2:
                    temp.color = 'R';
                    break;
                case 3:
                    temp.color = 'N';
                    break;
                case 4:
                    temp.color = 'U';
                    break;
                }
                special_count++;
            }
            else
            {
                temp.color = 'G'; // every remaiing tile thats not special is set to green
            }
        }
        _tiles[path_index][i] = temp; // once the logic is completed, the temp tile that was decided above is put in the tile array which will be the path
    }
}
// function for allowing the specified player to choose what path to be on
bool Board::setPlayerPath(int player_index, string path_choice)
{
    if (player_index >= 0 && player_index < _player_count)
    {
        if (path_choice == "Cub Training" || path_choice == "1")
        {
            _player_path[player_index] = 0;
            return true;
        }
        else if (path_choice == "Pride Lands" || path_choice == "2")
        {
            _player_path[player_index] = 1;
            return true;
        }
    }
    return false;
}
// function to return the path of the specified player.
int Board::getPlayerPath(int player_index) const
{
    if (player_index >= 0 && player_index < _player_count)
    {
        return _player_path[player_index];
    }
    return -1;
}

// function to display the tile when given which path and the position of the requested tile.
void Board::displayTile(int path_index, int pos)
{
    string color = "";
    bool player1Here = isPlayerOnTile(0, pos) && _player_path[0] == path_index;
    bool player2Here = (_player_count > 1) && isPlayerOnTile(1, pos) && _player_path[1] == path_index;

    switch (_tiles[path_index][pos].color)
    {
    case 'R':
        color = RED;
        break;
    case 'G':
        color = GREEN;
        break;
    case 'B':
        color = BLUE;
        break;
    case 'U':
        color = PURPLE;
        break;
    case 'N':
        color = BROWN;
        break;
    case 'P':
        color = PINK;
        break;
    case 'O':
        color = ORANGE;
        break;
    case 'Y':
        color = GREY;
        break;
    }
    // displays the player location. Display 1&2 when the players are on the same path and same tile
    if (player1Here && player2Here)
    {
        cout << color << "|1 & 2|" << RESET;
    }
    else if (player1Here)
    {
        cout << color << "|1|" << RESET;
    }
    else if (player2Here)
    {
        cout << color << "|2|" << RESET;
    }
    else
    {
        cout << color << "| |" << RESET;
    }
}
// function for displaying each path.
void Board::displayBoard()
{
    cout << "Cub Training Path:" << endl;
    for (int i = 0; i < _BOARD_SIZE; i++)
    { // loops through each tile by calling the display tile for each tile in the max size of the path
        displayTile(0, i);
    }
    cout << endl
         << endl;

    cout << "Pride Lands Path:" << endl;
    for (int i = 0; i < _BOARD_SIZE; i++)
    {
        displayTile(1, i);
    }
    cout << endl;
}
// function for moving the player and checking if the player has won and checking the events and handleing them
int Board::movePlayer(int player_index)
{
    if (player_index >= 0 && player_index < _player_count)
    {
        // Move one space
        _player_position[player_index]++;
        _players[player_index].age++;

        // Check if player reached the end
        if (_player_position[player_index] >= _BOARD_SIZE - 1)
        {
            _player_position[player_index] = _BOARD_SIZE - 1;
            return 3; // Game over - player reached the end
        }

        // Get current tile color and handle its event
        int current_pos = _player_position[player_index];
        int current_path = _player_path[player_index];
        char current_tile_color = _tiles[current_path][current_pos].color;
        int choice2;
        bool correctChoice = false;

        switch (current_tile_color)
        {
        case 'B': // Blue - Oasis tile
            // if (!_players[player_index].extraTurn){
            cout << "\nYou found an Oasis!" << endl;
            cout << "You gain an extra turn and +200 to all stats!" << endl;
            _players[player_index].addStats(200);

            system("Pause");
            _players[player_index].extraTurn = true;
            return 2;
            //}else{
            // cout << "You are already full from the first Oasis!" << endl;
            //_players[player_index].extraTurn = false;
            // system("Pause");
            //}

            break;

        case 'P': // Pink - Counseling tile
            cout << "\nWelcome to the Counseling Grounds!" << endl;
            cout << "+300 to all stats and you may choose an advisor!" << endl;

            _players[player_index].addStats(300);
            system("pause");
            _players[player_index].displayAdvisors();
            break;

        case 'R': // Red - Graveyard tile
            cout << "\nOh no! You've entered the Graveyard!" << endl;
            cout << "Move back 10 spaces and lose 100 from all stats!" << endl;
            _players[player_index].removeStats(100);
            system("Pause");
            _player_position[player_index] = max(0, _player_position[player_index] - 10);
            break;

        case 'N': // Brown - Hyenas tile
            cout << "\nHyenas are on the prowl!" << endl;
            cout << "Return to your previous position and lose 300 stamina!" << endl;
            _player_position[player_index] = max(0, _player_position[player_index] - 1);

            system("Pause");
            break;

        case 'U': // Purple - Challenge tile
        {
            int riddle_index = game_events.getRiddleIndex();
            string riddle = game_events.getRandomRiddle();
            cout << "\nRiddle: " << riddle << endl;

            string answer;
            cout << "Your answer: " << endl;
            // cin.ignore();  // Clear any leftover newlines
            getline(cin, answer);

            if (game_events.checkRiddleAnswer(answer))
            {
                cout << "Correct! +500 Wisdom!" << endl;
                _players[player_index].addWisdom(500);
            }
            else
            {
                cout << "Incorrect!" << endl;
            }
        }
        break;

        case 'G': // Green - Random event tile
            if (rand() % 2 + 1 == 1)
            { // 50% chance for event
                int prideChange = game_events.getRandomEvent();
                int playerAdvisor = _players[player_index].getAdvisor();
                int playerPath = _player_path[player_index];
                if (game_events.shouldEventAffectPlayer(playerPath, playerAdvisor))
                {
                    int oldPride = _players[player_index].getPridePoints();
                    _players[player_index].changePride(prideChange);
                    int newPride = _players[player_index].getPridePoints();
                    if (prideChange < 0)
                    {
                        cout << "You lost " << abs(prideChange) << " Pride Points!" << endl;
                        cout << "Your Pride points changed from " << oldPride << " to " << newPride << endl;
                    }
                    else
                    {
                        cout << "You gain " << prideChange << " Pride Points!" << endl;
                        cout << "Your Pride points changed from " << oldPride << " to " << newPride << endl;
                    }
                }
                system("pause");
            }
            break;
        }
    }
    // I wrote this to allow for more cases incase i want to modify the game further

    return 0; // Game continues
}
int Board::movePlayerBack(int player_index)
{
    _player_position[player_index] = max(0, _player_position[player_index] - 1);
    return 0;
}
// default constructor for the board class
Board::Board()
{
    _player_count = 1;
    _player_position[0] = 0;
    _player_path[0] = 0;

    if (!game_events.loadRiddlesFromFile("riddles.txt"))
    {
        cout << "Warning: Could not load riddles file" << endl;
    }
    if (!game_events.loadEventsFromFile("random_events.txt"))
    {
        cout << "Warning: Could not load events file" << endl;
    }

    initializeBoard();
}

// board constructor for the board class with sepcified player count

Board::Board(int player_count)
{
    _player_count = (player_count > _MAX_PLAYERS) ? _MAX_PLAYERS : player_count;

    for (int i = 0; i < _player_count; i++)
    {
        _player_position[i] = 0;
        _player_path[i] = 0;
    }
    if (!game_events.loadRiddlesFromFile("riddles.txt"))
    {
        cout << "Warning: Could not load riddles file" << endl;
    }
    if (!game_events.loadEventsFromFile("random_events.txt"))
    {
        cout << "Warning: Could not load events file" << endl;
    }
    initializeBoard();
}

int Board::getPlayerPosition(int player_index) const
{
    if (player_index >= 0 && player_index < _player_count)
    {
        return _player_position[player_index];
    }
    return -1;
}

bool Board::movePlayerVisible(int player_index)
{
    _player_position[player_index]++;

    // Check if player reached the end
    if (_player_position[player_index] >= _BOARD_SIZE - 1)
    {
        _player_position[player_index] = _BOARD_SIZE - 1;
        return true; // Game over - player reached the end
    }
    return false;
}

bool Board::isPlayerOnTile(int player_index, int pos)
{
    if (player_index >= 0 && player_index < _player_count)
    {
        return (_player_position[player_index] == pos);
    }
    return false;
}
