
#ifndef BOARD_H
#define BOARD_H
#include "Tile.h"
#include "GameEvents.h"
#include <string>
#include "Player.h"
using namespace std;

class Board
{
private:
    static const int _BOARD_SIZE = 52; // Length of each track
    Tile _tiles[2][_BOARD_SIZE];       // 2D array for two possible paths
    static const int _MAX_PLAYERS = 2;
    int _player_count;
    Player _players[_MAX_PLAYERS];
    int _player_position[_MAX_PLAYERS]; // Track position of each player
    int _player_path[_MAX_PLAYERS];     // Track which path each player chose (0 for Cub Training, 1 for Pride Lands)
    void displayTile(int path_index, int pos);
    void initializeTiles(int path_index);
    bool isPlayerOnTile(int player_index, int pos);
    GameEvents game_events;
    void handleTileEvent(int player_index);

public:
//hopefully all of these are self explanitry 
    Board();
    Board(int player_count);
    void initializeBoard();
    void displayBoard();
    bool setPlayerPath(int player_index, string path_choice);
    int getPlayerPath(int player_index) const;
    int movePlayer(int player_index);
    int getPlayerPosition(int player_index) const;
    bool movePlayerVisible(int player_index);
    Player getPlayer(int index) const;
    void updatePlayer(int index, Player updated_player);
    void calculateFinalScores();
    int getPlayerCount() const { return _player_count; }
    int movePlayerBack(int player_index);
};

#endif