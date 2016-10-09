#include <bits/stdc++.h>
using namespace std;
int a[300005];
struct node
{
    int l;
    int r;
    int pos;
};
struct node1
{
    int mx;
    int num;
};
node qs[200005];
node1 ans[200005];
int h[1000006];
int n;
int mx;
int num;
int len;
map<pair<int,int>,int> m;
map<pair<int,int>,int>::iterator it;
static struct IO {
	char tmp[1 << 10];

	// fast input routines
	char cur;

//#define nextChar() (cur = getc_unlocked(stdin))
//#define peekChar() (cur)
	inline char nextChar() { return cur = getc_unlocked(stdin); }
	inline char peekChar() { return cur; }

	inline operator bool() { return peekChar(); }
	inline static bool isBlank(char c) { return (c < '-' && c); }
	inline bool skipBlanks() { while (isBlank(nextChar())); return peekChar() != 0; }

	inline IO& operator >> (char & c) { c = nextChar(); return *this; }

	inline IO& operator >> (char * buf) {
		if (skipBlanks()) {
			if (peekChar()) {
				*(buf++) = peekChar();
				while (!isBlank(nextChar())) *(buf++) = peekChar();
			} *(buf++) = 0; } return *this; }

	inline IO& operator >> (string & s) {
		if (skipBlanks()) {	s.clear(); s += peekChar();
			while (!isBlank(nextChar())) s += peekChar(); }
		return *this; }

	inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this;	}

#define defineInFor(intType) \
	inline IO& operator >>(intType & n) { \
		if (skipBlanks()) { \
			int sign = +1; \
			if (peekChar() == '-') { \
				sign = -1; \
				n = nextChar() - '0'; \
			} else \
				n = peekChar() - '0'; \
			while (!isBlank(nextChar())) { \
				n += n + (n << 3) + peekChar() - 48; \
			} \
			n *= sign; \
		} \
		return *this; \
	}

defineInFor(int)
defineInFor(unsigned int)
defineInFor(long long)

	// fast output routines

//#define putChar(c) putc_unlocked((c), stdout)
	inline void putChar(char c) { putc_unlocked(c, stdout); }
	inline IO& operator << (char c) { putChar(c); return *this; }
	inline IO& operator << (const char * s) { while (*s) putChar(*s++); return *this; }

	inline IO& operator << (const string & s) { for (int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this; }

	char * toString(double d) { sprintf(tmp, "%lf%c", d, '\0'); return tmp; }
	inline IO& operator << (double d) { return (*this) << toString(d); }


#define defineOutFor(intType) \
	inline char * toString(intType n) { \
		char * p = (tmp + 30); \
		if (n) { \
			bool isNeg = 0; \
			if (n < 0) isNeg = 1, n = -n; \
			while (n) \
				*--p = (n % 10) + '0', n /= 10; \
			if (isNeg) *--p = '-'; \
		} else *--p = '0'; \
		return p; \
	} \
	inline IO& operator << (intType n) { return (*this) << toString(n); }

defineOutFor(int)
defineOutFor(long long)

#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;
int compare(struct node a,struct node b)
{
    int x = a.l/len;
    int y = b.l/len;
    if(x == y) {
        return a.r < b.r;
    }
    else {
        return x < y;
    }
}
int main()
{
    int q;
    int cl = 1;
    int cr = 1;
    int i;
    int c;

    cin>>n>>c;
    len = sqrt(n);
    for(i = 1; i <= n; i++) {
        cin>>a[i];
    }
    mx = 0;
    int pos;
    cin>>q;
    for(i = 1; i <= q; i++) {
        cin>>qs[i].l>>qs[i].r;
        qs[i].pos = i;
    }
    sort(qs+1,qs+q+1,compare);
    for(i = 1; i <= q; i++) {
        while(qs[i].l < cl)
        {   pos = cl-1;
            it = m.find(make_pair(h[a[pos]],a[pos]));
            if(it != m.end())
            {
                m.erase(it);
            }
            h[a[pos]]++;
            m[make_pair(h[a[pos]],a[pos])];
            cl--;
        }
        while(qs[i].l > cl) {
            pos = cl;
            it = m.find(make_pair(h[a[pos]],a[pos]));
            if(it != m.end())
            {
                m.erase(it);
            }
            h[a[pos]]--;
            m[make_pair(h[a[pos]],a[pos])];
            cl++;
        }
        while(qs[i].r+1 <= cr) {
            pos = cr-1;
            it = m.find(make_pair(h[a[pos]],a[pos]));
            if(it != m.end())
            {
                m.erase(it);
            }
            h[a[pos]]--;
            m[make_pair(h[a[pos]],a[pos])];
            cr--;
        }
        while(qs[i].r >= cr) {
            pos = cr;
            it = m.find(make_pair(h[a[pos]],a[pos]));
            if(it != m.end())
            {
                m.erase(it);
            }
            h[a[pos]]++;
            m[make_pair(h[a[pos]],a[pos])];
            cr++;
        }
        ans[qs[i].pos].num = m.rbegin()->first.second;
        ans[qs[i].pos].mx = m.rbegin()->first.first;
        /*for(it = m.begin(); it != m.end(); it++) {
            cout<<it->first.second<<' '<<it->first.first<<endl;
        }*/
    }
    for(i = 1; i <= q; i++) {
        if(ans[i].mx > (qs[i].r-qs[i].l+1)/2) {
            cout<<"yes"<<' '<<ans[i].num<<endl;
        }
        else {
            cout<<"no"<<endl;
        }
    }
}



