/*************************************************************************
    > File Name: d.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年01月28日 星期四 21时18分16秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int maxn = 1e6+100;
char s[maxn];
int fail[maxn];
void getFail(char *P, int *f){
	int n = strlen(P);
	f[0] = 0; f[1] = 0;
	for(int i = 1; i < n; ++i){
		int j = f[i];
		while(j && P[j]!= P[i]) j = f[j];
		f[i+1] = P[i]==P[j]?j+1:0;
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		int n = strlen(s);
		getFail(s,fail);
		int cir = n - fail[n], ans = 0;
		if(n%cir||cir==n) ans = cir - n%cir;
		printf("%d\n",ans);
	}
	return 0;
}
