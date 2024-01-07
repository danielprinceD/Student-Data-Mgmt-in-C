#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0;
struct Student
{
    char name[30];
    int rollno;
    int age;
    int phoneno;
};

void add_stud(struct Student *ptr, int num)
{
    printf("\nEnter Student Name : ");
    scanf("%s", (ptr + num)->name);
    printf("\nEnter Student Rollnum : ");
    scanf("%d", &(ptr + num)->rollno);
    printf("\nEnter Student Age : ");
    scanf("%d", &(ptr + num)->age);
    printf("\nEnter Student Phone number  : ");
    scanf("%d", &(ptr + num)->phoneno);
}

void display(struct Student *ptr, int num)
{
    printf("\n%s\t\t", (ptr + num)->name);
    printf("%d\t\t", (ptr + num)->rollno);
    printf("%d\t\t", (ptr + num)->age);
    printf("%d\t\t", (ptr + num)->phoneno);
}

void delete(struct Student *ptr, int num)
{
    if (ptr->rollno == num)
    {
        ptr->rollno = 0;
        strcpy(ptr->name, "Deleted");
        ptr->phoneno = 0;
        ptr->age = 0;
        return;
    }
}

int main()
{
    int choice, no_stud, i = 0, d_stud, del;
    struct Student new;
    struct Student *ptr = (struct Student *)malloc(100 * sizeof(struct Student));

    do
    {
        printf("1.Add Student Details\n");
        printf("2.Display all student Details\n");
        printf("3.Delete Student Detail\n");
        printf("4.Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("Enter Student Details : \n");
            add_stud(ptr, count);
            count++;

            break;
        case 2:
            printf("\nName\t\tRollno\t\tAge\t\tPhone number");
            for (i = 0; i < count; i++)
            {
                display(ptr, i);
                printf("\n\n");
            }
            break;
        case 3:
            printf("Enter the rollnumber of a student to delete the details  : ");
            int get_roll;
            scanf("%d", &get_roll);

            for (i = 0; i < count; i++)
            {
                delete (ptr + i, get_roll);
            }

            break;
        }
    } while (!(choice == 0 || choice == 4));
}