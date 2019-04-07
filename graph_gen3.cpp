#include<iostream>
#include<random>
#include<algorithm>
#include<vector>
#include<fstream>
#include <list>
#include <ctime>
using namespace std;

vector< vector<int> > create_complete_graph(int v)
{
	vector<int> temp;
	vector< vector <int> > res;
	for(int i=0;i<v;i++)
		temp.push_back(1);
	for(int j=0;j<v;j++)
		res.push_back(temp);

	return res;
}

vector<vector<int> > random_graph(double p, vector<vector<int> > g)
{
	int pr = p * 100;
	int rnd = 0;
	srand(time(NULL));
	for(int i=0; i < g.size();i++)
	{
		for(int j=0; j<g.size();j++)
		{
			rnd = rand() % 100;
			//cout<<rnd<<endl;
			if(rnd > pr)
				g[i][j] = 0;
			if(i==j) //no circle edge
				g[i][j] == 0;
		}
		
	}
	
	for(int i=0; i < g.size();i++)
		for(int j=0; j<g.size();j++)
			if(g[i][j]==1 && g[j][i]==1) //undirected
			{
				rnd = rand() % 100;
                        	if(rnd > pr)
                                	g[i][j] = 0;
				else
					g[j][i] = 0;
			}

	return g;
}
void DFSUtil(int v, bool visited[], list<int> *adj) 
{ 
    // Mark the current node as visited and print it 
    visited[v] = true; 
  
    // Recur for all the vertices adjacent to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited, adj); 
} 
bool is_connected(vector<vector<int> > g)
{
	bool visited[g.size()]; 
    	list<int> *adj;
	adj = new list<int>[g.size()];
	
	
	for (int i = 0; i < g.size(); i++) 
        	visited[i] = false; 
    	
	for(int i =0;i<g.size();i++)
		for(int j =0;j<g.size();j++)
			if(g[i][j]!=0)
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}

	for(int i =0;i<g.size(); i++)
		adj[i].unique();
	
	DFSUtil(0, visited, adj); 
 	cout<<"here"<<endl; 
     	// If DFS traversal doesn’t visit all vertices, then return false. 
    	for (int i = 0; i < g.size(); i++) 
        	if (visited[i] == false) 
             		{
				cout<<"ever here"<<endl;
				delete [] adj;
				return false;
			} 	
	delete [] adj;
	return true;
}

int edge_count(vector< vector<int> > g)
{
	int count = 0;
	for(int i =0;i<g.size();i++)
		for(int j=0;j<g.size();j++)
			if(g[i][j]!=0)
				count++;

	return count;
}
void print_graph(vector< vector<int> > g)
{
	int e = edge_count(g);
	ofstream file;
	file.open("graph_rand_con_test.txt");
	file<<g.size()<<" "<<g.size()<<" "<<e<<endl;
	for(int i=0; i < g.size();i++)
	{
		for(int j=0; j<g.size();j++)
		{
			if(g[i][j]!=0)
				file<<i<<" "<<j<<endl;
		}
	}
	file.close();
}
int main()
{
	vector<vector<int> > graph;
	int n;
	double p;
	cout<<"Number of nodes: "<<endl;
	cin>>n;
	cout<<"probability for edge generation: "<<endl;
	cin>>p;
	graph = create_complete_graph(n);
	do{
		graph = random_graph(p, graph);
	}while(!is_connected(graph));
	
	print_graph(graph);
	return 0;
}
