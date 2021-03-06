* * *


[TOC]

* * *


### 数位dp
#### 模板
``` cpp
//    pos    = 当前处理的位置(一般从高位到低位)
//    pre    = 上一个位的数字(更高的那一位)
//    status = 要达到的状态,如果为1则可以认为找到了答案,到时候用来返回,
//         　　 给计数器+1。
//    limit  = 是否受限,也即当前处理这位能否随便取值。如567,当前处理6这位,
//         　　 如果前面取的是4,则当前这位可以取0-9。如果前面取的5,那么当前
//         　　 这位就不能随便取，不然会超出这个数的范围,所以如果前面取5的
//         　　 话此时的limit=1,也就是说当前只可以取0-6。
//
//    用DP数组保存这三个状态是因为往后转移的时候会遇到很多重复的情况。
int    dfs(int pos,int pre,int status,int limit)
{
    //已结搜到尽头,返回"是否找到了答案"这个状态。
    if(pos < 1)
        return    status;

    //DP里保存的是完整的,也即不受限的答案,所以如果满足的话,可以直接返回。
    if(!limit && DP[pos][pre][status] != -1)
        return    DP[pos][pre][status];

    int    end = limit ? DIG[pos] : 9;
    int    ret = 0;
    
    //往下搜的状态表示的很巧妙,status用||是因为如果前面找到了答案那么后面
    //还有没有答案都无所谓了。而limti用&&是因为只有前面受限、当前受限才能
    //推出下一步也受限，比如567,如果是46X的情况,虽然6已经到尽头,但是后面的
    //个位仍然可以随便取,因为百位没受限,所以如果个位要受限,那么前面必须是56。
    //
    //这里用"不要49"一题来做例子。
    for(int i = 0;i <= end;i ++)
        ret += dfs(pos - 1,i,status || (pre == 4 && i == 9),limit && (i == end));

    //DP里保存完整的、取到尽头的数据
    if(!limit)
        DP[pos][pre][status] = ret;

    return    ret;
}
```

####  HDU 5787 K-wolf Number（数位dp）
``` cpp
/*
- 求1≤L≤R≤1018范围内，每2≤K≤5个数字都不同的数字有多少

- f[i][pre][5]:=从高到低，填到第i位，且之前的数字是pre，pre已经有1∼4位数合法数字数
- 由于不能有前导0，所以开个first判一判，其他套个板子就好了
*/
const int N = 1e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
LL l, r, f[20][N][5];
int k;

const int ten[] = {1, 10, 100, 1000, 10000, 100000};
int get(int x, int i) {
    return x / ten[i] % 10;
}

int add(int x, int y) {
    return (x * 10 + y) % ten[k - 1];
}

int digit[20];

LL dfs(int i, int pre, int num, bool first, bool e) {
    if(!i) return 1;
    if(!e && ~f[i][pre][num]) return f[i][pre][num];
    LL ret = 0;
    int to = e ? digit[i] : 9;
    for(int d = 0; d <= to; ++d) {
        bool ok = true;
        for(int j = 0; j < min(k - 1, num) && ok; ++j)
            if(get(pre, j) == d) ok = false;
        if(!ok) continue;
        ret += dfs(i - 1, first && !d ? 0 : add(pre, d),
                   first && !d ? 0 : min(k - 1, num + 1),
                   first && !d, e && d == to);
    }
    return e ? ret : f[i][pre][num] = ret;
}

LL calc(LL x) {
    int cnt = 0;
    for(; x; x /= 10) digit[++cnt] = x % 10;
    return dfs(cnt, 0, 0, 1, 1);
}

bool judge(int x, int k) {
    int cnt = 0;
    for(; x; x /= 10) digit[++cnt] = x % 10;

    for(int i = 1; i <= cnt; ++i) {
        bool ok = true;
        for(int j = 1; j < k; ++j) {
            if(i - j >= 1 && digit[i] == digit[i - j]) {
                ok = false;
                break;
            }
        }
        if(!ok) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(0);

    while(scanf("%I64d%I64d%d", &l, &r, &k) == 3) {
        memset(f, -1, sizeof f);
        LL ans = calc(r) - calc(l - 1);
        printf("%I64d\n", ans);
    }

    return 0;
}
```

#### 二维bit优化dp
``` cpp
/*
cf355 (Div. 2) D. Vanya and Treasure（dp、二维BIT优化）
题意:N，M≤300，P≤N×M，给定一个N×M图，每个格子Aij是1∼P的数字
从(1, 1)出发，两个格子的距离定义为曼哈顿距离，按顺序取1∼P的数字
问最短路是多少

优化一：
令cnt[i]:=i这个数字的个数，当cnt[i−1]×cnt[i]≤n×m的时候直接更新，否则bfs一波
这个时间复杂度是O(nmnm−−−√)，如果有人懂详细证明请教我。。
优化二：
我们展开这个dp转移方程：
f[x2][y2]=min{ f[x1][y1]+abs(x1−x2)+abs(y1−y2) }
*/
const int N = 300 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, p;
int s[N][N], f[N][N];
typedef pair<int, int> P;
vector<P> G[N * N];

struct BIT {
    int n, b[N][N];
    int timStp, vis[N][N];
    void init(int _n) {
        n = _n;
        timStp = 1;
        memset(vis, 0, sizeof vis);
    }
    void newOne() {
        ++timStp;
    }
    void update(int x, int y, int v) {
        for(int i = x; i <= n; i += i & -i) {
            for(int j = y; j <= n; j += j & -j) {
                if(vis[i][j] != timStp) vis[i][j] = timStp, b[i][j] = INF;
                b[i][j] = min(b[i][j], v);
            }
        }
    }
    int query(int x, int y) {
        int ret = INF;
        for(int i = x; i; i -= i & -i)
            for(int j = y; j; j -= j & -j)
                if(vis[i][j] == timStp) ret = min(ret, b[i][j]);
        return ret;
    }
} bit[4];

int main() {

    ios_base::sync_with_stdio(0);

    scanf("%d%d%d", &n, &m, &p);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            scanf("%d", s[i] + j);
            G[s[i][j]].push_back({i, j});
        }
    }

    memset(f, 0x3f, sizeof f);
    int nm = max(n, m);
    for(int i = 0; i < 4; ++i) bit[i].init(nm);
    //UL - f[x2][y2] = min { f[x1][y1] - x1 - y1 + x2 + y2 }
    //UR - f[x2][y2] = min { f[x1][y1] + x1 - y1 - x2 + y2 }
    //BR - f[x2][y2] = min { f[x1][y1] + x1 + y1 - x2 - y2 }
    //BL - f[x2][y2] = min { f[x1][y1] - x1 + y1 + x2 - y2 }
    for(int i = 0; i < G[1].size(); ++i) {
        int x = G[1][i].first, y = G[1][i].second;
        f[x][y] = x + y - 2;
        bit[0].update(x, y, f[x][y] - x - y);
        bit[1].update(nm - x + 1, y, f[x][y] + x - y);
        bit[2].update(nm - x + 1, nm - y + 1, f[x][y] + x + y);
        bit[3].update(x, nm - y + 1, f[x][y] - x + y);
    }

    for(int i = 2; i <= p; ++i) {
        for(int j = 0; j < G[i].size(); ++j) {
            int x = G[i][j].first, y = G[i][j].second, val = INF;
            val = min(val, bit[0].query(x, y) + x + y);
            val = min(val, bit[1].query(nm - x + 1, y) - x + y);
            val = min(val, bit[2].query(nm - x + 1, nm - y + 1) - x - y);
            val = min(val, bit[3].query(x, nm - y + 1) + x - y);
            f[x][y] = val;
        }

        for(int j = 0; j < 4; ++j) bit[j].newOne();
        for(int j = 0; j < G[i].size(); ++j) {
            int x = G[i][j].first, y = G[i][j].second;
            bit[0].update(x, y, f[x][y] - x - y);
            bit[1].update(nm - x + 1, y, f[x][y] + x - y);
            bit[2].update(nm - x + 1, nm - y + 1, f[x][y] + x + y);
            bit[3].update(x, nm - y + 1, f[x][y] - x + y);
        }
    }

    int x = G[p][0].first, y = G[p][0].second;
    printf("%d\n", f[x][y]);

    return 0;
}
```


``` cpp


/*
ZOJ 3256
N*M(2<=N<=7,1<=M<=10^9)的方格，问从左上角的格子到左下角的格子，
而且仅经过所有格子一次的路径数
插头DP+矩阵加速

对于一个图的邻接矩阵的N次方，其中(i,j)位置上的元素表示
点i经过N步到达点ｊ的方案数
*/
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

const int STATE=1010;
const int HASH=419;//这个小一点，效率高
const int MOD=7777777;

int N,M;
int D;
int code[10];
int ch[10];
int g[200][200];//状态转移图

struct Matrix
{
    int n,m;
    int mat[200][200];
};
Matrix mul(Matrix a,Matrix b)//矩阵相乘，要保证a的列数和b的行数相等
{
    Matrix ret;
    ret.n=a.n;
    ret.m=b.m;
    long long sum;
    for(int i=0;i<a.n;i++)
       for(int j=0;j<b.m;j++)
       {
           sum=0;
           for(int k=0;k<a.m;k++)
           {
               sum+=(long long)a.mat[i][k]*b.mat[k][j];
               //sum%=MOD;//加了这句话就会TLE，坑啊。。。
           }
           ret.mat[i][j]=sum%MOD;
       }
    return ret;
}
Matrix pow_M(Matrix a,int n)//方阵的n次方
{
    Matrix ret=a;
    memset(ret.mat,0,sizeof(ret.mat));
    for(int i=0;i<a.n;i++)ret.mat[i][i]=1;//单位阵
    Matrix temp=a;
    while(n)
    {
        if(n&1)ret=mul(ret,temp);
        temp=mul(temp,temp);
        n>>=1;
    }
    return ret;
}

struct HASHMAP
{
    int head[HASH],next[STATE],size;
    int state[STATE];
    void init()
    {
        size=0;
        memset(head,-1,sizeof(head));
    }
    int push(int st)
    {
        int i,h=st%HASH;
        for(i=head[h];i!=-1;i=next[i])
           if(state[i]==st)
              return i;
        state[size]=st;
        next[size]=head[h];
        head[h]=size++;
        return size-1;
    }
}hm;
void decode(int *code,int n,int st)
{
    for(int i=n-1;i>=0;i--)
    {
        code[i]=st&3;
        st>>=2;
    }
}
int encode(int *code,int n)
{
    int cnt=1;
    memset(ch,-1,sizeof(ch));
    ch[0]=0;
    int st=0;
    for(int i=0;i<n;i++)
    {
        if(ch[code[i]]==-1)ch[code[i]]=cnt++;
        code[i]=ch[code[i]];
        st<<=2;
        st|=code[i];
    }
    return st;
}

bool check(int st,int nst)//判断两种状态能不能转移
{
    decode(code,N,st);
    int flag=0;//标记格子上边是否有插头
    int cnt=0;
    int k;
    for(int i=0;i<N;i++)
    {
        if(flag==0)//这个格子上边没有插头
        {
            if(code[i]==0&&(nst&(1<<i))==0)//左边和右边都没有插头
               return false;
            if(code[i]&&(nst&(1<<i)))continue;
            if(code[i])flag=code[i];//插头从左边过来，从下边出去
            else flag=-1;//插头从下边进来从右边出去
            k=i;
        }
        else
        {
            if(code[i]&&(nst&(1<<i)))//左边和右边和上边都有插头
               return false;
            if(code[i]==0&&(nst&(1<<i))==0)continue;
            if(code[i])
            {
                if(code[i]==flag&&((nst!=0)||i!=N-1))return false;//只有最后一个格子才能合起来
                if(flag>0)
                {
                    for(int j=0;j<N;j++)
                      if(code[j]==code[i]&&j!=i)
                          code[j]=code[k];
                    code[i]=code[k]=0;
                }
                else
                {
                    code[k]=code[i];
                    code[i]=0;
                }
            }
            else
            {
                if(flag>0)code[i]=code[k],code[k]=0;
                else code[i]=code[k]=N+(cnt++);
            }
            flag=0;
        }
    }
    if(flag!=0)return false;
    return true;
}
struct Node
{
    int g[200][200];
    int D;
}node[20];//打表之用
void init()
{
    if(node[N].D!=0)
    {
        memcpy(g,node[N].g,sizeof(node[N].g));
        D=node[N].D;
        return;
    }
    int st,nst;
    hm.init();
    memset(code,0,sizeof(code));
    code[0]=code[N-1]=1;
    hm.push(0);
    hm.push(encode(code,N));
    memset(g,0,sizeof(g));
    for(int i=1;i<hm.size;i++)
    {
        st=hm.state[i];
        for(nst=0;nst<(1<<N);nst++)
          if(check(st,nst))
          {
              int j=hm.push(encode(code,N));
              g[i][j]=1;
          }
    }
    D=hm.size;
    memcpy(node[N].g,g,sizeof(g));
    node[N].D=D;
}
void solve()
{
    Matrix temp;
    temp.n=temp.m=D;
    memcpy(temp.mat,g,sizeof(g));
    Matrix ans=pow_M(temp,M);
    if(ans.mat[1][0]==0)printf("Impossible\n");
    else printf("%d\n",ans.mat[1][0]%MOD);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    for(int i=0;i<20;i++)node[i].D=0;
    while(scanf("%d%d",&N,&M)==2)
    {
        init();
        solve();
    }
    return 0;
}
```


