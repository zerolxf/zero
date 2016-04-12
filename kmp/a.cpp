/*************************************************************************
    > File Name: a.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年01月28日 星期四 20时00分16秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
const int maxn = 1e6+100;
using namespace std;
//char s[maxn], a[maxn], b[maxn];
int a[maxn], b[maxn];
int fail[maxn];
int n, m;
void getFail(int *P, int *f) {
//	int m = strlen(P);
	f[0] = 0; f[1] = 0;
	for(int i = 1; i < m; ++i){
		int j = f[i];
		while(j&&P[i] != P[j]) j = fail[j];
		f[i+1] = P[i]==P[j]?j+1:0;
	}
}
void find(int *T, int* P, int *f) {
//	int n = strlen(T), m = strlen(P);
	getFail(P,f);
	int j = 0;
	for(int i = 0; i < n; ++i){
		while(j && T[i] != P[j]) j = fail[j];
		if(P[j]==T[i]) ++j;
		if(j == m) {
			printf("%d\n", i-m+2);
			return ;
		}
	}
	printf("-1\n");
	return ;
}
int main() {
	int t, x;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i){
			scanf("%d", &a[i]);
		}
		for(int i = 0; i < m; ++i){
			scanf("%d",&b[i]);
		}
		find(a,b,fail);
	}
	return 0;
}
