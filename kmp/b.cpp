/*************************************************************************
    > File Name: b.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年01月28日 星期四 20时16分53秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn = 1e6+100;
char T[maxn], W[maxn], s[maxn];
int fail[maxn];
void getFail(char *P, int *f) {
	int m = strlen(P);
	f[0] = 0; f[1] = 0;
	for(int i = 1; i < m; ++i){
		int j = f[i];
		while(j && P[i] != P[j]) j = fail[j];
		f[i+1] = P[i]==P[j]?j+1:0;
	}
}
void find(char *T, char *P, int *f) {
	int n = strlen(T), m = strlen(P);
	getFail(P,f);
	int j = 0;
	int ans = 0;
	for(int i = 0; i < n; ++i){
		while(j&& T[i] != P[j]) j = fail[j];
		if(T[i]==P[j]) ++j;
		if(j==m) {
			ans++;
			j = fail[j];
		}
	}
	printf("%d\n",ans);
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%s",W);
		scanf("%s",T);
		find(T,W,fail);
	}
	return 0;
}
