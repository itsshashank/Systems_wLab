#include <stdio.h>
#include <string.h>
#define max 20
struct directory
{
    char dirname[max];
    int no_of_files;
    int no_of_dir;
    char fname[max][max];
} root, d[max],*temp;
void displaysub(int n)
{
    struct directory temp = d[n];
    printf("\n  |\t %s\n \t ", temp.dirname);
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
        printf("\n  |\n  | -->\t");
        displaysub(i);
    }
    for (int i = 0; i < root.no_of_files; i++)
    {
        printf("\n  |\n  | ->\t%s", root.fname[i]);
    }
    printf("\n  |\n  =\n");
}
int exist(char fn[], struct directory temp)
{
    for (int i = 0; i < temp.no_of_files; i++)
    {
        if (strcmp(fn, temp.fname[i]) == 0)
            return i;
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
    //struct directory *temp;
    int loc, fd;
    char name[max];
    printf("\n to which dir do you wanna add file root or subdir ( 0/1 ):");
    scanf("%d", &fd);
    if (fd == 0)
        temp = &root;
    else
    {
        printf("\nenter the dir name:");
        scanf("%s", name);
        loc = existDir(name);
        if (loc >= 0)
        {
            temp = &d[loc];
        }
        else
        {
            printf("\n soory bubby no dir :(\n");
            return;
        }
    }
    printf("\nEnter the file name : ");
    scanf("%s", name);
    if (exist(name, *temp) >= 0)
        printf("\nfile already in the directory\n");
    else
    {
        strcpy(temp->fname[temp->no_of_files], name);
        temp->no_of_files++;
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
void delete()
{
    //struct directory *temp;
    int loc, fd;
    char name[max];
    printf("\n to which dir do you wanna delete file from root or subdir ( 0/1 ):");
    scanf("%d", &fd);
    if (fd == 0)
        temp = &root;
    else
    {
        printf("\nenter the dir name:");
        scanf("%s", name);
        loc = existDir(name);
        if (loc >= 0)
        {
            temp = &d[loc];
        }
        else
        {
            printf("\n soory bubby no dir :(\n");
            return;
        }
    }
    printf("\nEnter the file name : ");
    scanf("%s", name);
    loc = exist(name, *temp); 
    if (loc >= 0)
    {
        for (int i = loc; i < temp->no_of_files; i++)
            strcpy(temp->fname[i], temp->fname[i + 1]);
        temp->no_of_files -- ;
    }
    else
    {
        printf("\nfile not in the directory\n");
    }
}
void delDir()
{
    char name[max];
    printf("\nEnter the directory name : ");
    scanf("%s", name);
    int loc = existDir(name);
    if (loc >= 0){
        for (int i = loc; i < root.no_of_dir; i++)
            d[i] = d[i+1];//strcpy(d[i].dirname, d[i+1].dirname);
        root.no_of_dir-- ;
        }
    else
    {
        printf("no such dir\n");
    }
}
int main(int argc, char const *argv[])
{
    printf("Enter the name of root directory: ");
    scanf("%s", root.dirname);
    root.no_of_files = root.no_of_dir = 0;
    int ch = 1;
    do
    {
        printf("\nDirectory Menu\n\t1.Add file\n\t2.Delete file\n\t3.Display\n\t4.Create Directory\n\t5.Delete directory\n\t6.Exit\nEnter your option:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            add();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            addDir();
            break;
        case 5:
            delDir();
            break;
        case 6:
            return 1;
        default:
            printf("not a choise try again\n");
        }
        printf("Do you  wanna continue(1/0):");
        scanf("%d", &ch);
    } while (ch == 1);
    return 0;
}