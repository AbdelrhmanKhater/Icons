#include <iostream>

using namespace std;

int seive[1000005],pm[1000005];
long long t,a,b,d[10];
long long counter=0,counter1=0;
int idx = 0;
int D;
int q = 0;
bool Make_Sure(int val, int d)
{
    while (val != 0)
    {
        if (!(val % d))
            val /= d;
        else
            return false;
        if (val == d)
            return true;
    }
}
void Generate_seive (){
for (int i=2;i<1000005;i++){
    seive[i]=1;

}
for (int i=2;i<1000005;i++){
    if (seive[i]==1){
        for (int j=2*i;j<1000005;j+=i){
            seive[j]=0;
        }
    }
    if (seive[i]==1){
        pm[idx++]=i;
        counter1++;
    }
}

}
int Rec_Solve(int val, int f, int p)
{
    if (val == 1)
    {
        if (f)
            return p;
        else
            return p * 2;
    }
    for (int i = 0; i < counter1; i++)
    {
        if(!(val % pm[i]))
        {
            if (Make_Sure(val, pm[i]))
                q++;
            if (!(pm[i] % D))
                return Rec_Solve(val / pm[i], 1, p + 1);
            else
                return Rec_Solve(val / pm[i], f, p + 1);
        }
    }
}
/*void QuipuFunction(long long s,long long ss){

while (s!=1){

    for (int i=0;i<counter1;i++){
            if(s%)


    }
}

}*/

int main()
{
    cin>>t>>a>>b;
    Generate_seive();
    for (int i =0;i<t;i++){

        cin>>d[i];
        int ret = 0;
        D = d[i];
        for (int j=a;j<=b;j++){
            ret += Rec_Solve(j, 0, 0) - q;
            q = 0;
        }
        cout<< ret << "\n";
        counter=0;
    }
    return 0;
}
