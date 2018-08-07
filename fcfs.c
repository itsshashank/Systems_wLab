#include<stdio.h>
#define max 50
void main(){
    int burst_t[max],comp_t[max],arr_t[max],wait_t[max],n,clock_t = 0,process=0;
    float avgw_t=0.0,avgt_t=0.0;
    printf("Enter no of processes:");
    scanf("%d",&n);
    printf("Enter the Burst time and arrival time\n");
    while(process++<n){
        printf("p%d\t",process);
        scanf("%d%d",&burst_t[process],&arr_t[process]);
        wait_t[process]=clock_t-arr_t[process];
        clock_t+=burst_t[process];
        comp_t[process]=clock_t;
        avgw_t+=wait_t[process];
        avgt_t+=comp_t[process]-arr_t[process];
    }
    avgt_t/=n;avgw_t/=n;
    printf("Avg Waiting time = %2.f\nAvg Turnaround time =%2.f\n",avgw_t,avgt_t);
}