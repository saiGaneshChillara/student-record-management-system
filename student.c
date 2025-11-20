#include<stdio.h>
#include <string.h>
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

  int choice;
  printf("\n--- Sort Options ---\n");
  printf("1. By Roll Number\n");
  printf("2. By Name\n");
  printf("3. By Marks\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  if (choice >= 1 && choice <= 3) {
    sortStudents(choice);
  }

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

void sortStudents(int mode) {
  if (count <= 1) {
    printf("Not enough students to sort.\n");
    return;
  }

  for (int i = 0; i < count - 1; i++) {
    for (int j = 0; j < count - i - 1; j++) {
      int swap = 0;

      if (mode == 1) {
        if (students[j].roll > students[j + 1].roll) 
          swap = 1;
      } else if (mode == 2) {
        if (strcmp(students[j].name, students[j + 1].name) > 0) 
          swap = 1;
      } else if (mode == 3) {
        if (students[j].marks > students[j + 1].marks) 
          swap = 1;
      }

      if (swap) {
        struct Student temp = students[j];

        students[j] = students[j + 1];
        students[j + 1] = temp;
      }
    }
  }

  printf("Sorted successfully!\n");
}