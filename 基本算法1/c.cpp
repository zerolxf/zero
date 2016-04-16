#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
#include<vector>

using namespace std;
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
map<double,double> st;
map<double,int> ed;
double a[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    bool ok = true;
    int n, d, cnt = 0;
    double l, r, x, y;
    int kase = 0;
    while(scanf("%d%d", &n, &d) && (n*n+d*d != 0)) {
        cnt = 0;
        ok = true;
        st.clear();
        ed.clear();
        printf("Case %d: ", ++kase);
        for(int i = 0; i < n; ++i){
            scanf("%lf%lf",&x, &y);
            if(!ok) continue;
            if(y > d) {
                ok = false;
                continue;
            } else {
                l = x - sqrt(d*d - y*y);
                r = x + sqrt(d*d - y*y);
                if(st.count(l)) st[l] = min(st[l], r);
                else st[l] = r;
                ed[r] = 0;
                a[cnt++] = l;
                a[cnt++] = r;
            }
        }
        if(!ok) {
            cout << "-1\n";
            continue;
        }
        sort(a, a+cnt);
       // cnt = unique(a, a+cnt) - a;
        int ans = 0;
        double last = -1e10;
        for(int i = 0; i < cnt; ++i) {
            if(a[i] > last && st.count(a[i])) {
                last = st[a[i]];
                ed[st[a[i]]] = ans;
                ans++;
            } else if(a[i] <= last+eps && st.count(a[i])) {
                ed[st[a[i]]] = ans;
            }
            if(a[i] <= last+eps && ed.count(a[i])  && ed[a[i]]== ans) last = a[i];
        }
        cout << ans << '\n';
    }
    return 0;
}
