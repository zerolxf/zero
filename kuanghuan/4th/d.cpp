/*************************************************************************
    > File Name: d.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月07日 星期日 10时55分57秒
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
ll a[maxn], x, y, z, xx, yy, zz;
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(cin >> x >> y >> z >> xx >> yy >> zz){
        for(int i = 1; i <= 6; ++i){
            cin >> a[i];
        }
        ll sum = 0;
        if(x < 0) sum += a[5];
        else if(x > xx) sum += a[6];
        if(y < 0) sum += a[1];
        else if(y > yy) sum += a[2];
        if(z < 0) sum += a[3];
        else if(z > zz) sum += a[4];
        cout<<sum<<"\n";

    }
	return 0;
}
