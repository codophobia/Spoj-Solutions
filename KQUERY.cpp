#include <bits/stdc++.h>
using namespace std;
int s[5*30005];
struct node
{
    int l;
    int r;
    int k;
    int pos;
};
struct node1
{
    int x;
    int pos;
};
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

int build(int node,int l,int r)
{
    if(l == r) {
        s[node] = 1;
        return s[node];
    }
    int mid = (l + r)/2;
    s[node] = build(node*2,l,mid) + build(node*2+1,mid+1,r);
    return s[node];

}
void update(int node,int l,int r,int pos)
{
    if(pos < l || pos > r) {
        return;
    }
    if(l == r) {
        s[node] = 0;
        return;
    }
    int mid = (l + r)/2;
    update(node*2,l,mid,pos);
    update(node*2+1,mid+1,r,pos);
    s[node] = s[node*2] + s[node*2+1];

}
int query(int node,int l,int r,int ql,int qr)
{
    if(qr < l || ql > r) {
        return 0;
    }
    if(ql <= l && qr >= r) {
        return s[node];
    }
    int mid = (l + r)/2;
    return query(node*2,l,mid,ql,qr) + query(node*2+1,mid+1,r,ql,qr);
}
int compare(struct node a,struct node b)
{
    return a.k < b.k;
}
int compare1(struct node1 a,struct node1 b)
{
    return a.x < b.x;
}
int main()
{
    int n;
    int i;
    int k;
    int j;
    int q;
    char c;
    int pos,ql,qr;
    node1 a[30005];
    node qs[200005];
    int ans[200005];
    int p = 1;

    cin>>n;
    for(i = 1; i <= n; i++) {
        cin>>a[i].x;
        a[i].pos = i;
    }
    build(1,1,n);
    cin>>q;
    for(i = 0; i < q; i++) {
        cin>>qs[i].l>>qs[i].r>>qs[i].k;
        qs[i].pos = i;
    }
    sort(qs,qs+q,compare);
    sort(a+1,a+n+1,compare1);
    for(i = 0; i < q; i++) {
        while(p <= n && a[p].x <= qs[i].k) {
            pos = a[p].pos;
            update(1,1,n,pos);
            p++;
        }
        ql = qs[i].l;
        qr = qs[i].r;
        //cout<<qs[i].pos<<endl;
        ans[qs[i].pos] = query(1,1,n,ql,qr);
    }
    for(i = 0; i < q; i++) {
        cout<<ans[i]<<endl;
    }
}
