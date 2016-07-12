/*************************************************************************
	> File Name: ll.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年07月02日 星期六 16时50分29秒
 ************************************************************************/
/*
 * 给定一个数列a1,a2,...an
 * 进行以下6种操作
 * ADD x y D :给第x个数到第y个数加D(增加一个add进行延迟标记)
 * REVERSE x y :反转[x,y]之间的数(伸展树经典操作)
 * REVOLVE x y T:循环右移T次(先把T对长度进行取模，然后就相当于把[y-T+1,y]放在[x,y-T]前面)
 * INSERT x P:在第x个数后面插入P （经典的插入）
 * DELETE x:删除第x个数（删除操作）
 * MIN x y:查询[x,y]之间最小的数(标记)
 *
 * 需要的操作:反转、删除、插入、查询区间最小值、成段更新、区间搬移(循环右移转化为区间搬移)
 * 需要的变量:pre,ch,key,size,add,rev,m(最小值)
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define Key_value ch[ch[root][1]][0]
#define Key_Value ch[ch[root][1]][0]
const int MAXN=200010;
const int INF=0x3f3f3f3f;
int pre[MAXN],ch[MAXN][2],key[MAXN],size[MAXN],add[MAXN],rev[MAXN],m[MAXN];
int root,tot1;
int s[MAXN],tot2;//内存池、内存池容量
int a[MAXN];
int n,q;

void NewNode(int &r,int father,int k)
{
    if(tot2)r=s[tot2--];
    else r=++tot1;
    ch[r][0]=ch[r][1]=0;
    pre[r]=father;
    size[r]=1;
    add[r]=rev[r]=0;
    key[r]=m[r]=k;
}
void Update_Rev(int r)
{
    if(!r)return;
    swap(ch[r][0],ch[r][1]);
    rev[r]^=1;
}
void Update_Add(int r,int ADD)
{
    if(!r)return;
    add[r]+=ADD;
    key[r]+=ADD;
    m[r]+=ADD;
}
void Push_Up(int r)
{
    size[r]=size[ch[r][0]]+size[ch[r][1]]+1;
    m[r]=key[r];
    if(ch[r][0])m[r]=min(m[r],m[ch[r][0]]);
    if(ch[r][1])m[r]=min(m[r],m[ch[r][1]]);
}
void Push_Down(int r)
{
    if(rev[r])
    {
        Update_Rev(ch[r][0]);
        Update_Rev(ch[r][1]);
        rev[r]=0;
    }
    if(add[r])
    {
        Update_Add(ch[r][0],add[r]);
        Update_Add(ch[r][1],add[r]);
        add[r]=0;
    }
}
void Build(int &x,int l,int r,int father)
{
    if(l>r)return;
    int mid=(l+r)/2;
    NewNode(x,father,a[mid]);
    Build(ch[x][0],l,mid-1,x);
    Build(ch[x][1],mid+1,r,x);
    Push_Up(x);
}
void Init()
{
    root=tot1=tot2=0;
    ch[root][0]=ch[root][1]=size[root]=add[root]=rev[root]=pre[root]=0;
    m[root]=INF;//这个不用也可以，如果在push_up那判断了的话，否则需要
    NewNode(root,0,INF);
    NewNode(ch[root][1],root,INF);
    Build(Key_value,1,n,ch[root][1]);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
//旋转
void Rotate(int x,int kind)
{
    int y=pre[x];
    Push_Down(y);
    Push_Down(x);
    ch[y][!kind]=ch[x][kind];
    pre[ch[x][kind]]=y;
    if(pre[y])
        ch[pre[y]][ch[pre[y]][1]==y]=x;
    pre[x]=pre[y];
    ch[x][kind]=y;
    pre[y]=x;
    Push_Up(y);
}
//Splay调整
void Splay(int r,int goal)
{
    Push_Down(r);
    while(pre[r]!=goal)
    {
        if(pre[pre[r]]==goal)
        {
            //这题有反转操作，需要先push_down,在判断左右孩子
            Push_Down(pre[r]);
            Push_Down(r);
            Rotate(r,ch[pre[r]][0]==r);
        }

        else
        {
            //这题有反转操作，需要先push_down,在判断左右孩子
            Push_Down(pre[pre[r]]);
            Push_Down(pre[r]);
            Push_Down(r);
            int y=pre[r];
            int kind=(ch[pre[y]][0]==y);
            //两个方向不同，则先左旋再右旋
            if(ch[y][kind]==r)
            {
                Rotate(r,!kind);
                Rotate(r,kind);
            }
            //两个方向相同，相同方向连续两次
            else
            {
                Rotate(y,kind);
                Rotate(r,kind);
            }
        }
    }
    Push_Up(r);
    if(goal==0)root=r;
}
int Get_Kth(int r,int k)
{
    Push_Down(r);
    int t=size[ch[r][0]]+1;
    if(t==k)return r;
    if(t>k)return Get_Kth(ch[r][0],k);
    else return Get_Kth(ch[r][1],k-t);
}
int Get_Min(int r)
{
    Push_Down(r);
    while(ch[r][0])
    {
        r=ch[r][0];
        Push_Down(r);
    }
    return r;
}
int Get_Max(int r)
{
    Push_Down(r);
    while(ch[r][1])
    {
        r=ch[r][1];
        Push_Down(r);
    }
    return r;
}
//下面是操作了
void ADD(int l,int r,int D)
{
    Splay(Get_Kth(root,l),0);
    Splay(Get_Kth(root,r+2),root);
    Update_Add(Key_value,D);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
void Reverse(int l,int r)
{
    Splay(Get_Kth(root,l),0);
    Splay(Get_Kth(root,r+2),root);
    Update_Rev(Key_value);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
void Revolve(int l,int r,int T)//循环右移
{
    int len=r-l+1;
    T=(T%len+len)%len;
    if(T==0)return;
    int c=r-T+1;//将区间[c,r]放在[l,c-1]前面
    Splay(Get_Kth(root,c),0);
    Splay(Get_Kth(root,r+2),root);
    int tmp=Key_value;
    Key_value=0;
    Push_Up(ch[root][1]);
    Push_Up(root);
    Splay(Get_Kth(root,l),0);
    Splay(Get_Kth(root,l+1),root);
    Key_value=tmp;
    pre[Key_value]=ch[root][1];//这个不用忘记
    Push_Up(ch[root][1]);
    Push_Up(root);
}
void Insert(int x,int P)//在第x个数后面插入P
{
    Splay(Get_Kth(root,x+1),0);
    Splay(Get_Kth(root,x+2),root);
    NewNode(Key_value,ch[root][1],P);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
void erase(int r)//回收内存
{
    if(r)
    {
        s[++tot2]=r;
        erase(ch[r][0]);
        erase(ch[r][1]);
    }
}
void Delete(int x)//删除第x个数
{
    Splay(Get_Kth(root,x),0);
    Splay(Get_Kth(root,x+2),root);
    erase(Key_value);
    pre[Key_value]=0;
    Key_value=0;
    Push_Up(ch[root][1]);
    Push_Up(root);
}
int Query_Min(int l,int r)
{
    Splay(Get_Kth(root,l),0);
    Splay(Get_Kth(root,r+2),root);
    return m[Key_value];
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char op[20];
    int x,y,z;
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        Init();
        scanf("%d",&q);
        while(q--)
        {
            scanf("%s",op);
            if(strcmp(op,"ADD")==0)
            {
                scanf("%d%d%d",&x,&y,&z);
                ADD(x,y,z);
            }
            else if(strcmp(op,"REVERSE")==0)
            {
                scanf("%d%d",&x,&y);
                Reverse(x,y);
            }
            else if(strcmp(op,"REVOLVE")==0)
            {
                scanf("%d%d%d",&x,&y,&z);
                Revolve(x,y,z);
            }
            else if(strcmp(op,"INSERT")==0)
            {
                scanf("%d%d",&x,&y);
                Insert(x,y);
            }
            else if(strcmp(op,"DELETE")==0)
            {
                scanf("%d",&x);
                Delete(x);
            }
            else
            {
                scanf("%d%d",&x,&y);
                printf("%d\n",Query_Min(x,y));
            }
        }
    }
    return 0;
}
