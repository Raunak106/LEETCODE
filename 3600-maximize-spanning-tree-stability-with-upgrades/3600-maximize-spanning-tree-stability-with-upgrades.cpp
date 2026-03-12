class DSU {
public:
    vector<int> parent, rankv;

    DSU(int n){
        parent.resize(n);
        rankv.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int find(int x){
        if(parent[x]!=x)
            parent[x]=find(parent[x]);
        return parent[x];
    }

    bool unite(int a,int b){
        a=find(a);
        b=find(b);

        if(a==b) return false;

        if(rankv[a]<rankv[b]) swap(a,b);

        parent[b]=a;
        if(rankv[a]==rankv[b]) rankv[a]++;

        return true;
    }
};

class Solution {
public:

    bool check(int n, vector<vector<int>>& edges, int k, int mid){
        DSU dsu(n);
        int used=0;
        int upgrades=0;

        // must edges first
        for(auto &e:edges){
            int u=e[0],v=e[1],s=e[2],must=e[3];

            if(must){
                if(s<mid) return false;

                if(!dsu.unite(u,v)) 
                    return false;

                used++;
            }
        }

        // optional edges
        for(auto &e:edges){
            int u=e[0],v=e[1],s=e[2],must=e[3];

            if(must) continue;

            if(s>=mid){
                if(dsu.unite(u,v)) used++;
            }
            else if(s*2>=mid && upgrades<k){
                if(dsu.unite(u,v)){
                    upgrades++;
                    used++;
                }
            }
        }

        return used==n-1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        // 🔴 IMPORTANT FIX
        sort(edges.begin(), edges.end(), [](auto &a, auto &b){
            return a[2] > b[2];
        });

        int left=1,right=200000;
        int ans=-1;

        while(left<=right){
            int mid=(left+right)/2;

            if(check(n,edges,k,mid)){
                ans=mid;
                left=mid+1;
            }
            else right=mid-1;
        }

        return ans;
    }
};