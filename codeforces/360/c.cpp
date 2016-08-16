/*************************************************************************
	> File Name: c.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年06月30日 星期四 01时20分07秒
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
struct Edge{
    int v, nxt;
    Edge(){}
    Edge(int _v, int _nxt){
        nxt =  _nxt, v = _v;
    }
}edge[maxn];
int head[maxn], flag[maxn];
int cnt[maxn];
int edgenum = 0;
void addedge(int u, int v){
    edge[edgenum] = Edge(v, head[u]);
    head[u] = edgenum++;
}
bool dfs(int u, int num){
    flag[u] = num;
    for(int i = head[u]; ~i; i = edge[i].nxt){
        int v = edge[i].v;
        if(flag[v]==1-num) continue;
        else if(flag[v] == -1){
            flag[v] = 1-num;
            dfs(v, 1-num);
        }else return false;
    }
    return true;
}
int a[maxn], b[maxn];
int c[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, m;
    while(cin >> n >> m){
        for(int i = 0; i <= n; ++i){
            head[i] = -1;
            flag[i] = -1;
            cnt[i] = 0;
        }
        edgenum = 0;
        int u, v;
        for(int i = 0; i < m; ++i){
           scanf("%d%d", &u, &v);
           addedge(u,v);
            addedge(v,u);
            cnt[u]++;cnt[v]++;
        }
        bool ok = true;
        for(int i = 1; i <= n; ++i){
            if(flag[i]==-1&&cnt[i]>0){
                flag[i] = 0;
                ok = ok && dfs(i,0);
            }
        }
        int cnta  = 0, cntb = 0;
        int cntc = 0;
        for(int i = 1; i <= n; ++i){
            if(flag[i]==-1) c[cntc++] = i;
            else if(flag[i]==0) a[cnta++]=i;
            else b[cntb++] = i;
        }
        if(cnta==0&&cntc>0) a[cnta++] = c[--cntc];
        if(cntb==0&&cntc>0) b[cntb++] = c[--cntc];
        for(int i = 0; i < n; ++i){
            for(int j = head[i]; ~j; j = edge[j].nxt){
                int v= edge[j].v;
                if(flag[v]!=1-flag[i]) ok = false;
            }
        }
        if(cnta<=0||cntb<=0||!ok){
            printf("-1\n");
        }else{
            printf("%d\n",cnta);
            for(int i = 0; i < cnta; ++i){
                printf("%d ",a[i]);
            }
            printf("\n");
            printf("%d\n",cntb);
            for(int i = 0; i < cntb; ++i){
                printf("%d ",b[i]);
            }
            printf("\n");

        }
    }
	return 0;
}
