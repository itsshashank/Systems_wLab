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
    //assuming arm moves upwards
    printf("enter direction to move (1 right /0 left) :");
    int dir, test = 0;
    scanf("%d", &dir);
    if (dir == 1)
    {
        printf("enter the upper bound of the disk :");
        int up;
        scanf("%d", &up);
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
        while (--test >= 0)
        {
            travel += head - queue[test];
            head = queue[test];
        }
    }
    else
    {
        // alternative solution
        //goes to the lower and find the mx element
        printf("enter the lower bound of the disk (default as 0):");
        int low;
        scanf("%d", &low);
        test = queue[0];
        for (i = 1; i < len; i++)
            if (test < queue[i])
                test = queue[i];
        //travel to the low and move directly to the max
        travel += head - low;
        travel += test;
        //
    }
    printf("total head movement %d\n", travel);
    float avg = (float)travel / len;
    printf("The avg head movement is %.2f\n", avg);
    return 0;
}
