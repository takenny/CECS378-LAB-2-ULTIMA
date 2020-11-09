/**
 * ULTIMA 5 CHEAT ENGINE
 * CECS 378 MW 8AM
 * Created by: KENNY TA 015020302
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void edit_Stat(int character_input, int stat); //edit a certain stat method declaration
void edit_Inventory(int& item_input, int& inventory_Value); //edit a certain inventory declaration

int main()
{
    int input, exit_input; //declaration of variables
    bool no_Exit = true; //for while loop

    cout << "WELCOME TO ULTIMA 5's CHEAT ENGINE" << endl; // initial print out of welcome screen.
    while (no_Exit) //while loop so don't need to keep rerunning program to change one thing
    {
        cout << "What would you like to edit?" << endl;
        cout << "Type '1' to MAX the Stat on a Selected Character" << endl;
        cout << "Type '2' to Edit your Inventory" << endl;
        cin >> input;
        switch (input) { //check input for response
        //case 1 handles the stat changes
        case 1:
            int player, stat; //used for options in switch statement
            cout << "You have chosen to max the stats on a selected character" << endl;
            cout << "Who do you want to max? Type 1 for Player, 2 for Shamino, 3 for Iolo, 4 for Mariah, 5 for Geophry, 6 for Jaana, 7 for Julia, 8 for Dupre, 9 for Katrin, 10 for Sentri, 11 for Gwenno, 12 for John, 13 for Gorn, 14 for Maxwell, 15 for Toshi, 16 for Saduj " << endl;
            cin >> player;
            if (player > 16 || player == 0) //this if checks for a valid input
            {
                cout << "Wrong input, please try again." << endl;
                break;
            }
            cout << "What Stat did you want to change? Type 1 for STR, 2 for INT, 3 for DEX, 4 for HP, 5 for MAXHP, 6 for EXP " << endl;
            cin >> stat;
            if (stat > 6 || stat == 0 || player > 16 || player == 0) //this if checks for a valid input
            {
                cout << "Wrong input, please try again." << endl;
                break;
            }
            //after check for valid input, checks if player is selected, if not then go to else
            if (player == 1)
            {
                edit_Stat(player - 1, stat); //calls method to edit stat
                //here logic is player-1 because told player to type 1 and the offset for player in SAVED.GAM is 0x00
            }
            else
            {
                edit_Stat((player - 1) * 0x20, stat); //here logic is to get other players, keep the player-1 then multiply by 0x20, or 32.
                //noticed this pattern while finding offsets in player
            }
            break;

        case 2:
            int item_Input, inventory_Value; //initialization of variables for method
            cout << "You have chosen to edit your inventory" << endl;
            cout << "What would you like to edit? Type the item you want to edit: 1 for gold, 2 for keys, 3 for skull keys, 4 for gems, 5 for black badge, 6 for magic carpets, 7 for magic axes" << endl;
            cin >> item_Input;
            if (item_Input == 1) //error checking for overflow values / invalid entries
            {
                cout << "How much gold do you want? MAX 9999" << endl;
                cin >> inventory_Value;
                if (inventory_Value > 9999) //inventory number too high, just sets to max
                {
                    cout << "Invalid amount, max amount of 9999 given" << endl;
                    inventory_Value = 9999;
                }
            }
            else if (item_Input == 2 || item_Input == 3 || item_Input == 4) //options for keys, skull keys, and gems that ahve max of 100
            {
                cout << "How many of each? MAX 100" << endl; //run check so doesnt go over values
                cin >> inventory_Value;
                if (inventory_Value > 100)
                {
                    cout << "Invalid amount, max amount of 100 given" << endl;
                    inventory_Value = 100;
                }
            }
            else if (item_Input == 5 || item_Input == 6) //checking error for magic carpet / black badges
            {
                int yes_no; //different option yes or no
                cout << "Do you want the item? Type 1 for Yes, 2 for No" << endl;
                cin >> yes_no;
                if (yes_no == 1) //yes user wants it
                {
                    inventory_Value = 0xff;
                }
                else //no user doesnt want it
                {
                    inventory_Value = 0x00;
                }
            }
            else if (item_Input == 7) //error checking for magic axes
            {
                cout << "How many magic axes do you want? MAX 10" << endl;
                cin >> inventory_Value;
                if (inventory_Value > 10)
                {
                    cout << "Invalid amount, max amount of 10 given" << endl;
                    inventory_Value = 10;
                }
            }
            else //default check for invalid entries of item input
            {
                cout << "Invalid entry. Try Again." << endl;
                break;
            }

            // insert method here
            edit_Inventory(item_Input, inventory_Value); //call to method to handle editing inventory
            break;

        default:
            cout << "Please input a valid option" << endl;
            break;
        }
        //end of switch statement
        //prompts user to continue?
        cout << "Would you like to exit? Type 1 for No, 2 for Yes" << endl;
        cin >> exit_input;
        if (exit_input == 1)
        {
            no_Exit = true; //keeps boolean the same and doesnt exit.
        }
        else
        {
            no_Exit = false; //exits.
        }
        cout << endl;

    }
    cout << "Thanks for using this program. Have a nice day!" << endl; //friendly thank you for using program
}

/**
 * This method edits the stats of the characters, users are able to choose between the player or other characters to edit.
 * This method takes two ints, the choice of character to edit, and the stat they wish to edit.
 * This method doesn't return anything.
*/
void edit_Stat(int character_input, int stat)
{
    fstream fin("SAVED.GAM", ios::in | ios::out | ios::binary); //file in for edit
    int location = 0; //location = 0 intially until user inputs what they want to edit

    switch (stat) //swtich statement for error checking of stat max value
    {
        case 1: //case 1 for stat to edit, = str
        {
            int stat_Value; //initialize for how much to edit by
            cout << "How much do you want to edit this stat by? MAX = 99" << endl;
            cin >> stat_Value;
            if (stat_Value > 99) //error check if over max, end
            {
                stat_Value = 99;
                cout << "You went too far, max STR given." << endl;
            }
            location = character_input + 0x0e; //location of the character's STR offset
            //location = 0 but add character_input from method parameters, and add 0x0e where str offset is stored
            fin.seekp(location); //seekp putting a pointer at the location in the file where str is stored.
            fin.write((char*)&stat_Value, 1); //wrote to the file using statvalue we wanted to change.
            //the 1 is there because we only want to write to one block, if we have a larger number / storage to write to, we use a different number
            //ex. hp is stored in two blocks, so we write to both in hp's case. in the case of str, int, dex, we use 1
            break;
        }
        case 2: //case 2 int
        { //similar logic here as case 1
            int stat_Value;
            cout << "How much do you want to edit this stat by? MAX = 99" << endl;
            cin >> stat_Value;
            if (stat_Value > 99)
            {
                stat_Value = 99;
                cout << "You went too far, max INT given." << endl;
            }
            location = character_input + 0x0f;
            fin.seekp(location);
            fin.write((char*)&stat_Value, 1);
            break;
        }
        case 3: //dex similar logic as case 1 and 2
        {
            int stat_Value;
            cout << "How much do you want to edit this stat by? MAX = 99" << endl;
            cin >> stat_Value;
            if (stat_Value > 99)
            {
                stat_Value = 99;
                cout << "You went too far, max DEX given." << endl;
            }
            location = character_input + 0x10;
            fin.seekp(location);
            fin.write((char*)&stat_Value, 1);
            break;
        }
        case 4: //hp
        //hp stores values in two data blocks, so added a 2 at the end of write to write the char which is generally 8 bits, into two, so 16 bits total
        {
            int stat_Value;
            cout << "How much do you want to edit this stat by? MAX = 999" << endl;
            cin >> stat_Value;
            if (stat_Value > 999)
            {
                stat_Value = 999;
                cout << "You went too far, max HP given." << endl;
            }
            location = character_input + 0x12;
            fin.seekp(location);
            fin.write((char*)&stat_Value, 2); //changed for hp max hp and gold
            break;
        }
        case 5: //maxhp similar logic as above.
        {
            int stat_Value;
            cout << "How much do you want to edit this stat by? MAX = 999" << endl;
            cin >> stat_Value;
            if (stat_Value > 999)
            {
                stat_Value = 999;
                cout << "You went too far, max MAXHP given." << endl;
            }
            location = character_input + 0x14;
            fin.seekp(location);
            fin.write((char*)&stat_Value, 2); //changed for hp max hp and gold
            break;
        }
        case 6: //exp similar logic as above
        {
            int stat_Value;
            cout << "How much do you want to edit this stat by? MAX = 9999" << endl;
            cin >> stat_Value;
            if (stat_Value > 9999)
            {
                stat_Value = 9999;
                cout << "You went too far, max EXP given." << endl;
            }
            location = character_input + 0x16;
            fin.seekp(location);
            fin.write((char*)&stat_Value, 2); //changed for hp max hp and gold
            break;
        }
        default:
        {
            cout << "Please input a valid option" << endl;
            break;
        }
    }

    fin.close();//close file to save data!
}

