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
int dis[maxn], v[maxn], L, P;
struct Node{
	int dis,v;
	bool operator < (const Node& rhs)const{
		return dis > rhs.dis;
	}
}node[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    priority_queue<int> q;
    int n;
    bool ok = true;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
    	scanf("%d%d", &node[i].dis, &node[i].v);
    }
    sort(node,node+n);
    scanf("%d%d", &L, &P);
    int ndis = L, cnt = 0, last = P, ans = 0;
    while(cnt < n) {
    	last = last - (ndis - node[cnt].dis);
    	ndis = node[cnt].dis;
    	while(last < 0 && q.size()) {
    		last += q.top();q.pop();
    		++ans;
    	}
    	if(last < 0) {
    		ok = false;
    		break;
    	}
    	q.push(node[cnt].v);
    	cnt++;
    }
    last -= ndis;
    if(ok)
    while(last < 0 && q.size()) {
    		//prln(q.top());
    		last += q.top();q.pop();
    		++ans;
    	}
    if(!ok || last < 0) printf("-1\n");
    else printf("%d\n", ans);
    return 0;
}