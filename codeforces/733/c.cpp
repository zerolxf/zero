/*************************************************************************
    > File Name: c.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年10月31日 星期一 22时27分57秒
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
#include <ctime>


using namespace std;
#define ll long long
#define rep(i,n) for(int i =0; i < n; ++i)
#define repp(i,n,x) for(int i =x; i < n+x; ++i)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) //cout << #x << " = " << x << " ";
#define prln(x)// cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
ll a[maxn], b[maxn];
typedef pair<int,int> P;
vector<P> ans;
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n, k;
    scanf("%d",&n);
    ll suma = 0, sumb = 0;
    repp(i,n,1){
        cin>>a[i];
        suma += a[i];
    }
    scanf("%d", &k);
    repp(i,k,1){
        cin>>b[i];
        sumb += b[i];
    }
    int eatnum = 0;
    bool ok = true;
    if(suma != sumb) ok = false;
    int pos = 1;
    prln(ok);
    for(int i = 1; i <= n; ){
        if(!ok) break;
        int l = i;
        int r = i;
        ll sum = 0;
        pr(r);prln(pos);
        if(pos>k){
            if(i<=n) ok = false;
        }
        while(r <= n && sum < b[pos]){
            sum += a[r];
            ++r;
        }
        prln(ok);pr(l);pr(r);pr(sum)prln(b[pos]);
        if(sum != b[pos]) {
            ok = false;
            break;
        }
        pos++;

        if(r-l==1) {
            i = r;
            continue;
        }
        ll ma = 0, index = 0;
        bool same = true;
        ma = a[r-1];
        for(int j = l; j < r-1; ++j){
            ma = max(ma, a[j]);
            if(a[j]!=a[j+1]){
                same = false;
            }
        }
        if(same){
            ok = false;
            break;
        }
        prln(ma);
        prln(r);
        for(int j = l; j < r; ++j){
            prln(a[j]);
            if(j==l){
                if(a[j]==ma&&a[l]!=a[l+1]){
                    index = l;
                }
            }
            if(j==r-1){
                if(a[r-1]==ma&&a[r-1]!=a[r-2]){
                    index = r-1;
                }

            }
            if(j!=l&&j!=r-1){
                if(a[j]==ma&&(a[j]!=a[j+1]||a[j]!=a[j-1])){
                    index = j;
                }
            }
        }
        prln(index);
        if(index==l){
            rep(j,r-l-1){
                ans.push_back(P(index-eatnum,1));
            }
            eatnum += r-l-1;
        }else if(index==r-1){
            rep(j,r-l-1){
                ans.push_back(P(index-eatnum,0));
                eatnum++;
            }
        }else{
            int dir = 0;
            if(a[index]>a[index-1]) dir = 0;
            if(a[index]>a[index+1]) dir = 1;
            if(dir==0){
                rep(j,index-l){
                    ans.push_back(P(index-eatnum,0));
                    eatnum++;
                }
                rep(j,r-1-index){
                    ans.push_back(P(index-eatnum,1));
                }
                eatnum += r-1-index;
            }
            else{
                rep(j,r-1-index){
                    ans.push_back(P(index-eatnum,1));
                }
                rep(j,index-l){
                    ans.push_back(P(index-eatnum,0));
                    eatnum++;
                }

                eatnum += r-1-index;
            }
        }
        i = r;
        prln(i);
    }
    int siz = ans.size();
    if(!ok) {
        printf("NO\n");
    }else{
        printf("YES\n");
        for(int i = 0; i < siz; ++i){
            printf("%d %c\n", ans[i].first, ans[i].second==0?'L':'R');
        }
        printf("\n");
    }

	return 0;
}
