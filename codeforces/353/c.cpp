/*************************************************************************
	> File Name: c.cpp
	> Author: liangxianfeng
	> Mail:   641587852@qq.com
	> Created Time: 2016年05月17日 星期二 01时13分28秒
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
int a[maxn];
ll cnt[maxn];
int sum[maxn];
int last[maxn];
map<int,int> mp;
struct Node{
    int last, num;
    Node(){}
    Node(int _last, int _num){
        last = _last;
        num = _num;
    }
    bool operator < (const Node& rhs)const{
        return last > rhs.last;
    }
};
int main(){
#ifdef LOCAL
	freopen("/home/zeroxf/桌面/in.txt","r",stdin);
	//freopen("/home/zeroxf/桌面/out.txt","w",stdout);
#endif
    int n;
    while(cin >> n){
        mp.clear();
        sum[0] = 0;
        ll ans = INF;
        ll temp = 0;
        rep(i,n){
            scanf("%d",&a[i+1]);
//        cin >> a[i+1];
            a[i+1+n] = a[i+1];
  //          pr(i+1);prln(a[i+1]);
        }
        mp[0] = 0;
        for(int i = 1; i <= n*2; ++i) {
            sum[i] = sum[i-1] + a[i];
            if(mp.count(sum[i]) == 0){
                last[i] = -1;
                mp[sum[i]] = i;
            }else {
                last[i] = mp[sum[i]];
                mp[sum[i]] = i;
            }
            pr(i);pr(sum[i]);prln(last[i]);
        }
        
        ans = n-1;
        temp = 0;
        priority_queue<Node> pq;
        for(int i = 1; i<= n; ++i){
            temp += i-last[i]-1;
pr(i);            prln(i-last[i]-1);
            pq.push(Node(last[i], i-last[i]+1));
        }
            while(pq.size()){
                Node x = pq.top();
                if(x.last<0) {
                    temp -= x.num;
                    pq.pop();
                }else break;
            }
        ans = min(ans,temp);
        prln(temp);
        for(int i = n+1; i <= n*2;++i){
            temp += i-last[i]-1;
  //          pr(i);
//            prln(last[i]);
            pq.push(Node(last[i], i-last[i]-1));
            while(pq.size()){
                Node x = pq.top();
                if(x.last<i-n) {
                    temp -= x.num;
                    pq.pop();
                }else break;
            }
    //       pr(i);prln(temp);
            ans = min(ans,temp);
        }
        cout << ans << "\n";
    }
	return 0;
}
