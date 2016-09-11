/*************************************************************************
	> File Name: c.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年08月05日 星期五 19时15分52秒
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
int a[maxn];
int vis[maxn];
pair<int,int> node[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    while(cin >> n){
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            node[i].first = a[i];
            node[i].second = i;

        }
        MEM(vis,0);
        //sort(a,a+n);
        sort(node+1,node+n+1);
        vector<int> xx, yy;
        int x = 0, y = 0, numx = 0, numy = 0;
        for(int i = 1; i <= n; ++i){
            //pr(i);pr(node[i].first);prln(node[i].second);
            if(x == y){
                if(numx < numy){
                    numx += a[node[i].second];
                    x++;
                    xx.push_back(node[i].second);
                }else{
                    numy += a[node[i].second];
                    y++;
                    yy.push_back(node[i].second);
                }
            }else if(x<y){
                 numx += a[node[i].second];
                 x++;
                 xx.push_back(node[i].second);
            }else{
                numy += a[node[i].second];
                y++;
                yy.push_back(node[i].second);
            }
        }
        int xxsiz = xx.size();
        printf("%d", xxsiz);
        printf("\n");
        for(int i = 0; i < xxsiz; ++i){
            printf("%d ", xx[i]);
        }
        printf("\n");
        int yysiz = yy.size();
        printf("%d", yysiz);
        printf("\n");
        for(int i = 0; i < yysiz; ++i){
            printf("%d ", yy[i]);
        }
        printf("\n");
    }
	return 0;
}
