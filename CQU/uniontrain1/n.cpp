/*************************************************************************
	> File Name: n.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月09日 星期一 20时46分02秒
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
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
char ch[30];
int dp[200][11000];
int n, p;
int ret(int x, int y) {
    int base = x;
    int ans = 1;
    while(y) {
        if(y&1) ans = (ans*base)%10007;
        y>>=1;
        base = (base*base)%10007;
    }
    return ans;
}
int sz, fail[maxn], nxt[maxn][30], cnt[maxn], root;
struct Automate{
    int newnode(){
        cnt[sz] = 0;
        memset(nxt[sz], -1, sizeof nxt[sz]);
        return sz++;
    }
    void init(){
        sz = 0;
        root = newnode();
    }
    void insert(char *s){
        int len = strlen(s);
        int u = root;
        for(int i = 0; i < len; ++i){
            int &v = nxt[u][s[i] - 'A'];
            if(v==-1) v = newnode();
            u = v;
        }
        cnt[u] = 1;
    }
    void build(){
        queue<int> q;
        fail[root] = root;
        for(int i = 0; i < 26; ++i){
            int &u = nxt[root][i];
            if(~u) {
                fail[u] = root;
                q.push(u);
            }else u = root;
        }
        while(q.size()){
            int u = q.front(); q.pop();
            if(cnt[fail[u]]) cnt[u] = 1;
            for(int i = 0; i < 26; ++i){
                int &v = nxt[u][i];
                if(~v){
                    fail[v] = nxt[fail[u]][i];
                    q.push(v);
                } else v = nxt[fail[u]][i];
            }
        }
    }
}ac;
int slove() {
/*    phx.clear();
    for(int i = 0; i < p; ++i){
        int len = S[i].size();
        for(int j = 0; j <= len; ++j){
            phx.push_back(S[i].substr(0,j));
        }
    }
    sort(phx.begin(), phx.end());
    int K = unique(phx.begin(), phx.end()) - phx.begin();
    phx.erase(phx.begin()+K, phx.end());
    int pos ;
    for(int i = 0; i < K; ++i){
       ng[i] = false;
        for(int j = 0; j < p; ++j){
            ng[i] |= phx[i].length() >= S[j].length() && (phx[i].substr(phx[i].length()-S[j].length()) == S[j]);
        }
        for(int j = 0; j < 26; ++j) {
            string s = phx[i] + ch[j];
            while(true) {
                pos = lower_bound(phx.begin(), phx.end(), s) - phx.begin();
                if(pos < K && s == phx[pos]) break;
                s = s.substr(1);
            }
            nxt[i][j] = pos;
        }
    }*/
    int K = sz;
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j < K; ++j){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j < K; ++j){
            if(cnt[j]) continue;
            for(int l = 0; l < 26; ++l) {
        //        if(cnt[nxt[i][l]]) continue;
                dp[i+1][nxt[j][l]] =  (dp[i+1][nxt[j][l]] + dp[i][j])%10007;
            }
        }
    }
    int ans = 0;
    ans += ret(26, n);
    for(int i = 0; i < K; ++i){
        if(!cnt[i])  ans = (ans-dp[n][i])%10007;
    }
    ans = (ans%10007+10007)%10007;
    return ans;
}
char str[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--){
        ac.init();
        scanf("%d%d", &p, &n);
        for(int i = 0; i < p; ++i){
            scanf("%s", str);
            ac.insert(str);
        }
        ac.build();
        int ans = slove();
        printf("%d\n", ans);
    }
	return 0;
}
