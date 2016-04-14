#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
#include<vector>

using namespace std;
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
int mp[110][110];
int x[200], y[200], dir[200], col, row;
int xx[] = {0,1,0,-1};
int yy[] = {1,0,-1,0};
bool mov(int id, int dd) {
    mp[x[id]][y[id]] = 0;
   // pr(id);prln(dd);
    int nx = x[id] + xx[dd];
    int ny = y[id] + yy[dd];
    if(nx == 0 || nx == (col+1) || ny==0||ny==(row+1)) {
       // pr(nx);prln(ny);
        printf("Robot %d crashes into the wall\n",id);
        return false;
    }
    if(mp[nx][ny] > 0) {
        printf("Robot %d crashes into robot %d\n",id,mp[nx][ny]);
        return false;
    }
    mp[nx][ny] = id;
    x[id] = nx;
    y[id] = ny;
    dir[id] = dd;
    return true;
}
bool getmove(int id, char op[], int num) {
    int dd, nx, ny;
    while(num--) {
        if(op[0] == 'F') {
            dd = dir[id];
           // pr(id);prln(dir[id]);
            if(!mov(id,dd)) return false;
        } else if(op[0] == 'L') {
            dir[id] = (dir[id]+3)%4;
            //if(!mov(id,dd)) return false;
        } else {
            dir[id] = (dir[id]+1)%4;
            //if(!mov(id,dd)) return false;
        }
    }
    return true;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int t, m, n,  num, id, d;
    bool ok ;
    char op[10], ch;
    scanf("%d", &t);
    while(t--) {
        ok = true;
        scanf("%d%d", &col, &row);
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= col; ++i){
            for(int j = 1; j <= row; ++j) {
                mp[i][j] = 0;
            }
        }
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d %c", &x[i], &y[i], &ch);
            if(ch == 'N') d = 0;
            if(ch == 'E') d = 1;
            if(ch == 'S') d = 2;
            if(ch == 'W') d = 3;
            dir[i] = d;
            mp[x[i]][y[i]] = i;
        }
        for(int j = 0; j < m; ++j) {
            scanf("%d%s%d", &id, op, &num);
            //pr(id);pr(op);prln(num);
            if(ok&&!getmove(id,op,num)){
                ok = false;
                continue;
            }
        }
        if(ok) printf("OK\n");
    }
    return 0;
}
