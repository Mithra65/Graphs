#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    private:
    vector<int>parent,rank;
    public:
    DisjointSet(int n){
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        for(int i = 0 ; i <= n ; i++){
            parent[i] = i;
        }
    }
    int findParent(int n){ // 6
        if(parent[n] == n) return n;
        return parent[n] = findParent(parent[n]);
    }
    void UnionbyRank(int u, int v){
        int ulpu = findParent(u);
        int ulpv = findParent(v);
        if(ulpu == ulpv){
            return;
        }
        if(rank[ulpu] > rank[ulpv]){
            parent[ulpv] = ulpu;
        }
        else if(rank[ulpv] > rank[ulpu]){
            parent[ulpu] = ulpv;
        }
        else{
            parent[ulpv] = ulpu;
            rank[ulpu]++;
        }


    }


};

int main(){
    DisjointSet DSU(7);
    DSU.UnionbyRank(1,2);
    DSU.UnionbyRank(2,3);
    DSU.UnionbyRank(5,6);
    if(DSU.findParent(5)!=DSU.findParent(1)){
        cout << "Not connected";
    }
    else{
        
    }
}
