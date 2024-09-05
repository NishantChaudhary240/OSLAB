#include <stdio.h>
#include <limits.h>
int findLRUPage(int frames[], int frameCount, int pageIndex, int pageRef[])
{
    int i, j;
    int lruIndex = 0;
    int leastRecent = INT_MAX;
    for (i = 0; i < frameCount; i++)
    {
        int pageUsed = 0;
        for (j = pageIndex - 1; j >= 0; j--)
        {
            if (frames[i] == pageRef[j])
            {
                pageUsed = 1;
                if (j < leastRecent)
                {
                    leastRecent = j;
                    lruIndex = i;
                }
                break;
            }
        }
        if (pageUsed == 0)
        {
            return i;
        }
    }

    return lruIndex;
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
    for (i = 0; i < frameCount; i++)
    {
        frames[i] = -1;
    }
    int frameStates[frameCount][pageCount];
    for (i = 0; i < frameCount; i++)
    {
        for (j = 0; j < pageCount; j++)
        {
            frameStates[i][j] = -1;
        }
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
                break;
            }
        }
        if (!isPageInFrames)
        {
            int replaceIndex = findLRUPage(frames, frameCount, i, referenceString);
            frames[replaceIndex] = page;
            pageFaults++;
        }
        for (j = 0; j < frameCount; j++)
        {
            frameStates[j][i] = frames[j];
        }
    }
    printf("Page Requests\t");
    for (i = 0; i < pageCount; i++)
    {
        printf("%d\t", referenceString[i]);
    }
    printf("\n");
    for (i = 0; i < frameCount; i++)
    {
        printf("Frame %d\t\t", frameCount - i);
        for (j = 0; j < pageCount; j++)
        {
            if (frameStates[i][j] != -1)
                printf("%d\t", frameStates[i][j]);
            else
                printf("-\t");
        }
        printf("\n");
    }
    printf("\nNumber of page faults: %d\n", pageFaults);
    return 0;
}
