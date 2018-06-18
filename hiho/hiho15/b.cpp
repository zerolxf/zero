
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
#define prln(x)// cout << #x << " = " << x <<  endl;
const int MOD = 1e9+7;
const int maxn = 1e5+100;
const int INF = 0x3f3f3f3f;
struct Node{
	ll pa,  sum;
	Node(){
		pa = 0, sum = 0;
	}
	Node(ll _pa,  ll _sum){
		pa = _pa, sum = _sum;
	}
	void add(Node& node){
		pa = node.pa;
		sum += node.sum;
	}
	
}node[maxn];
void find(int x){
	if(x==node[x].pa) return ;
	else{
		// pr(x);prln(node[x].pa);
		find(node[x].pa);
		node[x].add(node[node[x].pa]);
		pr(x);pr(node[x].pa);prln(node[x].sum);
	}
}
void unite(int x, int y, ll add){
	find(x);
	find(y);
	if(node[x].pa==node[y].pa) return;
	//x = node[x].pa, y = node[y].pa;
	pr(x);pr(y);pr(add);prln(node[x].sum+add-node[y].sum);
	pr(node[x].pa);prln(node[y].pa);
	node[node[x].pa] = Node(node[y].pa, -node[x].sum+add+node[y].sum);
}

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    
    int n, m, q;
    ll x, y, z;
    cin>>n>>m>>q;
    for(int i = 1; i <= n; ++i){
    	node[i] = Node(i, 0);
    }
    for(int i = 0; i < m; ++i){
    	scanf("%lld%lld%lld",&x,&y,&z);
    	pr(x);pr(y);prln(z);
    	unite(x, y, z);
    }
    for(int i = 0; i < q; ++i){
    	scanf("%lld%lld",&x,&y);
    	find(x);find(y);
    	if(node[x].pa != node[y].pa){
    		cout<<"-1\n";
    	}else{
    		pr(node[x].sum);prln(node[y].sum);
    		cout<<node[x].sum-node[y].sum<<"\n";
    	}
    }
    return 0;
}
