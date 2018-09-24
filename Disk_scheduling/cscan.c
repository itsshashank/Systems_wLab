#include <stdio.h>
#define max 50
int main()
{
    int i, j, key, len, head, queue[max], travel = 0;
    printf("enter the size of disk queue :");
    scanf("%d", &len);
    printf("enter the current head position :");
    scanf("%d", &head);
    printf("enter the disk queue:\t");
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &queue[i]);
    }
    //sort the queue
    for (i = 1; i < len; i++)
    {
        key = queue[i];
        j = i - 1;
        while (j >= 0 && queue[j] > key)
        {
            queue[j + 1] = queue[j];
            j = j - 1;
        }
        queue[j + 1] = key;
    }
    printf("enter direction to move (1 right /0 left) :");
    int dir, test = 0;
    scanf("%d", &dir);
    printf("enter the upper and lower bound of the disk :");
    int up, low;
    scanf("%d %d", &up, &low);
    if (dir == 1)
    {
        //assuming arm moves upwards
        for (i = 0; i < len; i++)
        {
            if (queue[i] >= head)
            {
                test = i;
                break;
            }
        }
        while (i < len)
        {
            travel += queue[i] - head;
            head = queue[i++];
        }
        //goes to the upper bound
        travel += up - head;
        head = up;
        //cycle to the begining
        //travel is not done since the cycle
        head = low;
        i = 0;
        while (i < test)
        {
            travel += queue[i] - head;
            head = queue[i++];
        }
    }
    else
    {
        for (i = 0; i < len; i++)
        {
            if (queue[i] >= head)
            {
                test = i;
                break;
            }
        }
        while (i > 0)
        {
            travel += head - queue[i];
            head = queue[i--];
        }
        //goes to the lower bound
        travel += head - low;
        head = low;
        //cycle to the END
        //travel is not done since the cycle
        head = up;
        //test = len;
        int temp = len- 1;
        while (temp > test)
        {
            travel += head - queue[temp];
            head = queue[temp--];
        }
    }
    printf("total head movement %d\n", travel);
    float avg = (float)travel / len;
    printf("The avg head movement is %.2f\n", avg);
    return 0;
}
