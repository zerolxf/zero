
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
const int maxn = 1e5+100;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
vector<int> G[maxn];
map<string,int> ID;
int cnt;
int getID(string& name) {
    if(ID.count(name)==0) {
        ID[name] = ++cnt;
    }
    return ID[name];
}
int dfs(int u, int d, int& k) {
    int ans1 = 0, c, ans2 = 1, k1 = 1, k2 = 1;
    for(int i = 0; i < G[u].size(); ++i) {
        ans1 += dfs(G[u][i],1,c);
        k1 = k1&&c;
        k = k1;
    }
    if(d == 0) return ans1;
    for(int i = 0; i < G[u].size(); ++i) {
        ans2 += dfs(G[u][i],0,c);
        k2 = k2&&c;
    }
    //pr(ans1);prln(ans2);
    if(ans1 == ans2){
        k = 0;
        return ans1;
    } else if(ans1 > ans2) {
        k = k1;
        return ans1;
    } else {
        k = k2;
        return ans2;
    }
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int n, u, v, k, ans;
    string name1, name2, root;
    while(cin >> n && n) {
        ID.clear();
        cnt = 0;
        cin >> root;
        getID(root);
        for(int i = 0; i <= n; ++i) G[i].clear();
        for(int i = 0; i < n-1; ++i){
            cin >> name1 >> name2;
            u = getID(name1);
            v = getID(name2);
           // pr(u);prln(v);
            G[v].push_back(u);
        }
        ans = dfs(1,1,k);
        printf("%d ",ans);
        cout << (k == 1? "Yes": "No") << "\n";
    }
    return 0;
}
