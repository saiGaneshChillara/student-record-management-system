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
    printf("Error: Roll number already exists\n\n");
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