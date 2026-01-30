#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "Person.h"
class Course;

class Instructor : public Person {
public:
    int id;
    Course* courses[5];
    int courseCount;

    static int totalInstructors;

    Instructor();
    Instructor(string n, int a);

    int getId();
    string getName();
    int getAge();
    int getCourseCount();
    void addCourse(Course* c);
    void displayDetails();
};

#endif
