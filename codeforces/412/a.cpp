
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
int cnt[maxn];
int a[maxn], b[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    MEM(cnt, 0);
    int n;
    cin>>n;
    bool ok = true;
    rep(i,n) cin >>a[i]>>b[i], ok = ok && (a[i]==b[i]), cnt[a[i]]++;
    bool flag = true;
    rep(i,n-1) flag = flag&&(a[i]>=a[i+1]);
    //for(int i = 0; i < maxn; ++i) if(cnt[i]>1) flag = false;
    if(ok&&!flag) cout <<"unrated\n";
	else if(ok&&flag) cout << "maybe\n";
	else cout << "rated\n";
    return 0;
}
