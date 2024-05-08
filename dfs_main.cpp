#include <bits/stdc++.h>
using namespace std;

// A simple representation of a graph using an adjacency list
class Graph {
public:
    int vertices;
    vector<vector<int>> adjList;

    Graph(int V) : vertices(V), adjList(V) {}

    // Function to add an edge to the graph
    void addEdge(int v, int w) {
        adjList[v].push_back(w);
    }
};

// Depth-First Search (DFS) Algorithm
void dfs(const Graph& graph, int start, vector<bool>& visited, vector<int>&path,int target) {
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int current = s.top();
        s.pop();
if(current == target)break;

        if (!visited[current]) {
            visited[current] = true;
            path.push_back(current);

            
            

            for (int neighbor : graph.adjList[current]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
        
    }
}

// Depth-Limited Search (DLS) in DFS Algorithm
void dls(const Graph& graph, int start, int depthLimit, vector<bool>& visited, vector<int>& path) {
    stack<pair<int, int>> s;  // Pair of node and its depth
    s.push({start, 0});

    while (!s.empty()) {
        int current = s.top().first;
        int depth = s.top().second;
        s.pop();

        if (depth <= depthLimit && !visited[current]) {
            visited[current] = true;
            path.push_back(current);

            for (int neighbor : graph.adjList[current]) {
                if (!visited[neighbor]) {
                    s.push({neighbor, depth + 1});
                }
            }
        }
    }
}

// Breadth-First Search (BFS) Algorithm
void bfs(const Graph& graph, int start, vector<bool>& visited, vector<int>& path) {
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (!visited[current]) {
            visited[current] = true;
            path.push_back(current);

            for (int neighbor : graph.adjList[current]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                }
            }
        }
    }
}

bool dfs_search(const Graph& graph, int start, int target) {
    stack<int> s;
    vector<bool>visited(graph.vertices,false);
    s.push(start);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

         if(current == target)return true;         

        if (!visited[current]) {
            visited[current] = true;
            

            for (int neighbor : graph.adjList[current]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
   return false;
}

bool bfs_search(const Graph& graph, int start, int target) {
    queue<int> q;
     vector<bool>visited(graph.vertices,false);
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

       if(current == target)return true;   

        if (!visited[current]) {
            visited[current] = true;
            

            for (int neighbor : graph.adjList[current]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                }
            }
        }
    }
    return false;
}


int main() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    vector<int>v;
    Graph graph(vertices);

    cout << "Enter the edges (format: vertex1 vertex2):" << endl;
    for (int i = 0; i < edges; ++i) {
        int v, w;
        cin >> v >> w;
        graph.addEdge(v, w);
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    vector<bool> visited(vertices, false);
    vector<int> path;

   /* // Depth-First Search
    dfs(graph, startVertex, visited, path);
    cout << "DFS Path: ";
    for (int vertex : path) {
        cout << vertex << " ";
    }
    cout << endl;*/

    // Depth-Limited Search
    int depthLimit;
    cout << "Enter the depth limit for DLS: ";
    cin >> depthLimit;
    visited.assign(vertices, false);
    path.clear();
    dls(graph, startVertex, depthLimit, visited, path);
    cout << "DLS Path (up to depth " << depthLimit << "): ";
    for (int vertex : path) {
        cout << vertex << " ";
    }
    cout << endl;

  /*  // Breadth-First Search
    visited.assign(vertices, false);
    path.clear();
    bfs(graph, startVertex, visited, path);
    cout << "BFS Path: ";
    for (int vertex : path) {
        cout << vertex << " ";
    }
    cout << endl;*/

    int targetVertex;
    cout<<"Enter the target vertex you want to search : "<<endl;
    cin>>targetVertex;

    int ch;
    cout<<"ENter choice 1.dfs search   and 2.bfs search : "<<endl;
    cin>>ch;

    
    if(ch==1){
    bool foundDFS = dfs_search(graph , startVertex ,targetVertex);
    cout<<"dfs search result : "<<(foundDFS ? "found" : "not found")<<endl;

// Depth-First Search
    dfs(graph, startVertex, visited, path ,targetVertex);
    cout << "DFS Path: ";
    for (int vertex : path) {
        cout << vertex << " ";
        v.push_back(vertex);
        if(vertex == targetVertex)break;
    }
    
    reverse(v.begin(),v.end());
    for (int i=1;i<v.size();i++) {
    // if(vertex == targetVertex)break;
        cout << v[i] << " ";
        
    }
    cout << endl;
    
    }


    if(ch==2){
    bool foundBFS = bfs_search(graph , startVertex ,targetVertex);
    cout<<"bfs search result : "<<(foundBFS ? "found" : "not found")<<endl;
    }
    


// Breadth-First Search
    visited.assign(vertices, false);
    path.clear();
    bfs(graph, startVertex, visited, path);
    cout << "BFS Path: ";
    for (int vertex : path) {
        cout << vertex << " ";
    }
    cout << endl;









    cout << endl;

    

    return 0;
}
