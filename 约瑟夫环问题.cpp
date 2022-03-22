//约瑟夫环问题：设编号为1，2，3，……，n的n(n>0)个人按顺时针方向围坐一圈，m为任意一个正整数。
//从第一个人开始顺时针方向自1起顺序报数，报到m时停止并且报m的人出列，再从他的下一个人开始重新
//从1报数，报到m时停止并且报m的人出列。如此下去，直到所有人全部出列为止。要求设计一个程序模拟
//此过程，对任意给定的m和n，求出出列编号序列。
//实验要求：用顺序表实现。
#include<iostream>
using namespace std;
class biao
{
public:
    int* p;
    int* L;
    int length;
    int e;
};
void create(biao& t, int n)
//创建顺序表      表   n个人
{
    t.length = n;
    t.e = n;
    t.p = new int[n];//开始的队列
    t.L = new int[n];//最终的队列
    for (int i = 0; i < t.length; i++)
        t.p[i] = i + 1;
}
void del(biao& t, int g)
//删除对应位置的数据
{
    if (g<0 || g>t.length) { cout << "删除失败，越界" << endl; return; }
    for (int i = g - 1; i < t.length - 1; i++)
        t.p[i] = t.p[i + 1];
    t.length--;
}
void chulie(biao& t, int m)
{
    int i = 0;
    int k = 0;
    int l = 1;
    while ( k < t.e )
    {
        if (l % m == 0)
        {
            t.L[k] = t.p[i];
            del(t, i + 1);
            l = 1;
            k++;
        }
        l++;
        i++;
        if (i >= t.length) i = 0;
    }
}
void display(biao& t)
{
    for (int i = 0; i < t.e; i++)
        cout << t.L[i] << endl;
}
int main()
{
    biao y;
    int m,n;
    cin >> n >> m;
    create(y, n);
    chulie(y, m);
    display(y);
}