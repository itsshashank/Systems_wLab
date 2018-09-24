#include <stdio.h>
#define max 50
int main()
{
    int len, head, queue[max], travel = 0;
    printf("enter the size of disk queue :");
    scanf("%d", &len);
    printf("enter the current head position :");
    scanf("%d", &head);
    printf("enter the disk queue:\t");
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &queue[i]);
        travel += (queue[i] > head) ? queue[i] - head : head - queue[i];
        head = queue[i];
    }
    printf("total head movement %d\n", travel);
    float avg = (float)travel / len;
    printf("The avg head movement is %.2f\n", avg);
    return 0;
}
