#include <bits/stdc++.h>
using namespace std;


class Graph{
public:
   int vertices;
   vector<vector<int>> adjList;

   Graph(int V) : vertices(V) , adjList(V) {} 
   void addEdge(int v , int w){
    adjList[v].push_back(w);
   }



bool dfs(int start, int target, vector<int>& path) {
        vector<bool> visited(vertices, false);
        stack<int> s;
        s.push(start);

        while (!s.empty()) {
            int current = s.top();
            s.pop();

            if (!visited[current]) {
                visited[current] = true;
                path.push_back(current);
                if (current == target) {
                    return true;
                }

                // Reversing to maintain order
                auto& neighbors = adjList[current];
                for (auto it = neighbors.rbegin(); it != neighbors.rend(); ++it) {
                    if (!visited[*it]) {
                        s.push(*it);
                    }
                }
            }
        }
        return false;
    }


bool bfs(int start, int target, vector<int>& path) {
        vector<bool> visited(vertices, false);
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            if (!visited[current]) {
                visited[current] = true;
                path.push_back(current);
                if (current == target) {
                    return true;
                }

                for (int neighbor : adjList[current]) {
                    if (!visited[neighbor]) {
                        q.push(neighbor);
                    }
                }
            }
        }
        return false;
    }







};

int main(){

cout<<"enter the no . of vertices and edges : "<<"\n";
int vertices , edges;
cin>>vertices>>edges;

Graph graph(vertices);

cout<<"now enter edges in vertex 1 : vertex 2 format "<<endl;
for(int i=0;i<edges;i++){
    int v,w;
    cin>>v>>w;
    graph.addEdge(v,w);

}

cout<<"enter start vertex"<<"\n";
int st;cin>>st;
cout<<"enter target vertex"<<"\n";
int tr;cin>>tr;

vector<int> path;
if(graph.bfs(st , tr , path)){
    cout<<"BFS path to "<<tr<<" : "<<endl;
    for(auto it : path){
        cout<<it<<" ";
        if(it == tr)break;
    }
}
else{
    cout<<"not found the target"<<"\n";
}

path.clear();

cout<<endl;
if(graph.dfs(st , tr , path)){
    cout<<"DFS path to "<<tr<<" : "<<endl;
    for(auto it : path){
        cout<<it<<" ";
        if(it == tr)break;
    }
}
else{
    cout<<"not found the target"<<"\n";
}




}