``` cpp
POJ 3133

/*
POJ 3133
连接2的插头为2，连接3的插头为3
没有插头为0
用四进制表示（四进制比三进制高效）

G++ 391ms
*/
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAXD=15;
const int HASH=10007;
const int STATE=1000010;
int N,M;
int maze[MAXD][MAXD];//0表示障碍，1是非障碍，2和3
int code[MAXD];
//0表示没有插头,2表示和插头2相连，3表示和插头3相连

struct HASHMAP
{
    int head[HASH],next[STATE],size;
    int state[STATE];
    int dp[STATE];
    void init()
    {
        size=0;
        memset(head,-1,sizeof(head));
    }
    void push(int st,int ans)
    {
        int i,h=st%HASH;
        for(i=head[h];i!=-1;i=next[i])
          if(state[i]==st)
          {
              if(dp[i]>ans)dp[i]=ans;
              return;
          }
        state[size]=st;
        dp[size]=ans;
        next[size]=head[h];
        head[h]=size++;
    }
}hm[2];
void decode(int *code,int m,int st)//四进制
{
    int i;
    for(int i=m;i>=0;i--)
    {
        code[i]=(st&3);
        st>>=2;
    }
}
int encode(int *code,int m)
{
    int i;
    int st=0;
    for(int i=0;i<=m;i++)
    {
        st<<=2;
        st|=code[i];
    }
    return st;
}
void shift(int *code,int m)//换行
{
    for(int i=m;i>0;i--)code[i]=code[i-1];
    code[0]=0;
}
void dpblank(int i,int j,int cur)
{
    int k,left,up;
    for(k=0;k<hm[cur].size;k++)
    {
        decode(code,M,hm[cur].state[k]);
        left=code[j-1];
        up=code[j];
        if(left&&up)
        {
            if(left==up)//只能是相同的插头
            {
                code[j-1]=code[j]=0;
                if(j==M)shift(code,M);
                hm[cur^1].push(encode(code,M),hm[cur].dp[k]+1);
            }
        }
        else if((left&&(!up))||((!left)&&up))//只有一个插头
        {
            int t;
            if(left)t=left;
            else t=up;//这里少写个else ,查了好久的错误
            if(maze[i][j+1]==1||maze[i][j+1]==t)//插头从右边出来
            {
                code[j-1]=0;
                code[j]=t;
                hm[cur^1].push(encode(code,M),hm[cur].dp[k]+1);
            }
            if(maze[i+1][j]==1||maze[i+1][j]==t)//插头从下边出来
            {
                code[j]=0;
                code[j-1]=t;
                if(j==M)shift(code,M);
                hm[cur^1].push(encode(code,M),hm[cur].dp[k]+1);
            }
        }
        else if(left==0&&up==0)//没有插头
        {
            code[j-1]=code[j]=0;//不加插头
            if(j==M)shift(code,M);
            hm[cur^1].push(encode(code,M),hm[cur].dp[k]);
            if(maze[i][j+1]&&maze[i+1][j])
            {
                if(maze[i][j+1]==1&&maze[i+1][j]==1)
                {
                    decode(code,M,hm[cur].state[k]);
                    code[j-1]=code[j]=2;//加2号插头
                    hm[cur^1].push(encode(code,M),hm[cur].dp[k]+1);
                    //decode(code,M,hm[cur].state[k]);
                    code[j-1]=code[j]=3;//加3号插头
                    hm[cur^1].push(encode(code,M),hm[cur].dp[k]+1);
                }
                else if((maze[i][j+1]==2&&maze[i+1][j]==1)||(maze[i+1][j]==2&&maze[i][j+1]==1)||(maze[i][j+1]==2&&maze[i+1][j]==2))
                {
                    decode(code,M,hm[cur].state[k]);
                    code[j-1]=code[j]=2;
                    hm[cur^1].push(encode(code,M),hm[cur].dp[k]+1);
                }
                else if((maze[i][j+1]==3&&maze[i+1][j]==1)||(maze[i+1][j]==3&&maze[i][j+1]==1)||(maze[i][j+1]==3&&maze[i+1][j]==3))
                {
                    decode(code,M,hm[cur].state[k]);
                    code[j-1]=code[j]=3;
                    hm[cur^1].push(encode(code,M),hm[cur].dp[k]+1);
                }
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
        if(code[j-1]!=0||code[j]!=0)continue;
        code[j-1]=code[j]=0;//不加插头
        if(j==M)shift(code,M);
        hm[cur^1].push(encode(code,M),hm[cur].dp[k]);
    }
}
void dp_2(int i,int j,int cur)
{
    int left,up,k;
    for(k=0;k<hm[cur].size;k++)
    {
        decode(code,M,hm[cur].state[k]);
        left=code[j-1];
        up=code[j];
        if((left==2&&up==0)||(left==0&&up==2))
        {
            code[j-1]=code[j]=0;
            if(j==M)shift(code,M);
            hm[cur^1].push(encode(code,M),hm[cur].dp[k]+1);
        }
        else if(left==0&&up==0)
        {
            if(maze[i][j+1]==1||maze[i][j+1]==2)
            {
                code[j-1]=0;
                code[j]=2;
                hm[cur^1].push(encode(code,M),hm[cur].dp[k]+1);
            }
            if(maze[i+1][j]==1||maze[i+1][j]==2)
            {
                code[j-1]=2;
                code[j]=0;
                if(j==M)shift(code,M);
                hm[cur^1].push(encode(code,M),hm[cur].dp[k]+1);
            }
        }
    }
}
void dp_3(int i,int j,int cur)
{
    int left,up,k;
    for(k=0;k<hm[cur].size;k++)
    {
        decode(code,M,hm[cur].state[k]);
        left=code[j-1];
        up=code[j];
        if((left==3&&up==0)||(left==0&&up==3))
        {
            code[j-1]=code[j]=0;
            if(j==M)shift(code,M);
            hm[cur^1].push(encode(code,M),hm[cur].dp[k]+1);
        }
        else if(left==0&&up==0)
        {
            if(maze[i][j+1]==1||maze[i][j+1]==3)
            {
                code[j-1]=0;
                code[j]=3;
                hm[cur^1].push(encode(code,M),hm[cur].dp[k]+1);
            }
            if(maze[i+1][j]==1||maze[i+1][j]==3)
            {
                code[j-1]=3;
                code[j]=0;
                if(j==M)shift(code,M);
                hm[cur^1].push(encode(code,M),hm[cur].dp[k]+1);
            }
        }
    }
}

void init()
{
    memset(maze,0,sizeof(maze));
    for(int i=1;i<=N;i++)
      for(int j=1;j<=M;j++)
      {
          scanf("%d",&maze[i][j]);
          //if(maze[i][j]==0)maze[i][j]=1;
          //if(maze[i][j]==1)maze[i][j]=0;
          //上面的写法是错的，！！！
          if(maze[i][j]==1||maze[i][j]==0)maze[i][j]^=1;//0变1，1变0
      }
}
void solve()
{
    int i,j,cur=0;
    hm[cur].init();
    hm[cur].push(0,0);
    for(int i=1;i<=N;i++)
      for(int j=1;j<=M;j++)
      {
          hm[cur^1].init();
          if(maze[i][j]==0)dpblock(i,j,cur);
          else if(maze[i][j]==1)dpblank(i,j,cur);
          else if(maze[i][j]==2)dp_2(i,j,cur);
          else if(maze[i][j]==3)dp_3(i,j,cur);
          cur^=1;
      }
    int ans=0;
    for(int i=0;i<hm[cur].size;i++)
      ans+=hm[cur].dp[i];
    if(ans>0)ans-=2;
    printf("%d\n",ans);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d%d",&N,&M))
    {
        if(N==0&&M==0)break;
        init();
        solve();
    }
    return 0;
}
```

