#include <iostream>
#include<time.h>
#define NUM 12
using namespace std;
int cat[NUM];
void getNum(int a[]);
void monkeySort(int a[]);
void bubbleSort(int a[]);
int main()
{
    getNum(cat);
    for(int i=0;i<NUM;i++){
        cout<<cat[i]<<" ";
    }
    cout<<endl;
    cout<<"press 1 to start monkeySort or 2 bubbleSort."<<endl;
    int in;
    cin>>in;
    if(in==1){
        monkeySort(cat);
    }
    else if(in==2){
        bubbleSort(cat);
    }

    for(int i=0;i<NUM;i++){
            cout<<cat[i]<<" ";
        }
    return 0;
}
void getNum(int a[])
{
    srand((unsigned)time(NULL));
    for(int i=0;i<NUM;i++){
        a[i] = rand()%100+1;
    }
}
bool sortCheck(int a[])
{
    for(int i=0;i<NUM-1;i++){
        if(a[i]>a[i+1])return 1;
    }
    return 0;
}
void monkeySort(int a[])
{
    srand((unsigned)time(NULL));
    while(sortCheck(a)!=0){
        int n = rand()%NUM;
        int m = rand()%NUM;
        if(n!=m){
            a[n]=a[n]^a[m];
            a[m]=a[n]^a[m];
            a[n]=a[n]^a[m];
        }
    }
}
void bubbleSort(int a[])
{
    for(int i=0;i<NUM-1;i++){
        for(int j=0;j<NUM-1-i;j++){
            if(a[j]>a[j+1]){
                a[j]=a[j+1]^a[j];
                a[j+1]=a[j+1]^a[j];
                a[j]=a[j+1]^a[j];
            }
        }
    }
}