/*************************************************************************
	> File Name: a.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月24日 星期日 08时59分38秒
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
const string s[]={"127","32767", "2147483647", "9223372036854775807"};
const string ans[] = {"byte", "short", "int", "long", "BigInteger"};
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    string str;
    while(cin >> str){
        int len = str.size();
        string ss;
        ss = str;
        //prln(str);

        if(str[0] == '-'){
            ss="";
            for(int i= 1; i < len; ++i){
                ss  += str[i];              
            }
            ss[len-2] -= 1;
        }
        int now = 0;
        str = ss;
        //cout << str << "\n";
        while(now < 4){
            if(str.size() < s[now].size() ) break;
            if(str.size() == s[now].size() && str <= s[now]) break;
            now++;
        }
        cout << ans[now] << "\n";

    }
	return 0;
}
