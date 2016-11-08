#include <complex>
using namespace std;
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
