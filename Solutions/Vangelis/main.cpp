#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <stdio.h>

using namespace std;
bool visited[1005];
int n,m,a,b,x,y;
vector < vector <int> > adjList;

bool dfs(int start,int parent=-1){
    visited[start]=true;
    for(int i=0;i<adjList[start].size();i++){
        int child=adjList[start][i];
        if(!visited[child]){
            if(dfs(child,start)) return true;
        }
        else if(parent != child) return true;
    }
    return false;

}

int main()
{

    int t;cin>>t;

    while(t--){
        cin>>n>>m;
        memset(visited,0,sizeof visited);
        adjList.clear();
        adjList.resize(n);
        for(int i=0;i<m;i++){
            cin>>x>>y;
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }
        //dfs
        bool f=false;
        for(int i=0;i<n;i++){
            if(!visited[i])
                if(dfs(i)){
                    f=true;
                    break;
                }
        }
        if(f) cout<<1<<'\n';
        else cout<<0<<'\n';

    }
    std::ios::sync_with_stdio(false);

    return 0;
}
