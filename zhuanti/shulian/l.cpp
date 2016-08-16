/*************************************************************************
	> File Name: l.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年07月02日 星期六 16时50分02秒
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
int pre[maxn], ch[maxn][2], size[maxn], rev[maxn];
int add[maxn], key[maxn], m[maxn], a[maxn];
#define Key_value ch[ch[root][1]][0]
int s[maxn];
int root, root1, tot1, tot2;
int n;
void NewNode(int &r, int father, int k){
    if(tot2) r = s[tot2--];
    else r = ++tot1;
    pre[r] = father;
    ch[r][0] = ch[r][1] = 0;
    size[r] = 1;
    rev[r] = add[r] = 0;
    key[r] = m[r] = k;

}
void Update_Rev(int r){
    if(!r) return;
    swap(ch[r][0], ch[r][1]);
    rev[r] ^=1;
}
void Update_Add(int r, int ADD){
    if(!r) return;
    add[r] = ADD;
    key[r] = ADD;
    m[r] = ADD*size[r];
}
void Push_Up(int r){
    size[r] = size[ch[r][0]] + size[ch[r][1]] + 1;
    m[r] = key[r];
    if(ch[r][0]) m[r] +=  m[ch[r][0]];
    if(ch[r][1]) m[r] +=  m[ch[r][1]];
}
void Push_Down(int r){
    if(rev[r]) {
        Update_Rev(ch[r][0]);
        Update_Rev(ch[r][1]);
        rev[r] = 0;
    }
    if(add[r]!=INF){
        Update_Add(ch[r][0], add[r]);
        Update_Add(ch[r][1], add[r]);
        add[r] = INF;
    }
}
void Build(int &x, int l, int r,int father){
    if(l>r) return;
    int mid = (l+r)>>1;
    NewNode(x, father, a[mid]);
    Build(ch[x][0],l,mid-1,x);
    Build(ch[x][1],mid+1,r, x);
    Push_Up(x);
}
void Init(){
   root = tot1 = 0;
    tot2 = 0;
   ch[root][0] = ch[root][1] = size[root] = rev[root] = 0;
    pre[root] =  0;
    add[root] = INF;
    m[root] = 0;
    NewNode(root, 0, 0);
    NewNode(ch[root][1], root, 0);
    Build(Key_value, 1, n, ch[root][1]);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
void Rotate(int x, int kind) {
    int y = pre[x];
    Push_Down(y);
    Push_Down(x);
    ch[y][!kind] = ch[x][kind];
    pre[ch[x][kind]] = y;
    if(pre[y]) ch[pre[y]][ch[pre[y]][1]==y] = x;
    pre[x] = pre[y];
    ch[x][kind] = y;
    pre[y] = x;
    Push_Up(y);
}
void Splay(int r, int goal) {
    Push_Down(r);
    while(pre[r] != goal) {
        if(pre[pre[r]] == goal) {
            Push_Down(pre[r]);
            Push_Down(r);
            Rotate(r, ch[pre[r]][0] == r);
        }else{
            Push_Down(pre[pre[r]]);
            Push_Down(pre[r]);
            Push_Down(r);
            int y = pre[r];
            int kind = (ch[pre[y]][0] == y);
            if(ch[y][kind] == r) {
                Rotate(r, !kind);
                Rotate(r, kind);
            }else {
                Rotate(y, kind);
                Rotate(r, kind);
            }
        }
    }
    Push_Up(r);
    if(goal == 0) root = r;
}
int Get_Min(int r) {
    Push_Up(r);
    while(ch[r][0]){
        r = ch[r][0];
        Push_Down(r);
    }
    return r;
}
int Get_Max(int r) {
    Push_Down(r);
    while(ch[r][1]){
        r = ch[r][1];
        Push_Down(r);
    }
    return r;
}
int Get_Kth(int r, int k){
    Push_Down(r);
    int t = size[ch[r][0]] + 1;
    if(t == k) return r;
    if(t > k) return Get_Kth(ch[r][0], k);
    else return Get_Kth(ch[r][1], k-t);
}
void ADD(int l, int r, int D){
    Splay(Get_Kth(root, l), 0);
    Splay(Get_Kth(root, r+2), root);
    Update_Add(Key_value, D);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
void Reverse(int l, int r){
    Splay(Get_Kth(root, l), 0);
    Splay(Get_Kth(root, r+2), root);
    Update_Rev(Key_value);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
void Revolve(int l, int r, int T){
    int len = r-l+1;
    T = (T%len+len)%len;
    if(T==0) return;
    int c = r - T+1;
    Splay(Get_Kth(root, c), 0);
    Splay(Get_Kth(root, r+2), root);
    int tmp = Key_value;
    Key_value = 0;
    Push_Up(ch[root][1]);
    Push_Up(root);
    Splay(Get_Kth(root,l), 0);
    Splay(Get_Kth(root,l+1), root);
    Key_value = tmp;
    pre[Key_value] = ch[root][1];
    Push_Up(ch[root][1]);
    Push_Up(root);

}
void Insert(int x, int y){
    Splay(Get_Kth(root, x+1), 0);
    Splay(Get_Kth(root, x+2), root);
    Build(Key_value, 1, y, ch[root][1]);
//    NewNode(Key_value, ch[root][1], P);
    Push_Up(ch[root][1]);
    Push_Up(root);
}
void erase(int r){
    if(r) {
        s[++tot2] = r;
        erase(ch[r][0]);
        erase(ch[r][1]);
    }
}
void Delete(int x, int y) {
    Splay(Get_Kth(root, x), 0);
    Splay(Get_Kth(root, y+2), root);
    erase(Key_value);
    pre[Key_value] = 0;
    Key_value = 0;
    Push_Up(ch[root][1]);
    Push_Up(root);
}
int Query_Min(int l, int r){
    Splay(Get_Kth(root, l), 0);
    Splay(Get_Kth(root, r+2), root);
    return m[Key_value];
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    char op[10];
    int x, y, z;
    while(scanf("%d", &n) == 1){
        for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        Init();
        int q;
        scanf("%d", &q);
        while(q--) {
            scanf("%s", op);
            if(strcmp(op, "3") == 0){
                scanf("%d%d%d", &x, &y, &z);
                ADD(x, x+y-1, z);
            }else if(strcmp(op, "4") == 0){
                scanf("%d%d", &x, &y);
                Reverse(x, x+y-1);
            }else if(strcmp(op, "REVOLVE") == 0){
                scanf("%d%d%d", &x, &y, &z);
                Revolve(x, y, z);
            }else if(strcmp(op, "1") == 0){
                scanf("%d%d", &x, &y);
                for(int i = 1; i <= y; ++i){
                    scanf("%d", &a[i]);
                }
                Insert(x, y);
            }else if(strcmp(op, "2") == 0){
                scanf("%d%d", &x, &y);
                Delete(x, y+x-1);
            }else {
                scanf("%d%d", &x, &y);
                printf("%d\n", Query_Min(x, x+y-1));
            }
        }
    }
	return 0;
}
