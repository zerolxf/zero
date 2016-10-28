/*************************************************************************
    > File Name: e.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月11日 星期日 00时16分02秒
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
struct Node{
    int x, h, op;
    bool operator < (const Node& rhs)const{
        return x < rhs.x;
    }
}node[maxn];
int hh[maxn];
int a[maxn];
typedef pair<int,int> P;
vector<P> ans;
vector<P> G[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    while(cin >> n){
        int h, l, r;
        int cnt = 0;
        int cnta = 0;
        rep(i,n){
            cin>>h>>l>>r;
            node[cnt++] = Node{l, h, 1};
            node[cnt++] = Node{r, h, -1};
            a[cnta++] = l;
            a[cnta++] = r;
        }
        sort(a, a+cnta);
        sort(node, node+cnt);
        cnta = unique(a, a+cnta) - a;
        map<int,int> mp;
        int head = 0;
        rep(i,cnta){
            for(j = head; j < cnt; ++j){
                if(node[j].x == a[i]) ++j;
            }
            for(int jj = head; jj < j; ++jj){

            }



        }
    }

	return 0;
}
