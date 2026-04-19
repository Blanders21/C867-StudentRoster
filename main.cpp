#include <iostream>
#include "roster.h"
using namespace std;

int main() {

    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,First,Last,email@email.com,25,30,35,40,SOFTWARE"
    };

    cout << "Course: C867 - Scripting and Programming\n";
    cout << "Language: C++\n";
    cout << "Student ID: YOUR_ID\n";
    cout << "Name: YOUR NAME\n\n";

    Roster classRoster;

    for (int i = 0; i < 5; i++) {

        string data = studentData[i];

        string studentID = data.substr(0, data.find(","));
        data.erase(0, data.find(",") + 1);

        string firstName = data.substr(0, data.find(","));
        data.erase(0, data.find(",") + 1);

        string lastName = data.substr(0, data.find(","));
        data.erase(0, data.find(",") + 1);

        string email = data.substr(0, data.find(","));
        data.erase(0, data.find(",") + 1);

        int age = stoi(data.substr(0, data.find(",")));
        data.erase(0, data.find(",") + 1);

        int d1 = stoi(data.substr(0, data.find(",")));
        data.erase(0, data.find(",") + 1);

        int d2 = stoi(data.substr(0, data.find(",")));
        data.erase(0, data.find(",") + 1);

        int d3 = stoi(data.substr(0, data.find(",")));
        data.erase(0, data.find(",") + 1);

        string degreeStr = data;

        DegreeProgram dp;
        if (degreeStr == "SECURITY") dp = SECURITY;
        else if (degreeStr == "NETWORK") dp = NETWORK;
        else dp = SOFTWARE;

        classRoster.add(studentID, firstName, lastName, email, age, d1, d2, d3, dp);
    }

    classRoster.printAll();

    cout << "\nInvalid Emails:\n";
    classRoster.printInvalidEmails();

    cout << "\nAverage Days:\n";
    classRoster.printAverageDaysInCourse("A1");
    classRoster.printAverageDaysInCourse("A2");
    classRoster.printAverageDaysInCourse("A3");
    classRoster.printAverageDaysInCourse("A4");
    classRoster.printAverageDaysInCourse("A5");

    cout << "\nSoftware Students:\n";
    classRoster.printByDegreeProgram(SOFTWARE);

    cout << "\nRemoving A3:\n";
    classRoster.remove("A3");

    classRoster.printAll();

    cout << "\nRemoving A3 again:\n";
    classRoster.remove("A3");

    return 0;
}