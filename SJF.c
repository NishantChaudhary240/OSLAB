#include <stdio.h>
#define MAX 10

int main()
{
    printf("\n\nName: Nishant Chaudhary\nRollno: 19\n\n__________________________________\n\n");
    int n, i, j, temp;
    float sum = 0, wt;
    int pid[MAX], arv[MAX], bt[MAX];
    int start[MAX], finish[MAX];
    int currentTime = 0, completed = 0;
    int remaining_bt[MAX];
    int shortest, min_index;

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
        remaining_bt[i] = bt[i];
    }
    int is_completed[MAX] = {0};
    while (completed < n)
    {
        shortest = -1;
        for (i = 0; i < n; i++)
        {
            if (arv[i] <= currentTime && !is_completed[i] && (shortest == -1 || remaining_bt[i] < remaining_bt[shortest]))
            {
                shortest = i;
            }
        }

        if (shortest != -1)
        {
            start[shortest] = currentTime;
            finish[shortest] = start[shortest] + remaining_bt[shortest];
            currentTime = finish[shortest];
            is_completed[shortest] = 1;
            completed++;
        }
        else
        {

            currentTime++;
        }
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (finish[i] > finish[j])
            {

                temp = finish[i];
                finish[i] = finish[j];
                finish[j] = temp;

                temp = start[i];
                start[i] = start[j];
                start[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = arv[i];
                arv[i] = arv[j];
                arv[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }
    printf("After scheduling by burst time (SJF):\n");
    for (i = 0; i < n; i++)
    {
        printf("Process ID: %d, Arrival Time: %d, Burst Time: %d, Start Time: %d, Finish Time: %d\n",
               pid[i], arv[i], bt[i], start[i], finish[i]);
    }

    printf("\nGantt Chart:\n");
    printf("0");
    for (i = 0; i < n; i++)
    {
        printf("---P%d---%d", pid[i], finish[i]);
    }
    printf("\n");
    printf("\n");
    printf("\nProcess Table\n");
    printf("ID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], arv[i], bt[i], finish[i], finish[i] - arv[i], finish[i] - arv[i] - bt[i]);
        sum += (finish[i] - arv[i] - bt[i]);
    }
    wt = sum / n;
    printf("\nThe average waiting time is %f\n", wt);

    return 0;
}