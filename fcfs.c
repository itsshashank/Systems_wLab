#include<stdio.h>
#define max 50
struct process{
    int burst_t,comp_t,arr_t,wait_t;
}p[max];
void main(){
    int n,clock_t=0,process=0;
    float avgw_t=0.0,avgt_t=0.0;
    printf("Enter no of processes:");
    scanf("%d",&n);
    printf("Enter the Burst time and arrival time\n");
    while(process++<n){
        printf("p%d\t",process);
        scanf("%d%d",&p[process].burst_t,&p[process].arr_t);
        p[process].wait_t=clock_t-p[process].arr_t;
        clock_t+=p[process].burst_t;
        p[process].comp_t=clock_t;
        avgw_t+=p[process].wait_t;
        avgt_t+=p[process].comp_t-p[process].arr_t;
    }
    avgt_t/=n;avgw_t/=n;
    printf("Avg Waiting time = %2.f\nAvg Turnaround time =%2.f\n",avgw_t,avgt_t);
}