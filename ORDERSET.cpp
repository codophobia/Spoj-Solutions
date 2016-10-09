#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
int s[1000006];
int a[200005];
int val;
int pos;
int ql;
int qr;
struct node
{
    char c;
    int x;
};
node qs[200005];
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
void build(int node,int l,int r)
{
    if(l == r) {
        s[node] = 0;
        return;
    }
    int mid = (l + r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    s[node] = s[node*2] + s[node*2+1];
}
void update(int node,int l,int r)
{
    if(pos < l || pos > r) {
        return;
    }
    if(l == r) {
        s[node] = val;
        return;
    }
    int mid = (l + r)/2;
    update(node*2,l,mid);
    update(node*2+1,mid+1,r);
    s[node] = s[node*2] + s[node*2+1];
}
int query(int node,int l,int r)
{
    if(qr < l || ql > r) {
        return 0;
    }
    if(ql <= l && qr >= r) {
        return s[node];
    }
    int mid = (l + r)/2;
    return query(node*2,l,mid) + query(node*2+1,mid+1,r);
}
int query1(int node,int l,int r,int x)
{
    if(l == r) {
        return l;
    }
    int mid = (l+r)/2;
    if(x <= s[node*2]) {
        return query1(node*2,l,mid,x);
    }
    else {
        return query1(node*2+1,mid+1,r,x-s[node*2]);
    }
}

int main()
{
    int q;
    unordered_map<int,int> m;
    unordered_map<int,int>::iterator it;
    char c;
    int i;
    int x;
    int n;
    int k = 1;

    cin>>q;
    for(i = 0; i < q; i++){
        cin>>qs[i].c>>qs[i].x;
        a[i+1] = qs[i].x;
    }
    sort(a+1,a+q+1);
    for(i = 0; i < q; i++) {
        m[a[i+1]] = i+1;
    }
    build(1,1,q);
    for(i = 0; i < q; i++) {
        if(qs[i].c == 'I') {
            pos = m[qs[i].x];
            //cout<<"insert "<<pos<<endl;
            val = 1;
            update(1,1,q);
          // print();
        }
        else if(qs[i].c == 'D') {
            pos = m[qs[i].x];
            //cout<<"delete "<<pos<<endl;
            val = 0;

            update(1,1,q);
        }
        else if(qs[i].c == 'C') {
            ql = 1;
            qr = m[qs[i].x]-1;
            cout<<query(1,1,q)<<endl;
        }
        else {
            if(qs[i].x > s[1]) {
                cout<<"invalid"<<endl;
            }
            else {
                pos = query1(1,1,q,qs[i].x);
                cout<<a[pos]<<endl;
            }
        }
    }


}
