/*************************************************************************
    > File Name: f.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年01月29日 星期五 00时35分17秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn = 1e6 + 100;
char s[maxn];
int fail[maxn], n;
void getFail(char *P, int *f){
//	int n = strlen(P);
	f[0] = 0;f[1] = 0;
	for(int i = 1; i < n; ++i){
		int j = f[i];
		while(j && P[j]!=P[i]) j = fail[j];
		f[i+1]=P[i]==P[j]?j+1:0;
	}
}
int main(){
	int  ans;
	while(scanf("%s",s) != EOF){
		n = strlen(s);
		getFail(s,fail);
		ans = 0;
		for(int i = 1; i <= n; ++i){
			ans = max(ans,i-fail[i]);
		}
		printf("%d\n",ans);
	}
}
