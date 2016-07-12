
/*
POJ 1739
不增加行。
起点和终点特殊处理

G++ 47ms
*/
#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
const int MAXD=15;
const int HASH=10007;
const int STATE=1000010;

int N,M;
int maze[MAXD][MAXD];
int code[MAXD];
int ch[MAXD];//最小表示法使用
int ex,ey;//最后一个非障碍格子的坐标

struct HASHMAP
{
    int head[HASH],next[STATE],size;
    long long state[STATE],f[STATE];
    void init()
    {
        size=0;
        memset(head,-1,sizeof(head));
    }
    void push(long long st,long long ans)
    {
        int i;
        int h=st%HASH;
        for(i=head[h];i!=-1;i=next[i])
          if(state[i]==st)
          {
              f[i]+=ans;
              return;
          }
        state[size]=st;
        f[size]=ans;
        next[size]=head[h];
        head[h]=size++;
    }
}hm[2];

void decode(int *code,int m,long long st)
{
    for(int i=m;i>=0;i--)
    {
        code[i]=st&7;
        st>>=3;
    }
}
long long encode(int *code,int m)
{
    int cnt=1;
    memset(ch,-1,sizeof(ch));
    ch[0]=0;
    long long st=0;
    for(int i=0;i<=m;i++)
    {
        if(ch[code[i]]==-1)ch[code[i]]=cnt++;
        code[i]=ch[code[i]];
        st<<=3;
        st|=code[i];
    }
    return st;
}

void shift(int *code,int m)
{
    for(int i=m;i>0;i--)code[i]=code[i-1];
    code[0]=0;
}

void dpblank(int i,int j,int cur)
{
    int k,left,up;
    prln("******************************");
    pr(i);prln(j);
     bool ok = false;
    if(i==2&&j==3) ok = true;
    for(k=0;k<hm[cur].size;k++)
    {
        ll s = hm[cur].state[k];
        ll t = hm[cur].f[k];
        pr(s);prln(t);
        decode(code,M,hm[cur].state[k]);
        left=code[j-1];
        up=code[j];

        if((i==N&&j==1)||(i==N&&j==M))//起点和终点
        {
            if((left&&(!up))||((!left)&&up))
            {
                code[j]=code[j-1]=0;
                if(j==M)shift(code,M);
                if(ok) {
                    pr("1");prln(encode(code,M));

                }
                hm[cur^1].push(encode(code,M),hm[cur].f[k]);
            }
            else if(left==0&&up==0)
            {
                if(maze[i][j+1])
                {
                   code[j-1]=0;
                   code[j]=13;
                   if(ok) {
                        pr("2");prln(encode(code,M));
                   }
                   hm[cur^1].push(encode(code,M),hm[cur].f[k]);
                }
                if(maze[i+1][j])
                {
                   code[j-1]=13;
                   code[j]=0;
                   if(j==M)shift(code,M);
                   if(ok) {
                        pr("3");prln(encode(code,M));
                   }
                   hm[cur^1].push(encode(code,M),hm[cur].f[k]);
                }
            }
            continue;
        }
        if(left&&up)
        {
            if(left==up)
            {//这种情况不能发生
               /* if(i==ex&&j==ey)//只能出现在最后一个非障碍格子
                {
                    code[j]=code[j-1]=0;
                    if(j==M)shift(code,M);
                    hm[cur^1].push(encode(code,M),hm[cur].f[k]);
                }*/
            }
            else //不在同一个连通分量则合并
            {
                code[j-1]=code[j]=0;
                for(int t=0;t<=M;t++)
                  if(code[t]==left)
                    code[t]=up;
                if(j==M)shift(code,M);
                if(ok) {
                        pr("4");prln(encode(code,M));
                }
                hm[cur^1].push(encode(code,M),hm[cur].f[k]);
            }
        }
        else if((left&&(!up))||((!left)&&up))
        {
            int t;
            if(left)t=left;
            else t=up;
            if(maze[i][j+1])
            {
                code[j-1]=0;
                code[j]=t;
                if(ok) {
                        pr("5");prln(encode(code,M));
                }
                hm[cur^1].push(encode(code,M),hm[cur].f[k]);
            }
            if(maze[i+1][j])
            {
                code[j-1]=t;
                code[j]=0;
                if(j==M)shift(code,M);
                if(ok) {
                        pr("6");prln(encode(code,M));
                }
                hm[cur^1].push(encode(code,M),hm[cur].f[k]);
            }
        }
        else
        {
            if(maze[i][j+1]&&maze[i+1][j])
            {
                code[j-1]=code[j]=13;
                if(ok) {
                        pr("7");prln(encode(code,M));
                }
                hm[cur^1].push(encode(code,M),hm[cur].f[k]);
            }
        }
    }
}
void dpblock(int i,int j,int cur)
{
    int k;
    for(k=0;k<hm[cur].size;k++)
    {
        decode(code,M,hm[cur].state[k]);
        code[j-1]=code[j]=0;
        if(j==M)shift(code,M);
        hm[cur^1].push(encode(code,M),hm[cur].f[k]);
    }
}
char str[20];
void init()
{
    memset(maze,0,sizeof(maze));
    for(int i=1;i<=N;i++)
    {
        scanf("%s",&str);
        for(int j=0;j<M;j++)
          if(str[j]=='.')
          {
              maze[i][j+1]=1;
          }
    }
}
void solve()
{
    int i,j,cur=0;
    hm[cur].init();
    hm[cur].push(0,1);
    for(i=1;i<=N;i++)
      for(j=1;j<=M;j++)
      {
          hm[cur^1].init();
          if(maze[i][j])dpblank(i,j,cur);
          else dpblock(i,j,cur);
          cur^=1;
      }
    long long ans=0;
    for(int i=0;i<hm[cur].size;i++)
      ans+=hm[cur].f[i];
    printf("%I64d\n",ans);
}
int main()
{
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  freopen("C:\\Users\\zero\\Desktop\\out1.txt","w",stdout);
 #endif
    while(scanf("%d%d",&N,&M))
    {
        if(N==0&&M==0)break;
        init();
        solve();
    }
    return 0;
}