## 数据结构
### 后缀数组
$$$ 找到出现k次可重叠最长子串 $$$
``` cpp
const int maxn = 2e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int rk[maxn], sa[maxn], height[maxn], w[maxn], wa[maxn], res[maxn];
void getSa(int len, int up){
	int *k = rk,*id = height, *r = res,*cnt=wa;
	rep(i,up) cnt[i] = 0;
	rep(i,len) cnt[k[i]=w[i]]++;
	rep(i,up) cnt[i+1] += cnt[i];
	for(int i = len-1; i >=0; --i){
		sa[--cnt[k[i]]] = i; 
	}
	int d = 1, p = 0;
	while(p < len) {
		for(int i = len-d; i < len;++i) id[p++] = i;
		rep(i,len) if(sa[i] >= d) id[p++] = sa[i]-d;
		rep(i,len) r[i] = k[id[i]];
		rep(i,up) cnt[i] = 0;
		rep(i,len) cnt[r[i]]++;
		rep(i,up) cnt[i+1] += cnt[i];
		for(int i = len-1; i >= 0; --i) {
			sa[--cnt[r[i]]] = id[i];
		}
		swap(k,r);
		p = 0;
		k[sa[0]] = p++;
		rep(i,len-1) {
			if(sa[i]+d < len && sa[i+1]+d <len &&r[sa[i]]==r[sa[i+1]]&&r[sa[i]+d]==r[sa[i+1]+d])
				k[sa[i+1]] = p-1;
			else	k[sa[i+1]] = p++;
		}
		if(p >= len) return;
		d*=2; up = p; p = 0;
	}
}
void getHeight(int len) {
	rep(i,len) rk[sa[i]] = i;
	height[0] = 0;
	for(int i = 0,p=0; i < len-1; ++i) {
		int j = sa[rk[i]-1];
		while(i+p<len&&j+p<len&&w[i+p]==w[j+p]) p++;
		height[rk[i]] = p;
		p = max(p-1,0);
	}
}
int getSuffix(int s[],int len) {
	int  up = 0;
	for(int i = 0; i < len; ++i) {
		w[i] = s[i];
		up = max(up,w[i]);
	}
	w[len++] = 0;
	getSa(len,up+1);
	getHeight(len);
	return len;
}
int n, k;
bool ok(int len) {
	int i = 2, 	cnt;
	while(true) {
		while(i <= n && height[i] < len) ++i;
		if(i > n) return false;
		cnt = 1;
		while(i <= n && height[i] >= len) {
			++i;
			cnt++;
		}
		if(cnt >= k) return true;
	}
	return false;
}
int num[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif

    cin >> n >> k;
    rep(i,n) scanf("%d",&num[i]);
    getSuffix(num,n);
    int l = 0, r= n, mid;
    while(l < r) {
    	mid = (l+r+1)/2;
    	if(ok(mid)) l = mid;
    	else r = mid-1;
    }
    printf("%d\n",l);
    return 0;
}
```
### AC自动机 
#### 在线AC自动机
``` cpp
/*
Educational Codeforces Round 16
给定N≤3×105次操作，操作一个字符串集合
1 s:向集合添加字符串s
2 s:从集合删除字符串s
3 s:查询字符串s在集合的所有字符串中出现了多少次
保证添加和删除操作合法，且∑|S|≤3×105
*/
const int N = 3e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

struct ACAutomata {
    static const int S = 26;
    int sz, root;
    vector<vector<int> > nxt;
    vector<int> fail, cnt;

    inline int idx(char c) {return c - 'a';}
    inline int newNode() {
        cnt.push_back(0);
        nxt.push_back(vector<int>(S, 0));
        return sz++;
    }
    void init() {
        sz = 0;
        nxt.clear();
        cnt.clear();
        fail.clear();
        root = newNode();
    }
    void insert(const char* s, int d) {
        int u = root;
        for(; *s; ++s) {
            int c = idx(*s);
            int& v = nxt[u][c];
            if(!v) v = newNode();
            u = v;
        }
        cnt[u] += d;
    }
    void build() {
        vector<int> q;
        fail.resize(nxt.size());
        fail[root] = root;
        for(int i = 0; i < S; ++i) {
            int& v = nxt[root][i];
            if(v) {
                fail[v] = root;
                q.push_back(v);
            } else v = root;
        }
        for(int k = 0; k < q.size(); ++k) {
            int u = q[k];
            for(int i = 0; i < S; ++i) {
                int& v = nxt[u][i];
                if(v) {
                    fail[v] = nxt[fail[u]][i];
                    cnt[v] += cnt[nxt[fail[u]][i]];
                    q.push_back(v);
                } else v = nxt[fail[u]][i];
            }
        }
    }
    LL query(const char* s) {
        LL ret = 0;
        int u = root;
        for(; *s; ++s) {
            int c = idx(*s);
            u = nxt[u][c];
            ret += cnt[u];
        }
        return ret;
    }
};

int q, op[N];
string s[N];

struct StaticToDynamic {
    static const int LOG = 20;
    ACAutomata ac[LOG];
    vector<int> g[LOG];

    void init() {
        for(int i = 0; i < LOG; ++i) {
            g[i].clear();
            ac[i].init();
        }
    }
    inline get(int x) {
        return x == 1 ? 1 : -1;
    }
    void add(int id) {
        int p = -1;
        for(int i = 0; i < LOG && !~p; ++i) if(g[i].empty()) p = i;
        g[p].push_back(id);
        ac[p].insert(s[id].c_str(), get(op[id]));

        for(int i = 0; i < p; ++i) {
            for(int id : g[i]) {
                g[p].push_back(id);
                ac[p].insert(s[id].c_str(), get(op[id]));
            }
            g[i].clear();
            ac[i].init();
        }
        ac[p].build();
    }
    LL query(int id) {
        LL ret = 0;
        for(int i = 0; i < LOG; ++i) ret += ac[i].query(s[id].c_str());
        return ret;
    }
} solver;

int main() {


    ios_base::sync_with_stdio(0);

    while(cin >> q) {
        solver.init();
        for(int i = 1; i <= q; ++i) {
            cin >> op[i] >> s[i];
            if(op[i] <= 2) {
                solver.add(i);
            } else {
                cout << solver.query(i) << endl;
            }
        }
    }

    return 0;
}
```

### 回文树
``` cpp
/*************************************************************************
hdu5785
给定N≤106的字符串，现在寻找所有三元组(i, j, k)，1≤i≤j<k≤N
使得s[i…j]和s[j+1…k]都是回文串，求∑∑i×k mod 109+7
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 1e6+100;
const int INF = 0x3f3f3f3f;
const int N = 27;
typedef pair<int,int> P;
const int MOD = 1e9+7;
struct Pstree{
    int nxt[maxn][26];
    int fail[maxn];
    int num[maxn];
    int len[maxn];
    int ans[maxn];
    char s[maxn];
    int last, n, p;
    int newnode(int x){
        for(int i = 0; i < N; ++i){
            nxt[p][i] = 0;
        }
        len[p] = x;
        num[p] = 0;
        ans[p] = 0;
        return p++;
    }
    void init(){
        p = 0;
        n = 0;
        last = 0;
        newnode(0);
        newnode(-1);
        s[n] = 255; 
        fail[0] = 1;
    }
    int getfail(int x){
        while(s[n-len[x]-1] != s[n]) x = fail[x];
        return x;
    }
    P add(int c){
        c -= 'a';
        s[++n] = c;
        int cur =  getfail(last);
        if(!nxt[cur][c]){
            int now = newnode(len[cur]+2);
            fail[now] = nxt[getfail(fail[cur])][c];
            nxt[cur][c] = now;
            num[now] =  num[fail[now]] + 1;
            ans[now] = ans[fail[now]] + len[cur]+2;
            ans[now] %= MOD;
        }
        last = nxt[cur][c];
        return P(num[last], ans[last]);
    }
}pstree;
char s[maxn];
int lnum[maxn];
int lans[maxn];
int main(){
    int n;
    while(scanf("%s", s) != EOF){
        n = strlen(s);
        pstree.init();
        for(int i = 0; i < n; ++i){
            P ans = pstree.add(s[i]);
            lnum[i+1] = ans.first;
            lans[i+1] = ans.second;
        }
        pstree.init();
        ll cnt = 0;
        for(int i = n-1; i > 0; --i){
            P ans = pstree.add(s[i]);
            cnt += ((ll)(i+1)*lnum[i] - (ll)lans[i])%MOD*((ll)((ll)i*ans.first%MOD) + ans.second)%MOD;
            cnt %= MOD;


        }
        cnt = (cnt%MOD+MOD)%MOD;
        printf("%lld\n", cnt);
    }
	return 0;
}
```



- N≤103的字符串，Q≤105次询问

- 每次询问[l, r]区间本质不同的回文子串有几个，即不完全相同的回文子串

``` cpp
/*hdu5658*/
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// last:= 指向添加一个字符后形成的最长回文串的节点
// s[i]:= 第 i 次添加的字符 n:= s 数组时针
// fail[i]:= i 失配后跳转到的 i 表示的最长回文串的最长真后缀回文串的节点
// cnt[i]:= 以 i 表示的最长回文串的右端点为右端点的回文串个数
// dif[i]:= i 表示的本质不同的回文串个数 （需要重新统计）
struct PalindromicTree {
    static const int M = 1e3 + 10, S = 26;
    int n, sz, last;
    int nxt[M][S], fail[M], len[M], s[M];
    int cnt[M], dif[M];

    int newNode(int l) {
        len[sz] = l;
        cnt[sz] = dif[sz] = 0;
        memset(nxt[sz], 0, sizeof nxt[sz]);
        return sz++;
    }

    void init() {
        sz = last = 0;
        newNode(0); newNode(-1);
        s[n = 0] = -1; // 无关字符减少特判
        fail[0] = 1;
    }

    int getFail(int u) {
        while(s[n - len[u] - 1] != s[n]) u = fail[u];
        return u;
    }

    void add(int c) {
        s[++n] = c;
        int u = getFail(last); // 找到这个回文串的匹配位置
        int& v = nxt[u][c];
        if(!v) {
            int cur = newNode(len[u] + 2);
            fail[cur] = nxt[getFail(fail[u])][c];
            v = cur;
            cnt[v] = cnt[fail[v]] + 1;
        }
        ++dif[v];
        last = v;
    }

    void count() {
        //父亲累加儿子，如果 fail[v]=u ，则 u 一定是 v 的子回文串
        for(int i = sz - 1; ~i; --i) dif[fail[i]] += dif[i];
    }
} pt;

int n, q;
char a[N];
int ans[N][N];

int main() {

    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%s", a + 1);
        n = strlen(a + 1);

        for(int i = 1; i <= n; ++i) {
            pt.init();
            for(int j = i; j <= n; ++j) {
                pt.add(a[j] - 'a');
                ans[i][j] = pt.sz - 2;
            }
        }

        scanf("%d", &q);
        while(q--) {
            int l, r; scanf("%d%d", &l, &r);
            printf("%d\n", ans[l][r]);
        }
    }
    return 0;
}
```


### 主席树
#### 标记永久化
- 给定N≤105个数，Q≤105询问,简而言之就是对某个版本进行区间更新区间查询
``` cpp
onst int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q;

typedef long long LL;

int root[N];
struct PersistentSegTree {
    static const int M = 1e5 * 30;
    int sz;
    struct Node {
        int ls, rs, add;
        LL sum;
    } tree[M];
    void init() {
        sz = 0;
        memset(&tree[0], 0, sizeof tree[0]);
    }
    int newNode(int rt) {
        tree[++sz] = tree[rt];
        return sz;
    }
    void up(int rt) {
        tree[rt].sum = tree[tree[rt].ls].sum + tree[tree[rt].rs].sum;
    }
    void build(int l, int r, int& rt) {
        rt = newNode(0);
        if(l == r) {
            scanf("%I64d", &tree[rt].sum);
            return;
        }
        int m = l + r >> 1;
        build(l, m, tree[rt].ls);
        build(m + 1, r, tree[rt].rs);
        up(rt);
    }
    void show(int l, int r, int rt) {
        pr("show"); pr(rt); pr(l); pr(r); pr(tree[rt].add); prln(tree[rt].sum);
        if(l == r) return ;
        int m = l + r >> 1;
        show(l, m, tree[rt].ls);
        show(m + 1, r, tree[rt].rs);
    }
    void update(int L, int R, int v, int l, int r, int& rt) {
        rt = newNode(rt);
        tree[rt].sum += v * (min(r, R) - max(l, L) + 1);
        if(L <= l && r <= R) {
            tree[rt].add += v;
            return;
        }
        int m = l + r >> 1;
        if(L <= m) update(L, R, v, l, m, tree[rt].ls);
        if(R > m) update(L, R, v, m + 1, r, tree[rt].rs);
    }
    LL query(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R) return tree[rt].sum;
        LL ret = 1LL * tree[rt].add * (min(r, R) - max(l, L) + 1);
        int m = l + r >> 1;
        if(L <= m) ret += query(L, R, l, m, tree[rt].ls);
        if(R > m) ret += query(L, R, m + 1, r, tree[rt].rs);
        return ret;
    }
} T;

int main() {

    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) == 2) {
        T.init();
        T.build(1, n, root[0]);

        int timStp = 0;
        while(q--) {
            char op[2]; scanf("%s", op);
            if(*op == 'C') {
                int l, r, d; scanf("%d%d%d", &l, &r, &d);
                ++timStp;
                root[timStp] = root[timStp - 1];
//                T.show(1, n, root[timStp]);
                T.update(l, r, d, 1, n, root[timStp]);
            } else if(*op == 'Q') {
                int l, r; scanf("%d%d", &l, &r);
                printf("%I64d\n", T.query(l, r, 1, n, root[timStp]));
            } else if(*op == 'H') {
                int l, r, t; scanf("%d%d%d", &l, &r, &t);
                printf("%I64d\n", T.query(l, r, 1, n, root[t]));
            } else {
                scanf("%d", &timStp);
            }
        }
    }

    return 0;
}
```

