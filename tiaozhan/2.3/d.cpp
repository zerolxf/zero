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
    const int maxn = 1e3+100;
    const int INF = 0x3f3f3f3f;
    #define pr(x)       cout << #x << " = " << x << " ";
    #define prln(x)     cout << #x << " = " << x <<endl;
    #define ll long long
    ll dp[maxn][2];
    struct Node{
        int l, r, v;
        bool operator < (const Node& rhs)const{
            return r < rhs.r || (r == rhs.r && l > rhs.l) || (r==rhs.r&&l==rhs.l&&v>rhs.v);
        }
    }a[maxn], temp;
    int main(){
    #ifdef LOCAL
        freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
      //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
     #endif
        int n, m, R, l, r, v;
        while(scanf("%d%d%d", &n, &m, &R) != EOF) {
            for(int i = 0; i < m; ++i) {
                scanf("%d%d%d", &l, &r, &v);
                a[i] = Node{l, r+R, v};
            }
            sort(a, a+m);
            temp = Node{-1,-1,-1};
            for(int i = 0; i < m; ++i) {
                temp.r = a[i].l;
                int pos = upper_bound(a,a+m,temp) - a - 1;
                dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
                if(pos < 0) dp[i][1] = a[i].v;
                else dp[i][1] = max(dp[pos][0],dp[pos][1]) + a[i].v;
            }
            ll ans = max(dp[m-1][0], dp[m-1][1]);
            printf("%lld\n", ans);
        }
        return 0;
    }
