#include<stdio.h>
#define max 50
void main(){
    int burst_t[max],comp_t[max],/*arr_t[max]*/order[max],wait_t[max],n,process=0,clock_t = 0,temp;
    float avgw_t=0.0,avgt_t=0.0;
    printf("Enter the no of processes:");
    scanf("%d",&n);
    printf("Enter the Burst time and arrival time\n");
    while(process++<n){
        printf("p%d\t",process);
        scanf("%d",&burst_t[process]);
        order[process]=process;
    }
    process = 0;
    for(int i=2;i<=n;i++){
        for(int j=i-1;j<=n;j++){
            if(burst_t[order[i]]<burst_t[order[j]]){
                temp=order[i];
                order[i]=order[j];
                order[j]=temp;
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d\t",order[i]);
        wait_t[order[i]]=clock_t;
        clock_t+=burst_t[order[i]];
        comp_t[order[i]]=clock_t;
        avgw_t+=wait_t[order[i]];
        avgt_t+=comp_t[order[i]];
    }
    avgt_t/=n;avgw_t/=n;
    printf("Avg Waiting time = %2.f\nAvg Turnaround time =%2.f\n",avgw_t,avgt_t);
}