#### prefix字典树 hdu5790
- N≤105个字符串，保证∑|Li|≤105，Q≤105次询问在线查询[L, R]区间有多少个不同的前缀
``` cpp
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q;
char s[N];

int root[N];
struct PersistentSegTree {
    static const int M = 1e5 * 40;
    int sz;
    struct Node {
        int ls, rs, sum;
    } tree[M];
    void init() {
        sz = 0;
        root[0] = 0;
    }
    int newNode(int rt) {
        tree[++sz] = tree[rt];
        return sz;
    }
    void update(int o, int v, int l, int r, int& rt) {
        rt = newNode(rt);
        tree[rt].sum += v;
        if(l == r) return;
        int m = l + r >> 1;
        if(o <= m) update(o, v, l, m, tree[rt].ls);
        else update(o, v, m + 1, r, tree[rt].rs);
    }
    int query(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R) return tree[rt].sum;
        int m = l + r >> 1, ret = 0;
        if(L <= m) ret += query(L, R, l, m, tree[rt].ls);
        if(R > m) ret += query(L, R, m + 1, r, tree[rt].rs);
        return ret;
    }
} T;

struct Trie {
    static const int M = 1e5 + 10, S = 26;
    int sz, rt, nxt[M][S];
    int val[M];
    int newNode() {
        val[sz] = 0;
        memset(nxt[sz], 0, sizeof nxt[sz]);
        return sz++;
    }
    void init() {
        sz = 0;
        rt = newNode();
    }
    void insert(char* s, int id) {
        int u = rt;
        for(int i = 0; s[i]; ++i) {
            int& v = nxt[u][s[i] - 'a'];
            if(!v) v = newNode();
            if(val[v]) T.update(val[v], -1, 1, n, root[id]);
            val[v] = id;
            T.update(val[v], 1, 1, n, root[id]);
            u = v;
        }
    }
} trie;

int main() {

    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        T.init();
        trie.init();

        for(int i = 1; i <= n; ++i) {
            scanf("%s", s);
            root[i] = root[i - 1];
            trie.insert(s, i);
        }

        int z = 0;
        scanf("%d", &q);
        while(q--) {
            int l, r; scanf("%d%d", &l, &r);
            l = (z + l) % n + 1;
            r = (z + r) % n + 1;
            if(l > r) swap(l, r);
            z = T.query(l, n, 1, n, root[r]);
            printf("%d\n", z);
        }
    }

    return 0;
}
```

### 二叉搜索树
#### nlogn建树+kmp
$$$ N≤6×105，给定1∼N的序列，按照这个顺序建立一颗二叉搜索树 $$$
$$$ 奇数是1，偶数是0，先序遍历这颗二叉搜索树生成1个01的欧拉序列 $$$
$$$ 查找T串可重叠的出现了几次，|T|≤7000 $$$
``` cpp
const int N = 6e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int rt, ls[N], rs[N];
char s[N << 1], t[7010];

void dfs(int rt) {
    s[n++] = (rt & 1) + '0';
    if(ls[rt]) {
        dfs(ls[rt]);
        s[n++] = (rt & 1) + '0';
    }
    if(rs[rt]) {
        dfs(rs[rt]);
        s[n++] = (rt & 1) + '0';
    }
}

int kmp() {
    m = strlen(t);
    vector<int> nxt(m + 1);
    nxt[0] = -1;
    for(int i = 0, j = -1; i < m;) {
        if(j == -1 || t[i] == t[j]) nxt[++i] = ++j;
        else j = nxt[j];
    }

    int ret = 0;
    for(int i = 0, j = 0; i < n;) {
        if(j == -1 || s[i] == t[j]) ++i, ++j;
        else j = nxt[j];
        if(j == m) {
            ++ret;
            j = nxt[j];
        }
    }
    return ret;
}

int main() {

    ios_base::sync_with_stdio(0);

    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        memset(ls, 0, sizeof ls);
        memset(rs, 0, sizeof rs);

        set<int> st;
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            if(!st.size()) rt = x;
            else {
                auto it = st.lower_bound(x);
                if(it == st.end()) rs[*--it] = x;
                else {
                    if(!ls[*it]) ls[*it] = x;
                    else rs[*--it] = x;
                }
            }
            st.insert(x);
        }
        scanf("%s", t);

        n = 0;
        dfs(rt);
        s[n] = 0;

        static int kase = 0;
        printf("Case #%d: %d\n", ++kase, kmp());
    }
    return 0;
}
```

### 可持久化Trie
#### HDU 5801 Up Sky,Mr.Zhu
$$$ 给定N≤105的字符串S，字符集大小为5，其中的回文子串长度<20 $$$
$$$ 定义回文子串str[0…n−1]的特征串为str[⌊n/2⌋…n−1] $$$
$$$ 给定询问区间s[L…R]里，特征串前缀为T的回文串有多少个，|T|≤10 $$$
``` cpp
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

int root[N];
struct PersistentTrie {
    static const int M = N * 10, S = 5;
    int sz;
    struct Node {
        LL val;
        int nxt[S];
    } dat[M];
    void init() {
        sz = 0;
        memset(&dat[0], 0, sizeof dat[0]);
    }
    int newNode(int rt) {
        dat[++sz] = dat[rt];
        return sz;
    }
    void update(char* s, int n, int& rt) {
        rt = newNode(rt);
        int u = rt;
        for(int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            int& v = dat[u].nxt[c];
            v = newNode(v);
            ++dat[v].val;
            u = v;
        }
    }
    LL query(char* s, int rt) {
        int u = rt;
        for(int i = 0; s[i]; ++i) {
            int c = s[i] - 'a';
            u = dat[u].nxt[c];
        }
        return dat[u].val;
    }
} trie;

int q;
char s[N], t[N][15];
int l[N], r[N];
LL ans[N];

bool check(char* s, int len) {
    for(int i = 0; i < len / 2; ++i)
        if(s[-i] != s[-(len - i - 1)]) return false;
    return true;
}

int main() {

    ios_base::sync_with_stdio(0);

    while(scanf("%s%d", s + 1, &q) == 2) {
        int n = strlen(s + 1);
        for(int i = 1; i <= q; ++i) scanf("%d%d%s", l + i, r + i, t[i]);

        memset(ans, 0, sizeof ans);
        for(int len = 1; len < 20; ++len) {
            trie.init();
            for(int i = 1; i <= n; ++i) {
                root[i] = root[i - 1];
                if(i < len) continue;
                bool ok = check(s + i, len);
                if(!ok) continue;
                int l = i - (len - 1) / 2;
                trie.update(s + l, (len + 1) / 2, root[i]);
            }
            for(int i = 1; i <= q; ++i) {
                if(r[i] - l[i] + 1 < len) continue;
                ans[i] += trie.query(t[i], root[r[i]]) - trie.query(t[i], root[l[i] + len - 2]);
            }
        }
        for(int i = 1; i <= q; ++i)
            printf("%I64d\n", ans[i]);
    }
    return 0;
}
```

### 树上莫队
#### SPOJ Count on a tree II（树上莫队）
$$$ 给定一颗N≤40000个点的树，点权Ai≤109 $$$
$$$ Q≤105，询问(u, v)路径上有多少不同的点权 $$$
``` cpp
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int B = 200;

int n, m, a[N], b[N];

struct Edge {
    int v, nxt;
} edge[N << 1];
int head[N], eCnt;

void addEdge(int u, int v) {
    edge[eCnt] = {v, head[u]};
    head[u] = eCnt++;
}

int L[N], R[N], dep[N], fa[N], vs[N], dfsNum;
int id[N], blocks;
int stk[N], top;

void dfs(int u, int f) {
    L[u] = ++dfsNum;
    vs[dfsNum] = u;
    fa[u] = f;

    int btm = top;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == f) continue;

        dep[v] = dep[u] + 1;
        dfs(v, u);

        if(top - btm >= B) {
            ++blocks;
            while(top != btm) {
                int v = stk[top--];
                id[v] = blocks;
            }
        }
    }
    R[u] = dfsNum;
    stk[++top] = u;
}

struct Query {
    int l, r, id;
};

bool cmpTree(const Query& a, const Query& b) {
    return id[a.l] < id[b.l] ||
           id[a.l] == id[b.l] && L[a.r] < L[b.r];
}

int cnt[N];
int sum, ans[N];

void add(int x) {
    if(cnt[b[x]]++ == 0) ++sum;
}

void del(int x) {
    if(--cnt[b[x]] == 0) --sum;
}

bool in[N];
int cross;
void reverse(int x) {
    if(in[x]) {
        in[x] = false;
        del(x);
    } else {
        in[x] = true;
        add(x);
    }
}

void moveUp(int& x) {
    if(!cross) {
        if(in[x] && !in[fa[x]]) cross = x;
        else if(in[fa[x]] && !in[x]) cross = fa[x];
    }
    reverse(x); x = fa[x];
}

void move(int a, int b) {
    if(a == b) return;
    cross = 0;
    if(in[b]) cross = b;
    while(dep[a] > dep[b]) moveUp(a);
    while(dep[b] > dep[a]) moveUp(b);
    while(a != b) moveUp(a), moveUp(b);
    reverse(a); reverse(cross);
}

void gao() {
    dfsNum = blocks = 0;
    dfs(1, 0);
    while(top) id[stk[top--]] = blocks;
}

int main() {

    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &m);

    vector<int> xs(n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        xs[i - 1] = a[i];
    }
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
    for(int i = 1; i <= n; ++i)
        b[i] = lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin() + 1;

    eCnt = 0; memset(head, -1, sizeof head);
    for(int i = 1; i < n; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }

    gao();

    vector<Query> qt(m);
    for(int i = 1; i <= m; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        if(id[u] > id[v]) swap(u, v);
        qt[i - 1] = {u, v, i};
    }

    sort(qt.begin(), qt.end(), cmpTree);

    sum = 0;
    memset(cnt, 0, sizeof cnt);
    memset(in, 0, sizeof in);

    add(1); in[1] = true;
    int l = 1, r = 0;
    for(auto& q : qt) {
        move(l, q.l);
        move(r, q.r);
        l = q.l; r = q.r;

        ans[q.id] = sum;
    }
    for(int i = 1; i <= m; ++i) printf("%d\n", ans[i]);

    return 0;
}
```

