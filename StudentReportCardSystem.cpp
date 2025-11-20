#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student{
    int Roll_No;
    char Name[100];
    float Percentage;
    char Grade;
    int Marks[5];
};

Student Records[100];
int studentCount = 0;

void AddStudent();
void DisplayAllRecords();
void SearchRecords();
void ModifyRecords();
void saveDataToFile();
void loadDataFromFile();

int main() {

    loadDataFromFile();

    int choice;
    do{
        cout << "--Welcome to Student Records--"<< endl;
        cout << "1.Add a Student" << endl;
        cout << "2.Display Records" << endl;
        cout << "3.Search Records" << endl;
        cout << "4.Modify Records" << endl;
        cout << "0.Exit" << endl;
        cout << "------------------------------"<<endl;
        cout << "Enter your choice: ";

        cin >> choice;

        if (cin.fail()){
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number from the ones mentioned above." << endl;
            continue;
        }

        switch (choice){
            case 1:
                AddStudent();
                break;
            case 2:
                DisplayAllRecords();
                break;
            case 3:
                SearchRecords();
                break;
            case 4:
                ModifyRecords();
                break;
            case 0:
                saveDataToFile();
                cout << "Saving data and Exiting... Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice!=0);
    return 0;
}

void AddStudent(){

    if (studentCount >= 100) {
        cout << "Database is full! Cannot add more students." << endl;
        return;
    }

    cout << "--- Add New Student ---" << endl;
    cout << "Enter Student Roll Number : ";
    cin >> Records[studentCount].Roll_No;
    cin.ignore();

    cout << "Enter Student Name : ";
    cin.getline(Records[studentCount].Name, 100);

    float total = 0;

    for (int i=0 ; i<=4 ; i++){
        cout << "Enter Marks in Subject " << i+1 << " : ";
        cin >> Records[studentCount].Marks[i];

        total = total + Records[studentCount].Marks[i];
    }

    Records[studentCount].Percentage = total/5;
    
    if (Records[studentCount].Percentage >= 90.00 && Records[studentCount].Percentage <= 100.00 ){
        Records[studentCount].Grade = 'A';
    }

    else if (Records[studentCount].Percentage >= 80.00 && Records[studentCount].Percentage < 90.00){
        Records[studentCount].Grade = 'B';
    }

    else if (Records[studentCount].Percentage >= 70.00 && Records[studentCount].Percentage < 80.00){
        Records[studentCount].Grade = 'C';
    }

    else{
        Records[studentCount].Grade = 'D';
    }

    studentCount++;

    cout << "Student Added Successfully." << endl;
    cout << "-----------------------------------" << endl;
}

void DisplayAllRecords(){

    if (studentCount==0){
        cout << "No Records Found." << endl;
        cout << "-----------------------------------" << endl;
        return;
    }

    cout << "There are " << studentCount << "Students in the Database." << endl;
    for (int i=0; i<studentCount; i++){
        cout << "---------------------------------------" << endl;
        cout << "Here are the deatils of Student " << i+1 << endl;
        cout << "---------------------------------------" << endl;
        cout << "Roll Number : " << Records[i].Roll_No << endl;
        cout << "Name : " << Records[i].Name << endl;
        
        for (int j=0; j<=4; j++){
            cout << "Marks in Subject " << j+1 << " : " << Records[i].Marks[j] << endl;
        }

        cout << "Percentage : " << Records[i].Percentage << "%" << endl;
        cout << "Grade : " << Records[i].Grade << endl;
        cout << "-----------------------------------" << endl;
    }
}

void SearchRecords(){

    if (studentCount==0){
        cout << "No Records Found." << endl;
        cout << "-----------------------------------" << endl;
        return;
    }

    cout << "There are " << studentCount << "Students in the Database." << endl;

    int choice2;
    cout << "---------------------------------------" << endl;
    cout << "1.Search Using Roll Number." << endl;
    cout << "2.Search Using Name." << endl;
    cout << "---------------------------------------" << endl;
    cout << "Enter your choice : ";
    cin >> choice2;

    if (cin.fail()){
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number from the ones mentioned above." << endl;
            return;
        }
    
        if (choice2==1){
            int searchRoll;
            cout << "Enter Roll Number to find : ";
            cin >> searchRoll;

            bool found = false;

            for (int i=0; i< studentCount; i++){
                if (Records[i].Roll_No == searchRoll){
                    cout << "---------------------------------------" << endl;
                    cout << "Here are the deatils of Roll Number " << searchRoll << endl;
                    cout << "---------------------------------------" << endl;
                    cout << "Roll Number : " << Records[i].Roll_No << endl;
                    cout << "Name : " << Records[i].Name << endl;
                    
                    for (int j=0; j<=4; j++){
                        cout << "Marks in Subject " << j+1 << " : " << Records[i].Marks[j] << endl;
                    }

                    cout << "Percentage : " << Records[i].Percentage << "%" << endl;
                    cout << "Grade : " << Records[i].Grade << endl;
                    cout << "-----------------------------------" << endl;

                    found = true;
                    break;
                }
            }

            if (found == false) {
                    cout << "No record found for Roll Number " << searchRoll << endl;
                    cout << "-----------------------------------" << endl;
                }

        }

        else if (choice2==2){
            char searchName[100];
            cout << "Enter Name to find : ";

            cin.ignore();
            cin.getline(searchName,100);

            bool found = false;

            for (int i=0; i< studentCount; i++){
                if (strcmp(Records[i].Name,searchName) == 0){
                    cout << "---------------------------------------" << endl;
                    cout << "Here are the deatils of " << searchName << endl;
                    cout << "---------------------------------------" << endl;
                    cout << "Roll Number : " << Records[i].Roll_No << endl;
                    cout << "Name : " << Records[i].Name << endl;
                    
                    for (int j=0; j<=4; j++){
                        cout << "Marks in Subject " << j+1 << " : " << Records[i].Marks[j] << endl;
                    }

                    cout << "Percentage : " << Records[i].Percentage <<
                    "%" << endl;
                    cout << "Grade : " << Records[i].Grade << endl;
                    cout << "-----------------------------------" << endl;

                    found = true;
                    break;
                }
            }

            if (found == false) {
                    cout << "No record found for " << searchName << endl;
                    cout << "-----------------------------------" << endl;
                }

        }
}

void ModifyRecords(){

    if (studentCount==0){
        cout << "No Records Found to modify." << endl;
        cout << "-----------------------------------" << endl;
        return;
    }

    int modifyRoll;

    cout << "Enter Roll Number of Student, whose details you need to modify : ";
    cin >> modifyRoll;

    bool found = false;

    for (int i=0; i<studentCount; i++){
        if (Records[i].Roll_No == modifyRoll){
            cout << "Record found for " << Records[i].Name << endl;
            cout << "-----------------------------------" << endl;
            cout << "       Enter New Details           " << endl;
            cout << "-----------------------------------" << endl;

            cout << "Enter new Roll Number : ";
            cin >> Records[i].Roll_No;

            cout << "Enter new name : ";
            cin.ignore();
            cin.getline(Records[i].Name,100);

            float total = 0;

            for (int j=0; j<=4; j++){
                cout << "Enter new marks in subject " << j+1 << " : ";
                cin >> Records[i].Marks[j];

                total = total + Records[i].Marks[j];
            }

            Records[i].Percentage = total/5;

            if (Records[i].Percentage >= 90.00 && Records[i].Percentage <= 100.00 ){
                Records[i].Grade = 'A';
            }

            else if (Records[i].Percentage >= 80.00 && Records[i].Percentage < 90.00){
                Records[i].Grade = 'B';
            }

            else if (Records[i].Percentage >= 70.00 && Records[i].Percentage < 80.00){
                Records[i].Grade = 'C';
            }

            else{
                Records[i].Grade = 'D';
            }

            cout << "Updated the records successfully."<< endl;
            cout << "-----------------------------------" << endl;

            found = true;
            break;
        }
    }
    
    if (found == false){
        cout << "There is no Student with Roll Number - " << modifyRoll << " in the database.";
        cout << "-----------------------------------" << endl;
    }
}

void saveDataToFile(){

    ofstream outFile("studentReportCardData.txt");

    if (!outFile){
        cout << "Error Saving File" << endl;
        return;
    }

    outFile << studentCount << endl;

    for (int i=0; i < studentCount; i++){
        outFile << Records[i].Roll_No << endl;
        outFile << Records[i].Name << endl; 

        for (int j=0; j <=4; j++){
            outFile << Records[i].Marks[j] << endl;
        }

        outFile << Records[i].Percentage << endl; 
        outFile << Records[i].Grade << endl; 
    }

    outFile.close();
}

void loadDataFromFile(){

    ifstream inFile("studentReportCardData.txt");

    if (!inFile) {
        return;
    }

    inFile >> studentCount;
    inFile.ignore();
    
    for (int i=0; i < studentCount; i++) {

        inFile >> Records[i].Roll_No;
        inFile.ignore();

        inFile.getline(Records[i].Name,100);

        for (int j=0; j <=4; j++){
            inFile >> Records[i].Marks[j];
        }

        inFile >> Records[i].Percentage;
        inFile >> Records[i].Grade;
    }
    
    inFile.close();
}