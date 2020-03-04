#include<stdio.h>
#include<iostream>
using namespace std;
bool judge(int *digital)
	{
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(digital[i]==digital[j])return false;
			}
		}
		return true;
	}
int main()
{
	int Solve;

	for(int i =0;i<8;i++)
	{
		for(int j=0;j<8;j++){
			for(int k=0;k<8;k++){
				for(int l=0;l<8;l++){
					for(int m=0;m<8;m++){
						for(int n=0;n<8;n++){
							for(int o=0;o<8;o++){
								for(int p=0;p<8;p++){
									int Horizontal[8]={i,j,k,l,m,n,o,p};
									int Na[8]={1+i,2+j,3+k,4+l,5+m,6+n,7+o,8+p};
									int Pie[8]={i-1,j-2,k-3,l-4,m-5,n-6,o-7,p-8};
									if(judge(Horizontal)&&judge(Pie)&&judge(Na))
									Solve++;
									}
								}
							}
						}
					}
				}
			}
		}
	cout<<Solve<<endl;
    system("pause");
    return 0;
}
