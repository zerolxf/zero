/*************************************************************************
    > File Name: e.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月10日 星期三 02时17分12秒
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
    int id, num;
    
    Node(int _id = 0, int _num = 0):id(_id),num(_num){}
    bool operator < (const Node& rhs)const{
        return num < rhs.num;
    }
}node[maxn];
typedef pair<int,int> P;
vector<P> ans;
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t, n;
    int kase = 0;
    scanf("%d", &t);
    while(t--){
        scanf("%d",&n);
        ans.clear();
        for(int i = 0; i < n; ++i){
            scanf("%d", &node[i].num);
            node[i].id = i+1;
        }
        bool ok = true;
        sort(node, node+n);
        for(int i = 0; i < n; ++i){
            int num = node[i].num;
            if(num>i) ok = false;
            for(int j = 0; j < num; ++j){
                ans.push_back(P(node[i].id, node[j].id));
            }
        }
        if(!ok){
            printf("Case #%d: No\n", ++kase);
        }else{
            printf("Case #%d: Yes\n", ++kase);
            int usiz = ans.size();
            printf("%d\n",usiz);
            for(int i = 0; i < usiz; ++i){
                printf("%d %d\n", ans[i].first, ans[i].second);
            }
        }
    }

	return 0;
}
