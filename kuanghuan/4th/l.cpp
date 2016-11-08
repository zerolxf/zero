/*************************************************************************
    > File Name: l.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月07日 星期日 13时17分21秒
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
const int maxn = 1e6+100;
const int INF = 0x3f3f3f3f;
char s[30];
int len;
typedef pair<int,ll> Node;
ll p, d;
int cntnode;
Node node[maxn];
ll base[30];
void get(int st){
    ll ans = 0;
    for(int i = 0; i < len; ++i){
        if((st>>i)&1){
            ans = ans*10 + 9;
        }else{
        }
    }
    ll last = p-ans;
    for(int i = 0; i < len; ++i){
        if(!((st>>i)&1))
        if(last>=base[len-1-i]){
            ll temp = last/base[len-1-i]*base[len-1-i];
            ans += temp;
            last -= temp;
        }
    }
    int num = 0;
    for(int i = len-1; i >= 0; --i){
        if((st>>i)&1) num++;
        else break;
    }
    //while(st&1){
        //num++;
        //st -= st&(-st);
    //}
    //pr(st);
    //prln(ans);
    //prln(p-d);
    //prln(num);
    if(ans <= p && ans >= p-d){
        node[cntnode++] = Node(num, ans);
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    base[0] = 1;
    for(int i = 1; i <= 19; ++i){
        base[i] = base[i-1]*10;
    }
    scanf("%s%I64d", s, &d);
    len = strlen(s);
    p = 0;
    for(int i = 0; i < len; ++i){
        p = p*10+s[i]-'0';
    }

    int st = (1<<len)-1;
    for(int i = 0; i < st; ++i){
        get(i);
    }
    len--;
    for(int i = 0; i < len; ++i){
        s[i] = s[i+1];
    }
    sort(node, node+cntnode);
    //for(int i = 0; i < cntnode; ++i){
        //pr(i);pr(node[i].first);prln(node[i].second);
    //}
    printf("%lld\n", node[cntnode-1].second);
	return 0;
}
