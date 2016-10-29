/*************************************************************************
    > File Name: b.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月16日 星期五 20时39分01秒
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
int n;
struct BIT{
    int sum[maxn];
    void clear(){
        memset(sum, 0, sizeof sum);
    }
    void add(int pos, int v){
        for(int i = pos; i <= n; i += i&(-i)){
            sum[i] += v;
        }
    }
    int getsum(int pos){
         int ans = 0;
         for(int i = pos; i > 0; i -= i&(-i)){
             ans += sum[i];
         }
         return ans;
    }
}bit1, bit[2];
int work(int last, int mid){
    int ans = 0;
    ans = max(bit[0].getsum(mid) - bit[0].getsum(last), bit[1].getsum(mid) - bit[1].getsum(last));
    return ans;
}
typedef pair<int,int> P;
P q[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(cin >> n){
        bit[0].clear();
        bit[1].clear();
        for(int i = 1; i <= n; ++i){
            int x;
            scanf("%d", &x);
            bit[x-1].add(i, 1);
        }
        int cnt = 0;
        for(int i = 1; i <= n; ++i){
            int ans = -1;
            int cnt1 = 0, cnt2 = 0;
            int last = 0;
            while(last < n){
                int l = last+1, r = min(last+i*2-1, n);
                int win = 0;
                while(l < r){
                    int mid = (l + r) >> 1;
                    if(work(last, mid) >= i) r = mid;
                    else l = mid + 1;
                }
                if(work(last, l) != i) break;
                if(bit[1].getsum(l) - bit[1].getsum(last) >= i) win = 1;
                last = l;
                if(win) cnt2++;
                else cnt1++;
                if(last == n){
                    if(win==1&&cnt2>cnt1) ans = cnt2;
                    if(win==0&&cnt1>cnt2) ans = cnt1;
                }
            }
            if(~ans){
                q[cnt++] = P(ans, i);
            }
        }
        printf("%d\n",cnt);
        sort(q, q+cnt);
        for(int i = 0; i < cnt; ++i){
            printf("%d %d\n", q[i].first, q[i].second);
        }
    }

	return 0;
}
