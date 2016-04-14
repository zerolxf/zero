#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>

using namespace std;
const int maxn = 2e5+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int hang[maxn], lie[maxn], num[maxn];
char s[maxn];
int mp[2100][2100];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
    	scanf("%s",s+1);
    	for(int j = 1; j <= n; ++j){
    		mp[i][j] = s[j] - '0';
    	}
    }

    for(int i = 0; i<= n; ++i) hang[i] = lie[i] = num[i]= 0;
    ll ans = 0;
    for(int i = n; i; --i){
    	for(int j = 1; j < i; ++j){
    		if((mp[j][i]+lie[i]+hang[j])%2==1) {
    			lie[i]++;
    			hang[j]++;
    			ans++;
    		}
    	}
    }
    for(int i = 1; i <= n; ++i) {
    	num[i] += lie[i] + hang[i];
    }

    for(int i = 0; i<= n; ++i) hang[i] = lie[i] =  0;
    for(int i = 1; i <= n; ++i){
    	for(int j = n; j > i; --j){
    		if((mp[j][i]+lie[i]+hang[j])%2==1) {
    			lie[i]++;
    			hang[j]++;
    			ans++;
    		}
    	}
    	
    }
    for(int i = 1; i <= n; ++i) num[i] += lie[i] + hang[i];
	for(int i = 1; i <= n; ++i){
		if((mp[i][i]+num[i])%2==1) ans++;
	}
	cout << ans << "\n";
    return 0;
}