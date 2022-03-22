#include<iostream>
#define size 10
using namespace std;
class Stack
{
    public:
    char arr[size];
    int length;
};
void init(Stack &t)
//初始化栈
{
    t.length=0;
}
bool Stackempty(Stack &t)
//判断栈是不是空的
{
    if(t.length==0) return true;
    else return false;
}
bool Push(Stack &t,char e)
//入栈操作
{
    if(t.length==size-1) return false;
    t.arr[t.length]=e;
    t.length++;
    return true;
}
bool Pop(Stack &t,char e)
//出栈操作
{
    if(t.length==size-1) return false;
    t.length--;
    e=t.arr[t.length];
    return true;
}
bool bracketmatch(Stack &t,char p[])
//匹配括号
{
    init(t);
    if(!Stackempty(t)) return false;
    int i=0;
    while(p[i]!='\0')
    {
        if(p[i]=='(')
        {
            Push(t,'(');
            p++;
        }
        else if(p[i]==')')
        {
            Pop(t,')');
            p++;
        }
    }
    if(Stackempty(t)) return true;
    else return false;
}