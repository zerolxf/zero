
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
#include<sstream>

using namespace std;
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
char mp[10][10];
string W, B, WW, BB, ss;

void line() {
    printf("+---+---+---+---+---+---+---+---+\n");
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    while(getline(cin,ss)) {
        int len = ss.size();
        int r, c;
        for(int i = 0; i < 8; ++i) {
            for(int j = 0; j <8; ++j) {
                if((i+j)%2 ==0) {
                    mp[i][j] = ':';
                } else mp[i][j] = '.';
            }
        }
        for(int i = 0; i < len; ++i) {
            if(ss[i] == ',') ss[i] = ' ';
        }
        stringstream sss(ss);
        sss >> W;
        while(sss >> W) {
            if(W.size() == 3) {
                c = W[1] - 'a';
                r = W[2] - '1';
                mp[r][c] = W[0];
            } else {
                c = W[0] - 'a';
                r = W[1] - '1';
                mp[r][c] = 'P';
            }
        }
        //getchar();
        getline(cin,ss);
        for(int i = 0; i < len; ++i) {
            if(ss[i] == ',') ss[i] = ' ';
        }
        stringstream ssss(ss);
        ssss >> B;
        while(ssss >> B) {
            if(B.size() == 3) {
                c = B[1] - 'a';
                r = B[2] - '1';
                mp[r][c] = B[0] + 'a' - 'A';
            } else {
                c = B[0] - 'a';
                r = B[1] - '1';
                mp[r][c] = 'p';
            }
        }
        line();
        for(int i = 0; i < 8; ++i) {
            for(int j = 0; j < 8; ++j) {
                if((i+j)%2) {
                    printf("|:%c:",mp[7-i][j]);
                } else printf("|.%c.",mp[7-i][j]);
            }
            printf("|\n");
            line();
        }
    }
    return 0;
}
