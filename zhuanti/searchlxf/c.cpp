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
char s[maxn][30];
char ss[maxn][3];
struct Node{
    int id;
    bool vis;
};
vector<Node> G[30][30];
int ans[maxn], acnt;
void dfs(int id) {
    char ch = ss[id][1];
    for(int i = 0; i < 26;++i){
        for(int j = 0; j < G[ch][i].size(); ++j){
            Node& x = G[ch][i][j];
            if(x.vis) continue;
            x.vis = true;
            dfs(x.id);
        }
    }
    ans[acnt++] = id;
    pr(id);
}
int cnt[30];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int t, n;
    cin >> t;
    while(t--){
        scanf("%d",&n);
        acnt = 0;
        for(int i = 0; i < 30; ++i){
            cnt[i] = 0;
            for(int j = 0; j < 30; ++j){
                G[i][j].clear();
            }
        }
        for(int i = 0; i < n; ++i){
            scanf("%s", s[i]);
            int len = strlen(s[i]);
            ss[i][0] = s[i][0]-'a';
            ss[i][1] = s[i][len-1]-'a';
            cnt[ss[i][0]]++;
            cnt[ss[i][1]]--;
            G[ss[i][0]][ss[i][1]].push_back(Node{i,false});
        }
        int l = 0, r = 0, lnum = 0;
        bool ok = true;
        for(int i = 0; i < 26; ++i){
            if(cnt[i] == 0) continue;
            if(cnt[i] == 1) {
                l++;
                for(int j = 0; j < 26; ++j){
                    if(G[i][j].size()) {
                            lnum = G[i][j][0].id;
                            pr(i);prln(lnum);
                            G[i][j][0].vis = true;
                    }
                }
            }
            else if(cnt[i] == -1) r++;
            else ok = false;
        }
        if(l > 1 || r > 1) ok = false;
        if(ok) {
            int ch = ss[lnum][0];
            if(G[ch][ch].size()) lnum = G[ch][ch][0].id;
            dfs(lnum);
            prln(lnum);
            for(int i = 0; i < 26; ++i){
                for(int j = 0; j < 26; ++j){
                    for(int k = 0; k < G[i][j].size(); ++k){
                        if(G[i][j][k].vis) continue;
                        ok = false;
                        break;
                    }
                    if(!ok) break;
                }
                if(!ok) break;
            }
            if(ok)
            for(int i = acnt-1; i >= 0; --i){
                printf("%s%c",s[ans[i]],i?'.':'\n');
            }
        }
        if(!ok) printf("***\n");
    }
    return 0;
}
