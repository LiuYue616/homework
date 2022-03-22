#include<iostream>
#define size 10
using namespace std;
class ArrayList
{
    public:
    int arr[size];
    int length;
};
void init(ArrayList &t)
//初始化
{
    for(int i=0;i<size;i++)
        t.arr[i]=0;
    t.length=0;
}bool putat(ArrayList &t,int k,int p)
//增加指定位置的数据 表，插入位置，插入数据
{
    if(k<1||k>t.length+1) return false;
    for(int i=t.length;i>=k;i--)
        t.arr[i]=t.arr[i-1];
    t.arr[k-1]=p;
    t.length++;
    return true;
}
bool deleat(ArrayList &t,int k,int &p)
//删除指定位置的数据 表，删除位置，删除数据
{
    if(k<1||k>t.length+1) return false;
    p=t.arr[k-1];
    for(int i=k-1;i<t.length-1;i++)
        t.arr[i]=t.arr[i+1];
    t.length--;
    return true;
}
bool setat(ArrayList &t,int k,int p)
//修改指定位置的数据 表，修改位置，修改数据
{
    if(k<1||k>t.length+1) return false;
    t.arr[k-1]=p;
    return true;
}
bool searchat(ArrayList &t,int k)
//查询指定位置的数据 表，查询位置
{
    if(k<1||k>t.length+1) return false;
    cout<<t.arr[k-1]<<endl;
    return true;
}
int search(ArrayList &t,int p)
//查询指定数据的位置
{
    for(int i=0;i<t.length;i++)
    {
        if(t.arr[i]==p) return i;
    }
    return -1;
}