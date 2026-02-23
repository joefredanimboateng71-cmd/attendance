#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include "Student.h"
#include "AttendanceSession.h"

using namespace std;

vector<Student> students;
vector<AttendanceSession> sessions;

void loadStudents();
void saveStudents();
void studentMenu();
void attendanceMenu();
bool studentExists(string indexNumber);

int main() {
    loadStudents();
    cout << "NEW VERSION 1.4";
    int choice;

    do {
        cout << "\n===== DIGITAL ATTENDANCE SYSTEM =====\n";
        cout << "1. Student Management\n";
        cout << "2. Attendance Session Management\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            studentMenu();
            break;
        case 2:
            attendanceMenu();
            break;
        case 3:
            saveStudents();
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 3);

    return 0;
}
void studentMenu() {
    int choice;

    do {
        cout << "\n--- Student Menu ---\n";
        cout << "1. Register Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Back\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            string idx, name, program;
            string year;

            cout << "Index Number: ";
            cin >> idx;

            if (studentExists(idx)) {
                cout << "Student already exists.\n";
                continue;
            }

            cin.ignore();
            cout << "Name: ";
            getline(cin, name);

            cout << "Program: ";
            getline(cin, program);

            cout << "Year Level: ";
            cin >> year;

            students.push_back(Student(idx, name, program, year));
            cout << "Student registered.\n";
        }
        else if (choice == 2) {
            for (const auto& s : students) {
                s.display();
            }
        }
        else if (choice == 3) {
            string idx;
            cout << "Enter index number: ";
            cin >> idx;

            bool found = false;
            for (const auto& s : students) {
                if (s.getIndexNumber() == idx) {
                    s.display();
                    found = true;
                }
            }
            if (!found)
                cout << "Student not found.\n";
        }

    } while (choice != 4);
}
void attendanceMenu() {
    int choice;

    do {
        cout << "\n--- Attendance Menu ---\n";
        cout << "1. Create Session\n";
        cout << "2. Back\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            string code, date, time;
            int duration;

            cout << "Course Code: ";
            cin.ignore();
            getline(cin,code);
            cout << "Date: ";
            cin >> date;
            cout << "Start Time: ";
            cin.ignore();
            getline(cin,time);
            cout << "Duration: ";
            cin >> duration;

            AttendanceSession session(code, date, time, duration);

            string idx, status;
            char more;

            do {
                cout << "Student Index: ";
                cin >> idx;

                if (!studentExists(idx)) {
                    cout << "Student not registered.\n";
                    continue;
                }

                cout << "Status (Present/Absent/Late): ";
                cin >> status;

                session.markAttendance(idx, status);

                cout << "Add another? (y/n): ";
                cin >> more;

            } while (more == 'y' || more == 'Y');

            sessions.push_back(session);

            ofstream file("sessions.txt", ios::app);
            file << session.toFileString();
            file.close();

            cout << "Session saved.\n";
        }

    } while (choice != 2);
}
void loadStudents() {
    ifstream file("students.txt");
    string line;

    while (getline(file, line)) {
        if (!line.empty()) {
            students.push_back(Student::fromFileString(line));
        }
    }
    file.close();
}

void saveStudents() {
    ofstream file("students.txt");

    for (const auto& s : students) {
        file << s.toFileString() << endl;
    }

    file.close();
}

bool studentExists(string indexNumber) {
    for (const auto& s : students) {
        if (s.getIndexNumber() == indexNumber)
            return true;
    }
    return false;
}