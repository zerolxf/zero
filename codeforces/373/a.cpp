/*************************************************************************
    > File Name: a.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年09月23日 星期五 21时04分40秒
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
int a[maxn], b[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif

    int n;
    while(cin>>n){
        for(int i = 0; i < n; ++i){
            scanf("%d",&a[i]);
        }
        if(n==1){
            if(a[0]==15) cout<<"DOWN\n";
            else if(a[0]==0) cout<<"UP\n";
            else cout<<"-1\n";
            continue;
        }else{

            if(a[n-1]==15) cout<<"DOWN\n";
            else if(a[n-1]==0) cout<<"UP\n";
            else{
                if(a[n-1]>a[n-2]) cout<<"UP\n";
                else cout<<"DOWN\n";
            }

        }

    }
	return 0;
}
