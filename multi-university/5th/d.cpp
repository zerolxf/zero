/*************************************************************************
	> File Name: d.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年08月03日 星期三 11时09分11秒
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
const double esp = 1e-12;
struct Node{
    ll x, y;
}node[maxn];
double vt[maxn];
const double pi = acos(-1);
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    ll x, y;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; ++i){
            scanf("%lld%lld", &x, &y);
            node[i] = Node{x, y};
        }
        ll cnta = 0, cntb = 0, cntv = 0;
        for(int i = 0; i < n; ++i){
            cntv = 0;
            for(int j = 0; j < n; ++j){
                if(i == j) continue;
                x = node[j].x-node[i].x, y = node[j].y-node[i].y;
                vt[cntv] = atan2(y, x);
                cntv++;
            }
            sort(vt, vt+cntv);
            int temp = cntv;
            for(int j = 0; j < cntv; ++j){
                vt[temp] = vt[j] + pi*2;
                temp++;
            }
            int l = 0, r = 0, rr = 0;
            int lb = 0;
            while(r < temp){
                if(l >= cntv) break;
                while(rr < temp && vt[rr] - vt[l] < pi){
                    rr++;
                }
                while(r < rr && (vt[r] - vt[l])*2 < pi){
                    r++;
                }
                while(lb < r && (vt[lb] - vt[l]) <= 0){
                    lb++;
                }
                cntb += rr-r;
                cnta += r-lb;
                l++;
            }
        }
        ll ans = (cnta-2*cntb)/3;
        printf("%lld\n", ans);

        
    }
	return 0;
}
