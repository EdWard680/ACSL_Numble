#ifndef _NUMBLE_H_
#define _NUMBLE_H_

//#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>

//#define DEBUG_NUMBLE

using namespace std;

class NumbleWord: private vector<int>
// represents a word in Numble, keeps sorted, maintains sum, maintains pivot
{
private:
    int pivot;
    mutable int sum;
    
private:
    void sort();// const;
    
public:
    NumbleWord(): pivot(-1), sum(-1) {};
    //NumbleWord(const int n): vector<int>(n), pivot(-1), sum(-1) {};
    NumbleWord(const string& s, const int p=-1);
    NumbleWord(const vector<int>& v, const int p=-1): vector<int>(v), pivot(p), sum(-1) {};
    NumbleWord(const NumbleWord& other): NumbleWord(*other, other.Pivot()) {};
	NumbleWord& operator= (const NumbleWord& other);
    
public:
    const int Sum() const;
	const int Sum() {**this; return const_cast<const NumbleWord *>(this)->Sum();};
    const int &Pivot() const {return pivot;};
    void Pivot(const int p);// {pivot = p;};
    vector<int>::const_iterator GetPivot();
	vector<int>::const_iterator GetPivot() const {return find(cbegin(), cend(), pivot);};
    vector<int>* const operator-> () {return &operator*();};
	const vector<int> * const operator-> () const {return this;};
    vector<int> &operator* ();  // monitors mutation of its inherited member
	const vector<int> &operator* () const {return *this;};
};

const NumbleWord getSizedWord(const NumbleWord &dict, const int n); // creates a new valid word from dict of size n
const NumbleWord makeWord(const NumbleWord& dict, const int n=-1);  // creates word of size n from dict

ostream& operator<< (ostream& out, const NumbleWord& nw);
istream& operator>> (istream& in, NumbleWord& nw);

#endif