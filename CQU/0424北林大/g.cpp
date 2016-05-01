/*************************************************************************
    > File Name: g.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月24日 星期日 15时09分52秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<string>
#include<cmath>
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
char s[1000];
char str[maxn];
int n, m, len;
unsigned long long hash1[1000][1000], hash2[1000][1000];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	while(cin >> n >> m){
		char ss[500];
		for(int i = 0; i < n; ++i){
			scanf("%s",ss);
			for(int j = 0; j < m; ++j){
				if(ss[j] >= 'A' && ss[j] <= 'Z') ss[j] = 'a' + ss[j] - 'A';
			}
			for(int j = 0; j < m; ++j){
				s[i*m+j] = ss[j] - 'a';
			}
		}
		s[m*n] = ss[m];
		scanf("%s", str);
		int len = strlen(str);
		for(int i = 0; i < len; ++i){
			if(str[i] >= 'A' && str[i] <= 'Z') str[i] = str[i] - 'A';
			else str[i] = str[i] - 'a';
		}
		int len1 = n*m;
		if(len1 < len) {
			printf("NO\n");
			continue;
		}
		bool ok = false;
		rep(i,len1+10) rep(j,len1+10) hash1[i][i] = hash2[i][i] = s[i];
		for(int i = 2; i <= len; ++i){
			for(int j = 0; j + i -1 < len1; ++j){
				hash1[j][j+i-1] = hash1[j][j+i-2]*31 + s[j+i-1];
				hash2[j][j+i-1] = hash2[j][j+i-2]*37 + s[j+i-1];
			}
		}
		unsigned long long x = 0, y = 0;
		for(int i = 0; i < len; ++i){
			x = x*31 + str[i];
			y = y*37 + str[i];
		}
		for(int i = 0; i < len1-len+1; ++i){
			if(hash1[i][i+len-1] == x && hash2[i][i+len-1] == y){
				bool fd = true;
				for(int j = 0; j < len; ++j){
					if(s[i+j] != str[j]){
						fd = false;
						continue;
					}
				}
				if(fd){
					ok = true;
					continue;
				}
			}
		}
		if(ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
