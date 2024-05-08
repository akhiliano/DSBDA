#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>goal,intitial;

map<vector<vector<int>>,int>vis;

void func(vector<vector<vector<int>>> &v,int k){
	vector<vector<vector<int>>>vec;
	
	vector<pair<int,vector<vector<int>>>>vp; // stores a state and its heuristic
	cout<<"\nNEXT ITERATION\n"<<endl;
	
	if(v.size()==0) {
		cout<<"NO solution"<<endl;return ;
	}
	for(int I=0;I<v.size();I++){
		vector<vector<int>>d=v[I];
		
		if(d==goal){
			cout<<"final state is achieved after " << k-1 << " steps"<<endl;
			
			return ;
		}
		int i1,j1;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(d[i][j]==-1){
					i1=i;j1=j;
				}
			}
		}
		int h;
		cout<<endl;
		cout<<"The states at step "<<k+1<<" is "<<endl;
		if(i1-1>=0){
			d[i1][j1]=d[i1-1][j1];
			d[i1-1][j1]=-1;

			h=0;
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					cout<<d[i][j]<<" ";
					if(goal[i][j]==-1){
					}
					else if(goal[i][j]!=d[i][j]) h++;
				}
				cout<<endl;
			}
			cout<<endl;

			if(vis[d]==0){
				vis[d]++;
				vp.push_back({k+h,d});
			}
			else cout<<"->this state is repeating"<<endl;
				d[i1-1][j1]=d[i1][j1];
				d[i1][j1]=-1;
				cout<<"g(n) = "<<k<<endl;
				cout<<"h(n) = "<<h<<endl;
				cout<<"f(n) = "<<k+h<<endl<<endl;
				
		}
		if(i1+1<3){
			d[i1][j1]=d[i1+1][j1];
			d[i1+1][j1]=-1;

			h=0;
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					cout<<d[i][j]<<" ";
					if(goal[i][j]==-1){
					}
					else if(goal[i][j]!=d[i][j]) h++;
				}
				cout<<endl;
			}
			cout<<endl;
			if(vis[d]==0){
				vis[d]++;
				vp.push_back({k+h,d});
			}
			else cout<<"->this state is repeating"<<endl;
			d[i1+1][j1]=d[i1][j1];
			d[i1][j1]=-1;
			cout<<"g(n) = "<<k<<endl;
			cout<<"h(n) = "<<h<<endl;
			cout<<"f(n) = "<<k+h<<endl;
			cout<<endl;
		}
		if(j1-1>=0){
			d[i1][j1]=d[i1][j1-1];
			d[i1][j1-1]=-1;
			h=0;
			for(int i =0;i<3;i++){
				for(int j=0;j<3;j++){
					cout<<d[i][j]<<" ";
					if(goal[i][j]==-1){
					}
					else if(goal[i][j]!=d[i][j]) h++;
				}
				cout<<endl;
			}
			cout<<endl;
			if(vis[d]==0){
				vis[d]++;
				vp.push_back({k+h,d});
			}
			else cout<<"->this state is repeating"<<endl;
			d[i1][j1-1]=d[i1][j1];
			d[i1][j1]=-1;
			cout<<"g(n) = "<<k<<endl;
			cout<<"h(n) = "<<h<<endl;
			cout<<"f(n) = "<<k+h<<endl;
			cout<<endl;
		}
		if(j1+1<3){
			d[i1][j1]=d[i1][j1+1];
			d[i1][j1+1]=-1;

			h=0;
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					cout<<d[i][j]<<" ";
					if(goal[i][j]==-1){
					}
					else if(goal[i][j]!=d[i][j]) h++;
				}
				cout<<endl;
			}
			cout<<endl;
			if(vis[d]==0){
				vis[d]++;
				vp.push_back({k+h,d});
			}else{
				cout<<"->this state is repeating"<<endl;
			}
			d[i1][j1+1]=d[i1][j1];
			d[i1][j1]=-1;
			cout<<"g(n) = "<<k<<endl;
			cout<<"h(n) = "<<h<<endl;
			cout<<"f(n) = "<<k+h<<endl;
			cout<<endl;
		}
			
	}
	if(vp.size()){
	sort(vp.begin(),vp.end());
	vec.push_back(vp[0].second);
	}
	cout<<endl;
	//cout<<"F values: ";
	//for(auto xp : vp) cout<<xp.first<<" ";
	cout<<endl;
	for(int i=1;i<vp.size();i++){
		if(vp[i].first==vp[i-1].first) vec.push_back(vp[i].second);
		else break;
	}
	
	cout<<"minimum huiristic values are:"<<endl;
	
	for(int i=0;i<vec.size();i++){
		vector<vector<int>>pr=vec[i];
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				cout<<pr[j][k]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		cout<<"f(n) = "<<vp[i].first<<endl;
	}
	func(vec,k+1);
}



int main(){
	cout<<"enter initial state "<<endl;
	for(int i=0;i<3;i++){
		vector<int>v;
		for(int j=0;j<3;j++){
			int k;cin>>k;
			v.push_back(k);	
		}
		intitial.push_back(v);
	} 
	cout<<"enter final state "<<endl;
	for(int i=0;i<3;i++){
		vector<int>v1;
		for(int j=0;j<3;j++){
			int k;cin>>k;
			v1.push_back(k);
		}
		goal.push_back(v1);
	}
	vector<vector<vector<int>>>vec;
	vec.push_back(intitial);int k=1;
	func(vec,k);
	return 0;
}
