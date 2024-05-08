#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

vector<int>graph[N];

void coloring(int V){
	vector<int>result(V,-1);
	result[0]=0; 

	vector<bool>used(V,false);

	set<int>st;

	for (int u = 1; u < V; u++){
		//checking for available neighbours colors
		for (auto it:graph[u])			if (result[it] != -1)	used[result[it]] = true;
		
		//finding min available color
		int color;
		for (color = 0; color < V; color++)			if (used[color] == false)break;

		//assigning min color to current node
		result[u] = color; 

		//storing the unique colors
		st.insert(color);

		//reset neighbours colors
		for (auto it:graph[u])			if (result[it] != -1)	used[result[it]] = false;
	}
	
	cout<<"Vertex\tColour\n";
	for (int u = 0; u < V; u++){
		cout << u << "\t"<< result[u] << endl;
	}
	
	cout<<"\n Minimum colors used: "<<st.size()<<"\n";
}

int main()
{
	cout<<"Enter the number of vertex and edges ";
	int n,m;cin>>n>>m;
	cout<<"Enter the edges: \n";
	for(int i =0;i<m;i++){
		int a,b;cin >>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	coloring(n);

	return 0;
}