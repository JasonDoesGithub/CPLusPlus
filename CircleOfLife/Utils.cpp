#include "Utils.h"
#include <ctime>
#include <chrono>
#include <thread>
#include <iostream>
#include <cctype>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;

int split(std::string input_string, char separator, std::string arr[], const int ARR_SIZE)
{
     int start = 0;
     int counter = 0;
     if (input_string.length() < 1)
     {
          return 0;
     }
     for (unsigned int i = 0; i < input_string.length(); i++)
     {
          if (counter < ARR_SIZE)
          {
               if (input_string[i] == separator)
               {
                    arr[counter] = input_string.substr(start, i - start);
                    counter++;
                    start = i + 1;
               }
          }
          else
          {
               return -1;
          }
     }
     arr[counter] = input_string.substr(start, input_string.length() - start);
     counter++;
     if (counter == 0)
     {
          arr[0] = input_string;
          return 1;
     }
     return counter;
}

void printLion()
{
     cout << "\n";
     cout << "                                                              ..\n";
     cout << "                                                            ..:::....    ......      .......\n";
     cout << "                                                           .:------:......:-:::.......:---:..\n";
     cout << "                                                           .---++**=-:-==--===-=-..:-=+=---:.. \n";
     cout << "                                                           .:-==+****==---====---==****+*+=-.\n";
     cout << "                                                            :--+*##*+=--::-===---=++#%*++=-:.\n";
     cout << "                                                            .:-=*#++=---:::-=---:-=**##*+--.\n";
     cout << "                                                             ..:=--=--:::::--:::::----+=-:..\n";
     cout << "                                                            ...:==-=--==-------=--:----.\n";
     cout << "                                                           .:=+++====*##*+-----*%*=---.\n";
     cout << "                                                     ....:-==+++**++---=*===---*-----:.\n";
     cout << "                       ....::::......          .....:-======++++**+==---===---------:\n";
     cout << "                     .:===============-:::::::-============+=++++**+===-=+=--------:.\n";
     cout << "                   .:===---------==--=========------======+++===+++**=======------:.\n";
     cout << "                  .:==-------------------=-=-------------=+++=====++++-==#=:-=---...\n";
     cout << "                 .:==-------=---------------------------==+=+=---==+++===-=#=-::-..\n";
     cout << "                 .===-----=--====---------=-----------===++=+=----==++*++*#@#*+-=..\n";
     cout << "               ..-==-------======--------=-------------=++====----==+++*+==-----=..\n";
     cout << "               ..++=-------=======-------------------===++==-------==+++===------\n";
     cout << "               .:=+==--------=+===------------=-=-=-====++==--------======------.\n";
     cout << "               .-=====--------======----------------=-===+++=--------=---=-----:\n";
     cout << "              .:==---=----------=+=====-------------=--====------------==-----:.\n";
     cout << "             .:====---=----:-:----======-=--------------==--------------------.\n";
     cout << "             .===---=-:-:--::::--=---=------------------==--::-----------=---:.\n";
     cout << "           ..++==------:::-----=--:.....:----------------=--:----:-----------..\n";
     cout << "          .:+*==----:---+===----..       ...:-------------=------::-=--:--:::..\n";
     cout << "        ..=**+=--:---++==-----:..               ......   .==----:::----::::::..\n";
     cout << "        :=++=+---:-++==------...                         .-=-----::--::::::::\n";
     cout << "        -===-=---.=+=----:-:..                           ..------:::--:::::::\n";
     cout << "        -===--::. :----:-:..                               :------:::-:::::::..\n";
     cout << "      ..=--::::.  .-:::::.                                 .------::::--::::-..\n";
     cout << "     ..:-:::::.   .::::::.                                  .--:----::-:::::-..\n";
     cout << "    .:#+--:::..   ..::::::..                                .:-------:-:::::-..\n";
     cout << "  ..#%*-:::-::..  ...:::::....                              .:--:-:--:--:::::..\n";
     cout << "  .....---=-==-:.....::-------:...............................:::-----::::::-:.....\n";
     cout << "      .:-=---=-:.....:-=-:---=:...............................::------=--:-------:..\n";
     cout << "      ........................................................::--+---===-=-::::=::.\n";
     cout << "                                                   ...........:.:-::.:::::=::--:-:..\n"
          << endl;
     system("Color 00");
}

