
#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<utility>
#include<sstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f;
const int maxn = 4000010;
const int MOD= 1e9+7;
#define pr(x) cout << #x <<" = " << x << " ";
#define prln(x) cout << #x <<" = " << x << "\n";
struct Node{
    ll x, y;
    bool operator < (const Node &rhs)const{
        return (x < rhs.x )||(x==rhs.x&&y<rhs.y);
    }
    bool operator== (const Node& rhs)const{
        return x==rhs.x&&y==rhs.y;
    }
}node[1005], hasha[1005];
ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}
struct Line{
    ll a, b, c, u, v;
    bool operator < (const Line& rhs)const{
        return (a<rhs.a)||(a==rhs.a&&b<rhs.b)||(a==rhs.a&&b == rhs.b&&c<rhs.c);
    }
    Line(){}
    Line(ll _a, ll _b, ll _c, ll _u, ll _v){
        a = _a;
        b = _b;
        c = _c;
        u = _u;
        v = _v;
    }
    void reduce(){
        ll temp = gcd(a, b);
        temp = gcd(temp, c);
        a /= temp; b /= temp; c /= temp;
        if(a < 0) {
            a = -a; b = -b; c = -c;
        }
    }
}line[maxn];
bool equal(const Line& x, const Line& rhs){
   // bool operator == (const Line& rhs)const{
        return x.a== rhs.a&&x.b==rhs.b&&x.c==rhs.c;
  //  }
}

bool cmp(const int& a,const int& b){
    return (line[a].a<line[b].a)||(line[a].a==line[b].a&&line[a].b<line[b].b)||(line[a].a==line[b].a&&line[a].b == line[b].b&&line[a].c<line[b].c);
}
ll cnt[1005], siz[1005];
int vis[1005], q[1005];
ll ret(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y&1) ans = ans*x%MOD;
        x = x*x%MOD;
        y >>= 1;
    }
    return ans;
}
int id[maxn];
int main()
{
    #ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
    #endif // LOCAL
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        memset(vis, 0, sizeof vis);
        memset(siz, 0, sizeof siz);
        memset(cnt, 0, sizeof cnt);
        int qcnt = 0;
       // cout<<n<<" ";
        for(int i = 0; i < n; ++i){
            scanf("%lld%lld", &node[i].x, &node[i].y);
            hasha[i] = node[i];
          //  cout<<node[i].x<<" ";
        }
        int cnta =0;
        sort(hasha, hasha+n);
      //  prln(n);
       cnta = unique(hasha, hasha+n)-hasha;
      // prln(cnta);
       int pos=0;
        for(int i = 0; i < n; ++i){
            pos = lower_bound(hasha, hasha+cnta, node[i]) - hasha;
            siz[pos]++;
        }
        int m = 0;
     //   cout <<n<<" "<<m;
    //  prln(cnta);
        for(int i = 0; i < cnta; ++i){
            Node &a = hasha[i];
            for(int j = i+1; j < cnta; ++j){
                Node &b = hasha[j];
                line[m] = Line(a.y-b.y,-(a.x-b.x),(b.y-a.y)*b.x - (b.x-a.x)*b.y, i, j);
                line[m].reduce();
                id[m] = m;
                m++;
            }
        }
        ll ans = 0;
        sort(id, id+m, cmp);
        //sort(line, line+m);
     //   prln(m);
        for(int i = 0; i < m; ++i){
            int r = i+1;
            qcnt = 0;
            while(r < m && equal(line[id[i]], line[id[r]])) ++r;
            ll scnt = 0;
            for(int j = i; j < r; ++j){
                int u = line[id[j]].u;


                if(vis[u] != i+1){
                    cnt[u]++;
                    scnt += siz[u];
                    vis[u] = i+1;
                }
                u = line[id[j]].v;
                 if(vis[u] != i+1){
                    cnt[u]++;
                    scnt += siz[u];
                    vis[u] = i+1;
                }
            }
             i = r-1;
           // pr(i);prln(scnt);
            ans = (ans + (ret(2,scnt) - 1 - scnt)%MOD+MOD)%MOD;
        }
        for(int i = 0; i < cnta; ++i){
            if(siz[i] < 2) continue;
            ans = (ans - (cnt[i]-1)*(ret(2, siz[i]) - 1 - siz[i]));
            ans = (ans%MOD+MOD)%MOD;
        }
        ans = (ans%MOD+MOD)%MOD;
        printf("%lld\n", ans);
    }
    return 0;
}
