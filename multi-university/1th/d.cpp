/*************************************************************************
	> File Name: d.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月19日 星期二 17时52分44秒
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
const int maxn = 2e6+100;
const int INF = 0x3f3f3f3f;
const int HASHSIZE = 1e5+7;
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
}hh;
int a[maxn];
const int N = 60;
struct Has{
    ll dp[N];
    int state[N], head[N], nxt[N];
    int sz;
    void init()
    {
        sz = 0;
        memset(head, -1, sizeof head);
    }
    void push(int _st, ll num){
        int st = _st%37;
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
        int st = _st%37;
        for(int i = head[st]; ~i; i = nxt[i]) {
            if(state[i] == _st){
                return dp[i];
            }
        }
        return 0;
    }
}ck[2];
int n, m;
int gcd(int x, int y){
    if(y==0) return x;
    return  gcd(y, x%y);
}
int sum[maxn];
void build(int rt, int l, int r){
    if(l == r){
        scanf("%d", &a[l]);
        sum[rt] = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(rt<<1, l, m);
    build(rt<<1|1, m+1, r);
    sum[rt] = gcd(sum[rt<<1], sum[rt<<1|1]);
}
int query(int rt, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return sum[rt];
    }
    int m = (l + r) >> 1;
    if(qr <= m) return query(rt<<1, l, m, ql, qr);
    else if(ql > m) return query(rt<<1|1, m+1, r, ql, qr);
    else{
        return gcd(query(rt<<1, l, m, ql, qr), query(rt<<1|1, m+1, r, ql, qr));
    }
}
int l[maxn], r[maxn];
int num[maxn], ans[maxn];
map<int, ll> ha, mp[2];
int dp[20][123456];
int getlen(int x){
    int ans = 0;
    while(x){
        ans++;
        x>>=1;
    }
    return ans;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    scanf("%d", &t);
    int kase = 0;
    while(t--){
        //hh.init();
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &dp[0][i]);
        }
        for(int i = 1; (1<<i)<=n; ++i){
            for(int j = 1; j <= n; ++j){
                dp[i][j] = gcd(dp[i-1][j], dp[i-1][j+(1<<(i-1))]);
            }
        }
        //build(1, 1, n);
        scanf("%d", &m);
        int x, y;
        for(int i = 0; i < m; ++i){
            scanf("%d%d", &x, &y);
            int len = getlen(y-x+1) -1;
            num[i] = gcd(dp[len][x], dp[len][y-(1<<len)+1]);
            //prln(num[i]);
        }
        int now = 0, pre = 1;
        mp[0].clear();
        mp[1].clear();
        ha.clear();
        //ck[now].init();
        //ck[pre].init();
        for(int i = 1; i <= n; ++i){
            swap(now,pre);
            mp[now].clear();
            for(auto itr = mp[pre].begin(); itr != mp[pre].end(); itr++){
               int temp = gcd(dp[0][i], itr->first);
               //prln(temp);
               mp[now][temp] += itr->second;
            }
            mp[now][dp[0][i]]++;
            for(auto itr = mp[now].begin(); itr != mp[now].end(); itr++){
                ha[itr->first] += itr->second;
            }
            //ck[now].init();
            //ck[now].push(a[i], 1);
            //prln(a[i]);
            //for(int j = 0; j < ck[pre].sz; ++j){
                //temp = gcd(a[i], ck[pre].state[j]);
                //prln(ck[pre].state[j]);
                //pr(j);prln(temp);
                //ck[now].push(gcd(a[i], ck[pre].state[j]), ck[pre].dp[j]);
            //}
            //for(int j = 0; j < ck[now].sz; ++j){
                //hh.push(ck[now].state[j], ck[now].dp[j]);
            //}
        }
        printf("Case #%d:\n",++kase);
        for(int i = 0; i < m; ++i){
            //prln(num[i]);
            printf("%d %lld\n", num[i], ha[num[i]]);
        }
        
    }
	return 0;
}
