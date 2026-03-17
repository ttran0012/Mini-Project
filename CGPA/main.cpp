//
//  main.cpp
//  CGPA
//
//  Created by Tan Tran on 3/12/26.
//

#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <limits>
#include "student.h"
#include "course.h"
#include "semester.h"
using namespace std;


// Map to store Grades
map<string, float> buildGradeMap(){
    map<string, float> grades;
    grades["A"]     = 4.0;
    grades["A-"]    = 3.7;
    grades["B+"]    = 3.3;
    grades["B"]     = 3.0;
    grades["B-"]    = 2.7;
    grades["C+"]    = 2.3;
    grades["C"]     = 2.0;
    grades["F"]     = 0;
    
    return grades;
}


void showMenu() {
    std::cout << "\n  [1] Add semester\n"
                     "  [2] View transcript & CGPA\n"
                     "  [3] View CGPA only\n"
                     "  [4] Exit\n"
                     "  Choice: ";
    
}

int readPositiveInput(string prompt){
    int value;
    while(true){
        cout << prompt;
        if(!(cin >> value)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid! Please enter a number.\n";
        } else if (value <= 0) {
            cout << "Invalid! Must be greater than zero.\n";
        } else { return value; }
    }
}


int main() {
    map<string, float> gradeMap = buildGradeMap();
    
    float cgpaCredits =0;
    float cgpaQualityPoints = 0;
    vector<Semester>semesters;
    
    Course c;
    // Ask for Student info
    string name, id;
    
    cout << "Student Name: ";
    getline(cin, name);
    cout << "Student ID: ";
    while(true){
        if(!(cin >> id)){
            cin.clear();
            cout << "Invalid! Please enter a number.\n";
        } else if(id.length() < 6) {
            cout << "Invalid! ID Must be greater than 6.\n";
        }
        else {
            break;
        }
    }
    
    int age = readPositiveInput("Student age: ");
    cin.ignore();
    // Constructor
    Student s(name, id, age);
    
    int choice = 0;
    while(true){
        showMenu();
        if(!(cin >> choice)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << " Please enter 1-4.\n";
            continue;
        }
        
        switch (choice) {
            case 1: {
                cout << "\nADD SEMESTER\n";
                float totalCredits = 0;
                float totalQualityPoints = 0;
                
                int numCourses = readPositiveInput("How many courses? ");
                cin.ignore();
                
                vector<Course> courses;
                for(int i = 0; i < numCourses; i++){
                    string grade;
                    float credits;
                    string courseName;
                    
                    cout << "\nCourse " << (i+1) << ":\n";
                    cout << " Name: ";
                    getline(cin, courseName);
    
                    while(true){
                        cout << " Credits: ";
                        if(!(cin >> credits)){
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << " Invalid! Please enter a number.\n";
                        } else if (credits <= 0) {
                            cout << " Invalid! Credits must be greater than zero.\n";
                        }
                        else {
                            break;
                        }
                    }
                    cin.ignore();
                    
                    while(true){
                        cout << "Grade (e.g. A, A-, B+, B, C-):   ";
                        cin  >> grade;
                        // Handles Invalid Grade Character
                        if(gradeMap.count(grade) == 0){
                            cout << "Invalid grade! Try again.\n";
                        } else {
                            // Grade is Valid. Break out of loop
                            break;
                        }
                    }
                    cin.ignore(); // Fix: BUG Add this line to prevent Name: Credits:
                    
                    float gradePoints = gradeMap[grade];
                    
                    totalCredits += credits;
                    totalQualityPoints += credits * gradePoints;
                    
                    Course c;
                    c.name          = courseName;
                    c.credits       = credits;
                    c.letterGrade   = grade;
                    c.gradePoints   = gradePoints;
                    courses.push_back(c);
                    
                }
                float gpa = totalQualityPoints / totalCredits;
                cout << "\nSemester GPA\n: " << fixed << setprecision(2) << gpa << endl;
                cgpaCredits += totalCredits;
                cgpaQualityPoints += totalQualityPoints;
                
                Semester sem;
                sem.number  = semesters.size() + static_cast<size_t>(1);
                // sem.number  = semesters.size() + 1; this cause issues (unsigned)
                sem.courses = courses;
                sem.gpa     = gpa;
                semesters.push_back(sem);
                
                break;
            }
                
            case 2: {
                cout << "\nTranscript & CGPA\n";
                // s.getName() Getters to read the Class
                cout << "Transcript for: " << s.getName() << "\n";
                cout << "Student ID: " << s.getId() << "\n";
                if(semesters.empty()){
                    cout << "\nNo Semesters recorded yet.\n";
                }
                
                for(int s = 0; s < semesters.size(); s++){
                    cout << "\n=== Semester " << semesters[s].number << " ===\n";
                    cout << left << setw(20) << "Course"
                    << setw(10) << "Credits"
                    << setw(8) << "Grade"
                    << "Points\n";
                    
                    cout << string(45, '-') << "\n";
                    
                    for(int i = 0; i < semesters[s].courses.size(); i++){
                        Course c = semesters[s].courses[i];
                        cout << left << fixed << setprecision(2) << setw(20) << c.name
                        << setw(10) << c.credits
                        << setw(8) << c.letterGrade
                        << c.gradePoints << "\n";
                    }
                    
                    // Fix this ugliness
                    // Show 4.00 instead of 4
                    cout << "Semester GPA: " <<semesters[s].gpa << "\n";
                }
                
                float cgpa = cgpaQualityPoints / cgpaCredits;
                cout << "\nCGPA: " << cgpa << "\n";
                
                // Class Standing
                if(cgpa >= 3.7) {
                    cout << "Standing: Summa Cum Laude\n";
                }
                else if(cgpa >= 3.3) {
                    cout << "Standing: Magna Cum Laude\n";
                }
                else if(cgpa >= 3.0) {
                    cout << "Standing: Cum Laude\n";
                }
                else if(cgpa >= 2.0) {
                    cout << "Standing: Good Standing\n";
                }
                else {
                    cout << "Standing: Academic Probation\n";
                }
            }
                break;
            case 3:
                if (cgpaCredits > 0) {
                    cout << "\nCGPA: " << cgpaQualityPoints / cgpaCredits << endl;
                } else {
                    cout << "\nCGPA: N/A (no credits yet)" << endl;
                }
                break;
            case 4:
                cout << "\nGoodbye!\n";
                return 0;
                
            default:
                cout << "\nInvalid Choice\n";
        }
    }
    
    
    return 0;
    
    
}

