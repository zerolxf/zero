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
const int maxn = 4e5+1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n)` memset(a,b,n*sizeof(int))
const long double N = 1e7;
const long double l = -(long double)sqrt(14)/8.0;
const long double r = (long double)sqrt(14)/8.0;
long double get(){
    const long double dx = (r-l)*1.0/N;
    long double x = l;
    long double y = 0;
    long double sum = 0;
    for(int i = 0; x < r; ++i){
        y = (sqrt(0.25-x*x) - sqrt(1-x*x)+sqrt(2.0)/2.0);
        x += dx;
        sum += y*dx;
    }
    sum*=2;
    return sum;
}
int main(){
#ifdef LOCAL
    //freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    long double ans = get();
    int t;
    long double k;
    const long double pi = acos(-1);
    scanf("%d", &t);
    while(t--){
        //scanf("%lf",&k);
        cin>>k;
        printf("%.2f\n",(double)(k*k*ans));

    }
    return 0;
}
