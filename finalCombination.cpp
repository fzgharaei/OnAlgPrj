#include<iostream>
#include<vector>
 
using namespace std;
 
vector< vector<int> > Combination(int a[], int reqLen, int start, int currLen, bool check[], int len) 
//void Combination(int a[], int reqLen, int start, int currLen, bool check[], int len)
{
vector< vector<int> > vec(126, vector<int>(4));
//vector< vector<int> > vec;
cout<<"here 0"<<endl;
vector<int> temp;
	// Return if the currLen is more than the required length.
	if(currLen > reqLen)
	{
		cout<<"here1"<<endl;
		return vec;
	}// If currLen is equal to required length then print the sequence.
	else 	if (currLen == reqLen) 
	{
		int count = 0;
		//vector<int> temp;
		cout<<"here again"<<endl;
		cout<<"\t";
		for (int i = 0; i < len; i++) 
		{
			
			if (check[i] == true) 
			{
				//cout<<a[i]<<" ";
				temp.push_back(a[i]);
				//cout<< temp[i];
				
			}
			
		}
		vec.push_back(temp);

/*	std::cout <<  vec[126].at(0) << ' ';
	std::cout <<  vec[126].at(1) << ' ';
	std::cout <<  vec[126].at(2) << ' ';
	std::cout <<  vec[126].at(3) << ' ';
*/		cout<<"\n";
		cout<<"here2"<<endl;
		return vec;
	}
	// If start equals to len then return since no further element left.
	if (start == len) 
	{
		cout<<"here3"<<endl;
		return vec;
	}
	// For every index we have two options.
	// First is, we select it, means put true in check[] and increment currLen and start.
	check[start] = true;
	cout<<"here4"<<endl;
	Combination(a, reqLen, start + 1, currLen + 1, check, len);
	// Second is, we don't select it, means put false in check[] and only start incremented.
	check[start] = false;
	cout<<"here5"<<endl;
	Combination(a, reqLen, start + 1, currLen, check, len);
}
 
int main()
{
int arr[9]={1,2,3,4,5,6,7,8,9};
bool check[9]={false,false,false,false,false,false,false,false,false};

vector<vector<int> > finalVec;
Combination(arr, 4, 0, 0, check, 9);

finalVec = Combination(arr, 4, 0, 0, check, 9);
       	  std::cout <<  finalVec[126].at(0) << ' ';
          std::cout <<  finalVec[126].at(1) << ' ';
          std::cout <<  finalVec[126].at(2) << ' ';
          std::cout <<  finalVec[126].at(3) << ' ';


	return 0;




}
