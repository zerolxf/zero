/*************************************************************************
	> File Name: d.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月17日 星期二 02时28分58秒
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
int ch[maxn][2];
int p[maxn];
int a[maxn];
int sz;
void add(int id, int num) {
    bool ok = num<a[id]?0:1;
    if(ch[id][ok]==-1){
        ch[id][ok] = ++sz;
        p[sz] = a[id]; 
        return;
    }else{
        add(ch[id][ok],num);
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    sz = 0;
    int n;
    cin >> n;
    memset(ch,-1,sizeof ch);
    rep(i,n) scanf("%d",&a[i]);
    rep(i,n-1) add(0,a[i+1]);
    rep(i,n-1){
        printf("%d ",p[i+1]);
    }
    printf("\n");
	return 0;
}
