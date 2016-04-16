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
const int maxn = 2e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x)     //  cout << #x << " = " << x << " ";
#define prln(x)    // cout << #x << " = " << x <<endl;
#define ll long long
int l[maxn], r[maxn], x[maxn], y[maxn], lpos[maxn], rpos[maxn];

struct Node{
    int l, r, v;
    bool operator > (const Node& rhs)const{
        return v > rhs.v;
    }
};

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n, d;
    while(scanf("%d%d", &n, &d)==2 ) {

        for(int i = 0; i < n; ++i) {
            scanf("%d%d", &x[i], &y[i]);
        }
        if(n==1) {
            printf("-1 -1\n");
            continue;
        }
        l[0] = y[0];lpos[0]=0;
        r[n-1] = y[n-1];rpos[n-1]=n-1;
        for(int i = 1; i < n; ++i) {
            if(y[i] > l[i-1]) {
                lpos[i] = i;
                l[i] = y[i];
            } else {
                lpos[i] = lpos[i-1];
                l[i] = l[i-1];
            }
        }
        for(int i = n-2; i>=0;--i) {
            if(y[i] > r[i+1]) {
                rpos[i] = i;
                r[i] = y[i];
            } else{
                rpos[i] = rpos[i+1];
                r[i] = r[i+1];
            }
        }
        //Node ans{-1,-1,0};
        int pos, ans = -1, ansl = -1, ansr = -1;
        for(int i = 0; i < n; ++i) {
            prln(i);pr(x[i]);prln(y[i]);
            pos = lower_bound(x,x+n,x[i]+d) - x;
            prln(pos);
            if(pos < n) {
                if(y[i]+r[pos] > ans) {
                    ansl = lpos[i]+1;
                    ansr = rpos[pos]+1;
                    ans = y[i]+r[pos];
                } 
            }
            pos = upper_bound(x,x+n,x[i]-d) - x - 1;
            prln(pos);
           // if(pos == i) --pos;
            if(pos >=0) {
                if(y[i]+l[pos] > ans) {
                    ans = y[i]+l[pos];
                    ansr = rpos[i]+1;
                    ansl = lpos[pos]+1;
                } 
            }
        }
        printf("%d %d\n", ansl, ansr);
    }
    return 0;
}