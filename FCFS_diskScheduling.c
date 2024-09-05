#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 8
void FCFS(int arr[], int head)
{
    int seek_count = 0;
    int cur_track, distance;
    int i;
    for (i = 0; i < SIZE; i++)
    {
        cur_track = arr[i];
        distance = abs(head - cur_track);
        seek_count += distance;
        head = cur_track;
    }
    printf("Total number of seek operations: %d\n", seek_count);
    printf("Seek Sequence is:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d\n", arr[i]);
    }
}
int main()
{
    printf("\n\nName: Nishant Chaudhary\nRollno: 19\n\n__________________________________\n\n");
    int requests1[SIZE] = {98, 183, 41, 122, 14, 124, 65, 67};
    int initial_head_position1 = 53;
    printf("First set of requests:\n");
    FCFS(requests1, initial_head_position1);
    return 0;
}