#### HDU 5799 This world need more Zhu（树上莫队）
$$$ 给定一颗N≤105个点的树，点权Ai≤109，Q≤105，询问形如op u v a b $$$
$$$ op=1时，u=v，查询子树u中，gcd(∑cnt[x]=ax, ∑cnt[y]=by) $$$
$$$ op=2时，查询路径(u, v)中，gcd(∑cnt[x]=ax, ∑cnt[y]=by) $$$
``` cpp
/*op=1，dfs序搞成序列上的莫队，op=2树上莫队*/
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int B = 250;

typedef long long LL;
int n, m, a[N], b[N];

struct Edge {
    int v, nxt;
} edge[N << 1];
int head[N], eCnt;

void addEdge(int u, int v) {
    edge[eCnt] = {v, head[u]};
    head[u] = eCnt++;
}

int L[N], R[N], dep[N], fa[N], vs[N], dfsNum;
int id[N], blocks;
int stk[N], top;

void dfs(int u, int f) {
    L[u] = ++dfsNum;
    vs[dfsNum] = u;
    fa[u] = f;

    int btm = top;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == f) continue;

        dep[v] = dep[u] + 1;
        dfs(v, u);

        if(top - btm >= B) {
            ++blocks;
            while(top != btm) {
                int v = stk[top--];
                id[v] = blocks;
            }
        }
    }
    R[u] = dfsNum;
    stk[++top] = u;
}

struct Query {
    int l, r, block, a, b, id;
};

bool cmpSeq(const Query& a, const Query& b) {
    return a.block < b.block ||
           a.block == b.block && a.r < b.r;
}
bool cmpTree(const Query& a, const Query& b) {
    return id[a.l] < id[b.l] ||
           id[a.l] == id[b.l] && L[a.r] < L[b.r];
}

int cnt[N];
LL sum[N], ans[N];

void add(int x) {
    sum[cnt[b[x]]] -= a[x];
    ++cnt[b[x]];
    sum[cnt[b[x]]] += a[x];
}

void del(int x) {
    sum[cnt[b[x]]] -= a[x];
    --cnt[b[x]];
    sum[cnt[b[x]]] += a[x];
}

bool in[N];
int cross;
void reverse(int x) {
    if(in[x]) {
        in[x] = false;
        del(x);
    } else {
        in[x] = true;
        add(x);
    }
}

void moveUp(int& x) {
    if(!cross) {
        if(in[x] && !in[fa[x]]) cross = x;
        else if(in[fa[x]] && !in[x]) cross = fa[x];
    }
    reverse(x); x = fa[x];
}

void move(int a, int b) {
    if(a == b) return;
    cross = 0;
    if(in[b]) cross = b;
    while(dep[a] > dep[b]) moveUp(a);
    while(dep[b] > dep[a]) moveUp(b);
    while(a != b) moveUp(a), moveUp(b);
    reverse(a); reverse(cross);
}

void gao() {
    dfsNum = blocks = 0;
    dfs(1, 0);
    while(top) id[stk[top--]] = blocks;
}

int main() {

    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);

        vector<int> xs(n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            xs[i - 1] = a[i];
        }
        sort(xs.begin(), xs.end());
        xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
        for(int i = 1; i <= n; ++i)
            b[i] = lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin() + 1;

        eCnt = 0; memset(head, -1, sizeof head);
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }

        gao();

        vector<Query> qs, qt;
        for(int i = 1; i <= m; ++i) {
            int op, u, v, a, b;
            scanf("%d%d%d%d%d", &op, &u, &v, &a, &b);
            if(op == 1) {
                int p = L[u] / B;
                qs.push_back({L[u], R[u], p, a, b, i});
            } else {
                if(id[u] > id[v]) swap(u, v);
                qt.push_back({u, v, -1, a, b, i});
            }
        }

        {
            //subtree
            sort(qs.begin(), qs.end(), cmpSeq);
            memset(cnt, 0, sizeof cnt);
            memset(sum, 0, sizeof sum);

            int l = 1, r = 0;
            for(auto& q : qs) {
                while(r < q.r) add(vs[++r]);
                while(l < q.l) del(vs[l++]);
                while(r > q.r) del(vs[r--]);
                while(l > q.l) add(vs[--l]);

                ans[q.id] = __gcd(sum[q.a], sum[q.b]);
            }
        }

        {
            //path
            sort(qt.begin(), qt.end(), cmpTree);
            memset(cnt, 0, sizeof cnt);
            memset(sum, 0, sizeof sum);
            memset(in, 0, sizeof in);

            add(1); in[1] = true;
            int l = 1, r = 0;
            for(auto& q : qt) {
                move(l, q.l);
                move(r, q.r);
                l = q.l; r = q.r;

                ans[q.id] = __gcd(sum[q.a], sum[q.b]);
            }
        }

        static int kase = 0;
        printf("Case #%d:\n", ++kase);
        for(int i = 1; i <= m; ++i) printf("%I64d\n", ans[i]);
    }

    return 0;
}
```

### 线段树
####  AOJ 2450 Do use segment tree （树链剖分 + 线段树区间合并）
$$$ 一颗N<=2×105的树,Q<=105,两种操作 $$$
$$$ 1 u v c,将u−>v路径上的点权变为c  $$$
$$$ 2 u v c,查询u−>v路径上的最大连续点权和,c卖萌的 $$$
``` cpp
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q, w[N], val[N];

struct Node {
    int l, r;
    int pre, suf, sub, sum;
    Node() {pre = suf = sub = sum = -INF;}
    Node rev() {
        Node ret = *this;
        swap(ret.pre, ret.suf);
        return ret;
    }
    void set(int v) {
        sum = v * (r - l + 1);
        pre = suf = sub = max(v, sum);
    }
};

void printNode(Node x) {
    printf("l: %d r: %d pre: %d suf: %d sub: %d sum: %d\n",
           x.l, x.r, x.pre, x.suf, x.sub, x.sum);
}

Node operator+ (const Node& A, const Node& B) {
    if(A.sub == -INF) return B;
    if(B.sub == -INF) return A;
    Node ret; ret.l = A.l, ret.r = B.r;
    ret.sum = A.sum + B.sum;
    ret.pre = max(A.pre, A.sum + B.pre);
    ret.suf = max(B.suf, B.sum + A.suf);
    ret.sub = max(A.suf + B.pre, max(A.sub, B.sub));
    return ret;
}

struct SegTree {
    Node dat[N << 2];
    int setv[N << 2];

    void push_up(int rt) {
        dat[rt] = dat[rt << 1] + dat[rt << 1 | 1];
    }

    void push_down(int rt) {
        if(setv[rt] != -INF) {
            int v = setv[rt], ls = rt << 1, rs = ls | 1;
            setv[ls] = setv[rs] = v;
            dat[ls].set(v);
            dat[rs].set(v);
            setv[rt] = -INF;
        }
    }

    void build(int l, int r, int rt) {
        setv[rt] = -INF;
        if(l == r) {
            dat[rt].l = l, dat[rt].r = r;
            dat[rt].set(val[l]);
            return;
        }
        int m = l + r >> 1;
        build(l, m, rt << 1);
        build(m + 1, r, rt << 1 | 1);
        push_up(rt);
    }

    void update(int L, int R, int v, int rt) {
        if(L <= dat[rt].l && dat[rt].r <= R) {
            setv[rt] = v;
            dat[rt].set(v);
            return;
        }
        push_down(rt);
        int m = dat[rt].l + dat[rt].r >> 1;
        if(L <= m) update(L, R, v, rt << 1);
        if(R > m) update(L, R, v, rt << 1 | 1);
        push_up(rt);
    }

    void printAll(int rt) {
        printNode(dat[rt]);
        if(dat[rt].l == dat[rt].r) return;
        printAll(rt << 1);
        printAll(rt << 1 | 1);
    }

    Node query(int L, int R, int rt) {
        if(L <= dat[rt].l && dat[rt].r <= R) return dat[rt];
        push_down(rt);
        int m = dat[rt].l + dat[rt].r >> 1;
        Node ret;
        if(L <= m && R > m) ret = query(L, R, rt << 1) + query(L, R, rt << 1 | 1);
        else if(L <= m) ret = query(L, R, rt << 1);
        else if(R > m) ret = query(L, R, rt << 1 | 1);
        return ret;
    }
};

struct Edge {
    int to, nxt;
};

struct HLD {
    int head[N], cnt, tid;
    int sz[N], son[N], fa[N], dep[N], top[N], dfn[N];
    Edge edge[N << 1];
    SegTree T;

    void init() {
        cnt = tid = 0;
        memset(head, -1, sizeof head);
        memset(son, 0, sizeof son);
    }

    void add_edge(int u, int v) {
        edge[cnt] = (Edge) {v, head[u]};
        head[u] = cnt++;
        edge[cnt] = (Edge) {u, head[v]};
        head[v] = cnt++;
    }
    //find heavy edge
    void dfs1(int u, int f, int d) {
        sz[u] = 1, fa[u] = f, dep[u] = d;
        for(int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            if(v == f) continue;
            dfs1(v, u, d + 1);
            if(!son[u] || sz[v] > sz[son[u]]) son[u] = v;
            sz[u] += sz[v];
        }
    }
    //connect heavy edge
    void dfs2(int u, int tp) {
        dfn[u] = ++tid;
        val[tid] = w[u];
        top[u] = tp;
        if(son[u]) dfs2(son[u], tp);
        for(int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            if(v == fa[u] || v == son[u]) continue;
            dfs2(v, v);
        }
    }

    void update(int u, int v, int c) {
        int fu = top[u], fv = top[v];
        while(fu != fv) {
            if(dep[fu] < dep[fv]) {
                swap(u, v);
                swap(fu, fv);
            }
            T.update(dfn[fu], dfn[u], c, 1);
            u = fa[fu];
            fu = top[u];
        }
        if(dep[u] > dep[v]) swap(u, v);
        T.update(dfn[u], dfn[v], c, 1);
    }

    int query(int u, int v) {
        Node L, R;  //there [l,r] info doesn't matter
        int fu = top[u], fv = top[v];
        while(fu != fv) {
            if(dep[fu] > dep[fv]) {
                L = L + T.query(dfn[fu], dfn[u], 1).rev();
                u = fa[fu], fu = top[u];
            } else {
                R = T.query(dfn[fv], dfn[v], 1) + R;
                v = fa[fv], fv = top[v];
            }
        }
        if(dep[u] > dep[v]) L = L + T.query(dfn[v], dfn[u], 1).rev();
        else R = T.query(dfn[u], dfn[v], 1) + R;
        return (L + R).sub;
    }

    void build() {
        dfs1(1, -1, 0);
        dfs2(1, 1);
        T.build(1, n, 1);
    }
};

HLD hld;

int main() {

    while(scanf("%d%d", &n, &q) == 2) {
        hld.init();
        for(int i = 1; i <= n; ++i) scanf("%d", w + i);
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            hld.add_edge(u, v);
        }
        hld.build();
        while(q--) {
            int op, x, y, z; scanf("%d%d%d%d", &op, &x, &y, &z);
            if(op == 1) hld.update(x, y, z);
            else printf("%d\n", hld.query(x, y));
        }
    }
    return 0;
}
```

#### HDU 5737 Differencia（归并树）
$$$$$$$$$ N≤105长度的A，B两个数组，Ai，Bi≤109 $$$$$$$$$
$$$$$$$$$ Q≤3×106次查询，2种查询 $$$$$$$$$
$$$ + l r x:把A数组的[l, r]区间数变为x $$$
$$$ ? l r:查询[l, r]区间Ai≥Bi的下标个数 $$$

``` cpp
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q, A, B;
int a[N], b[N];

int rnd(int& last, int& a, int& b) {
    int C = ~(1 << 31), M = (1 << 16) - 1;
    a = (36969 + (last >> 3)) * (a & M) + (a >> 16);
    b = (18000 + (last >> 3)) * (b & M) + (b >> 16);
    return (C & ((a << 16) + b)) % 1000000000;
}

namespace Discretization {
    vector<int> xs;
    void init() {
        xs = vector<int>(b + 1, b + 1 + n);
        sort(xs.begin(), xs.end());
        for(int i = 1; i <= n; ++i) {
            b[i] = lower_bound(xs.begin(), xs.end(), b[i]) - xs.begin() + 1;
            a[i] = upper_bound(xs.begin(), xs.end(), a[i]) - xs.begin();
        }
    }
    int get(int x) {
        return upper_bound(xs.begin(), xs.end(), x) - xs.begin();
    }
}

namespace Allocator {
    int data[N << 6], *p;
    void init() {
        p = data;
    }
    int* allocate(int len) {
        p += len;
        return p - len;
    }
}

struct Node {
    int* indexLeft, *indexRight;
    int tag, sum;

    void setTag(int v) {
        tag = sum = v;
    }
    int goLeft(int v) {
        if(v) return indexLeft[v];
        return 0;
    }
    int goRight(int v) {
        if(v) return indexRight[v];
        return 0;
    }

} tree[N << 2];

void pushUp(int rt) {
    tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
}

void pushDown(int rt) {
    if(~tree[rt].tag) {
        int v = tree[rt].tag;
        int ls = rt << 1, rs = ls | 1;
        tree[ls].setTag(tree[rt].goLeft(v));
        tree[rs].setTag(tree[rt].goRight(v));
        tree[rt].tag = -1;
    }
}

void merge(int rt, int l, int r) {
    static int tmp[N];
    int m = l + r >> 1;
    int* vl = b + l - 1, *vr = b + m;
    int sl = m - l + 1, sr = r - m;
    int i = 1, j = 1, k = 1;
    while(i <= sl && j <= sr) {
        if(vl[i] < vr[j]) {
            tree[rt].indexLeft[k] = i;
            tree[rt].indexRight[k] = j - 1;
            tmp[k++] = vl[i++];
        } else {
            tree[rt].indexLeft[k] = i - 1;
            tree[rt].indexRight[k] = j;
            tmp[k++] = vr[j++];
        }
    }
    while(i <= sl) {
        tree[rt].indexLeft[k] = i;
        tree[rt].indexRight[k] = j - 1;
        tmp[k++] = vl[i++];
    }
    while(j <= sr) {
        tree[rt].indexLeft[k] = i - 1;
        tree[rt].indexRight[k] = j;
        tmp[k++] = vr[j++];
    }
    memcpy(b + l, tmp + 1, r - l + 1 << 2);
}

void build(int l, int r, int rt) {
    tree[rt].tag = -1;
    tree[rt].indexLeft = Allocator::allocate(r - l + 1);
    tree[rt].indexRight = Allocator::allocate(r - l + 1);
    if(l == r) {
        tree[rt].sum = a[l] >= b[l];
        return;
    }
    int m = l + r >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    pushUp(rt);
    merge(rt, l, r);
}

void update(int L, int R, int v, int l, int r, int rt) {
    if(L <= l && r <= R) {
        tree[rt].setTag(v);
        return;
    }
    int m = l + r >> 1;
    pushDown(rt);
    if(L <= m) update(L, R, tree[rt].goLeft(v), l, m, rt << 1);
    if(R > m) update(L, R, tree[rt].goRight(v), m + 1, r, rt << 1 | 1);
    pushUp(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) return tree[rt].sum;
    int m = l + r >> 1, ret = 0;
    pushDown(rt);
    if(L <= m) ret += query(L, R, l, m, rt << 1);
    if(R > m) ret += query(L, R, m + 1, r, rt << 1 | 1);
    return ret;
}

int main() {

    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d", &n, &q, &A, &B);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        for(int i = 1; i <= n; ++i) scanf("%d", b + i);

        Allocator::init();
        Discretization::init();
        build(1, n, 1);

        int ans = 0, last = 0;
        for(int i = 1; i <= q; ++i) {
            int l = rnd(last, A, B) % n + 1;
            int r = rnd(last, A, B) % n + 1;
            int x = rnd(last, A, B) + 1;
            if(l > r) swap(l, r);
            if(l + r + x & 1) {
                x = Discretization::get(x);
//                printf("+ %d %d %d\n", l, r, x);
                update(l, r, x, 1, n, 1);
            } else {
                last = query(l, r, 1, n, 1);
//                printf("? %d %d ans = %d\n", l, r, last);
                ans += 1LL * i * last % MOD;
                if(ans >= MOD) ans -= MOD;
            }
        }
        printf("%d\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
```

