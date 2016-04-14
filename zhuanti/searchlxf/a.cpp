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
const int maxn = 1e6+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
#define rep(i,n) for(int i = 0; i < n; ++i)
int t;
int l[30], r[30];
char s[maxn];
int mp[30][30], vis[30][30];
void dfs(int x, int y){
    for(int i = 0; i < 26; ++i) {
        if(mp[i][x] && !vis[i][x]) {
            vis[i][x] = true;
            dfs(i,x);
        }
        if(mp[y][i] && !vis[y][i]){
            vis[y][i] = true;
            dfs(y,i);
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n;
    cin >>t;
    while(t--) {
        cin >> n;
        memset(vis,0,sizeof vis);
        memset(mp,0,sizeof mp);
        for(int i = 0; i <= 26; ++i) l[i] = r[i] = 0;
        for(int i = 0; i < n;++i){
            scanf("%s",s);
            int len = strlen(s);
            l[s[0]-'a']++;
            r[s[len-1]-'a']++;
            mp[s[0]-'a'][s[len-1]-'a']++;
        }
        bool ok = true;
        int lll = 0, rr = 0;
        for(int i = 0; i < 26; ++i) {
            if(l[i] == r[i]) continue;
            else if(l[i] == r[i]+1) lll++;
            else if(r[i] == l[i]+1) rr++;
            else ok = false;
        }
        int cnt = 0;
        for(int i = 0; i < 26; ++i){
            for(int j = 0; j < 26; ++j){
                if(mp[i][j] && !vis[i][j]) {
                    vis[i][j]  = true;
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        if(lll < 2 && rr < 2 && ok && cnt == 1){
            printf("Ordering is possible.\n");
        } else printf("The door cannot be opened.\n");
    }
    return 0;
}
