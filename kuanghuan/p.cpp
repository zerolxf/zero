/*************************************************************************
	> File Name: p.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月24日 星期日 15时59分35秒
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
const char s[] = {"aeiou"};
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    string str;
    int a[3];
    for(int i = 0; i < 3; ++i){
        getline(cin , str);
        int len = str.size();
        int ans = 0;
        for(int j = 0; j < len; ++j){
            for(int k = 0; k < 5; ++k){
                if(str[j] == s[k]) ans++;
            }
        }
        a[i] = ans;
    }
    if(a[0] == 5 && a[1] == 7 && a[2] == 5){
        printf("YES\n");
    }else cout << "NO\n";
	return 0;   
}
