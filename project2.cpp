#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void WelcomeMenu() {
    cout << "*************************************************" << endl;
    cout << "         Grade Book Log In          " << endl;
    cout << "            -Main Menu-              " << endl;
    cout << "\n\n";
    cout << " S)  Student Log In" << endl;
    cout << " I)  Instructor Log In" << endl;
    cout << " E)  Exit" << endl;
    cout << "==================================================" << endl;
}

void StudentWelcome() {
    cout << "****************************************" << endl;
    cout << "         - Student Menu -        " << endl;
    cout << "       J) View Weighted Grade Total" << endl;
    cout << "       K) View All Assignment Grades" << endl;
    cout << "       E) Exit" << endl;
    cout << "****************************************" << endl;
}

void profWelcome() {
    cout << "****************************************" << endl;
    cout << "         - Instructor  Menu - " << endl;
    cout << "       A) Enter Grades" << endl;
    cout << "       B) Delete Assignment" << endl;
    cout << "       C) View Grades" << endl;
    cout << "       D) Enter Student" << endl;
    cout << "       X) Exit" << endl;
    cout << "****************************************" << endl;
}

void addStudentToCSV() {
    ofstream file("students.csv", ios::app);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }
    
    string firstName, lastName, email;
    cout << "Enter First Name: "; cin >> firstName;
    cout << "Enter Last Name: "; cin >> lastName;
    cout << "Enter Email: "; cin >> email;
    
    file << firstName << "," << lastName << "," << email << "\n";
    file.close();
    cout << "Student added successfully!" << endl;
}

void enterGradeToCSV() {
    ofstream file("grades.csv", ios::app);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }
    
    string email, assignment;
    double grade;
    cout << "Enter Student Email: "; cin >> email;
    cout << "Enter Assignment Name: "; cin >> assignment;
    cout << "Enter Grade: "; cin >> grade;
    
    file << email << "," << assignment << "," << grade << "\n";
    file.close();
    cout << "Grade recorded successfully!" << endl;
}

int main() {
    char option = 'Z';
    WelcomeMenu();
    while (option != 'E') {
        cout << "Enter Main Menu Option: ";
        cin >> option;
        option = toupper(option);
        
        if (option == 'S') {
            StudentWelcome();
        } else if (option == 'I') {
            profWelcome();
            char profOption;
            cout << "Enter Instructor Menu Option: ";
            cin >> profOption;
            profOption = toupper(profOption);
            
            if (profOption == 'A') {
                enterGradeToCSV();
            } else if (profOption == 'D') {
                addStudentToCSV();
            }
        } else if (option == 'E') {
            cout << "Exiting Grade Book..." << endl;
        }
    }
    return 0;
}
