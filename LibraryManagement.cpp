#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int Max_book_count=100;
const int MAX_STR_LEN = 100;

struct Book {
    char title[MAX_STR_LEN];
    char author[MAX_STR_LEN];
    int id;
    int total_quantity;
    int issued_quantity;
};

Book library[Max_book_count];
int book_count=0;

void addBook();
void displayAllBooks();
void searchBook();
void issueBook();
void returnBook();
void saveDataToFile();
void loadDataFromFile();
int findBookIndexById(int id);

int main(){
    loadDataFromFile();

    int choice;
    do{
        cout << "\n--- Library Management System ---" << endl;
        cout << "1. Add New Book" << endl;
        cout << "2. Display All Books" << endl;
        cout << "3. Search for a Book" << endl;
        cout << "4. Issue a Book" << endl;
        cout << "5. Return a Book" << endl;
        cout << "0. Exit" << endl;
        cout << "-------------------------------" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        if (cin.fail()){
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number from the ones mentioned above." << endl;
            continue;
        }

        switch(choice){
            case 1:
                addBook();
                break;
            case 2:
                displayAllBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                issueBook();
                break;
            case 5:
                returnBook();
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

void addBook(){
    if (book_count >= Max_book_count){
        cout << "ERROR: Library is full. Cannot add more books." << endl;
        return;
    }

    cout << "--- Add New Book ---" << endl;
    cout << "Enter Book ID: ";
    cin >> library[book_count].id;
    cin.ignore();

    cout << "Enter Book Title: ";
    cin.getline(library[book_count].title, MAX_STR_LEN);

    cout << "Enter Author: ";
    cin.getline(library[book_count].author, MAX_STR_LEN);

    cout << "Enter Total Quantity: ";
    cin >> library[book_count].total_quantity;

    library[book_count].issued_quantity = 0;

    book_count++ ;

    cout << "Book added successfully!" << endl;
}

void displayAllBooks(){
    if (book_count == 0) {
        cout << "The library is empty. No books to display." << endl;
        return;
    }

    cout << "\n--- All Books in Library ---" << endl;
    for (int i = 0; i < book_count; i++) {
        cout << "------------------------------" << endl;
        cout << "Book Record " << (i + 1) << endl;
        cout << "ID       : " << library[i].id << endl;
        cout << "Title    : " << library[i].title << endl;
        cout << "Author   : " << library[i].author << endl;
        cout << "Total Qty: " << library[i].total_quantity << endl;
        cout << "Issued   : " << library[i].issued_quantity << endl;
        int available = library[i].total_quantity - library[i].issued_quantity;
        cout << "Available: " << available << endl;
    }
    cout << "------------------------------" << endl;
}

void searchBook() {
    if (book_count == 0) {
        cout << "The library is empty. No books to search." << endl;
        return;
    }

    int choice;
    cout << "Search by: (1) ID or (2) Title? ";
    cin >> choice;

    bool found = false;

    if (choice == 1) {
        int id;
        cout << "Enter Book ID to search: ";
        cin >> id;

        int index = findBookIndexById(id);
        if (index != -1) {
            cout << "Book Found!" << endl;
            cout << "ID       : " << library[index].id << endl;
            cout << "Title    : " << library[index].title << endl;
            cout << "Author   : " << library[index].author << endl;
            found = true;
        }
    } 
    else if (choice == 2) {
        char search_title[MAX_STR_LEN];
        cout << "Enter Title to search: ";
        cin.ignore();
        cin.getline(search_title, MAX_STR_LEN);

        for (int i = 0; i < book_count; i++) {
            if (strcmp(library[i].title, search_title) == 0) {
                cout << "Book Found!" << endl;
                cout << "ID       : " << library[i].id << endl;
                cout << "Title    : " << library[i].title << endl;
                cout << "Author   : " << library[i].author << endl;
                found = true;
                break;
            }
        }
    }
    else {
        cout << "Invalid search choice." << endl;
        return;
    }

    if (!found) {
        cout << "Book not found." << endl;
    }
}

int findBookIndexById(int id) {
    for (int i=0; i<book_count; i++){
        if (library[i].id=id){
            return i;
        }
    }
    return -1;
}

void issueBook(){
    int id;
    cout << "Enter Book ID to issue: ";
    cin >> id;

    int index = findBookIndexById(id);

    if (index==-1){
        cout << "Error: Book with ID " << id << " not found." << endl;
        return;
    }

    if (library[index].issued_quantity < library[index].total_quantity) {
        library[index].issued_quantity++;
        cout << "'" << library[index].title << "' has been issued." << endl;
        cout << "Copies remaining: " 
             << (library[index].total_quantity - library[index].issued_quantity) << endl;
    } else {
        cout << "Error: All copies of '" << library[index].title << "' are already issued." << endl;
    }
}

void returnBook() {
    int id;
    cout << "Enter Book ID to return: ";
    cin >> id;

    int index = findBookIndexById(id);

    if (index == -1) {
        cout << "Error: Book with ID " << id << " not found." << endl;
        return;
    }

    if (library[index].issued_quantity > 0) {
        library[index].issued_quantity--;
        cout << "'" << library[index].title << "' has been returned." << endl;
        cout << "Copies available: " 
             << (library[index].total_quantity - library[index].issued_quantity) << endl;
    } else {
        cout << "Error: No copies of '" << library[index].title << "' were issued." << endl;
    }
}

void saveDataToFile() {

    ofstream outFile("library_data.txt");
    
    if (!outFile.is_open()) {
        cout << "Error: Could not open file to save data." << endl;
        return;
    }

    outFile << book_count << endl;

    for (int i = 0; i < book_count; i++) {
        outFile << library[i].id << endl;
        outFile << library[i].title << endl;
        outFile << library[i].author << endl;
        outFile << library[i].total_quantity << endl;
        outFile << library[i].issued_quantity << endl;
    }

    outFile.close();
}

void loadDataFromFile() {
    ifstream inFile("library_data.txt");

    if (!inFile.is_open()) {
        cout << "No saved data file found. Starting with an empty library." << endl;
        return;
    }

    inFile >> book_count;
    if (inFile.fail()) {
        cout << "Error reading data file. Starting empty." << endl;
        inFile.close();
        book_count = 0;
        return;
    }

    inFile.ignore(); 

    for (int i = 0; i < book_count; i++) {
        if (inFile.eof()) {
            cout << "Warning: Data file ended unexpectedly. Loaded " << i << " books." << endl;
            book_count = i; 
            break;
        }

        inFile >> library[i].id;
        inFile.ignore(); 

        inFile.getline(library[i].title, MAX_STR_LEN);
        inFile.getline(library[i].author, MAX_STR_LEN);

        inFile >> library[i].total_quantity;
        inFile >> library[i].issued_quantity;
        inFile.ignore(); 
    }

    inFile.close();
    cout << "Loaded " << book_count << " books from file." << endl;
}