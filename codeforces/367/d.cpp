/*************************************************************************
    > File Name: d.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月12日 星期五 01时10分33秒
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
const int maxn = 1e7+100;
const int INF = 0x3f3f3f3f;
int ch[maxn][2];
int num[maxn][2];
int a[40];
int tot;
const int N = 32;
void insert(int x, int v){
    rep(i,N){
        a[i] = (x>>i)&1;
    }
    int root = 0;
    //prln(x);
    for(int i = N-1; i >= 0; --i){
        int& u = ch[root][a[i]];
        //pr(i);prln(a[i]);
        if(u==-1){
            u = ++tot;
        }
        num[root][a[i]]+=v;
        //prln(num[root][a[i]]);
        root = u;
    }
}
ll find(int x){
    rep(i,N){
        a[i] = (x>>i)&1;
    }
    int root = 0;
    ll ans = 0;
    //prln(x);
    //memset(num,0,sizeof num);
    for(int i = N-1; i >=0; --i){
        int u = ch[root][!a[i]];
        //pr(i);prln(a[i]);
        //prln(num[root][!a[i]]);
        if(num[root][!a[i]]==0){
            //pr(root);pr(u);
            //prln(ch[root][a[i]]);
            u = ch[root][a[i]];
            //prln(u);
        }else{
            ans = ans|((ll)1<<i);
        }
        root = u;
    }
    return ans;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    memset(ch,-1,sizeof ch);
    memset(num,0,sizeof num);
    int n;
    cin>>n;
    char op[10];
    ll x;
    insert(0,1);
    rep(i,n){
        scanf("%s%I64d",op,&x);
        if(op[0]=='?'){
            ll ans = find(x);
            cout<<ans<<"\n";
        }else if(op[0]=='+'){
            insert(x,1);
        }else{
            insert(x,-1);
        }
    }
    //prln(tot);

	return 0;
}
