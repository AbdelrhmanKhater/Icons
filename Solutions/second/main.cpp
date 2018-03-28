#include <bits/stdc++.h>

using namespace std;

int n , m ,counter;
struct package {
int s,k;
};
struct cyl {
int r,ca;
};
package p[500];
cyl c[500];

bool grt (cyl i , cyl j){
return i.r>j.r;

}
bool grt1 (package i , package j){
return i.s>j.s ;
}

int main()
{
    cin >> n >> m ;
    for (int i = 0 ; i < n ; i ++){
        cin >> p[i].s;
    }
    for (int i = 0 ; i < n ; i ++){
        cin >> p[i].k;
    }
    for (int i = 0 ; i < m ; i ++){
        cin >> c[i].r;
    }
    for (int i = 0 ; i < m ; i ++){
        cin >> c[i].ca;
    }
    sort (c,c+m,grt);
    sort (p,p+n,grt1);
    int i=0;
    int j=0 ;
    while (i<m && j <n){
        if (2*c[i].r>sqrt(2*p[j].s*p[j].s)){
            c[i].ca-=1;
            p[j].k-=1;
            counter ++;
        }
        else {
            j++;
        }
        if (p[j].k==0){
            j++;
        }
        if (c[i].ca==0){
            i++;
        }

    continue ;
    }
    cout << counter ;
    return 0;
}
