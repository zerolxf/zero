/*************************************************************************
    > File Name: f.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月24日 星期六 12时53分41秒
 ************************************************************************/
#include <algorithm>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = (1 << 21) + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double PI = acos(-1);

typedef complex<double> Complex;

void rader(Complex *y, int len) {
    for(int i = 1, j = len / 2; i < len - 1; i++) {
        if(i < j) swap(y[i], y[j]);
        int k = len / 2;
        while(j >= k) {j -= k; k /= 2;}
        if(j < k) j += k;
    }
}
void fft(Complex *y, int len, int op) {
    rader(y, len);
    for(int h = 2; h <= len; h <<= 1) {
        double ang = op * 2 * PI / h;
        Complex wn(cos(ang), sin(ang));
        for(int j = 0; j < len; j += h) {
            Complex w(1, 0);
            for(int k = j; k < j + h / 2; k++) {
                Complex u = y[k];
                Complex t = w * y[k + h / 2];
                y[k] = u + t;
                y[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if(op == -1) for(int i = 0; i < len; i++) y[i] /= len;
}

int n, m, k;
Complex A[N], B[N];
bool p[N], q[N];

void multiply(bool *p, int &n, bool *q, int m) {
    int len = 1;
    while(len <= n + m) len <<= 1;
    for(int i = 0; i < len; ++i) A[i] = Complex(i <= n ? p[i] : 0, 0);
    for(int i = 0; i < len; ++i) B[i] = Complex(i <= m ? q[i] : 0, 0);

    fft(A, len, 1);
    fft(B, len, 1);
    for(int i = 0; i < len; ++i) A[i] *= B[i];
    fft(A, len, -1);
    for(int i = 0; i <= n + m; ++i) p[i] = A[i].real() > 0.5;
    n += m;
}
const int maxn = 4e5+100;
long long a[maxn], b[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int kase;
    scanf("%d", &kase);
    while(kase--){
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%lld", &a[i]);
        for(int i = 0; i < n; ++i) scanf("%lld", &b[i]);

        ll sum = 0;
        for(int i = 0; i < n; ++i){
            sum += a[i]*a[i] + b[i]*b[i];
        }


    }

	return 0;
}
