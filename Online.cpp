#include <fstream>
#include <algorithm> 
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <queue>
#include <vector>

using namespace std;

void adjacencyMatrix(int M,int N,string fileName);
void computeDistancesFromFile(string fileName);
void computeOPT(string D,string  r,string C0);
void computeWFA(string D,string  r,string  C0);
void computeGreedy(string D,string r,string C0);

void addEdge(vector <int> edges[], int u, int v) 
{ 
   edges[u].push_back(v); 
   edges[v].push_back(u); 
} 


int minEdgeBFS(vector <int> edges[], int u, int v, int n) 
//int minEdgeBFS(int edges[5][5], int u, int v, int n)
{


    // visited[n] for keeping track of visited 
    // node in BFS 
    vector<bool> visited(n, 0); 
     	
  
    // Initialize distances as 0 
    vector<int> distance(n, 0); 
  
    // queue to do BFS. 
    queue <int> Q; 
    distance[u] = 0; 
 	std::cout << "u: source:  " << u << "\n"; 
    Q.push(u); 
    visited[u] = true; 
    while (!Q.empty()) 
    {
        int x = Q.front();
	Q.pop(); 
        std::cout << "front: " << x << "\n" ;
 
      for (int i=0; i<edges[x].size(); i++) 
	//for (int i=0; i<5; i++)
        {
	std::cout << "visited: " << visited[edges[x][i]]  << "\n" ;	 
            if (visited[edges[x][i]]) 
                continue; 
  
            // update distance for i 
            distance[edges[x][i]] = distance[x] + 1; 
            Q.push(edges[x][i]); 
            visited[edges[x][i]] = 1; 
        } 
    } 
    return distance[v];
} 





 void computeDistancesFromFile(string fileName)
 {
vector <int> edges[9];
  
  std::ifstream file(fileName);
  std::string line;
  
  while (std::getline(file, line))
  {
  // Ignore headers and comments
  if (line.length() >= 4 || line[0] == '%')
          continue;
      std::istringstream iss(line);
      int m, n;
      if (!(iss >> m >> n)) { break; } // error
  
      // process pair (m,n)
          std::cout << m << "  " <<  n << "\n";
	  addEdge(edges, m, n);	  
  }
  
  
  std::cout << "\n";
  //fin.close();

int M = 9;
int Matrix2D[M][M];
 for (int i = 0; i < M; i++)
     {
         for (int j = 0; j < M; j++)
         {
	     Matrix2D[i][j] = minEdgeBFS(edges, i,j , 9);
             //cout << Matrix2D[i][j] << ' ';
 
         }
         //std::cout << std::endl;
     }

for (int i = 0; i < M; i++)
       {
           for (int j = 0; j < M; j++)
          {
              //Matrix2D[i][j] = minEdgeBFS(edges, i,j , 9);
              cout << Matrix2D[i][j] << ' ';
 
          }
          std::cout << std::endl;
      }



//int x = minEdgeBFS(edges, 4,6 , 9);
//std::cout << x << "\n";
  }//
int main()
  {

string fileName = "ENZYMES_g473.txt";
computeDistancesFromFile(fileName);

}
