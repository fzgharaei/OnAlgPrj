#include<iostream>
#include <cstdlib>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

//(a) generate the input sequence by sampling each new request uniformly 
//at random from [n] and independently of all other requests;
vector<int> uniform(int n, int len){
int range_from  = 0;
int range_to    = n;
vector<int> results;
std::random_device                  rand_dev;
std::mt19937                        generator(rand_dev());
std::uniform_int_distribution<int>  distr(range_from, range_to);

for (int i = 0; i < len; ++i)
	results.push_back(distr(generator));


return results;
}
// (b)generate the input sequence randomly but with some dependence 
// (maybe the input sequence arises out of some Markov chain process); 
vector<int> markov(int n, int len) //somewhat like random walk
{
	vector<int> results;
	int a_point = n/2;
	results.push_back(a_point);
	
	while(results.size()<len){
		double rnd = rand() / ((double) RAND_MAX);
		if(rnd < 0.5 && a_point>0)
			a_point--;
		else if(a_point<20)
			a_point++;
		else
			continue;

		results.push_back(a_point);
	}
	return results;
}
//(c) generate the input sequence by picking 5 nodes from V uniformly 
// at random and always requesting one of the 5 nodes such that Greedy
//does not have a server present at the requested node at the time of the request; 
vector<int> avoiding_greedy(int n)
{
	vector<int> result;
	vector<int> init_conf;
	init_conf.push_back(0);
	init_conf.push_back(1);
	init_conf.push_back(2);
	init_conf.push_back(3);
		
	std::vector<int>::iterator it;
	
	for (int i =0;i<5;i++)
	{
		int num = rand()%n;

  		while( find (init_conf.begin(), init_conf.end(), num) != init_conf.end())
    			num = rand()%n;

		result.push_back(num);
	}

return result;
}

void print_seq(vector<int> seq){
	for(int i =0;i<seq.size();i++)
		cout<<seq[i]<<" ";
	cout<<endl;
}		
int main(){
	
	cout<<"enter number of nodes"<<endl;
	int n;
	cin >> n;
	
	cout<<"enter length of sequence for A and B - equal for now"<<endl;
	int len;
	cin>> len;
	
	vector<int> A = uniform(n, len);
	cout<<"uniform: ";
	print_seq(A);
	vector<int> B = markov(n, len);
	cout<<"markov: ";
	print_seq(B);
	vector<int> C = avoiding_greedy(n);
	cout<<"! Greedy: ";
	print_seq(C);

	return 0;
}
