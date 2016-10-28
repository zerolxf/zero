/*************************************************************************
    > File Name: a.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月30日 星期五 21时57分35秒
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

char s[maxn];
vector<int> ans;
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    scanf("%d",&n);
    scanf("%s", s);
    int cnt = 0, num = 0;
    for(int i = 0; i < n; ++i){
        if(num&&s[i] == 'W'){
            ans.push_back(num);
            num = 0;
        }else if(s[i]=='B'){
            num++;
        }
    }
    if(num){
        ans.push_back(num);
    }
    cnt = ans.size();
    cout<<cnt<<"\n";
    rep(i,cnt){
        cout<<ans[i] << " ";
    }

	return 0;
}
