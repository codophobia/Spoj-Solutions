#include <bits/stdc++.h>
using namespace std;
struct node
{
    int r;
};
node x[5*100005];
node y[5*100005];
node z[5*100005];
int lazyx[5*100005];
int lazyy[5*100005];
int lazyz[5*100005];
int ul,ur,ql,qr;
void updatex(int node,int l,int r)
{
    if(lazyx[node] != 0) {
        x[node].r = (r-l+1)-x[node].r;
        if(l != r) {
            lazyx[node*2] = (lazyx[node*2] + lazyx[node])%2;
            lazyx[node*2+1] = (lazyx[node*2+1] + lazyx[node])%2;
        }
        lazyx[node] = 0;
    }
    if(ur < l || ul > r) {
        return;
    }
    if(r <= ur && ul <= l) {
        x[node].r = (r-l+1) - x[node].r;
        if(l != r) {
            lazyx[node*2] = (lazyx[node*2] + 1)%2;
            lazyx[node*2+1] = (lazyx[node*2+1] + 1)%2;
        }
        return;
    }
    int mid = (l + r)/2;
    updatex(node*2,l,mid);
    updatex(node*2+1,mid+1,r);
    x[node].r = x[node*2].r + x[node*2+1].r;
}
void updatey(int node,int l,int r)
{
    if(lazyy[node] != 0) {
        y[node].r = (r-l+1)-y[node].r;
        if(l != r) {
            lazyy[node*2] = (lazyy[node*2] + lazyy[node])%2;
            lazyy[node*2+1] = (lazyy[node*2+1] + lazyy[node])%2;
        }
        lazyy[node] = 0;
    }
    if(ur < l || ul > r) {
        return;
    }
    if(r <= ur && ul <= l) {
        y[node].r = (r-l+1)-y[node].r;
        if(l != r) {
            lazyy[node*2] = (lazyy[node*2] + 1)%2;
            lazyy[node*2+1] = (lazyy[node*2+1] + 1)%2;
        }
        return;
    }
    int mid = (l + r)/2;
    updatey(node*2,l,mid);
    updatey(node*2+1,mid+1,r);
    y[node].r = y[node*2].r + y[node*2+1].r;
}
void updatez(int node,int l,int r)
{
    if(lazyz[node] != 0) {
        z[node].r = (r-l+1)-z[node].r;
        if(l != r) {
            lazyz[node*2] = (lazyz[node*2] + lazyz[node])%2;
            lazyz[node*2+1] = (lazyz[node*2+1] + lazyz[node])%2;
        }
        lazyz[node] = 0;
    }
    if(ur < l || ul > r) {
        return;
    }
    if(r <= ur && ul <= l) {
        z[node].r = (r-l+1)-z[node].r;
        if(l != r) {
            lazyz[node*2] = (lazyz[node*2] + 1)%2;
            lazyz[node*2+1] = (lazyz[node*2+1] + 1)%2;
        }
        return;
    }
    int mid = (l + r)/2;
    updatez(node*2,l,mid);
    updatez(node*2+1,mid+1,r);
    z[node].r = z[node*2].r + z[node*2+1].r;
}
node queryx(int node,int l,int r)
{
    if(lazyx[node] != 0) {
        x[node].r = (r-l+1)-x[node].r;
        if(l != r) {
            lazyx[node*2] = (lazyx[node*2] + lazyx[node])%2;
            lazyx[node*2+1] = (lazyx[node*2+1] + lazyx[node])%2;
        }
        lazyx[node] = 0;
    }
    if(qr < l || ql > r) {
        struct node g;
        g.r = 0;
        return g;
    }
    if(ql <= l && qr >= r) {
        return x[node];
    }
    int mid = (l + r)/2;
    struct node temp;
    struct node left = queryx(node*2,l,mid);
    struct node right = queryx(node*2+1,mid+1,r);
    temp.r = left.r + right.r;
    return temp;
}

node queryy(int node,int l,int r)
{
    if(lazyy[node] != 0) {
        y[node].r = (r-l+1)-y[node].r;
        if(l != r) {
           lazyy[node*2] = (lazyy[node*2] + lazyy[node])%2;
        lazyy[node*2+1] = (lazyy[node*2+1] + lazyy[node])%2;
        }
        lazyy[node] = 0;
    }
    if(qr < l || ql > r) {
        struct node g;
        g.r = 0;
        return g;
    }
    if(ql <= l && qr >= r) {
        return y[node];
    }
    int mid = (l + r)/2;
    struct node temp;
    struct node left = queryy(node*2,l,mid);
    struct node right = queryy(node*2+1,mid+1,r);
    temp.r = left.r + right.r;
    return temp;
}
node queryz(int node,int l,int r)
{
    if(lazyz[node] != 0) {
        z[node].r = (r-l+1)-z[node].r;
        if(l != r) {
            lazyz[node*2] = (lazyz[node*2] + lazyz[node])%2;
            lazyz[node*2+1] = (lazyz[node*2+1] + lazyz[node])%2;
        }
        lazyz[node] = 0;
    }
    if(qr < l || ql > r) {
        struct node g;
        g.r = 0;
        return g;
    }
    if(ql <= l && qr >= r) {
        return z[node];
    }
    int mid = (l + r)/2;
    struct node temp;
    struct node left = queryz(node*2,l,mid);
    struct node right = queryz(node*2+1,mid+1,r);
    temp.r = left.r + right.r;
    return temp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int nx;
    int ny;
    int nz;
    int i;
    int q;
    int c;
    int t;
    long long int ans;
    int x1,y1,z1,x2,y2,z2;
    long long int rx,ry,rz,gx,gy,gz;

    cin>>t;
    while(t--) {
        cin>>nx>>ny>>nz>>q;
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        memset(z,0,sizeof(z));
        memset(lazyx,0,sizeof(lazyx));
        memset(lazyy,0,sizeof(lazyy));
        memset(lazyz,0,sizeof(lazyz));
       /* ul = 1;
        ur = nx;
        updatex(1,1,nx);
        ul = 1;
        ur = ny;
        updatey(1,1,ny);
        ul = 1;
        ur = nz;
        updatez(1,1,nz);
        printx();
        printy();
        printz();*/
        while(q--) {
            ans = 0;
            cin>>c;
            if(c == 0) {
                cin>>ul>>ur;
                ul++;
                ur++;
                updatex(1,1,nx);
               //printx();
            }
            else if(c == 1) {
                cin>>ul>>ur;
                ul++;
                ur++;
                updatey(1,1,ny);
                //printy();
            }
            else if(c == 2) {
                cin>>ul>>ur;
                ul++;
                ur++;
                updatez(1,1,nz);
                //printz();
            }
            else {
                cin>>x1>>y1>>z1>>x2>>y2>>z2;
                ql = x1;
                qr = x2;
                ql++;
                qr++;
                rx = (long long)queryx(1,1,nx).r;
                gx = abs((qr-ql+1)-rx);
                ql = y1;
                qr = y2;
                ql++;
                qr++;
                ry = (long long)queryy(1,1,ny).r;
                gy = abs((qr-ql+1)-ry);
                ql = z1;
                qr = z2;
                ql++;
                qr++;
                rz = (long long)queryz(1,1,nz).r;
                gz = abs((qr-ql+1)-rz);
                ans = (rx*ry*rz) + (rx*gy*gz) + (ry*gx*gz) + (rz*gx*gy);
                //cout<<rx<<' '<<gx<<' '<<ry<<' '<<gy<<' '<<rz<<' '<<gz<<endl;
                cout<<ans<<endl;
                //printx();
                //printy();

                //printz();
            }
        }
    }
}


