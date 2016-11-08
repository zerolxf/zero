/*************************************************************************
	> File Name: b.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月15日 星期五 16时12分09秒
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
    cin >> t;
    while(t--){
        scanf("%s%s",a,b);
        int lena = strlen(a), lenb = strlen(b);
        bool ok = (lena==lenb);
        for(int i = 0; i< lena; ++i){
            if(a[i]>='a') a[i] += 'A'-'a';
            if(b[i]>='a') b[i] += 'A'-'a';
            if(a[i]=='B') a[i] =  'P';
            if(a[i]=='I') a[i] =  'E';
            if(b[i]=='B') b[i] =  'P';
            if(b[i]=='I') b[i] =  'E';
            if((a[i]!=b[i])) ok = false;
        }
        if(ok) printf("Yes\n");
        else printf("No\n");
    }
	return 0;
}
