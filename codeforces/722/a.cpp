/*************************************************************************
    > File Name: a.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月01日 星期六 22时03分45秒
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

int a[maxn], n;
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    //cin >> n;
    //rep(i,n){
        //cin>>a[i];
    //}
    char s[10];
    cin>>n>>s;
    if(n==24){
        int ans = 0;
        int num1 = 0, num2 = 0;
        num1 = (s[0]-'0')*10 + s[1] - '0';
        num2 = (s[3] - '0')*10 + s[4] - '0';
        if(num1>23){
            s[0] = '0';
            ans++;
        }
        if(num2>59){
            s[3] = '0';
            ans++;
        }
        //cout<<ans<<"\n";
        cout<<s<<"\n";
    }else{
        int ans = 0;
        int num1 = 0, num2 = 0;
        num1 = (s[0]-'0')*10 + s[1] - '0';
        num2 = (s[3] - '0')*10 + s[4] - '0';

        if(num1==0) s[0] = '1',ans++;
        if(num1>12){
            if(s[1] == '0') s[0] = '1';
            else s[0] = '0';
            ans++;
        }
        if(num2>59){
            s[3] = '0';
            ans++;
        }
        //cout<<ans<<"\n";
        cout<<s<<"\n";
        

    }

	return 0;
}
