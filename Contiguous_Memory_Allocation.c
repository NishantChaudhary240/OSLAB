#include <stdio.h>
#include <stdlib.h>
#define MAX_FILES 10
void allocateFiles(int file_sizes[], int num_files, int disk_size)
{
    int i, j, k, allocated;
    int disk[disk_size];
    for (i = 0; i < disk_size; i++)
        disk[i] = 0;
    printf("Allocating files...\n");
    for (i = 0; i < num_files; i++)
    {
        allocated = 0;
        for (j = 0; j <= disk_size - file_sizes[i]; j++)
        {
            for (k = j; k < j + file_sizes[i]; k++)
            {
                if (disk[k] != 0)
                    break;
            }
            if (k == j + file_sizes[i])
            {
                for (k = j; k < j + file_sizes[i]; k++)
                    disk[k] = i + 1;
                allocated = 1;
                printf("File %d (size %d) allocated from block %d to block %d\n", i + 1, file_sizes[i], j, j + file_sizes[i] - 1);
                break;
            }
        }
        if (!allocated)
            printf("File %d (size %d) could not be allocated\n", i + 1, file_sizes[i]);
    }
    printf("\nFinal Disk Allocation:\n");
    printf("Block\tFile ");
    for (i = 0; i < disk_size; i++)
        printf("%d ", disk[i]);
    printf("\n");
}

int main()
{
    int file_sizes[MAX_FILES];
    int num_files, disk_size;
    int i;
    printf("\n\nName: Nishant Chaudhary\nRollno: 19\n\n__________________________________\n\n");
    printf("Enter the number of files (max %d): ", MAX_FILES);
    scanf("%d", &num_files);

    if (num_files < 1 || num_files > MAX_FILES)
    {
        printf("Invalid number of files. Must be between 1 and %d.\n", MAX_FILES);
        return 1;
    }

    printf("Enter the sizes of the files:\n");
    for (i = 0; i < num_files; i++)
    {
        printf("Size of file %d: ", i + 1);
        scanf("%d", &file_sizes[i]);
    }
    printf("Enter the size of the disk: ");
    scanf("%d", &disk_size);
    if (disk_size <= 0)
    {
        printf("Invalid disk size. Must be greater than 0.\n");
        return 1;
    }
    allocateFiles(file_sizes, num_files, disk_size);
    return 0;
}
