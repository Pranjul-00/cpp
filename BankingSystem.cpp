#include <iostream>
#include <fstream>

using namespace std;

struct Account{
    long int accNum;
    char Name[100];
    char accType;
    float Balance;
};

void createAccount;
void Deposit;
void Withdraw;
void BalanceEnquiry;
void saveDataToFile;
void loadDataFromFile;

Account Records[100];
int totalAccounts = 0;

int main(){

    loadDataFromFile();

    int choice;

    do{

        cout << "------Welcome to the Banking System------" << endl;
        cout << "1.Create a New Account" << endl;
        cout << "2.Deposit" << endl;
        cout << "3.Withdraw" << endl;
        cout << "4.Balance Enquiry" << endl;
        cout << "0.Exit" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        if(cin.fail()){
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Invalid Choice. Kindly Retry.";
            return;
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
                BalanceEnquiry();
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
        cout << "Database is full. Cannot addd more accounts" << endl;
        return;
    }

    cout << "--- Add New Student ---" << endl;

    cout << "Enter Account Number : ";
    cin >> Records[totalAccounts].accNum;
    cin.ignore();

    cout << "Enter Account Holder name : ";
    cin.getline(Records[totalAccounts].Name,100);

    cout << 
}