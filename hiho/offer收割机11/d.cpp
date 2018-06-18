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
const int maxn = 4e6;
const int INF = 0x3f3f3f3f;
#define pr(x)     //  cout << #x << " = " << x << " ";
#define prln(x)    // cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int mp[maxn];
int unit;
struct Node{
    int l, r, id;
    bool operator < (const Node& rhs)const{
        if(l/unit==rhs.l/unit) return r < rhs.r;
        return l/unit < rhs.l/unit;
    }
}q[maxn];
ll num[maxn], qq[maxn], sum[maxn];
int n, m;
int aa[maxn], bit1[maxn], bit2[maxn], id[maxn], has[maxn], bb[maxn];
int N;

int bsize = 0;
void inithash(){
	sort(bb, bb+n);
	bsize = unique(bb,bb+n) - bb;
	N = bsize;
	for(int i = 0; i < n; ++i){
		has[i] = lower_bound(bb, bb+bsize, aa[i])-bb+1;
	}
}
void add1(int x, int y){

	for(int i = x; i <= N; i += i&(-i)){
		//prln(i);
		bit1[i] += y;
	}
}
int getsum1(int x){
	ll ans = 0;
	for(int i = x; i > 0; i -= i&(-i)){
		ans += bit1[i];
	}
	return ans;
}
void add2(int x, int y){
	for(int i = x; i <= N; i += i&(-i)){
		bit2[i] += y;
	}
}
int getsum2(int x){
	ll ans = 0;
	for(int i = x; i > 0; i -= i&(-i)){
		ans += bit2[i];
	}
	return ans;
}

void modui() {
    sort(q, q+m);
    int L = 0, R = 0;
    ll ans = 0;
    memset(bit1, 0, sizeof bit1);
    memset(bit2, 0, sizeof bit2);
    prln(N);
    for(int i = 0; i < m; ++i){
    	pr(L);prln(R);
        while(R < q[i].r) {
        	add1(has[R], 1);
            add2(has[R], aa[R]);
            int rnum = getsum1(N)-getsum1(has[R]-1);
            ans += (ll)(rnum)*aa[R];
            ans += (ll)(getsum2(has[R]-1));
            R++;
        }
        while(R > q[i].r) {
            R--;
            ans -= (ll)(getsum1(N)-getsum1(has[R]-1))*aa[R];
            ans -= (ll)(getsum2(has[R]-1));
            add1(has[R], -1);
            add2(has[R], -aa[R]);
        }
        while(L < q[i].l){
            ans -= (ll)(getsum1(N)-getsum1(has[L]))*aa[L];
            ans -= (ll)(getsum2(has[L]));
            add1(has[L], -1);
            add2(has[L], -aa[L]);
            L++;
        }
        while(L > q[i].l){
            L--;
            add1(has[L], 1);
            add2(has[L], aa[L]);
            ans += (ll)(getsum1(N)-getsum1(has[L]))*aa[L];
            ans += (ll)(getsum2(has[L]));
        }
        qq[q[i].id] = ans;
    }
}

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
   int t;
   cin >> t;
   while(t--){
   		cin >> n >> m;
   		N = n;
   		for(int i = 0; i < n; ++i){
   			cin >> aa[i];
   			bb[i] = aa[i];
   		}
   		inithash();
   		unit = sqrt(n);
   		for(int i = 0; i < m; ++i){
            scanf("%d%d", &q[i].l, &q[i].r);
            q[i].l--;
            q[i].id = i;
        }
        modui();
        for(int i = 0; i < m; ++i){
            printf("%lld\n", qq[i]);
        }
   }
    return 0;
}
