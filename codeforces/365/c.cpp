/*************************************************************************
	> File Name: c.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年08月04日 星期四 23时58分04秒
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
#define CLR(x) memset(x,0,sizeof x)
#define MEM(a,b) memset(a,b,sizeof a)
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<  endl; 
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;
ll x[maxn], y[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    ll n, u, v, w;
    while(cin >> n >> w >> v >> u){
        for(int i = 1; i <= n; ++i){
            //cin >> x[i] >> y[i];
            scanf("%I64d%I64d", &x[i], &y[i]);
        }
        int id = 0;
        queue<int> q;
        ll miy = INF;
        ll mix = INF;
        ll lx = INF, rx = -INF;;
        for(int i = 1; i <= n; ++i){
            lx = min(lx, x[i]);
            //prln(x[i]);
            //prln(lx);
            rx = max(rx, x[i]);
            if(x[i]>=0)
            if(y[i] < miy || (y[i] == miy&&x[i]<=mix)){
                id = i;
                miy = y[i];
                mix = x[i];
            }
        }
        if(rx<=0||w*v<=lx*u){
            //prln("ok");
            printf("%.10f\n",w*1.0/u);
            continue;
        }
        q.push(id);
        int last = id;
        for(int i = 1; i < n; ++i){
            int ii = (id)%n+i;
            ii = id+i;
            if(ii>n) ii -= n; 
            if(x[ii]>=x[last]&&y[ii]>=y[last]){
                last = ii;
                q.push(ii);
            }else break;
        }
        double t = 0;
        double nowx = 0,nowy = 0;
        while(q.size()){
            int nowid = q.front(); q.pop();
            //prln(nowid);
            //pr(x[nowid]);pr(nowx);prln(v);
            double ut = (x[nowid]-nowx)*1.0/v;
            //prln(ut);
            nowx = x[nowid];
            nowy += ut*u;
            t += ut;
            nowy = min(nowy, 1.0*y[nowid]);
            //pr(nowx);prln(nowy);
        }
        t += (w-nowy)*1.0/u;
        double tt = 0;
        mix = INF, miy = INF;
        id = 0;
        for(int i = 1; i <= n; ++i){
            if(x[i]>=0)
            if(x[i]<mix||(x[i]==mix&&y[i]<=miy)){
                mix = x[i];
                miy = y[i];
                id = i;
            }
        }
        queue<int> qq;
        bool ok = true;
        last = id;
        qq.push(id);
        //prln(id);
        for(int i = 1; i < n; ++i){

            int ii = ((id)%n-i)%n;
            ii = id-i;
            if(ii<=0) ii += n;
            //ii = (ii+n)%n;
            //prln(ii);
            if(x[ii]>=x[last]&&y[ii]>=y[last]){
                qq.push(ii);
                last = ii;
            }else break;
        }
        nowx = 0, nowy = 0;
        tt = 0;
       if(lx<0) ok = false;
        if(lx>=0)
        while(qq.size()){
            int nowid = qq.front(); qq.pop();
            double ut = (x[nowid]-nowx)*1.0/v;
            if(ut<0){
                ok = false;
                break;
            }
            //pr(nowx);pr(x[nowid]);
            nowx = x[nowid];
            nowy += ut*u;
            tt += ut;
            //pr(nowid);pr(ut);pr(nowy);prln(y[nowid]);
            //nowy = min(nowy, 1.0*y[nowid]);
            if(nowy < y[nowid]){
                ok = false;
                break;
            }

        }
        if(ok){
            //prln(tt);
            tt += (w-nowy)*1.0/u;
        }
        if(ok) t = min(t,tt);
        printf("%.10f\n", t);
    }
	return 0;
}
