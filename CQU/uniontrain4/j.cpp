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
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) //cout << #x << " = " << x << " ";
#define prln(x)// cout << #x << " = " << x <<  endl; 
const int maxn = 1e5+100;
const int INF = 0x3f3f3f3f;
#define ull unsigned long long
ull cntr[128], cntl[128];
int unit;
struct Node{
	int L, R, id;
	Node(){}
	Node(int _L, int _R, int _id){
		L = _L;
		R = _R;
		id = _id;
	}
	bool operator < (const Node &rhs)const{
		if(L/unit == rhs.L/unit) return R < rhs.R;
		return L/unit < rhs.L/unit;
	}
}node[maxn];
int n, m, num;
ull ans[maxn];
ull a[maxn], suma[maxn];
ull xorsum;
ull addR(ull x){
	ull sum = 0;
	xorsum = xorsum^x;
	for(int i = 0; i < 64; ++i){
		if((xorsum>>i) & 1){
			cntl[i]++;
		}
		if((x>>i)&1){
			cntr[i] = num - cntr[i] + 1;
		}
		sum = sum + ((cntr[i]) << i);
	}
	num++;
	return sum;
}
ull removeR(ull x){
	ull sum = 0;
	for(int i = 0; i < 64; ++i){
		sum += (cntr[i]) << i;
		if((xorsum>>i)&1){
			cntl[i]--;
		}
		if((x>>i)&1){
			cntr[i] = num - cntr[i];
		}
	}
	num--;
	xorsum = xorsum^x;
	return sum;
}
ull addL(ull x){
	ull sum = 0;
	xorsum = xorsum^x;
	for(int i = 0; i < 64; ++i){
		if(((xorsum)>>i) & 1){
			cntr[i]++;
		}
		if((x>>i)&1){
			cntl[i] = num - cntl[i] + 1;
		}
		sum += (cntl[i]) << i;
	}
	num++;
	return sum;
}
ull removeL(ull x){
	ull sum = 0;
	for(int i = 0; i < 64; ++i){
		sum += (cntl[i]) << i;
		if((xorsum>>i)&1){
			cntr[i]--;
		}
		if((x>>i)&1){
			cntl[i] = num - cntl[i];
		}
	}
	num--;
	xorsum = xorsum^x;
	return sum;
}
void get() {
	unit = sqrt(n+0.5);
	sort(node, node+m);
	ull sum = 0;
	memset(cntl, 0, sizeof cntl);
	memset(cntr, 0, sizeof cntr);
	num = 0;
	int L = 1, R = 0;
	xorsum = 0;
	for(int i = 0; i < m; ++i){
		while(R < node[i].R){
			sum = sum + addR(a[++R]);
		}
		while(R > node[i].R) {
			sum = sum - removeR(a[R--]);
		}
		while(L > node[i].L){
			sum = sum + addL(a[--L]);
		}
		while(L < node[i].L){
			sum = sum - removeL(a[L++]);
		}
		ans[node[i].id] += sum; 
	}
}
int main(){
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int t, l, r, id;
	int kase = 0;
	scanf("%d", &t);
	while(t--){
		//printf("kase = %d\n",++kase);
		scanf("%d%d", &n, &m);
		memset(ans, 0, sizeof ans);
		suma[0] = 0;
		for(int i = 1; i <= n; ++i){
			scanf("%llu", &a[i]);
			//suma[i] = suma[i-1] + a[i];
		}
		for(int i = 0; i < m; ++i){
			scanf("%d%d", &l, &r);
			node[i] = Node(l, r, i);
		//	ans[i] = ans[i] - (suma[r] - suma[l-1]);
		}
		get();
		for(int i = 0; i < m; ++i){
			printf("%llu\n", ans[i]);
		//	cout << ans[i] << "\n";
		}
	}
	return 0;
}
