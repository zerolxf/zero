/*************************************************************************
    > File Name: i.cpp
    > Author: liangxianfeng
    > Mail:   liangxianfeng96@qq.com
    > Created Time: 2016年08月08日 星期一 13时51分06秒
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
const int maxn = 1e5+100;
const int INF = 0x3f3f3f3f;
int tr[21][maxn], nxt[maxn*20][5], num[maxn*20];
char s[maxn], t[maxn];
int siz;
char temp[30];
bool is(int len){
    for(int p = 0, q = len-1; p < q; p++,q--){
        if(temp[p] != temp[q]) return false;
    }
    return true;
}
//bool is(char str[], int pos, int len){
    //for(int i = 0; i < len/2; ++i){
        //if(str[pos + i] != str[pos+len-i-1]) return false;
    //}
    //return true;
//}
void update(int &ntr, int ptr, char str[], int pos){
    ntr = ++siz;
    num[ntr] = num[ptr] + 1;
    for(int i = 0; i < 5; ++i){
        nxt[ntr][i] = nxt[ptr][i];
    }
    //prln(str[pos]);
    //pr(ntr);pr(ptr);pr(num[ntr]);prln(num[ptr]);
    if(str[pos] == '\0') return;
    update(nxt[ntr][str[pos]-'a'], nxt[ptr][str[pos]-'a'], str, pos+1);

}
int query(int r, int l, char str[], int pos){
    if(str[pos] == '\0'){
        //prln(str);
        //pr(r);prln(l);
        //pr(num[r]);prln(num[l]);
        return num[r] - num[l];
    }
    return query(nxt[r][str[pos]-'a'], nxt[l][str[pos]-'a'], str, pos+1);
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    while(scanf("%s", s+1) != EOF){
        int len = strlen(s+1);
        memset(tr, 0, sizeof tr);
        memset(num, 0, sizeof num);
        memset(nxt[0], 0, sizeof nxt[0]);
        memset(nxt[1], 0, sizeof nxt[1]);
        siz = 0;
        for(int i = 1; i <= 20; ++i){
            for(int j = i; j <= len; ++j){
                for(int p = 0, q = j-i+1; q <= j; ++q,p++){
                    temp[p] = s[q];
                }
                temp[i] = '\0';
                if(is(i)){
                    //pr(i);prln(temp);
                    update(tr[i][j], tr[i][j-1], temp, i/2);
                }else tr[i][j] = tr[i][j-1];
            }
        }
        //prln("query");
        int q, l, r;
        scanf("%d", &q);
        for(int i = 0; i < q; ++i){
            scanf("%d%d%s", &l, &r, temp);
            //int lent = strlen(temp);
            int ans = 0;
            for(int j = 1;  j <= 20 && l <= r; ++j, ++l)
            ans += query(tr[j][r], tr[j][l-1], temp, 0);
            printf("%d\n",ans);
        }
    }
	return 0;
}
