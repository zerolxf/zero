
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
const int maxn = 5e5+100;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
int lson[maxn], rson[maxn], cnt, v[maxn];

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int t, n, k, q, rt;
    cin >> t;
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", v + i);
            lson[i] = rson[i] = -1;
        }
        for(int i = 1; i < n; ++i) {
            rt = 0;
            while(true) {
                if(v[rt] < v[i])
                {
                    if(lson[rt] == -1)
                    {
                        lson[rt] = i;
                        break;
                    }
                    rt = lson[rt];
                }
                else
                {
                    if(rson[rt] == -1)
                    {
                        rson[rt] = i;
                        break;
                    }
                    rt = rson[rt];
                }
            }
        }
        scanf("%d", &k);
        while(k--) {
            rt = 0;
            scanf("%d", &q);
           // prln(q);
            while(v[rt] != q) {
               // prln(v[rt]);
                if(v[rt] < q) {
                    printf("W");
                    rt = lson[rt];
                } else {
                    printf("E");
                    rt = rson[rt];
                }
            }
            printf("\n");
        }
    }
    return 0;
}
