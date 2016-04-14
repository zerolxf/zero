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
#define rep(i,n) for(int i = 0;i < n; i++) 
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
int a[maxn], ma[maxn], mi[maxn], p[maxn];
int find(int x) {
    return p[x]= (x==p[x] ?x: find(p[x]) );
}
struct Node{
    int pos, num;
    bool operator < (const Node& rhs)const{
        return num > rhs.num||(num==rhs.num&&pos > rhs.pos);
    }
}b[maxn];

    bool cmp(const Node& l, const Node& r) {
        return l.num < r.num||(l.num==r.num&&l.pos > r.pos);
    }
int k, n;
void slove(int ans[]) {
    for(int i = 0; i <= n+1; i++){
        p[i] = i;
    }
    for(int i = 1; i <= n; ++i) {
        int pos = b[i].pos, l = b[i].pos-k+1;
        //pr(pos);pr(l);prln(a[pos]);
        if(l < 1) l = 1;
        while(pos >= l) {
        //  pr(pos);
            if(p[pos]==pos) {
                ans[pos] = b[i].num;
                p[pos] = pos-1;
                --pos;
            } else {
                pos = find(pos);
            }
        }
    }
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
        cin >> n >> k;
        for(int i = 1; i <= n; ++i) {
            scanf("%d",&a[i]);
        }
        for(int i = 1; i <= n; ++i) {
            b[i].pos = i;
            b[i].num = a[i];
        }
        sort(b+1,b+n+1,cmp);
        slove(mi);
        int m = n/2;
        Node temp;
        for(int i = 1; i <= m; ++i){
            temp = b[i];
            b[i] = b[n-i+1];
            b[n-i+1] = temp;
        }
        //sort(b+1,b+n+1);
        slove(ma);
        for(int i = 1; i <= n-k+1; ++i) {
            printf("%d ", mi[i]);
        }
        printf("\n");   
        for(int i = 1; i <= n-k+1; ++i) {
            printf("%d ", ma[i]);
        }
 
    return 0;
}