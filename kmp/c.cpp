/*************************************************************************
    > File Name: c.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年01月28日 星期四 20时27分51秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int maxn = 1e6+100;
char T[maxn], W[maxn], s[maxn];
int fail[maxn];
void getFail(char *P, int *f){
	int m = strlen(P);
	f[0]= 0; f[1] = 0;
	for(int i = 1; i < m; ++i){
		int j = fail[i];
		while(j && P[i] != P[j]) j = f[j];
		f[i+1] = P[i]==P[j]?j+1:0;
	}
}
void find(char *T, char *P, int *f){
	int n = strlen(T), m = strlen(P);
	getFail(P,f);
	int cnt = 0, j = 0;
	for(int i = 0; i < n; ++i){
		while(j && T[i] != P[j]) j = f[j];
		if(T[i]==P[j]) ++j;
		if(j==m) {
			j = 0;cnt++;
		}
	}
	printf("%d\n",cnt);
}
int main() {
	while(scanf("%s%s",T,W)==2){
		find(T,W,fail);
	}
	return 0;
}
