
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
#include<vector>

using namespace std;
const int maxn = 1e5+100;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
int add[maxn], sum[maxn], num[maxn], p[maxn];
vector<int> G[maxn];
void pushdown(int rt) {
    if(add[rt]) {
        for(int i = 0; i < G[rt].size(); ++i) {
            int v = G[rt][i];
            add[v] =1 - add[rt];
            sum[v] = num[v] - sum[v];
        }
        add[rt] = 0;
    }
}
void pushup(int rt,int cnt) {
    if(rt == 1) return;
    int v = p[rt];
    sum[v] += cnt;
    pushup(v, cnt);

}
void update(int rt) {
    pushdown(rt);
    int cnt = sum[rt];
    sum[rt] = num[rt] - sum[rt];
    add[rt] = 1-add[rt];
    pushup(rt, sum[rt]-cnt);
}
int dfs(int u) {
    int ans = 1;
    for(int i = 0; i < G[u].size();++i) {
        int v = G[u][i];
        ans += dfs(v);
    }
    num[u] = ans;
    return ans;
}
void updown(int rt) {
    if(rt==1) {
        pushdown(rt);
        return;
    }
    updown(p[rt]);
    for(int i = 0; i < G[rt].size();++i) {
        int v = G[rt][i];
        pushdown(v);
    }
}
int query(int rt) {
    updown(p[rt]);
    return sum[rt];
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int n, k, x;
    char op[10];
    while(cin >> n >> k) {
        for(int i = 0; i <= n; ++i) {
            G[i].clear();
            p[i] = 1;
            num[i] = sum[i] = add[i] = 0;
        }
        for(int i = 2; i <= n; ++i) {
            scanf("%d", &x);
            G[x].push_back(i);
            p[i] = x;
        }
        dfs(1);
        for(int i = 0; i < k; ++i) {
            scanf("%s%d", op, &x);
            if(op[0]=='o') {
                update(x);
            }
            else cout << query(x) << "\n";
        }
    }
    return 0;
}
