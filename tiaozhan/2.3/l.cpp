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
const int maxn = 5e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
bool vis[maxn];
struct Node{
    int a, h, c;
    bool operator < (const Node& rhs)const{
        return a < rhs.a || (a==rhs.a&&h>rhs.h)||(a==rhs.a&&h==rhs.h&&c>rhs.c);
    }
}node[maxn];
int a[maxn], h[maxn], c[maxn];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    int n;
    while(cin >> n) {
        for(int i = 0; i < n; ++i) {
            scanf("%d%d%d", &node[i].h, &node[i].a, &node[i].c);
        }
        sort(node, node+n);
        Node temp = Node{-1,-1,-1};
        int num,maxh,av,ac,l,ans=0;
        vis[0] = 1;
        for(int i = 0; i < n; ++i) {
            num = node[i].c;
            ac = 1;
            while(ac <= num) {
              //  pr(i);prln(ac);
                av = ac*node[i].h;
               // prln(av);
                l = node[i].a-av;
                while(l>=0) {
                    if(!vis[l+av]&&vis[l]) {
                        vis[l+av]=true;
                        if(l+av>ans) ans = l+av;
                    }
                    l--;
                }
                num-=ac;
                ac = ac<<1;
            }
            if(num>0) {
                av = num*node[i].h;
                l = node[i].a-av;
                while(l>=0) {
                    if(!vis[l+av]&&vis[l]) {
                        vis[l+av]=true;
                        if(l+av>ans) ans = l+av;
                    }
                    l--;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
