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
const int base = 7;
struct Node{
    int hash, id;
    bool operator < (const Node& rhs)const{
        return hash < rhs.hash;
    }
};
struct Tree{
    int hash, n;
    int f[maxn], head[maxn], to[maxn], nxt[maxn];
    Node node[maxn];
    int siz[maxn];
    int a[maxn];
    int l[maxn], r[maxn];
    int tcnt = 0;
    ll temp[maxn];
    ll gethash(int x){
        ll ans = 0;
        sort(temp+1, temp+x);
        for(int i = 0; i < x; ++i){
            pr(i);prln(temp[i]);
            ans = (ans*base + temp[i])%MOD;
        }
        prln(ans);
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
    void init(int _n){
        n = _n;
        tcnt = 0;
        memset(head, -1, sizeof head);
        edgenum = 0;
    }
    void dfs1(int u, int fa) {
        prln("*************");
        siz[u] = 1;
        //prln(u);
        for(int i = head[u]; ~i; i= nxt[i]){
            //prln(i);
            int v = to[i];
            if(v == fa) continue;
            dfs1(v, u);
            f[i] = 0;
            int cnt = 0;
            temp[cnt++] = siz[v];
            siz[u] += siz[v];
            for(int j = head[v]; ~j; j = nxt[j]){
                if(to[j] == u) continue;
                temp[cnt++] = f[j];
            }
            prln(cnt);
            f[i] = gethash(cnt);
            //pr(to[i]);prln(siz[to[i]]);
            pr(i);prln(f[i]);
        }
        pr(u);prln(siz[u]);
        prln(">>>>>>>>>>>>>>>");
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
            pr(i);prln(r[i]);
        }
    }
    void dfs2(int u, int fa){
        int cnt = 0;
        int tempsz = tcnt;
        for(int i = head[u]; ~i; i = nxt[i]){
            temp[tcnt++] = f[i];
        }
        sort(temp+tempsz, temp+tcnt);
        cnt = tcnt - tempsz;
        for(int i = tempsz; i < tcnt; ++i){
            if(i == tempsz) l[i] = temp[i];
            else{
                l[i] = (l[i-1]*base+temp[i])%MOD;
            }
        }
        for(int i = tcnt-1; i >= tempsz; --i){
            if(i == tcnt-1){
                r[i] = temp[i]*ret(base, tcnt-1-i);
            }else{
                r[i] = (r[i+1] + temp[i]*ret(base, tcnt-i-1)); 
            }
        }
        for(int i = head[u]; ~i; i = nxt[i]){
            int v = to[i];
            if(v == fa) continue;
            int ni = i^1;
            int pos = lower_bound(temp+tempsz, temp+tcnt, f[i]) - temp-tempsz;
            f[ni] = n-siz[to[i]];
            f[ni] = f[ni]*ret(base, cnt-1)%MOD;
            if(pos) f[ni] = (f[ni] + l[pos-1+tempsz]*ret(base, cnt-pos));
            if(pos!=cnt) f[ni] = (f[ni] + r[tempsz+pos+1])%MOD;
            dfs2(to[i], u);

        }
        tcnt = tempsz;
    }
    void getf(){
        for(int i = 1; i <= n; ++i){
            node[i].id = i;
            node[i].hash = 0;
            int &ans = node[i].hash;
            int cnt = 0;
            for(int j = head[i]; ~j; j = nxt[j]){
                temp[cnt++] = f[j];
            }
            sort(temp, temp+cnt);
            for(int j = 0; j < cnt; ++j){
                ans = (ans*base + temp[j])%MOD;
            }
            pr(i);pr(siz[i]);prln(node[i].hash);
        }
    }
}hh, hw;
ll getstr(char s[], int len){
    ll ans = 0;
    for(int i = 0; i < len; ++i){
        ans = ans*base + s[i];
        ans %= MOD;
    }
    return ans;
}
int hasha[maxn], hashb[maxn];
char su[20], sv[20];
char ss[212345][2][20];
int bian[213456][20];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int  n, m;
    //scanf("%d", &t);
    while(scanf("%d%d", &n, &m) != EOF){
        //scanf("%d%d", &n, &m);
        hh.init(n);
        hw.init(n);
        int lenu = 0,lenv = 0,hashu = 0,hashv = 0;
        int cnta =0,cntb = 0;
        for(int i = 1; i < n; ++i){
            scanf("%s%s",ss[i][0], ss[i][1]);
            lenu = strlen(ss[i][0]);
            lenv = strlen(ss[i][1]);
            hashu = getstr(ss[i][0], lenu);
            hashv = getstr(ss[i][1], lenv);
            pr(i);pr(hashu);prln(hashv);
            hasha[cnta++] = hashu;
            hasha[cnta++] = hashv;
            bian[i][0] = hashu;
            bian[i][1] = hashv;
        }

        for(int i = 1; i < n; ++i){
            scanf("%s%s",ss[i][0], ss[i][1]);
            lenu = strlen(ss[i][0]);
            lenv = strlen(ss[i][1]);
            hashu = getstr(ss[i][0], lenu);
            hashv = getstr(ss[i][1], lenv);
            pr(i);pr(hashu);prln(hashv);
            hashb[cntb++] = hashu;
            hashb[cntb++] = hashv;
            bian[i+n][0] = hashu;
            bian[i+n][1] = hashv;
        }
        sort(hasha,hasha+cnta);
        sort(hashb,hashb+cntb);
        cnta = unique(hasha, hasha+cnta)-hasha;
        cntb = unique(hashb, hashb+cntb)-hashb;
        for(int i = 1; i < n; ++i){
            int pos1 = lower_bound(hasha, hasha+cnta,bian[i][0])-hasha+1;
            int pos2 = lower_bound(hasha, hasha+cnta,bian[i][1])-hasha+1;
            hh.addedge(pos1, pos2);
            hh.addedge(pos2, pos1);
            //pr(pos1);prln(pos2);
        }
        for(int i = 1; i < n; ++i){
            int pos1 = lower_bound(hashb, hashb+cntb,bian[i+n][0])-hashb+1;
            int pos2 = lower_bound(hashb, hashb+cntb,bian[i+n][1])-hashb+1;
            hw.addedge(pos1, pos2);
            hw.addedge(pos2, pos1);
            //pr(pos1);prln(pos2);
        }
        prln("**************");
        hh.dfs1(1,1);
        hh.dfs2(1,1);
        hh.getf();
        prln("**************");
        hw.dfs1(1,1);
        hw.dfs2(1,1);
        hw.getf();
        bool ok = true;
        for(int i = 0; i < hh.edgenum; ++i){
            pr(i);pr(hh.f[i]);prln(hw.f[i]);
            if(hh.f[i] != hw.f[i]) ok = false;
        }
        if(ok) cout << "YES";

        
    }
	return 0;
}
