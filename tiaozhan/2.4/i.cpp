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
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
struct Node{
	int l, r;
	bool operator < (const Node& rhs)const{
		return l > rhs.l || (l == rhs.l && r > rhs.r);
	}
}node[maxn];
bool vis[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n, t;
    scanf("%d", &t);
    while(t--) {
    	scanf("%d", &n);
    	for(int i = 0; i < n; ++i) {
    		scanf("%d%d", &node[i].l, &node[i].r);
    		vis[i] = 0;
    	}
    	sort(node, node+n);
    	int last = 0, num = INF, ans = 0, cnt = 0, st;
    	while(cnt < n) {
    		++ans;
    		num = INF;
    		st = last;
    		//prln(last);
    		last = 0;
    		for(int i = st; i < n; ++i) {
    			if(!vis[i]){
	    			if(num >= node[i].r) {
	    				num = node[i].r;
	    				++cnt;
	    				vis[i] = true;
	    			} else if(!last){
	    				last = i;
	    			}
    			}
    		}
		}    	
    	printf("%d\n", ans);
    }
    return 0;
}