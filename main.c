#include<stdio.h>
#include "student.h"

int main() {
  int choice;

  while (1) {
    printf("1. Add student\n");
    printf("2. View Students\n");
    printf("3.Search Student\n");
    printf("4. Delete Student\n");
    printf("5. Exit\n");
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
          printf("Student not found.\n");
        } else {
          printf("Roll: %d | Name: %s | Marks: %.2f\n", students[index].roll, students[index].name, students[index].marks);
        }
        break;
      }
      case 4: {
        int r;
        printf("Enter roll number to delete: ");
        scanf("%d", &r);

        deleteStudent(r);
        break;
      }
      case 5: return 0;
      default: printf("Invalid choice\n");
    }
  }
  return 0;
}