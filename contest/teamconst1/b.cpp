        /*************************************************************************
    > File Name: b.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月15日 星期一 12时23分30秒
 ************************************************************************/

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
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
int a[20][50], k, sum, n, m;
int head[20], tail[20];
int main(){

	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
    while(scanf("%d%d", &n, &k) != EOF){
        memset(tail, 0, sizeof tail);
        memset(head, 0, sizeof head);
        m = 0;
        rep(i, n){
            scanf("%d", &tail[i]);
            rep(j,tail[i]){
                scanf("%d", &a[i][j]);
            }
            //sort(a[i], a[i]+tail[i]);
        }
        sum = 0, m = 0;
        ll ans = 0;
        while(m<k){
            rep(i,n){
                int j = head[i];
                //prln("******");
                //pr(i);
                //prln(head[i]);
                //while(j < tail[i] && a[i][j] <sum) ++j;
                if(j == tail[i]) m++, ans += 50, sum += 50;
                else {
                    if(a[i][j]<sum){
                        head[i] = j+1;
                        continue;
                    }
                    m++, ans += a[i][j], sum += a[i][j];
                    head[i] = j+1;
                    //prln(a[i][j]);
                    //prln(head[i]);
                    //prln(sum);
                }

                if(m>=k) break;
            }
        }
        printf("%lld\n",ans);

    }



	return 0;
}
