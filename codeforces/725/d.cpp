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
typedef pair<int,int> P;
P node[maxn];
map<ll,ll> mp;
int a[maxn], b[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    int n;
    while(cin>>n){
        mp.clear();
        rep(i,n){
            scanf("%I64d%I64d",&a[i],&b[i]);
        }
        int ans = 1;
        int cnt = 0;
        for(int i = 1; i < n; ++i){
            node[cnt++] = P(-a[i], b[i]);
        }
        ll last = a[0];
        sort(node,node+cnt);
        priority_queue<ll> pq;
        int num = 0;
        for(int i = 0; i < cnt; ++i){
            if(-node[i].first<=last){
                pq.push(-(node[i].second+1-node[i].first));
                num = i;
            }
        }
        int ans = num+1;
        while(pq.size() && num < cnt && last+node[num]>=0){

        }
        cout<<ans<<"\n";
    }

    return 0;
}
