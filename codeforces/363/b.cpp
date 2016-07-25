/*************************************************************************
	> File Name: b.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月19日 星期二 21时13分10秒
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
int a[1100][1100];
char s[1100][1100];
int r[maxn], c[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, m;
    while(cin >> n >> m){
        memset(a, 0, sizeof a);
        memset(c, 0, sizeof c);
        memset(r, 0, sizeof r);
        int cnt = 0;
        or(int i = 1; i <= n; ++i){
            scanf("%s", s[i]);
            for(int j = 1; j <= m; ++j){
                if(s[i][j-1] == '.') a[i][j] = 0;
                else a[i][j] = 1, cnt++;
                r[i] += a[i][j];
                c[j] += a[i][j];
            }
        }
        bool ok = false;
        //prln(cnt);
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                //pr(i);pr(j);pr(r[i]);pr(c[j]);prln(a[i][j]);
                if((r[i]+c[j])==(cnt+a[i][j])){
                    ok = true;
                    printf("YES\n");
                    printf("%d %d\n", i, j);
                    break;
                }
            }
            if(ok) break;
        }
        if(!ok){
            printf("NO\n");
        }
    }
	return 0;
}
