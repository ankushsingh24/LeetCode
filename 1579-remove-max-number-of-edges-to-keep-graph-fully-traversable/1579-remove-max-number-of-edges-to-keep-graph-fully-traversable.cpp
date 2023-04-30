class DSU {
public:
    vector<int> Parent, Rank;
    DSU(int n)
    {
        Parent.resize(n);
        Rank.resize(n);
        for(int i=0 ; i<n ; i++)
            Parent[i] = i;
    }
    
    int Find(int x)
    {
        return Parent[x] = Parent[x] == x ? x : Find(Parent[x]);
    }
    
    bool Union(int x, int y)
    {
        int xset = Find(x), yset = Find(y);
        if(xset != yset)
        {
            Rank[xset] < Rank[yset] ? Parent[xset] = yset : Parent[yset] = xset;
            Rank[xset] += Rank[xset] == Rank[yset];
            return true;
        }
        
        return false;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) 
    {
        sort(edges.begin(), edges.end(), [&](auto const &a, auto const &b){
            return a[0] > b[0];
        });
        
        DSU dsu_alice(n+1);
        DSU dsu_bob(n+1);
        
        int removed_edge = 0, alice_edges = 0, bob_edges = 0;
        for(auto edge: edges)
        {
            if(edge[0] == 3) // Both Alice & Bob
            {
                if(dsu_alice.Union(edge[1], edge[2]))
                {
                    dsu_bob.Union(edge[1], edge[2]);
                    alice_edges++;
                    bob_edges++;
                }
                else
                    removed_edge++;
            }
            
            else if(edge[0] == 2) // Bob
            {
                if(dsu_bob.Union(edge[1], edge[2]))
                    bob_edges++;
                else
                    removed_edge++;
            }
            
            else // Alice
            {
                if(dsu_alice.Union(edge[1], edge[2]))
                    alice_edges++;
                else
                    removed_edge++;
            }
        }
        
        return (bob_edges == n-1 && alice_edges == n-1) ? removed_edge : -1;
    }
};