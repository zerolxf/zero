/*************************************************************************
    > File Name: d.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月31日 星期一 23时56分47秒
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
#include <ctime>


using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define repp(i,n,x) for(int i =x; i < n+x; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
typedef pair<int,int> P;
map<P,int> mp;
struct Node{
    int num;
    double r;
    int a, b;
    Node(int _num, double _r, int _a, int _b){
        num = _num, r= _r, a = _a, b = _b;
    }
    bool operator < (const Node& rhs)const{
        return r < rhs.r;
    }
};
int a[maxn][3];
P vt[maxn];
int tot;
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    scanf("%d", &n);
    tot = 1;
    int id = 0;
    Node ans = Node(0,0,0,0);
    repp(i,n,1){
        scanf("%d%d%d",&a[i][0], &a[i][1], &a[i][2]);
        sort(a[i],a[i]+3);
        int mi = min(a[i][0],a[i][1]);
        mi = min(mi, a[i][2]);
        Node now = Node(1, mi*0.5, i, 0);
        if(ans < now) ans = now;

        P v = P(a[i][0], a[i][1]);
        if(mp.count(v)){
            id = mp[v];
            mi = min(a[i][0],a[i][1]);
            mi = min(mi, a[i][2]+vt[id].second);
            Node temp = Node(2, mi*0.5, vt[id].first, i);
            if(ans < temp) ans = temp;
            if(vt[id].second < a[i][2]) vt[id] = P(i, a[i][2]);
        }
        else {
            tot++;
            id = tot;
            mp[v] = tot;
            vt[id] = P(i, a[i][2]);
        }

        v = P(a[i][0], a[i][2]);
        if(mp.count(v)){
            id = mp[v];
            mi = min(a[i][0],a[i][2]);
            mi = min(mi, a[i][1]+vt[id].second);
            Node temp = Node(2, mi*0.5, vt[id].first, i);
            if(ans < temp) ans = temp;
            if(vt[id].second < a[i][1]) vt[id] = P(i, a[i][1]);
        }
        else {
            tot++;
            id = tot;
            mp[v] = tot;
            vt[id] = P(i, a[i][1]);
        }

        v = P(a[i][1], a[i][2]);
        if(mp.count(v)){
            id = mp[v];
            mi = min(a[i][1],a[i][2]);
            mi = min(mi, a[i][0]+vt[id].second);
            Node temp = Node(2, mi*0.5, vt[id].first, i);
            if(ans < temp) ans = temp;
            if(vt[id].second < a[i][0]) vt[id] = P(i, a[i][0]);
        }
        else {
            tot++;
            id = tot;
            mp[v] = tot;
            vt[id] = P(i, a[i][0]);
        }
    }
    if(ans.num==1){
        printf("%d\n%d\n",ans.num, ans.a);
    }else{
        printf("%d\n%d %d\n",ans.num,ans.a,ans.b);
    }



	return 0;
}
