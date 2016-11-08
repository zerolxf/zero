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
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
ll base[maxn], prime[maxn], pcnt, bcnt;
void getprime() {
    bool vis[maxn];
    pcnt = 0;bcnt = 0;
    base[bcnt++] = 1;
    for(int i = 2; i < maxn; ++i) {
        if(!vis[i]){
            prime[++pcnt] = i;
        }
        for(int j = i*i; j < maxn; j+=i) {
            vis[j] = true;
        }
    }
    ll a = 1;
    while(a < 3e9) {
        a *= prime[bcnt];
        base[bcnt++] = a;
    }
    for(int i = 1; i <= pcnt; ++i){
       // prln(i);prln(prime[i]);
    }
}
struct Node{
    ll a, p;
    bool operator < (const Node& rhs)const{
        return p < rhs.p;
    }
};
vector<Node> ans;
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    getprime();
    ll n;
    while(cin >> n && n) {
        ans.clear();
        printf("%lld = ",n);
        if(n == 1) {
            printf("1\n");
            continue;
        }
        while(n) {
            int pos = upper_bound(base,base+bcnt, n) - base - 1;
            ans.push_back(Node{n/base[pos], pos});
            n %= base[pos];
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size()-1; ++i) {
            if(ans[i].p) {
                printf("%lld",ans[i].a);
                for(int j = 1; j <= ans[i].p; ++j) {
                    printf("*%lld", prime[j]);
                }
                printf(" + ");
            } else printf("1 + ");
        }
        int i = ans.size() - 1;
        printf("%lld",ans[i].a);
        for(int j = 1; j <= ans[i].p; ++j) {
            printf("*%lld", prime[j]);
        }
        printf("\n");
    }
    return 0;
}
