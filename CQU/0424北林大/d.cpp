/*************************************************************************
    > File Name: d.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月24日 星期日 16时52分24秒
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
unsigned long long a[20][100][100], b[20][100][100];
int m, n, l0, r0;
int ql, qr;
char s[20][100];
bool cmp(int c, int d, int ii) {
	bool ok = true;
	int e = r0-l0+1;
	for(int i = 0; i < e; ++i){
		if(s[ii][c+i] != s[0][l0+i]){
			ok = false;
			break;
		}
	}
	return ok;
}
bool getlen(unsigned long long aa, unsigned long long bb, int len) {
	bool ok = true;
	for(int i = 0; i < n; ++i){
		bool fd = false;
		for(int j = 0; j + len -1 < 60; ++j){
			if(a[i][j][j+len-1] == aa && b[i][j][j+len-1] == bb){
			if(!cmp(j,j+len-1, i)) continue;
				fd = true;
				break;
			}
		}
		if(!fd){
			ok = false;
			break;
		}
	}
	return ok;
}
bool ok(int len) {
	bool fd = false;
	for(int i = 0; i+len-1 < 60; ++i){
		l0 = i; r0 = i+len-1;
		if(getlen(a[0][i][i+len-1], b[0][i][i+len-1], len)) {
			ql = i; qr = i+len-1;
			fd = true;
			break;
		}
	}
	return fd;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	while(cin >> n) {
		for(int i = 0; i < n; ++i){
			scanf("%s",s[i]);
			for(int j = 0; j < 60; ++j){
				s[i][j] -= 'A';
				a[i][j][j] = s[i][j];
				b[i][j][j] = s[i][j];
			}
		}
		for(int i = 0; i < n; ++i){
			for(int j = 2; j <= 60; ++j){
				for(int k = 0; k + j -1 < 60; ++k){
					a[i][k][k+j-1] = a[i][k][k+j-2]*31 + s[i][k+j-1];
					b[i][k][k+j-1] = b[i][k][k+j-2]*37 + s[i][k+j-1];
				}
			}
		}
		int l = 1, r = 60, mid;
		if(!ok(3)) {
			printf("No significant commonalities\n");
			continue;
		}
		while(l < r) {
			int mid = (l+r+1)/2;
			if(ok(mid)) l = mid;
			else r = mid-1;
		}
		vector<string> ans;
		if(l < 3){
			printf("No significant commonalities\n");
		} else {
			int lenn = qr - ql+1;
			for(int i = 0; i + lenn-1 < 60; ++i){
				if(getlen(a[0][i][i+lenn-1],b[0][i][i+lenn-1],lenn)){
					char temp[100];
					for(int p = i; p <= i+lenn-1; ++p){
						temp[p-i] = s[0][p] + 'A';
					}
					temp[i+lenn] = '\0'; 
					ans.push_back(temp);
				}
			}
			sort(ans.begin(), ans.end());
			cout << ans[0] << "\n";
			continue;
			for(int i = ql; i <= qr; ++i){
				printf("%c",s[0][i]+'A');
			}
			printf("\n");
		}

	}
	return 0;
}
