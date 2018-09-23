#include <stdio.h>
#define limit 50
int available[limit], max[limit][limit], allocation[limit][limit], safe_seq[limit], process[limit], finish[limit],need[limit][limit], work[limit];
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
    //optional
    /*printf("\nthe need metrix\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }*/
}
void printwork(int r)
{
    for (int j = 0; j < r; j++)
    {
        work[j] = available[j] - work[j];
    }
}
int resourceAllocation(int p,int r)
{
    int nextp;
    int i = 0,j,k,l;
    while (i < p)
    {
        for (j = 0; j < p; j++)
        {
            if (finish[j] == 0)
            {
                int k;
                for (k = 0; k < r; k++)
                    if (need[j][k] > work[k])
                    {
                        nextp = -1;
                        //the process not alloacted
                        break;
                    }
                    else
                        nextp = 1;
                if (nextp != -1)
                {
                    int l;
                    for (l = 0; l < r; l++)
                        work[l] += allocation[j][l];
                    //processes allocated
                    safe_seq[i++] = j;
                    finish[j] = 1;
                }
            }
        }
        if(nextp == -1)
            return 1;
    }
    return 0;
}
void display(int res,int p){
    if(res == 0){
        printf("\nSystem is in safe state\nthe sequnece is :");
        for (int i = 0; i < p; i++)
            printf("%d\t", safe_seq[i]);
        printf("\n");
    }
    else{
        printf("System not in safe state\n");
    }
}
int main()
{
    int p, r, i, j;
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
    display(resourceAllocation(p,r),p);
    int n=0,tar,request[limit];
    do{
        printf("enter theprocesses to request:");
        scanf("%d",&tar);
        printf("process request\t\t");
        ch = 'A';
        for (i = 0; i < r; i++, ch++)
                {
                    printf("%c ", ch);
                }
            printf("\n");
            printf("p%d",tar);
            for (j = 0; j < r; j++)
            {
                scanf("%d", &request[j]);
                // max[tar][j] += update[j]; 
            }
            for (i = 0; i < p; i++)
            {
                finish[i] = 0;
                safe_seq[i] = -1;
            }
            for (j = 0; j < r; j++)
                    work[j] = 0;
            for (i = 0; i < p; i++)
            {
                process[i] = i;
                for (j = 0; j < r; j++)
                {
                    if (available[j] > 0)
                        work[j] += allocation[i][j];
                    else
                    {
                        printf("cant allocate ");
                        return 1;
                    }
                }
            }
            int flag =0; // resource request algorithem
            for (j = 0; j < r; j++)
                { if(request[j] <= need[tar][j]) ;else flag =1;
                }
            for (j = 0; j < r; j++)
                { if(request[j] <= available[j]) ;else flag =1;
                }
            if(flag == 0){
                for (j = 0; j < r; j++)
                { available[j]-=request[j];
                    allocation[tar][j] +=request[j];
                    need[tar][j] -=request[j];
                }
            }else display(1,p);        
        printwork(r);    
        //calneedmatrix(p, r);
        display(resourceAllocation(p,r),p);
        printf("do you want to request more (1/0):");
        scanf("%d",&n);
    }while(n==1);
    return 0;
}
