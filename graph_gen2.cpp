#include<iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include<fstream>
#include <sstream>

using namespace std;

void swap( int* a, int *b )
{
   int temp;

   temp = *a;
   *a = *b;
   *b = temp;
}
int ran( int k )
{
   return rand() % k;
}
void print_graph( int v,
                  int e,
                  char* out_file,
                  int* adj_matrix)
{
   int i, j, index;
   FILE *fp;

   if ( ( fp = fopen( out_file, "w" ) ) == NULL ) {
      printf( "Unable to open file %s for writing.\n", out_file );
      return;
   }
   printf( "\n\tWriting graph to file %s.\n", out_file );

   fprintf( fp, "%d %d %d\n", v, v, e );

   
      for ( i = 0; i < v-1; i++ )
         for ( j = i + 1; j < v; j++ ) {
            index = i * v + j - 1;
            if ( adj_matrix[ index ] )
               fprintf( fp, "%d %d\n", i, j );
    	}
   fclose( fp );
   printf( "\tGraph is written to file %s.\n", out_file );
}
void init_array( int* a, int end )
{
   int i;

   for ( i = 0; i < end; i++ )
      *a++ = i;
}

void permute( int* a, int n )
{
   int i;

   for ( i = 0; i < n - 1; i++ )
      swap( a + i + ran( n - i ), a + i );
}
int main(){
	//int numV, numE;
	int v, e;
	cout<<"enter number of vertex"<<endl;
	cin>> v;
	cout<<"enter number of edges"<<endl;
	cin>> e;
	std::stringstream ss, ss1;
	ss << v;
	ss1 << e;
	//char* filename = "ConnectedGraph_"+ss.str()+"_vertix_"+ss1.str()+"_edges";
	//ofstream output(filename.c_str());

	int i, j, count, index, *adj_matrix, *tree;

	if ( ( adj_matrix = ( int * ) calloc( v * v, sizeof( int ) ) )
	     == NULL ) {
	   printf( "Not enough room for this size graph\n" );
	   return 1;
	}

	if ( ( tree = ( int * ) calloc( v, sizeof( int ) ) ) == NULL ) {
	   printf( "Not enough room for this size graph\n" );
	   free( adj_matrix );
	   return 1;
	}

   printf( "\n\tBeginning construction of graph.\n" );

   /*  Generate a random permutation in the array tree. */
  init_array( tree, v );

   // for ( int k = 0; k < v; k++ )
   //    *tree++ = k;
cout<<"happy till here"<<endl;
   
   permute( tree, v );
	// for ( int k = 0; k < v - 1; k++ )
 //    	swap( tree + k + ran( v - k ), tree + k );
   /*  Next generate a random spanning tree.
       The algorithm is:

         Assume that vertices tree[ 0 ],...,tree[ i - 1 ] are in
         the tree.  Add an edge incident on tree[ i ]
         and a random vertex in the set {tree[ 0 ],...,tree[ i - 1 ]}.
    */

   for ( i = 0; i < v-1; i++ ) {
      j = ran( i+1 );
      adj_matrix[ tree[ i ] * v + tree[ j ] ] = adj_matrix[ tree[ j ] * v + tree[ i ] ] = 1;
   }

   /* Add additional random edges until achieving at least desired number */
   for ( count = v - 1; count < e; ) {
      i = ran( v );
      j = ran( v );

      if ( i == j )
         continue;

      if ( i > j )
         swap( &i, &j );

      index = i * v + j;
      if ( !adj_matrix[ index ] ) {
         adj_matrix[ index ] = 1;
         count++;
      }
   }

   print_graph( v, count, "ConnectedGraph_testCase.txt", adj_matrix);

   free( tree );
   free( adj_matrix );
}