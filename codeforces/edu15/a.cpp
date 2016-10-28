/*************************************************************************
	> File Name: a.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月29日 星期五 22时59分22秒
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
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    memset(a, 0x3f, sizeof a);
    int n, ans = 0;
    while(cin >> n){
        int pos = 0;
        int x;
        int ans = 0;
        int last = INF;
        pos = 1;
        for(int i = 0; i < n; ++i){
            scanf("%d", &x);
            if(x>last) pos++;
            else pos = 1;
            last = x;
            ans = max(ans,pos);
        }
        cout << ans << "\n";
    }
	return 0;
}
