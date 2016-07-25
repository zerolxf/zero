/*************************************************************************
	> File Name: b.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月18日 星期一 10时08分06秒
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
const int maxn = 3e6+100;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const int N = 1e6+2;
int head[N], nxt[maxn], cnt[maxn], to[maxn];
int edgenum;
void addedge(int u, int v, int x){
    nxt[edgenum] = head[u];
    to[edgenum] = v;
    cnt[edgenum] = x;
    head[u] = edgenum++;
}
int prime[N/10], pcnt;
bool vis[maxn];
void getprime(){
    int count = 0;
    for(ll i = 2; i <= 1e6+1; ++i){
        if(vis[i]) continue;
        prime[pcnt++] = i;
        for(ll j = i; j <= 1e6+1; j += i){
            int jj = j;
            int x = 0;
            while(jj>1&&jj%i==0){
                x++;
                jj/=i;
            }
            addedge(j,pcnt-1,x);
            count++;
            vis[j] = true;
            //pr(i);prln(jj);
        }
    }
    //prln(count);
}
int num[N];
void add(int x, int y){
    for(int i = head[x]; ~i; i = nxt[i]){
        int v = to[i];
        num[v] += y*cnt[i];
        //if(num[v]<0) num[v]=0;
    }
}
void update(int x){
    for(int i = head[x]; ~i; i = nxt[i]){
        int v = to[i];
        if(num[v]<cnt[i]) num[v]=cnt[i];
    }
}
ll inline ret(ll x, int y){
    ll ans = 1;
    if(y<1) return ans;
    while(y){
        if(y&1)ans = (ans*x)%MOD;
        x = x*x%MOD;
        y >>= 1;
    }
    return ans;
}
int get(int x){
    ll ans = 1;
    add(x, -1);
    for(int i = 0; i < pcnt; ++i){
        if(prime[i] > x) break;
        ans = ans*ret(prime[i], num[i])%MOD;
    }
    add(x,1);
    return ans;
}
struct Node{
    int q, id;
    bool operator < (const Node& rhs)const{
        return q < rhs.q;
    }
}q[600];
int ans[600];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    memset(head,-1,sizeof head);
    getprime();

    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; ++i){
        scanf("%d", &q[i].q);
        q[i].id = i;
    }
    sort(q,q+t);
    int now = 0;
    //prln(t);
    for(int i = 0; i < t; ++i){
        //prln(now);
        while(now <= q[i].q) {
            now++;
            update(now);
        }
        ans[q[i].id] = get(now);
    }
    for(int i = 0; i < t; ++i){
        printf("%d\n",ans[i]);
    }
	return 0;
}
