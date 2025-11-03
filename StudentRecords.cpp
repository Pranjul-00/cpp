#include <iostream>
#include <fstream> 

using namespace std;

struct Student {
    int rollNo;
    char name[50];
    float marks[5];
    float total;
    float average;
};

int getValidInt(const char* prompt, int min, int max) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cout << "  [Error] Invalid input. Please enter a number.\n";
            cin.clear(); 
            char c;
            while (cin.get(c) && c != '\n'); 
        } 
        else if (value < min || value > max) {
            cout << "  [Error] Value must be between " << min << " and " << max << ".\n";
        }
        else {
            return value;
        }
    }
}

float getValidMark(const char* prompt) {
    float value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cout << "  [Error] Invalid input. Please enter a number.\n";
            cin.clear();
            char c;
            while (cin.get(c) && c != '\n');
        } 
        else if (value < 0.0 || value > 100.0) {
            cout << "  [Error] Mark must be between 0.0 and 100.0.\n";
        } 
        else {
            return value;
        }
    }
}


int main() {
    
    const int MAX_STUDENTS = 100;
    Student students[MAX_STUDENTS];
    int n; 

    cout << "--- Student Record Management ---\n";
    
    n = getValidInt("Enter number of students (1-100): ", 1, MAX_STUDENTS);

    for (int i = 0; i < n; ++i) {
        cout << "\n--- Enter details for Student " << (i + 1) << " ---\n";
        
        students[i].rollNo = getValidInt("Enter Roll Number: ", 1, 1000000);

        cout << "Enter Name: ";
        cin >> students[i].name;
        
        students[i].total = 0;
        for (int j = 0; j < 5; ++j) {
            char markPrompt[30]; 
            sprintf(markPrompt, "Enter Mark for Subject %d: ", j + 1); 
            
            students[i].marks[j] = getValidMark(markPrompt);
            students[i].total += students[i].marks[j];
        }
        
        students[i].average = students[i].total / 5.0;
        cout << "  Total: " << students[i].total << ", Average: " << students[i].average << endl;
    }
    
    ofstream outFile("students.txt");
    if (!outFile) {
        cerr << "Error: Could not open students.txt for writing!" << endl;
        return 1;
    }

    outFile << "RollNo\tName\tMark1\tMark2\tMark3\tMark4\tMark5\tTotal\tAverage\n";
    
    for (int i = 0; i < n; ++i) {
        outFile << students[i].rollNo << "\t"
                << students[i].name << "\t";
        for (int j = 0; j < 5; ++j) {
            outFile << students[i].marks[j] << "\t";
        }
        outFile << students[i].total << "\t"
                << students[i].average << "\n";
    }
    outFile.close();
    cout << "\nSuccessfully saved " << n << " student records to students.txt\n";
    
    cout << "\n--- Reading Records from students.txt ---\n";
    ifstream inFile("students.txt");
    if (!inFile) {
        cerr << "Error: Could not open students.txt for reading!" << endl;
        return 1;
    }

    Student tempStudent; 
    
    float maxAverage = -1.0;
    char topStudentName[50];
    int topStudentRoll = -1;

    char header[256];
    inFile.getline(header, 256);
    
    cout << "RollNo\tName\tSub1\tSub2\tSub3\tSub4\tSub5\tTotal\tAverage\n";
    cout << "--------------------------------------------------------------------------------\n";
    
    while (inFile >> tempStudent.rollNo 
                  >> tempStudent.name 
                  >> tempStudent.marks[0] 
                  >> tempStudent.marks[1] 
                  >> tempStudent.marks[2] 
                  >> tempStudent.marks[3] 
                  >> tempStudent.marks[4] 
                  >> tempStudent.total 
                  >> tempStudent.average) {
        
        cout << tempStudent.rollNo << "\t"
             << tempStudent.name << "\t"
             << tempStudent.marks[0] << "\t"
             << tempStudent.marks[1] << "\t"
             << tempStudent.marks[2] << "\t"
             << tempStudent.marks[3] << "\t"
             << tempStudent.marks[4] << "\t"
             << tempStudent.total << "\t"
             << tempStudent.average << endl;
        
        if (tempStudent.average > maxAverage) {
            maxAverage = tempStudent.average;
            topStudentRoll = tempStudent.rollNo;
            
            for(int k = 0; k < 50; k++) {
                topStudentName[k] = tempStudent.name[k];
                if (tempStudent.name[k] == '\0') {
                    break;
                }
            }
        }
    }
    inFile.close();
    cout << "--------------------------------------------------------------------------------\n";

    if (topStudentRoll != -1) {
        cout << "\n--- Student with Highest Average ---\n";
        cout << "  Name:       " << topStudentName << endl;
        cout << "  Roll No:    " << topStudentRoll << endl;
        cout << "  Average:    " << maxAverage << endl;
    } else {
        cout << "\nNo records were read from the file.\n";
    }

    return 0;
}