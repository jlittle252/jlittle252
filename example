include <iostream>
#include <string>
using namespace std;

// Define a User class
class User {
private:
    string firstName;
    string lastName;
    string id;
    string address;

public:
    // Function to get user details
    void enterDetails() {
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

int main() {
    User user1;  // Create an object of User

    // Enter and display user details
    cout << "Enter User Details:\n";
    user1.enterDetails();

    cout << "\nDisplaying User Details:\n";
    user1.displayDetails();

    return 0;
}
