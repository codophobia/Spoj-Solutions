#include <bits/stdc++.h>
using namespace std;
int lazy[1000006];
int val;
int ql;
int qr;
int ul;
int ur;
struct node
{
    int m0;
    int m1;
    int m2;
};
node s[5*100005];
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
node build(int node,int l,int r)
{
    if(l == r) {
        s[node].m0 = 1;
        s[node].m1 = s[node].m2 = 0;
        return s[node];
    }
    int mid = (l + r)/2;
    struct node left = build(node*2,l,mid);
    struct node right = build(node*2+1,mid+1,r);
    s[node].m0 = left.m0 + right.m0;
    s[node].m1 = left.m1 + right.m1;
    s[node].m2 = left.m2 + right.m2;
    return s[node];

}
void update(int node,int l,int r)
{
    int temp;
    if(lazy[node] != 0) {
        int m = lazy[node];
        if(m == 1) {
            temp = s[node].m2;
            s[node].m2 = s[node].m1;
            s[node].m1 = s[node].m0;
            s[node].m0 = temp;
        }
        else if(m == 2) {
            temp = s[node].m1;
            s[node].m1 = s[node].m2;
            s[node].m2 = s[node].m0;
            s[node].m0 = temp;
        }

        if(l != r) {
            lazy[node*2] = (lazy[node*2] + lazy[node])%3;
            lazy[node*2+1] = (lazy[node*2+1] + lazy[node])%3;
        }
        lazy[node] = 0;
    }
    if(ur < l || ul > r) {
        return;
    }
    if(r <= ur && ul <= l) {
        //cout<<s[node].m0<<' '<<s[node].m1<<' '<<s[node].m2<<endl;
        temp = s[node].m2;
        s[node].m2 = s[node].m1;
        s[node].m1 = s[node].m0;
        s[node].m0 = temp;
        if(l != r) {
            lazy[node*2] = (lazy[node*2] + 1)%3;
            lazy[node*2+1] = (lazy[node*2+1] + 1)%3;
        }
        return;
    }
    int mid = (l + r)/2;
    update(node*2,l,mid);
    update(node*2+1,mid+1,r);
    s[node].m0 = s[node*2].m0 + s[node*2+1].m0;
    s[node].m1 = s[node*2].m1 + s[node*2+1].m1;
    s[node].m2 = s[node*2].m2 + s[node*2+1].m2;
}
node query(int node,int l,int r)
{
    int temp;
    struct node p;
    if(lazy[node] != 0) {
        int m = lazy[node];
        if(m == 1) {
            temp = s[node].m2;
            s[node].m2 = s[node].m1;
            s[node].m1 = s[node].m0;
            s[node].m0 = temp;
        }
        else if(m == 2) {
            temp = s[node].m1;
            s[node].m1 = s[node].m2;
            s[node].m2 = s[node].m0;
            s[node].m0 = temp;
        }

        if(l != r) {
            lazy[node*2] = (lazy[node*2] + lazy[node])%3;
            lazy[node*2+1] = (lazy[node*2+1] + lazy[node])%3;
        }
        lazy[node] = 0;
    }

    if(qr < l || ql > r) {
        p.m0 = p.m1 = p.m2 = 0;
        return p;
    }
    if(ql <= l && qr >= r) {
        return s[node];
    }
    int mid = (l + r)/2;
    struct node left = query(node*2,l,mid);
    struct node right = query(node*2+1,mid+1,r);
    p.m0 = left.m0 + right.m0;
    p.m1 = left.m1 + right.m1;
    p.m2 = left.m2 + right.m2;
    return p;
}
int main()
{
    int n;
    int i;
    int q;
    int c;

    cin>>n>>q;
    build(1,1,n);
    //print();
    while(q--) {
        cin>>c;
        if(c == 0) {
            cin>>ul>>ur;
            ul++;
            ur++;
            update(1,1,n);
            //print();
        }
        else {
            cin>>ql>>qr;
            ql++;
            qr++;
            cout<<query(1,1,n).m0<<endl;
          // print();
        }
    }
}


