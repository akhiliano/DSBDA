#include<bits/stdc++.h>
using namespace std;

class DSU{
    int* parent;
    int* rank;
public:
    DSU(int n){
        parent=new int[n];
        rank=new int[n];
        for(int i=0;i<n;i++){
            parent[i]=-1;
            rank[i]=1;
        }
    }

    int find(int i){
        if(parent[i]==-1)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y){
        int s1=find(x);
        int s2=find(y);
        if(s1!=s2){
            if(rank[s1]<rank[s2]){
                parent[s1]=s2;
            }
            else if(rank[s1]>rank[s2]){
                parent[s2]=s1;
            }
            else{
                parent[s2]=s1;
                rank[s1]+=1;
            }
        }
    }
};

class frieden{
    public:
    void selection_sort(vector<int> &arr, int n){
        int i, j, min_index;

        for(i=0; i<n-1; i++){
            min_index = i;
            for(j= i+1; j<n; j++){
                if (arr[j]<arr[min_index]){
                    min_index = j;
                }
            }

            if (min_index != i){
                swap(arr[i], arr[min_index]);
            }
        }

        cout<<"\nSorted array is : ";

        for (i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
    }

    void prims(vector<vector<int>> graph, int V){
        int parent[V];
        int key[V];
        bool mstSet[V];
    
        for (int i = 0; i < V; i++)
            key[i] = INT_MAX, mstSet[i] = false;
    
        key[0] = 0;
        parent[0] = -1;
    
        for (int count = 0; count < V - 1; count++) {
            int min_index = INT_MAX, u;
            for (int v = 0; v < V; v++){
                if (mstSet[v] == false && key[v] < min_index)
                    min_index = key[v], u = v;
            }
   
            mstSet[u] = true;
    
            for (int v = 0; v < V; v++){
                if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                    parent[v] = u, key[v] = graph[u][v];
            }
        }

        cout<<"\nMinimum spanning tree formed using edges :";
        cout<<("\nEdge\t\tWeight\n");
        int ans = 0;
        for (int i = 1; i < V; i++){
            cout<<parent[i]<<"\t"<<i<<"\t"<<graph[i][parent[i]]<<"\n";
            ans += graph[i][parent[i]];
        }
        cout << "\nMinimum Cost Spanning Tree: " << ans<<endl;
    }

    void kruskals(vector<vector<int>> graph, int n){
        DSU ss(n);

        int ans = 0;
        cout<<"\nMinimum spanning tree formed using edges :";
        cout << "\nEdge\t\tWeight"<< endl;
        for (auto edge : graph) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
            if (ss.find(x) != ss.find(y)) {
                ss.unite(x, y);
                ans += w;
                cout << x << "\t" << y << "\t" << w<< endl;
            }
        }

        cout << "\nMinimum Cost Spanning Tree: " << ans<<endl;

    }

    int minDistance(int dist[], bool sptSet[],int V){
        int min=INT_MAX,min_index;
        for(int v=0;v<V;v++)
            if(sptSet[v]==false && dist[v]<=min)
                min=dist[v],min_index=v;
        return min_index;
    }

    void Dijistra(vector<vector<int>> &graph,int V,int E){
        int src=0;
        int dist[V];
        bool sptSet[V];
        for (int i = 0; i < V; i++) dist[i] = INT_MAX, sptSet[i] = false;
        dist[src] = 0;
        for (int count = 0; count < V - 1; count++) {
            int u = minDistance(dist, sptSet,V);
            sptSet[u] = true;
                for (int v = 0; v < V; v++)
                    if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                        dist[v] = dist[u] + graph[u][v];
        }

        cout << "\nVertex \t Distance from Source" << endl;
        for (int i = 0; i < V; i++)
            cout << i << "\t\t" << dist[i] << endl;
    }
};

int main(){
    frieden f;
    int Flag = 1;

    cout<<"\t\t\t --- Greedy Algorithm ---";

    while(Flag == 1){
        int choice;

        cout<<"\n\nUser manual :\n1. Selection sort\n2. prims\n3. kruskals\n4. Dijisktra\n5. Exit\n";
        cout<<"\nEnter your choice : ";
        cin>>choice;

        if(choice == 1){
            vector<int> arr;
            int n;
            cout<<"\nEnter Size of array : ";
            cin>>n;
            cout<<"\nEnter array to sort : ";

            for (int i=0; i<n; i++){
                int temp;
                cin>>temp;
                arr.push_back(temp);
            }

            f.selection_sort(arr, n);

        }
        else if(choice == 2){
            int vertex, edge;

            cout<<"Number of vertex : ";
            cin>>vertex;
            cout<<"Number of edge: ";
            cin>>edge;
            cout<<"\nEnter the source, destination and cost :\n";

            vector<vector<int>> graph(vertex, vector<int>(vertex, 0));

            for(int i=0; i<edge; i++){
                int x, y, cost;
                cin>>x;
                cin>>y;
                cin>>cost;

                graph[x][y] = cost;
                graph[y][x] = cost;
            }
            f.prims(graph, vertex);
        }
        else if(choice == 3){
            int vertex, edge;

            cout<<"Number of vertex : ";
            cin>>vertex;
            cout<<"Number of edge: ";
            cin>>edge;
            cout<<"\nEnter the source, destination and cost :\n";

            vector<vector<int>> graph;

            for(int i=0; i<edge; i++){
                int x, y, cost;
                cin>>x;
                cin>>y;
                cin>>cost;
                graph.push_back({cost, x, y});
            }

            sort(graph.begin(), graph.end());
            f.kruskals(graph, vertex);

        }
        else if(choice == 4){
            int vertex, edge;

            cout<<"Number of vertex : ";
            cin>>vertex;
            cout<<"Number of edge: ";
            cin>>edge;
            cout<<"\nEnter the source, destination and cost :\n";

            vector<vector<int>> graph(vertex, vector<int>(vertex, 0));

            for(int i=0; i<edge; i++){
                int x, y, cost;
                cin>>x;
                cin>>y;
                cin>>cost;

                graph[x][y] = cost;
                graph[y][x] = cost;
            }

            f.Dijistra(graph, vertex, edge);

        }
        else if(choice == 5){
            cout<<"\n\nSuccessfully terminated !!";
            Flag = 0;
        }
        else{
            cout<<"\n\nInvalid choice, terminated !!";
            return 0;
        }

    }

    return 0;
}

/*
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9
*/


/* 
0 1 4
1 7 11
0 7 8
1 2 8
7 8 7
7 6 1
2 8 2
8 6 6
2 5 4
6 5 2
2 3 7
3 5 14
3 4 9
5 4 10
*/