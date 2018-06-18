
/*
* @author:  liangxianfeng
* @mail: liangxianfeng96@qq.com
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define repp(i,n,x) for(int i =x; i < n+x; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) //cout << #x << " = " << x << " ";
#define prln(x) //cout << #x << " = " << x <<  endl;
const int MOD = 1e9+7;
const int maxn = 6e5+100;
const int INF = 0x3f3f3f3f;
ll c[maxn], v[maxn], n, a, b;
typedef pair<int,int> P;
P node[maxn];
vector<P> vt[2];
struct Seg{
	int num[maxn], op, siz;
	void build(int rt, int l, int r){
		if(r<l) return ;
		pr(rt);pr(l);prln(r);
		if(l == r){
			num[rt] = vt[op][l-1].second;
			pr(op);pr(rt);prln(vt[op][l-1].second);
			return;
		}
		int mid = (l+r) >> 1;
		build(rt<<1, l, mid);
		build(rt<<1|1, mid+1, r);
		num[rt] = max(num[rt<<1], num[rt<<1|1]);
	}
	int query(int rt, int l, int r, int ql, int qr){
		pr(rt);pr(l);pr(r);pr(ql);prln(qr);
		if(r<l||qr<ql) return 0;
		if(ql <= l && r <= qr){
			return num[rt];
		}
		int mid = (l+r) >> 1;
		int ans = 0;
		if(mid >= ql) ans = max(ans, query(rt<<1, l, mid, ql, qr));
		if(mid < qr) ans = max(ans, query(rt<<1|1, mid+1, r, ql, qr));
		return ans;
	}
}seg[2];
int x[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    cin >> n >> a >> b;
    char op[10];
    rep(i,n){
    	cin >> v[i] >> c[i] >> op;
    	if(op[0] == 'C') vt[0].push_back(P(c[i], v[i]));
    	else vt[1].push_back(P(c[i], v[i]));
    }
    int siz0 = vt[0].size(), siz1 = vt[1].size();
    sort(vt[0].begin(), vt[0].end());
    sort(vt[1].begin(), vt[1].end());
    prln(siz0);prln(siz1);
    seg[0].siz = siz0, seg[0].op = 0;
    seg[1].siz = siz1, seg[1].op = 1;
    seg[0].build(1, 1, siz0);
    seg[1].build(1, 1, siz1);
    ll ans1 = -1, ans0 = -1;
    for(int i = 0; i < siz0; ++i){
    	if(vt[0][i].first<=a&&vt[0][i].second>=ans0) ans0 = vt[0][i].second;
    	x[i] = vt[0][i].first;
    }
    ll ans = 0;
    rep(i, siz0){
    	int left = a-x[i];
    	int pos = upper_bound(x, x+siz0, left) - x-1;
    	pos++;
    	if(pos<= 0) continue;
    	if( (i+1) <= pos){
            if(pos-1<1) continue;
    		ll l = seg[0].query(1, 1, siz0, 1, (i+1)-1);
    		ll r = seg[0].query(1, 1, siz0, (i+1)+1, pos);
    		ans = max(ans, max(l, r)+vt[0][i].second);
    	}else{
    	    if(pos<1) continue;
    		ll l = seg[0].query(1, 1, siz0, 1, pos);
    		ans = max(ans, l+vt[0][i].second);
    	}
    }
    prln(ans);
    for(int i = 0; i < siz1; ++i){
    	if(vt[1][i].first<=b&&vt[1][i].second>=ans1) ans1 = vt[1][i].second;
    	x[i] = vt[1][i].first;
    }
	rep(i, siz1){
    	int left = b-x[i];
    	int pos = upper_bound(x, x+siz1, left) - x-1;
    	pos++;
    	if(pos<= 0) continue;
    	if( (i+1) <= pos){
                if(pos-1<1) continue;
    		ll l = seg[1].query(1, 1, siz1, 1, (i+1)-1);
    		ll r = seg[1].query(1, 1, siz1, (i+1)+1, pos);
    		ans = max(ans, max(l, r)+vt[1][i].second);
    	}else{
    	     if(pos<1) continue;
    		ll l = seg[1].query(1, 1, siz1, 1, pos);
    		ans = max(ans, l+vt[1][i].second);
    	}
    }
    prln(ans);
    if(ans1!=-1&&ans0!=-1)
    ans = max(ans, ans1+ans0);
    cout << ans << "\n";
    return 0;
}
