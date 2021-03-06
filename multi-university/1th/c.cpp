/*************************************************************************
	> File Name: cc.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月23日 星期六 14时39分42秒
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
#define rep_1(i,n) for(int i =1; i <= n; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) //cout << #x << " = " << x << " ";
#define ii (n-i+1)
#define jj (m-j+1)
#define prln(x) //cout << #x << " = " << x <<  endl; 
const int maxn = 1e3+100;
const int INF = 0x3f3f3f3f;
ll l[maxn][maxn], r[maxn][maxn], up[maxn][maxn], down[maxn][maxn];
int a[maxn][maxn];
int n, m;
const int MOD = 1e9+7;
char s[maxn][maxn];
struct Node{
    int x, y;
    Node(){}
    Node(int _x, int _y){
        x = _x;
        y = _y;
    }
}rr[maxn], cc[maxn];
int cntc, cntr;
void calcnt(){
    cntc = cntr = 0;
    rep_1(i,n){
        rep_1(j,m){
            if(s[i][j]=='G'){ 
                a[i][j] = 0;
                rr[cntr++] = Node(i,j);
            }
            else a[i][j] = 1;
        }
    }
    rep_1(j, m){
        rep_1(i, n){
            if(a[i][j]==0)cc[cntc++] = Node(i,j);
        }
    }
    for(int i = 0; i <= n; ++i){
        l[i][0] = 0;
        l[i][1] = 0;
        r[i][m+1] = 0;
        r[i][m] = 0;
    }
    for(int i = 0; i <= m; ++i){
        up[0][i] = 0;
        up[1][i] = 0;
        down[n+1][i] = 0;
        down[n][i] = 0;
    }
    rep_1(i, n){
        rep_1(j, m){
            l[i][1+j] = a[i][j] + l[i][j]; 
            up[i+1][j] = a[i][j] + up[i][j];
            down[ii-1][jj] = a[ii][jj] + down[ii][jj];
            r[ii][jj-1] = a[ii][jj] + r[ii][jj];
        }
    }
}
inline int getremove1(int x, int y){
    return x*y*(x+y)/2;
}
inline ll getremove(int x, int y){
    ll ans = 0;
    ans = (ans + getremove1(x-1,y) + getremove1(x,m-y) + getremove1(n-x+1,y-1) + getremove1(n-x,m-y+1));
    return ans;
}
ll getadd(){
    ll ans  = 0;
    bool flag = true;
    ll last = 0;
    for(int i = 0; i < cntr; ++i){
        Node& g = rr[i];
        ans += l[g.x][g.y]*r[g.x][g.y]*4;
        if(i == 0){
            last = l[g.x][g.y];
        }else{
            if(g.x-rr[i-1].x>1){
                last = l[g.x][g.y];
                flag = true;
                continue;
            }
            if(flag && g.y > rr[i-1].y){
                ans += last*r[g.x][g.y]*4;
                last += l[g.x][g.y];
                flag = true;
            }else if(flag && g.y < rr[i-1].y){
                last = r[rr[i-1].x][rr[i-1].y];
                ans += last*l[g.x][g.y]*4;
                last += r[g.x][g.y];
                flag = false;
            }else if(!flag && g.y > rr[i-1].y){
                last = l[rr[i-1].x][rr[i-1].y];
                ans += last*r[g.x][g.y]*4;
                last += l[g.x][g.y];
                flag = true;
            }else {
                ans += last*l[g.x][g.y]*4;
                last += r[g.x][g.y];
                flag = false;
            }
        }
    }
    flag  = true;
    last = 0;
    for(int i = 0; i < cntc; ++i){
        Node& g = cc[i];
        ans += up[g.x][g.y]*down[g.x][g.y]*4;
        if(i == 0){
            last += up[g.x][g.y];
        }else{
            if(g.y-cc[i-1].y>1){
                last = up[g.x][g.y];
                flag = true;
                continue;
            }
            if(flag && g.x > cc[i-1].x){
                ans += last*down[g.x][g.y]*4;
                last += up[g.x][g.y];
                flag = true;
            }else if(flag && g.x < cc[i-1].x){
                last = down[cc[i-1].x][cc[i-1].y];
                ans += last*up[g.x][g.y]*4;
                last += down[g.x][g.y];
                flag = false;
            }else if(!flag && g.x > cc[i-1].x){
                last = up[cc[i-1].x][cc[i-1].y];
                ans += last*down[g.x][g.y]*4;
                last += up[g.x][g.y];
                flag = true;
            }else {
                ans += last*up[g.x][g.y]*4;
                last += down[g.x][g.y];
                flag = false;
           
            }
        }
    }
    return ans;
}
ll solve(){
    calcnt();
    ll ans = 0;
    ll add = 0;
    ll x = getremove(1,1);
    ll sumx = x;
    for(int i = 2; i <= m; ++i){
        x -= (m-2*i+2)*n;
        prln(x);
        sumx += x;
    }
    ll sum = sumx;
    for(int i = 2; i <= n; ++i){
        sumx -= (n-2*i+2)*m*m;
        sum += sumx;
    }
    for(int i = 0; i < cntr; ++i){
        sum -= 2*getremove(rr[i].x, rr[i].y);
    }
   add = getadd();
   ans = sum + add;
    return ans;
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        rep_1(i, n){
            scanf("%s", s[i]+1);
        }
        ll temp = solve();
        double ans = (ll)n*m-cntc;
        ans = ans*ans;
        ll gadd = 0;
        for(int i = 0; i < cntc; ++i){
            for(int j = 0; j < cntc; ++j){
                gadd += abs(cc[i].x-cc[j].x)+abs(cc[i].y-cc[j].y);
            }
        }
        temp += gadd;
        ans = temp*1.0/ans;
        printf("%.4f\n",ans);

    }
	return 0;
}
