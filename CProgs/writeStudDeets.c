#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int marks;
    char name[25];
};

void main()
{
    struct Student *S = (struct Student *)malloc(sizeof(struct Student));
    FILE *ptr = fopen("studs.txt", "a");
    char ch = 'y';

    while (ch == 'Y' || ch == 'y')
    {
        printf("Enter name: ");
        scanf("%s", S->name);
        printf("Enter Marks: ");
        scanf("%d", &S->marks);
        fwrite(S, sizeof(struct Student), 1, ptr);
        
        printf("More Entries? (Y/N): ");
        scanf("%s", &ch);
    }

    fclose(ptr);

    ptr = fopen("studs.txt", "r");

    while (!feof(ptr))
    {
        fread(S, sizeof(struct Student), 1, ptr);
        printf("Name: %s\n", S->name);
        printf("Marks: %d\n", S->marks);
    }

    fclose(ptr);
}