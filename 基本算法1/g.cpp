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
int q[41], cnt, num, a;
int main(){
#ifdef LOCAL
    freopen("C:\\Users\\Administrator\\Desktop\\in.txt","r",stdin);
  //freopen("C:\\Users\\Administrator\\Desktop\\out.txt","w",stdout);
 #endif
    stack<int> st;
    int t, n;
    scanf("%d", &t);
   // prln(t);
        while(t--) {
            scanf("%d", &n);
           // prln(n);
            num = cnt = 0;
            for(int i = 0; i < n; ++i) {
                scanf("%d", &a);
              //  pr(a);
                while(num < a) {
                    q[cnt++] = 0;
                    num++;
                }
                q[cnt++] = 1;
            }
            num = 0;
            for(int i = 0; i < cnt; ++i) {
                if(q[i] == 1) {
                    num++;
                    int u = st.top();st.pop();
                    printf("%d%c", num-u, (i==cnt-1?'\n':' '));
                } else {
                    st.push(num);
                }
            }
    }
    return 0;
}
