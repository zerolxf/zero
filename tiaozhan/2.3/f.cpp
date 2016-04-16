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
const int maxn = 2e6+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
int vis[maxn];
int v[maxn], num[maxn];

inline bool scan_d(int &ret) {
   char c; int sgn;
   if(c=getchar(),c==EOF) return 0; //EOF
   while(c!='-'&&(c<'0'|c>'9')) c=getchar();
   sgn=(c=='-')?-1:1;
   ret=(c=='-')?0:(c-'0');
   while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
   ret*=sgn;
   return 1;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
#endif
    int n, m, kase = 0;
    while(scanf("%d%d", &n, &m) != EOF && (n||m)) {
        for(int i = 0; i < n; ++i) scan_d(v[i]);
        for(int i = 0; i < n; ++i) scan_d(num[i]);
        vis[0] = 1;
        int a,l,av,ans=0;
        for(int i = 0; i < n; ++i) {
            a = 1;
            while(a <= num[i]) {
                av = a*v[i];
                l = m-av;
                while(l>=0)
                {
                   vis[l+av] |= vis[l];
                    l--;
                }
                num[i] -= a;
                a = a<<1;
            }
            if(num[i] > 0) {
                a = num[i];
                av = a*v[i];
                l = m-av;
                while(l>=0)
                {
                   vis[l+av] |= vis[l];
                    l--;
                }
            }
        }
        int *p = vis;
        while(m--) {
            p++;
            if(*p) ++ans,*p=0;
        }
        printf("%d\n", ans);
    }
    return 0;
}
