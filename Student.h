#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    string indexNumber;
    string name;
    string program;
    string yearLevel;

public:
    Student();
    Student(string idx, string nm, string prog, string year);

    string getIndexNumber() const;
    string getName() const;
    string getProgram() const;
    string getYearLevel() const;

    void display() const;

    string toFileString() const;
    static Student fromFileString(const string& line);
};

#endif
