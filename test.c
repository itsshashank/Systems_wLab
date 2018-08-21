#include<stdio.h>
#define max 50
struct perocess{
    int burst_t,comp_t,arr_t,wait_t,flag;
}p[max];
void main()
{
    int n,process=0,order[max],total_bt=0,temp;
    printf("Enter no of processes:");
    scanf("%d",&n);
    printf("Enter the Burst time and arrival time\n");
    while(process++<n){
        order[process]=process;
        printf("p%d\t",process);
        scanf("%d%d",&p[process].burst_t,&p[process].arr_t);
        p[process].flag=0;
        total_bt+=p[process].burst_t;
    }
    printf("Initial order of the processes:");
    for(int i=1;i<=n;i++){
        printf("%d\t",order[i]);
    }
    printf("\ntotal bt is %d",total_bt);
    for(int i=2;i<=n;i++){
        for(int j=i-1;j<n;j++){
            if(p[order[i]].arr_t<p[order[j]].arr_t){
                temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }
        }
    }
    printf("order of the processes:");
    for(int i=1;i<=n;i++){
        printf("%d\t",order[i]);
    }
}