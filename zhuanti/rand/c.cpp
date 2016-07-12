#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>

using namespace std;
const int maxn = 1e6+1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)      // cout << #x << " = " << x << " ";
#define prln(x)    // cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
const int HASH = 1e5+3;
int code[20];
int m, n;
struct HASHMAP
{
    int head[HASH+100],next[maxn],siz;
    long long state[maxn],f[maxn];
    void init()
    {
        siz=0;
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
        state[siz]=st;
        f[siz]=ans;
        next[siz]=head[h];
        head[h]=siz++;
    }
}hh[2];
void decode(long long st)
{
    for(int i=m;i>=0;i--)
    {
        code[i]=st&7;
        st>>=3;
    }
}
int ch[20];
long long encode()
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
void shift()
{
    for(int i=m;i>0;i--)code[i]=code[i-1];
    code[0]=0;
}
int maze[20][20];
char str[20];
/*
void dpblank(int i,int j,int cur)
{
    int k,left,up;
    for(k=0;k<hh[cur].siz;k++)
    {
        decode(hh[cur].state[k]);
        left=code[j-1];
        up=code[j];

        if((i==n&&j==1)||(i==n&&j==m))//起点和终点
        {
            if((left&&(!up))||((!left)&&up))
            {
                code[j]=code[j-1]=0;
                if(j==m)shift();
                hh[cur^1].push(encode(code),hh[cur].f[k]);
            }
            else if(left==0&&up==0)
            {
                if(maze[i][j+1])
                {
                   code[j-1]=0;
                   code[j]=13;
                   hh[cur^1].push(encode(code),hh[cur].f[k]);
                }
                if(maze[i+1][j])
                {
                   code[j-1]=13;
                   code[j]=0;
                   if(j==m)shift();
                   hh[cur^1].push(encode(code),hh[cur].f[k]);
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
                }
            }
            else //不在同一个连通分量则合并
            {
                code[j-1]=code[j]=0;
                for(int t=0;t<=m;t++)
                  if(code[t]==left)
                    code[t]=up;
                if(j==m)shift();
                hh[cur^1].push(encode(code),hh[cur].f[k]);
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
                hh[cur^1].push(encode(code),hh[cur].f[k]);
            }
            if(maze[i+1][j])
            {
                code[j-1]=t;
                code[j]=0;
                if(j==m)shift();
                hh[cur^1].push(encode(code),hh[cur].f[k]);
            }
        }
        else
        {
            if(maze[i][j+1]&&maze[i+1][j])
            {
                code[j-1]=code[j]=13;
                hh[cur^1].push(encode(code),hh[cur].f[k]);
            }
        }
    }
}*/

void dpblack( int x, int y, int now){
    int pre = now^1;
    hh[now].init();
    memset(code, 0, sizeof code);
    prln("******************************");
    pr(x);prln(y);
    bool ok = false;
    if(x==2&&y==3) ok = true;
    for(int i = 0; i < hh[pre].siz; ++i){
        ll s = hh[pre].state[i];
        ll t = hh[pre].f[i];
        pr(s);prln(t);
        memset(code, 0, sizeof code);
        decode(s);
        int left = code[y-1];
        int up = code[y];
        if((x==n&&y==1)||(x==n&&y==m)){
            if((left&&(!up))||((!left)&&up)) {
                code[y] = code[y-1] = 0;
                if(y==m) shift();
                if(ok) prln(encode());
                hh[now].push(encode(), t);
            }else if(left==0&&up==0){
                if(maze[x][y+1]){
                    code[y-1] = 0;
                    code[y] = 13;
                    if(ok) prln(encode());
                    hh[now].push(encode(), t);
                }
                if(maze[x+1][y]){
                    code[y-1] = 13;
                    code[y] = 0;
                    if(y==m) shift();
                    if(ok) prln(encode());
                    hh[now].push(encode(), t);
                }
            }
            continue;
        }
        if(left && up) {
            if(left == up) {

            }
            else{
                code[y-1] = code[y] = 0;
                for(int c = 0; c <= m; ++c) if(code[c] == left) code[c] = up;
                if(y==m) shift();
                if(ok) prln(encode());
                hh[now].push(encode(), t);
            }
        }else if((left&&(!up))||((!left)&&up)){
            int cx;
            if(left)cx=left;
            else cx=up;
                if(maze[x][y+1]) {
                    code[y-1] = 0;
                    code[y] = cx;
                    if(ok) prln(encode());
                    hh[now].push(encode(), t);
                }
                if(maze[x+1][y]){
                    code[y-1] = cx;
                    code[y] = 0;
                    if(y==m) shift();
                    if(ok) prln(encode());
                    hh[now].push(encode(), t);
                }
            }else{
                if(maze[x+1][y]&& maze[x][y+1]) {
                    code[y] = code[y-1] = 13;
                    if(ok) prln(encode());
                    hh[now].push(encode(), t);
                }
            }
    }
}

void dpblock( int i, int j, int now) {
    int k;
    int cur = now^1;
    for(k=0;k<hh[cur].siz;k++)
    {
        decode(hh[cur].state[k]);
        code[j-1]=code[j]=0;
        if(j==m)shift();
        hh[cur^1].push(encode(),hh[cur].f[k]);
    }
}
/*
void slove() {
    int now = 0, pre = 1;
    hh[now].init();
    memset(code, 0,sizeof code);
    hh[now].push(0, 1);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            now = now^1;
            hh[now].init();
            if(maze[i][j]) dpblack(now, i, j);
            else dpblock(now, i, j);
        }
    }
    ll  ans = 0;
    for(int i = 0; i < hh[now].siz; ++i){
        ans += hh[now].f[i];
    }
    printf("%I64d\n", ans);
}*/
void solve()
{
    int i,j,cur=0;
    hh[cur].init();
    hh[cur].push(0,1);
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
      {
          cur^=1;
          hh[cur].init();
          if(maze[i][j])dpblack(i,j,cur);
          else dpblock(i,j,cur);
      }
    long long ans=0;
    for(int i=0;i<hh[cur].siz;i++)
      ans+=hh[cur].f[i];
    printf("%I64d\n",ans);
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    while(scanf("%d%d", &n, &m) ){
        if(n==0&&m==0) break;
        memset(maze,0,sizeof maze);
        //pr(n);prln(m);
        for(int i = 0; i< n; ++i){
            scanf("%s", str);
            for(int j = 0; j < m; ++j){
                if(str[j] == '.') maze[i+1][j+1] = 1;
            }
        }

        solve();
    }
    return 0;
}
