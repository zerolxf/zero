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
char s[50000][10], ss[20];
int n, cnt;
void dfs(int pos){
	//prln("");
	if(pos == n) {
		//pr(pos);prln(n);
		for(int i = 0; i < n; ++i){
			s[cnt][i] = ss[i];
		}
		cnt++;
		//prln(cnt);
		return ;
	}

	for(int i = 0; i < 6; ++i){
		ss[pos] = 'a' + i;
		dfs(pos+1);
	}
	return ;
}
char b[300][300];
char  a[100];

bool ok(int pos) {
	//prln(pos);
	if(pos == n-1){
		if(ss[pos] == 'a') return true;
		return false;
	}
	char ch = b[ss[pos]][ss[pos+1]];
	if(ch==0) return false;
	ss[pos+1] = ch;
	return ok(pos+1);
}
char s1[10], s2[10];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int pos  = 0, q;
    cnt = 0;
    scanf("%d%d",&n,&q);
   // prln(n);prln(q);
    dfs(0);
    memset(b,0,sizeof b);
    for(int i = 0; i < q; ++i) {
    	scanf("%s%s",s1,s2);
    	b[s1[0]][s1[1]] = s2[0];
    }
   // prln(cnt);
    int ans = 0;
    for(int i = 0; i <cnt; ++i){
    	for(int j = 0; j < 6; ++j){
    		ss[j] = s[i][j];
    	}
    	if(ok(0)) ans++;
    }
    cout << ans << "\n";
    return 0;
}