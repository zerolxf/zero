/*************************************************************************
	> File Name: k.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月09日 星期一 12时47分03秒
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
const int maxn = 6e5+100;
const int INF = 0x3f3f3f3f;
int s[maxn];
int getminpos(int len) {
    int l = len*2;
    for(int i = len; i < l; ++i){
        s[i] = s[i-len];
    }
    s[l] = 0;
    int i = 0, j = 1, k = 0;
    while(i < len && j < len && k < len) {
        if(s[i+k] == s[j+k]) k++;
        else if(s[i+k] < s[j+k]) {
            j = max(i+1,j+k+1);
            k = 0;
        } else i = max(j+1,i+k+1), k = 0;
    }
    if(i < len) return i;
    return j;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < n; ++i){
            scanf("%d", &s[i]);
        }
        int ans = getminpos(n);
        for(int i = 0; i < n; ++i){
            printf("%d%c",s[(i+ans)%n],(i==n-1?'\n':' '));
        }
    }

	return 0;
}
