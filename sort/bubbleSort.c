#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int set[], int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - i - 1; j++)
        {
            if (set[j] > set[j + 1])
            {
                set[j] = set[j] ^ set[j + 1];
                set[j + 1] = set[j] ^ set[j + 1];
                set[j] = set[j] ^ set[j + 1];
            }
        }
}
int main()
{
    int set[10];
    printf("plz input 10 nums: ");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &set[i]);
    }
    int size = sizeof(set) / sizeof(int);
    bubbleSort(set, size);
    for (int i = 0; i < 10; i++)
    {
        printf("%4d", set[i]);
    }
    return 0;
}
