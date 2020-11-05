// ULTIMA5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

//declared methods to write later
void edit_Stat(int character_input, int stat);
void edit_Inventory(int& item_input, int& inventory_Value);
//void max_All();



int main()
{

    int input, exit_input;
    bool exit = true;

    cout << "WELCOME TO ULTIMA 5's CHEAT ENGINE" << endl;
    while (exit)
    {
        cout << "WHAT WOULD YOU LIKE TO EDIT?" << endl;
        cout << "Type '1' to MAX the Stat on a Selected Character" << endl;
        cout << "Type '2' to Edit your Inventory" << endl;
        cin >> input;
        switch (input) { //check if this is okay  
        case 1:
            int player, stat;
            cout << "You have chosen to max the stats on a selected character" << endl;
            cout << "Who do you want to max? Type 1 for Player, 2 for Shamino, 3 for Iolo, 4 for Mariah, 5 for Geophry, 6 for Jaana, 7 for Julia, 8 for Dupre, 9 for Katrin, 10 for Sentri, 11 for Gwenno, 12 for John, 13 for Gorn, 14 for Maxwell, 15 for Toshi, 16 for Saduj " << endl;
            //insert method here 
            cin >> player;
            cout << "What Stat did you want to change? Type 1 for STR, 2 for INT, 3 for DEX, 4 for HP, 5 for MAXHP, 6 for EXP " << endl;
            cin >> stat;
            if (stat > 6 || stat == 0)
            {
                cout << "Wrong input, please try again." << endl;
            }
            //need to run check if stat is over max value of address 
            if (player == 1)
            {
                edit_Stat(player - 1, stat);
            }
            else
            {
                //cout << "player is " << (player - 1) * 32; debugging? its wroking...? 
                edit_Stat((player - 1) * 32, stat);
            }
            //test codew       edit_Stat(player*0x20, 990); //hp edit? 
            break;
        case 2:
            int item_Input;
            int inventory_Value;
            cout << "You have chosen to edit your inventory" << endl;
            cout << "What would you like to edit? Type the item you want to edit: 1 for gold, 2 for keys, 3 for skull keys, 4 for gems, 5 for black badge, 6 for magic carpets, 7 for magic axes" << endl;
            cin >> item_Input;
            if (item_Input == 1)
            {
                cout << "How much gold do you want? MAX 9999" << endl;
                cin >> inventory_Value;
                if (inventory_Value > 9999)
                {
                    cout << "Invalid amount, max amount allocated" << endl;
                    inventory_Value = 9999;
                }
            }
            else if (item_Input == 2 || item_Input == 3 || item_Input == 4)
            {
                cout << "How many of each? MAX 100" << endl; //run check so doesnt go over values 
                cin >> inventory_Value;
                if (inventory_Value > 100)
                {
                    cout << "Invalid amount, max amount allocated" << endl;
                    inventory_Value = 100;
                }
            }
            else if (item_Input == 5 || item_Input == 6) //badge and carpet? booleans 
            {
                int yes_no;
                cout << "Do you want the item? Type 1 for Yes, 2 for No" << endl;
                cin >> yes_no;
                if (yes_no == 1)
                {
                    inventory_Value = 0xff;
                }
                else
                {
                    inventory_Value = 0x00;
                }
            }
            else if (item_Input == 7)
            {
                cout << "How many magic axes do you want? MAX 10" << endl;
                cin >> inventory_Value;
                if (inventory_Value > 10)
                {
                    cout << "Invalid amount, max amount allocated" << endl;
                    inventory_Value = 10;
                }
            }
            else //default check 
            {
                cout << "Invalid entry. Try Again." << endl;
            }

            // insert method here 
            cout << "asodhiaosjdfsa " << item_Input << "ASDOIUJHASIDJ" << inventory_Value << endl;
            edit_Inventory(item_Input, inventory_Value);
            break;

        default:
            cout << "Please input a valid option" << endl;
            return 0;
        }

        cout << "Would you like to exit? Type 1 for no, 2 for yes" << endl;
        cin >> exit_input;
        if (exit_input == 1)
        {
            exit = true;
        }
        else
        {
            exit = false;
        }

    }
    cout << "Thanks for using this program. Have a nice day!" << endl;
}

void edit_Stat(int character_input, int stat) //edit hp? 
{
         char test_hp = 0x3DE;
    fstream fin("SAVED.GAM", ios::in | ios::out | ios::binary);
    int location = 0;
   // cout << "You want to edit which stat? Type hp, mhp, exp, gold" << endl;
  //  cin >> stat_input;
  //  transform(stat_input.begin(), stat_input.end(), stat_input.begin(), ::tolower);
    switch (stat) //swtich statemtn for error checking of stat max value 
    {
        case 1: //case 1 for stat to edit, = str 
        {
            int stat_Value;
            cout << "How much do you want to edit this stat by? MAX = 99" << endl;
            cin >> stat_Value;
            if (stat_Value > 99)
            {
                stat_Value = 99;
                cout << "You went too far, max STR given." << endl;
            }
            location = character_input + 0x0e;
            fin.seekp(location);
            fin.write((char*)&stat_Value, 1);
            break;
        }
        case 2:
        {
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
        case 3:
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
        case 4:
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
        case 5:
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
        case 6:
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

    /*
    if (stat_input == "hp" || "mhp" || "exp" || "gold") //hp for test 
        //using 990 ? 
    {
        location = 0x12; //tried with higher bit value but didnt compile correctly. worked this way wrote correctly to file

        fin.seekp(location);
        fin.write((char*)&stat_Value, 2); //2 for byte block 2 for hp , max hp, exp, gold
        //1 for byte block 1 for everything else that have one address 
     
    }
    else
    {
        location = 0; //whatever location;

        fin.seekp(location);
        fin.write((char*)&stat_Value, 1);
    }
   */

    fin.close();
    //cout << hex << stat_Value << endl; 
}

void edit_Inventory(int& item_input, int& inventory_Value)
{
    fstream fin("SAVED.GAM", ios::in | ios::out | ios::binary);
    int location = 0;
    cout << "ITEM INPUT IS " << item_input << " and " << inventory_Value <<endl;
    switch (item_input)
    {
        case 1: //gold 
         {
            location = 0x204;
            fin.seekp(location);
            fin.write((char*)&inventory_Value, 2);
            break;
         }
        case 2: //keys
        {
            location = 0x206;
            fin.seekp(location);
            fin.write((char*)&inventory_Value, 1);
            break;
        }
        case 3:
        {
            location = 0x20b;
            fin.seekp(location);
            fin.write((char*)&inventory_Value, 1);
            break;
        }
        case 4:
        {
            location = 0x207;
            fin.seekp(location);
            fin.write((char*)&inventory_Value, 1);
            break;
        }
        case 5:
        {
            location = 0x218;
            fin.seekp(location);
            fin.write((char*)&inventory_Value, 1);
            break;
        }
        case 6:
        {
            location = 0x20a;
            fin.seekp(location);
            inventory_Value = 2;
            fin.write((char*)&inventory_Value, 1);
            break;
        }
        case 7:
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
   
    //need a check for black badges and magic carpets boolean values so swtich statment ? i guess ? 
    fin.close();
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
