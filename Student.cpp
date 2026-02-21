#include "Student.h"
#include <iostream>
#include <sstream>

Student::Student() {
    indexNumber = "";
    name = "";
    program = "";
    yearLevel = 0;
}

Student::Student(string idx, string nm, string prog, int year) {
    indexNumber = idx;
    name = nm;
    program = prog;
    yearLevel = year;
}

string Student::getIndexNumber() const {
    return indexNumber;
}

string Student::getName() const {
    return name;
}

string Student::getProgram() const {
    return program;
}

int Student::getYearLevel() const {
    return yearLevel;
}

void Student::display() const {
    cout << "Index: " << indexNumber
         << " | Name: " << name
         << " | Program: " << program
         << " | Year: " << yearLevel << endl;
}

string Student::toFileString() const {
    return indexNumber + "|" + name + "|" + program + "|" + to_string(yearLevel);
}

Student Student::fromFileString(const string& line) {
    stringstream ss(line);
    string idx, nm, prog, yearStr;

    getline(ss, idx, '|');
    getline(ss, nm, '|');
    getline(ss, prog, '|');
    getline(ss, yearStr, '|');

    return Student(idx, nm, prog, stoi(yearStr));
}
