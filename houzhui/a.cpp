/*************************************************************************
    > File Name: a.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年01月28日 星期四 19时32分34秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn = 4e4+100;
const int x = 123;
int n, m, pos;
unsigned long long hash[maxn], xp[maxn], H[maxn];
int rank[maxn];
int cmp(const int& a, const int& b){
	return hash[a] < hash[b] || (hash[a]==hash[b]&&a<b);
}
int possible(int L) {
	int c= 0;
	pos = -1;
	for(int i = 0; i < n-L+1; ++i) {
		rank[i] = i;
		hash[i] = H[i] - H[i+L]*xp[L];
	}
	sort(rank,rank+n-L+1,cmp);
	for(int i = 0; i < n-L+1; ++i) {
		if(i==0 || hash[rank[i]] != hash[rank[i-1]]) c= 0;
		if(++c >= m) pos = max(pos,rank[i]);
	}
	return pos >= 0;
}

int main(){
	char s[maxn];
	while(scanf("%d", &m)==1 && m) {
		scanf("%s",s);
		n = strlen(s);
		H[n] = 0;
		for(int i = n-1; i >= 0; --i) H[i] = H[i+1]*x + (s[i]-'a');
		xp[0] = 1;
		for(int i = 1; i <= n; ++i) xp[i] = xp[i-1]*x;
		if(!possible(1)) printf("none\n");
		else {
			int l = 1, r = n, mid;
			while(l < r) {
				mid = (l+r+1)>>1;
				if(possible(mid)) {
					l = mid;
				} else r = mid-1;
			}
			possible(l);
			printf("%d %d\n",l,pos);
		}
	}
	return 0;
}
