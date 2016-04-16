/*************************************************************************
    > File Name: g.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年01月29日 星期五 13时28分17秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn = 1e6+100;
char s[maxn] ;
int fail[maxn], n, len;
void getFail(char *P, int *f){
	f[0] = 0; f[1] = 0;
	for(int i = 1; i < len; ++i){
		int j = f[i];
		while(j && P[i]!=P[j]) j = f[j];
		f[i+1] = P[i]==P[j]?j+1:0;
	}
}
int main(){
	while(scanf("%s",s) !=EOF){
		len = strlen(s);
		getFail(s,fail);
		int cir = len - fail[len];
		int ans = len/cir;
		printf("%d\n",ans);
	}
}
