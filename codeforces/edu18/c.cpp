
/*
* @author:  liangxianfeng
* @mail: liangxianfeng96@qq.com
*/
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
#include <ctime>

using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define repp(i,n,x) for(int i =x; i < n+x; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl;
const int MOD = 1e9+7;
const int maxn = 1e5+100;
vector<int> vt[2];
string s;
string getans(int a, int b){
	string ans = "";
	int len = s.size();
	int last = len-1;
	for(int i = len-1; i >= 0; --i){
		if(i==a || i==b)  continue;
		last = i;break;
	}
	bool first = true;
	rep(i,len){
		if(i==a||i==b) continue;
		if(first && s[i] == '0' && i != last) continue;
		first = false;
		ans += s[i];
	}
	return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    int sum = 0;
    cin >> s;
    int len = s.size();
    rep(i, len) sum = (sum + s[i] - '0');
    sum %= 3;
    if(sum==0){
    	cout<<s<<endl;
    	return 0;
    }
    sum--;
    rep(i,len){
    	if((s[i]-'0')%3==1) vt[0].push_back(i);
    	else if((s[i]-'0')%3==2) vt[1].push_back(i);
    }    
    int sz0 = vt[sum].size(), sz1 = vt[1-sum].size();
    string ans1, ans2;
    if(sz0>0)	ans1 = getans(vt[sum][sz0-1], len);
    if(sz1>1)	ans2 = getans(vt[1-sum][sz1-1], vt[1-sum][sz1-2]);
    if(ans1.size()==0&&ans2.size()==0){
    	printf("-1\n");
    }else if(ans1.size() > ans2.size()){
    	cout << ans1 << endl;
    }else cout << ans2 << endl;
    return 0;
}
