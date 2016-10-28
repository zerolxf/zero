/*************************************************************************
    > File Name: c.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月14日 星期三 00时52分29秒
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

int n;
map<ll,int> mp,cnt;
char s[maxn];
int num[20];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(cin>>n){
        char op[10];
        ll x = 0;
        ll y = 0;

        rep(i,n){
            scanf("%s", op);
            if(op[0] == '+'){
                //cin>>x;
                scanf("%I64d", &x);
                if(mp.count(x) == 0) mp[x] = 1;
                else mp[x]++;
                rep(j,19){
                    num[j] = x%10;
                    x /= 10;
                }
                y = 0;
                for(int j = 18; j >= 0; --j){
                    if(num[j]%2) y = y*2+1;
                    else y = y*2;
                }
                if(cnt.count(y) == 0) cnt[y] = 1;
                else cnt[y]++;
            }else if(op[0] == '-'){
                //cin>>x;
                scanf("%I64d", &x);
                if(mp.count(x) == 0) mp[x] = 1;
                else mp[x]--;
                rep(j,19){
                    num[j] = x%10;
                    x /= 10;
                }
                y = 0;
                for(int j = 18; j >= 0; --j){
                    if(num[j]%2) y = y*2+1;
                    else y = y*2;
                }
                if(cnt.count(y) == 0) cnt[y] = 1;
                else cnt[y]--;
            }else{
                int ans = 0;
                scanf("%s", s);
                int len = strlen(s);
                ll y = 0;
                rep(j,len){
                    y = y*2+s[j]-'0';
                }
                ans = cnt[y];
                cout<<ans<<"\n";
            }

        }

    }

	return 0;
}
