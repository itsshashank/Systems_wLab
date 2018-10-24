#include <stdio.h>
#include <string.h>
#define max 20
struct directory
{
    char dirname[max];
    int no_of_files;
    char fname[max][max];
} d;
void display()
{
    printf("\n %s\n", d.dirname);
    int c = 0;
    while (d.dirname[c++] != '\0')
        printf("--");
    for (int i = 0; i < d.no_of_files; i++)
    {
        printf("\n  |\n  | ->\t%s", d.fname[i]);
    }
    printf("\n  |\n  =\n");
}
int exist(char fn[])
{
    for (int i = 0; i < d.no_of_files; i++)
    {
        if (strcmp(fn, d.fname[i]) == 0)
            return i;
    }
    return -1;
}
void add()
{
    char name[max];
    printf("\nEnter the file name : ");
    scanf("%s", name);
    if (exist(name) >= 0)
        printf("\nfile already in the directory\n");
    else
    {
        strcpy(d.fname[d.no_of_files], name);
        d.no_of_files++;
    }
}

void delete ()
{
    char name[max];
    printf("\nEnter the file name : ");
    scanf("%s", name);
    int loc = exist(name);
    if (loc >= 0)
    {
        for (int i = loc; i < d.no_of_files; i++)
            strcpy(d.fname[i], d.fname[i + 1]);
        d.no_of_files--;
    }
    else
        printf("\nNo file by that name\n");
}
int main(int argc, char const *argv[])
{
    printf("Enter the name of root directory: ");
    scanf("%s", d.dirname);
    d.no_of_files = 0;
    int ch = 1;
    do
    {
        printf("\nDirectory Menu\n\t1.Add file\n\t2.Delete file\n\t3.Display\nEnter your option:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            add();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("not a choice try again\n");
        }
        printf("Do you  wanna continue(0/1):");
        scanf("%d", &ch);
    } while (ch == 1);
    return 0;
}