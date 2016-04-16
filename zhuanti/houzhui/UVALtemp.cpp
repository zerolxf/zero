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
int rk[maxn], res[maxn], height[maxn], w[maxn], wa[maxn], sa[maxn];
void getSa(int len, int up){
	int *k = rk,*id = height, *r = res,*cnt=wa;
	rep(i,up) cnt[i] = 0;
	rep(i,len) cnt[k[i]=w[i]]++;
	rep(i,up) cnt[i+1] += cnt[i];
	for(int i = len-1; i >=0; --i){
		sa[--cnt[k[i]]] = i; 
	}
	int d = 1, p = 0;
	while(p < len) {
		for(int i = len-d; i < len;++i) id[p++] = i;
		rep(i,len) if(sa[i] >= d) id[p++] = sa[i]-d;
		rep(i,len) r[i] = k[id[i]];
		rep(i,up) cnt[i] = 0;
		rep(i,len) cnt[r[i]]++;
		rep(i,up) cnt[i+1] += cnt[i];
		for(int i = len-1; i >= 0; --i) {
			sa[--cnt[r[i]]] = id[i];
		}
		swap(k,r);
		p = 0;
		k[sa[0]] = p++;
		rep(i,len-1) {
			if(sa[i]+d < len && sa[i+1]+d <len &&r[sa[i]]==r[sa[i+1]]&&r[sa[i]+d]==r[sa[i+1]+d])
				k[sa[i+1]] = p-1;
			else	k[sa[i+1]] = p++;
		}
		if(p >= len) return;
		d*=2; up = p; p = 0;
	}
}
void getHeight(int len) {
	rep(i,len) rk[sa[i]] = i;
	height[0] = 0;
	for(int i = 0,p = 0; i < len-1; ++i){
		int j = sa[rk[i]-1];
		while(j + p < len && i + p < len && w[i+p]==w[j+p]) p++;
		height[rk[i]] = p;
		p = max(p-1,0);
	}
}
int getSuffix(char s[]) {
	int len = strlen(s), up = 0;
	rep(i,len) {
		w[i] = s[i]-'a';
		up = max(w[i],up);
	}
	w[len++] = 0;
	getSa(len,up+1);
	getHeight(len);
	return len;
}
int n, k;
int getans(int len) {
	int pos = 0, i = 2;
	while(true) {
		while(i <= n && height[i] < len) i++;
		if(i > n) return -1;
		int cnt = 1;
		while(i <= n&&height[i] >= len) {
			pos = max(pos,sa[i-1]);
			pos = max(pos,sa[i]);
			++i;
			cnt++;
		}
		if(cnt >= k) {
			return pos;
		}
		pos = 0;
	}
	return -1;
}
char s[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    while(cin >> k && k) {
    	scanf("%s",s);
    	n = strlen(s);
    	getSuffix(s);
    	int l = 1, r = n, mid = (l+r), pos = -1;
    	pos = getans(1);
    	if(pos==-1) {
    		printf("none\n");
    		continue;
    	}
    	while(l < r) {
    		mid = (l+r+1)>>1;
    		pos = getans(mid);
    		if(pos != -1) l = mid;
    		else r = mid-1;
    	} 
    	pos = getans(l);
    	printf("%d %d\n",l, pos);
    }
    return 0;
}












