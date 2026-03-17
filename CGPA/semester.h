//
//  semester.h
//  CGPA
//
//  Created by Tan Tran on 3/14/26.
//


#ifndef SEMESTER_H
#define SEMESTER_H

#include <cstddef>
#include <vector>

#include "course.h" // gives full access to course

struct Semester {
    int number;
    std::vector<Course>courses;
    float gpa;
};

#endif 