#### UVA 11402 Ahoy, Pirates!（线段树标记合并）
$$$ F a b：[a, b]变为1 $$$
$$$ E a b：[a, b]变为0 $$$
$$$ I a b：[a, b]01翻转，即0变1，1变0 $$$
$$$ S a b：[a, b]中1有多少个 $$$ 
``` cpp
const int N = 1.1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

string str;

struct Node {
    int l, r;
    int sum;
    Node() {}
    Node(int l, int r): l(l), r(r) {}
    int len() {
        return r - l + 1;
    }
    void set(int v) {
        if(v == -1) return;
        if(v == 2) sum = len() - sum;
        else sum = len() * v;
    }
} dat[N << 2];

int tag[N << 2];

void pushUp(int rt) {
    dat[rt].sum = dat[rt << 1].sum + dat[rt << 1 | 1].sum;
}

void combineTag(int fa, int& son) {
    if(fa == 2) {
        if(son == -1) son = 2;
        else if(son == 2) son = -1;
        else son ^= 1; // switch 0, 1
    } else son = fa; //set 0, 1
}

void pushDown(int rt) {
    if(tag[rt] == -1) return;

    int ls = rt << 1, rs = ls | 1;
    dat[ls].set(tag[rt]);
    dat[rs].set(tag[rt]);
    combineTag(tag[rt], tag[ls]);
    combineTag(tag[rt], tag[rs]);

    tag[rt] = -1;
}

void build(int l, int r, int rt) {
    dat[rt] = Node(l, r);
    tag[rt] = -1;
    if(l == r) {
        dat[rt].sum = str[l] - '0';
        return;
    }
    int m = l + r >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    pushUp(rt);
}

void update(int L, int R, int v, int rt) {
    if(L <= dat[rt].l && dat[rt].r <= R) {
        dat[rt].set(v);
        combineTag(v, tag[rt]);
        return;
    }
    pushDown(rt);
    int m = dat[rt].l + dat[rt].r >> 1;
    if(L <= m) update(L, R, v, rt << 1);
    if(R > m) update(L, R, v, rt << 1 | 1);
    pushUp(rt);
}

int query(int L, int R, int rt) {
    if(L <= dat[rt].l && dat[rt].r <= R) return dat[rt].sum;
    pushDown(rt);
    int m = dat[rt].l + dat[rt].r >> 1;
    int ret = 0;
    if(L <= m) ret += query(L, R, rt << 1);
    if(R > m) ret += query(L, R, rt << 1 | 1);
    return ret;
}

int main() {

    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        str.clear();
        int m; scanf("%d", &m);
        while(m--) {
            int cnt;
            char buf[105]; scanf("%d%s", &cnt, buf);
            while(cnt--) str += buf;
        }
        build(0, str.size() - 1, 1);

        int q; scanf("%d", &q);
        int qs = 0;
        static int kase = 0;
        printf("Case %d:\n", ++kase);
        while(q--) {
            char op[2]; int a, b; scanf("%s%d%d", op, &a, &b);
            if(*op == 'F') update(a, b, 1, 1);
            else if(*op == 'E') update(a, b, 0, 1);
            else if(*op == 'I') update(a, b, 2, 1);
            else printf("Q%d: %d\n", ++qs, query(a, b, 1));
        }
    }
    return 0;
}
```

### POJ 3168 Barn Expansion（扫描线）
$$$ 给定N≤2.5×104个矩形，保证没有重合，且任何边相切或者顶点重合的是不好的 $$$
$$$ 问最后还有几个好的 $$$ 
``` cpp
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int bx[N], by[N], ux[N], uy[N];

struct Line {
    int x, y, id;
    Line() {}
    Line(int x, int y, int id): x(x), y(y), id(id) {}
    bool operator<(const Line& l) const {
        if(x == l.x) {
            if(y == l.y) return id < l.id; //+ first
            return y < l.y;
        }
        return x < l.x;
    }
};

void solve(vector<int>& bad, int* bx, int* ux, int* by, int* uy) {
    vector<Line> events;
    for(int i = 1; i <= n; ++i) {
        events.push_back(Line(bx[i], by[i], -i));
        events.push_back(Line(bx[i], uy[i], i));
        events.push_back(Line(ux[i], by[i], -i));
        events.push_back(Line(ux[i], uy[i], i));
    }
    sort(events.begin(), events.end());

    int sum = 1;
    for(int i = 1; i < events.size(); ++i) {
        sum += events[i].id < 0 ? 1 : -1;
        int preID = abs(events[i - 1].id), curID = abs(events[i].id);
        if(sum >= 2) bad[preID] = bad[curID] = true;
    }
}

int main() {

    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i)
            scanf("%d%d%d%d", bx + i, by + i, ux + i, uy + i);

        vector<int> bad(n + 1, false);
        solve(bad, bx, ux, by, uy);
        solve(bad, by, uy, bx, ux);

        int ans = n - count(bad.begin(), bad.end(), true);
        printf("%d\n", ans);
    }

    return 0;
}
```

## 数学
### FFT
#### HDU 5730 Shell Necklace（dp、cdq分治+FFT）
$$$ 给定N≤105个贝壳的项链，每连续i≤N个贝壳模式的贡献是ai $$$
$$$ 对于某种串项链的方式，假设含有模式b1, b2, ⋯, bm，总贡献为∏mi=1abi $$$
$$$ 求所有串项链方式的贡献和 $$$
``` cpp
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 313;
const double PI = acos(-1);

int n, a[N];
int f[N];

typedef complex<double> Complex;

void rader(Complex* y, int len) {
    for(int i = 1, j = len / 2; i < len - 1; i++) {
        if(i < j) swap(y[i], y[j]);
        int k = len / 2;
        while(j >= k) {j -= k; k /= 2;}
        if(j < k) j += k;
    }
}
void fft(Complex* y, int len, int op) {
    rader(y, len);
    for(int h = 2; h <= len; h <<= 1) {
        double ang = op * 2 * PI / h;
        Complex wn(cos(ang), sin(ang));
        for(int j = 0; j < len; j += h) {
            Complex w(1, 0);
            for(int k = j; k < j + h / 2; k++) {
                Complex u = y[k];
                Complex t = w * y[k + h / 2];
                y[k] = u + t;
                y[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if(op == -1) for(int i = 0; i < len; i++) y[i] /= len;
}

Complex A[N << 1], B[N << 1];

void cdq(int l, int r) {
    if(l == r) return;
    int mid = (l + r) >> 1;
    cdq(l, mid);

    int len = 1;
    while(len <= r - l + 1) len <<= 1;
    for(int i = 0; i < len; i++) {
        A[i] = Complex(l + i <= mid ? f[l + i] : 0, 0);
        B[i] = Complex(l + i + 1 <= r ? a[i + 1] : 0, 0);
    }
    fft(A, len, 1);
    fft(B, len, 1);
    for(int i = 0; i < len; i++) A[i] *= B[i];
    fft(A, len, -1);

    for(int i = mid + 1; i <= r; i++) {
        f[i] += fmod(A[i - l - 1].real(), MOD) + 0.5;
        if(f[i] >= MOD) f[i] -= MOD;
    }
    cdq(mid + 1, r);
}

int main() {

    ios_base::sync_with_stdio(0);


    while(scanf("%d", &n) == 1 && n) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            a[i] %= MOD;
        }

        memset(f, 0, sizeof f);
        f[0] = 1;
        cdq(0, n);
        printf("%d\n", f[n]);
    }

    return 0;
}
```

### NTT
#### HDU 5829 Rikka with Subset （NTT）
$$$ 给定N≤105个数，对于一个给定的1≤K≤N，设数集全集为U $$$
$$$ 任意S∈U，val(S):=S中前min(K, |S|)大数的和 $$$
$$$ val(U)k=∑S∈Uval(S) $$$
$$$ 输出每个val(U)k $$$

``` cpp
/*
//ntt(A, len, 1);
//ntt(B, len, 1);
//for(int i = 0; i < len; ++i) A[i] = A[i] * B[i] % P;
//ntt(A, len, -1);
//(r ^{2k}) + 1 	rr	kk	gg
3	1	1	2
5	1	2	2
17	1	4	3
97	3	5	5
193	3	6	5
257	1	8	3
7681	15	9	17
12289	3	12	11
40961	5	13	3
65537	1	16	3
786433	3	18	10
5767169	11	19	3
7340033	7	20	3
23068673	11	21	3
104857601	25	22	3
167772161	5	25	3
469762049	7	26	3
1004535809	479	21	3
2013265921	15	27	31
2281701377	17	27	3
3221225473	3	30	5
75161927681	35	31	3
77309411329	9	33	7
206158430209	3	36	22
2061584302081	15	37	7
2748779069441	5	39	3
6597069766657	3	41	5
39582418599937	9	42	5
79164837199873	9	43	5
263882790666241	15	44	7
1231453023109121	35	45	3
1337006139375617	19	46	3
3799912185593857	27	47	5
4222124650659841	15	48	19
7881299347898369	7	50	6
31525197391593473	7	52	3
180143985094819841	5	55	6
1945555039024054273	27	56	5
4179340454199820289    29	57	3
*/
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
const int G = 3, P = 998244353;

LL quick(LL x, LL n) {
    LL ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % P;
        x = x * x % P;
    }
    return ret;
}

LL A[N << 2], B[N << 2];
void rader(LL* y, int len) {
    for(int i = 1, j = len / 2; i < len - 1; i++) {
        if(i < j) swap(y[i], y[j]);
        int k = len / 2;
        while(j >= k) {j -= k; k /= 2;}
        if(j < k) j += k;
    }
}
void ntt(LL* y, int len, int op) {
    rader(y, len);
    for(int h = 2; h <= len; h <<= 1) {
        LL wn = quick(G, (P - 1) / h);
        if(op == -1) wn = quick(wn, P - 2);
        for(int j = 0; j < len; j += h) {
            LL w = 1;
            for(int k = j; k < j + h / 2; k++) {
                LL u = y[k];
                LL t = w * y[k + h / 2] % P;
                y[k] = (u + t) % P;
                y[k + h / 2] = (u - t + P) % P;
                w = w * wn % P;
            }
        }
    }
    if(op == -1) {
        LL inv = quick(len, P - 2);
        for(int i = 0; i < len; i++) y[i] = y[i] * inv % P;
    }
}

int n, a[N], f[N];
LL fact[N], invf[N], two[N], invt[N];

int main() {

    ios_base::sync_with_stdio(0);

    fact[0] = two[0] = invf[0] = invt[0] = 1;
    for(int i = 1; i < N; ++i) {
        fact[i] = fact[i - 1] * i % P;
        two[i] = two[i - 1] * 2 % P;
        invf[i] = quick(fact[i], P - 2);
        invt[i] = quick(two[i], P - 2);
    }

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        sort(a + 1, a + n + 1, greater<int>());

        int len = 1;
        while(len <= n << 1) len <<= 1;
        for(int i = 0; i < len; ++i) {
            A[i] = i <= n ? two[n - i] * invf[i] % P : 0;
            B[i] = i >= 1 && i <= n ? a[i] * fact[i - 1] % P : 0;
        }
        reverse(B + 1, B + n + 1);

        ntt(A, len, 1);
        ntt(B, len, 1);
        for(int i = 0; i < len; ++i) A[i] = A[i] * B[i] % P;
        ntt(A, len, -1);

        for(int i = 1; i <= n; ++i) f[i] = invt[i] * invf[i - 1] % P * A[n - i + 1] % P;
        for(int i = 1; i <= n; ++i) if((f[i] += f[i - 1]) >= P) f[i] -= P;
        for(int i = 1; i <= n; ++i) printf("%d ", f[i]);
        puts("");
    }

    return 0;
}
```

