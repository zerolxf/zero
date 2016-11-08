/*************************************************************************
	> File Name: c.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月29日 星期五 23时15分06秒
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
ll a[maxn], b[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, m;
    while(cin >> n >> m){
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            //scanf("%I64d", &a[i]);
        }
        for(int i = 0; i < m; ++i){
            cin >> b[i];
            //scanf("%I64d", &b[i]);
        }
        sort(a, a+n);
        sort(b, b+m);
        ll ans = 0;
        for(int i = 0; i < n; ++i){
            //prln(a[i]);
            int pos = lower_bound(b, b+m, a[i]) - b;
            ll need = 1e10;
            //pr(pos);
            if(pos) need = min(need, a[i]-b[pos-1]);
            //pr(need);
            //pr(pos);prln(b[pos]);
            //prln(b[pos-1]);
            if(pos!=m) need = min(need, b[pos]-a[i]);
            //pr(b[pos]);pr(a[i]);
            //prln(need);
            ans = max(need, ans);

        }
        cout << ans <<"\n";
    }

	return 0;
}
