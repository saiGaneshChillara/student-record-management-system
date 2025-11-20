#include<stdio.h>
#include "student.h"

int main() {
  int choice;

  while (1) {
    printf("1. Add student\n");
    printf("2. View Students\n");
    printf("3.Exit\n");
    printf("Choose an option: ");

    if (scanf("%d", &choice) != 1) {
      printf("Invalid input. Enter numbers only\n");
      
      while(getchar() != '\n');
      continue;
    }

    switch (choice) {
      case 1: addStudent();
              break;
      case 2: viewStudents();
              break;
      case 3: {
        int r;
        printf("Enter roll number to search: ");
        scanf("%d", &r);

        int index = searchStudent(r);
        if (index == -1) {
          printf("Student nout found.\n");
        } else {
          printf("Roll: %d | Name: %s | Marks: %.2f\n", students[index].roll, students[index].name, students[index].marks);
        }
        break;
      }
      default: printf("Invalid choice\n");
    }
  }
  return 0;
}