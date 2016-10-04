/*************************************************************************
    > File Name: d.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月14日 星期三 01时17分08秒
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
/*#define pr(x) cout << #x << " = " << x << " ";*/
/*#define prline(a,b,c,d) get(a,b,c,d);*/
#define prline(a, b, c, d) cout << "? " << a << " "<< b << " " << c << " " << d << endl;
/*#define prln(x) cout << #x << " = " << x <<  endl; */
const int maxn = 4e5+100;
const int INF = 0x3f3f3f3f;

int xl[10], xr[10], xu[10], xd[10];
int get(int a, int b, int c, int d){
    int ans = 0;
    rep(i,2){
        if(a<=xl[i] && xr[i] <= c){
            if(b <= xd[i] && xu[i] <= d){
                ans++;
            }
        }
    }
    return ans;
}
int getl(int l, int d, int r, int u, int x){
    int num = 0;
    int lx = l, rx = r;
    while(lx < rx){
        int mid = (lx+rx+1) >> 1;
        prline(mid, d, r, u);
        /*num = prline(mid, d, r, u);*/
        cin >> num;
        if(num>=x) lx = mid;
        else rx = mid-1;
    }
    return lx;
}
int getr(int l, int d, int r, int u, int x){
    int lx = l, rx = r;
    int num = 0;
    while(lx < rx){
        int mid = (lx+rx) >> 1;
        prline(l, d, mid, u);
        /*num = prline(l, d, mid, u);*/
        cin >> num;
        if(num>=x) rx = mid;
        else lx = mid+1;
    }
    return lx;
}
int getu(int l, int d, int r, int u, int x){

    int uy = u, dy = d;
    int num = 0;
    while(dy < uy){
        int mid = (uy+dy) >> 1;
        prline(l, d, r, mid);
        /*num = prline(l, d, r, mid);*/
        cin>>num;
        if(num>=x) uy = mid;
        else dy = mid+1;
    }
    return dy;
}
int getd(int l, int d, int r, int u, int x){
    int num = 0;
    int dy = d, uy = u;
     while(dy < uy){
        int mid = (uy+dy+1) >> 1;
        prline(l, mid, r, u);
        /*num = prline(l, mid, r, u);*/
        cin>>num;
        if(num >= x) dy = mid;
        else uy = mid-1;
    }
     return dy;
}
int ansl[10], ansr[10], ansu[10], ansd[10];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    cin>>n;
    cout<<"? 1 1 5 5"<<endl;
    /*while(cin>>n){*/
        /*rep(i,2){*/
            /*cin>>xl[i]>>xd[i]>>xr[i]>>xu[i];*/
        /*}*/
        ansl[0] = getl(1, 1, n, n, 1);
        ansl[1] = getl(1, 1, n, n, 2);

        ansr[0] = getr(1, 1, n, n, 1);
        ansr[1] = getr(1, 1, n, n, 2);

        ansu[0] = getu(1, 1, n, n, 1);
        ansu[1] = getu(1, 1, n, n, 2);

        ansd[0] = getd(1, 1, n, n, 1);
        ansd[1] = getd(1, 1, n, n, 2);

        /*rep(i,2){*/
            /*cout<<ansl[i] << " " << ansr[i] << " " << ansd[i] << " " << ansu[i] << endl;*/
        /*}*/

        for(int i = 0; i < 16; ++i){
            int num[10];
            for(int j = 0; j < 4; ++j){
                num[j] = (i>>j)&1;
            }
            int x = 0, y = 0;
            prline(ansl[num[0]], ansd[num[1]], ansr[num[2]], ansu[num[3]]);
            /*pr(ansl[num[0]]);pr(ansd[num[1]]);pr(ansr[num[2]]);prln(ansu[num[3]]);*/
            cin>>x;
            prline(ansl[1-num[0]], ansd[1-num[1]], ansr[1-num[2]], ansu[1-num[3]]);
            cin>>y;
            //pr(x);prln(y);
            //x = prline(ansl[num[0]], ansd[num[1]], ansr[num[2]], ansu[num[3]]);
            //y = prline(ansl[1-num[0]], ansd[1-num[1]], ansr[1-num[2]], ansu[1-num[3]]);
            //pr(i);pr(x);prln(y);
            if(x==1&&y==1){
                if(ansl[num[0]] > ansr[num[2]]) continue;
                if(ansd[num[1]] > ansu[num[3]]) continue;
                if(ansl[1-num[0]] > ansr[1-num[2]]) continue;
                if(ansd[1-num[1]] > ansu[1-num[3]]) continue;
                if((ansl[num[0]] < ansl[1-num[0]] && ansl[1-num[0]] < ansr[num[2]]) || (ansl[num[0]] < ansr[1-num[2]] && ansr[1-num[2]] < ansr[num[2]])){
                    if((ansd[num[1]] < ansd[1-num[1]] && ansd[1-num[1]] < ansu[num[3]]) || (ansd[num[1]] < ansu[1-num[3]] && ansu[1-num[3]] < ansu[num[3]])){
                        continue;
                    }

                }
                cout << "! " << ansl[num[0]] << " " << ansd[num[1]] << " " << ansr[num[2]] << " " << ansu[num[3]];
                cout << " " << ansl[1-num[0]] << " " << ansd[1-num[1]] << " " << ansr[1-num[2]] << " " << ansu[1-num[3]] << endl;
                break;
            }
        }
    /*}*/
    

	return 0;
}
