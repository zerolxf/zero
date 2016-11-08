const int N = 3e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

struct ACAutomata {
    static const int S = 26;
    int sz, root;
    vector<vector<int> > nxt;
    vector<int> fail, cnt;

    inline int idx(char c) {return c - 'a';}
    inline int newNode() {
        cnt.push_back(0);
        nxt.push_back(vector<int>(S, 0));
        return sz++;
    }
    void init() {
        sz = 0;
        nxt.clear();
        cnt.clear();
        fail.clear();
        root = newNode();
    }
    void insert(const char* s, int d) {
        int u = root;
        for(; *s; ++s) {
            int c = idx(*s);
            int& v = nxt[u][c];
            if(!v) v = newNode();
            u = v;
        }
        cnt[u] += d;
    }
    void build() {
        vector<int> q;
        fail.resize(nxt.size());
        fail[root] = root;
        for(int i = 0; i < S; ++i) {
            int& v = nxt[root][i];
            if(v) {
                fail[v] = root;
                q.push_back(v);
            } else v = root;
        }
        for(int k = 0; k < q.size(); ++k) {
            int u = q[k];
            for(int i = 0; i < S; ++i) {
                int& v = nxt[u][i];
                if(v) {
                    fail[v] = nxt[fail[u]][i];
                    cnt[v] += cnt[nxt[fail[u]][i]];
                    q.push_back(v);
                } else v = nxt[fail[u]][i];
            }
        }
    }
    LL query(const char* s) {
        LL ret = 0;
        int u = root;
        for(; *s; ++s) {
            int c = idx(*s);
            u = nxt[u][c];
            ret += cnt[u];
        }
        return ret;
    }
};

int q, op[N];
string s[N];
