#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class User {
    private:
        string firstName;
        string lastName;
        string id;
        string address;
   

    public:
        // Function to get user details
        void enterDetails() {
            cin.ignore();
            cout << "Enter First Name: ";
            getline(cin, firstName);
            cout << "Enter Last Name: ";
            getline(cin, lastName);
            cout << "Enter ID: ";
            getline(cin, id);
            cout << "Enter Address: ";
            getline(cin, address);
        }
    
        // Function to display user details
        void displayDetails() const {
            cout << "\nUser Information:\n";
            cout << "First Name: " << firstName << endl;
            cout << "Last Name: " << lastName << endl;
            cout << "ID: " << id << endl;
            cout << "Address: " << address << endl;
        }
    };

class UTA {
    private:
    int totalPayUTA;

    protected:
    int labHours;
    int hourPay;
    int researchHours;
    int lectureHours;

    public:
    virtual void workDetails(){
        cout << "Enter worked hours: ";
        cin >> labHours;
    }

    void calculateMonthlyPay() {
        totalPayUTA = (labHours * hourPay);
        cout << "Total Monthly Pay: " << totalPayUTA << endl;
    }

    void calculateNineMonthsPay() {
        int nineMonthsPay = totalPayUTA * 9;
        cout << "Total Pay for 9 Months: " << nineMonthsPay << endl;
    }
};

class MTA: public UTA{
    private:
    int totalPayMTA;

    public:

    void workDetails() override{
        cout << "Enter worked hours: ";
        cin >> labHours;
        cout << "Enter lecture hours: ";
        cin >> lectureHours;
    }

};

class PHDTAR: public UTA{
    private:
    int totalPayPhDTAR;

    public:
    void workDetails() override{
        cout << "Enter worked hours: ";
        cin >> labHours;
        cout << "Enter lecture hours: ";
        cin >> lectureHours;
        cout << "Enter research hours: ";
        cin >> researchHours;
    }

};

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


int main() {
    char option;
    User uta1;
    do {
        WelcomeMenu();
        cout << "Enter Main Menu Option: ";
        cin >> option;
        option = toupper(option);
        
        if (option == 'U') {
            char subOption;
            
            do {
                UtaWelcome();
                cout << "Enter UTA Menu Option: ";
                cin >> subOption;
                subOption = toupper(subOption);
        
                if (subOption == 'F') {
                    
                    cout << "\n++++++Enter User Details++++++\n"<< endl;
                    uta1.enterDetails();


                } else if (subOption == 'G') {
                    
                } else if(subOption == 'H'){

                } else if (subOption == 'I'){
                    
                    
                    cout << "\nDisplaying User Details:\n";
                    uta1.displayDetails();
                    


                }
                
            } while (subOption != 'X');
        
        }//option 
        
        else if (option == 'I') {
            char subOption2;
            do {
                PhdTarWelcome();
                cout << "Enter PhdTar Menu Option: ";
                cin >> subOption2;
                subOption2 = toupper(subOption2);
                
                if (subOption2 == 'A') {
                    
                } else if (subOption2 == 'B'||subOption2 == 'C'||subOption2 == 'D') {
                    
                } 
            } while (subOption2 != 'X');
        } 
        
        else if (option == 'M') {
            char subOption3;
            do {
                MtaWelcome();
                cout << "Enter MTA Menu Option: ";
                cin >> subOption3;
                subOption3 = toupper(subOption3);

                if (subOption3 == 'J'||subOption3 =='K'||subOption3 =='L'||subOption3 =='M'){
                    
                }

            } while (subOption3!= 'X');
        }

    } while (option != 'X');
    
    cout << "Exiting ..." << endl;
    return 0;
}
