#include<bits/stdc++.h>
using namespace std;

#define MAX_V 100

class Graph{
    private:
    int v;
    int adjMat[MAX_V][MAX_V];

    public:

    Graph(int vertices){
        v = vertices;
        for(int i=0; i<v; i++){
            for(int j= 0; j<v; j++){
                adjMat[i][j] = 0;
            }
        }
    }

    void addedge(int u, int v){
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }

    void dfsRecur(int node, bool visited[]){
        visited[node] = true;
        cout<<node << " ";
        for(int i = 0; i<v; i++){
            if(adjMat[node][i] == 1 && !visited[i]){
                dfsRecur(i,visited);
            }
        }
    }

    void dfsiter(int start){
        bool visited[MAX_V] = {false};
        stack<int> s;
        s.push(start);
        while(!s.empty()){
            int node = s.top();
            s.pop();
            if(!visited[node]){
                visited[node] = true;
                cout<<node<<" ";
            }
            for(int i = v-1; i>=0; --i){
                if(adjMat[node][i] == 1 && !visited[i]){
                    s.push(i);
                }
            }

        }
    }

        void bfs(int start){
            bool visited[MAX_V] = {false};
            queue<int>q;
            q.push(start);
            visited[start] = true;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                cout<< node <<" ";
                for (int i = 0; i < v; ++i) {
                    if (adjMat[node][i] == 1 && !visited[i]) {
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }
        }

        int count(){
            bool visited[MAX_V] = {false};
            int componentcount = 0;
            for(int i=0 ; i<v; i++){
                if(!visited[i]){
                    cout<< "Performing  DFS for component: " << componentcount+1<<": ";
                    dfsRecur(i, visited);
                    componentcount++;
                    cout<<endl;
                }
            }
            return componentcount;
        }

};

int main(){
    int v,e;

    cout<<"enter number of vertices: "<<endl;
    cin>>v;
    Graph g(v);

    cout<<"enter no. of edges: ";
    cin>>e;

    cout<<"enter edges (u,v) where u and v are vertex indices (0-based): \n";
    for(int i = 0; i<e; ++i){
        int u,v;
        cin>> u >> v;
        g. addedge(u,v);
    }

    int startnode;
    cout<<"enter the starting node: ";
    cin>> startnode;

    cout<<"\nRecursive DFS: ";
    bool visited[MAX_V] = {false};
    g.dfsRecur(startnode, visited);
    cout << "\nIterative DFS: ";
    g.dfsiter(startnode);
    cout << "\nBFS: ";
    g.bfs(startnode);
    cout << "\n";


    int components = g.count();
    cout<<"number of connected components: " << components <<endl;

    return 0;


}


