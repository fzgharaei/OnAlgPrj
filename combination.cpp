#include <iostream>
#include <vector>

using namespace std;

vector<int> people;
vector< vector<int> > combinations;
vector<int> combination;

void pretty_func(const vector<int>& v) {
  static int count = 0;
  cout << "combination no " << (++count) << ": [ ";
  for (int i = 0; i < v.size(); ++i) { cout << v[i] << " "; }
  cout << "] " << endl;
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

int main() {
  int n = 6, k = 4;

  //for (int i = 0; i < n; ++i) { people.push_back(i); }
	people.push_back(11);
	people.push_back(13);
	people.push_back(17);
	people.push_back(19);
	people.push_back(23);
	people.push_back(35);
	combination_calc(0, k);

  for(int i =0; i<=combinations.size(); i++){
	for(int j =0; j<combinations[i].size();j++)
		cout<<combinations[i][j]<<" ";
	cout<<endl;
	cout<<"test size"<<combinations[i].size()<<endl; 
	}
	cout<<"combinations size"<<combinations.size()<<endl;
return 0;
}
