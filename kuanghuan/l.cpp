/*************************************************************************
	> File Name: l.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月24日 星期日 16时09分07秒
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
    int t, id, k;
    Node(){}
    Node(int _t, int _id, int _k){
        t = _t;
        id = _id;
        k = _k;
    }
    bool operator <(const Node& rhs)const{
        return t<rhs.t||(t==rhs.t&&id<rhs.id);
    }
};
vector<Node> vt[1234];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, m, l, r, t, k;
    while(cin >> n >> m){
        for(int i = 0; i < m; ++i){
            cin >> l >> r >> t >> k;
            for(int j = l; j <= r; ++j){
                vt[j].push_back(Node(t, i, k));
            }
        }
        ll ans = 0;
        for(int i = 1; i <= 1000; ++i){
            sort(vt[i].begin(), vt[i].end());
            int vsiz = vt[i].size();
            if(vsiz == 0) continue;
            ans += vt[i][0].k;
        }
        cout << ans << "\n";
    }
	return 0;
}
