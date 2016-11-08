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

char s[maxn];
bool ch[200];
string ss = "pqrst";
bool bfs(int& pos) {
    char op = s[pos];
    if(op <= 'z' && op >= 'a') return ch[op];
    if(op == 'N') {
        pos++;
        bool ans = bfs(pos);
        return !ans;
    } else {
        pos++;
        bool lson = bfs(pos);
        pos++;
        bool rson = bfs(pos);
        if(op == 'K') return lson&&rson;
        if(op == 'A') return lson||rson;
        if(op == 'C') return !(lson==true&&rson==false);
        return lson == rson;
    }
}
bool dfs(int pos) {
    bool ans = true;
   // prln(ss[pos]);
    ch[ss[pos]] = false;
    if(pos == 4) {
        int cnt = 0;
        ans = ans&&bfs(cnt);
    }
    else ans = ans&&dfs(pos+1);
    if(!ans) {

        return false;
    }
    ch[ss[pos]] = true;
    if(pos == 4) {
        int cnt = 0;
        ans = ans&&bfs(cnt);
    }
    else ans = ans&&dfs(pos+1);
    if(!ans) return false;
    return true;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    while(scanf("%s", s) != EOF) {
        if(s[0] == '0') break;
        bool ans = dfs(0);
        if(!ans) printf("not\n");
        else printf("tautology\n");
    }
    return 0;
}
