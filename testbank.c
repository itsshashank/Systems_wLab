#include<stdio.h>
#define limit 50
int available[limit],max[limit][limit],allocation[limit][limit],need[limit][limit];
void calneedmatrix(int n,int m){ //need = max - allocation
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}
int nfeed(int a){
  return a;
}
void printwork(int r){
    for(int j=0;j<r;j++){
            printf("%d",available[j]);
        }
}
int main()
{
    int p,r,i,j;
    char ch ='A';
    printf("Enter the no of process and no of resources:");
    scanf("%d%d",&p,&r);
    printf("Enter the instances of resources:\n");
    for(i=0;i<r;i++,ch++){
        printf("%c:",ch);
        scanf("%d",&available[i]);
    }
    printwork(r);
    printf("Enter the Allocation and max for a process:\n");
    printf("process\tAllolcation\n\t");
    ch ='A';
    for(i=0;i<r;i++,ch++)
        printf("%c ",ch);
    printf("\n");
    for(i=0;i<p;i++){
        printf("p%d\t",i+1);
        for(j=0;j<r;j++){
            scanf("%d",&allocation[i][j]);
            if(available[j]>0)
                available[j] -= allocation[i][j];
            else{  printf("cant allocate ");
                    return 1;
            }    
        }
    }
    printwork(r);
    printf("process\tmax\n\t");
    ch ='A';
    for(i=0;i<r;i++,ch++)
        printf("%c ",ch);
    printf("\n");
    for(i=0;i<p;i++){
        printf("p%d\t",i+1);
        for(j=0;j<r;j++){
            scanf("%d",&max[i][j]);
        }
    }
    calneedmatrix(p,r); // to calculate need matrix
    int safe_seq[limit],finish[p],nextp;
    i=0;
    while(i<p){
      nextp = -1;
      for(j=0;j<p;j++){
        if(finish[j] == 0){
          int k;
          for(k=0;k<r;k++)
            if(need[j][k]>=available[k])
              break;
            if(k==r){
                int l;
                for(l=0;l<r;l++)
                available[k] +=allocation[i][l];
            safe_seq[i++] = j;
            finish[j]=1;
            nextp = 1;
            }
        }
      }
      if(nextp == -1){
        printf("System is not in safe state\n");
        continue;
      }
    }
    printf("\nSystem is in safe state the sequnece is :");
  	for (i = 0; i < p ; i++)
  		printf("%d\t",safe_seq[i]);
    return 0;
}
