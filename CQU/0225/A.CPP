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
const int maxn = 2e6+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
struct ma{
	int k, p;
	bool operator <(const ma& rhs)const{
		return p < rhs.p;
	}
};
struct mi{
	int k, p;
	bool operator <(const mi& rhs)const{
		return p > rhs.p;
	}
};
bool vis[maxn];

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int op, k, p, cnt;

    priority_queue<ma> qa;
    priority_queue<mi> qi;
    cnt = 0;
    while(scanf("%d",&op)!=EOF&&op) {
    	//prln(op);prln(cnt);
    	if(op == 1) {
    		scanf("%d%d",&k,&p);
    		qa.push(ma{k,p});
    		qi.push(mi{k,p});
    		vis[k] = false;
    		cnt ++;
    	} else if(cnt==0) {
    		printf("0\n");
    	} else {
    		--cnt;
    		if(op==2) {
    			ma x = qa.top();
    			qa.pop();
    			while(vis[x.k]) {
    				x = qa.top();
    				qa.pop();
    			}
    			vis[x.k] = true;
    			printf("%d\n", x.k);
    		} else {
    			mi x = qi.top();
    			qi.pop();
    			while(vis[x.k]) {
    				x = qi.top();
    				qi.pop();
    			}
    			vis[x.k] = true;
    			printf("%d\n", x.k);
    		}
    	}
    }
    return 0;
}