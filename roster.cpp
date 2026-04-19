#include "roster.h"
#include <iostream>
using namespace std;

Roster::Roster() {
    lastIndex = -1;
}

// add function to create a new student and add it to the roster
void Roster::add(string id, string first, string last, string email, int age, int d1, int d2, int d3, DegreeProgram dp) {
    lastIndex++;
    classRosterArray[lastIndex] = new Student(id, first, last, email, age, d1, d2, d3, dp);
}

// Print all students in the roster
void Roster::printAll() {
    for (int i = 0; i <= lastIndex; i++) {
        classRosterArray[i]->print();
    }
}

void Roster::remove(string studentID) {
    bool found = false;

    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            found = true;

            delete classRosterArray[i];

            for (int j = i; j < lastIndex; j++) {
                classRosterArray[j] = classRosterArray[j + 1];
            }

            lastIndex--;
            break;
        }
    }

    if (!found) {
        cout << "Student with ID " << studentID << " not found.\n";
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {

            int* days = classRosterArray[i]->getDaysInCourse();
            int avg = (days[0] + days[1] + days[2]) / 3;

            cout << "Student ID: " << studentID
                << ", Average Days: " << avg << endl;
        }
    }
}

void Roster::printInvalidEmails() {
    for (int i = 0; i <= lastIndex; i++) {
        string email = classRosterArray[i]->getEmail();

        if (email.find("@") == string::npos ||
            email.find(".") == string::npos ||
            email.find(" ") != string::npos) {

            cout << email << " is invalid.\n";
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram dp) {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getDegreeProgram() == dp) {
            classRosterArray[i]->print();
        }
    }
}

Roster::~Roster() {
    for (int i = 0; i <= lastIndex; i++) {
        delete classRosterArray[i];
    }
}