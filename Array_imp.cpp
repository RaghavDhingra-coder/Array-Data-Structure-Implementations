#include<iostream>
using namespace std;
#define OVERFLOW 1
#define INVALIDINDEX 2;
class DynArray
{
private:
int capacity;
int last_index;
int*p;
protected:
void doubleArray() // **
{ capacity=capacity*2;
    int*a=new int[capacity];
    for(int i=0;i<=last_index;i++)
    a[i]=p[i];
    delete []p;
    p=a;
}
public:

DynArray(int cap) //** 
{
capacity=cap;
p=new int[capacity];
last_index=-1;
}
~DynArray() // **
{
    delete[]p;
}

void halfArray() //** 
{ capacity=capacity/2;
int*a=new int[capacity];
for(int i=0;i<=last_index;i++)
a[i]=p[i];
delete []p;
last_index=capacity-1;
p=a;
}
int get_capacity()// **
{
    return capacity;
}
bool is_empty() //** 
{
   return last_index==-1; 
}
void append(int data) // **
{
if(is_full())
doubleArray();
p[last_index+1]=data;
last_index++;
}
void insert(int index,int data) // **
{
    if(index<0||index>last_index+1)
    throw INVALIDINDEX;
    if(is_full())
    doubleArray();
    for(int i=index;i<=last_index;i++)
    p[i+1]=p[i];
    p[index]=data;
    last_index++;
}
void edit(int index,int data) // **
{
if(index<0||index>last_index)
throw INVALIDINDEX;
p[index]=data;
}
void del(int index)
{
if(index<0||index>last_index)
throw INVALIDINDEX;
for(int i=index;i<last_index;i++)
p[i]=p[i+1];
last_index--;
if(capacity>1&&count()==capacity/2)
halfArray();
}
bool is_full() // **
{
    return last_index==capacity-1;
}
int get_element(int index)  //** 
{
if(index<0||index>last_index)
throw INVALIDINDEX;
return p[index];
}
int count()  // **
{
    return last_index+1;
}
int find_element(int data) // **
{
    for(int i=0;i<=last_index;i++)
    if(p[i]==data)
    return i;
    return -1;
}
void show()
{
    for(int i=0;i<=last_index;i++)
    cout<<p[i]<<" ";
}
};