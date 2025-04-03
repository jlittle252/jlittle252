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
    int hourPay = 20;
    int researchHours;
    int lectureHours;

    public:
    virtual void workDetails(){
            cout << "Enter worked Lab hours: ";
            cin >> labHours;
        if (labHours <= 10) {
            labHours = labHours;
        } 
        else {
            cout << "Worked hours cannot exceed 10." << endl;
            cout << "Please enter a valid number of worked hours." << endl;
            cin >> labHours;
        }
    }

    virtual void calculateMonthlyPay() {
        totalPayUTA = (labHours * hourPay);
        cout << "Total Monthly Pay: " << totalPayUTA << endl;
    }

    virtual void calculateNineMonthsPay() {
        int nineMonthsPay = totalPayUTA * 9;
        cout << "Total Pay for 9 Months: " << nineMonthsPay << endl;
    }
};

class MTA: public UTA{
    private:
    int totalPayMTA;

    public:
    void workDetails() override{
        cout << "Enter worked Lab hours: ";
            cin >> labHours;
        if (labHours <= 10) {
            labHours = labHours;
        } 
        else {
            cout << "Worked Lab hours cannot exceed 10." << endl;
            cout << "Please enter a valid number of worked hours." << endl;
            cin >> labHours;
        }
            cout << "Enter worked Lecture hours: ";
            cin >> lectureHours;
        if (lectureHours <= 3) {
            lectureHours = lectureHours;
        } 
        else {
            cout << "Worked Lecture hours cannot exceed 3." << endl;
            cout << "Please enter a valid number of worked lecture hours." << endl;
            cin >> lectureHours;
        }
    }
    // Function to calculate monthly pay
    void calculateMonthlyPay() override {
        totalPayMTA = (labHours * hourPay) + (lectureHours * hourPay);
        cout << "Total Monthly Pay: " << totalPayMTA << endl;
    }

    // Function to calculate 9 months pay
    void calculateNineMonthsPay() override {
        int nineMonthsPay = totalPayMTA * 9;
        cout << "Total Pay for 9 Months: " << nineMonthsPay << endl;
    }

};

class PHDTAR: public UTA{
    private:
    int totalPayPhDTAR;

    public:
    void workDetails() override{
            cout << "Enter worked Lab hours: ";
            cin >> labHours;
        if (labHours <= 10) {
            labHours = labHours;
        } 
        else {
            cout << "Worked Lab hours cannot exceed 10." << endl;
            cout << "Please enter a valid number of worked hours." << endl;
            cin >> labHours;
        }

            cout << "Enter worked Lecture hours: ";
            cin >> lectureHours;
        if (lectureHours <= 3) {
            lectureHours = lectureHours;
        } 
        else {
            cout << "Worked Lecture hours cannot exceed 3." << endl;
            cout << "Please enter a valid number of worked lecture hours." << endl;
            cin >> lectureHours;
        }
        // Research hours
            cout << "Enter research hours: ";
            cin >> researchHours;
        if (researchHours <= 7) {
            cout << "Enter research hours: ";
            cin >> researchHours;
        }
        else {
            cout << "Research hours cannot exceed 7." << endl;
            cout << "Please enter a valid number of research hours." << endl;
            cin >> researchHours;
        }
    }

    // Function to calculate monthly pay
    void calculateMonthlyPay() override {
        totalPayPhDTAR = (labHours * hourPay) + (lectureHours * hourPay) + (researchHours * hourPay);
        cout << "Total Monthly Pay: " << totalPayPhDTAR << endl;
    }
    // Function to calculate 9 months pay
    void calculateNineMonthsPay() override {
        int nineMonthsPay = totalPayPhDTAR * 9;
        cout << "Total Pay for 9 Months: " << nineMonthsPay << endl;
    }

};

void WelcomeMenu() {
    cout << "*************************************************" << endl;
    cout << "         Jianshe University          " << endl;
    cout << "        Student Payment System       " << endl;
    cout << "            -Main Menu-              " << endl;
    cout << "\n\n";
    cout << " U)  UTA Portal" << endl;
    cout << " M)  MTA Portal" << endl;
    cout << " I)  PhDTAR Portal" << endl;
    cout << " X)  Exit" << endl;
    cout << "==================================================" << endl;
}
void UtaWelcome() {
    cout << "****************************************" << endl;
    cout << "         - UTA Menu -        " << endl;
           
    cout << "       G) Enter Worked Hours" << endl;
    cout << "       H) View Months Payment" << endl;
    cout << "       I) View  9 Months Payment" << endl;
    cout << "       X) Exit" << endl;
    cout << "****************************************" << endl;
}
void MtaWelcome() {
    cout << "****************************************" << endl;
    cout << "         - MTA Menu -        " << endl;
    
    cout << "       J) Enter Worked Hours" << endl;
    cout << "       K) View Months Payment" << endl;
    cout << "       L) View  9 Months Payment" << endl;
    cout << "       X) Exit" << endl;
    cout << "****************************************" << endl;
}
void PhdTarWelcome() {
    cout << "****************************************" << endl;
    cout << "         - PhDTAR  Menu - " << endl;
    
    cout << "       A) Enter Worked Hours" << endl;
    cout << "       B) View Months Payment" << endl;
    cout << "       C) View  9 Months Payment" << endl;
    cout << "       X) Exit" << endl;
    cout << "****************************************" << endl;
}


int main() {
    char option;
    User uta1;
    UTA uta2;
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
        
                if (subOption == 'G') {
                    cout << "\n++++++Enter User Details++++++\n"<< endl;
                    uta1.enterDetails();
                    uta2.workDetails();
                    
                } else if(subOption == 'H'){
                    uta2.calculateMonthlyPay();

                } else if (subOption == 'I'){
                    uta2.calculateNineMonthsPay();
                    
                    
                
                    


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
                    cout << "\n++++++Enter User Details++++++\n"<< endl;
                    uta1.enterDetails();
                    
                } else if (subOption2 == 'B'){ 
                
                } else if (subOption2 == 'C'){

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

                if (subOption3 == 'J') {
                    cout << "\n++++++Enter User Details++++++\n"<< endl;
                    uta1.enterDetails();
                    
                } else if (subOption3 == 'K'){ 
                
                } else if (subOption3 == 'L'){
                    
                }

            } while (subOption3!= 'X');
        }

    } while (option != 'X');
    
    cout << "Exiting ..." << endl;
    return 0;
}
