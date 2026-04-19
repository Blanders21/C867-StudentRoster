#include "student.h"
#include <iostream>
using namespace std;

//Constructor
Student::Student(string id, string first, string last, string email, int age, int d1, int d2, int d3, DegreeProgram dp) {
    studentID = id;
    firstName = first;
    lastName = last;
    this->email = email;
    this->age = age;
    daysInCourse[0] = d1;
    daysInCourse[1] = d2;
    daysInCourse[2] = d3;
    degreeProgram = dp;
}

// Getters
string Student::getStudentID() { return studentID; }
string Student::getFirstName() { return firstName; }
string Student::getLastName() { return lastName; }
string Student::getEmail() { return email; }
int Student::getAge() { return age; }
int* Student::getDaysInCourse() { return daysInCourse; }
DegreeProgram Student::getDegreeProgram() { return degreeProgram; }

// Setters
void Student::setStudentID(string id) { studentID = id; }
void Student::setFirstName(string first) { firstName = first; }
void Student::setLastName(string last) { lastName = last; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }

void Student::setDaysInCourse(int d1, int d2, int d3) {
    daysInCourse[0] = d1;
    daysInCourse[1] = d2;
    daysInCourse[2] = d3;
}

void Student::setDegreeProgram(DegreeProgram dp) { degreeProgram = dp; }


// Print function
void Student::print() {
    string degreeStr;

    if (degreeProgram == SECURITY) degreeStr = "SECURITY";
    else if (degreeProgram == NETWORK) degreeStr = "NETWORK";
    else degreeStr = "SOFTWARE";

    cout << studentID << "\t"
        << "First Name: " << firstName << "\t"
        << "Last Name: " << lastName << "\t"
        << "Email: " << email << "\t"
        << "Age: " << age << "\t"
        << "Days: {" << daysInCourse[0] << ", "
        << daysInCourse[1] << ", "
        << daysInCourse[2] << "} "
        << "Degree: " << degreeStr << endl;
}
