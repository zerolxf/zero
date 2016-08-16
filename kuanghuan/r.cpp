/*************************************************************************
	> File Name: r.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月24日 星期日 14时57分35秒
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
map<int,int> sg;
vector<int> vt[maxn];
int a[maxn];
int cnta;
void dfs(int x){
    if(sg.count(a[x])) return;
    int xsiz = vt[x].size();
    bool vis[1100];
    for(int i = 0; i < xsiz; ++i){
        int y = a[x]/vt[x][i];
        int pos = lower_bound(a, a+cnta, vt[x][i]) - a;
        dfs(pos);
        if(y&1) {
            vis[sg[vt[x][i]]] = true;
        }else vis[0] = true;
    }
    for(int i = 0; i < INF; ++i){
        if(!vis[i]){
            sg[a[x]] = i;
            return ;
        }
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, m, k;
    cin >> m >> n >> k;
    int ma = sqrt(n+100);
    cnta = 0;
    for(int i = 1; i <= ma; ++i){
        if(n%i == 0){
            a[cnta++] = i;
            a[cnta++] = n/i;
        }
    }
    sort(a, a+cnta);
    cnta = unique(a, a+cnta) - a;
    for(int i = 0; i < cnta; ++i){
        if(a[i] < k) continue;
        for(int j = 0; j < i; ++j){
            if(a[j] < k) continue;
            if(a[i]%a[j]!= 0) continue;
            vt[i].push_back(a[j]);
        }
    }
    //sg[k] = 0;
    dfs(cnta-1);
    int ans = 0;
    if(m&1) ans = sg[n];
    if(ans == 0){
        cout << "Marsel" << "\n";
    }else cout << "Timur\n";
	return 0;
}
