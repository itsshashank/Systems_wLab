#include <stdio.h>
#define max 50
struct process
{
    int burst_t, comp_t, arr_t, flag, wait_t,priority;
} p[max];
//Lowest priority is first
void print_order(int arr[], int n)
{
    printf(" order of the processes:");
    for (int i = 1; i <= n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
void main(){
    int key, n, i,j, finish, process = 0, order[max], total_bt = 0, run = 0;
    float avgt_t=0.0,avgw_t=0.0;
    printf("Enter no of processes:");
    scanf("%d", &n);
    printf("Enter the priority ,Burst time and arrival time\n");
    while (process++ < n)
    {
        printf("p%d\t", process);
        scanf("%d%d%d",&p[process].priority, &p[process].burst_t, &p[process].arr_t);
        total_bt += p[process].burst_t;
        order[process] = process;
        p[process].flag = 0;
    }
    //print_order(order,n);
    for (i = 2; i <= n; i++){   //sort based on arr_t
        key = order[i];
        j = i - 1;
        while (j >= 1 && p[order[j]].arr_t > p[key].arr_t)
        {
            order[j + 1] = order[j];
            j = j - 1;
        }
        order[j + 1] = key;
    }
    //print_order(order,n);
    process = 0;
    while (run <= total_bt && process++ < n)
    {
        if (p[order[process]].arr_t <= run && p[order[process]].flag == 0)
        {
            for (int i = process; i <= n && p[order[i]].arr_t <= run; i++) //sort based on priority
            {   //print_order(order,n);
                key = order[i];
                j = i - 1;
                while (j >= process && p[order[j]].priority > p[key].priority)
                {
                    order[j + 1] = order[j];
                    j = j - 1;
                }
                order[j + 1] = key;
            }
        }
        p[order[process]].flag = 1;
        run += p[order[process]].burst_t;
    }
    run = 0;
    for (int i = 1; i <= n; i++)
    {
        //printf("%d\t", order[i]);
        p[order[i]].wait_t = run;
        run += p[order[i]].burst_t;
        p[order[i]].comp_t = run;
        avgw_t += p[order[i]].wait_t-p[order[i]].arr_t;
        avgt_t += p[order[i]].comp_t - p[order[i]].arr_t; //TAT= Completion time-arrival time
    }
    avgt_t /= n;
    avgw_t /= n;
    printf("\nAvg Waiting time = %.2f\nAvg Turnaround time =%.2f\n", avgw_t, avgt_t);
}
