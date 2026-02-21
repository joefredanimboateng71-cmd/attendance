#ifndef ATTENDANCESESSION_H
#define ATTENDANCESESSION_H

#include <string>
#include <vector>
using namespace std;

class AttendanceSession {
private:
    string courseCode;
    string date;
    string startTime;
    int durationMinutes;

    vector<pair<string, string>> attendance; 
    // indexNumber , status

public:
    AttendanceSession();
    AttendanceSession(string code, string dt, string time, int duration);

    string getCourseCode() const;
    string getDate() const;

    void markAttendance(string indexNumber, string status);
    void updateAttendance(string indexNumber, string status);

    void displaySessionInfo() const;
    void displayAttendanceList() const;
    void displaySummary() const;

    string toFileString() const;
};

#endif