### FWT
#### IForg 1028 Bob and Alice are playing numbers
$$$ n个数里选2个数进行三种位运算的最大值 $$$
$$$ 数的大小只有106，cnt[i]:=i这个数出现了多少次 $$$
$$$ 然后卷积一下自己，减去自己和自己的，倒着枚举找到最大的那个就做完了 $$$
``` cpp
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

LL quick(LL x, LL n) {
    LL ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
    }
    return ret;
}

const LL invTwo = quick(2, MOD - 2);

void fwtXor(LL* a, int len) {
    if(len == 1) return;
    int h = len >> 1;
    fwtXor(a, h);
    fwtXor(a + h, h);
    for(int i = 0; i < h; ++i) {
        LL x1 = a[i];
        LL x2 = a[i + h];
        a[i] = (x1 + x2) % MOD;
        a[i + h] = (x1 - x2 + MOD) % MOD;
    }
}

void ifwtXor(LL* a, int len) {
    if(len == 1) return;
    int h = len >> 1;
    for(int i = 0; i < h; ++i) {
        // y1=x1+x2
        // y2=x1-x2
        LL y1 = a[i];
        LL y2 = a[i + h];
        a[i] = (y1 + y2) * invTwo % MOD;
        a[i + h] = (y1 - y2 + MOD) * invTwo % MOD;
    }
    ifwtXor(a, h);
    ifwtXor(a + h, h);
}

void fwtAnd(LL* a, int len) {
    if(len == 1) return;
    int h = len >> 1;
    fwtAnd(a, h);
    fwtAnd(a + h, h);
    for(int i = 0; i < h; ++i) {
        LL x1 = a[i];
        LL x2 = a[i + h];
        a[i] = (x1 + x2) % MOD;
        a[i + h] = x2;
    }
}

void ifwtAnd(LL* a, int len) {
    if(len == 1) return;
    int h = len >> 1;
    for(int i = 0; i < h; ++i) {
        // y1=x1+x2
        // y2=x2
        LL y1 = a[i];
        LL y2 = a[i + h];
        a[i] = (y1 - y2 + MOD) % MOD;
        a[i + h] = y2;
    }
    ifwtAnd(a, h);
    ifwtAnd(a + h, h);
}

void fwtOr(LL* a, int len) {
    if(len == 1) return;
    int h = len >> 1;
    fwtOr(a, h);
    fwtOr(a + h, h);
    for(int i = 0; i < h; ++i) {
        LL x1 = a[i];
        LL x2 = a[i + h];
        a[i] = x1;
        a[i + h] = (x2 + x1) % MOD;
    }
}

void ifwtOr(LL* a, int len) {
    if(len == 1) return;
    int h = len >> 1;
    for(int i = 0; i < h; ++i) {
        // y1=x1
        // y2=x2+x1
        LL y1 = a[i];
        LL y2 = a[i + h];
        a[i] = y1;
        a[i + h] = (y2 - y1 + MOD) % MOD;
    }
    ifwtOr(a, h);
    ifwtOr(a + h, h);
}

int n, op;
const int C = 1 << 20;
LL a[N], cnt[C + 10];

int gao() {
    for(int i = C; ~i; --i) if(cnt[i]) return i;
    return -1;
}

int main() {

    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &op);
        memset(cnt, 0, sizeof cnt);
        for(int i = 1; i <= n; ++i) {
            scanf("%lld", a + i);
            ++cnt[a[i]];
        }

        static int kase = 0;
        printf("Case #%d: ", ++kase);
        if(op == 1) {
            fwtAnd(cnt, C);
            for(int i = 0; i < C; ++i) cnt[i] = cnt[i] * cnt[i] % MOD;
            ifwtAnd(cnt, C);
            for(int i = 1; i <= n; ++i) --cnt[a[i] & a[i]];
            printf("%d\n", gao());
        } else if(op == 2) {
            fwtXor(cnt, C);
            for(int i = 0; i < C; ++i) cnt[i] = cnt[i] * cnt[i] % MOD;
            ifwtXor(cnt, C);
            for(int i = 1; i <= n; ++i) --cnt[a[i] ^ a[i]];
            printf("%d\n", gao());
        } else {
            fwtOr(cnt, C);
            for(int i = 0; i < C; ++i) cnt[i] = cnt[i] * cnt[i] % MOD;
            ifwtOr(cnt, C);
            for(int i = 1; i <= n; ++i) --cnt[a[i] | a[i]];
            printf("%d\n", gao());
        }
    }

    return 0;
}
```

#### SRM 518 NIM

题意:
$$$ 2个人玩nim游戏，能选K≤109堆，每堆必须是素数pi≤L≤106，后手赢的方案数 $$$

分析:
$$$ nim游戏，由SG定理知，先手xorsum为0输，即后手赢 $$$
$$$ 问题就变成了这个，之后就可以dp了，f[i][j]:=选i堆异或和为j的方法数 $$$
$$$ 显然f[1][j]是知道的，转移是f[i][j]=∑x⊕y=jf[i−1][x]×f[1][y] $$$
$$$ 发现这是个and卷积的形式，答案就是卷积的k次幂，所以直接做就好了 $$$

``` cpp
fwtXor(a, L)
a[i] = a[i] ^ k
ifwtXor(a, L)
ans = a[0]
```

#### Codeforces 449D Jzzhu and Numbers
- 题意：
	- 给定长度为N≤106的数列，Ai≤106，选出0<k≤N个数
	使得它们二进制与起来的值为0，求方法数
	分析：
	题解给了一个容斥的做法，是基于子集卷积的
	f[s]:=子集状态为s的方法数，g[s]:=s中1的个数
	f[s]可由fwt子集卷积变换得到，之后我们根据容斥原理：
	ans=2n+∑ s=1 {{2 ^20} −1} (−1) ^g(s)*2 ^f(s)，这里空集被容斥掉了
	事实上，可以不用自己容斥，无论是哪种理解，对于某个f[s]，可以随便选
	即变成2f[s]，然后再ifwt变换回去，答案就是f[0]，这里空集同样被容斥掉了
	从这里我们看出其实卷积也有容斥的感觉
	(试了一下代码发现fwt变换其实就是所谓的高维前缀和)

``` cpp
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

void fwtAnd(LL* a, int len) {
    if(len == 1) return;
    int h = len >> 1;
    fwtAnd(a, h);
    fwtAnd(a + h, h);
    for(int i = 0; i < h; ++i) {
        LL x1 = a[i];
        LL x2 = a[i + h];
        a[i] = (x1 + x2) % MOD;
        a[i + h] = x2 % MOD;
    }
}

void ifwtAnd(LL* a, int len) {
    if(len == 1) return;
    int h = len >> 1;
    for(int i = 0; i < h; ++i) {
        // y1=x1+x2
        // y2=x2
        LL y1 = a[i];
        LL y2 = a[i + h];
        a[i] = (y1 - y2 + MOD) % MOD;
        a[i + h] = y2 % MOD;
    }
    ifwtAnd(a, h);
    ifwtAnd(a + h, h);
}

int n;
const int C = 1 << 20;
LL cnt[C + 10], two[C + 10];

int main() {

    ios_base::sync_with_stdio(0);

    two[0] = 1;
    for(int i = 1; i < C; ++i) two[i] = two[i - 1] * 2 % MOD;

    while(scanf("%d", &n) == 1) {
        memset(cnt, 0, sizeof cnt);
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            ++cnt[x];
        }

        fwtAnd(cnt, C);
        for(int i = 0; i < C; ++i) cnt[i] = two[cnt[i]];
        ifwtAnd(cnt, C);
        printf("%I64d\n", cnt[0]);
    }

    return 0;
}
```


## 其他
### 树Hash
#### HDU 5732 Subway（树哈希）
$$$ 给定N≤105个节点的2棵树，保证2棵树同构 $$$
$$$ 输出一种2棵树的节点映射方式 $$$

