# Digital Attendance System

## Overview

The Digital Attendance System is a console-based C++ application designed to replace traditional paper-based attendance in lecture halls.  

The system allows to:

- Register students
- Create lecture sessions
- Mark attendance (Present, Absent, Late)
- Generate attendance summaries
- Persist data using text files

The application runs offline on Windows and uses file handling (`fstream`) for data storage.

---

## Functional Reqiurements

### 1. Student Management
- Register students
- View all registered students
- Search students by index number
- Prevent duplicate student registrations

### 2. Attendance Session Management
- Create lecture sessions (course code, date, time, duration)
- Mark attendance status as (Present, Absent, Late)

### 3. Reports
- Display attendance list for a session
- Display summary counts of attendance status

### 4. File Storage
- Student data stored in `students.txt`
- Session data stored in `sessions.txt`
- Data remains available between program executions

---

## Technologies Used
- Programming Language: C++
- Compiler: g++
- Data Storage: Text files using `fstream`
- Platform: Windows (Console-based)

---
## How to Compile and Run (Windows)

### Step 1: Open terminal in project folder
### Step 2: Compile the program using this script: g++ -std=c++17 main.cpp Student.cpp AttendanceSession.cpp -o attendance.exe
- attendance.exe file will be created
### Step 3: Run the program:
- type in the terminal: attendancce.exe

---
## File Storage Format: All relevant data will be stored in the .txt files below
- students.txt
- sessions.txt

## Author
- Name: Anim Boateng Joefred
- Institution: Accra Technical University
- Year: 2026

## Academic Integrity
- This project was developed as part of an academic assignment.  
- All code is original and implemented using standard C++ libraries.