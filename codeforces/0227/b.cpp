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
int get(int x) {
    int ans = 0;
    while(x%5==0){
        ans++;
        x/=5;
    }
    return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int m;
    while(cin >> m) {
        int num = 0, x= 0;
        while(num < m) {
            x+=5;
            num += get(x);
        }
        if(num > m) {
            printf("0\n");
        } else {
            printf("5\n%d",x);
            for(int i = 1; i < 5; ++i){
                printf(" %d",i+x);
            }
            printf("\n");
        }
    }
    return 0;
}