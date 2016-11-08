/*************************************************************************
    > File Name: b.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月13日 星期六 11时47分01秒
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
#include <complex>
#include <cmath>
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
char s1[maxn], s2[maxn], s3[maxn];
int s[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(scanf("%s%s", s1, s2) != EOF){
        memset(s, 0, sizeof s);
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        int len3 = max(len1, len2);
        int len = 1;
        while(len <= len3) len <<= 1;
        len <<= 1;
        for(int i = 0; i <len; ++i) x[i] = y[i] = cmx(0,0);
        for(int i = 0; i < len1; ++i){
            x[i] = cmx(s1[len1-i-1] - '0', 0);
        }

        for(int i = 0; i < len2; ++i){
            y[i] = cmx(s2[len2-i-1] - '0', 0);
        }
        fft(x, len, 1);
        fft(y, len, 1);
        for(int i = 0; i < len; ++i){
            x[i] *= y[i];
        }
        fft(x, len, -1);
        for(int i = 0; i < len; ++i){
            s[i] = (ll)(x[i].real()+0.5);
        }
        for(int i = 0; i < len; ++i){
            s[i+1] += (s[i])/10;
            s[i] %= 10;
        }
        //bool first = false;
        while(len > 0 && s[len] <= 0) len--;
        for(int i = len; i >= 0; --i){
            //if(!first && !s[i]) continue; 
            //first = true;
            printf("%c",s[i]+'0');
        }
        printf("\n");

    }

	return 0;
}
