/*************************************************************************
    > File Name: f.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月07日 星期日 11时10分56秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
int last, a[maxn], b[maxn], n;
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(cin >> n >> last){
        rep(i,n) cin>>a[i+1]>>b[i+1];
        bool ok = true;
        for(int i = n; i; --i){
            if(last == a[i]||last==b[i]||a[i]==7-last||b[i]==7-last){
                ok = false;
            }
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}
