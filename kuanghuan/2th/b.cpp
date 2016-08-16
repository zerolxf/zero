/*************************************************************************
	> File Name: b.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月24日 星期日 09时21分21秒
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

int a[maxn], l[maxn], r[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    while(cin >> n){
        l[1] = 0;
        r[1] = 0;
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        for(int i = 2; i <= n; ++i){
            if(a[i] >= a[i-1]) l[i] = l[i-1]+1;
            else l[i] = 0;
        }
        for(int i = n-1; i; --i){
            if(a[i] >= a[i+1]) r[i] = r[i+1] + 1;
            else r[i] = 0;
        }
        int ans = 1;
        for(int i = 1; i <= n; ++i){
            ans = max(ans, l[i]+r[i]+1);
        }
        cout << ans << "\n";
    }
	return 0;
}
