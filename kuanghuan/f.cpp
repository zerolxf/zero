/*************************************************************************
	> File Name: f.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月24日 星期日 12时53分54秒
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
int a[maxn];
int c[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    char s[maxn];
    cin >> n;
    scanf("%s",s+1);
    rep(i,n+1) a[i] = 1;
     rep(j,n)
    for(int i = n-1; i; --i){
        if(s[i] == '='){
            a[i+1] = max(a[i+1],a[i]);
            a[i+1] = a[i];
        }else if(s[i] == 'L'){
            a[i] = max(a[i], a[i+1]+1);
        }else {
            a[i+1] = max(a[i]+1, a[i+1]);
        }
        //prln(s[i]);
        //pr(i);pr(a[i]);prln(a[i+1]);
    }
    //rep(j,n)
    s[0] = 'L';
    bool vis[maxn];
    for(int i = 1; i < n; ++i){
        if(vis[i]) continue;
        if(s[i] == 'L') continue;
        if(s[i] == 'R' && s[i-1]=='L'){
            a[i] = 1;
        }
        int j = i+1;
        while(j <= n && s[j] == 'R'){
            a[j] = a[j-1]+1;
            vis[j] = true;
            j++;
        }
        j = i-1;
        while(j>0&&s[j] == 'L'){
            a[j] = a[j+1]+1;
            --j;
        }
    }
    for(int i = 1; i <= n; ++i){
        cout << a[i] << " ";
    }
    cout << "\n";
	return 0;
}
