#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Course;   
class Student : public Person {
public:
    int rollNo;
    Course* courses[5];
    int courseCount;

    static int totalStudents;

    Student();
    Student(string n, int a);

    int getRollNo();
    int getCourseCount();
    string getName();
    int getAge();
    void enroll(Course* c);
    void displayDetails();
};

#endif
