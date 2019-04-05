
// A C++ Program to generate test cases for 
// an unweighted directed graph 
#include<bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    set<pair<int, int> > container; 
    set<pair<int, int> >::iterator it; 
      
    freopen ("Test_Graph.txt", "w", stdout); 
      
    //For random values every time 
    srand(time(NULL)); 
      
    int NUM = 8;    // Number of Vertices - can be read from input
    int NUMEDGE = 18; // Number of Edges 
	printf("%d %d %d\n", NUM, NUM, NUMEDGE);      
//    for (int i=1; i<=3; i++) // 3 generation for test
 //   { 
        //NUM = 1 + rand() % MAX_VERTICES; 
      
        // the most dense graph can have N*(N-1)/2 edges 
        //NUMEDGE = 1 + rand() % MAX_EDGES; 
          
        //while (NUMEDGE > NUM*(NUM-1)/2) 
         //       NUMEDGE = 1 + rand() % MAX_EDGES;         
          
        //printf("%d %d\n", NUM, NUMEDGE); 
          
        // Then print the edges of the form (a b) 
        // where 'a' is connected to 'b' 
        for (int j=0; j<NUMEDGE; j++) 
        { 
            int a = rand() % NUM; 
            int b = rand() % NUM; 
            pair<int, int> p = make_pair(a, b); 
              
            // Search for a random "new" edge everytime 
            // Note - In a tree the edge (a, b) is same  
            // as the edge (b, a) 
            while (container.find(p) != container.end()) 
            { 
                a = rand() % NUM; 
                b = rand() % NUM; 
                p = make_pair(a, b); 
            } 
            container.insert(p); 
        } 
              
        for (it=container.begin(); it!=container.end(); ++it) 
            printf("%d %d\n", it->first, it->second); 
              
        container.clear(); 
        printf("\n");             
      
 //   } 
    // Uncomment the below line to store 
    // the test data in a file 
    fclose(stdout); 
    return(0); 
} 

