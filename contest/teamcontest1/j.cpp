#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>

using namespace std;
const int maxn = 4e5+1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
char num[maxn], ans[maxn];
bool vis[maxn];
int main(){

    int n;
    cin >> n;
    int x;
    for(int i = 0; i < maxn; ++i) num[i] = '0', ans[i] = '0';
    num[n] = 0;ans[n] = 0;
    puts(num);
    fflush(stdout);
    cin >> x;
    if(x == n) return 0;
    if(x == n/2){

    }
    int last = x;int pos = 0;
    num[pos] = '1';
    puts(num);
    fflush(stdout);
    bool ok = false;
    while(cin >> x){
        if(x == n){
            ok = true;
            break;
        }
        if(x == n/2){
            break;
        }
        num[++pos] = '1';
        puts(num);
        fflush(stdout);
    }
    if(ok) return 0;
    ans[pos] = '1';
    num[pos] = '0';
    for(int i = 0; i < n; ++i){
        if(i==pos) continue;
        char c = num[i];
        if(c=='0') num[i] = '1';
        else num[i] = '0';
        puts(num);
        fflush(stdout);
        cin>>x;
        if(x==n){
            break;
        }else if(x==n/2){
            ans[i] = num[i];
        }else{
            ans[i] = c;
        }
     }
     if(!ok){
        puts(ans);
        fflush(stdout);
     }
    return 0;
}
