#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
void scanchar(char &c){
    register int x = gc();
    for(;(x < 65 || x > 97);x = gc());
    c = x;
}
int main()
{
    int q;
    unordered_multimap<int,int> m;
    char c;
    int i;
    int x;
    int mn;
    int n;
    int k;

    scanint(n);
    scanint(q);
    for(i = 1; i <= n; i++) {
        scanint(x);
        m.insert(make_pair(x,i));
    }
    k = n;
    for(i = 1; i <= q; i++) {
        scanchar(c);
        scanint(x);
        if(c == 'I') {
            k++;
            m.insert(make_pair(x,k));
            printf("%d\n",k);
        }
        else if(c == 'D') {
            auto it = m.equal_range(x);
            if(it.first != m.end()) {
                auto d = it.first;
                auto s = it.first;
                s++;
                while(s != it.second) {
                    d = s;
                    s++;
                }
                printf("%d\n",d->second);
                m.erase(d);
            }
            else {
                printf("NONE\n");
            }
        }
        else {
            auto it = m.equal_range(x);
            if(it.first != m.end()) {
                auto d = it.first;
                auto s = it.first;
                s++;
                while(s != it.second) {
                    d = s;
                    s++;
                }
                printf("%d\n",d->second);
            }
            else {
                printf("NONE\n");
            }

        }
    }




}

