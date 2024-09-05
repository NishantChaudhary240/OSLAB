#include <stdio.h>
#define MAX_FRAMES 50
#define MAX_PAGES 100
int findSecondChancePage(int frames[], int usedBits[], int frameCount, int *currentPointer)
{
    while (1)
    {
        int frameIndex = *currentPointer;
        if (usedBits[frameIndex] == 0)
        {
            return frameIndex;
        }
        else
        {
            usedBits[frameIndex] = 0;
            *currentPointer = (*currentPointer + 1) % frameCount;
        }
    }
}
int main()
{
    int i, j;
    int pageFaults = 0;
    int frameCount, pageCount;
    printf("\n\nName: Nishant Chaudhary\nRollno: 19\n\n__________________________________\n\n");
    printf("Enter number of reference strings: ");
    scanf("%d", &pageCount);
    printf("Enter size of frame: ");
    scanf("%d", &frameCount);
    int referenceString[pageCount];
    printf("Enter the elements of the reference string: \n");
    for (i = 0; i < pageCount; i++)
    {
        scanf("%d", &referenceString[i]);
    }
    int frames[frameCount];
    int usedBits[frameCount];
    int currentPointer = 0;
    for (i = 0; i < frameCount; i++)
    {
        frames[i] = -1;
        usedBits[i] = 0;
    }
    for (i = 0; i < pageCount; i++)
    {
        int page = referenceString[i];
        int isPageInFrames = 0;
        for (j = 0; j < frameCount; j++)
        {
            if (frames[j] == page)
            {
                isPageInFrames = 1;
                usedBits[j] = 1;
                break;
            }
        }
        if (!isPageInFrames)
        {
            int replaceIndex = findSecondChancePage(frames, usedBits, frameCount, &currentPointer);
            frames[replaceIndex] = page;
            usedBits[replaceIndex] = 1;
            pageFaults++;
        }
    }
    printf("\nNumber of page faults: %d\n", pageFaults);
    return 0;
}
