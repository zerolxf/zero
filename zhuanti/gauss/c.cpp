/*************************************************************************
	> File Name: c.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月27日 星期三 18时17分42秒
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
int equ,var;
const int MAXN = 77;
ll a[MAXN][MAXN]; //增广矩阵
ll x[MAXN]; //解集
int free_x[MAXN];//用来存储自由变元(多解枚举自由变元可以使用)
int free_num;//自由变元的个数
//返回值为-1表示无解,为0是唯一解,否则返回自由变元个数
int n;


void Debug(void)
{
    int i, j;
    for (i = 0; i < equ; i++)
    {
        for (j = 0; j < var + 1; j++)
        {
            printf("%5lld ",a[i][j]);
            //cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


inline ll gcd(ll a,ll b)
{
    ll t;
    while(b!=0)
    {
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}
inline ll lcm(ll a,ll b)
{
    return a/gcd(a,b)*b;//先除后乘防溢出
}
int MOD;
inline ll ret(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y&1) ans = ans*x%MOD;
        x = x*x%MOD;
        y >>= 1;
    }
    return ans;
}
inline ll exgcd(ll temp, ll x){
    return temp*ret(x,MOD-2)%MOD;
}
// 高斯消元法解方程组(Gauss-Jordan elimination).(-2表示有浮点数解，但无整数解，
//-1表示无解，0表示唯一解，大于0表示无穷解，并返回自由变元的个数)
//有equ个方程，var个变元。增广矩阵行数为equ,分别为0到equ-1,列数为var+1,分别为0到var.
int Gauss(int equ,int var)
{
    int i,j,k;
    int max_r;// 当前这列绝对值最大的行.
    int col;//当前处理的列
    ll ta,tb;
    ll LCM;
    ll temp;
    int free_x_num;
    int free_index;

    for(int i=0;i<=var;i++)
    {
        x[i]=0;
        free_x[i]=true;
    }

    //转换为阶梯阵.
    col=0; // 当前处理的列
    for(k = 0;k < equ && col < var;k++,col++)
    {// 枚举当前处理的行.
// 找到该col列元素绝对值最大的那行与第k行交换.(为了在除法时减小误差)
        max_r=k;
        for(i=k+1;i<equ;i++)
        {
            if(fabs(a[i][col])>fabs(a[max_r][col])) max_r=i;
        }
        if(max_r!=k)
        {// 与第k行交换.
            for(j=k;j<var+1;j++) swap(a[k][j],a[max_r][j]);
        }
        if(a[k][col]==0)
        {// 说明该col列第k行以下全是0了，则处理当前行的下一列.
            k--;
            continue;
        }
        for(i=k+1;i<equ;i++)
        {// 枚举要删去的行.
            if(a[i][col]!=0)
            {
                //a[i][j] = (a[i][j]%MOD+MOD)%MOD;
                a[i][col] = (a[i][col]%MOD + MOD)%MOD;
                a[k][col] = (a[k][col]%MOD + MOD)%MOD;
                LCM = lcm(fabs(a[i][col]),fabs(a[k][col]));
                ta = LCM/fabs(a[i][col]);
                tb = LCM/fabs(a[k][col]);
                if(a[i][col]*a[k][col]<0)tb=-tb;//异号的情况是相加
                for(j=col;j<var+1;j++)
                {
                    a[i][j] = a[i][j]*ta-a[k][j]*tb;
                    a[i][j] = (a[i][j]%MOD+MOD)%MOD;
                }
            }
        }
        //Debug();
    }

    //Debug();
    temp = 0;
    //prln(temp);
    // 1. 无解的情况: 化简的增广阵中存在(0, 0, ..., a)这样的行(a != 0).
    for (i = k; i < equ; i++)
    { // 对于无穷解来说，如果要判断哪些是自由变元，那么初等行变换中的交换就会影响，则要记录交换.
        if (a[i][col]%MOD != 0) return -1;
    }
    // 2. 无穷解的情况: 在var * (var + 1)的增广阵中出现(0, 0, ..., 0)这样的行，即说明没有形成严格的上三角阵.
    // 且出现的行数即为自由变元的个数.
    if (k < var)
    {
         //首先，自由变元有var - k个，即不确定的变元至少有var - k个.
        for (i = k - 1; i >= 0; i--)
        {
             //第i行一定不会是(0, 0, ..., 0)的情况，因为这样的行是在第k行到第equ行.
             //同样，第i行一定不会是(0, 0, ..., a), a != 0的情况，这样的无解的.
            free_x_num = 0; // 用于判断该行中的不确定的变元的个数，如果超过1个，则无法求解，它们仍然为不确定的变元.
            for (j = 0; j < var; j++)
            {
                if (a[i][j]%MOD != 0 && free_x[j]) free_x_num++, free_index = j;
            }
            if (free_x_num > 1) continue; // 无法求解出确定的变元.
             //说明就只有一个不确定的变元free_index，那么可以求解出该变元，且该变元是确定的.
            temp = a[i][var];
            for (j = 0; j < var; j++)
            {
                if (a[i][j]%MOD != 0 && j != free_index) temp -= a[i][j] * x[j];
                temp = temp%MOD;
            }
            //prln(temp);
            temp = (temp%MOD+MOD)%MOD;
            a[i][free_index] = (a[i][free_index]%MOD+MOD)%MOD;
            x[free_index] = exgcd(temp, a[i][free_index]);
            //x[free_index] = temp&a[i][free_index];
            //x[free_index] = x[free_index]&1;
            //x[free_index] = temp / a[i][free_index]; // 求出该变元.
            free_x[free_index] = 0; // 该变元是确定的.
        }
        //prln(var-k);
        return var - k; // 自由变元有var - k个.
    }
    // 2. 唯一解的情况: 在var * (var + 1)的增广阵中形成严格的上三角阵.
    // 计算出Xn-1, Xn-MOD ... X0.
    for (i = var - 1; i >= 0; i--)
    {
        temp = a[i][var];
        //prln(temp);
        temp =(temp+MOD)%MOD;
        for (j = i + 1; j < var; j++)
        {
            if (a[i][j]%MOD != 0) temp -= a[i][j] * x[j];
            temp = temp%MOD;
        }
        temp = (temp%MOD+MOD)%MOD;
        a[i][i] = (a[i][i]%MOD+MOD)%MOD;

        //if (temp % a[i][i] != 0) return -2; // 说明有浮点数解，但无整数解.
        x[i] = exgcd(temp, a[i][i]);
        //pr(a[i][i]);pr(temp);prln(x[i]);
        //x[i] = temp / a[i][i];
    }
    return 0;
}
char s[maxn];
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &MOD);
        scanf("%s", s);
        n = strlen(s);
        equ = var = n;
        for(int i = 0; i < n; ++i){
            if(s[i] == '*')a[i][n] = 0;
            else a[i][n] = s[i]-'a'+1;
            for(int j = 0; j < n; ++j){
                a[i][j] = ret(i+1, j);
            }
        }
        //Debug();
        int ans = Gauss(n, n);
        for(int i = 0; i < n; ++i){
            printf("%lld ", (x[i]+MOD)%MOD);
        }
        printf("\n");
    }
	return 0;
}
