#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Room{
    int RoomNum;
    char guestName[100];
    char roomType[100];
    double RentPerNight;
    int status;
};

int roomCount = 0;
Room Records[100];

void InitializeRooms();
void checkIN();
void checkOUT();
void AvailableRooms();
void SearchGuest();
void saveDataToFile();
void LoadDataFromFile();

int main(){

    LoadDataFromFile();

    int choice;

    do{

        system("cls");

        cout << "-----Hotel Room Booking-------" << endl;
        cout << "1.Check In" << endl;
        cout << "2.Check Out" << endl;
        cout << "3.Show Available Rooms" << endl;
        cout << "4.Search Guest" << endl;
        cout << "0.Exit" << endl;
        cout << "------------------------------" << endl;
        cout << "Enter you choice : ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid Choice. Kindly Retry." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                checkIN();
                break;
            case 2:
                checkOUT();
                break;
            case 3:
                AvailableRooms();
                break;
            case 4:
                SearchGuest();
                break;
            case 0:
                saveDataToFile();
                cout << "Saving and Exiting." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;

        }
    }
    while(choice != 0);
    return 0;
}

void InitializeRooms(){

    if (roomCount > 0) {
        return; 
    }

    for (int i = 0; i < 10; i++) {
        Records[i].RoomNum = 101 + i;
        Records[i].RentPerNight = 100.00;
        Records[i].status = 0;
        
        strcpy(Records[i].guestName, "VACANT");
        strcpy(Records[i].roomType, "AC"); 
    }

    roomCount = 10;
}

void checkIN(){

    if (roomCount >= 99){
    cout << "All rooms are occupied. No rooms available." << endl;
    return;
    }

    cout << "----Guest Check In------" << endl;
    cout << "Enter Room Number : ";
    cin
}