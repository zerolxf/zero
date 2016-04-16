/*************************************************************************
    > File Name: e.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年01月29日 星期五 00时20分04秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>

using namespace std;
const int maxn  = 1e6+100;
char s[maxn];
int fail[maxn];
void getFail(char *P, int *f){
	int m  = strlen(P);
	f[0] = 0; f[1] = 0;
	for(int i = 1; i < m; ++i){
		int j  = f[i];
		while(j && P[j] != P[i]) j = f[j];
		f[i+1] = P[i]==P[j]?j+1:0;
	}
}
int main(){
	int t, n, kase = 0;
	while(scanf("%d",&n) != EOF &&  n){
		scanf("%s",s);
		getFail(s,fail);
		printf("Test case #%d\n",++kase);
		for(int i = 2; i <= n; ++i) {
			int cir = i - fail[i];
			if(cir != i && i%cir==0) {
				printf("%d %d\n",i, i/cir);
			}
		}
		printf("\n");
	}
	return 0;
}