void titleScreen()
{
     system("CLS");
     int choice;
     bool choseTutorial = false;
     bool correctChoice = false;

     // choice = (char) toupper(choice);
     while (!correctChoice)

     {
          cout << "================ Circle of Life ================\n\n"
               << endl;
          cout << "\n Do you want to play the tutorial?\n\n1. Yes\n2. No\n"
               << endl;
          cin >> choice;
          switch (choice)
          {
          case 1:
               choseTutorial = true;
               tutorial();
               return;
               break;
          case 2:
               choseTutorial = false;
               correctChoice = true;
               system("CLS");
               break;

          default:
               cout << "Invalid Input" << endl;
               sleep_for(800ms);
               system("CLS");
               break;
          }
     }
     return;
}

void tutorial()
{
     system("CLS");
     cout << "================= Tutorial =================\n\n"
          << endl;
     cout << "\nWelcome to the Circle of Life!" << endl;
     sleep_for(2000ms);
     system("CLS");
     cout << "================= Tutorial =================\n\n"
          << endl;
     cout << "\nYou have entered the tutorial." << endl;
     sleep_for(2000ms);
     system("CLS");
     cout << "================= Tutorial =================\n\n"
          << endl;
     cout << "\nWe will run through a few of the basics so you can get a grip on the game!" << endl;
     sleep_for(2000ms);
     system("CLS");
     cout << "================= Tutorial =================\n\n"
          << endl;
     cout << "\nTry to keep up!" << endl;
     sleep_for(2000ms);
     system("Pause");
     system("CLS");
     cout << "================= Tutorial =================\n\n"
          << endl;
     cout << "\nAlrighty, when you enter the game you will be prompted to pick a character!" << endl;
     sleep_for(2000ms);
     cout << "\nThis is a pretty important decision! It will affect how you will play the game!" << endl;
     sleep_for(2000ms);
     cout << "\nHere is an example:\n\n"
          << endl;
     sleep_for(500ms);
     cout << "| Name:      | Age: | Strength: | Stamina: | Wisdom:   | PridePoints: |" << endl;
     cout << "| PlayerName |   9  |     400   |      300 |      800  |      20000   |\n\n"
          << endl;
     system("Pause");
     system("CLS");

     cout << "================= Tutorial =================\n\n"
          << endl;
     cout << "\nLets run over what each of these stats mean.\n"
          << endl;
     sleep_for(2000ms);
     cout << "     |" << endl;
     cout << "     v" << endl;
     cout << "| Name:      | Age: | Strength: | Stamina: | Wisdom:   | PridePoints: |" << endl;
     cout << "| PlayerName |   9  |     400   |      300 |      800  |      20000   |" << endl;
     cout << "\nThis is your name... I SHOULD'nt have to explain this one.....\n"
          << endl;
     sleep_for(2500ms);
     system("Pause");
     system("CLS");
     cout << "================= Tutorial =================\n\n"
          << endl;
     cout << "                |" << endl;
     cout << "                v" << endl;
     cout << "| Name:      | Age: | Strength: | Stamina: | Wisdom:   | PridePoints: |" << endl;
     cout << "| PlayerName |   9  |     400   |      300 |      800  |      20000   |" << endl;
     cout << "\nThis is your age. While it doesnt play a significant role in the game as of yet, its pretty cool to see this change as you progress.\n"
          << endl;
     sleep_for(2500ms);
     system("Pause");
     system("CLS");
     cout << "================= Tutorial =================\n\n"
          << endl;
     cout << "                          |          |         |              |" << endl;
     cout << "                          v          v         v              v" << endl;
     cout << "| Name:      | Age: | Strength: | Stamina: | Wisdom:   | PridePoints: |" << endl;
     cout << "| PlayerName |   9  |     400   |      300 |      800  |      20000   |" << endl;
     cout << "\nOk, now moving onto the good stuff. Your Stats... These are how you win. In essence. You want a lot of these!\n"
          << endl;
     sleep_for(1200ms);
     cout << "\nYou gain and loose these throughout the game from completing riddles and running into random events. In the end, they all will be added up. The player with the most... WINS!\n"
          << endl;
     sleep_for(2500ms);
     system("pause");
     system("CLS");
     cout << "================= Tutorial =================\n\n"
          << endl;
     cout << "\nNext, You will need to pick a path.\n"
          << endl;
     sleep_for(1000ms);
     cout << "\nYou will pick between the Pridelands and Cub training.\n"
          << endl;

     sleep_for(1000ms);
     cout << "\nCub Training:\n"
          << endl;
     sleep_for(1000ms);
     cout << "This path equips your lion character with essential Leadership Traits: Stamina, Strength and Wisdom\n";
     sleep_for(1500ms);
     cout << "needed for future leadership at the pride rock. This path requires an investemt of 5000 pride points.\n";
     sleep_for(1500ms);
     cout << "Pride points are how you track your progress, they are what you need to win.\n";
     sleep_for(1500ms);
     cout << "This path also grants you an additional 500 Strength, Stamina and 1000 Wisdom.\n";
     sleep_for(1500ms);
     cout << "Points to the starting amount of your character's Leadership Traits before you start the journey. Choosing\n";
     sleep_for(1500ms);
     cout << "this path allows your character to grow and mature, gaining valuable abilities at the expense of early\n";
     sleep_for(1500ms);
     cout << "progress. Although this path slows down your initial Pride Point accumulation, the boost in key traits and\n";
     sleep_for(1500ms);
     cout << "the opportunity to select an advisor for mentorship prepare your character for greater challenges and future ";

     cout << "leadership potential.\n";
     cout << "Advisor Choice: \nIf the player selects Cub Training, they will be prompted to choose an advisor who\n";
     sleep_for(1500ms);
     cout << "grants a unique special ability that protects them during random events that have a negative influence\n";
     sleep_for(1500ms);
     cout << "on their Pride Points (please see Advisor List).\n\n";
     sleep_for(1500ms);
     cout << "Straight to the Pride Lands:\n";
     sleep_for(1500ms);
     cout << "This option lets your lion character jump directly into life on the Savannah with an immediate boost of\n";
     sleep_for(1500ms);
     cout << "+5,000 Pride Points from the starting number of Pride Points, allowing early progression and quick success\n";
     sleep_for(1500ms);
     cout << "in achieving intermediate goals. This path adds 200 Stamina Points, 200 Strength Points, and 200 Wisdom\n";
     sleep_for(1500ms);
     cout << "Points to the starting amount of your character's Leadership Traits before you start the journey, leaving your\n";
     sleep_for(1500ms);
     cout << "character with fewer resources to prepare for more difficult situations. Also, you do not get an initial Advisor\n";
     sleep_for(1500ms);
     cout << "if you choose this path. Although this path offers a strong head start, it lacks the long-term resilience and\n";
     sleep_for(1500ms);
     cout << "special abilities that could be gained through mentorship in Cub Training, making it a riskier approach to ";

     cout << "becoming a Pride Leader.\n"
          << endl;
     sleep_for(2500ms);
     system("pause");
     system("CLS");
     cout << "Did you read all of that?" << endl;
     sleep_for(500ms);
     cout << "Well it was kinda important, but if you didnt congrats you get to figure out what they do all on your lonesome." << endl;
     sleep_for(500ms);
     cout << "Well, This is the end of the tutorial. See you on the other side!" << endl;
     system("Pause");
     system("CLS");
}
