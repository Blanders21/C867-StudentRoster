#pragma once
#include <string>
#include "degree.h"
using namespace std;

class Student {
private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int daysInCourse[3];
    DegreeProgram degreeProgram;

public:
    // Constructor
    Student(string id, string first, string last, string email, int age, int d1, int d2, int d3, DegreeProgram dp);

    // Getters
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getDaysInCourse();
    DegreeProgram getDegreeProgram();

    // Setters
    void setStudentID(string id);
    void setFirstName(string first);
    void setLastName(string last);
    void setEmail(string email);
    void setAge(int age);
    void setDaysInCourse(int d1, int d2, int d3);
    void setDegreeProgram(DegreeProgram dp);

    void print();
};

