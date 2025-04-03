#include <iostream>
using namespace std;

// Base class: UTA (Undergraduate Teaching Assistant)
class UTA {
protected:
    int labHours;
public:
    UTA() : labHours(10) {}  // Default lab hours = 10
    
    // Virtual function for dynamic polymorphism
    virtual void workDetails() {
        cout << "UTA can work " << labHours << " hours per week in the laboratory.\n";
    }
};

// Derived class: MTA (Master's Teaching Assistant) - Single Inheritance
class MTA : public UTA {
protected:
    int lectureHours;
public:
    MTA() : lectureHours(3) {}  // 3 lectures of 1 hour each
    
    // Overriding workDetails() - Dynamic Polymorphism
    void workDetails() override {
        cout << "MTA can work " << labHours << " hours in the lab and give " 
             << lectureHours << " one-hour lectures per week.\n";
    }
    
    // Function overloading - Static Polymorphism
    void workDetails(bool detailed) {
        if (detailed) {
            cout << "MTA Work Breakdown:\n";
            cout << "- Lab Work: " << labHours << " hours per week\n";
            cout << "- Lectures: " << lectureHours << " one-hour sessions per week\n";
        } else {
            workDetails();
        }
    }
};

// Derived class: PhDTAR (PhD Teaching and Research Assistant)
class PhDTAR : public MTA {
private:
    int researchHours;
public:
    PhDTAR() : researchHours(7) {}  // Additional 7 research hours
    
    // Overriding workDetails() - Dynamic Polymorphism
    void workDetails() override {
        cout << "PhDTAR can work " << labHours << " hours in the lab, give " 
             << lectureHours << " one-hour lectures, and conduct "
             << researchHours << " hours of research per week.\n";
    }
    
    // Function overloading - Static Polymorphism
    void workDetails(bool detailed) {
        if (detailed) {
            cout << "PhDTAR Work Breakdown:\n";
            cout << "- Lab Work: " << labHours << " hours per week\n";
            cout << "- Lectures: " << lectureHours << " one-hour sessions per week\n";
            cout << "- Research: " << researchHours << " hours per week\n";
        } else {
            workDetails();
        }
    }
};

int main() {
    // Static Binding (Compile-Time Polymorphism)
    cout << "Using Static Polymorphism (Function Overloading):\n";
    MTA mtaObj;
    PhDTAR phdTarObj;
    mtaObj.workDetails(true);   // Detailed MTA work breakdown
    phdTarObj.workDetails(true); // Detailed PhDTAR work breakdown
    cout << "\n";

    // Dynamic Binding (Run-Time Polymorphism)
    cout << "Using Dynamic Polymorphism (Virtual Functions):\n";
    UTA* ptr1 = &mtaObj;
    UTA* ptr2 = &phdTarObj;
    
    ptr1->workDetails();  // Calls overridden function in MTA
    ptr2->workDetails();  // Calls overridden function in PhDTAR

    return 0;
}
