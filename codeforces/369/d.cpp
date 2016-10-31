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
const int maxn = 4e5+1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
const int MOD = 1e9+7;
int id[maxn];
int cnt;
ll ans;
int edgenum;
int head[maxn], nxt[maxn], to[maxn];
void addedge(int u, int v){

    nxt[edgenum] = head[u];
    to[edgenum] = v;
    head[u] = edgenum++;
}
ll ret(ll x, ll y){
    if(y==0) return 1;
    ll a = 1;
    while(y){
        if(y&1) a = a*x%MOD;
        x = x*x%MOD;
        y >>=1;
        //prln(y);
    }
    return a;
}
ll sum;
void dfs(int u, int fa,int rev){
    id[u] = id[fa]+1;
    for(int i = head[u]; ~i; i = nxt[i]){
        int v = to[i];
        if((i^1)==rev) continue;
        if(id[v]){
            ll temp = (id[u]-id[v]+1);
            if(temp<=0) continue;
            sum-=temp;
            temp = ret(2,temp)-2;
            temp = (temp%MOD+MOD)%MOD;
            ans = ans*temp%MOD;
            continue;
        }
        dfs(v, u, i);
    }
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    cnt = 0;
    edgenum = 0;
    sum = 0;
    memset(head,-1,sizeof head);
    int u, v, n;
    memset(id,0,sizeof id);
    ans = 1;
    id[0] = 0;
    while(cin>>n){
        rep(i,n){
            scanf("%d",&u);
            addedge(i+1,u);
            addedge(u,i+1);
        }
        sum=n;
        rep(i,n){
            if(id[i+1]==0){
                dfs(i+1,0,-1);
            }
        }
        ans = ans*ret(2,sum)%MOD;
    }
    cout<<ans<<"\n";
    return 0;
}
