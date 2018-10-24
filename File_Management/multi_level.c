#include <stdio.h>
#include <string.h>
#define max 20
struct directory
{
    char dirname[max];
    int no_of_files;
    int no_of_dir;
    char fname[max][max];
} root, d[max];
void displaysub(int n)
{
    struct directory temp = d[n];
    printf("\t\n %s\n", temp.dirname);
    int c = 0;
    while (temp.dirname[c++] != '\0')
        printf("--");
    for (int i = 0; i < temp.no_of_files; i++)
    {
        printf("\n\t|\n\t| ->\t%s", temp.fname[i]);
    }
    printf("\n\t|\n\t=\n");
}
void display()
{
    printf("\n %s\n", root.dirname);
    int c = 0;
    while (root.dirname[c++] != '\0')
        printf("--");
    for (int i = 0; i < root.no_of_dir; i++)
    {
        displaysub(i);
    }
    for (int i = 0; i < root.no_of_files; i++)
    {
        printf("\n  |\n  | ->\t%s", root.fname[i]);
    }
    printf("\n  |\n  =\n");
}
int exist(char fn[], int fd)
{
    struct directory temp;
    if (fd == 0)
        temp = root;
    else
        for (int j = 0; j < root.no_of_dir; j++)
        {
            temp = d[j];
            for (int i = 0; i < temp.no_of_files; i++)
            {
                if (strcmp(fn, temp.fname[i]) == 0)
                    return i;
            }
        }
    return -1;
}
int existDir(char fn[])
{
    for (int i = 0; i < root.no_of_dir; i++)
    {
        if (strcmp(fn, d[i].dirname) == 0)
            return i;
    }
    return -1;
}
void add()
{
    struct directory temp;
    int loc, fd;
    char name[max];
    printf("\n to which dir do you wanna add file root or subdir ( 0/1 ):");
    scanf("%d", &fd);
    if (fd == 0)
        temp = root;
    else
    {
        printf("\nenter the dir name:");

        scanf("%s", name);
        loc = existDir(name);
        if (loc >= 0)
        {
            temp = d[loc];
        }
        else
        {
            printf("\n soory bubby no dir :(\n");
            return;
        }
    }

    printf("\nEnter the file name : ");
    scanf("%s", name);
    if (exist(name, fd) >= 0)
        printf("\nfile already in the directory\n");
    else
    {
        strcpy(temp.fname[temp.no_of_files], name);
        temp.no_of_files++;
    }
}
void addDir()
{
    char name[max];
    printf("\nEnter the directory name : ");
    scanf("%s", name);
    if (existDir(name) >= 0)
        printf("\ndirectory existes\n");
    else
    {
        strcpy(d[root.no_of_dir].dirname, name);
        root.no_of_dir++;
    }
}

/*void delete (int fd)
    {
        char name[max];
        if (fd == 0)
            strcpy(d.fname[d.no_of_files], name);
        d.no_of_files++;
        printf("\nEnter the file name : ");
        else printf("\nEnter the directory name : ");
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
    }*/
int main(int argc, char const *argv[])
{
    printf("Enter the name of root directory: ");
    scanf("%s", root.dirname);
    root.no_of_files = root.no_of_dir = 0;
    int ch = 1;
    do
    {
        printf("\nDirectory Menu\n\t1.Add file\n\t2.Delete file\n\t3.Display\n\t4.Create Directory\n\t5.Delete directory\nEnter your option:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            add();
            break;
        case 2:
            //delete (0);
            break;
        case 3:
            display();
            break;
        case 4:
            add(1);
            break;
        case 5:
            //delete (1);
            break;
        default:
            printf("not a choice try again\n");
        }
        printf("Do you  wanna continue(0/1):");
        scanf("%d", &ch);
    } while (ch == 1);
    return 0;
}