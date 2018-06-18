#include<stdio.h>  
#include<string.h>  
#include<string>  
#include<map>  
#include<vector>  
using namespace std;  
const int N = 300010 ;  
#define ll long long  
ll num[N] ;  
map<ll, vector<int> >mp;  
void two(ll tnum , int n , int& L , int& R )  
{  
    int l=0,r=mp[tnum].size()-1 , mid;  
    while(l<=r)  
    {  
        mid = (l+r)>>1;  
        if(mp[tnum][mid]>=L)  
            r = mid - 1 ;  
        else  
            l = mid + 1;  
    }  
    L  = l ;  
    if(L==mp[tnum].size()){  
        L = -1 ;  
        R =  L - 1 ;  
        return ;  
    }  
    l = 0 , r = mp[tnum].size()-1 ;  
    while(l<=r)  
    {  
        mid = (l+r)>>1;  
        if(mp[tnum][mid]>=R)  
            r = mid - 1 ;  
        else  
            l = mid + 1;  
    }  
    if(l==mp[tnum].size())  
        R = l-1;  
    else if(mp[tnum][l]>R)  
        R = l-1 ;  
    else  
        R = l ;  
}  
  
int main()  
{  
	#ifdef LOCAL
    freopen("C:\\Users\\liangxianfeng\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\liangxianfeng\\Desktop\\out.txt","w",stdout);
#endif
    int n,m,a,b , ans , T = 0;  
    char s[100] ;  
    while(scanf("%d%d%d%d",&n,&m,&a,&b)>0){  
        mp[0].push_back(0);  
        num[0]=0;  
        for(int i=1; i<=m; i++){  
            scanf("%s",s);  
            num[i] = 0 ;  
            for(int j=0; j<n; j++)  
                if(s[j]=='1'&& !(num[i-1]&(1LL<<j)) || s[j]=='0'&&(num[i-1]&(1LL<<j))==(1LL<<j))  
                    num[i] |= 1LL<<j ;  
  
            mp[ num[i] ].push_back(i) ;  
           // printf("size = %d\n",mp[num[i]].size());  
        }  
        ans = 0 ;  
        for(int i=1; i<=m; i++){  
            ll tnum = 0 ;  
            for(int j=0; j<n; j++)  
                if((num[i]&(1LL<<j))==0)  
                  tnum |= 1LL<<j;  
            int L = i-b , R = i-a ;  
            two(tnum , n , L , R );  
            if(R>=L)  
                ans += R-L+1 ;  
           // printf("[ %d , %d ] num = %lld ,tnum = %lld size = %d\n",L,R,num[i],tnum,mp[tnum].size());  
        }  
        for(int i=0; i<=m; i++)  
            mp[num[i]].clear() ;  
  
        printf("Case %d: %d\n",++T , ans ) ;  
    }  
}  