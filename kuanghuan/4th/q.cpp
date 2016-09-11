/*************************************************************************
    > File Name: q.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月07日 星期日 15时04分44秒
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
int cnt[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    while(scanf("%d", &n) != EOF){
        int x;
        ll sum = 0;
        memset(cnt,0,sizeof cnt);
        rep(i,n){
            scanf("%d", &x);
            cnt[x]++;
            sum += x;
        }
        bool ok = true;
        if(cnt[0] <= 0) ok = false;
        int last = sum%3;
        if(last)
        for(int i = 1; i <= 9; ++i){
            if(i%3==last && cnt[i]>=1){
                cnt[i]--;
                last = 0;
                break;
            }
        }
        int need = 2;
        if(last==0) need = 0;
        if(last){
            for(int i = 1; i <= 9; ++i){
                if(need && i%3==(3-last)){
                    if(cnt[i]&&need){
                        cnt[i]--;
                        need--;
                    }
                    if(cnt[i]&&need){
                        cnt[i]--;
                        need--;
                    }
                }
            }
        }
        if(need) ok = false;
        int num = 0;
        if(!ok){
            printf("-1\n");
        }else{
            for(int i = 9; i > 0; --i){
                for(int j = 0; j < cnt[i]; ++j){
                    num++;
                    printf("%d",i);
                }
            }
            if(num == 0){
                printf("0\n");
                continue;
            }
            for(int i = 0; i < cnt[0]; ++i){
                printf("0");
            }
            printf("\n");
        }


    }
	return 0;
}
