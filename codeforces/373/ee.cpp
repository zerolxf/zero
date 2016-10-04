/*************************************************************************
    > File Name: ee.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月23日 星期五 22时31分01秒
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
const int maxn = 1e9+100;
const int INF = 0x3f3f3f3f;
int last[maxn];
const int MOD = 1e9+7;
typedef pair<int,int> P;
map<P,int> st;
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

    ll a = 1, b = 1;
    ll c= 0;
    for(int i = 1; i < maxn; ++i){
        c = a+b;
        if(c>MOD) c-= MOD;
        if(st.count(P(a,b))) {
            printf("%d\n",i-st[P(a,b)]);
            break;
        }
        st[P(a,b)] = i;
        a = b;
        b = c;
    }
	return 0;
}
