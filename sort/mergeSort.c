#include <stdio.h>
#include <stdlib.h>
#define NUM 10

void merge(int *set, int left, int mid, int right)
{
    int *temp = (int*)malloc(sizeof(int)*(right - left +1));
    for(int count = left; count <= right; count++){
        temp[count - left] = set[count];
    }
    int i = left, j = mid + 1;
    for(int k = left; k <= right; k++){
                if(i > mid){
                    set[k] = temp[j - left];
                    j++;
                }else if(j > right){
                    set[k] = temp[i - left];
                    i++;
                }else if(set[i] < set[j]){
                    set[k] = temp[i - left];
                    i++;
                }else{
                    set[k] = temp[j - left];
                    j++;
                }
            }        
    free(temp);
}

void divide(int *set, int left, int right)
{
    if(left < right){
        int mid = (left + right) / 2;
        divide(set, left, mid);
        divide(set, mid+1, right);
        if(set[mid] > set[mid+1]){
            merge(set, left, mid, right);
        }
    }else{
        return;
    }
}

void mergeSort(int *set, int size)
{
    
    divide(set, 0, size - 1);
}

int main()
{
    int set[NUM];
    printf("plz input %d nums: ",NUM);
    for (int i = 0; i < NUM; i++)
    {
        scanf("%d", &set[i]);
    }
    int size = sizeof(set) / sizeof(int);
    mergeSort(set, size);
    for (int i = 0; i < NUM; i++)
    {
        printf("%4d", set[i]);
    }
    return 0;
}