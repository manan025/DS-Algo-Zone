#include <bits/stdc++.h>
using namespace std;

class graph{
    unordered_map<string,list<pair<string,int>>> up;
    public:
    void addedge(string s,string d,int dist, bool bidir)
    {
        up[s].push_back(make_pair(d,dist));
        if(bidir){
            up[d].push_back(make_pair(s,dist));
        }
    }
    void printAdj(){
        for(auto j:up){
            cout<<j.first<<"->";
            for(auto l: j.second){
                cout<<"("<<l.first<<","<<l.second<<")"<<endl;
            }
        }
    }
    void Dijsktra(string src){
        unordered_map<string,int> dist;
        for(auto j:up){
            dist[j.first] = INT_MAX;
        }
        set<pair<int,string>> s;
        dist[src] = 0;
        s.insert(make_pair(0,src));
        while(!s.empty()){
            auto p = *(s.begin());
            string node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());
            for(auto nbr: up[node]){
                if(nodeDist + nbr.second < dist[nbr.first]){
                    auto f = s.find(make_pair(dist[nbr.first],nbr.first));
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    dist[nbr.first] = nodeDist + nbr.second;
                    s.insert(make_pair(dist[nbr.first],nbr.first));
                }
            }
        }
        for(auto d:dist){
            cout<<d.first<<" is at distance "<<d.second<<" from "<<src<<endl;
        }
    }
};
int main()
{
    graph g;
    g.addedge("Amritsar","Delhi",1,true);
    g.addedge("Amritsar","Jaipur",4,true);
    g.addedge("Jaipur","Delhi",2,true);
    g.addedge("Jaipur","Mumbai",8,true);
    g.addedge("Bhopal","Agra",2,true);
    g.addedge("Mumbai","Bhopal",3,true);
    g.addedge("Agra","Delhi",1,true);
    g.Dijsktra("Amritsar");
}
