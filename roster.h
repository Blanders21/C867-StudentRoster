#pragma once
#include "student.h"

class Roster {
private:
    Student* classRosterArray[5];
    int lastIndex;

public:
    Roster();
    void add(string, string, string, string, int, int, int, int, DegreeProgram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram dp);
    ~Roster();
};
