#include <stdio.h>
int main()
{
    printf("\n\nName: Nishant Chaudhary\nRollno: 19\n\n__________________________________\n\n");
    int n, i, j, temp;
    float sum = 0, wt;
    int pid[10], arv[10], bt[10];
    int start[10], finish[10];
    int currentTime = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the process IDs:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pid[i]);
    }

    printf("Enter the arrival times of processes:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arv[i]);
    }

    printf("Enter the burst times of processes:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arv[j] > arv[j + 1])
            {

                temp = arv[j];
                arv[j] = arv[j + 1];
                arv[j + 1] = temp;

                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (currentTime < arv[i])
        {
            currentTime = arv[i];
        }
        start[i] = currentTime;
        finish[i] = start[i] + bt[i];
        currentTime = finish[i];
    }

    printf("After sorting by arrival time:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process ID: %d, Arrival Time: %d, Burst Time: %d, Start Time: %d, Finish Time: %d\n",
               pid[i], arv[i], bt[i], start[i], finish[i]);
    }
    printf("\nGantt Chart:\n");
    printf("0");
    for (int i = 0; i < n; i++)
    {
        printf("---P%d---%d", pid[i], finish[i]);
    }
    printf("\n");

    printf("\nProcess Table\n");
    printf("ID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], arv[i], bt[i], finish[i], finish[i] - arv[i], finish[i] - arv[i] - bt[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++)
    {
        sum = sum + (finish[i] - arv[i] - bt[i]);
    }
    wt = sum / n;
    printf("the average waiting time is %f", wt);
    return 0;
}
