
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
const int maxn = 1e5+100;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x <<endl;
#define ll long long
int nxt[maxn];
struct node{
    int i , j;
    node(int i, int j):i(i),j(j){}
    node();
};
void GetFail(string& p) {
    for(int i = 0; i <= p.size(); ++i) nxt[i] = 0;
    for(int i = 1; i < p.size(); ++i) {
        int j = nxt[i];
        while(j && p[i] != p[j]) j = nxt[j];
        nxt[i + 1] = (p[i] == p[j])? j+1 : 0;
    }
}
int MR(string &s, int l){
    int i = 0, j = 1, k = 0;
    while(i < l && j < l) {
        k = 0;
        while(s[i+k] == s[j+k]) ++k;
        if(k == l) return min(i,j);
        if(s[i+k] < s[j+k]) i = max(j+1, i+k+1);
        else j = max(i+1, j+k+1);
    }
    return min(i,j);
}
int KmpSearch(string &s, string &p) {
    GetFail(p);
    int j = 0;
    int ans = -1;
    for(int i = 0; i < s.size(); ++i) {
        while(j && s[i] != p[j]) j = nxt[j];
        if(s[i] == p[j]) ++j;
        if(j == p.size()) {
            int pos = i - p.size() + 1;
            if(pos >= p.size()) break;
            ans = pos;
        }
    }
    return ans;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\lxf\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\lxf\\Desktop\\out.txt","w",stdout);
 #endif
    int t, l;cin >> t;
    while(t--) {
        string s1, s2, s3;
        cin >> l >> s1;
        s1 += s1;
        for(int i = 0; i < l; ++i) s2 += s1[l-i-1];
        s2 += s2;
        s3 = s2;
        int x1 = MR(s1,l), x2 = MR(s2, l);

        s1 = s1.substr(x1,l);
        s2 = s2.substr(x2,l);
        x2 = l - KmpSearch(s3,s2);
        if(s1 > s2) cout << x1 + 1 << " 0\n";
        else if(s1 < s2) cout << x2 <<" 1\n";
        else {
            if(x1 + 1 <= x2) cout << x1+1 << " 0\n";
            else cout << x2 << " 1\n";
        }
    }
    return 0;
}
