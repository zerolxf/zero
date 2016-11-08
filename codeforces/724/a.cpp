/*************************************************************************
    > File Name: a.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月08日 星期六 20时12分19秒
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
string s[] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
int c[] = {31, 30, 28};
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    string a, b;
    while(cin >> a >> b){
        int aa = 1, bb = 1;
        for(int i = 0; i < 7; ++i){
            if(a==s[i]) aa = i+1;
            if(b==s[i]) bb = i+1;
        }
        bool ok = false;
        for(int i = 0; i < 3; ++i){
            int cc = aa+c[i];
            cc%=7;
            if(cc==0) cc = 7;
            if(cc==bb) ok = true;
        }
        if(ok) printf("YES\n");
        else printf("NO\n");

    }

	return 0;
}
