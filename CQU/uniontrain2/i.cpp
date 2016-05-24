/*************************************************************************
	> File Name: i.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月14日 星期六 15时27分02秒
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
#define ll    
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 6e5+100;
const int INF = 0x3f3f3f3f;
  double sum[maxn], suma[maxn], sumb[maxn];
int n;
  double t[maxn];
  double eps = 1e-9;
struct Node{
      double num, x;
    Node(){}
    Node(  double _num,  double _x){
        num = _num;
        x = _x;
    }
}q[2][maxn];
int tail[55], head[55];
bool get1(const Node& a, const Node& b,  const   double x){
    return (b.num - a.num)*1.0 <= x * (b.x - a.x) +eps;
}
bool get2(const Node& a, const Node& b,const Node& c){
    return (c.num - a.num)*(b.x-a.x) <= (b.num - a.num)*(c.x-a.x)+eps;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int kase,k;
    scanf("%d", &kase);
    while(kase--){
        sum[0] = suma[0] = sumb[0] = 0;
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++i){
        //    cin >> t[i];
            scanf("%lf", &t[i]);
        }
        for(int i = 1; i <= n; ++i){
            suma[i] = suma[i-1] + t[i];
            sum[i]  =(t[i]*sum[i-1] + 1)/t[i];
            sumb[i] = sumb[i-1] + sum[i-1]*t[i];
        }
          double y, temp ;
        int now = 0, pre = 1;
        head[now] = 0;tail[now] = -1;
        q[now][++tail[now]] = Node(0,0);
        for(int j = 1; j <=k; ++j){
            pre = now;
            now = now^1;
            tail[now] = -1, head[now] = 0;
            for(int i = 1; i <= n; ++i){
                  double x = sum[i];
                while(head[pre] < tail[pre] && get1(q[pre][head[pre]], q[pre][head[pre]+1], x)){
                    head[pre]++;
                }
                Node qq = q[pre][head[pre]];
                y = qq.num + (suma[i] - qq.x)*sum[i];
                if(j==k) temp = y;
                Node nw = Node(y,suma[i]);
                while(head[now] < tail[now] && get2(q[now][tail[now]-1], q[now][tail[now]], nw)) tail[now]--;
                q[now][++tail[now]] = nw;
            }
        }
          double ans = temp - sumb[n];
        //cout << ans << "\n";
        printf("%.9f\n", ans);
    }
	return 0;
}
