/*************************************************************************
	> File Name: ii.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月17日 星期日 08时39分02秒
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
int num[maxn];
int cnt[maxn];
ll getans( int pos, int left){
    ll ans = 0;
    if(left == 0){
        for(int i = 0; i < pos; ++i){
            //pr(num[i]);
            cnt[num[i]]++;
            ans++;
        }
        //cout << "\n";
        return 1;
    }
    for(int i = 1; i <= left; ++i){
        num[pos++] = i;
        if(i<=left)
        ans += getans(pos,left-i);
        pos--;

    }
    return ans;
}
int main(){
#ifdef LOCAL
	//freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

    int n, ans;
    while(cin >> n ){
        memset(cnt, 0, sizeof cnt);
        memset(num, 0, sizeof num);
        ans = getans(0, n);
        prln(ans);
        ans = 0;
        ll cntnum = 0;
        for(int i = 1; i <= n; ++i){
            pr(i);prln(cnt[i]);
            cntnum += cnt[i];
            //prln(ans);
        }
        prln(cntnum);
        prln(cntnum/(n+1));

    }
	return 0;
}
