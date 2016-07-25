/*************************************************************************
	> File Name: hdu5730.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月25日 星期一 11时27分08秒
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
#include<complex>
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
cmx x[maxn], y[maxn];
int a[maxn], dp[maxn], n;
//void change(cmx x[], int len) {
    //int i, j, k;
    //for(i = 1, j = len/2; i < len - 1; i++) {
        //if(i < j)
            //swap(x[i], x[j]);
        //k = len / 2;
        //while(j >= k) {
            //j -= k;
            //k /= 2;
        //}
        //if(j < k)
            //j += k;
    //}
//}
void change(cmx x[], int len){

    for(int i = 1, j = len/2; i < len-1; ++i){
        if(i < j) swap(x[i], x[j]);
        int k = len/2;
        while(j >= k){
            j -= k;
            k /= 2;
        }
        while(j < k) j+= k;
    }
}
void fft(cmx x[], int len, int on){
    change(x, len);
    for(int i = 2; i <= len; i <<= 1){
        cmx wn(cos(-on*2*PI/i), sin(-on*2*PI/i));
        for(int j = 0; j < len; j += i){
            cmx w(1,0);
            for(int k = j; k < j + i/2; ++k){
                cmx u = x[k];
                cmx v = x[k+i/2]*w;
                x[k] = u + v;
                x[k+i/2] = u-v;
                w *= wn;
            }
        }
    }
    if(on == -1){
        for(int i = 0; i < len; ++i){
            x[i] /= len;
        }
    }
}
const int MOD = 313;
void cdq(int l, int r){
    if(l == r){
        dp[l] += a[l];
        dp[l] %= MOD;
        return;
    }
    int mid = (l + r) >> 1;
    cdq(l, mid);
    int len = 1;
    while(len <= (r-l+1)) len <<= 1;
    rep(i,len) x[i] = y[i] = cmx(0,0);
    for(int i = l; i <= mid; ++i){
        x[i-l] = cmx(dp[i], 0);
    }
    for(int i = 1; i <= r-l; ++i){
        y[i-1] = cmx(a[i], 0);
    }
    fft(x, len, 1);
    fft(y, len, 1);
    for(int i = 0; i < len; ++i){
        x[i] *= y[i];
    }
    fft(x, len, -1);
    for(int i = mid+1; i <= r; ++i){
        dp[i] += (int)(x[i-l-1].real() + 0.5);
        dp[i] %= MOD;
    }
    cdq(mid+1, r);
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(cin >> n && n){
        MEM(dp, 0);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            a[i] %= MOD;
        }
        cdq(1, n);
        cout << dp[n] << "\n";
    }
	return 0;
}
