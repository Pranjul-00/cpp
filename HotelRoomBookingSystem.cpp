#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Room{
    int RoomNum;
    char guestName[100];
    char roomType[100];
    double RentPerNight;
    int status;         //i am gonna use 0 for vacant.
};

int roomCount = 0;
Room Records[100];

void InitializeRooms();
void copyString();
int compareString();
void checkIN();
void checkOUT();
void roomsDetail();
void SearchGuest();
void saveDataToFile();
void LoadDataFromFile();

int main(){

    LoadDataFromFile();

    if (roomCount == 0) {
        InitializeRooms();
    }

    int choice;

    do{

        system("cls");

        cout << "-----Hotel Room Booking-------" << endl;
        cout << "1.Check In" << endl;
        cout << "2.Check Out" << endl;
        cout << "3.Show Details of Rooms." << endl;
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
                roomsDetail();
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

void copyString(char destination[], const char source[]) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

int compareString(const char str1[], const char str2[]){
    int i = 0;
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
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
        
        copyString(Records[i].guestName, "VACANT");
        copyString(Records[i].roomType, "AC"); 
    }

    roomCount = 10;
}

void checkIN(){

    int desiredRoom;

    cout << "------------------------------" << endl;
    cout << "Here are the details of available rooms." << endl;
    cout << "------------------------------" << endl;

    for (int i=0; i < roomCount; i++){

        if (Records[i].status == 0){
            cout << "Room Number : " << Records[i].RoomNum << endl; 
            cout << "Room Type : " << Records[i].roomType<< endl; 
            cout << "Room Rent : " << Records[i].RentPerNight << endl; 
            cout << "------------------------------" << endl;
        }
    }

    cout << "Enter Room Number of the room you\n'd like to book " << endl;
    cin >> desiredRoom;

    bool roomFound = false;

    for (int i=0; i < roomCount; i++){

        if (Records[i].RoomNum == desiredRoom){

            roomFound = true;

            if (Records[i].status == 1){

                cout << "Sorry! Room no. " << desiredRoom << " is already occupied." << endl;
                return;

            }

            cout << "Enter Guest name : ";
            cin.ignore();
            cin.getline(Records[i].guestName,100);

            Records[i].status = 1;

            cout << "Success! Room " << desiredRoom << " booked for " << Records[i].guestName << endl;
            system("pause");
            return;
        }
    }

    if (roomFound == false) {
        cout << "Error: Room Number " << desiredRoom << " does not exist." << endl;
        system("pause");
    }
}

void checkOUT(){

    int roomCheck;

    bool roomFound = false;

    cout << "------------------------------" << endl;
    cout << "Welcome to the check-out system." << endl;
    cout << "------------------------------" << endl;
    cout << "Enter Room Number : ";
    cin >> roomCheck;

    for (int i=0; i < roomCount; i++){

        if (Records[i].RoomNum == roomCheck){

            roomFound = true;

            if (Records[i].status == 0){
                cout << "Room is already vacant." << endl;
                system("pause");
                return;
            }

            cout << "Thank You for your stay with us " << Records[i].guestName << endl;

            cout << "Your room rent is: $" << Records[i].RentPerNight << endl;

            Records[i].status = 0;
            copyString(Records[i].guestName, "VACANT");

            cout << "Checkout complete. Room " << roomCheck << " is now vacant." << endl;

            roomFound = true;
            system("pause");
            return;
        }
    }

    if (roomFound == false) {
        cout << "Room no. " << roomCheck << " does not exist." << endl;
    }
}

void SearchGuest(){

    bool guestFound = false;
    char guestCheck[100];

    cout << "------------------------------" << endl;
    cout << "Welcome to the Search system." << endl;
    cout << "------------------------------" << endl;

    cout << "Enter name of the guest : " << endl;
    cin.ignore();
    cin.getline(guestCheck,100);

    for (int i=0; i < roomCount; i++) {

        if (Records[i].status == 1){

            if (compareString(Records[i].guestName,guestCheck) == 0) {
            cout << "------------------------------" << endl;
            cout << " Details Found Successfully." << endl;
            cout << "------------------------------" << endl; 
            cout << "Guest Name : " << Records[i].guestName << endl;
            cout << "Room Number : " << Records[i].RoomNum << endl;
            cout << "Room Type : " << Records[i].roomType << endl;
            cout << "Rent : " << Records[i].RentPerNight << endl;
            cout << "------------------------------" << endl;

            guestFound = true;
            system("pause");
            return;
            }
        }
    }

    if (guestFound == false) {
        cout << "Cannot find the guest in the records." << endl;
        system("pause");
    }
}

void roomsDetail(){

    cout << "------------------------------" << endl;
    cout << "Here are details of all the rooms" << endl;
    cout << "------------------------------" << endl;

    for (int i=0; i < roomCount; i++) {

        cout << "Room Number : " << Records[i].RoomNum << endl;
        cout << "Status (0 -> Vacant ; 1 -> Occupied) : " << Records[i].status << endl;
        cout << "Room Type : " << Records[i].roomType << endl;
        cout << "Room Rent : " << Records[i].RentPerNight << endl;
        cout << "------------------------------" << endl;

    }

    system("pause");
}

void saveDataToFile(){

    ofstream outFile("Hotel_Records.txt");

    if (!outFile) {
        cout << "Error Saving data to file." << endl;
        return;
    }

    outFile << roomCount << endl;

    for (int i=0; i < roomCount; i++) {

        outFile << Records[i].RoomNum << endl;
        outFile << Records[i].guestName << endl;
        outFile << Records[i].status << endl;
        outFile << Records[i].roomType << endl;
        outFile << Records[i].RentPerNight << endl;
    }

    outFile.close();
}

void LoadDataFromFile(){

    ifstream inFile("Hotel_Records.txt");

    if (!inFile) {
        return;
    }

    inFile >> roomCount;
    inFile.ignore();

    for (int i=0; i < roomCount; i++) {

        inFile >> Records[i].RoomNum;
        inFile.ignore();

        inFile.getline(Records[i].guestName,100);
        inFile.getline(Records[i].roomType,100);
        
        inFile >> Records[i].RentPerNight;
        inFile >> Records[i].status;

        inFile.ignore();
    }

    inFile.close();
}