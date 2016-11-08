#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <vector>

using namespace std;
const int maxn = 4e5+1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define rep(i,n) for(int i = 0;i < n; i++)
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
char s[2][30];
char ss[30];
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\zero\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\zero\\Desktop\\out.txt","w",stdout);
 #endif
    bool ok = false;
    scanf("%s",ss);
    for(int i = 0; i < 27; ++i){
        for(int j = i+2; j < 27; ++j){
            if(ss[i]==ss[j]){
                ok = true;
                if((j-i)&1){
                    int len = (j-i)/2;
                    s[0][12-len] = ss[i];
                    int cnt = i-1;
                    int pos = 12-len-1;
                    for(int k = 12-len-1; k >= 0 && cnt>=0; --k){
                        s[0][k] = ss[cnt--];
                    }
                    pos = 0;
                    while(cnt >= 0){
                        s[1][pos++] = ss[cnt--];
                    }
                    //0you
                    cnt = i+1;
                    for(int k = 13-len; k < 13; ++k){
                        s[0][k] = ss[cnt++];
                    }
                    for(int k = 12; k > 12-len; --k){
                        s[1][k] = ss[cnt++];
                    }
                    cnt++;
                    for(int k = 12-len; k >= 0 && cnt < 27; --k){
                        s[1][k] = ss[cnt++];
                    }
                    pos = 0;
                    while(cnt<27){
                        s[0][pos++] = ss[cnt++];
                    }
                }else{
                    int len = (j-i)/2-1;
                    s[0][12-len] = ss[i];
                    int cnt = i-1;
                    int pos = 12-len-1;
                    for(int k = 12-len-1; k >= 0 && cnt>=0; --k){
                        s[0][k] = ss[cnt--];
                    }
                    pos = 0;
                    while(cnt >= 0){
                        s[1][pos++] = ss[cnt--];
                    }
                    //0you
                    cnt = i+1;
                    for(int k = 13-len; k < 13; ++k){
                        s[0][k] = ss[cnt++];
                    }
                    for(int k = 12; k >= 12-len; --k){
                        s[1][k] = ss[cnt++];
                    }
                    cnt++;
                    for(int k = 12-len-1; k >= 0 && cnt < 27; --k){
                        s[1][k] = ss[cnt++];
                    }
                    pos = 0;
                    while(cnt<27){
                        s[0][pos++] = ss[cnt++];
                    }
                }
            }
        }
    }
    if(ok) {
        s[0][13] = s[1][13] = 0;
        printf("%s\n%s\n",s[0],s[1]);
    }else{
        printf("Impossible\n");
    }
    return 0;
}
