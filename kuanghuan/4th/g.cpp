/*************************************************************************
    > File Name: g.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月07日 星期日 12时23分57秒
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
ll a[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    ll s, k;
    cin >> s >> k;
    ll sum = 0;
    int pos = 0;
    a[pos++] = 1;
    cin >> s >> k;
    ll mi = min(s, (ll)INF);
    while(a[pos-1] <= mi){
        //pr(a[pos-1]);prln(mi);
        sum += a[pos-1];
        int last = pos-k-1;
        //prln(sum);
        if(last>=0) sum -= a[last];
        a[pos++] = sum;
        //prln(a[pos-1]);
    }
    int need = s;
    vector<int> ans;
    while(need > 0){
        int p = upper_bound(a, a+pos, need) - a;
        need -= a[p-1];
        //prln(need);
        //prln(a[p-1]);
        ans.push_back(a[p-1]);
    }
    if(ans.size()<2) ans.push_back(0);
    int usiz = ans.size();
    printf("%d\n",usiz);
    for(int i = usiz-1; i >= 0; --i){
        printf("%d ", ans[i]);
    }
    printf("\n");

	return 0;
}
