#include<iostream>
using namespace std;
typedef struct //页面类型
{ 
int pn; //页号
int pfn;//面号 
int counter; //一个周期内访问该页面的次数
int time //访问时间
} pl-type;
pfc_struct //页面控制结构
{ 
       int pn,pfn; 
       struct pfc_struct *next; 
} 
typedef   struct pfc_struct pfc_type;  
pfc_type  pfc_struct[total_vp];//定义用户进程虚页控制结构
pfc_type *freepf_head, *busypf_head; //空页面头的指针,忙页面头的指针
pfc_type  *busypf_tail; //忙页面尾的指针
void initialize( );//初始化函数,给每个相关的页面赋值。 
void FIFO( );//计算使用 FIFO 算法时的命中率。 
void LRU( );//计算使用 LRU 算法时的命中率。 

int a[total_instruction];//指令流数据组。 
int page[total_instruction];// 每条指令所属的页号。 
int offset[total_instruction];// 每页装入 10 条指令后取模运算页号偏移值。 
int total_pf;// 用户进程的内存页面数。 
int disaffect;//页面失效次数
int main()
{

}
void FIFO()
{

}