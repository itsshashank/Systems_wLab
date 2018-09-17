#include <stdio.h>
#define limit 50
int available[limit], max[limit][limit], allocation[limit][limit], need[limit][limit], work[limit];
void calneedmatrix(int n, int m)
{ //need = max - allocation
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    printf("\nthe need metrix\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }
}
void printwork(int r)
{
    for (int j = 0; j < r; j++)
    {
        work[j] = available[j] - work[j];
    }
}
int main()
{
    int p, r, i, j, safe_seq[limit], process[limit], finish[limit];
    char ch = 'A';
    printf("Enter the no of process and no of resources:");
    scanf("%d%d", &p, &r);
    printf("Enter the instances of resources:\n");
    for (i = 0; i < r; i++, ch++)
    {
        printf("%c:", ch);
        scanf("%d", &available[i]);
    }
    //printwork(r);
    printf("Enter the Allocation and max for a process:\n");
    printf("process\tAllolcation\n\t");
    ch = 'A';
    for (i = 0; i < r; i++, ch++)
    {
        work[i] = 0;
        printf("%c ", ch);
    }
    printf("\n");
    for (i = 0; i < p; i++)
    {
        printf("p%d\t", i);
        process[i] = i;
        for (j = 0; j < r; j++)
        {
            scanf("%d", &allocation[i][j]);
            if (available[j] > 0)
                work[j] += allocation[i][j];
            else
            {
                printf("cant allocate ");
                return 1;
            }
        }
    }
    printwork(r);
    printf("process\tmax\n\t");
    ch = 'A';
    for (i = 0; i < r; i++, ch++)
        printf("%c ", ch);
    printf("\n");
    for (i = 0; i < p; i++)
    {
        finish[i] = 0;
        safe_seq[i] = -1;
        printf("p%d\t", i);
        for (j = 0; j < r; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    calneedmatrix(p, r); // to calculate need matrix
    int nextp;
    i = 0;
    while (i < p)
    {
        for (j = 0; j < p; j++)
        {
            //printf("the process %d\n", j);
            if (finish[j] == 0)
            {
                int k;
                for (k = 0; k < r; k++)
                    if (need[j][k] > work[k])
                    {
                        nextp = -1;
                        //printf("the process not alloacted%d\n", j);
                        break;
                    }
                    else
                        nextp = 1;
                if (nextp != -1)
                {
                    int l;
                    for (l = 0; l < r; l++)
                        work[l] += allocation[j][l];
                    //printf("aloocated %d", j);
                    safe_seq[i++] = j;
                    finish[j] = 1;
                }
            }
        }
        //i++;
    }
    printf("\nSystem is in safe state\n the sequnece is :");
    for (i = 0; i < p; i++)
        printf("%d\t", safe_seq[i]);
    printf("\n");
    return 0;
}
