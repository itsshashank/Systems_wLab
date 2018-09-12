#include<stdio.h>
#define limit 50
int available[limit],max[limit][limit],allocation[limit][limit],need[limit][limit];
void cal_need_matrix(int n,int m){ //need = max - allocation
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}
int main()
{
    int p,r,i,j;
    printf("Enter the no of process and no of resources:");
    scanf("%d%d",&p,&r);
    printf("Enter the available instances of resources");
    for(i=0;i<r;i++)
        scanf("%d",&available[i]);
    printf("Enter the Allocation and max for a process:\n");
    printf("process\tAllolcation\tmax\n\t\t");
    char ch ='A';
    for(i=0;i<m;i++,r++)
        printf("%c\t",r);
        ch ='A';
    for(i=0;i<m;i++,r++)
        printf("%c\t",r);
    printf("\n");    
    for(i=0;i<n;i++){
        printf("p%d\t",i+1);
        for(j=0;j<m;j++){
            scanf("%d%d",&allocation[i][j],&max[i][j]);
        }
    }
    cal_need_matrix(n,m); // to calculate need matrix
    int safe_seq[p];
    printf("\nSystem is in safe state the sequnece is :")
	for (int i = 0; i < P ; i++)
		printf("%d\t",safe_seq[i]);
    return 0;
}
