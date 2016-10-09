#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i;
    int j;
    int k;
    int n;
    int hi;
    int lo;
    int sum;
    int a[105];
    vector<int> v1,v2;
    sum = 0;

    scanf("%d",&n);

    for(i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            for(k = 0; k < n; k++) {
                v1.push_back(a[i]*a[j]+a[k]);
            }
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            for(k = 0; k < n; k++) {
                if(a[k] != 0) {
                v2.push_back((a[i]+a[j]) * a[k]);
                }
            }
        }
    }

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    for(i = 0; i < v1.size();i++) {
        lo = lower_bound(v2.begin(),v2.end(),v1[i]) - v2.begin();
        hi = upper_bound(v2.begin(),v2.end(),v1[i]) - v2.begin();

        sum = sum + (hi-lo);

    }

    printf("%d\n",sum);
}
