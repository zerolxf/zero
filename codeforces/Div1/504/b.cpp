/*************************************************************************
    > File Name: b.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月29日 星期六 19时47分54秒
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
#include <ctime>


using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define repp(i,n,x) for(int i =x; i < n+x; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 2e5+100;
const int INF = 0x3f3f3f3f;
int n;
int c[maxn], d[maxn];
struct Con{
    int a[maxn], b[maxn];
    void add(int x, int v){
        for(int i = x; i <= n; i += i&(-i)) c[i] += v;
    }
    int sum(int x){
        int ans = 0;
        for(int i = x; i > 0; i -= i&(-i)) ans += c[i];
        return ans;
    }

    void init(){
        memset(c,0,sizeof c);
        for(int i = 1; i <= n; ++i){
            add(i,1);
        }
    }
    void getb(){
        for(int i = 1; i <= n; ++i){
            b[i] = sum(a[i])-1;
            add(a[i],-1);
        }
    }
    void read(){
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            a[i]++;
        }
    }
    int binaryquery(int k){
        int l = 1, r = n;
        while(l < r){
            int mid = (l+r) >> 1;
            if(sum(mid)>=k) r = mid;
            else l = mid+1;
        }
        return l;
    }
    void ready(){
        init();
        read();
        getb();
    }
    void RevCon(){
       for(int i = 1; i <= n; ++i){
            d[i] = binaryquery(b[i]+1);
            add(d[i],-1);
        }
    }
    void out(){
        for(int i = 1; i <= n; ++i){
            printf("%d ",d[i]-1);
        }
        printf("\n");
    }
    void solve(){
        init();
        RevCon();
        out();
    }
    void AddCon(const Con& s, const Con& t){
        for(int i = 1; i <= n; ++i){
            b[i] = s.b[i] + t.b[i];
        }
        for(int i = n; i > 0; --i){
            int ma = n-i+1;
            if(b[i] >= ma) b[i] -= ma, b[i-1]+=1;
            if(b[i] >= ma) b[i] -= ma, b[i-1]+=1;
        }
    }
}S, T, ST;

int a[maxn], b[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    cin >> n;
    S.ready();
    T.ready();
    ST.AddCon(S,T);
    ST.solve();
	return 0;
}
