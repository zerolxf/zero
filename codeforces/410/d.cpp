
/*
* @author:  liangxianfeng
* @mail: liangxianfeng96@qq.com
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define repp(i,n,x) for(int i =x; i < n+x; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl;
const int MOD = 1e9+7;
const int maxn = 1e5+100;
const int INF = 0x3f3f3f3f;
int a[maxn], b[maxn], o[maxn];
bool cmp(int x, int y){return b[x]>b[y];}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    int n;
    cin >> n;
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i], o[i] = i;
    sort(o,o+n,cmp);
    vector<int> ans;
    ans.push_back(o[0]);
    for(int i = 1; i < n-1; i += 2){
    	if(a[o[i]]>=a[o[i+1]]) ans.push_back(o[i]);
    	else ans.push_back(o[i+1]);
    }
    if(n%2==0) ans.push_back(o[n-1]);
    cout<<ans.size()<<endl;
    for(auto x:ans) cout << x+1 << " ";
    cout<<endl;
    return 0;

}
