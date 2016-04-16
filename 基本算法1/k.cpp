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
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
int num[200];
char s[100];
struct Node{
    string s;
    int flag ;
    bool operator < (const Node& rhs)const{
        if(s.size() < rhs.s.size()) {
            return true;
        } else if(s.size() > rhs.s.size()) return false;
        if(s.size()==3) {
            if(s[0] != rhs.s[0]) return num[s[0]] < num[rhs.s[0]];
            if(s[2] != rhs.s[2]) {
                return s[2]*flag > rhs.s[2]*rhs.flag;
            }
            return s[1] > rhs.s[1];
        }
        if(s[1] != rhs.s[1]) {
            return s[1]*flag > rhs.s[1]*rhs.flag;
        }
            return s[0] > rhs.s[0];
    }
};
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    priority_queue<Node> B,W;
    scanf("%s", s);
    num['K'] = 10;num['k'] = 10;
    num['Q'] = 9; num['q'] = 9;
    num['R'] = 8; num['r'] = 8;
    num['B'] = 7; num['b'] = 7;
    num['N'] = 6; num['n'] = 6;
    for(int i = 0; i < 8; ++i) {
        scanf("%s", s);
        for(int j = 0; j < 8; ++j) {
            string ch;
            ch  += s[2+j*4];
            if(ch[0] <= 'Z' && ch[0] >= 'A') {
                if(ch=="P") ch="";
                ch += ('a'+j);
                ch += ('1'+7-i);
                W.push(Node{ch,1});
            } else if(ch[0] <= 'z' && ch[0] >= 'a') {
                if(ch=="p") ch="";
                else ch[0] += 'A'-'a';
                ch += ('a'+j);
                ch += ('1'+7-i);
                B.push(Node{ch,-1});
            }
        }
        scanf("%s", s);
    }
        printf("White: ");
        if(W.size()) {
            Node x = W.top();W.pop();
            cout << x.s;
        }
        while(W.size()) {
            Node x = W.top();W.pop();
            cout << "," << x.s;
        }
        cout << "\n";
        printf("Black: ");
        if(B.size()) {
            Node x = B.top();B.pop();
            cout << x.s;
        }
        while(B.size()) {
            Node x = B.top();B.pop();
            cout << "," << x.s;
        }
        cout << "\n";
    return 0;
}
