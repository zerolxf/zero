
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
const int INF = 0x3f3f3f3f;
void solve(string s){
	int len = s.size();
	bool ok = true;
	string t;
	vector<string> vt;
	for(int i = 0; i < len; ++i){
		if(s[i]>='A'&&s[i]<='Z'){
			ok = false;
			vt.push_back(t);
			t = "";
			t += s[i]-'A'+'a';
		}
		if(s[i] == '_') {
			vt.push_back(t);
			t="";
		}
		if(s[i]>='a'&&s[i]<='z') t += s[i];
	}
	vt.push_back(t);
	string ans;
	if(ok){
		int sz = vt.size();
		ans += vt[0];
		for(int i = 1; i < sz; ++i){
			vt[i][0] = vt[i][0] -'a' + 'A';
			ans += vt[i];
		}

	}else{
		int sz = vt.size();
		ans += vt[0];
		for(int i = 1; i < sz; ++i){
			ans += '_';
			ans += vt[i];
		}		
	}
	cout<<ans<<endl;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    string s;
    int n;
    cin >> n;
    while(n--){
    	cin>>s;
    	solve(s);
    }
    return 0;
}
