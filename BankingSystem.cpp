#include <iostream>
#include <fstream>

using namespace std;

struct Account{
    long int accNum;
    char Name[100];
    char accType;
    float Balance;
};

void createAccount();
void Deposit();
void Withdraw();
void AccountEnquiry();
void saveDataToFile();
void loadDataFromFile();

Account Records[100];
int totalAccounts = 0;

int main(){

    loadDataFromFile();

    int choice;

    do{

        system("cls");

        cout << "------Welcome to the Banking System------" << endl;
        cout << "1.Create a New Account" << endl;
        cout << "2.Deposit" << endl;
        cout << "3.Withdraw" << endl;
        cout << "4.Account Enquiry" << endl;
        cout << "0.Exit" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        if(cin.fail()){
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Invalid Choice. Kindly Retry.";
            continue;;
        }

        switch(choice){
            case 1:
                createAccount();
                break;
            case 2:
                Deposit();
                break;
            case 3:
                Withdraw();
                break;
            case 4:
                AccountEnquiry();
                break;
            case 0:
                saveDataToFile();
                cout << "Saving data and Exiting... Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again..";
                break;
        }
    } while(choice != 0);
    return 0;
}

void createAccount(){

    if (totalAccounts >= 99){
        cout << "Database is full. Cannot add more accounts" << endl;
        return;
    }

    cout << "---------- Add New Account -------------" << endl;
    
    cout << "Enter Account Number : ";
    cin >> Records[totalAccounts].accNum;
    cin.ignore();

    cout << "Enter Account Holder name : ";
    cin.getline(Records[totalAccounts].Name,100);

    cout << "Enter Account type (Savings/Current): ";
    cin >> Records[totalAccounts].accType;

    do {
        cout << "Enter opening balance (Min 500): ";
        cin >> Records[totalAccounts].Balance;
        if(Records[totalAccounts].Balance < 500) {
            cout << "Error: Opening balance must be at least 500." << endl;
        }
    } while (Records[totalAccounts].Balance < 500);

    cout << "------------------------------------------" << endl;
    cout << "        Account added successfully." << endl;
    cout << "------------------------------------------" << endl;

    totalAccounts++;

    system("pause");
}

void Deposit(){

    if (totalAccounts == 0){
        cout << "No Accounts in the database." << endl;
        system("pause");
        return;
    }

    long int searchAcc;
    float DepositedAmt;

    cout << "Enter Account Number to Deposit : ";
    cin >> searchAcc;

    bool found = false;

    for (int i=0; i < totalAccounts; i++){
        if (Records[i].accNum == searchAcc){

            cout << "------------------------------------------" << endl;
            cout << "Account Number : " << searchAcc << endl;
            cout << "Account Holder Name : " << Records[i].Name << endl;
            cout << "Current Balance : " << Records[i].Balance << endl;
            cout << "------------------------------------------" << endl;
            cout << "Enter amout to be deposited : ";
            cin >> DepositedAmt;
            cout << DepositedAmt << " deposited successfully to A/C : " << searchAcc << endl;

            Records[i].Balance = Records[i].Balance + DepositedAmt;

            cout << "------------------------------------------" << endl;
            cout << "Updated the Account Balance successfully." << endl;
            cout << "New Account Balance : " << Records[i].Balance;
            cout << "------------------------------------------" << endl;

            found = true;
            break;
        }
    }

    if (found == false) {
        cout << "Error: Account Number " << searchAcc << " not found." << endl;
    }

    system("pause");
}

void Withdraw(){

    if (totalAccounts == 0){
            cout << "No Accounts in the database." << endl;
            system("pause");
            return;
    }
    
    long int searchAcc;
    float WithdrawnAmt;

    cout << "Enter Account Number to Withdraw : ";
    cin >> searchAcc;

    bool found = false;

    for (int i=0; i < totalAccounts; i++){
        if (Records[i].accNum == searchAcc){

            cout << "------------------------------------------" << endl;
            cout << "Account Number : " << searchAcc << endl;
            cout << "Account Holder Name : " << Records[i].Name << endl;
            cout << "Current Balance : " << Records[i].Balance << endl;
            cout << "------------------------------------------" << endl;
            cout << "Enter Amount to be withdrawn : ";
            cin >> WithdrawnAmt;
            
            if (Records[i].Balance - WithdrawnAmt < 500) {
                cout << "------------------------------------------" << endl;
                cout << "Transaction Failed! Insufficient Balance." << endl;
                cout << "You must maintain a minimum of 500." << endl;
                cout << "------------------------------------------" << endl;
            } 
            else {
                Records[i].Balance = Records[i].Balance - WithdrawnAmt;
                cout << "Withdrawn successfully." << endl;
                cout << "New Account Balance : " << Records[i].Balance << endl;
            }

            found = true;
            break;
        }
    }

    if (found == false){
        cout << "Error: Account Number " << searchAcc << " not found." << endl;
    }

    system("pause");
}

void AccountEnquiry(){

    if (totalAccounts == 0){
            cout << "No Accounts in the database." << endl;
            system("pause");
            return;
    }

    long int searchAcc;

    cout << "Enter Account Number for enquiry : ";
    cin >> searchAcc;

    bool found = false;

    for (int i=0; i < totalAccounts; i++){
        if (Records[i].accNum == searchAcc){

            cout << "------------Account Details---------------" << endl;
            cout << "Account Number : " << searchAcc << endl;
            cout << "Account Holder Name : " << Records[i].Name << endl;
            cout << "Account type : " << Records[i].accType << endl;
            cout << "Current Balance : " << Records[i].Balance << endl;
            cout << "------------------------------------------" << endl;

            found = true;
            break;
        }
    }

    if (found == false){
        cout << "Error: Account Number " << searchAcc << " not found." << endl;
    }

    system("pause");
}

void saveDataToFile(){

    ofstream outFile("BankRecords.txt");

    if (!outFile){
        cout << "Error saving file." << endl;
        return;
    }

    outFile << totalAccounts << endl;

    for (int i=0; i < totalAccounts; i++){
        outFile << Records[i].accNum << endl;
        outFile << Records[i].Name << endl;
        outFile << Records[i].accType << endl;
        outFile << Records[i].Balance << endl;
    }

    outFile.close();

}

void loadDataFromFile(){

    ifstream inFile("BankRecords.txt");

    if (!inFile){
        cout << "Error loading file." << endl;
        return;
    }

    inFile >> totalAccounts;

    for (int i=0; i < totalAccounts; i++){
        inFile >> Records[i].accNum;

        inFile.ignore();
        inFile.getline(Records[i].Name,100);

        inFile >> Records[i].accType;
        inFile >> Records[i].Balance;
    }

    inFile.close();

}