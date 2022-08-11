#include <stdio.h>
#include <stdlib.h>

void shellSort(int *set, int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            for (int j = i; j >= gap; j -= gap)
            {
                if (set[j] < set[j - gap])
                {
                    set[j] = set[j] ^ set[j - gap];
                    set[j - gap] = set[j] ^ set[j - gap];
                    set[j] = set[j] ^ set[j - gap];
                }
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
    shellSort(set, size);
    for (int i = 0; i < 10; i++)
    {
        printf("%4d", set[i]);
    }
    return 0;
}