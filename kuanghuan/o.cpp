/*************************************************************************
	> File Name: o.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月24日 星期日 13时46分30秒
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
map<int,int> mp;
set<int> st;
int n, a[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
     int k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
        mp[a[i]] = 0;
    }
    mp.clear();
    for(int i = 1; i <= k; ++i){
        if(mp[a[i]] == 1){
            st.erase(a[i]);
        }else if(mp[a[i]] == 0){
            st.insert(a[i]);
        }
        mp[a[i]]++;
    } 
    int ans = 0;
    if(st.size()){
        auto itr = st.end();
        itr--;
        ans = *itr;
        cout << ans << "\n";
    }else {
        printf("Nothing\n");
    }

   for(int i = k+1; i <= n; ++i){
      if(mp[a[i-k]] == 1){
            st.erase(a[i-k]);
        }else if(mp[a[i-k]] == 2){
            st.insert(a[i-k]);
        }
        mp[a[i-k]]--;
         if(mp[a[i]] == 1){
            st.erase(a[i]);
        }else if(mp[a[i]] == 0){
            st.insert(a[i]);
        }
           mp[a[i]]++;
         if(st.size()){
            auto itr = st.end();
            itr--;
            ans = *itr;
            cout << ans << "\n";
        }else {
            printf("Nothing\n");
        }

    }
	return 0;
}
