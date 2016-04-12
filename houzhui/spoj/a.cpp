/*************************************************************************
    > File Name: a.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年01月29日 星期五 14时51分11秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#define ll long long
#define rep(i,n) for(int i = 0; i < n; ++i)
using namespace std;
const int maxn = 2e5+100;
char s[maxn];
int rk[maxn], sa[maxn], height[maxn], w[maxn], res[maxn], wa[maxn];
void getSa(int len, int up) {
	int *k = rk, *r = res, *id = height, *cnt = wa;
	rep(i,up) cnt[i] = 0;
	rep(i,len) cnt[k[i]=w[i]]++;
	rep(i,up) cnt[i+1] += cnt[i];
	for(int i = len-1; i >= 0; --i){
		sa[--cnt[k[i]]] = i;
	}
	int d = 1, p = 0;
	while(p < len){
		for(int i = len-d; i<len; ++i){
			id[p++] = i;
		}
		rep(i,len) if(sa[i] >= d) id[p++] = sa[i]-d;
		rep(i,len) r[i] = k[id[i]];
		rep(i,up) cnt[i] = 0;
		rep(i,len)	cnt[r[i]]++;
		rep(i,up) cnt[i+1] += cnt[i];
		for(int i = len-1; i>=0; --i){
			sa[--cnt[r[i]]] = id[i];
		}
		swap(k,r);
		p = 0;
		k[sa[0]] = p++;
		rep(i,len-1){
			if(sa[i]+d<len&&sa[i+1]+d<len&&r[sa[i]]==r[sa[i+1]]&&r[sa[i]+d]==r[sa[i+1]+d]) k[sa[i+1]] = p-1;
			else k[sa[i+1]] = p++;
		}
		if(p >= len) return ;
		d *=2; up = p; p = 0;
	}
}
void getHeight(int len){
	rep(i,len) rk[sa[i]] = i;
	height[0] = 0;
	for(int i = 0, p = 0; i <len-1; ++i){
		int j = sa[rk[i]-1];
		while(i+p<len&&j+p<len&&w[i+p]==w[j+p]) ++p;
		height[rk[i]] = p;
		p = max(p-1,0);		
	}
}
ll getSuffix(char s[]){
	int len =  strlen(s), up = 0;
	rep(i,len){
		w[i] = s[i];
		up = max(up,w[i]);
	}
	w[len++] = 0;
//	printf("%d\n",len);
	getSa(len,up+1);
//	printf("%d\n",len);
	getHeight(len);
	return len;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		scanf("%s",s);
		ll len = getSuffix(s)-1, ans;
		ans = len*(len+1)/2;
	//	printf("%lld\n",len);
		for(int i = 1; i <= len; ++i) ans -= height[i];
		printf("%lld\n",ans);
	}
}








































