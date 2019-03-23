#include <fstream>
#include <algorithm> 
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <queue>
#include <vector>

using namespace std;


struct serverCFGs {
  int cfg[4];
  int cost; 
} srvcfg[126];


    vector<int> people;
    vector< vector<int> > combinations;
    vector<int> combination;

void adjacencyMatrix(int M,int N,string fileName);
int** computeDistancesFromFile(string fileName);
//void computeOPT(string D,string  r,string C0);
//void computeWFA(int** D,string  r,string  C0);
//void computeGreedy(int** D,string r,string C0);

void addEdge(vector <int> edges[], int u, int v) 
{ 
   edges[u].push_back(v); 
   edges[v].push_back(u); 
} 

 void pretty_func(const vector<int>& v) {
      static int count = 0;
      //cout << "combination no " << (++count) << ": [ ";
      //for (int i = 0; i < v.size(); ++i) { cout << v[i] << " "; }
      //cout << "] " << endl;
            combinations.push_back(v);
    }

  void combination_calc(int offset, int k) {
    if (k == 0) {
        pretty_func(combination);
        return;
      } 
      for (int i = offset; i <= people.size() - k; ++i) {
        combination.push_back(people[i]);
        combination_calc(i+1, k-1);
        combination.pop_back();
            }
}


void calCombinationCFG() {
    int n = 6, k = 4;
          combination_calc(0, k);
  
//    for(int i =0; i<=combinations.size(); i++){
//          for(int j =0; j<combinations[i].size();j++)
//                  cout<<combinations[i][j]<<" ";
//          cout<<endl;
          //cout<<"test size"<<combinations[i].size()<<endl;
//          }
          //cout<<"combinations size"<<combinations.size()<<endl;

}

int MinimumDisTwoConfig(int** D,int arr1[],int arr2[]){
         int totDis = 0;
         for (int i=0;i<4; i++){
                 if (arr1[i] == -1)
                         continue;
                 if (arr2[i] == -1)
                         continue;
                 int xpoint;
                 int ypoint;
                 xpoint = arr1[i];
                 ypoint = arr2[i];
                 totDis= D[xpoint][ypoint]+ totDis;
 
         }
         return totDis;
 
 }


int disStrings(int** Distance,int arr1[4], int arr2[4]){

int k=0;
int diffArr1[4] = {-1,-1,-1,-1};
for (int i=0;i<4;i++){
	int diff = 0;
	for (int j=0;j<4;j++){
	if (arr1[i] != arr2[j]){
		diff++;
	}
	}
	if (diff == 4){
		diffArr1[k] = arr1[i];
		k++;
		}
}
	//for (int i=0;i< 4;i++)
	//cout<< "DiffArr1:   "   <<diffArr1[i] << " \n";
	cout<< "\n";
//for (auto p = diffArr1.begin(); p != diffArr1.end(); p++) 
//cout<< "DiffArr1:   "   <<diffArr1[i] << " \n";
/////////////////////for diff2
 k=0;
 int diffArr2[4] = {-1,-1,-1,-1};
  for (int i=0;i<4;i++){
          int diff = 0;
          for (int j=0;j<4;j++){
          if (arr2[i] != arr1[j]){
                  diff++;
          }
          }
          if (diff == 4){
                  diffArr2[k] = arr2[i];
                  k++;
                  }
  }
          //for (int i=0;i< 4;i++)
          //cout<< "DiffArr2:   "   <<diffArr2[i] << " \n";
int dis;
dis = MinimumDisTwoConfig(Distance,diffArr1,diffArr2);
return dis;

}

