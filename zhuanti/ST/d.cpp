/*************************************************************************
	> File Name: d.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月31日 星期日 14时56分34秒
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
const int maxn = 2e5+100;
const int INF = 0x3f3f3f3f;
struct Node{
    int mi, ma;
    Node(){
        mi = INF;
        ma = -INF;
    }
    Node(int _mi, int _ma){
        mi = _mi;
        ma = _ma;
    }
    void update(const Node& a,const Node& b){
        this->mi = min(a.mi, b.mi);
        this->ma = max(a.ma, b.ma);
    }
}dp[maxn][19];
int n;
int get(int l, int r){
    int k = 0;
    for(k = 0; (1<<(k+1)) <= (r-l+1); ++k);
    Node ans;
    ans.update(dp[l][k], dp[r-(1<<k)+1][k]);
    //pr(l);prln(r);pr(ans.mi);prln(ans.ma);
    if(ans.ma > ans.mi) return 1;
    else if(ans.ma < ans.mi) return -1;
    return 0;
}
int query(int st){
    if(get(st, st) > 0 || get(st, n) < 0) return 0;
    int l = st, r = n;
    int ansl = 0, ansr = 0;
    //prln("<<<<");
    while(l < r){
        int mid = (l+r) >> 1;
        if(get(st,mid) >= 0) r = mid;
        else l = mid+1;
    }
    ansl = l;
    l = st; r  = n;
    //prln(">>>>>");
    while(l < r){
        int mid = (l+r+1) >> 1;
        if(get(st,mid) <= 0) l = mid;
        else r = mid-1;
    }
    //prln("end");
    ansr = r;
    
    //pr(ansr);prln(ansl);
    return ansr-ansl+1;
}
void ST(){
    for(int j = 1; (1<<j) <= n; ++j){
        for(int i = 1; i +(1<<j)-1 <= n; ++i){
            dp[i][j].update(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
        }
    }
}
int a[maxn], b[maxn]; 
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(scanf("%d", &n) != EOF){
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; ++i){
            scanf("%d", &b[i]);
            dp[i][0].mi = b[i];
            dp[i][0].ma = a[i];
        }
        ST();
        ll ans = 0;
        for(int i = 1; i <= n; ++i){
            int temp = 0;
            temp = query(i);
            ans = ans + temp;
            //pr(i);prln(temp);
        }
        cout << ans << "\n";
    }
	return 0;
}
