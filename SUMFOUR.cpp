#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
int a[4005];
int b[4005];
int c[4005];
int d[4005];
int main()
{
    int n;
    int val;
    int lo;
    int hi;
    int sum;
    vector<int> s1;
    pair<vector<int>::iterator,vector<int>::iterator > it;
    int i;
    int j;


    scanf("%d",&n);
    sum = 0;

    for(i = 0; i < n; i++) {
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            s1.push_back(a[i]+b[j]);

        }
    }

    sort(s1.begin(),s1.end());


    for(i = 0; i < n;i++) {
        for(j = 0; j < n; j++) {
            val = -1 * (c[i] + d[j]);
            it = equal_range(s1.begin(),s1.end(),val);
            sum = sum + ((it.second-s1.begin())-(it.first-s1.begin()));
        }
    }


    printf("%d\n",sum);

    return 0;



}
