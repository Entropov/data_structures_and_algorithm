#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *set, int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (set[j] < set[j - 1])
            {
                set[j] = set[j] ^ set[j - 1];
                set[j - 1] = set[j] ^ set[j - 1];
                set[j] = set[j] ^ set[j - 1];
            }
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
    insertionSort(set, size);
    for (int i = 0; i < 10; i++)
    {
        printf("%4d", set[i]);
    }
    return 0;
}