``` cpp
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
const LL seed[2] = {999999937, 999999929};
const LL mod[2] = {1000000007, 1000000009}; //1e9+7/+9
struct Hash {
    LL h[2];
    Hash() {}
    Hash(const LL& first) {
        for(int i = 0; i < 2; ++i) h[i] = first;
    }
    Hash operator+(const Hash& rhs) const {
        Hash ret = *this;
        for(int i = 0; i < 2; ++i) {
            ret.h[i] = ret.h[i] * seed[i] % mod[i];
            if((ret.h[i] += rhs.h[i]) >= mod[i]) ret.h[i] -= mod[i];
        }
        return ret;
    }
    bool operator<(const Hash& rhs) const {
        return make_pair(h[0], h[1]) < make_pair(rhs.h[0], rhs.h[1]);
    }
    bool operator==(const Hash& rhs) const {
        return make_pair(h[0], h[1]) == make_pair(rhs.h[0], rhs.h[1]);
    }

    void see() {
        printf("(%llu %llu)\n", h[0], h[1]);
    }
};

int n;
vector<int> G[2][N];

void getDiameter(int u, int f, int d, int idx, pair<int, int>& diameter) {
    diameter = max(diameter, make_pair(d, u));
    vector<int>& cur = G[idx][u];
    for(auto& v : cur) {
        if(v == f) continue;
        getDiameter(v, u, d + 1, idx, diameter);
    }
}

bool getPath(int u, int f, int t, int idx, vector<int>& path) {
    path.push_back(u);
    if(u == t) return true;
    vector<int>& cur = G[idx][u];
    for(auto& v : cur) {
        if(v == f) continue;
        if(getPath(v, u, t, idx, path)) return true;
    }
    path.pop_back();
    return false;
}

vector<pair<Hash, int> > treeHash[2][N];

Hash getHash(int u, int f, int idx) {
    vector<int>& cur = G[idx][u];
    vector<pair<Hash, int> > sons;
    for(auto& v : cur) {
        if(v == f) continue;
        sons.push_back({getHash(v, u, idx), v});
    }

    Hash h(1);
    sort(sons.begin(), sons.end());
    for(auto& v : sons) h = h + v.first;
    treeHash[idx][u].swap(sons);
    return h;
}

map<string, int> mp[2];
vector<string> names[2];
int ID(string s, int idx) {
    if(mp[idx].count(s)) return mp[idx][s];
    names[idx].push_back(s);
    mp[idx][s] = names[idx].size();
    return mp[idx][s];
}

void init(int idx) {
    mp[idx].clear(); names[idx].clear();
    for(int i = 1; i <= n; ++i) G[idx][i].clear();
}

void OLE(string s) {
    while(1)
        puts(s.c_str());
}

void RE() {
    printf("%d\n", *((int*)0));
}

bool match(vector<pair<Hash, int> >& cur, vector<pair<Hash, int> >& nxt,
           vector<pair<int, int> >& ans) {
    if(cur.size() != nxt.size()) return false;
    int cnt = 0;
    for(int i = 0; i < cur.size(); ++i) {
        bool ok = false;
        for(int j = i; j < nxt.size() && cur[i].first == nxt[j].first; ++j) {
            swap(nxt[i], nxt[j]);
            if(match(treeHash[0][cur[i].second], treeHash[1][nxt[i].second], ans)) {
                ++cnt;
                ok = true;
                ans.push_back({cur[i].second, nxt[i].second});
                break;
            }
        }
        if(!ok) {
            while(cnt--) ans.pop_back();
            return false;
        }
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d", &n) == 1) {
        for(int i = 0; i < 2; ++i) {
            init(i);

            for(int j = 1; j < n; ++j) {
                char a[20], b[20]; scanf("%s%s", a, b);
                int u = ID(a, i), v = ID(b, i);
//                printf("%d->%d\n", u, v);
                G[i][u].push_back(v);
                G[i][v].push_back(u);
            }
//            puts("");
        }

        vector<pair<Hash, int> > hashes[2];
        for(int i = 0; i < 2; ++i) {
            pair<int, int> diameter = { -INF, -INF};
            getDiameter(1, -1, 0, i, diameter);
            int u = diameter.second;
            diameter = { -INF, -INF};
            getDiameter(u, -1, 0, i, diameter);
            int v = diameter.second;

//            printf("diameter %d -> %d\n", u, v);

            vector<int> path;
            getPath(u, -1, v, i, path);
            int sz = path.size();
            int x = path[sz >> 1], y = -1;
            if(~path.size() & 1) y = path[sz / 2 - 1];
            hashes[i].push_back({getHash(x, y, i), x});
            if(~y) hashes[i].push_back({getHash(y, x, i), y});

//            printf("start %d %d\n", x, y);

            sort(hashes[i].begin(), hashes[i].end());
        }

        vector<pair<int, int> > ans;
        if(!match(hashes[0], hashes[1], ans)) RE();

//        prln(ans.size());
        if(ans.size() != n) OLE("WA");

        for(int i = 0; i < ans.size(); ++i) {
            int u, v; tie(u, v) = ans[i];
            printf("%s %s\n", names[0][u - 1].c_str(), names[1][v - 1].c_str());
        }
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
```

#### VK Cup 2016 - Round 1 D. Bear and Polynomials（哈希）
$$$ N≤2×105，给定一个N次多项式，即P(x)=∑Ni=0ai⋅xi $$$
$$$ 已经P(2)≠0，现要改变其中一个系数ai，使得P′(2)=0 $$$
$$$ 求方法数 $$$
``` cpp
/* 
由于N非常大，所以直接算是不行的
我们可以通过对素数取模来哈希这个结果，这个素数一定要比max{ai}大
取2个素数，之后枚举每个系数，算出答案，比较是否相等即可，同时别忘记负数答案了
各种取模，注意不要模出负数了
时间复杂度O(n)
*/
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k;
int a[N];
typedef long long LL;

LL ksm(LL x, LL n, LL MOD) {
    LL ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
    }
    return ret;
}

int main() {

    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &k);
    LL sum[2] = {}, mod[2] = {MOD, MOD + 2};
    LL power[2] = {1, 1}, base[2] = {2, 2};
    for(int i = 0; i <= n; ++i) {
        scanf("%d", a + i);
        for(int j = 0; j < 2; ++j) {
            sum[j] = (sum[j] + a[i] * power[j] % mod[j]) % mod[j];
            sum[j] = (sum[j] + mod[j]) % mod[j];
            power[j] = power[j] * base[j] % mod[j];
        }
    }

    int ans = 0;
    for(int i = 0; i < 2; ++i) power[i] = 1, base[i] = ksm(2, mod[i] - 2, mod[i]);
    for(int i = 0; i <= n; ++i) {
        LL delta[2];
        for(int j = 0; j < 2; ++j) {
            delta[j] = (a[i] - sum[j] * power[j] % mod[j]) % mod[j];
            delta[j] = (delta[j] + mod[j]) % mod[j];
            power[j] = power[j] * base[j] % mod[j];
        }

        LL cof = INF;
        if(delta[0] == delta[1]) cof = delta[0];
        if(delta[0] - mod[0] == delta[1] - mod[1]) cof = delta[0] - mod[0];
        if(abs(cof) > k || i == n && cof == 0) continue;

        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}
```

#### Codeforces Round 354 (Div. 2) E. The Last Fight Between Human and AI

$$$ 给定一个N≤105次多项式P(x)=anxn+an−1xn−1+...+a1x+a0 $$$
$$$ 现2个人轮流随意填P(x)的系数，填过的不能再填 $$$
$$$ 现有一个多项式Q(x)=x−k，如果最终多项式P(x)可以整除Q(x)，那么后手赢 $$$
$$$ 有一部分系数数已经被2个人填了，?表示还没填 $$$
$$$ 现2个人最优操作的情况下，问后手是否能赢 $$$
``` cpp
/* 假如所有系数ai都是确定的，如果P(x)能被x−k整除
说明x−k是P(x)的一个因子，显然x=k是P(x)=0的一个根，k≠0
那么讨论一下k=0的情况：
如果a[0]=0，那么Q(x)已经整除P(x)，反之则不能整除
如果a[0]不确定，那么第一个填a[0]的人胜
再仔细看一下k≠0的情况：
如果系数全部确定的情况上面已经说了，代入x=k判断P(x)=0成立性
对于不完全确定的情况，我们先看一下只有1个不确定的情况：
令其他的确定系数的项的和为A，不确定的那项为aixi
由P(x)=A+aixi=0得，ai=−Axi，由于ai可以是实数
那么最后一步的操作者有必胜策略
这样分2种情况讨论，每种情况里又有2种情况讨论这题就做完了
对于如何算出P(k)，实际上只有从高位到低位乘起来
如果中间大于N×max{Ai}那么就无解了，然后判是不是0就好了
当然对于zz选手的我，直接取很多素数对结果取模进行哈希判断也是可以哒
*/

const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k;
int a[N];

int calc(int mod) {
    int ret = 0;
    for(int i = n; ~i; --i) ret = (1LL * ret * k + a[i]) % mod;
    return ret;
}

int main() {


    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d", &n, &k) == 2) {
        int unknown = 0;
        for(int i = 0; i <= n; ++i) {
            char buf[10]; scanf("%s", buf);
            a[i] = *buf == '?' ? INF : atoi(buf);
            unknown += a[i] == INF;
        }

        int used = n + 1 - unknown;

        if(k == 0) {
            //a[0] is 0 will win
            puts(a[0] == 0 || a[0] == INF && (used & 1) ? "Yes" : "No");
        } else {
            if(!unknown) {
                bool ok = true;
                for(int i = 2e9; ; ++i) {
                    if(calc(i)) {ok = false; break;}
                    if(1.0 * (clock() - _) / CLOCKS_PER_SEC > 0.95) break;
                }
                puts(ok ? "Yes" : "No");
            } else puts(~(n + 1) & 1 ? "Yes" : "No");
        }
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
```

### 生成树计数
$$$ 给定无向图3个点A、B、G，AB间有a条边，AG间有b条边，BG间有c条边 $$$
$$$ 求从A出发回到A的欧拉回路的个数，答案模10 ^9+7 $$$

``` cpp
/*
叉姐给出1个有向图欧拉回路计数的定理
有向图欧拉回路的话，判定条件：连通，每个点入度=出度
有向图欧拉回路计数(BSET Theorem)：
ec(G)=ts(G)⋅deg(s)!⋅∏v∈V, v≠s(deg(v)−1)!, ts(G):=以s为根的外向树的个数
注意特判1个点答案是1
生成树计数(Kirchhoff Theorem)：
基尔霍夫矩阵K=度数矩阵D−邻接矩阵A
重边：按照边数计算，自环：不计入度数
无向图生成树计数：c=|K的任意1个n−1阶主子式|
有向图外向树计数：c=|去掉根所在的那阶得到的主子式|
以上是学习内容，这个题只要枚举一条边的其中1个方向的边数
然后根据欧拉回路判定性条件解出其他边的2个方向的边数
然后直接套定理解出个数，注意选边的时候要乘组合数
然后这个题就做完了，时间复杂度O(n)
*/
const int N = 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
LL a[N][N], ans[N];
bool isFreeX[N];

LL gauss(int n, int m) {
    for(int i = 0; i < m; ++i) isFreeX[i] = false;
    LL ret = 1, neg = 0;

    int r = 1, c = 1;
    for(; r < n && c < m; ++r, ++c) {
        int p = r;
        for(; p < n; ++p) if(a[p][c]) break;
        if(p == n) {--r; isFreeX[c] = true; continue;}
        if(p != r) {
            neg ^= 1;
            for(int i = c; i <= m; ++i) swap(a[p][i], a[r][i]);
        }

        //eliminate coefficient
        for(int i = r + 1; i < n; ++i) {
            while(a[i][c]) {
                LL delta = a[i][c] / a[r][c];
                for(int j = c; j <= m; ++j) {
                    a[i][j] += MOD - delta * a[r][j] % MOD;
                    a[i][j] %= MOD;
                }
                if(!a[i][c]) break;
                neg ^= 1;
                for(int j = c; j <= m; ++j) swap(a[r][j], a[i][j]);
            }
        }
    }
    if(r != n) return 0;
    for(int i = 1; i < r; ++i) ret = ret * a[i][i] % MOD;
    if(neg) ret = (-ret + MOD) % MOD;
    return ret;
}

int A, B, C;
int deg[N];

bool check(int& x, int A) {
    if(x & 1) return false;
    x /= 2;
    return x >= 0 && x <= A;
}

const int M = 1e5 + 10;
LL fact[M], finv[M];

LL quick(LL x, LL n) {
    LL ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
    }
    return ret;
}

LL comb(int n, int m) {
    if(n < m) return 0;
    return fact[n] * finv[m] % MOD * finv[n - m] % MOD;
}

int main() {

    ios_base::sync_with_stdio(0);

    fact[0] = finv[0] = 1;
    for(int i = 1; i < M; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
        finv[i] = quick(fact[i], MOD - 2);
    }

    while(scanf("%d%d%d", &A, &B, &C) == 3) {
        LL ans = 0;
        for(int x = 0; x <= A; ++x) { //x in-degrees from A; y from C, z from B
            int y = 2 * x + C - A;
            if(!check(y, C)) continue;
            int z = 2 * y + B - C;
            if(!check(z, B)) continue;
            if(x + B - z != A - x + z) continue; //check A

            deg[0] = x + B - z;
            deg[1] = y + A - x;
            deg[2] = z + C - y;
            for(int i = 0; i < 3; ++i) a[i][i] = deg[i];
            a[0][1] = -(A - x); a[0][2] = -z;
            a[1][0] = -x;  a[1][2] = -(C - y);
            a[2][0] = -(B - z); a[2][1] = -y;

            LL cur = comb(A, x) * comb(C, y) % MOD * comb(B, z) % MOD;

            //BEST Theorem
            cur = cur * gauss(3, 3) % MOD;
            cur = cur * deg[0] % MOD;
            for(int i = 0; i < 3; ++i) cur = cur * fact[deg[i] - 1] % MOD;
            ans = (ans + cur) % MOD;
        }
        printf("%lld\n", ans);
    }

    return 0;
}
``` 