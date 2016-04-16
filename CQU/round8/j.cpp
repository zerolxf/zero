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
const int maxn = 2e5+100;
const int inf = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
typedef pair<int,int> P;
int n,m;
int d[20][20][20][20];
char s[20][20];
int dp[20][20][(1 << 17)];
int dir[4][2] = {1,0,-1,0,0,1,0,-1};
bool leap[20][20];
struct Node
{
	int x,y,st;
	Node(int x = 0,int y = 0,int st = 0):x(x),y(y),st(st){}
};
struct Edge
{
	int ux,uy,vx,vy;
}edge[20];
void init(int x,int y)
{
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			d[x][y][i][j] = inf;
	memset(leap,false,sizeof(leap));
	leap[x][y] = true;
	d[x][y][x][y] = 0;
	queue<Node>p;
	p.push(Node(x,y,0));
	while(p.size())
	{
		Node u = p.front();p.pop();
		d[x][y][u.x][u.y] = u.st;
		for(int i = 0;i < 4;i++)
		{
			int tempx = u.x + dir[i][0];
			int tempy = u.y + dir[i][1];
			if(tempx >= 0 && tempy >= 0 && tempx < n && tempy < n)
			{
				if(!leap[tempx][tempy] && s[tempx][tempy] != '#')
				{
					leap[tempx][tempy] = true;
					p.push(Node(tempx,tempy,u.st + 1));
				}
			}
		}
	}
}
int dfs(int x,int y,int s)
{
	if(dp[x][y][s] != -1)return dp[x][y][s];
	int ans = inf;
	for(int i = 0;i < m;i++)
	{
		if(s & (1 << i))continue;
		ans = min(ans,d[x][y][edge[i].ux - 1][edge[i].uy - 1] + dfs(edge[i].vx - 1,edge[i].vy - 1,s | (1 << i)));
	}
	return dp[x][y][s] = ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    while(scanf("%d%d",&n,&m) != EOF)
    {
    	for(int i = 0;i < n;i++)
    		scanf("%s",s + i);
    	for(int i = 0;i < n;i++)
    	{
    		for(int j = 0;j < n;j++)
    			init(i,j);
    	}
    	for(int i = 0;i < m;i++)
    		scanf("%d%d%d%d",&edge[i].ux,&edge[i].uy,&edge[i].vx,&edge[i].vy);
    	int ans = inf;
    	memset(dp,-1,sizeof(dp));
    	for(int i = 0;i < m;i++)
    		ans = min(ans,dfs(edge[i].vx - 1,edge[i].vy - 1,(1 << i)));
    	if(ans == inf)
    		printf("-1\n");
    	else
    		printf("%d\n",ans);
    }
    return 0;
}