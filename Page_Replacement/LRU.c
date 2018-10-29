#include <stdio.h>
#define max 25
int page[max], hits[max];
int top = 0, len, next = 0;
int search(int ch)
{
    for (int i = 0; i < top; i++)
        if (ch == page[i])
            return i;
    return -1;
}
void printPage()
{
    printf("\n");
    for (int i = 0; i < len; i++)
        printf("--");
    printf("\n");
    printf("|");
    for (int i = 0; i < len; i++)
        if (i < len)
            printf("%d|", page[i]);
        else
            printf("0|");
    printf("\n");
    for (int i = 0; i < len; i++)
        printf("--");
    printf("\n");
}
int findLeast()
{
    int min = hits[0], minI = 0;
    for (int i = 1; i < len; i++)
    {
        if (hits[i] < min)
        {
            minI = i;
            min = hits[i];
        }
    }
    return minI;
}
void replace(int a)
{
    next = findLeast();
    page[next] = a;
}
void push(int ch)
{
    if (top < len)
    {
        page[top] = ch;
        hits[top] = 0;
        top++;
    }
    else
        replace(ch);
}
int main(int argc, char const *argv[])
{
    int seq[max], seq_len;
    int no_of_pageFaults = 0;
    printf("Enter the max size of pages: ");
    scanf("%d", &len);
    printf("Enter the size of sequence: ");
    scanf("%d", &seq_len);
    printf("Enter the sequence :");
    //scanf("%s",seq);
    for (int i = 0; i < seq_len; i++)
    {
        scanf("%d", &seq[i]);
    }
    printf("The paging \n");
    for (int i = 0; i < seq_len; i++)
    {
        printf("%d\t", seq[i]);
        int loc = search(seq[i]);
        if (loc >= 0) //no page fault
            hits[loc]++;                    // do nothing
        else
        {
            no_of_pageFaults++;
            push(seq[i]);
        }
        printPage();
    }
    printf("no of page fault is %d and Fault Rate is %f\n", no_of_pageFaults, (float)no_of_pageFaults / seq_len);
    return 0;
}