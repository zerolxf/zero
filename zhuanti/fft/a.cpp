/*************************************************************************
    > File Name: a.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月12日 星期五 19时27分41秒
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
#include <complex>
using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
typedef complex<double> cmx;
cmx x1[maxn], y[maxn];
int a[maxn];

void change(cmx y[],int len)
{
    int i,j,k;
    for(i = 1, j = len/2;i < len-1;i++)
    {
        if(i < j)swap(y[i],y[j]);
        k = len/2;
        while( j >= k)
        {
            j -= k;
            k /= 2;
        }
        if(j < k)j += k;
    }
}
void fft(cmx y[],int len,int on)
{
    change(y,len);
    for(int h = 2;h <= len;h <<= 1)
    {
        cmx wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j = 0;j < len;j += h)
        {
            cmx w(1,0);
            for(int k = j;k < j+h/2;k++)
            {
                cmx u = y[k];
                cmx t = w*y[k+h/2];
                y[k] = u+t;
                y[k+h/2] = u-t;
                w = w*wn;
            }
        }
    }
    if(on == -1)
        for(int i = 0;i < len;i++)
            y[i] /= len;
}
ll num[maxn];
ll sum[maxn];
ll cnt[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        memset(cnt, 0, sizeof cnt);
        for(int i = 0; i < n; ++i){
            scanf("%d", &a[i]);
            cnt[a[i]]++;
        }
        sort(a, a+n);
        int len1 = a[n-1]+1;
        int len = 1;
        while(len < 2*len1) len <<= 1;
        rep(i,len) x1[i] = cmx(0,0);
        for(int i = 0; i < len1; ++i){
            x1[i] = cmx(cnt[i], 0);
        }
        fft(x1,len,1);
        for(int i = 0; i < len; ++i){
             x1[i] = x1[i]*x1[i];
        }
        fft(x1, len, -1);
        for(int i = 0; i < len; ++i){
            num[i] = (ll)(x1[i].real()+0.5);
        }
        len = a[n-1]*2;
        for(int i = 0; i < n; ++i){
            num[a[i]+a[i]]--;
        }
        for(int i = 1; i <= len; ++i) num[i] /= 2;

        sum[0] = 0;
        for(int i = 1; i <= len; ++i) sum[i] = sum[i-1] + num[i];
        ll temp = 0;

        ll ans = 0;
        for(ll i = 0; i < n; ++i){
            ans += sum[len] - sum[a[i]];
            ans -= i*(n-i-1);
            temp = n-i-1;
            ans -= temp*(temp-1)/2;
            ans -= n-1;
        }
        ll all = (ll)n*(n-1)*(n-2)/6;
        printf("%.7lf\n",(double)ans*1.0/all);

        

    }
	return 0;
}
