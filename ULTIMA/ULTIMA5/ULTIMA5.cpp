// ULTIMA5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

using namespace std;

//declared methods to write later
void edit_Stat(int input, int stat_Value);
void edit_Inventory(int input, int inventory_Value);
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
    switch (input & input < 4) {
    case 1:
        cout << "You have chosen to max the stats on a selected character" << endl;
        cout << "Who do you want to max?" << endl;
        //insert method here 
        
        edit_Stat(1, 990); //hp edit? 
        break;
    case 2:
        cout << "You have chosen to edit your inventory" << endl;
        cout << "What would you like to edit?" << endl;
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

void edit_Stat(int input, int stat_Value) //edit hp? 
{
  
    char test_hp = 0x3DE;
    int stat_input;
    int location = 0;
    cout << "You want to edit which stat" << endl;
    cin >> stat_input;
    if (stat_input == 1) //hp for test 
        //using 990 ? 
    {
        location = 0x12; //tried with higher bit value but didnt compile correctly. worked this way wrote correctly to file

        fin.seekp(location);
        fin.write((char*)&stat_Value, sizeof(stat_Value));
     
    }
   

    cout << hex << stat_Value << endl; 

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
