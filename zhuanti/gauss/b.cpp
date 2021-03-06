/*************************************************************************
	> File Name: b.cpp
	> Author: liangxianfeng
	> Mail:   liangxianfeng96@qq.com
	> Created Time: 2016年07月27日 星期三 16时09分39秒
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
const int maxn = 30;
const int INF = 0x3f3f3f3f;
const int MAXN = 22;
//有equ个方程,var个变元。增广矩阵行数为equ,列数为var+1,分别为0到var
int equ,var;
int a[MAXN][MAXN]; //增广矩阵
int x[MAXN]; //解集
int free_x[MAXN];//用来存储自由变元(多解枚举自由变元可以使用)
int free_num;//自由变元的个数
//返回值为-1表示无解,为0是唯一解,否则返回自由变元个数
int n;
void init(){
    memset(a, 0, sizeof a);
    memset(x, 0, sizeof x);
    equ = n;var = n;
    for(int i = 0; i < n; ++i){
        a[i][i] = 1;
        if(i>0) a[i][i-1] = 1;
        if(i < n-1) a[i][i+1] = 1;
    }
}

int Gauss()
{
    int max_r,col,k;
    free_num = 0;
    for(k = 0, col = 0 ; k < equ && col < var ; k++, col++)
    {
        max_r = k;
        for(int i = k+1;i < equ;i++)
        {
            if(abs(a[i][col]) > abs(a[max_r][col]))
            max_r = i;
        }
        if(a[max_r][col] == 0)
        {
            k--;
            free_x[free_num++] = col;//这个是自由变元
            continue;
        }
        if(max_r != k)
        {
            for(int j = col; j < var+1; j++)
            swap(a[k][j],a[max_r][j]);
        }
        for(int i = k+1;i < equ;i++)
        {
            if(a[i][col] != 0)
            {
                for(int j = col;j < var+1;j++)
                    a[i][j] ^= a[k][j];
            }
        }
    }
    for(int i = k;i < equ;i++)
        if(a[i][col] != 0)
            return -1;//无解
    if(k < var) return var-k;//自由变元个数
    //唯一解,回代
    for(int i = var-1; i >= 0;i--)
    {
        x[i] = a[i][var];
        for(int j = i+1;j < var;j++)
        x[i] ^= (a[i][j] && x[j]);
    }
    return 0;
}
void solve()
{
    int t = Gauss();
    //prln(t);
    //prln(free_x[0]);
    if(t == -1)
    {
        printf("inf\n");
        return;
    }
    else if(t == 0)
    {
        int ans = 0;
        for(int i = 0;i < n*n;i++)
        ans += x[i];
        printf("%d\n",ans);
        return;
    }
    else
    {
    //枚举自由变元
        int ans = 0x3f3f3f3f;
        int tot = (1<<t);
        for(int i = 0;i < tot;i++)
        {
            int cnt = 0;
            for(int j = 0;j < t;j++)
            {
                if(i&(1<<j))
                {
                    x[free_x[j]] = 1;
                    cnt++;
                }
                else x[free_x[j]] = 0;
            }
            for(int j = var-t-1;j >= 0;j--)
            {
                int idx;
                for(idx = j;idx < var;idx++)
                if(a[j][idx])
                break;
                x[idx] = a[j][var];
                for(int l = idx+1;l < var;l++)
                    if(a[j][l])
                        x[idx] ^= x[l];
                    cnt += x[idx];
            }
            ans = min(ans,cnt);
        }
        printf("%d\n",ans);
    }
}
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    n = 20;
    init();
    for(int i = 0; i < 20; ++i){
        scanf("%d", &a[i][n]);
    }
    solve();
	return 0;
}
