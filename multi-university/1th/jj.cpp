
/*************************************************************************
	> File Name: j.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月20日 星期三 16时37分34秒
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
const int MOD = 1e9+7;
const int base = 37;
struct Tree{
    int hash, n;
    int f[maxn], head[maxn], to[maxn], nxt[maxn];
    int siz[maxn];
    int a[maxn];
    int l[maxn], r[maxn];
    ll temp[maxn];
    ll gethash(int x){
        ll ans = 0;
        sort(temp+1, temp+x);
        for(int i = 0; i < x; ++i){
            ans = (ans*base + temp[i])%MOD;
        }
        return ans;
    }
    int edgenum;
    void addedge(int u, int v){
        nxt[edgenum] = head[u];
        to[edgenum] = v;
        f[edgenum] = -1;
        head[u] = edgenum++;
    }
    ll ret(ll x, int y){
        ll ans = 1;
        while(y){
            if(y&1) ans = ans*x%MOD;
            x = x*x%MOD;
            y >>= 1;
        }
        return ans;
    }
    void dfs1(int u, int fa) {
        ll siz[u] = 1;
        for(int i = head[u]; ~i; i= nxt[i]){
            int v = to[i];
            if(v == fa) continue;
            dfs1(v, u);
            f[i] = 0;
            int cnt = 0;
            temp[cnt++] = siz[v];
            siz[u] += siz[v];
            for(int j = head[v]; ~j; j = nxt[j]){
                if(j == u) continue;
                temp[cnt++] = f[j];
            }
            f[i] = gethash(cnt);
        }
    }
    void inittemp(int x){
        l[0] = l[x] = 0;
        r[0] = r[x] = 0;
        if(x){
            l[0] = temp[0];
        }
        for(int i = 1; i < x; ++i){
            l[i] = l[i]*base+temp[i];
        }
        for(int i = x-1; i >= 0; --i){
            r[i] = r[i+1]*base+temp[i];
        }
    }
    void dfs2(int u, int fa){
        int cnt = 0;
        for(int i = head[u]; ~i; i = nxt[i]){
            int v = to[i];
            if(v == fa) continue;
            temp[cnt++] = f[i];
        }
        sort(temp, temp+cnt);
        inittemp(cnt);
        for(int i = head[u]; ~i; i = nxt[i]){
            int ni = i^1;
            int pos = lower_bound(temp, temp+cnt, f[i]) - temp;
            f[ni] = siz[to[i]];
            f[ni] = f[ni]*ret(base, cnt)%MOD;
            if(pos) f[ni] = (f[ni] + l[pos-1]*ret(base, cnt-pos));
            if(pos!=cnt) f[ni] = (f[ni] + r[pos+1])%MOD;
            dfs2(to[i], u);
        }
    }
}hh, hw;
const int HASHSIZE = 1e5+1e4;
struct Hash{
    ll dp[maxn];
    int state[maxn], head[HASHSIZE], nxt[maxn];
    int sz;
    void init()
    {
        sz = 0;
        memset(head, -1, sizeof head);
    }
    void push(int _st, ll num){
        int st = _st%HASHSIZE;
        for(int i = head[st]; ~i; i = nxt[i]){
            if(state[i] == _st){
                dp[i] = (dp[i]+num);
                return;
            }
        }
        state[sz] = _st;
        nxt[sz] = head[st];
        dp[sz] = num;
        head[st] = sz++;
    }
    ll gethash(int _st){
        int st = _st%HASHSIZE;
        for(int i = head[st]; ~i; i = nxt[i]) {
            if(state[i] == _st){
                return dp[i];
            }
        }
        return 0;
    }
}ha, hb;

int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t, n, m;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        ha.init();
        hb.init();
        
    }
	return 0;
}
