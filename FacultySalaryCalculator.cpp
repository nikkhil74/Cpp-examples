#include <iostream>
#include <string>
using namespace std;

// Base class
class FacultyMember {
public:
    string name;
    int id;
    string department;

    FacultyMember(string n, int i, string d) : name(n), id(i), department(d) {}

    virtual float calculateSalary() = 0; // Pure virtual function

    void displayInfo() {
        cout << "Name: " << name << ", ID: " << id << ", Department: " << department << endl;
    }
};

// Derived class 1
class Professor : virtual public FacultyMember {
public:
    Professor(string n, int i, string d) : FacultyMember(n, i, d) {}

    float calculateSalary() override {
        return 100000; // Base salary for Professor
    }
};

// Derived class 2
class AssociateProfessor : virtual public FacultyMember {
public:
    AssociateProfessor(string n, int i, string d) : FacultyMember(n, i, d) {}

    float calculateSalary() override {
        return 80000; // Base salary for Associate Professor
    }
};

// Derived class 3
class AssistantProfessor : virtual public FacultyMember {
public:
    AssistantProfessor(string n, int i, string d) : FacultyMember(n, i, d) {}

    float calculateSalary() override {
        return 60000; // Base salary for Assistant Professor
    }
};

// Additional role 1
class Researcher : virtual public FacultyMember {
public:
    Researcher(string n, int i, string d) : FacultyMember(n, i, d) {}

    void conductResearch() {
        cout << name << " is conducting research." << endl;
    }
};

// Additional role 2
class Administrator : virtual public FacultyMember {
public:
    Administrator(string n, int i, string d) : FacultyMember(n, i, d) {}

    void manageDepartment() {
        cout << name << " is managing the department." << endl;
    }
};

// Combined role using multiple inheritance
class DualRoleFaculty : public Professor, public Researcher {
public:
    DualRoleFaculty(string n, int i, string d)
        : FacultyMember(n, i, d), Professor(n, i, d), Researcher(n, i, d) {}

    float calculateSalary() override {
        return Professor::calculateSalary() + 20000; // Bonus for research
    }
};

int main() {
    DualRoleFaculty drf("Dr. Smith", 101, "Computer Science");

    drf.displayInfo();
    cout << "Total Salary: $" << drf.calculateSalary() << endl;
    drf.conductResearch();

    return 0;
}
