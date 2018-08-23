#include <stdio.h>
#define max 50
struct perocess
{
    int burst_t, comp_t, arr_t, wait_t, flag;
} p[max];
void print_order(int arr[], int n)
{
    printf(" order of the processes:");
    for (int i = 1; i <= n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
void main()
{
    int n, i, j, key, process = 0, order[max], total_bt = 0, run = 0;
    float avgt_t=0.0,avgw_t=0.0;
    printf("Enter no of processes:");
    scanf("%d", &n);
    printf("Enter the Burst time and arrival time\n");
    while (process++ < n)
    {
        order[process] = process;
        printf("p%d\t", process);
        scanf("%d%d", &p[process].burst_t, &p[process].arr_t);
        p[process].flag = 0;
        total_bt += p[process].burst_t;
    }
    for (i = 2; i <= n; i++)
    {
        key = order[i];
        j = i - 1;
        while (j >= 1 && p[order[j]].arr_t > p[key].arr_t)
        {
            order[j + 1] = order[j];
            j = j - 1;
        }
        order[j + 1] = key;
    }
    process = 0;
    while (run <= total_bt && process++ < n)
    {
        if (p[order[process]].arr_t < run && p[order[process]].flag == 0)
        {
            for (int i = process; i <= n && p[order[i]].arr_t < run; i++)
            {
                key = order[i];
                j = i - 1;
                while (j >= process && p[order[j]].burst_t > p[key].burst_t)
                {
                    order[j + 1] = order[j];
                    j = j - 1;
                }
                order[j + 1] = key;
            }
        }
        p[order[process]].flag = 1;
        run += p[order[process]].burst_t;
        //printf("process %d is done and run time is %d \n",order[process],run);
    }
    run = 0;
    printf("\t Guntt Chart\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d\t", order[i]);
        p[order[i]].wait_t = run;
        run += p[order[i]].burst_t;
        p[order[i]].comp_t = run;
        avgw_t += p[order[i]].wait_t;
        avgt_t += p[order[i]].comp_t;
    }
    avgt_t /= n;
    avgw_t /= n;
    printf("\nAvg Waiting time = %.2f\nAvg Turnaround time =%.2f\n", avgw_t, avgt_t);
}