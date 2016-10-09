#include <bits/stdc++.h>
using namespace std;
struct dolls
{
    int w;
    int h;
};
dolls a[20005];
vector<dolls> v;
int compare(dolls a,dolls b)
{
    if(a.h == b.h) {
        return a.w < b.w;
    }
    return a.h > b.h;
}
int main()
{
    int n;
    int i;
    int j;
    int t;
    int mid;
    int lo;
    int hi;

    cin>>t;
    while(t--) {
        scanf("%d",&n);
        for(i = 0; i < n; i++) {
            scanf("%d %d",&a[i].w,&a[i].h);
        }
        sort(a,a+n,compare);
        v.clear();
        v.push_back(a[0]);
        for(i = 1; i < n; i++) {
            lo = 0;
            hi = v.size() - 1;
            while(lo <= hi) {
                mid = (lo + hi) / 2;
                if(v[mid].w > a[i].w && v[mid].h != a[i].h) {
                    hi = mid - 1;
                }
                else {
                    lo = mid + 1;
                }
            }
            if(lo == v.size()) {
                v.push_back(a[i]);
            }
            else {
                v[lo].w = a[i].w;
                v[lo].h = a[i].h;
            }
        }
        printf("%d\n",v.size());

    }
}

