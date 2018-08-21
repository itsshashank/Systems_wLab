#include<stdio.h>
#define max 50
struct process{
    int burst_t,comp_t,arr_t,wait_t,flag;
}p[max];
void main(){
    int n,clock_t=0,process=0,order[max],temp,total_bt=0;
    float avgw_t=0.0,avgt_t=0.0;
    printf("Enter no of processes:");
    scanf("%d",&n);
    printf("Enter the Burst time and arrival time\n");
    while(process++<n){
        printf("p%d\t",process);
        scanf("%d%d",&p[process].burst_t,&p[process].arr_t);
        printf("entered");
        order[process]=process;
        p[process].flag=0;
        total_bt+=p[process].burst_t;
    }
    printf("Initial order of the processes:");
    for(int i=1;i<=n;i++){
        printf("%d\t",order[i]);
    }
    process = 0;
    for(int i=2;i<=n;i++){
        for(int j=i-1;j<=n;j++){
            if(p[order[i]].arr_t<p[order[j]].arr_t){
                temp=order[i];
                order[i]=order[j];
                order[j]=temp;
            }
        }
    }
    process=0;
    while(p[order[process]].flag==0 && p[order[process]].arr_t<=clock_t){
            for(int i=process+1;p[order[i]].arr_t<=clock_t/*i<=n*/;i++){
                for(int j=i-1;p[order[j]].arr_t<=clock_t/*j<=n*/;j++){
                    if(p[order[i]].burst_t<p[order[j]].burst_t){
                        temp=order[i];
                        order[i]=order[j];
                        order[j]=temp;
                    }
                }
            }
            p[order[process]].flag=1;
            clock_t+=p[order[process]].burst_t;
            process++;
    }
    for(int i=1;i<=n;i++){
        printf("%d\t",order[i]);
        p[order[i]].wait_t=clock_t;
        clock_t+=p[order[i]].burst_t;
        p[order[i]].comp_t=clock_t;
        avgw_t+=p[order[i]].wait_t;
        avgt_t+=p[order[i]].comp_t;
    }
    avgt_t/=n;avgw_t/=n;
    printf("Avg Waiting time = %2.f\nAvg Turnaround time =%2.f\n",avgw_t,avgt_t);
}
