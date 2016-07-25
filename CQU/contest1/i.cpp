/*************************************************************************
	> File Name: i.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月18日 星期一 08时49分35秒
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
char a[maxn], b[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%s%s", a, b);
        int lena = strlen(a);
        int lenb = strlen(b);
        int index = 1;
        for(int i = index; i < lenb; ++i){
            if(b[i] != b[i-1]) break;
            index++;
        }
        bool ok = true;
        for(int i = 0; i < index; ++i){
            if(a[i] != b[i]) ok = false;
        }
        int l = index, r = index;
        while(l < lena && r < lenb){
            while(r < lenb && a[l] != b[r]) r++;
            if(a[l] == b[r]) l++,r++;
        }
        if(l!= lena) ok = false;
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
	return 0;
}
