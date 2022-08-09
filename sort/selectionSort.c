#include <stdlib.h>
#include <stdio.h>

void selectionSort(int *set, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (set[j] < set[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            set[i] = set[i] ^ set[min];
            set[min] = set[i] ^ set[min];
            set[i] = set[i] ^ set[min];
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
    selectionSort(set, size);
    for (int i = 0; i < 10; i++)
    {
        printf("%4d", set[i]);
    }
    return 0;
}