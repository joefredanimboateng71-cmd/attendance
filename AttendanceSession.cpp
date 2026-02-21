#include "AttendanceSession.h"
#include <iostream>
#include <sstream>

AttendanceSession::AttendanceSession() {
    durationMinutes = 0;
}

AttendanceSession::AttendanceSession(string code, string dt, string time, int duration) {
    courseCode = code;
    date = dt;
    startTime = time;
    durationMinutes = duration;
}

string AttendanceSession::getCourseCode() const {
    return courseCode;
}

string AttendanceSession::getDate() const {
    return date;
}

void AttendanceSession::markAttendance(string indexNumber, string status) {
    for (auto& record : attendance) {
        if (record.first == indexNumber) {
            cout << "Attendance already marked.\n";
            return;
        }
    }
    attendance.push_back({indexNumber, status});
}

void AttendanceSession::updateAttendance(string indexNumber, string status) {
    for (auto& record : attendance) {
        if (record.first == indexNumber) {
            record.second = status;
            return;
        }
    }
    cout << "Student not found in session.\n";
}

void AttendanceSession::displaySessionInfo() const {
    cout << "Course: " << courseCode
         << " | Date: " << date
         << " | Time: " << startTime
         << " | Duration: " << durationMinutes << " mins\n";
}

void AttendanceSession::displayAttendanceList() const {
    for (const auto& record : attendance) {
        cout << "Index: " << record.first
             << " | Status: " << record.second << endl;
    }
}

void AttendanceSession::displaySummary() const {
    int present = 0, absent = 0, late = 0;

    for (const auto& record : attendance) {
        if (record.second == "Present") present++;
        else if (record.second == "Absent") absent++;
        else if (record.second == "Late") late++;
    }

    cout << "Summary:\n";
    cout << "Present: " << present << endl;
    cout << "Absent: " << absent << endl;
    cout << "Late: " << late << endl;
}

string AttendanceSession::toFileString() const {
    stringstream ss;
    ss << "SESSION\n";
    ss << courseCode << "|" << date << "|" << startTime << "|" << durationMinutes << "\n";

    for (const auto& record : attendance) {
        ss << record.first << "|" << record.second << "\n";
    }

    ss << "END\n";
    return ss.str();
}
