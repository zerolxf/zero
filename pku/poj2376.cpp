/*************************************************************************
    > File Name: b.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月29日 星期六 19时47分54秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define repp(i,n,x) for(int i =x; i < n+x; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define L first
#define R second
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl;
const int INF = 1e9+7;
const int maxn = 1e5+100;
typedef pair<int,int> P; 
P a[maxn];
class CMP{
public:
	bool operator()(const P& a, const P& b){
		return a.R < b.R;
	}
};

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
   	int n, t;
   	scanf("%d%d", &n, &t);
   	for(int i = 1; i <= n; ++i)	scanf("%d%d", &a[i].L, &a[i].R);
   	sort(a+1, a+n+1);
   	priority_queue<P, vector<P>, CMP > pq;
   	int r = 1, l = 0, pos = 1, ans = 0;
   	pq.push(P(0,0));
   	while(l < r && pos <= n && r <= t){
   		while(pos <= n && a[pos].L <= r) pq.push(a[pos++]);
   		l = r;
   		r = max(pq.top().R+1, r);
   		ans++;
   	}
   	if(r <= t) ans = -1;
   	cout << ans << "\n";
    return 0;
}
