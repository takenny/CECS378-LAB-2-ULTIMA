// ULTIMA5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

//declared methods to write later
void edit_Stat(int character_input, int stat_Value);
void edit_Inventory(int item_input, int inventory_Value);
void max_All();

fstream fin("SAVED.GAM", ios::in | ios::out | ios::binary);

int main()
{
    int input;

    cout << "WELCOME TO ULTIMA 5's CHEAT ENGINE" << endl;
    cout << "WHAT WOULD YOU LIKE TO EDIT?" << endl;
    cout << "Type '1' to MAX the Stat on a Selected Character" << endl;
    cout << "Type '2' to Edit your Inventory" << endl;
    cout << "Type '3' to MAX the STATS and INVENTORY" << endl;
    cin >> input;
    switch (input) { //check if this is okay  
    case 1:
        int player, stat_Value;
        cout << "You have chosen to max the stats on a selected character" << endl;
        cout << "Who do you want to max? Type 1 for Player, 2 for Shamino, 3 for Iolo, 4 for Mariah, 5 for Geophry, 6 for Jaana, 7 for Julia, 8 for Dupre, 9 for Katrin, 10 for Sentri, 11 for Gwenno, 12 for John, 13 for Gorn, 14 for Maxwell, 15 for Toshi, 16 for Saduj " << endl;
        //insert method here 
        cin >> player;
        cout << "What Stat did you want to change? Type 1 for STR, 2 for INT, 3 for DEX, 4 for HP, 5 for MAXHP, 6 for EXP " << endl;
        cin >> stat_Value;
        //need to run check if stat is over max value of address 
        if (player == 1)
        {
            edit_Stat(player, stat_Value);
        }
        else
        {
            edit_Stat(player * 0x20, stat_Value);
        }
                    //test codew       edit_Stat(player*0x20, 990); //hp edit? 
        break;
    case 2:
        cout << "You have chosen to edit your inventory" << endl;
        cout << "What would you like to edit? Type the item you want to edit: gold, keys, skull keys, gems, black badge, magic carpets, magic axes" << endl;
        // insert method here 
        break;
    case 3:
        //insert method here 
        cout << "You have maxed your stats and inventory!" << endl;

    default:
        cout << "Please input a valid option" << endl;
        return 0;
    }

}

void edit_Stat(int character_input, int stat_Value) //edit hp? 
{
    char test_hp = 0x3DE;
    string stat_input;
    int location = 0;
    cout << "You want to edit which stat? Type hp, mhp, exp, gold" << endl;
    cin >> stat_input;
    transform(stat_input.begin(), stat_input.end(), stat_input.begin(), ::tolower);
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
   
    fin.close();
    //cout << hex << stat_Value << endl; 
}

void edit_Inventory(int item_input, int inventory_Value)
{

    fin.close();
}

void max_All()
{

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
