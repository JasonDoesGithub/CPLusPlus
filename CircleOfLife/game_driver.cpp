//CIRCLE OF LIFE GAME! WRITTEN BY JASON LESTER, FINISHED ON 12/11/2024
#include <iostream>
#include "Board.h"
#include "Player.h"
#include "Utils.h"
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

// Function to simulate rolling a die (1-6)
int rollDie()
{
    return (rand() % 6) + 1;
}

int main()
{
    // Initialize random seed and set up game environment
    bool correctChoice = false;
    using namespace std::this_thread;
    using namespace std::chrono_literals;
    srand(time(0));

    // Welcome message and game initialization
    cout << "=== Welcome to The Circle of Life Board Game ===\n"
         << endl;
    Board game(2);

    // Display welcome art and pause
    printLion();
    system("Pause");
    system("CLS");

    // Variables for game setup
    string choice;
    int intChoice;
    Player temp_player;
    titleScreen();

    // Player 1 setup
    cout << "\nPlayer 1, choose your Character:" << endl;
    temp_player = game.getPlayer(0);
    temp_player.chooseCharacter();
    game.updatePlayer(0, temp_player);
    system("CLS");
    while (!correctChoice)
    {
        cout << "\nPlayer 1, choose your path:" << endl;
        cout << "1. Cub Training" << endl;
        cout << "2. Pride Lands" << endl;
        cout << "Enter choice (1 or 2): ";
        cin >> choice;
        if (choice == "1" || choice == "2")
        {
            correctChoice = true;
        }
        else
        {
            cout << "Invalid input" << endl;
            correctChoice = false;
            sleep_for(500ms);
            system("CLS");
        }
    }
    game.setPlayerPath(0, choice);

    // Stat changes based on path choice for Player 1
    temp_player = game.getPlayer(0);
    if (choice == "1") // Cub Training
    {
        temp_player.changePride(-5000);
        temp_player.setStrength(temp_player.getStrength() + 500);
        temp_player.setStamina(temp_player.getStamina() + 500);
        temp_player.setWisdom(temp_player.getWisdom() + 1000);
    }
    else if (choice == "2") // Pride Lands
    {
        temp_player.changePride(5000);
        temp_player.setStrength(temp_player.getStrength() + 200);
        temp_player.setStamina(temp_player.getStamina() + 200);
        temp_player.setWisdom(temp_player.getWisdom() + 200);
    }
    game.updatePlayer(0, temp_player);

    // Handle advisor selection for Player 1 if on Cub Training path
    if (stoi(choice) == 1)
    {

        temp_player = game.getPlayer(0);
        temp_player.displayAdvisors();
        game.updatePlayer(0, temp_player);
    }
    correctChoice = false;
    system("CLS");

    // Player 2 setup
    cout << "\nPlayer 2, choose your Character:" << endl;
    temp_player = game.getPlayer(1);
    temp_player.chooseCharacter();
    game.updatePlayer(1, temp_player);
    system("CLS");
    correctChoice = false;
    while (!correctChoice)
    {
        cout << "\nPlayer 2, choose your path:" << endl;
        cout << "1. Cub Training" << endl;
        cout << "2. Pride Lands" << endl;
        cout << "Enter choice (1 or 2): ";
        cin >> choice;
        if (choice == "1" || choice == "2")
        {
            correctChoice = true;
        }
        else
        {
            cout << "Invalid input" << endl;
            correctChoice = false;
            sleep_for(500ms);
            system("CLS");
        }
    }
    game.setPlayerPath(1, choice);

    // Stat changes based on path choice for Player 2
    temp_player = game.getPlayer(1);
    if (choice == "1") // Cub Training
    {
        temp_player.changePride(-5000);
        temp_player.setStrength(temp_player.getStrength() + 500);
        temp_player.setStamina(temp_player.getStamina() + 500);
        temp_player.setWisdom(temp_player.getWisdom() + 1000);
    }
    else if (choice == "2") // Pride Lands
    {
        temp_player.changePride(5000);
        temp_player.setStrength(temp_player.getStrength() + 200);
        temp_player.setStamina(temp_player.getStamina() + 200);
        temp_player.setWisdom(temp_player.getWisdom() + 200);
    }
    game.updatePlayer(1, temp_player);

    system("CLS");

    // Handle advisor selection for Player 2 if on Cub Training path
    if (stoi(choice) == 1)
    {
        temp_player = game.getPlayer(1);
        temp_player.displayAdvisors();
        game.updatePlayer(1, temp_player);
    }
    system("CLS");

    // Main game loop variables
    int game_over = 0;
    int current_player = 0;
    int choice1;
    int roll;
    bool doneWithSecondlayer = false;
    correctChoice = false;
    int total_finished = 0;
    int sumTraits;
    int remainingAbilities[2] = {3, 3};
    int convertedPoints;
    bool doubleroll = false;
    int turnCounter[2] = {0, 0};
    bool finished_status[2] = {false, false};

    // Main game loop
    while (total_finished < 2)
    {
        // Skip finished players
        if (finished_status[current_player])
        {
            current_player = (current_player + 1) % 2;
            continue;
        }
        if (current_player == 0)
        {
            if (turnCounter[0] <= 3)
            {
                turnCounter[0]++;
            }
            else
            {
                turnCounter[0] = 3;
            }
        }
        else
        {
            if (turnCounter[1] <= 3)
            {
                turnCounter[1]++;
            }
            else
            {
                turnCounter[1] = 3;
            }
        }
        correctChoice = false;
        while (!correctChoice)
        {
            system("CLS");
            cout << "\nPlayer " << current_player + 1 << "'s Turn!\n"
                 << endl;
            temp_player = game.getPlayer(current_player);
            temp_player.displayMenu();

            cin >> choice1;
            switch (temp_player.menuChoice(choice1))
            {
            case 1:

                while (!doneWithSecondlayer)
                {
                    system("CLS");
                    cout << "\nWould you like to convert your stats to pride points?\n1. Yes\n2. No\n"
                         << endl;
                    cin >> choice1;
                    switch (choice1)
                    {
                    case 1:
                        temp_player = game.getPlayer(current_player);
                        sumTraits = temp_player.getStrength() + temp_player.getStamina() + temp_player.getWisdom();
                        convertedPoints = sumTraits / 10;

                        temp_player.setStrength(0);
                        temp_player.setStamina(0);
                        temp_player.setWisdom(0);
                        temp_player.changePride(convertedPoints);
                        game.updatePlayer(current_player, temp_player);
                        cout << "Converted " << sumTraits << " Trait Points into " << convertedPoints << " Pride Points.\n"
                             << endl;
                        system("pause");
                        doneWithSecondlayer = true;
                        break;
                    case 2:
                        doneWithSecondlayer = true;
                        break;
                    default:
                        cout << "Invalid Input" << endl;
                        break;
                    }
                }
                doneWithSecondlayer = false;
                break;
            case 2:
                correctChoice = false;
                system("pause");
                system("CLS");
                break;
            case 4:

                while (!doneWithSecondlayer)
                {
                    system("CLS");
                    cout << "Do you want to: \n\n1. View Your Advisors Ability\n2. Use Your Advisors Ability\n"
                         << endl;
                    cin >> choice1;
                    switch (choice1)
                    {
                    case 1:
                        system("CLS");
                        cout << "Your Advisor:\n"
                             << endl;
                        switch (temp_player.getAdvisor())
                        {

                        case 1:
                            cout << "Rafiki - Invisibility (The ability to become un-seen and allows you to move back one space for 200 stamina.)" << endl;
                            sleep_for(800ms);
                            system("pause");
                            doneWithSecondlayer = true;
                            break;
                        case 2:
                            cout << "Nala - Night Vision (the ability to see clearly in darkness and can grant you 200 stamina every three turns.)" << endl;
                            sleep_for(800ms);
                            system("pause");
                            doneWithSecondlayer = true;
                            break;
                        case 3:
                            cout << "Sarabi - Energy Manipulation (the ability to shape and control the properties of energy and allows you to re-roll three times in one game.)" << endl;
                            sleep_for(800ms);
                            system("pause");
                            doneWithSecondlayer = true;
                            break;
                        case 4:
                            cout << "Zazu - Weather Control (the ability to influence and manipulate weather patterns and can move you back one space three times.)" << endl;
                            sleep_for(800ms);
                            system("pause");
                            doneWithSecondlayer = true;

                            break;
                        case 5:
                            cout << "Sarafina - Super Speed (the ability to run 4x faster than the maximum speed of lions allows you to double your roll for 500 stamina.)" << endl;
                            sleep_for(800ms);
                            doneWithSecondlayer = true;
                            system("pause");
                            break;
                        default:
                            cout << "Invalid Input." << endl;
                            sleep_for(800ms);
                            break;
                        }
                        break;

                        doneWithSecondlayer = true;
                        break;
                    case 2:
                        switch (temp_player.getAdvisor())
                        {

                        case 1:
                            if (temp_player.getStamina() > 200)
                            {
                                cout << "Zazu is moving you back one space!\n"
                                     << endl;
                                temp_player.addStamina(-200);
                                cout << "Your stamina is now: " << temp_player.getStamina() << endl;
                                game.displayBoard();
                                game.movePlayerBack(current_player);
                                sleep_for(800ms);
                                system("cls");
                                cout << "Done!\n"
                                     << endl;
                                game.displayBoard();
                                system("pause");
                            }

                            sleep_for(800ms);
                            system("pause");
                            doneWithSecondlayer = true;
                            break;
                        case 2:
                            if (turnCounter[current_player] == 3)
                            {
                                cout << "Nala Grants you 200 stamina!" << endl;
                                temp_player.addStamina(200);
                            }
                            else
                            {
                                cout << "You gotta wait " << 3 - turnCounter[current_player] << " Turns until you can use this ability!" << endl;
                            }

                            sleep_for(800ms);
                            system("pause");
                            doneWithSecondlayer = true;
                            break;
                        case 3:
                            cout << "Your advisor can be used when you roll!" << endl;
                            sleep_for(800ms);
                            system("pause");
                            doneWithSecondlayer = true;
                            break;
                        case 4:
                            if (remainingAbilities[current_player] > 0)
                            {
                                cout << "Zazu is moving you back one space!\n"
                                     << endl;
                                game.displayBoard();
                                game.movePlayerBack(current_player);
                                sleep_for(800ms);
                                system("cls");
                                cout << "Done!\n"
                                     << endl;
                                game.displayBoard();
                                system("pause");
                            }

                            doneWithSecondlayer = true;

                            break;
                        case 5:
                            if (temp_player.getStamina() > 500)
                            {
                                cout << "Sarafina will double your next roll" << endl;
                                cout << "Your stamina is now: " << temp_player.getStamina() << endl;
                                doubleroll = true;
                            }
                            else
                            {
                                cout << " You dont have enough stamina!" << endl;
                            }

                            sleep_for(800ms);
                            doneWithSecondlayer = true;
                            system("pause");
                            break;
                        default:
                            cout << "Invalid Input." << endl;
                            sleep_for(800ms);
                            break;
                        }
                        break;

                        doneWithSecondlayer = true;
                        break;
                    default:
                        cout << "Invalid Input." << endl;
                        sleep_for(800ms);
                        system("cls");
                        break;
                    }
                }
                doneWithSecondlayer = false;
                correctChoice = false;
                doneWithSecondlayer = false;
                system("CLS");
                break;
            case 3:
                system("CLS");
                cout << "\nPlayer " << current_player + 1 << " You are here:\n"
                     << endl;
                game.displayBoard();
                system("Pause");
                correctChoice = false;
                system("CLS");
                break;
            case 5:
                roll = rollDie();
                cout << "You Rolled a " << roll << endl;
                if (temp_player.getAdvisor() == 3)
                {
                    cout << "\nYour advisor allows you to reroll.\n\nWould you like to use one of your rolls?\n You have: " << remainingAbilities[current_player] << " Rolls Left.\n\n1. Yes\n2. No" << endl;
                    cin >> choice1;
                    if (choice1 == 1)
                    {
                        system("CLS");
                        roll = rollDie();
                        cout << "\nYou Rolled a " << roll << endl;
                    }
                    else
                    {
                        system("CLS");
                    }
                }
                if (doubleroll)
                {
                    roll = roll * 2;
                    cout << "\nYour advisor doubled your roll to: " << roll << endl;
                    doubleroll = false;
                }
                system("Pause");
                cin.get();
                correctChoice = true;
                system("CLS");
                break;
            case 6:
                break;
            default:
                cout << "Invalid Input" << endl;
                correctChoice = false;
                system("CLS");
                break;
            }
            game.updatePlayer(current_player, temp_player);
        }
        doneWithSecondlayer = false;
        // Handle player movement
        game.displayBoard();
        for (int i = 0; i < roll; i++)
        {
            cout << "\n\nMoving!\n\n"
                 << endl;
            sleep_for(500ms);

            if (i < roll - 1)
            {
                game_over = game.movePlayerVisible(current_player);
            }
            else
            {
                game_over = game.movePlayer(current_player);
            }
            sleep_for(500ms);
            system("CLS");
            game.displayBoard();
        }

        if (game_over == 2)
        {

            cout << "\nExtra Roll! \n\n"
                 << endl;
            system("pause");
            roll = rollDie();
            cout << "You Rolled a " << roll << endl;
            sleep_for(1000ms);
            system("CLS");
            game_over = 0;

            for (int i = 0; i < roll; i++)
            {

                cout << "\n\nMoving!\n\n"
                     << endl;
                sleep_for(500ms);

                if (i < roll - 1)
                {
                    game_over = game.movePlayerVisible(current_player);
                }
                else
                {
                    game_over = game.movePlayer(current_player);
                }
                sleep_for(500ms);
                system("CLS");
                game.displayBoard();
            }

            sleep_for(500ms);
            system("CLS");
            game.displayBoard();
        }
        system("Pause");

        // Check if player reached Pride Rock
        if (game_over == 3)
        {
            cout << "\nPlayer " << current_player + 1 << " has reached Pride Rock!" << endl;
            finished_status[current_player] = true;
            total_finished++;
            system("pause");

            if (total_finished >= 2)
            {
                cout << "\nAll players have reached Pride Rock!" << endl;
                game.calculateFinalScores();
                system("Pause");
            }
        }

        // Switch to next player
        current_player = (current_player + 1) % 2;
    }

    // Display final game state
    cout << "\nFinal board state:" << endl;
    game.displayBoard();
    cout << "Press anything to End the Game" << endl;
    getline(cin, choice);

    return 0;
}
