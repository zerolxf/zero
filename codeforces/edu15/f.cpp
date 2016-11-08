/*************************************************************************
	> File Name: f.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月30日 星期六 00时10分40秒
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
struct Node{
    int c, v;
    bool operator < (const Node& rhs)const{
        return v > rhs.v || (v==rhs.v&&c<rhs.c);
    }
}node[maxn];
int sum[maxn];
struct Q{
    int id, last;
}q[maxn], q1[maxn], q2[maxn];
int ans[maxn];

void solve(int l, int r, int ql, int qr){
    if(l>r) return;
    if(l == r){
        for(int i = ql; i <= qr; ++i){
            if(q[i].last >= node[l].c){
                ans[q[i].id]++;
            }
        }
        return;
    }
    int mid = (l+r)>>1;
    int f = 0, g = 0;
    int lsum = sum[mid] - sum[l-1];
    for(int i = ql; i <= qr; ++i){
        if(q[i].last >= lsum){
            ans[q[i].id] += mid-l+1;
            q[i].last -= lsum;
            q2[g++] = q[i];
        }else{
            q1[f++] = q[i];
        }
    }
    memcpy(q+ql, q1, f*sizeof(Q));
    memcpy(q+ql+f, q2, g*sizeof(Q));
    solve(l, mid, ql, ql+f-1);
    solve(mid+1, r, qr-g+1, qr);
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, m, k;
    while(cin >> n){
        memset(ans, 0, sizeof ans);
        for(int i = 0; i < n; ++i){
            scanf("%d%d", &node[i].c, &node[i].v);
        }
        sort(node, node+n);
        for(int i = 1; i <= n; ++i){
            sum[i] = sum[i-1] + node[i-1].c;
        }
    }
	return 0;
}
