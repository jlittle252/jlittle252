#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void WelcomeMenu() {
    cout << "*************************************************" << endl;
    cout << "         Jianshe University          " << endl;
    cout << "        Student Payment System       " << endl;
    cout << "            -Main Menu-              " << endl;
    cout << "\n\n";
    cout << " U)  UTA Log In" << endl;
    cout << " M)  MTA Log In" << endl;
    cout << " I)  PhDTAR Log In" << endl;
    cout << " X)  Exit" << endl;
    cout << "==================================================" << endl;
}
void PhdTarWelcome() {
    cout << "****************************************" << endl;
    cout << "         - PhDTAR  Menu - " << endl;
    cout << "       A) New TAR Enter" << endl;
    cout << "       B) Enter Worked Hours" << endl;
    cout << "       C) View Months Payment" << endl;
    cout << "       D) View  9 Months Payment" << endl;
    cout << "       X) Exit" << endl;
    cout << "****************************************" << endl;
}
void UtaWelcome() {
    cout << "****************************************" << endl;
    cout << "         - UTA Menu -        " << endl;
    cout << "       F) New UTA Enter" << endl;
    cout << "       G) Enter Worked Hours" << endl;
    cout << "       H) View Months Payment" << endl;
    cout << "       I) View  9 Months Payment" << endl;
    cout << "       X) Exit" << endl;
    cout << "****************************************" << endl;
}

void MtaWelcome() {
    cout << "****************************************" << endl;
    cout << "         - MTA Menu -        " << endl;
    cout << "       J) New MTA Enter" << endl;
    cout << "       K) Enter Worked Hours" << endl;
    cout << "       L) View Months Payment" << endl;
    cout << "       M) View  9 Months Payment" << endl;
    cout << "       X) Exit" << endl;
    cout << "****************************************" << endl;
}



void newToCSV() {
    ofstream file("masterFile.csv", ios::app);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }
    
    string firstName, lastName, address, id;
    cout << "Enter First Name: "; cin >> firstName;
    cout << "Enter Last Name: "; cin >> lastName;
    cout << "Enter Address: "; cin >> address;
    cout << "Enter ID: "; cin >> id;
    
    file << firstName << "," << lastName << "," << address << "," << id << "\n";
    file.close();
    cout << "TA Added Successfully!" << endl;
}

void enterHours() {
    ofstream file("masterFile.csv", ios::app);
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }
    
    string hours;
    double grade;
    cout << "Enter Worked Hours: "; cin >> hours;
    
    
    file << hours <<  "\n";
    file.close();
    cout << "Hours Recorded Successfully!" << endl;
}

int main() {
    char option;
    do{
        WelcomeMenu();
        cout << "Enter Main Menu Option: ";
        cin >> option;
        option = toupper(option);
        
        if (option == 'U') {
            char subOption;
            do {
                UtaWelcome();
                cout << "Enter UTA Menu Option: ";
                cin >> option;
                subOption = toupper(subOption);
        
                if (subOption == 'F') {
                    enterHours();
                } else if (subOption == 'G') {
                    newToCSV();
                } else if (subOption == 'H') {
                    newToCSV();
                } else if (subOption == 'I') {
                    newToCSV();
                } // D
            } while (subOption != 'X');
        
        }//option 
        
        else if (option == 'I') {
            char subOption2;
            do {
                PhdTarWelcome();
                cout << "Enter PhdTar Menu Option: ";
                cin >> option;
                subOption2 = toupper(subOption2);
                
                if (subOption2 == 'A') {
                    enterHours();
                } else if (subOption2 == 'B') {
                    newToCSV();
                } else if (subOption2 == 'C') {
                    newToCSV();
                } else if (subOption2 == 'D') {
                    newToCSV();
                } // D
            } while (subOption2 != 'X');
        } 
        
        else if (option == 'M'){
            char subOption3;
            do {
                MtaWelcome();
                cout << "Enter MTA Menu Option: ";
                cin >> subOption3;
                subOption3 = toupper(subOption3);

                if (subOption3 == 'J'){
                    newToCSV();
                } else if (subOption3 =='K'){
                    newToCSV();
                }else if (subOption3 =='L'){
                    newToCSV();
                }else if (subOption3 =='M'){
                    newToCSV();
                }//M
            } while (subOption3!= 'X');
        }// else if

    } while (option != 'X');
    
    cout << "Exiting ..." << endl;
    return 0;
}

    
            
