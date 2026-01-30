#ifndef CMS_H
#define CMS_H

#include "Student.h"
#include "Instructor.h"
#include "Course.h"

class CMS {
private:
    Student students[20];
    Instructor instructors[10];
    Course courses[10];

    int studentCount;
    int instructorCount;
    int courseCount;

public:
    CMS();

    void addStudent();
    void addInstructor();
    void addCourse();
    void enrollStudentInCourse();
    void assignInstructorToCourse();
    void assignGrade();
    void assignNewInstructor();
    void showAllPersons();
    void showAllStudents();
    void showAllInstructors();
    void deleteStudent();
    void deleteInstructor();
    void viewCourse();
    void viewAllCourses();
    void deleteCourse();
    void searchStudent();
    void searchInstructor();
    void exportToFiles();
};

#endif
