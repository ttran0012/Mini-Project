//
//  student.h
//  CGPA
//
//  Created by Tan Tran on 3/14/26.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string name;
    std::string id;
    int age;
    bool isGraduated;
    
public:
    Student(std::string n, std::string i, int a);
    std::string getName();
    std::string getId();
    
};


#endif
