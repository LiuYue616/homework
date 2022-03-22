#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *pre;
    Node *next;
};
void initList(Node *&L)
//初始化
{
    L=new Node;
    L->pre=NULL;
    L->next=NULL;
}
void createList1(Node *&L,int a[],int n)
//头插法
{
    Node *s;
    L=new Node;
    L->pre=NULL;
    L->next=NULL;
    for(int i=0;i<n;i++)
    {
        s=new Node;
        s->data=a[i];
        s->next=L->next;
        if(L->next!=NULL) L->next->pre=s;
        L->next=s;
        s->pre=L;
    }
}
void createList2(Node *&L,int a[],int n)
//尾插法
{
    Node *s,*r;
    L=new Node;
    L->next=NULL;
    r=L;
    for(int i=0;i<n;i++)
    {
        s=new Node;
        s->data=a[i];
        r->next=s;
        s->pre=r;
        r=s;
    }
    r->next=NULL;
}
void deleteList(Node *&L)
//删除链表
{
    Node *p=L,*k=L->next;
    while(k!=NULL)
    {
        delete p;
        p=k;
        k=p->next;
    }
    delete p;
}
int ListLength(Node *&L)
//求链表长度
{
    int t=0;
    Node *p=L;
    while(p->next!=NULL)
    {
        t++;
        p=p->next;
    }
    return t;
}
void Listdisplay(Node *&L)
//输出链表
{
    Node *p=L->next;
    while(p!=NULL)
    {
        cout<<p->data;
        p=p->next;
    }
}
bool addList(Node *&L,int i,int e)
//增加结点    表     位置     数据
{
    int j=0;
    Node *p=L,*s;
    if(i<=0) return false;
    while(j<i-1 && p!=nullptr)
    {
        j++;
        p=p->next;
    }
    if(p==nullptr) return false;
    else
    {
        s=new Node;
        s->data=e;
        s->next=p->next;
        p->next->pre=s;
        p->next=s;
        s->pre=p;
        return true;
    }
}
bool delList(Node *&L,int i)
//删除结点    表     位置   
{
    int j=0;
    Node *p=L,*s;
    if(i<=0) return false;
    while(j<i-1 && p!=nullptr)
    {
        j++;
        p=p->next;
    }
        if(p==nullptr) return false;
    else
    {
        s=p->next;
        p->next=s->next;
        s->next->pre=p;
        delete s;
        return true;
    }
}
bool getdata(Node *&L,int i,int &e)
//获得某个节点数据  表   位置   数据
{
    int j=0;
    Node *p=L,*s;
    if(i<=0) return false;
    while(j<i && p!=nullptr)
    {
        j++;
        p=p->next;
    }
    if(p==nullptr) return false;
    else
    {
        e=p->data;
        return true;
    }
}
bool setdata(Node *&L,int i,int e)
//修改某个节点数据  表  位置   数据
{
        int j=0;
    Node *p=L,*s;
    if(i<=0) return false;
    while(j<i && p!=nullptr)
    {
        j++;
        p=p->next;
    }
    if(p==nullptr) return false;
    else
    {
        p->data=e;
        return true;
    }
}
int Locatedata(Node *&L,int e)