#include<iostream>
#include<time.h>
#include<cmath>
using namespace std;
void buckerSort(int* p,int n);//桶排序
int main()
{
     int i,n;
    int num=1000;
    cin>>n;
    clock_t start1=clock();
    while(num>0)
    {
        int p[n];
        for(i=0;i<n;i++)
        {
            p[i]=(rand() % (n));
        }
     //   insertionSort(p,n);
     //   quickSort(p,0,n-1);
     buckerSort(p,n);
        num--;
    }
    clock_t end1=clock();
    cout<<"buckerSort:"<<end1-start1<<endl;
    system("pause");
    return 0;
}
void buckerSort(int* p,int n)
{
    int bucket[n]={0};
    for(int i=0;i<n;i++)
    {
        bucket[p[i]]=bucket[p[i]]+1;
    }
    int j=0;
    for(int i=0;i<n;i++)
    {
        while(bucket[i]!=0)
        {
            p[j]=i;
            bucket[i]=bucket[i]-1;
            j=j+1;
        };
        
    }

}