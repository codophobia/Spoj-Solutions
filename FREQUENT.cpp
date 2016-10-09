#include <bits/stdc++.h>
using namespace std;
int ql;
int qr;
struct node
{
    pair<int,int> left;
    pair<int,int> right;
    pair<int,int> mx;
};
node s[5*100005];
int a[100005];
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

struct node merge(struct node left,struct node right)
{
    struct node t;
    if(left.left.first == right.left.first) {
        t.left.first = left.left.first;
        t.left.second = left.left.second + right.left.second;
    }
    else {
        t.left = left.left;
    }
    if(left.right.first == right.right.first) {
        t.right.first = left.right.first;
        t.right.second = left.right.second + right.right.second;
    }
    else {
        t.right = right.right;
    }
    t.mx = (left.mx.second > right.mx.second)?left.mx:right.mx;
    if(left.right.first == right.left.first) {
        if(left.right.second + right.left.second > t.mx.second) {
            t.mx.first = left.right.first;
            t.mx.second = left.right.second + right.left.second;
        }
    }
    return t;
};

void build(int node,int l,int r)
{
    struct node left,right;
    if(l == r) {
        pair<int,int> p = make_pair(a[l],1);
        s[node].left = p;
        s[node].right = p;
        s[node].mx = p;
        return;
    }
    int mid = (l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    left = s[node*2];
    right = s[node*2+1];
    s[node] = merge(left,right);

}
struct node query(int node,int l, int r)
{

    struct node left,right,x;
    if(ql > r || qr < l) {
        x.left = make_pair(-1000000,0);
        x.right = make_pair(-1000001,0);
        x.mx = make_pair(-1000002,-1000000000);
        return x;
    }
    if(ql <= l && qr >= r) {
        return s[node];
    }
    int mid = (l+r)/2;
    left = query(node*2,l,mid);
    right = query(node*2+1,mid+1,r);
    x = merge(left,right);
    return x;

}

int main()
{
    int q,n,i;
    cin>>n>>q;
    while(1) {
        for(i = 1; i <= n; i++) {
            cin>>a[i];
        }
        build(1,1,n);
        while(q--) {
            cin>>ql>>qr;
            cout<<query(1,1,n).mx.second<<endl;
        }
        cin>>n;
        if(n == 0) {
            break;
        }
        cin>>q;
    }

}
