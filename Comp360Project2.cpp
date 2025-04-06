
 
// This program is a student payment system that allows users to enter their details and calculate their monthly and 9-month pay based on their work hours.

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
            cout << "\n \n";
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
            cout << "Enter Lab hours: ";
            cin >> labHours;
        if (labHours <= 10) {
            labHours = labHours;
        } 
        else {
            cout << "* * * * * * * ************************ * * * * * * *" << endl;
            cout << "Lab hours cannot exceed 10." << endl;
            cout << "Please enter a valid number of worked Lab hours." << endl;
            cin >> labHours;
            cout << "* * * * * * * ************************ * * * * * * *" << endl;
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

    void calulateMonthlyPay(int weeks){
        int totalWeeksPay;
        totalWeeksPay = (labHours * hourPay) * weeks;
        cout << "Total pay for " << weeks << " weeks: " << totalWeeksPay << endl;
    }
};

class MTA: public UTA{
    private:
    int totalPayMTA;

    public:
    void workDetails() override{
        cout << "Enter Lab hours: ";
            cin >> labHours;
        if (labHours <= 10) {
            labHours = labHours;
        } 
        else {
            cout << "* * * * * * * ************************ * * * * * * *" << endl;
            cout << "Lab hours cannot exceed 10." << endl;
            cout << "Please enter a valid number of worked Lab hours." << endl;
            cin >> labHours;
            cout << "* * * * * * * ************************ * * * * * * *" << endl;
        }
            cout << "Enter Lecture hours:  ";
            cin >> lectureHours;
        if (lectureHours <= 3) {
            lectureHours = lectureHours;
        } 
        else {
            cout << "* * * * * * * ************************ * * * * * * *" << endl;
            cout << "Worked Lecture hours cannot exceed 3." << endl;
            cout << "Please enter a valid number of worked lecture hours." << endl;
            cin >> lectureHours;
            cout << "* * * * * * * ************************ * * * * * * *" << endl;
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

    void calulateMonthlyPay(int weeks){
        int totalWeeksPay;
        totalWeeksPay = ((labHours * hourPay) + (lectureHours * hourPay)) * weeks;
        cout << "Total pay for " << weeks << " weeks: " << totalWeeksPay << endl;
    }

};

class PHDTAR: public UTA{
    private:
    int totalPayPhDTAR;

    public:
    void workDetails() override{
            cout << "Enter Lab hours :  ";
            cin >> labHours;
        if (labHours <= 10) {
            labHours = labHours;
        } 
        else {
            cout << "* * * * * * * ************************ * * * * * * *" << endl;
            cout << "Lab hours cannot exceed 10." << endl;
            cout << "Please enter a valid number of worked Lab hours." << endl;
            cin >> labHours;
            cout << "* * * * * * * ************************ * * * * * * *" << endl;
        }

            cout << "Enter Lecture hours: ";
            cin >> lectureHours;
        if (lectureHours <= 3) {
            lectureHours = lectureHours;
        } 
        else {
            cout << "* * * * * * * ************************ * * * * * * *" << endl;
            cout << "Worked Lecture hours cannot exceed 3." << endl;
            cout << "Please enter a valid number of worked lecture hours." << endl;
            cin >> lectureHours;
            cout << "* * * * * * * ************************ * * * * * * *" << endl;
        }
        // Research hours
            cout << "Enter research hours: ";
            cin >> researchHours;
        if (researchHours <= 7) {
            researchHours = researchHours;

        }
        else {
            cout << "* * * * * * * ************************ * * * * * * *" << endl;
            cout << "Research hours cannot exceed 7." << endl;
            cout << "Please enter a valid number of research hours." << endl;
            cin >> researchHours;
            cout << "* * * * * * * ************************ * * * * * * *" << endl;
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

    void calulateMonthlyPay(int weeks){
        int totalWeeksPay;
        totalWeeksPay = ((labHours * hourPay) + (lectureHours * hourPay) + (researchHours * hourPay)) * weeks;
        cout << "Total pay for " << weeks << " weeks: " << totalWeeksPay << endl;
    }
};

void WelcomeMenu() {
    cout << "*************************************************" << endl;
    cout << "          Jianshe University          " << endl;
    cout << "        Student Payment System       " << endl;
    cout << "            -Main Menu-              " << endl;
    cout << "\n\n";
    cout << " U)  UTA Portal" << endl;
    cout << " M)  MTA Portal" << endl;
    cout << " P)  PhDTAR Portal" << endl;
    cout << " X)  Exit" << endl;
    cout << "==================================================" << endl;
}
void UtaWelcome() {
    cout << "****************************************" << endl;
    cout << "         - UTA Menu -        " << endl;
           
    cout << "       G) Enter Worked Hours" << endl;
    cout << "       H) View Months Payment" << endl;
    cout << "       I) View  9 Months Payment" << endl;
    cout << "       J) Calculate Any Number of Weeks Pay" << endl;
    cout << "       X) Exit" << endl;
    cout << "****************************************" << endl;
}
void MtaWelcome() {
    cout << "****************************************" << endl;
    cout << "         - MTA Menu -        " << endl;
    
    cout << "       J) Enter Worked Hours" << endl;
    cout << "       K) View Months Payment" << endl;
    cout << "       L) View  9 Months Payment" << endl;
    cout << "       M) Calculate Any Number of Weeks Pay" << endl;
    cout << "       X) Exit" << endl;
    cout << "****************************************" << endl;
}
void PhdTarWelcome() {
    cout << "****************************************" << endl;
    cout << "         - PhDTAR  Menu - " << endl;
    
    cout << "       A) Enter Worked Hours" << endl;
    cout << "       B) View Months Payment" << endl;
    cout << "       C) View  9 Months Payment" << endl;
    cout << "       D) Calculate Any Number of Weeks Pay" << endl;
    cout << "       X) Exit" << endl;
    cout << "****************************************" << endl;
}


int main() {
    char option;
    User uta1;
    UTA uta2;
    MTA mta;

    // pointers for MTA and PHDTAR CLasses
    // MTA and PHDTAR are derived from UTA
    UTA* mtaPtr = &mta;
    UTA* mtaPtr2 = &mta;
    PHDTAR phd;
    UTA* ptr1 = &phd;
    UTA* ptr2 = &phd;
     
    do {
        WelcomeMenu();
        cout << "Enter Main Menu Option: ";
        cin >> option;
        option = toupper(option);
        
        if (option == 'U') {//UTA portal
            char subOption;
            
            do {
                UtaWelcome();
                cout << "Enter UTA Menu Option: ";
                cin >> subOption;
                subOption = toupper(subOption);
                // Enter worked Hours(this will also prompt for user info i.e Name, Address, ID)
                if (subOption == 'G') {
                    cout << "\n++++++Enter UTA User Details++++++\n"<< endl;
                    uta1.enterDetails();
                    uta2.workDetails();
                }
                // View Monthly Payment 
                else if(subOption == 'H'){
                    uta1.displayDetails();
                    uta2.calculateMonthlyPay();

                } 
                //View Months Payment
                else if (subOption == 'I'){ 
                    uta1.displayDetails();
                    uta2.calculateNineMonthsPay();
                }
                // Option to allow user to calculate pay for any chosen number of weeks
                else if (subOption == 'J'){
                    int weeks;
                    cout << "Enter number of weeks: ";
                    cin >> weeks;
                    uta1.displayDetails();
                    uta2.calulateMonthlyPay(weeks);
                }
                
            } while (subOption != 'X'); // Exit UTA portal
        
        }
        
        else if (option == 'P') { //PHDTAR Portal
            char subOption2;
            
            do {
                PhdTarWelcome();
                cout << "Enter PhdTar Menu Option: ";
                cin >> subOption2;
                subOption2 = toupper(subOption2);
                
                // Enter worked Hours(this will also prompt for user info i.e Name, Address, ID)
                if (subOption2 == 'A') {
                    cout << "\n++++++PhdTar User Details++++++\n"<< endl;
                    uta1.enterDetails();
                    ptr1->workDetails();
                } 
                // View Monthly Payment
                else if (subOption2 == 'B'){ 
                    uta1.displayDetails();
                    ptr2->calculateMonthlyPay();
                } 
                //View Nine Months Payment
                else if (subOption2 == 'C'){
                    uta1.displayDetails();
                    ptr2->calculateNineMonthsPay();
                }
                 // Option to allow user to calculate pay for any chosen number of weeks
                else if (subOption2 == 'D'){
                    int weeks;
                    cout << "Enter number of weeks: ";
                    cin >> weeks;
                    uta1.displayDetails();
                    uta2.calulateMonthlyPay(weeks);
                }
            } while (subOption2 != 'X'); // Exit PHDTAR Portal
        } 
        
        else if (option == 'M') { //MTA Portal
            char subOption3;
            do {
                MtaWelcome();
                cout << "Enter MTA Menu Option: ";
                cin >> subOption3;
                subOption3 = toupper(subOption3);

                // Enter worked Hours(this will also prompt for user info i.e Name, Address, ID)
                if (subOption3 == 'J') {
                    cout << "\n++++++Enter MTA User Details++++++\n"<< endl;
                    uta1.enterDetails();
                    mtaPtr->workDetails();
                } 
                //View Monthly Payment
                else if (subOption3 == 'K'){ 
                    uta1.displayDetails();
                    mtaPtr2->calculateMonthlyPay();
                } 
                // View Nine Months Payment
                else if (subOption3 == 'L'){
                    uta1.displayDetails();
                    mtaPtr2->calculateNineMonthsPay();
                }
                // Option to allow user to calculate pay for any chosen number of weeks
                else if (subOption3 == 'M'){
                    int weeks;
                    cout << "Enter number of weeks: ";
                    cin >> weeks;
                    uta1.displayDetails();
                    uta2.calulateMonthlyPay(weeks);
                }
            } while (subOption3!= 'X'); //Exit MTA portal
        }

    } while (option != 'X'); // Exit Main Menu
    
    cout<< "\n\n";
    cout << "                 *                  " << endl;
    cout << "                * *                 " << endl;
    cout << "               * * *                " << endl;
    cout << "              * * * *               " << endl;
    cout<< "\n\n";
    cout << "* * * * * * * Goodbye * * * * * * *" << endl;
    cout<< "\n\n";
    cout << "              * * * *               " << endl;
    cout << "               * * *                " << endl;
    cout << "                * *                 " << endl;
    cout << "                 *                  " << endl;
    return 0;
    return 0;
}// end of code
