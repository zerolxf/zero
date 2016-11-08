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
const int maxn = 1e4+100;
const int INF = 0x3f3f3f3f;
#define pr(x)       cout << #x << " = " << x << " ";
#define prln(x)     cout << #x << " = " << x <<endl;
#define ll long long
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define MN(a,b,n) memset(a,b,n*sizeof(int))
struct Node{
	int base, num, flag;
	bool operator <(const Node& rhs)const{
		if(num < rhs.num) return true;
		if(num > rhs.num) return false;
		if(base*num < rhs.base*rhs.num) return true;
		if(base*num > rhs.base*rhs.num) return false;
		if(flag < rhs.flag) return true;
		return false;
	}

}a[maxn];
int cnt ;
void print(int id, int c) {
	int base = a[id].base;
	int flag = a[id].flag;
	int num = a[id].num;
	if(num==1) {
		if(base == 1)
			printf("(x%c1)", (flag==-1)?'-':'+');
		else
			printf("(x^%d%c1)",base,(flag==-1)?'-':'+');
		return;

	}
	printf("(");
	if(flag == 1) {
		for(int i = num; i >= 2; --i) {
			printf("x^%d+",base*i);
		}
		
	}
	if(flag != 1) {
		for(int i = num; i >= 2; --i) {
			printf("x^%d%c",base*i,(i%2?'+':'-'));
		}
	}
	if(base == 1) printf("x+1)");
	else printf("x^%d+1)",base);
}
void dfs(int base,int num, int flag) {
	if(num == 1&&base==1) {
		a[cnt++] = Node{1,1,flag};
		return ;
	}
	if(num%2 == 1) {
		a[cnt++] = Node{base,num-1,-flag};
		//dfs(base*2,num/2,flag);
		a[cnt++] = Node{base,1,flag};
		return ;
	}
	if(num%2 == 0 && flag == 1) {
		if((num-(num&(-num)))==0) {
			a[cnt++] = Node{base*num,1,flag};
		}else{
			dfs(base*2,num/2,1);
		}
	}
	if(num%2 == 0 && flag == -1) {

		dfs(base,num/2,1);
		dfs(base,num/2,-1);
	}
	return ;
}
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
 	cnt = 0;
 	int n;
 	while(scanf("%d", &n)!=EOF && n){
 		cnt = 0;
 		prln(n);
 		if(n==1) {
 			printf("x-1\n");
 			continue;
 		}
	 	dfs(1,n,-1);
	 	sort(a,a+cnt);
	 	//prln(n);
	 	for(int i = 0; i < cnt; ++i) {
	 		print(i,1);
	 	}
	 	printf("\n");
	 }
    return 0;
}