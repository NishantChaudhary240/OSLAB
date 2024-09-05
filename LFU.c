#include <stdio.h>
int main()
{
    int i, j, n, page[50], frameno, frame[10], move = 0, flag = 0, count = 0, count1[10] = {0};
    int repindex, leastcount;
    printf("\n\nName: Nishant Chaudhary\nRollno: 19\n\n__________________________________\n\n");
    printf("Enter the number of pages\n");
    scanf("%d", &n);
    printf("Enter the page reference numbers\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &page[i]);
    }
    printf("Enter the number of frames\n");
    scanf("%d", &frameno);

    for (i = 0; i < frameno; i++)
    {
        frame[i] = -1;
    }
    for (i = 0; i < n; i++)
    {
        flag = 0;
        for (j = 0; j < frameno; j++)
        {
            if (page[i] == frame[j])
            {
                flag = 1;
                count1[j]++;
                break;
            }
        }
        if (flag == 0)
        {
            if (count < frameno)
            {
                frame[move] = page[i];
                count1[move] = 1;
                move = (move + 1) % frameno;
                count++;
            }
            else
            {
                repindex = 0;
                leastcount = count1[0];
                for (j = 1; j < frameno; j++)
                {
                    if (count1[j] < leastcount)
                    {
                        leastcount = count1[j];
                        repindex = j;
                    }
                }
                frame[repindex] = page[i];
                count1[repindex] = 1;
                count++;
            }
        }
    }

    printf("Number of page faults is %d\n", count);
    return 0;
}
