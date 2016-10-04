/*************************************************************************
    > File Name: b.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月30日 星期五 22时16分40秒
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
int n, k;
int cal(int x){
    return (x-1)/k*5+x;

}
int cnt[maxn], sum[maxn];
set<string> st;
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    string str;
    cin>>n>>k;
    rep(i,n){
        cin>>str;
        //prln(str);
        int len = str.size();
        //prln(len);
        if(st.count(str)) continue;
        else cnt[len]++,st.insert(str);
    }
    for(int i = 1; i <= 100; ++i){
        cnt[i] += cnt[i-1];
    }
    cin>>str;
    int len = str.size();
    int ans1 = cal(cnt[len-1]+1), ans2 = cal(cnt[len]);
    printf("%d %d\n", ans1, ans2);

	return 0;
}
