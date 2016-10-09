#include <bits/stdc++.h>
using namespace std;
int dpa[2500][2500];
int dpw[2500][2500];
int dpf[2500][2500];
int f(int h,int a,char c)
{
   // cout << h <<"  "<<a <<" "<<c<<endl;
    if(a <= 0 || h <= 0) {
        return 0;
    }
    if(c == 'A' && dpa[h][a] != -1) {
        return dpa[h][a];
    }
    if(c == 'W' && dpw[h][a] != -1) {
        return dpw[h][a];
    }
    if(c == 'F' && dpf[h][a] != -1) {
        return dpf[h][a];
    }
    if(c == 'A') {
        dpa[h][a] =  max(f(h-5,a-10,'W'),f(h-20,a+5,'F')) + 1;
        return dpa[h][a];
    }
    else if(c == 'W') {
         dpw[h][a] =  max(f(h+3,a+2,'A'),f(h-20,a+5,'F')) + 1;
         return dpw[h][a];
    }
    else {
         dpf[h][a] =  max(f(h+3,a+2,'A'),f(h-5,a-10,'W')) + 1;
         return dpf[h][a];
    }
}
int main()
{
    int t;
    int h;
    int a;
    int i;
    int j;
    int mx;
    int x,y,z;

    cin>>t;
    while(t--) {
        cin>>h>>a;
        for(i = 0; i < 2500; i++) {
            for(j = 0; j < 2500; j++) {
                dpa[i][j] = -1;
                dpw[i][j] = -1;
                dpf[i][j] = -1;
            }
        }
        x = f(h+3,a+2,'A');
      //  y = f(h-5,a-10,'W',1);
        //z = f(h-20,a+5,'F',1);
       // mx = max(x,y);
        //mx = max(mx,z);
        cout<<x<<endl;
    }
}
