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
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int a[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    int t, n, m;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        rep(i,n) scanf("%d", &a[i]);
        int l1, l2, r1, r2;
        rep(i,m){
            scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
            if(l1 > l2){
                swap(l1, l2);
                swap(r1, r2);
            }
            int lsum = r1-l1+1;
            int rsum = r2-l2+1;
            int sum = lsum+rsum;
            int mid = (lsum+rsum)/2;
            if(r1 < r2){
                if(sum%2==0){

                    if(lsum == rsum){
                        double ans = (a[r1]+a[l2])/2.0;
                    }else if(r1>=mid+1){
                        double ans = (a[l1+mid-1]+a[l1+mid])/2.0;
                    }else{
                        mid -= lsum;
                        double ans = (a[l2+mid-1]+a[l2+mid])/2.0;
                    }
                    printf("%.8f\n",ans);
                }else{
                    if(lsum>=mid){
                        printf("%d",a[l1+mid-1]);
                    }else{
                        printf("%d\n",a[l2+mid-lsum-1]);
                    }
                }
            }else{
                if(r1<r2) swap(r1,r2);

            }
        }
    }
    return 0;
}
