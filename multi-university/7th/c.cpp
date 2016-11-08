/*************************************************************************
    > File Name: c.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月10日 星期三 14时45分51秒
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
const int N = 1024;
bool link[1024][1024];
int a[1024];
bool vis[1024];
vector<int> v1, v2;
typedef pair<int,int> P;
P aa[N], b[N], d[N];
int e[N];
char ss[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/1003.in","r",stdin);
    //freopen("/home/zeroxf/桌面/1003.out2","w",stdout);
#endif
    int  n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        //prln(n);prln(m);
        if(n+m == 0) break;
        int cnt = 0;
        memset(vis, 0, sizeof vis);
        memset(link,0,sizeof link);
        v1.clear();
        v2.clear();
        getchar();
        int c = 0, i = 0, j = 0;
         while(true){
            c = getchar();
            if(c!='0' && c !='1'){
                continue;
            }
            if(j==n) j = 0,i++;
            link[i][j] = c-'0';
            j++;
            if(++cnt == n*n) break;
        }
        //getchar();
        //for(int i = 0; i < n; ++i){
            //gets(ss);
            //prln(ss);
            //for(int j = 0; j < n; ++j){
                //link[i][j] = ss[j<<1]-'0';
            //}
        //}
       for(int i = 0; i < m; ++i){
            scanf("%d", &a[i]);
            a[i]--;
            vis[a[i]] = true;
        }
        cnt = 0;
        int cntaa = 0, cntb = 0, cntd = 0;
        for(int i = 0; i < n; ++i){
            if(vis[i]){
                cnt = 0;
                for(int j = 0; j < n; ++j){
                    if(!vis[j]) continue;
                    if(link[i][j])  cnt++;
                }
                aa[cntaa++] = P(cnt, i);
            }else{
                cnt = 0;
                for(int j = 0; j < n; ++j){
                    if(vis[j]) continue;
                    if(link[i][j])  cnt++;
                }
                b[cntb++] = P(cnt,i);
            }
        }
        bool ok = true;
        sort(aa, aa+cntaa);
        sort(b, b+cntb);
        for(int i = 0; i < cntaa; ++i){
            if(aa[i].first != i) ok = false;
            //pr(i);pr(aa[i].first);prln(aa[i].second);
        }
        for(int i = 0; i < cntb; ++i){
            if(b[i].first != i) ok = false;
            //pr(i);pr(b[i].first);prln(b[i].second);
        }

        int ans = 0;
        if(!ok){
            printf("NO\n");
        }else{
            printf("YES ");
            ans = 0;
            for(int i = 0; i < cntb; ++i){
                ok = true;
                int v = b[i].second;
                cnt = 0;
                for(int j = 0; j < cntaa; ++j){
                    if(link[v][aa[j].second]) cnt++;
                }
                for(int j = 0; j < cntaa; ++j){
                    if(j<cnt){
                        if(!link[v][aa[j].second]) ok = false;
                    }else{
                        if(link[v][aa[j].second]) ok = false;
                    }
                }
                if(ok) d[cntd++] = P{cnt, i};
            }
            MEM(e, 0x3f);
            sort(d, d+cntd);
            int len = 0;
            for(int i = 0; i < cntd; ++i){
                int pos = lower_bound(e, e+len, d[i].second) - e;
                e[pos] = d[i].second;
                len = max(pos+1, len);
            }
            printf("%d\n", len);

        }

    }

	return 0;
}
