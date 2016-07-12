
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
const int maxn = 6e5+100;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
int f[maxn], last[maxn];
int ans[maxn];
int n, m, x;
char T[maxn], P[maxn];
void getFail() {
    f[0] = 0; f[1] = 0;
    for(int i = 1; i < m; ++i) {
        //pr(i);
        int j = f[i];
        while(j && P[j] != P[i]) j = f[j];
        f[i+1] = P[i] == P[j]?j+1:0;
    }
}
void find() {
    getFail();
    int j = 0;
  //  cout << 1 << endl;
    int k = 0, cnt = 0;
    for(int i = 0; i < n; ++i) {
     //   pr(i);
        while(j&&P[j]!=T[i]) j = f[j];
        if(P[j] == T[i]) ++j;
        if(j == m) {
            cnt -= m-1;
            if(cnt) j = last[ans[cnt]];
            else j = 0;
            k++;
        }else {
            last[i] = j;
            ans[++cnt] = i;
        }
    }
    for(int i = 0; i < n; ++i) {
     //   pr(i);prln(last[i]);
    }
    printf("%d\n", k);
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    while(scanf("%s%s", P, T)!=EOF){
        n = strlen(T), m = strlen(P);
        find();
    }
    return 0;
}
