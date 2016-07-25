/*************************************************************************
	> File Name: ddd.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月19日 星期二 22时59分32秒
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
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
const int MAXN = 200000+10;  
  
vector<int>grap[MAXN]; //稀疏图，用邻接表表示图  
stack<int>S;  
  
int low[MAXN]; //low[u] 为u或u的子树能够追溯到的最早的栈中节点的次序编号  
int num[MAXN]; //num[u] 为u搜索的次序编号(时间戳)  
int visited[MAXN];  //标记是否已经被搜索过  
int instack[MAXN]; //标记是否在栈中  
int inde; //顶点的前序编号  
int cnt_scc;   //记录总共将图缩成多少个点  
int belong[MAXN];  //belong[i] = j 表示原图的点i缩点后为点j  
  
int min(int a, int b)  
{  
    return a < b ? a : b;  
}  
  
int max(int a, int b)  
{  
    return a > b ? a : b;  
}  
  
//初始化  
void init(int n)  
{  
    for(int i=0; i<=n; i++)  
    {  
        grap[i].clear();  
    }  
    while(!S.empty())  
    {  
        S.pop();  
    }  
    memset(instack,0,sizeof(instack));  
    memset(visited,0,sizeof(visited));  
    memset(low,-1,sizeof(low));  
    memset(num,-1,sizeof(num));  
    memset(belong,-1,sizeof(belong));  
    inde = 0;  
    cnt_scc = 0;  
}  
  
//找出连通分支，并缩点  
void tarjan(int v)  
{  
    low[v] = num[v] = ++inde;  
    S.push(v);  
    instack[v] = 1;  
    visited[v] = 1;  
  
    for(int i=0; i<grap[v].size(); i++)  
    {  
        int w = grap[v][i];  
        if(!visited[w])  
        {  
            tarjan(w);  
            low[v] = min(low[v],low[w]);  //v或v的子树能够追溯到的最早的栈中节点的次序编号  
        }  
        else if(instack[w])  //(v,w)为后向边  
        {  
            low[v] = min(low[v],num[w]);  
        }  
    }  
    int u;  
    if(low[v] == num[v])  //满足强连通分支条件,进行缩点  
    {  
        ++cnt_scc;  
        do  
        {  
            u = S.top();  
            belong[u] = cnt_scc;  //缩点  
            S.pop();  
            instack[u] = 0;    //出栈解除标记  
        }while(u != v);  
    }  
} 
int p[maxn];
int cnt[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, ans, root;
    while(cin >> n){
        root = 0;
        ans = 0;
        memset(cnt, 0, sizeof cnt);
        init(n);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &p[i]);
            if(p[i] == i) root = i;
            grap[i].push_back(p[i]);
        }
        for(int i = 1; i <= n; ++i){
            if(p[i] == i && i != root && root){
                p[i] = root;
                ans++;
            }
        }
        for(int i = 1; i <= n; ++i){
            if(!visited[i])tarjan(i);
            cnt[belong[i]]++;
        }
        for(int i = 1; i <= n; ++i){
             if(!root && cnt[belong[i]] > 1){
                 root = i;
                 p[i] = i;
                 ans++;
                 break;
             }
        }
        for(int i = 1; i <= n; ++i){
            if(belong[i]!=belong[root] && cnt[belong[i]]>1){
                p[i] = root;
                ans++;
                cnt[belong[i]] = 0;
            }
        }
        cout << ans << "\n";
        for(int i = 1; i <= n; ++i){
            cout << p[i] << " ";
        }
        cout << "\n";

    }
	return 0;
}
