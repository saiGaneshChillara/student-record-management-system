#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100

struct  Student {
  int roll;
  char name[50];
  float marks;
};

extern struct Student students[MAX_STUDENTS];

extern int count;

void addStudent();
void viewStudents();
int searchStudent(int roll);

void deleteStudent(int roll);

#endif
