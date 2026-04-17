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