/**
 * This method edits the player's inventory.
 * This method takes two integer params, the choice of item to edit, and the inventory value.
 * This method doesn't return anything.
*/
void edit_Inventory(int& item_input, int& inventory_Value)
{
    fstream fin("SAVED.GAM", ios::in | ios::out | ios::binary); //open file to for editting
    int location = 0; //location set to 0
    switch (item_input) //switch statement to handle all the diffferent cases
    {
        case 1: //gold
         {
            location = 0x204; //location is shared amongst different characters so did not need logic to add characters offsets
            fin.seekp(location);
            fin.write((char*)&inventory_Value, 2); //gold is only item that requires two 8bit blocks of data
            break;
         }
        case 2: //keys
        {
            location = 0x206;
            fin.seekp(location);
            fin.write((char*)&inventory_Value, 1);
            break;
        }
        case 3: //skullkeys
        {
            location = 0x20b;
            fin.seekp(location);
            fin.write((char*)&inventory_Value, 1);
            break;
        }
        case 4: //gems
        {
            location = 0x207;
            fin.seekp(location);
            fin.write((char*)&inventory_Value, 1);
            break;
        }
        case 5: //black badges
        {
            location = 0x218;
            fin.seekp(location);
            fin.write((char*)&inventory_Value, 1);
            break;
        }
        case 6: //magic carpet
        {
            location = 0x20a;
            fin.seekp(location);
            inventory_Value = 2;
            fin.write((char*)&inventory_Value, 1);
            break;
        }
        case 7: //magic axes
        {
            location = 0x240;
            fin.seekp(location);
            fin.write((char*)&inventory_Value, 1);
            break;
        }
        default:
        {
            cout << "Input a valid response" << endl;
        }
    }

    fin.close();
}

//end
