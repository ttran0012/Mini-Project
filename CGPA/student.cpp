//
//  student.cpp
//  CGPA
//
//  Created by Tan Tran on 3/14/26.
//

#include "student.h"


// Constructor
Student::Student(std::string n, std::string i, int a){
    name        = n;
    id          = i;
    age         = a;
    isGraduated = false;
}

// Getters
std::string Student::getName() {
    return name;
}

//
std::string Student::getId() {
    return id;
}
