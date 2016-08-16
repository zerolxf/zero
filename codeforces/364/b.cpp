/*************************************************************************
	> File Name: b.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月23日 星期六 00时49分37秒
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
#define pr(x) //cout << #x << " = " << x << " ";
#define prln(x) //cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
ll cntr[maxn], cntc[maxn];
bool c[maxn];
bool r[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    ll n, m;
    while(cin >> n >> m){
        for(int i = 1; i <= n; ++i){
            cntr[i] = cntc[i] = n;
        }
        memset(r, 0, sizeof r);
        memset(c, 0, sizeof c);
        int x, y;
        int a = 0, b =0;
        ll last = n*n;
        for(int i = 0; i < m; ++i){
            scanf("%d%d", &x, &y);
            ll ans = 0;
            //prln(i);
            //pr(n);prln(m);
            if(a==n||b==n){
                 printf("0\n");
                 continue;
            }
            pr(a);prln(b);
            if(!r[x]){
                ans += n-b;
            }
            prln(ans);
            if(!c[y]){
                ans += n - a;
            }
            prln(n-a);
            prln(ans);
            if(!r[x]&&!c[y]){
                ans--;
            }
            prln(ans);
            if(!r[x]) a++;
            if(!c[y]) b++;
            prln(ans);
            r[x] = c[y] = 1;
            cout << last - ans << " ";
            last -= ans;
        }
        cout << "\n";
    }
	return 0;
}
