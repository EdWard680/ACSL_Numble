#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class NumbleWord: private vector<int>
// represents a word in Numble, keeps sorted, maintains sum, maintains pivot
{
private:
    int pivot;
    mutable int sum;
    
private:
    void sort() const;
    
public:
    NumbleWord(): pivot(-1), sum(-1) {};
    NumbleWord(const int n): vector<int>(n), pivot(-1), sum(-1) {};
    NumbleWord(const string& s, const int indexOfPivot);
    NumbleWord(const vector<int>& v, const int p): vector<int>(v), pivot(p) {};
    NumbleWord(const NumbleWord& other): NumbleWord(*other, other.Pivot()) {};
    
public:
    const int Sum() const;
    const int &Pivot() const {return pivot;};
    void Pivot(const int p) {pivot = p;};
    const int * const GetPivot() const;
    vector<int>* const operator-> () {return &operator*();};
    vector<int> &operator* ();  // monitors mutation of its inherited member
};

const NumbleWord makeWord(const NumbleWord& dict, const int n=-1);  // creates word of size n from dict