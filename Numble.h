#include <stdlib>
#include <vector>
#include <algorithm>

using namespace std;

class NumbleWord: private vector<int>
// represents a word in Numble, keeps sorted, maintains sum, maintains pivot
{
private:
	int pivot;
	mutable int sum;
	
public:
	NumbleWord(): pivot(0), sum(-1) {};
	NumbleWord(const int n): vector<int>(n), pivot(0), sum(-1) {};
	NumbleWord(const string& s, const int indexOfPivot);
	NumbleWord(const vector<int>& v, const int p): vector<int>(v), pivot(p) {};
	
public:
	const int sum() const;
	const int &pivot() const {return pivot;};
	void pivot(const int p) {pivot = p;};
	int * const getPivot();
	vector<int>* const operator-> ();  // monitors mutation of its inherited member
};

const NumbleWord makeWord(const NumbleWord& dict, const int n=-1);  // creates word of size n from dict