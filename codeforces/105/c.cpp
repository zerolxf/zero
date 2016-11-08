/*************************************************************************
	> File Name: c.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年08月01日 星期一 18时58分22秒
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
int ma, sum;
int ans[maxn];
int n;
int a, b;
bool cal(int last){
        ans[1] =last;
        ma = last;
        sum=last;
        for(int i = 2; i <= n; ++i){
            if(i <= a+1){
                ans[i] = sum+1;
                sum += ans[i];
                ma = max(ans[i], ma);
                last = ans[i];
            }else if(i>n-b){
                ans[i] = ma+1;
                sum += ans[i];
                ma = max(ma, ans[i]);
                last = ans[i];
            }else{
                ans[i] = last;
                sum += ans[i];
                ma = max(ma, ans[i]);
                last = ans[i];
            }
        }
        bool ok = true;
        for(int i = 1; i <= n; ++i){
            if(ans[i] >= 50000) ok = false;
        }
    return ok;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(cin >> n >> a >> b){

        swap(a,b);
        if(n==1){
            cout<<"1\n";
            continue;
        }
        if(b==n-1){
            cout<<"-1\n";
            continue;
        }
        if(n==1&&(a||b)){
            cout<<"-1\n";
            continue;
        }
        bool ok = false;
        if(cal(1)) ok = true;
        if(!ok) {
            if(cal(2)) ok = true;
        }
        if(ok) {
            for(int i =1 ; i <= n; ++i){
                cout << ans[i] << " ";
            }
            cout<<"\n";
        }else{
            cout<<"-1\n";
        }
    }
	return 0;
}
