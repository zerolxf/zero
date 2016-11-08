/*************************************************************************
	> File Name: c.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月07日 星期六 23时36分52秒
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
const int maxn = 5100+100;
const int INF = 0x3f3f3f3f;
int n;
int a[maxn], cnt[maxn];
int last[maxn];
int ans[maxn];
struct Node{
    int pos, cnt;
    Node(){}
    Node(int _p, int _c){
        pos = _p;cnt = _c;
    }
    bool operator < (const Node& rhs)const{
        return cnt < rhs.cnt || (cnt==rhs.cnt&&pos>rhs.pos);
    }
};
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    cin >> n;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
        if(last[a[i]] == 0) last[a[i]] = i;
    }
    for(int i = 1; i <= n; ++i) {
        memset(cnt, 0, sizeof cnt);
        priority_queue<Node> pq;
        for(int j = i; j <= n; ++j) {
            pq.push(Node(a[j],++cnt[a[j]]));
            Node u = pq.top();
            ans[u.pos]++;
        }
        while(pq.size()) pq.pop();
    }
    for(int i = 1; i <= n; ++i){
        printf("%d ", ans[i]);
    }
    printf("\n");
	return 0;
}
