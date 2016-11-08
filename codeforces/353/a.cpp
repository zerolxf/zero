/*************************************************************************
	> File Name: a.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月17日 星期二 00时31分16秒
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

int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

    //scanf printf
    ll a, b, c;
    cin >> a >> b >> c;
    if(c<0){
        c = -c;
        swap(a,b);
    }
    if(c==0){
        if(a==b) printf("YES\n");
        else printf("NO\n");
    }else {
        if((b-a)<0 || (b-a)%c!=0) printf("NO\n");
        else printf("YES");
    }
        return 0;
    if((b-a)*c>=0 && (c==0 || (b-a)%c==0)) printf("YES\n");
    else printf("NO\n");
	return 0;
}
