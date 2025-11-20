#include<stdio.h>
#include "student.h"

struct Student students[MAX_STUDENTS];

int count = 0;

void addStudent() {
  if (count >= MAX_STUDENTS) {
    printf("Storage full\n");
    return;
  }

  struct Student s;

  printf("Enter roll number: ");
  scanf("%d", &s.roll);

  if (searchStudent(s.roll) != -1) {
    printf("Error: Roll number %d already exists\n\n", s.roll);
    return;
  }

  printf("Enter name: ");
  scanf("%s", s.name);

  printf("Enter marks: ");
  scanf("%f", &s.marks);

  students[count++] = s;

  printf("Student added succesfully\n\n");
}

void viewStudents() {
  if (count == 0) {
    printf("No students available\n");
    return;
  }

  // students[0] = { 35, "Ganesh", 100 };

  printf("\n ---Student List---\n");
  for (int i = 0; i < count; i++) {
    printf("Roll : %d | Name: %s | Marks: %.2f\n", students[i].roll, students[i].name, students[i].marks);
  }
  printf("\n");
}

int searchStudent(int roll) {
  for (int i = 0; i < count; i++) {
    if (students[i].roll == roll) {
      return i;
    }
  }

  return -1;
}

void deleteStudent(int roll) {
  int index = searchStudent(roll);

  if (index == -1) {
    printf("Student with roll %d not found\n", roll);
    return;
  }

  for (int i = index; i < count - 1; i++) {
    students[i] =  students[i + 1];
  }

  count--;

  printf("Student with roll %d deleted succesfully.\n", roll);
}