#include <stdio.h>
#include <string.h>
struct ste
{
    char a[100];
} s;
void main()
{
    char d[30];
    FILE *fp1, *fp2, *fp3;
    int n = 5, g = 5, h = 5, lc = 1, s1, flag;
    gotoxy(19, 3);
    printf(“\nASSEMBLERCODE\n”);
    printf(“\nMACHINECODE\n”);
    printf(“\nMNEUMONIC OPCODE\n”);
    gotoxy(7, 6);
    fp1 = fopen(“SOURCE1.TXT”,”r”);
    do
    {
        s1 = 0;
        fscanf(fp1,”% s”, s.a);
        gotoxy(15, 10);
        if ((lc % 3 == 2) && (strcmp(s.a,”END”) != 0))
        {
            fp3 = fopen(“OPCODE1.TXT”,”r”);
            printf(“% s”, s.a);
            do
            {
                fscanf(fp3,”% s”, d);
                if (strcmp(d, s.a) == 0)
                {
                    fscanf(fp3,”% s”, d);
                    gotoxy(10, h++);
                    printf(“% s”, d);
                }
            }
            while (!feof(fp3));
        }
        else
        {
            if ((lc % 3 == 0) && (strcmp(s.a,”END”) != 0))
            {
                gotoxy(30, g++);
                fp2 = fopen(“PASSONE1.TXT”,”r”);
                printf(“% s”, s.a);
                do
                {
                    fscanf(fp2,”% s”, d);
                    if (strcmp(d, s.a) == 0)
                    {
                        fscanf(fp2,”% s”, d);
                        gotoxy(12, n);
                        printf(“% s”, d);
                        s1 = 1;
                    }
                } while (!feof(fp2));
                gotoxy(12, n);
                if (s1 == 0)
                    printf(“% s”, s.a);
                n++;
            }
        }
        lc++;
    }
    while (!feof(fp1));
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    printf(“\n\t\t PASS - 2 COMPLETED”);
}