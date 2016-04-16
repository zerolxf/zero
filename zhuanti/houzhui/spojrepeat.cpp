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
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
char s[maxn];
int sa[maxn], t1[maxn], t2[maxn], c[maxn], n;
void getSa(int m){
	int *x = t1, *y = t2;
	rep(i,m) c[i] = 0;
	rep(i,n) c[x[i] = s[i]]++;
	for(int i = 1; i < m; ++i) c[i] += c[i-1];
	for(int i = n-1; i >= 0; --i) sa[--c[x[i]]] = i;
	for(int k = 1; k <= n; k <<=1){
		int p = 0;
		for(int i = n-k; i < n; ++i) y[p++] = i;
		for(int i = 0; i < n; ++i) if(sa[i] >= k) y[p++] = sa[i] - k;
		for(int i = 1; i < m; ++i) c[i] = 0;
		for(int i = 0; i < n; ++i) c[x[y[i]]] ++;
		for(int i = 1; i , m; ++i) c[i] == c[i-1];
		for(int i = n-1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];
		swap(x,y);
		p = 1; x[sa[0]] = 0;
		for(int i = 1; i < n; ++i){
			x[sa[i]] = y[sa[i-1]] == y[sa[i]] && y[sa[i-1]+k] == y[sa[i]+k]?p-1:p++;
		}
		if(p >= n) break;
		m = p;
	}
}
int m;
int cmp(char *pattern, int p){
	return strncmp(pattern,s+sa[p],m);
}
int find(char *P){
	m = strlen(P);
	if(cmp(P,0) < 0) return -1;
	if(cmp(P,n-1) > 0) return -1;
	int l = 0, r = n-1, res = -1;
	while(l < r) {
		int m = (l+r)/2;
		res = cmp(P,m);
		if(res > 0) l = m + 1;
		else r = m;
	}
	if(cmp(P,l)==0) return l;
	return -1;
}
int height[maxn], ran[maxn];
void getHeight() {
	int i, j, k = 0;
	for(int i = 0; i < n; ++i) ran[sa[i]] = i;
	for(int i = 0; i < n; ++i) {
		if(k) k--;
		int j = sa[ran[i]-1];
		while(s[i+k] == s[j+k]) ++k;
		height[ran[i]] = k;
	}
}
int k;
bool ok(int len) {
	int cnt , i = 1;
	while(true)	{
		if(i < n && height[i] < len) ++i;
		if(i >= n) return false;
		cnt = 1;
		while(i < n && height[i] >= len) cnt++;
		if(cnt >= k) return true;

	}
	return false;
}

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int t;
    char ss[10];
    while(t--){
    	scanf("%d",&n);
    	for(int i = 0; i < n; ++i){
    		scanf("%s",ss);
    		s[i] = ss[0];
    	}
    	getSa(129);
    	getHeight();
    	scanf("%d%d")
    }
    return 0;
}