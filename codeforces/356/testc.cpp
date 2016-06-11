/*************************************************************************
	> File Name: testc.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年06月09日 星期四 01时31分52秒
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
int getint(string x){
    int len = x.size();
    int ans = 0;
    for(int i = 0; i < len; ++i){
        ans = ans*10 + x[i] - '0';
    }
    return ans;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/out.txt","r",stdin);
	freopen("/home/zeroxf/桌面/in.txt","w",stdout);
#endif
    string op;
    bool ok = true;
        int cnt = 0;
        do{
            cin >> op;
            if(op == "prime" || op[0] == 'c'){
                if(cnt > 20) {
                    prln(i);
                    ok = false;
                }
                break;
            }
            int x = getint(op);
            if(i%x==0) cout << "yes" << endl;
            else cout << "no" << endl;
        }while(true);
        if(!ok) break;
	return 0;
}
