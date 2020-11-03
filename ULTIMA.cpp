#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int input;
    fstream fin("SAVED.GAM", ios::in | ios::out | ios::binary);

    cout << "WELCOME TO ULTIMA 5's CHEAT ENGINE" << endl;
    cout << "WHAT WOULD YOU LIKE TO EDIT?" << endl;
    cout << "Type '1' to MAX the Stat on a Selected Character" << endl;
    cout << "Type '2' to Edit your Inventory" << endl;
    cout << "Type '3' to MAX the STATS and INVENTORY" << endl;
    cin >> input;
    switch (input && input <= 3) {
    case 1:
        cout << "You have chosen to max the stats on a selected character" << endl;
        cout << "Who do you want to max?" << endl;
        //insert method here 
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
