#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef struct QNode *PtrToQNode;
struct QNode {
    int *Data;      /* 存储元素的数组   */
    int  Front;
};
bool cmp(const int p1,const int p2)
{
    if(p1<p2)
    {
        return false;
    }
    else{
        return true;
    }
}
typedef PtrToQNode Deque;
Deque createdeque()
{
    Deque D;
    D= (Deque)malloc(sizeof(struct QNode));
    D->Data=(int *)malloc(100000*sizeof(int));
    D->Front=-1;
    return D;
}
Deque Pop(Deque s)
{
    Deque D=s;
    if(D->Front<0)
    {
        cout<<"Invalid"<<endl;
        return D;
    }
    else
    {
        cout<<D->Data[D->Front]<<endl;
        D->Front--;
        return D;
    }
    
}
bool PeekMedian(Deque D)
{
    Deque s=createdeque();
    
    if(D->Front<0)
    {
        return false;
    }
    else
    {
        
            
        s->Front=D->Front;
        for(int i=0;i<=D->Front;i++)
        {
            s->Data[i]=D->Data[i];
        }
        sort(s->Data,s->Data+(s->Front+1),cmp);
        if((s->Front)%2==0)
        {
            cout<<s->Data[(s->Front)/2]<<endl;
        }
        else
        {
            cout<<s->Data[((s->Front+1))/2]<<endl;
        }
        return true;
    }
    
}
Deque Push(  Deque t,int X )
{
    Deque D;
    D=t;
    D->Front++;
    D->Data[D->Front]=X;
    return D;
}
int main()
{
  //  cout<<"sjhf"<<endl;
    int n;
    cin>>n;
    string name;
    int m;
    Deque s;
    s=createdeque();
    for(int i=0;i<n;i++)
    {
        cin>>name;
        if(name=="Pop")
        {
            m=1;
        }
        else if(name=="Push")
        {
            m=2;
        }
        else if(name=="PeekMedian")
        {
            m=3;
        }
        else
        {
            
        }
        switch(m)
        {
            case 1 :
            {
                
                s=Pop(s);
                break;
            }
            case 2 :
            {
                int t;
                cin>>t;
                s=Push(s,t);
                break;
            }
            case 3:
            {
                
                if(PeekMedian(s))
                {
                    
                }
                else
                {
                    cout<<"Invalid"<<endl;
                }
                break;
            }
        }
    }
    
    
    return 0;
}
