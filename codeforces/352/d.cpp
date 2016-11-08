/*************************************************************************
	> File Name: d.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月12日 星期四 01时45分18秒
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
#define pr(x)// cout << #x << " = " << x << " ";
#define prln(x) //cout << #x << " = " << x <<  endl; 
const int maxn = 5e5+100;
const int INF = 0x3f3f3f3f;
ll a[maxn];
ll sum[maxn], dsum[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, k;
    cin >> n >> k;
    sum[0] = 0;
    ll b = 0;
    for(int i = 0; i < n; ++i){
        scanf("%I64d", &a[i]);
        b += a[i];
    }
    sort(a, a+n);
    if(n==1) {
        printf("0\n");
        return 0;
    }

    for(int i = 1; i < n; ++i){
        sum[i] = i*(a[i]-a[i-1]) + sum[i-1];
    }
    dsum[n-1] = 0;
    for(int i = n-2; i >= 0; --i){
        dsum[i] = (n-1-i)*(a[i+1]-a[i]) + dsum[i+1];
    }
    ll bb = b;
    b/=n;
    int pos = upper_bound(a,a+n,b) - a;
    int pos2 = upper_bound(sum,sum+pos,k) -sum;
    ll temp = 0, cc = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] < b) temp+=b-a[i];
        if(a[i] > b) cc++;
    }
    if(cc < (bb%n)) temp +=cc;
    if(temp<=k){
        if(bb%n==0)
        printf("0\n");
        else printf("1\n");
        return 0;
    }
    pos2--;
    ll lk = k - sum[pos2];
    ll add = lk/(pos2+1);
    ll mi = a[pos2]+add;
    sort(dsum, dsum+n);
    prln(pos);
    pos = n-pos;
    prln(pos);
    int pos3 = upper_bound(dsum, dsum+pos,k) - dsum;
    for(int i = 0; i < n; ++i){
        pr(i);prln(dsum[i]);
    }
    pos3--;
    prln(pos3);
    lk = k - dsum[pos3];
    prln(lk);
    ll del = (lk)/(pos3+1);
    prln(del);
    ll ma = a[n-1-pos3]-del;
    prln(ma);prln(mi);
    cout << ma - mi << "\n";
	return 0;
}
