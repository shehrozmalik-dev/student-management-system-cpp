#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
using namespace std;

class Student;
class Instructor;

class Course {
public:
    string code;
    string name;
    Instructor* instructor;
    Student* students[5];
    int studentCount;
    int grades[5];

    Course();
    Course(string c, string n);

    string getCode();
    string getName();
    int getStudentCount();
    void assignInstructor(Instructor* i);
    void enrollStudent(Student* s);
    void updateGrade(int studentId, int grade);
    int getGrade(Student* s);
    void displayCourse();
};

#endif
