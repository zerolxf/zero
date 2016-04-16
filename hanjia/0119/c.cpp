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
	int x1,y1,x2,y2;
}a[maxn],b[maxn];
int d[10];
inline void getx(int& lx, int& rx,int i, int j){
	d[0] = a[i].x1;
	d[1] = a[i].x2;
	d[2] = a[j].x1;
	d[3] = a[j].x2;
	sort(d,d+4);
	lx = d[1];rx=d[2];
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif	
    int n, cntr, cntc;
    while(cin >> n && n){
    	int x1,x2,y1,y2,miy,may;
    	cntc = cntr = 0;
    	for(int i = 0; i < n; ++i) {
    		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    		if(x1>x2) swap(x1,x2);
    		if(y1>y2) swap(y1,y2);
    		if(x1==x2) b[cntc++] = Node{x1,y1,x2,y2};
    		else if(y1 == y2) a[cntr++] = Node{x1,y1,x2,y2};
    	}
    	ll ans = 0;
    	int lx,rx;
    	for(int i = 0; i < cntr; ++i) {
    		for(int j = i+1; j < cntr; ++j) {
    			int ret = 0;
    			int uy = max(a[i].y1,a[j].y1);
    			int dy = min(a[i].y1,a[j].y1);
    			if(uy==dy) continue;
    			if(a[i].x2 <= a[j].x1) continue;
    			lx = max(a[i].x1,a[j].x1);
    			rx = min(a[i].x2,a[j].x2);
    			if(lx >= rx) continue;
    			//getx(lx,rx,i,j);
    			for(int l = 0; l < cntc; ++l) {
    				if(b[l].y1 <= dy && b[l].y2 >= uy && b[l].x1 <= rx && b[l].x1 >= lx) {
    					ret++;
    				}
    			}
    			ans += ret*(ret-1)/2;
    		}
    	}
    	printf("%lld\n", ans);
    }
    return 0;
}