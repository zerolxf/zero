/*************************************************************************
    > File Name: c.cpp
    > Author: Zeroxf
    > Mail: 641587852@qq.com 
    > Created Time: 2016年04月30日 星期六 16时55分27秒
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
ll a[maxn*2], b[maxn];
ll last[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
	a[1] = 1;a[2] = 2;
	int pos = 2, p = 2;
	b[1] = 1, b[0] = 0;
	while(p < maxn){
		if(p+a[pos]>maxn) break;
		for(int i = p; i < p+a[pos];++i){
			a[i] = pos;
			b[i] = b[i-1] + b[i-2];
		}
		p = p+a[pos];
		last[pos] = p-1;
		pos++;
	}
	for(int i = 2; i < 40; ++i){
		pr(i);pr(last[i]);
//		pr(b[i]);
		pr(last[last[i]]);
		pr(last[last[i]]-last[last[i-1]]);
		pr(i*i);
		prln(i*i*i);
	}
	return 0;
}
