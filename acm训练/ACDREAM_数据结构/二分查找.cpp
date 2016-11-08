
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
#include<set>
using namespace std;
const int maxn = 1e5+100;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
struct node{
    int v, c, id;
    bool operator< (const node& rhs)const{
        return v > rhs.v;
    }
}A[maxn], B[maxn];
int n, m, l, ans[maxn];
typedef pair<int,int> P;
bool check(int x) {
    set<P> s;
    int cost = 0;
    for(int i = 1, j =1; i <= m;) {
        while(j<= n &&A[j].v>=B[i].v) s.insert(P(A[j].c, A[j].id)),j++;
        if(!s.size()) return false;
        cost += s.begin()->first;
        if(cost > l) return false;
        int t = x, id = s.begin()->second;
        s.erase(s.begin());
        while(t-- && i <= m) ans[B[i++].id] = id;
    }
    return true;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    while(cin >> n >> m >> l) {

        for(int i = 1; i <= n; ++i) scanf("%d", &A[i].v);
        for(int i = 1; i <= n; ++i) scanf("%d", &A[i].c), A[i].id = i;
        for(int i = 1; i <= m; ++i) scanf("%d", &B[i].v), B[i].id = i;
        sort(A+1, A+n+1);
        sort(B+1, B+m+1);
        int l = 0, r = 1e5;
        while(l <= r) {
            int t;
            t = l + r >> 1;
        //pr(t);
           if(check(t)) r = t-1;
           else l = t + 1;
        }
        if(check(l)){
            cout << "Good Luck\n";
            for(int i = 1; i <= m; ++i) {
                cout << ans[i] << (i == m?'\n':' ');
            }
        } else cout << "Do it yourself\n";
    }
    return 0;
}
