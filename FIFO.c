#include <stdio.h>

int main()
{
    int incomingStream[] = {7, 0, 2, 4, 3, 1, 4, 7, 2, 0, 4, 3, 0, 3, 2, 7};
    int pageFaults = 0;
    int frames = 3;
    int m, n, s, pages;
    pages = sizeof(incomingStream) / sizeof(incomingStream[0]);
    printf("\n\nName: Nishant Chaudhary\nRollno: 19\n\n__________________________________\n\n");
    printf("Incoming\tFrame 1\tFrame 2\tFrame 3\n");
    int temp[frames];
    for (m = 0; m < frames; m++)
    {
        temp[m] = -1;
    }
    for (m = 0; m < pages; m++)
    {
        s = 0;
        for (n = 0; n < frames; n++)
        {
            if (incomingStream[m] == temp[n])
            {
                s++;
                pageFaults--;
                break;
            }
        }
        pageFaults++;
        if ((pageFaults <= frames) && (s == 0))
        {
            temp[pageFaults - 1] = incomingStream[m];
        }
        else if (s == 0)
        {
            temp[(pageFaults - 1) % frames] = incomingStream[m];
        }
        printf("%d\t\t", incomingStream[m]);
        for (n = 0; n < frames; n++)
        {
            if (temp[n] != -1)
                printf("%d\t", temp[n]);
            else
                printf("-\t");
        }
        printf("\n");
    }
    printf("\nTotal Page Faults:\t%d\n", pageFaults);
    return 0;
}
