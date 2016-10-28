/*************************************************************************
	> File Name: b.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年08月05日 星期五 18时34分37秒
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
char s[maxn];
int vis[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(scanf("%s", s) != EOF){
        int lens = strlen(s);
        int index = 0;
        for(int i = 0; i < lens; ++i){
            if(s[i] == ':') index = i;
        }
        for(int i = 0; i < index; ++i) a[i] = s[i];
        for(int i = index+1; i < lens; ++i) b[i-1-index] = s[i];
        a[index] = 0;
        b[lens-index] = 0;
        int lena = strlen(a);
        int lenb = strlen(b);
        //pr(lena);prln(lenb);
        //prln(a);prln(b);
        int numa = 0, numb = 0;
        bool ok = true;
        memset(vis, 0, sizeof vis);
        int mi = 1;
        for(int i = 0; i < lena; ++i){
            if(a[i] == '0') numa++;
            else break;
        }
        for(int i = 0; i < lenb; ++i){
            if(b[i] == '0') numb++;
            else break;
        }
        //pr(numa);prln(numb);
        if(lena-numa<=1&&lenb-numb<=1){
            ok = false;
        }
        for(int i = 1; i <= 60; ++i){
            ll aa = 0;
            for(int j = 0; j < lena; ++j){
                int c = a[j] - '0';
                if(a[j]>='A'&&a[j]<='Z') c = a[j]-'A'+10;
                aa = aa*i+c;
                mi = max(mi, c);
                if(c>=i) {
                    aa = INF;
                    break;
                }
            }
            //pr(i);prln(aa);
            if(aa<24) vis[i]++;
        }
        for(int i = 1; i <= 60; ++i){
             ll aa = 0;
            for(int j = 0; j < lenb; ++j){
                int c = b[j] - '0';
                if(b[j]>='A'&&b[j]<='Z') c = b[j]-'A'+10;
                aa = aa*i+c;
                mi = max(mi, c);
                if(c>=i) {
                    aa = INF;
                    break;
                }
            }
            if(aa<60) vis[i]++;
        }
        vector<int> ans;
        //prln(mi);
        for(int i = mi+1; i <= 60; ++i){
            if(vis[i]  == 2){
                ans.push_back(i);
            }
        }

        if(ans.size()==0){
            printf("0\n");
            continue;
        }
        else if(!ok){
            printf("-1\n");
        }else{
            for(int i = 0; i < ans.size(); ++i){
                printf("%d ", ans[i]);
            }
            printf("\n");
            //printf("%d")
        }

    }
	return 0;
}
