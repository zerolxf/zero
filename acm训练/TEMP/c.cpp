
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
int p[123456], cnt, n, m;
set<int> s[123456];
map<string,int> ID;
int getID(string name) {
    if(ID.count(name)) {
        return ID[name];
    } else ID[name] = ++cnt;
    s[cnt].clear();
    return cnt;
}
void init(int n) {
    for(int i = 0; i <= n; ++i) p[i] = i;
}
int find(int x) {
    return p[x] == x? x : find(p[x]);
}
int unit(int x, int y) {
    x = find(x), y = find(y);
    p[y] = x;
    return x;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    char op[10];
    string name, name1;
    int x, id, px, py;
    while(cin >> n) {
        ID.clear();
        init(n);
        cnt = 0;
        for(int j = 0; j < n; ++j) {
            scanf("%s", op);
            if(op[0] == 'a') {
                cin >> name;
                id = getID(name);
                scanf("%d", &m);
                for(int i = 0; i < m; ++i) {
                    scanf("%d", &x);
                    s[id].insert(x);
                }
            } else if(op[0] == 's') {
                cin >> name >> name1;
                getID(name);getID(name1);
                if(ID[name] == ID[name1]) continue;
                px = find(ID[name]);
                py = find(ID[name1]);
                p[px] = py;
                s[py].insert(s[px].begin(), s[px].end());
                s[px].clear();
            } else {
                cin >> name;
                getID(name);
                px = find(ID[name]);
                cout << min(1000,(int)s[px].size());
            }
        }
        cout << "\n";
    }
    return 0;
}
