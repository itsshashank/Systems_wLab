#include <stdio.h>
#define max 50
struct process
{
    int burst_t, comp_t, arr_t, wait_t,remain_t,priority;
} p[max],temp;
void main(){
    int n, i,j, finish, process = 0, total_bt = 0, run = 0;
    float avgt_t=0.0,avgw_t=0.0;
    printf("Enter no of processes:");
    scanf("%d", &n);
    printf("Enter the priority ,Burst time and arrival time\n");
    while (process++ < n)
    {
        printf("p%d\t", process);
        scanf("%d%d%d",&p[process].priority, &p[process].burst_t, &p[process].arr_t);
        p[process].remain_t = p[process].burst_t;
        total_bt += p[process].burst_t;
    }
    //sort according to priority
    for (i = 2; i <= n; i++)
    {
        temp = p[i];
        j = i - 1;
        while (j >= 1 && p[j].priority > temp.priority)
        {
            p[j + 1] = p[j];
            j = j - 1;
        }
        p[j + 1] = temp;
    }
    for (int i = 1; i <= n; i++)
    {
        //printf("%d\t", order[i]);
        p[i].wait_t = run;
        run += p[i].burst_t;
        p[i].comp_t = run;
        avgw_t += p[i].wait_t;
        avgt_t += p[i].comp_t;
    }
    avgt_t /= n;
    avgw_t /= n;
    printf("\nAvg Waiting time = %.2f\nAvg Turnaround time =%.2f\n", avgw_t, avgt_t);
}