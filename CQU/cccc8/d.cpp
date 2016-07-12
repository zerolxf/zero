#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>

using namespace std;
const int maxn = 1e7+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int a[maxn];
queue<int> b, c;
int main(){
#ifdef LOCAL
   // freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    int cnta = 0;
    int maxb = (ll)1031926999/2;
    int maxc = (ll)1031926999/3;
    a[cnta] = 1;
    b.push(a[cnta]);
    c.push(a[cnta++]);
    int bx, cx;
    while(cnta <= 1e7){
        bx = b.front();
        cx = c.front();
        if(bx*2+1<=cx*3+1){
            b.pop();
            if(bx*2+1==a[cnta-1]) continue;
            a[cnta++] = bx*2+1;
            if(a[cnta-1]<=maxc)
            c.push(a[cnta-1]);
            if(a[cnta-1]<=maxb)
            b.push(a[cnta-1]);
        }else{
            c.pop();
            if(cx*3+1==a[cnta-1]) continue;
            a[cnta++] = cx*3+1;
            if(a[cnta-1]<=maxc)
            c.push(a[cnta-1]);
            if(a[cnta-1]<=maxb)
            b.push(a[cnta-1]);
        }
    }
    ll num = 1e7;
    int n;
    while(scanf("%d", &n) != EOF){
        printf("%d\n",a[n-1]);
    }
    return 0;
}
