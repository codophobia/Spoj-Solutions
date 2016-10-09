#include <bits/stdc++.h>
using namespace std;
int compare(pair<int,int> a,pair<int,int> b)
{
    return(a.second < b.second);
}
int main()
{
    char a[100];
    int i;
    int p;
    int k1;
    int k2;
    int k3;
    int j;

    while(1) {
        scanf("%d%d%d",&k1,&k2,&k3);
        vector<pair<char,int> > v1,v2,v3,v;

        if(k1 == 0 && k2 == 0 && k3 == 0) {
            break;
        }

        scanf("%s",a);

        for(i = 0; i < strlen(a);i++) {
            if(a[i] >= 'a' && a[i] <= 'i') {
                v1.push_back(pair<char,int> (a[i],i));
            }
            else if(a[i] >= 'j' && a[i] <= 'r') {
                v2.push_back(pair<char,int> (a[i],i));
            }
            else {
                v3.push_back(pair<char,int> (a[i],i));
            }
        }

        for(i = 0; i < v1.size();i++) {
            p = (i + k1) % v1.size();
            v.push_back(pair<int,int> (v1[i].first,v1[p].second));
        }



        for(i = 0; i < v2.size();i++) {
            p = (i + k2) % v2.size();
            //v2[i].second = v2[p].second;
            v.push_back(pair<int,int> (v2[i].first,v2[p].second));
        }

        for(i = 0; i < v3.size();i++) {
            p = (i + k3) % v3.size();

            v.push_back(pair<int,int> (v3[i].first,v3[p].second));
        }

       sort(v.begin(),v.end(),compare);

        for(i = 0; i < v.size();i++) {
            printf("%c",v[i].first,v[i].second);
        }

        printf("\n");



    }


}