void computeWFA(int** D,int r[],int C0[]){

for (int i=0;i<5;i++){
	cout << "i: "<< "request:  " << i <<  "  " << r[i]<<  "  \n";
	for (int j=0;j<126;j++){	

		cout << "config[j]\n";
		for (int a=0;a<4;a++)
		cout << srvcfg[j].cfg[a] << "  ";
		cout << "\n";



		int found =0;
 		for(int k =0;k<4;k++){
         	if (r[i] ==  srvcfg[j].cfg[k]){
			found = 1;
			cout << "foundddd" << "\n";
			break;
         	}//if
				
		}//k: array of each config

		
		if (found == 0){//cal cost for processing r[i]
			cout<< "found == 0" << "\n";
			int origcfg0[4];
			int origcfg1[4];
			int origcfg2[4];
			int origcfg3[4];

			for(int l =0;l<4;l++){

			origcfg0[l] = srvcfg[j].cfg[l];
			origcfg1[l] = srvcfg[j].cfg[l];
			origcfg2[l] = srvcfg[j].cfg[l];
			origcfg3[l] = srvcfg[j].cfg[l];
			
			}

			origcfg0[0] = r[i];
			origcfg1[1] = r[i];
			origcfg2[2] = r[i];
			origcfg3[3] = r[i];

			for(int k =0;k<4;k++)
			cout << "cfg0: " << origcfg0[k] << " ";
			cout << "\n";
			
			
			for(int k =0;k<4;k++)
			cout <<  "cfg1: "<<  origcfg1[k] << " ";
			cout << "\n";
			
			for(int k =0;k<4;k++)
			cout <<  "cfg2: " << origcfg2[k] << " ";
			cout << "\n";
			

			for(int k =0;k<4;k++)
			cout <<  "cfg3: " << origcfg3[k] << " ";
			cout << "\n";
			


	
			int cost0,cost1,cost2,cost3,cost;

			//cost0= disStrings(D,C0,origcfg0); //+ D[r[i],origcfg0[0]];
			int index;
			int m = sizeof(origcfg0)/sizeof(origcfg0[0]); 
  			sort(origcfg0, origcfg0+m); 
			for (int z=0;z<126;z++){
				if (origcfg0[0] == srvcfg[z].cfg[0] &&
					origcfg0[1] == srvcfg[z].cfg[1] &&
						origcfg0[2] == srvcfg[z].cfg[2] &&
							origcfg0[3] == srvcfg[z].cfg[3]) {
					
				index = z;
				cout << "index : " << index <<"\n";
				}
				
			}
				
							
			cost0= srvcfg[index].cost;  
			cost1= disStrings(D,C0,origcfg1); //+ D[r[i],origcfg1[1]];
			cost2= disStrings(D,C0,origcfg2); //+ D[r[i],origcfg2[2]];
			cost3= disStrings(D,C0,origcfg3); //+ D[r[i],origcfg3[3]];
			
			cout << "cost0: "<< cost0 << "\n";
			cout << "cost1: "<< cost1 << "\n"; 
			cout << "cost2: "<< cost2 << "\n";
			cout << "cost3: "<< cost3 << "\n";
				
			cost = min (cost0,cost1);
			cost = min (cost,cost2);	
			cost = min (cost,cost3);

			cout << "min cost: "<< cost;
				
					

			srvcfg[j].cost= cost;
			cout<< cost <<"  ";
		
		}
		else if (found == 1){ //cost is the same as previous step 
			cout << "Found == 1" << " \n";
			srvcfg[j].cost = srvcfg[j].cost;
			
		}
	}//j :Number of  configs
	}//i: Number of requests

}

