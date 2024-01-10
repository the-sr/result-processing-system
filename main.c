#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
    char name[30], address[50], reg[12], phone[13], clas[2];
    int acc1, cs1, eng1, math1, nep1, acc2, cs2, eng2, math2, nep2, acc3, cs3, eng3, math3, nep3, total1, total2, total3;
    float p1, p2, p3;
} st;
void detail_overwrite();
void marks_overwrite();
void detail_add();
void marks_add();
void search_regd();
void search_name();
// Main Function
int main()
{
    int a, b, c, d;
main_menu:
    printf("\tEnter:\n'1'.To Search Marksheet of a Student\n'2'.To Add or Edit Students Detail\n'3'.To Add or Edit Students Mark Detail \n'4'.To Exit\n\n");
    scanf("%d", &a);
    if (a == 1)
    {
        system("cls");
        printf("\n\tEnter:\n'1'.To Search using Registration No.\n'2'.To Search using Name\n'3'.To Return to Main Menu\n\n");
        fflush(stdin);
        scanf("%d", &b);
        if (b == 1)
        {
            system("cls");
            search_regd();
        }
        else if (b == 2)
        {
            system("cls");
            search_name();
        }
        else if (b == 3)
        {
            system("cls");
            goto main_menu;
        }
        else
        {
            printf("Invalid Choice");
        }
    }
    else if (a == 2)
    {
        system("cls");
        printf("\t\n'1'.To Add New Student Detail in the Existing Data\n'2'.To Overwrite the Existing Data with New Data\n'3'.To Return to Main Menu\n\n");
        fflush(stdin);
        scanf("%d", &c);
        if (c == 1)
        {
            system("cls");
            detail_add();
        }
        else if (c == 2)
        {
            system("cls");
            detail_overwrite();
        }
        else if (c == 3)
        {
            system("cls");
            goto main_menu;
        }
        else
        {
            printf("\n\t~~~~~Invalid Choice~~~~~");
        }
    }
    else if (a == 3)
    {
        system("cls");
        printf("\t\n'1'.To Add New Student Marks in the Existing Data\n'2'.To Overwrite the Existing Data with New Data\n'3'.To Return to Main Menu\n\n");
        fflush(stdin);
        scanf("%d", &d);
        if (d == 1)
        {
            system("cls");
            marks_add();
        }
        else if (d == 2)
        {
            system("cls");
            marks_overwrite();
        }
        else if (d == 3)
        {
            system("cls");
            goto main_menu;
        }
        else
        {
            printf("\n\t~~~~~Invalid Choice~~~~~");
        }
    }
    else if (a == 4)
    {
        printf("\n\t~~~~~ Thank You ~~~~~");
    }
    else
    {
        printf("\n\t~~~~~ Invalid Choice ~~~~~");
    }
    return 0;
}
// OverWriting Student Detail in File
void detail_overwrite()
{
    FILE *fptr;
    char next = 'Y';
    fptr = (fopen("detail.txt", "w"));
    if (fptr != NULL)
    {
        while (next == 'Y' || next == 'y')
        {
            printf("\n~~~~~Enter the information of the student~~~~~");
            printf("\nRegistration No. : ");
            fflush(stdin);
            scanf("%s", st.reg);
            printf("Name : ");
            fflush(stdin);
            // scanf("%s",st.name);
            gets(st.name);
            printf("Address : ");
            fflush(stdin);
            // scanf("%s",st.address);
            gets(st.address);
            printf("Phone No. : ");
            scanf("%s", st.phone);
            printf("Class : ");
            scanf("%s", st.clas);
            fwrite(&st, sizeof(st), 1, fptr);
            printf("\nDo you want to add more(Y/N):");
            fflush(stdin);
            next = getchar();
            printf("\n");
        }
    }
    fclose(fptr);
    system("cls");
    main();
}
// OverWriting Marks of Student in File
void marks_overwrite()
{
    FILE *fp;
    char next = 'Y';
    fp = (fopen("marks.txt", "w"));
    if (fp != NULL)
    {
        while (next == 'Y' || next == 'y')
        {
            printf("\n~~~~~Enter the marks of Student~~~~~");
            printf("\nEnter Registration Number: ");
            scanf("%s", st.reg);
            fflush(stdin);
            // Reading 1st terminal marks
            printf("\nEnter the marks of First Terminal Examination.");
            printf("\nEnter the mark of Account: ");
            scanf("%d", &st.acc1);
            fflush(stdin);
            printf("Enter the mark of Computer: ");
            scanf("%d", &st.cs1);
            fflush(stdin);
            printf("Enter the mark of English: ");
            scanf("%d", &st.eng1);
            fflush(stdin);
            printf("Enter the mark of Math: ");
            scanf("%d", &st.math1);
            fflush(stdin);
            printf("Enter the mark of Nepali: ");
            scanf("%d", &st.nep1);
            fflush(stdin);
            st.total1 = st.acc1 + st.cs1 + st.eng1 + st.math1 + st.nep1;
            st.p1 = st.total1 / 5.00;
            // Reading 2nd terminal marks
            printf("\nEnter the Marks of Second Terminal Examination.");
            printf("\nEnter the mark of Account: ");
            scanf("%d", &st.acc2);
            fflush(stdin);
            printf("Enter the mark of Computer: ");
            scanf("%d", &st.cs2);
            fflush(stdin);
            printf("Enter the mark of English: ");
            scanf("%d", &st.eng2);
            fflush(stdin);
            printf("Enter the mark of Math: ");
            scanf("%d", &st.math2);
            fflush(stdin);
            printf("Enter the mark of Nepali: ");
            scanf("%d", &st.nep2);
            fflush(stdin);
            st.total2 = st.acc2 + st.cs2 + st.eng2 + st.math2 + st.nep2;
            st.p2 = st.total2 / 5.00;
            // Reading third terminal marks
            printf("\nEnter the Marks of Final Terminal Examination.");
            printf("\nEnter the mark of Account: ");
            scanf("%d", &st.acc3);
            fflush(stdin);
            printf("Enter the mark of Computer: ");
            scanf("%d", &st.cs3);
            fflush(stdin);
            printf("Enter the mark of English: ");
            scanf("%d", &st.eng3);
            fflush(stdin);
            printf("Enter the mark of Math: ");
            scanf("%d", &st.math3);
            fflush(stdin);
            printf("Enter the mark of Nepali: ");
            scanf("%d", &st.nep3);
            fflush(stdin);
            st.total3 = st.acc3 + st.cs3 + st.eng3 + st.math3 + st.nep3;
            st.p3 = st.total3 / 5.00;
            fwrite(&st, sizeof(st), 1, fp);
            printf("\nDo you want to add more(Y/N):");
            fflush(stdin);
            next = getchar();
            printf("\n");
        }
    }
    fclose(fp);
    system("cls");
    main();
}
// Adding new student detail in file
void detail_add()
{
    FILE *fptr;
    char next = 'Y';
    fptr = (fopen("detail.txt", "a"));
    if (fptr != NULL)
    {
        while (next == 'Y' || next == 'y')
        {
            printf("\n~~~~~Enter the information of the student~~~~~");
            printf("\nRegistration No. : ");
            fflush(stdin);
            scanf("%s", st.reg);
            printf("Name : ");
            fflush(stdin);
            // scanf("%s",st.name);
            gets(st.name);
            printf("Address : ");
            fflush(stdin);
            // scanf("%s",st.address);
            gets(st.address);
            printf("Phone No. : ");
            scanf("%s", st.phone);
            printf("Class : ");
            scanf("%s", st.clas);
            fwrite(&st, sizeof(st), 1, fptr);
            printf("\nDo you want to add more(Y/N):");
            fflush(stdin);
            next = getchar();
            printf("\n");
        }
    }
    fclose(fptr);
    system("cls");
    main();
}
// Adding new student marks in file
void marks_add()
{
    FILE *fp;
    char next = 'Y';
    fp = (fopen("marks.txt", "a"));
    if (fp != NULL)
    {
        while (next == 'Y' || next == 'y')
        {
            printf("\n~~~~~Enter the marks of Student~~~~~");
            printf("\nEnter Registration Number: ");
            scanf("%s", st.reg);
            fflush(stdin);
            // Reading 1st terminal marks
            printf("\nEnter the marks of First Terminal Examination.");
            printf("\nEnter the mark of Account: ");
            scanf("%d", &st.acc1);
            fflush(stdin);
            printf("Enter the mark of Computer: ");
            scanf("%d", &st.cs1);
            fflush(stdin);
            printf("Enter the mark of English: ");
            scanf("%d", &st.eng1);
            fflush(stdin);
            printf("Enter the mark of Math: ");
            scanf("%d", &st.math1);
            fflush(stdin);
            printf("Enter the mark of Nepali: ");
            scanf("%d", &st.nep1);
            fflush(stdin);
            st.total1 = st.acc1 + st.cs1 + st.eng1 + st.math1 + st.nep1;
            st.p1 = st.total1 / 5.00;
            // Reading 2nd terminal marks
            printf("\nEnter the Marks of Second Terminal Examination.");
            printf("\nEnter the mark of Account: ");
            scanf("%d", &st.acc2);
            fflush(stdin);
            printf("Enter the mark of Computer: ");
            scanf("%d", &st.cs2);
            fflush(stdin);
            printf("Enter the mark of English: ");
            scanf("%d", &st.eng2);
            fflush(stdin);
            printf("Enter the mark of Math: ");
            scanf("%d", &st.math2);
            fflush(stdin);
            printf("Enter the mark of Nepali: ");
            scanf("%d", &st.nep2);
            fflush(stdin);
            st.total2 = st.acc2 + st.cs2 + st.eng2 + st.math2 + st.nep2;
            st.p2 = st.total2 / 5.00;
            // Reading third terminal marks
            printf("\nEnter the Marks of Final Terminal Examination.");
            printf("\nEnter the mark of Account: ");
            scanf("%d", &st.acc3);
            fflush(stdin);
            printf("Enter the mark of Computer: ");
            scanf("%d", &st.cs3);
            fflush(stdin);
            printf("Enter the mark of English: ");
            scanf("%d", &st.eng3);
            fflush(stdin);
            printf("Enter the mark of Math: ");
            scanf("%d", &st.math3);
            fflush(stdin);
            printf("Enter the mark of Nepali: ");
            scanf("%d", &st.nep3);
            fflush(stdin);
            st.total3 = st.acc3 + st.cs3 + st.eng3 + st.math3 + st.nep3;
            st.p3 = st.total3 / 5.00;
            fwrite(&st, sizeof(st), 1, fp);
            printf("\nDo you want to add more(Y/N):");
            fflush(stdin);
            next = getchar();
            printf("\n");
        }
    }
    fclose(fp);
    system("cls");
    main();
}
// search function using registratsion number
void search_regd()
{
    FILE *fptr, *fp;
    char key[20];
    printf("\nEnter the Registration No to search: ");
    scanf("%s", key);
    printf("\n~~~~~~~~~~MARKSHEET~~~~~~~~~~\n");
    printf("\n-----Student Detail-----\n");
    fptr = fopen("detail.txt", "r");
    if (fptr != NULL)
    {
        while (!feof(fptr))
        {
            fread(&st, sizeof(st), 1, fptr);
            if (strcmp(st.reg, key) == 0)
            {
                printf("\nRegistration No.: %s\nName: %s\nAddress: %s\nPhone: %s\nClass:%s\n", st.reg, st.name, st.address, st.phone, st.clas);
                break;
            }
        }
    }
    fclose(fptr);
    printf("\n-----Marks Detail-----\n");
    fp = fopen("marks.txt", "r");
    printf("\nSubjects  1st Terminal \t2nd Terminal \tFinal Terminal");
    if (fp != NULL)
    {
        while (!feof(fp))
        {
            fread(&st, sizeof(st), 1, fp);
            if (strcmp(st.reg, key) == 0)
            {
                printf("\nAccount   \t%d\t \t%d\t \t%d\nComputer  \t%d\t \t%d\t \t%d\nEnglish   \t%d\t \t%d\t \t%d\nMath      \t%d\t \t%d\t \t%d\nNepali    \t%d\t \t%d\t \t%d\n\nTotal     \t%d\t \t%d\t \t%d\nPercentage\t%.2f\t \t%.2f\t \t%.2f\n", st.acc1, st.acc2, st.acc3, st.cs1, st.cs2, st.cs3, st.eng1, st.eng2, st.eng3, st.math1, st.math2, st.math3, st.nep1, st.nep2, st.nep3, st.total1, st.total2, st.total3, st.p1, st.p2, st.p3);
                break;
            }
        }
    }
    fclose(fp);
}
// search function using name
void search_name()
{
    FILE *fptr, *fp;
    char find[30], temp[12];
    printf("\nEnter the Name to search: ");
    fflush(stdin);
    gets(find);
    // scanf("%s",find);
    printf("\n~~~~~~~~~~MARKSHEET~~~~~~~~~~\n");
    printf("\n-----Student Detail-----\n");
    fptr = fopen("detail.txt", "r");
    if (fptr != NULL)
    {
        while (!feof(fptr))
        {
            fread(&st, sizeof(st), 1, fptr);
            if (strcmp(st.name, find) == 0)
            {
                printf("\nRegistration No.: %s\nName: %s\nAddress: %s\nPhone: %s\nClass:%s\n", st.reg, st.name, st.address, st.phone, st.clas);
                strcpy(temp, st.reg);
                break;
            }
        }
    }
    fclose(fptr);
    printf("\n-----Marks Detail-----\n");
    fp = fopen("marks.txt", "r");
    printf("\nSubjects  1st Terminal \t2nd Terminal \tFinal Terminal");
    if (fp != NULL)
    {
        while (!feof(fp))
        {
            fread(&st, sizeof(st), 1, fp);
            if (strcmp(st.reg, temp) == 0)
            {
                printf("\nAccount   \t%d\t \t%d\t \t%d\nComputer  \t%d\t \t%d\t \t%d\nEnglish   \t%d\t \t%d\t \t%d\nMath      \t%d\t \t%d\t \t%d\nNepali    \t%d\t \t%d\t \t%d\n\nTotal     \t%d\t \t%d\t \t%d\nPercentage\t%.2f\t \t%.2f\t \t%.2f\n", st.acc1, st.acc2, st.acc3, st.cs1, st.cs2, st.cs3, st.eng1, st.eng2, st.eng3, st.math1, st.math2, st.math3, st.nep1, st.nep2, st.nep3, st.total1, st.total2, st.total3, st.p1, st.p2, st.p3);
                break;
            }
        }
    }
    fclose(fp);
}
