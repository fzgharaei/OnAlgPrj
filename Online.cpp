#include <fstream>
#include <algorithm> 
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{

// Declare variables:
int M, N;
M = 4;
N = 12;

// Create and initialize matrix:
double* matrix;			     // Creates a pointer to the array
matrix = new double[M*N];	     // Creates the array of M*N size
std::fill(matrix, matrix + M*N, 0.); // From <algorithm>, zeros all entries.

// Open the file:
std::ifstream file("ENZYMES_g473.txt");
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
	std::cout << m << " " <<  n << "\n";
	matrix[(m-1)*M + n - 1] = 1;
	matrix[(n-1)*M + m - 1] = 1;
}

std::cout << "\n";
file.close();
for (int m = 0; m < M; m++)
{
    for(int n = 0; n < N; n++)
        std::cout << matrix[m + n*M] << ' ';
    std::cout << std::endl;
}
}
