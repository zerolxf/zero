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
const int maxn = 2e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x)      // cout  << #x << " = " << x << " ";
#define prln(x)    // cout <<"\n"<< #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int a[maxn], b[maxn], n;
struct Node
{
	int op, num;
};
std::vector<Node> ans;
void getl(int pos) {
	int temp;
	ans.clear();
	if(pos > 1) ans.push_back(Node{2,pos-1});
	for(int i = 1; i <= n; ++i){
		temp = (pos+i-1)%(n);
		if(temp==0) temp = n;
		b[i] = a[temp];
	}
	for(int i = 1; i <= n; ++i) a[i] = b[i];
}
void fuck(int pos) {
	ans.push_back(Node{1,pos});
	swap(a[pos],a[pos+3]);
	swap(a[pos+1],a[pos+2]);
}
bool gao(int pos1, int pos2) {
	if(pos2 < pos1) return false;
	if(pos2 == pos1) return true;
	if(pos2 == pos1+1 ){
		if(n < pos2+3) return false;
		fuck(pos1);fuck(pos2);fuck(pos1);
		return true;
	}
	if(pos2 == pos1+2) {
		if(n < pos2+2) return false;
		fuck(pos1+1);fuck(pos1);
		return true;
	}
	if(pos2 == pos1+3) {
		fuck(pos1);
		return true;
	}
	return false;
}
bool work(int pos1, int pos2) {
	if(pos2==pos1) return true;
	if(pos2 < pos1) return false;
	while(pos2 > pos1+3) {
		gao(pos2-3,pos2);
		pos2 -= 3;
		//ans.push_back(Node{1,pos2})
	}
	return gao(pos1,pos2);
}
int dis[maxn];
Node step[maxn];
int num[100], c[100];
void geta(int x) {
	for(int i = 1; i <= n; ++i){
		num[i] = x%10;
		pr(num[i]);
		x /= 10;
	}
}

int cao1(int pos) {
	for(int i = 1; i <= n; ++i) c[i] = num[i];
	int pos1 = pos1+1,pos2=pos+2,pos3=pos+3;
	if(pos1 > n) pos1 -= n;
	if(pos2 > n) pos2 -= n;
	if(pos3 > n) pos3 -= n;
	swap(c[pos],c[pos3]);
	swap(c[pos1],c[pos2]);
	int x = 0;
	//prln(x);
	for(int i = n; i > 0; --i){
		x = x*10+c[i];
		//pr(c[i]);
	}
	prln("");
	return x;
}
int cao2(int pos) {
	int x;
	for(int i = 1; i <= n; ++i) {
		x = pos+i;
		if(x > n) x-= n;
		c[i] = num[x];
	}
	x = 0;
	for(int i = n; i > 0; --i){
		x = x*10+c[i];
	}
	return x;
}
int last[maxn];

void bfs(int x) {
	ll sum = 0;
	ans.clear();
	prln(x);
	for(int i = n;i>0;--i) {
		sum = sum*10+i;
	}
	for(int i = 0; i <= 5000; ++i) {
		dis[i] = INF;
		last[i] = INF;
	}
	dis[sum] = 0;
	queue<int> q;
	q.push(sum);
	pr(sum);
	while(q.size()) {
		int u = q.front();q.pop();
		geta(u);
		//prln("");
		prln(u);
		for(int i = 1; i <= n; ++i) {
			int v = cao1(i);
			pr(v);
			if(dis[v]==INF) {
				step[v]=Node{1,i};
				dis[v] = dis[u]+1;
				last[v] = u;
				q.push(v);
			}
			v = cao2(i);
			pr(v);
			if(dis[v]==INF) {
				step[v]=Node{2,i};
				dis[v] = dis[u]+1;
				last[v] = u;
				q.push(v);
			}
		}
	}
	printf("%d\n", dis[x]);
	prln(dis[x]);
	while(dis[x] != 0){
		pr(x);prln(last[x]);
		printf("%d %d\n", step[x].op,step[x].num);
		x = last[x];
	}
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    while(cin >> n) {
    	n*=2;
    	bool ok = true;
    	ans.clear();
    	int pos = 0;
    	for(int i = 1; i <= n; ++i) cin >> a[i];
    	if(n <= 4) {
    		int s= 0;
    		for(int i = n; i>0;--i){
    			s = s*10+a[i];
    		}
    		bfs(s);
    		continue;
    	}
    	for(int i = 1; i <= n; ++i) {
    		for(int j = i; j <= n; ++j) {
    			if(a[j]==i) {
    				pos = j;
    			}
    		}
    		if(!work(i,pos)) ok = false;
    		if(!ok) break;
    	}
    	if(ok) {
    		printf("%d\n", ans.size());
    		for(int i = 0; i < ans.size(); ++i){
    			printf("%d %d\n", ans[i].op,ans[i].num);
    		}
    	} else{
	    		ok = true;
	    		ans.clear();
	    		for(int i = 1; i <= n; ++i) {
		    		if(a[i]==1) {
		    			getl(i);
		    			break;
		    		}
	    		}
		    	for(int i = 1; i <= n; ++i) {
		    		for(int j = i; j <= n; ++j) {
		    			if(a[j]==i) {
		    				pos = j;
		    			}
		    		}
		    		if(!work(i,pos)) ok = false;
		    		if(!ok) break;
		    	}
		    	if(ok) {
		    		printf("%d\n", ans.size());
		    		for(int i = 0; i < ans.size(); ++i){
		    			printf("%d %d\n", ans[i].op,ans[i].num);
		    		}
		    	}
    		}
    }
    return 0;
}