/*************************************************************************
    > File Name: b.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月01日 星期六 23时30分03秒
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
char s[] = "aeiouy";
int a[maxn], b[maxn];
string ss;
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    cin>>n;
    rep(i,n){
        scanf("%d", &a[i]);
    }
    getchar();
    rep(i,n){
        getline(cin, ss);
        //prln(ss);
        int len = ss.size();
        int temp = 0;
        for(int j = 0; j < len; ++j){
            for(int l = 0; l < 6; ++l){
                if(ss[j] == s[l]) temp++;
            }
        }
        b[i] = temp;
    }
    sort(b, b+n);
    sort(a, a+n);
    bool ok = true;
    rep(i,n){
        if(b[i] != a[i]) ok = false;
    }
    if(ok) printf("YES\n");
    else printf("NO\n");



	return 0;
}
