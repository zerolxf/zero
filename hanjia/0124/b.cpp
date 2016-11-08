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
const int maxn = 1e6+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
const int N = 1e6;
ll base[20], bt[maxn], bnum, cnt;
int getpos(int x){
	int pos = upper_bound(base,base+8,x)-base;
	return pos;
}
void getbase() {
	base[0] = 1;
	bnum = 9;
	for(int i = 1; i < 9; ++i){
		base[i] = base[i-1]*10;
	}
}
void getbt(int b){
	for(ll i = 1; i <= 1000000; ++i){
		bt[i] = i*b;
		//pr(i);prln(bt[i]);
		if(bt[i] > N) {
			cnt = i;
			break;
		}
	}
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    ll n, a, b;
    cin >> a >> b >> n;
    getbase();
    getbt(b);
    if(b==1){
    	printf("%lld\n",a*base[n]);
    	return 0;
    }
    int numa = getpos(a), numb = getpos(b);
    ll aa = a*base[n], aaa=(a+1)*base[n];
    pr(aa);pr(aaa);pr(n);prln(base[n]);
    int pos1 = lower_bound(bt+1,bt+cnt,aa)-bt;
    int pos2 = lower_bound(bt+1,bt+cnt,aaa)-bt;
    pr(cnt);pr(pos1);prln(pos2);
    ll ans = INF;
    for(int i = pos1; i < pos2; ++i){
    	ans = bt[i];
    }
    if(ans!=INF){
    	printf("%lld\n",a*base[n]);
    } else printf("-1\n");
    return 0;
}