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
    //s是内存池,一旦有东西加入tot2++,这样tot2就不为空为真,就进入内存池取一个节点,s存的只是一个编号
    //tot1表示已经使用的最好编号
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
    add[r] += ADD;
    key[r] += ADD;
    m[r] += ADD;
}
void Push_Up(int r){
    size[r] = size[ch[r][0]] + size[ch[r][1]] + 1;
    m[r] = key[r];
    if(ch[r][0]) m[r] = min(m[r], m[ch[r][0]]);
    if(ch[r][1]) m[r] = min(m[r], m[ch[r][1]]);
}
void Push_Down(int r){
    if(rev[r]) {
        Update_Rev(ch[r][0]);
        Update_Rev(ch[r][1]);
        rev[r] = 0;
    }
    if(add[r]){
        Update_Add(ch[r][0], add[r]);
        Update_Add(ch[r][1], add[r]);
        add[r] = 0;
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
    pre[root] = add[root] = 0;
    m[root] = INF;
    //Newnode参数 第一个引用赋值node节点编号,第二个是父亲节点,第三个是键值
    //初始的两个键值更具具体题目意思设定,这里由于多加两个节点,以后,增删改查的适合索引号加+1
    //为什么不是加2?因为是放在另一非root节点的左儿子上面,这样这个非root节点就不必算上了,根据感觉他以后一直都会排在最后面
    //至于这两个点为什么要?可能就是为了凑出root和他的右儿子,以至于不需要因为点不足不好插?
    NewNode(root, 0, INF);
    NewNode(ch[root][1], root, INF);
    //build的话,统一作为root右儿子的左儿子,也就是定义好的Key_value
    Build(Key_value, 1, n, ch[root][1]);
    //由于旋转的原因,所以这里和根节点也就两层关系,pushdown要立马push上去,但是不需要向线段树那样递归了
    Push_Up(ch[root][1]);
    Push_Up(root);
}
//1 表示右旋, 0表示左旋
void Rotate(int x, int kind) {
    int y = pre[x];
    Push_Down(y);
    Push_Down(x);
    //总结就是有三个ch改变,三个pre改变,其中要判断一下pre[y]的存在
    ch[y][!kind] = ch[x][kind];
    pre[ch[x][kind]] = y;
    //ch[pre[y]][1] == y相当于获取当前y是他父亲左儿子还是右儿子
    if(pre[y]) ch[pre[y]][ch[pre[y]][1]==y] = x;
    pre[x] = pre[y];
    ch[x][kind] = y;
    pre[y] = x;
    Push_Up(y);
}
void Splay(int r, int goal) {
    //进行任何操作前都要pushDown,这和线段树原理是一样的
    Push_Down(r);
    //我们现在要把r调到goal下面,所以如果已经在下面了什么都不要做,否则r和goal必定差两代
    while(pre[r] != goal) {
        //如果只需要一次rorate
        //当是这样感觉好像有点问题,不能保持遍历有序?
        //按照下面之字形那种平衡树大小移动后相对不变的感觉,发现好像遍历依旧有序
        //感觉是对的,kuangbin博客那个单旋图好像有点问题,跟着感觉走
        if(pre[pre[r]] == goal) {
            Push_Down(pre[r]);
            Push_Down(r);
            //比较神奇的一个比较ch[pre[y]][0] == r这个表达式的值是和旋转方向相同,和节点方向相反的
            //同时ch[pre[y]][1] == r这个表达式的值和节点方向相同,他是这样的让为真时指向右节点
            Rotate(r, ch[pre[r]][0] == r);
        }else{
            //一字型和之字形旋转
            //把r上调两代,所以两代以前的延迟必须要pushdown
            Push_Down(pre[pre[r]]);
            Push_Down(pre[r]);
            Push_Down(r);
            int y = pre[r];
            //如上面所示,左儿子的话就是右旋,那么kind=1否则kind=0,和节点方向相反
            //右儿子就是左旋
            //第一个实际可以不用kind表示,他只是把kind当做一个01常量了
            int kind = (ch[pre[y]][0] == y);
            //如果kind是0同时r是左子节点则true或者 kind是1同时r是右子节点则需要左旋
            //旋转类型和kind01相反,也就是说ch[pre[y]][!kind]==y属于一字型,而下面属于相反之字形
            //所以下面的第二个旋转一定是kind是可以的,如果同向的话,那么第二次一字型旋转方向同之前kind,之字形同r旋转到了y的位置所以也是kind
           if(ch[y][kind] == r) {
                //之字形
                //之字形只要动r节点
                //这样就可以保证遍历有序性,模拟一下过程
                Rotate(r, !kind);
                Rotate(r, kind);
            }else {
                //一字型
                //先动父亲在动自己为什么可以保证遍历有序的性质?
                //感觉就是这里y的右子节点遍历顺序小于y同时大于pre[y],那么之字形旋转之后y的右节点跑到pre[y]的左子节点同样符合性质
                //就好比平衡树大小移动一样
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
void Insert(int x, int P){
    Splay(Get_Kth(root, x+1), 0);
    Splay(Get_Kth(root, x+2), root);
    NewNode(Key_value, ch[root][1], P);
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
void Delete(int x) {
    Splay(Get_Kth(root, x), 0);
    Splay(Get_Kth(root, x+2), root);
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
            if(strcmp(op, "ADD") == 0){
                scanf("%d%d%d", &x, &y, &z);
                ADD(x, y, z);
            }else if(strcmp(op, "REVERSE") == 0){
                scanf("%d%d", &x, &y);
                Reverse(x, y);
            }else if(strcmp(op, "REVOLVE") == 0){
                scanf("%d%d%d", &x, &y, &z);
                Revolve(x, y, z);
            }else if(strcmp(op, "INSERT") == 0){
                scanf("%d%d", &x, &y);
                Insert(x, y);
            }else if(strcmp(op, "DELETE") == 0){
                scanf("%d", &x);
                Delete(x);
            }else {
                scanf("%d%d", &x, &y);
                printf("%d\n", Query_Min(x, y));
            }
        }
    }
	return 0;
}
