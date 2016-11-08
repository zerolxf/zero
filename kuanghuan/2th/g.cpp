/*************************************************************************
	> File Name: g.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月24日 星期日 10时55分32秒
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
int a[maxn], b[maxn], pos[maxn];
int cnt;
void get(int x, int y){
    for(int i = cnt; i > x; --i){
        a[i] = a[i-1];
    }
    a[x] = y;
    cnt++;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, k;
    while(cin >>n >> k){
        //prln(n);prln(k);
        memset(b,0,sizeof b);
        for(int i = 1; i <= n; ++i){
            cin >> b[i];
            //prln(b[i]);
        }
        cnt = 0;
        //prln(n);
        for(int i = n; i; --i){
            int d = 0;
            for(int j = 0; j <= cnt; ++j){
                //pr(i);prln(j);
                if(d==b[i]){
                    get(j,i);
                    break;
                }
                if(a[j]>=i+k) d++;
            }
        }
        cout << a[0];
        for(int i = 1; i < cnt; ++i){
            cout << " " << a[i];
        }
    }
	return 0;
}
