#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
#define max 30
int lcs_length1(string a,string b);
/*
int lcs_length2(string a,string b)
{
    int[max][max] len;
    len.resize(a.size()+1);
    for(int i=0;i<a.size();i++)
    {
        len[i].resize(b.size()+1,0);
    }
    for(int i=1;i<=a.size();i++)
    {
        for(int j=1;j<=b.size();j++)
        {
            if(a[i-1]==b[i-1])
            {
                len[i][j]=len[i-1][j-1]+1;
            }
            else if(len[i-1][j]>=len[i][j-1])
            {
                len[i][j]=len[i-1][j];
            }
            else
            {
                len[i][j]=len[i][j-1];
            }
            
        }
    }

    int aPos= a.size();
    int bPos= b.size();
    int commonLen=len[aPos][bPos];//此为最长公共子序列的长度
    int k=commonLen;
    vector<char> common;
    common.resize(commonLen);
    //沿着先前构建的表进行回溯
    while(aPos && bPos)
    {
        if(len[aPos][bPos]=len[aPos-1][bPos-1]+1)
        {
            common[--k] = a[--aPos];
            bPos--;
        }
        else if(len[aPos][bPos]=len[aPos-1][bPos])
        {
            aPos--;
        }
        else
        {
            bPos--;
        }
    }
    //输出最长公共子序列
    for(int i = 0; i < commonLen; i++)
    {
       cout<<common[i];
    }
    cout<<endl;
    return commonLen;
}
*/
int main()
{
    
    string s1="ACCGGTCGAGATGCAG";
    string s2="GTCGTTCGGAATGCAT";
    cout<<"hello world";
    cout<<lcs_length1(s1,s2)<<endl;
    
   cout<<"hello world";
   system("pause");
    return 0;
}
int lcs_length1(string a,string b)
{
    vector<vector<int>> len;
    len.resize(a.size()+1);
    for(int i=0;i<=a.size();++i)
    {
        len[i].resize(b.size()+1,0);
    }
    for(int i=1;i<=a.size();i++)
    {
        for(int j=1;j<=b.size();j++)
        {
            if(a[i-1]==b[i-1])
            {
                len[i][j]=len[i-1][j-1]+1;
            }
            else if(len[i-1][j]>=len[i][j-1])
            {
                len[i][j]=len[i-1][j];
            }
            else
            {
                len[i][j]=len[i][j-1];
            }
            
        }
    }

    int aPos= a.size();
    int bPos= b.size();
    int commonLen=len[aPos][bPos];//此为最长公共子序列的长度
    int k=commonLen;
    vector<char> common;
    common.resize(commonLen);
    //沿着先前构建的表进行回溯
    while(aPos!=0 && bPos!=0)
    {
        if(len[aPos][bPos]==len[aPos-1][bPos-1]+1)
        {
            common[--k] = a[--aPos];
            bPos--;
        }
        else if(len[aPos][bPos]==len[aPos-1][bPos])
        {
            aPos--;
        }
        else
        {
            bPos--;
        }
    }
    //输出最长公共子序列
    for(int i = 0; i < commonLen; i++)
    {
       cout<<common[i];
    }
    cout<<endl;
    return commonLen;
}