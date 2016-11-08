/*************************************************************************
    > File Name: b.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月23日 星期五 21时18分14秒
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
int cnt[2];
char ss[] = "rbrb";
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, ans = 0;
    while(cin>>n)
    {
        scanf("%s",s);
        int len = strlen(s);

        ss[0] = 'r', ss[1] = 'b';
        cnt[0] = cnt[1] = 0;
        for(int i = 0; i < len; ++i){
            if(i&1){
                if(s[i]!=ss[i&1]) cnt[(i&1)]++;
            }else{
                if(s[i]!=ss[i&1]) cnt[(i&1)]++;
            }
        }
        ans = 0;
        //prln(ss);
        //pr(cnt[0]);prln(cnt[1]);
        ans = min(cnt[0], cnt[1]);
        ans += abs(cnt[0]-cnt[1]);
        int tans = ans;
        ans = 0;
        ss[0] = 'b', ss[1] = 'r';

        cnt[0] = cnt[1] = 0;
        for(int i = 0; i < len; ++i){
            if(i&1){
                if(s[i]!=ss[i&1]) cnt[(i&1)]++;
            }else{
                if(s[i]!=ss[i&1]) cnt[(i&1)]++;
            }
        }

        //prln(ss);
        //pr(cnt[0]);prln(cnt[1]);
        //pr(cnt[0]);prln(cnt[1]);

        ans = min(cnt[0], cnt[1]);
        ans += abs(cnt[0]-cnt[1]);
        ans = min(ans, tans);
        cout<<ans<<"\n";

    }

	return 0;
}
