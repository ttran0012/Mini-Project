//
//  course.h
//  CGPA
//
//  Created by Tan Tran on 3/14/26.
//

#ifndef COURSE_H
#define COURSE_H

#include <string>


struct Course {
    std::string name;
    float credits;
    std::string letterGrade;
    float gradePoints;
};

#endif
