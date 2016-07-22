/*************************************************************************
	> File Name: j.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月20日 星期三 16时37分34秒
 ************************************************************************/
#pragma comment(linker, "/STACK:102400000,102400000")
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
#define pr(x) //cout << #x << " = " << x << " ";
#define prln(x) //cout << #x << " = " << x <<  endl; 
#define ni (i^1)
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
const ll MOD = 1e12+7;
const ll base = 2e7+13;
struct Node{
    ll hash;
    int id;
    bool operator < (const Node& rhs)const{
        return hash < rhs.hash;
    }
}a[maxn], b[maxn];
struct State{
    int x;
};
struct Tree{
    ll hash, n;
    ll f[maxn];
    int head[maxn], to[maxn], nxt[maxn];
    Node node[maxn];
    ll siz[maxn];
    ll l[maxn], r[maxn];
    int tcnt = 0;
    ll temp[maxn];
    ll gethash(int x){
        ll ans = 0;
        sort(temp+1, temp+x);
        for(int i = 0; i < x; ++i){
            /*pr(i);prln(temp[i]);*/
            ans = (ans*base + temp[i])%MOD;
        }
        /*prln(ans);*/
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
        prln(u);
        //prln(u);
        for(int i = head[u]; ~i; i= nxt[i]){
            prln(i);
            prln(nxt[i]);
            int v = to[i];
            if(v == fa) continue;
            dfs1(v, u);
            f[i] = 0;
            int cnt = 0;
            temp[cnt++] = siz[v];
            siz[u] += siz[v];
            for(int j = head[v]; ~j; j = nxt[j]){
                prln(j);
                if(to[j] == u) continue;
                temp[cnt++] = f[j];
            }
            prln(cnt);
            f[i] = gethash(cnt);
            //pr(to[i]);prln(siz[to[i]]);
            //pr(i);prln(f[i]);
        prln(">>>>>>>>>>>>>>>");
        }

        prln(">>>>>>>>>>>>>>>");
        //pr(u);prln(siz[u]);
    }
    int pos;
    void dfs2(int u, int fa){
        int cnt = 0;
        int tempsz = tcnt;
        pr(u);prln(fa);
        prln(tcnt);
        prln("-----------");
        int i,  v;
        for(i = head[u]; ~i; i = nxt[i]){
            temp[tcnt++] = f[i];
            pr(i);prln(tcnt);
        }
        sort(temp+tempsz, temp+tcnt);
        cnt = tcnt - tempsz;
        /*prln("*************");*/
        pr(u);pr(fa);
        /*pr(tempsz);pr(tcnt);prln(cnt);*/
        for(i = tempsz; i < tcnt; ++i){
            pr(i);prln(tcnt);
            if(i == tempsz) l[i] = temp[i];
            else{
                l[i] = (l[i-1]*base+temp[i])%MOD;
            }
        }
        for(i = tcnt-1; i >= tempsz; --i){
            prln(i);
            if(i == tcnt-1){
                r[i] = temp[i]*ret(base, tcnt-1-i);
            }else{
                r[i] = (r[i+1] + temp[i]*ret(base, tcnt-i-1)); 
            }
        }
        prln("1");
        for(i = head[u]; ~i; i = nxt[i]){
            v = to[i];
            if(v == fa) continue;
            /*prln(ni);*/
            /*pr(f[i]);*/
            prln("3");
            prln(i);
            pos = lower_bound(temp+tempsz, temp+tcnt, f[i]) - temp-tempsz;
            /*pr(pos);prln(cnt);*/
            /*for(int j = tempsz; j < tcnt; ++j){*/
                /*pr(j);*/
                /*pr(l[j]);*/
                /*pr(r[j]);*/
                /*prln(temp[j]);*/

            /*}*/
            f[ni] = n-siz[to[i]];
            //prln(f[ni]);
            f[ni] = f[ni]*ret(base, cnt-1)%MOD;
            prln(f[ni]);
            if(pos) f[ni] = (f[ni] + l[pos-1+tempsz]*ret(base, cnt-pos-1));
            /*prln(f[ni]);*/
            pr(cnt-pos-1);
            /*pr(l[pos-1+tempsz]);*/
            /*pr(tempsz+pos+1);*/
            if(pos!=cnt-1) f[ni] = (f[ni] + r[tempsz+pos+1])%MOD;
            /*pr(r[pos+tempsz+1]);*/
            prln(f[ni]);
            
            prln("4");
            dfs2(to[i], u);
            prln("5");

        }
        prln(tcnt);
        tcnt = tempsz;
        //prln("--------------");
    }
    void getf(){
        for(int i = 1; i <= n; ++i){
            node[i].id = i;
            node[i].hash = 0;
            ll &ans = node[i].hash;
            int cnt = 0;
            for(int j = head[i]; ~j; j = nxt[j]){
                temp[cnt++] = f[j];
            }
            sort(temp, temp+cnt);
            for(int j = 0; j < cnt; ++j){
                ans = (ans*base + temp[j])%MOD;
            }
            //pr(i);pr(siz[i]);prln(node[i].hash);
        }
        sort(node+1, node+1+n);
    }
    int getid(ll _hash, int l){
        Node x;
        x.hash = _hash;
        int pos = lower_bound(node+1+l, node+1+n, x) - node; 
        return pos;
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
ll hasha[maxn], hashb[maxn];
/*char su[20], sv[20];*/
char ss[212345][2][20];
ll bian[213456][20];
int id[maxn];
int ida[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
    /*freopen("/home/zeroxf/桌面/out1.txt","w",stdout);*/
#endif
    int  n;
    //scanf("%d", &t);
    while(scanf("%d", &n) != EOF){
        //scanf("%d%d", &n, &m);
        hh.init(n);
        hw.init(n);
        prln(n);
        int lenu = 0,lenv = 0,hashu = 0,hashv = 0;
        int cnta =0,cntb = 0;
        for(int i = 1; i < n; ++i){
            scanf("%s%s",ss[i][0], ss[i][1]);
            lenu = strlen(ss[i][0]);
            lenv = strlen(ss[i][1]);
            hashu = getstr(ss[i][0], lenu);
            hashv = getstr(ss[i][1], lenv);
            //pr(i);pr(hashu);prln(hashv);
            hasha[cnta++] = hashu;
            hasha[cnta++] = hashv;
            bian[i][0] = hashu;
            bian[i][1] = hashv;
        }

        for(int i = 1; i < n; ++i){
            scanf("%s%s",ss[i+n][0], ss[i+n][1]);
            lenu = strlen(ss[i+n][0]);
            lenv = strlen(ss[i+n][1]);
            hashu = getstr(ss[i+n][0], lenu);
            hashv = getstr(ss[i+n][1], lenv);
            //pr(i);pr(hashu);prln(hashv);
            hashb[cntb++] = hashu;
            hashb[cntb++] = hashv;
            bian[i+n][0] = hashu;
            bian[i+n][1] = hashv;
        }
        prln("1");
        sort(hasha,hasha+cnta);
        sort(hashb,hashb+cntb);
        cnta = unique(hasha, hasha+cnta)-hasha;
        cntb = unique(hashb, hashb+cntb)-hashb;

        prln("2");
        for(int i = 1; i < n; ++i){
            int pos1 = lower_bound(hasha, hasha+cnta,bian[i][0])-hasha+1;
            int pos2 = lower_bound(hasha, hasha+cnta,bian[i][1])-hasha+1;
            hh.addedge(pos1, pos2);
            hh.addedge(pos2, pos1);
            ida[pos1] = (i)*2;
            ida[pos2] = (i)*2+1;
            //pr(pos1);prln(pos2);
        }

        prln("3");
        for(int i = 1; i < n; ++i){
            int pos1 = lower_bound(hashb, hashb+cntb,bian[i+n][0])-hashb+1;
            int pos2 = lower_bound(hashb, hashb+cntb,bian[i+n][1])-hashb+1;
            hw.addedge(pos1, pos2);
            hw.addedge(pos2, pos1);
            id[pos1] = (i+n)*2;
            id[pos2] = (i+n)*2+1;
            //pr(pos1);prln(pos2);
        }

        prln("4");
        hh.dfs1(1,1);
        prln("**************");
        //hh.dfs2(1,1);
        hh.getf();
        //prln("**************");
        hw.dfs1(1,1);
        //hw.dfs2(1,1);
        hw.getf();
        hh.getf();
        bool ok = true;
        for(int i = 0; i < hh.edgenum; ++i){
            /*pr(i);pr(hh.f[i]);prln(hw.f[i]);*/
            if(hh.f[i] != hw.f[i]) ok = false;
        }
        int posa, posb, pa, pb;
        for(int i = 0; i < cnta; ++i){
            //pr(i);pr(hh.node[i].hash);prln(hh.node[i].id);
            //pr(i);pr(hw.node[i].hash);prln(hw.node[i].id);
            posa = ida[hh.node[i+1].id]/2;
            pa = ida[hh.node[i+1].id]&1;
            posb = id[hw.node[i+1].id]/2;
            pb = id[hw.node[i+1].id]&1;
            printf("%s %s\n", ss[posa][pa], ss[posb][pb]);
        }
       //for(int i = 0; i < cnta; ++i){
            //prln(hh.node[i+1].hash);
            //posa = ida[hh.node[i+1].id]/2;
            //pa = ida[hh.node[i+1].id]&1;
            //posb = hw.getid(hh.node[i+1].hash, l);
            //l = posb+1;
            //pr(posb);
            //prln(hw.node[posb].hash);
            //pb = id[posb]&1;
            //posb = id[posb]/2;
            //prln(l);
            //printf("%s %s\n", ss[posa][pa], ss[posb][pb]);
       //}
        //if(ok) cout << "YES";

        
    }
	return 0;
}