int minEdgeBFS(vector <int> edges[], int u, int v, int n) 
{

    // visited[n] for keeping track of visited 
    // node in BFS 
    vector<bool> visited(n, 0); 
     	
    // Initialize distances as 0 
    vector<int> distance(n, 0); 
  
    // queue to do BFS. 
    queue <int> Q; 
    distance[u] = 0; 
 	//std::cout << "u: source:  " << u << "\n"; 
    Q.push(u); 
    visited[u] = true; 
    while (!Q.empty()) 
    {
        int x = Q.front();
	Q.pop(); 
        //std::cout << "front: " << x << "\n" ;
 
      for (int i=0; i<edges[x].size(); i++) 
	//for (int i=0; i<5; i++)
        {
	//std::cout << "visited: " << visited[edges[x][i]]  << "\n" ;	 
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

 int** computeDistancesFromFile(string fileName)
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
const int M = 9;
 int** matrix;                      // Creates a pointer to the array
 matrix = new int*[M];            // Creates the array of M*M size
 //std::fill(matrix, &matrix[0][0], &matrix[M][0], 0); // From <algorithm>, zeros all entries.
 for (int i = 0; i < M; i++)
     {
	matrix[i]= new int[M];
         for (int j = 0; j < M; j++)
         {
		matrix[i][j] = minEdgeBFS(edges, i,j , 9);
         }
         //std::cout << std::endl;
     }
for (int i = 0; i < M; i++)
       {
           for (int j = 0; j < M; j++)
          {
		cout << matrix[i][j] << ' ';
          }
          std::cout << std::endl;
      }
return matrix;
  }//

int computeGreedy(int** D,int r[],int C0[]){
	int cost = 0;
	int ymin =0;
	int xmin =0;
	
	 for (int i = 0; i < 4; i++)
       	{
		cout <<  "original C0 "<< "\n" ;
	
		for (int k = 0; k<4; k++)
         {
                 cout << C0[k]<< "  ";
         }
	cout <<   "\n" ;
	
		int x = r[i];
		int x0 = r[0];
		int y0 = C0[0];
		int min = D[x0][y0];	
		//cout << x << "x: \n";
            for (int j = 0; j < 4; j++)
           {
		int y = C0[j];
		if (D[x][y] < min){
		min = D[x][y];
		xmin = x;
		ymin = y;
		}
		//min = std::min(min, D[x][y]);
		
                 cout << D[x][y] << ' ';
           }
	   std::cout << "min: " << "xmin: " << " ymin: " << min << "  " <<xmin << "  " << ymin << "\n";
	   //update C0
	   C0[ymin] = r[i];
	std::cout << "updated C0 " << "\n" ;
	for (int k = 0; k<4; k++)
	{
		cout << C0[k]<< "  ";
	}
	cout <<   "\n" ;	
	   cost = cost + min;
	   std::cout << "cost: " << cost ; 	
	
           std::cout << std::endl;
       	}	
	//cout << D[3][1] << "vvvvvvv\n";
	return cost;
}	
/*
int MinimumDisTwoConfig(int** D,int arr1[],int arr2[]){
	int totDis = 0;
	for (int i=0;i<4; i++){
		if (arr1[i] == -1)
			continue;
		if (arr2[i] == -1)
			continue;
		int xpoint;
		int ypoint;
		xpoint = arr1[i];
		ypoint = arr2[i];
		totDis= D[xpoint][ypoint]+ totDis; 
			
	}
	return totDis;

}
*/

int main()
  {

string fileName = "ENZYMES_g473.txt";
int** Distance;
Distance = computeDistancesFromFile(fileName);
int C0[] = {0,1,2,3};
int requests[] = {4,5,6,7};
computeGreedy( Distance, requests, C0);


//Intialize all points
            people.push_back(0);
            people.push_back(1);
            people.push_back(2);
            people.push_back(3);
            people.push_back(4);
            people.push_back(5);
            people.push_back(6);
            people.push_back(7);
            people.push_back(8);
calCombinationCFG();


    for(int i =0; i<=combinations.size(); i++){
            for(int j =0; j<combinations[i].size();j++){
		      srvcfg[i].cfg[j] = combinations[i][j];
		      
                    //cout<<combinations[i][j]<<" ";
		      cout<< srvcfg[i].cfg[j] <<" ";
		}
            cout<<endl;
	}

int C00[4] = {0,1,2,3};
//int C1[4];
int C1[4]= {-1,-1,-1,-1};
//disStrings(C00,C1);
int dis;
for (int i =0; i< 126; i++){

	for (int j =0;j<4;j++){
	C1[j] = srvcfg[i].cfg[j];
	//cout<< "C1: "<<C1[j] <<"  ";
	}
	//cout << "\n";
	

	dis = disStrings(Distance,C00,C1);
	//dis = MinimumDisTwoConfig(Distance,C00,C1);
	srvcfg[i].cost = dis;

}
int C11[4]= {4,1,2,3};
dis = disStrings(Distance,C00,C11);
cout << "xxxxxxxxxxdis: "<< dis << "\n";


//Fill struct of configurations

//for (int i;i<4;i++)
//cout << C00[i]<< " ";
//for (int i =0; i< 126; i++){
//	cout<< srvcfg[i].cost <<" \n";
//}

computeWFA(Distance,requests,C00);







}
