/*************************************************************************
	> File Name: a.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月26日 星期二 18时26分25秒
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
char s[maxn];
int len;
ll get(){
    int len = strlen(s);
    if(len >= 11) return -1;
    ll ans = 0;
    for(int i = 0; i < len; ++i){
        ans = ans*10 + s[i] - '0';
    }
    return ans;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(scanf("%s", s) != EOF){
        ll ans = get();
        if(ans <= 0){
            printf("TAT\n");
            continue;
        }
        int cnt = 0;
        while(ans > 1){
            ans = sqrt(ans+0.5);
            cnt++;
        }
        if(cnt>5){
            cout << "TAT\n";
            continue;
        }
        cout << cnt << "\n";
    }
	return 0;
}
