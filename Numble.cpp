#include "Numble.h"

NumbleWord::NumbleWord(const string &s, const int p): vector<int>(s.size())  // error checking left to callers
{
    for(auto c = s.begin(); c != s.end(); c++) // omg c++
    {
      if(*c >= '0' && *c <= '9')
          push_back(int(*c-'0'));
    }
    
    Pivot(p);
}

NumbleWord& NumbleWord::operator= (const NumbleWord& other)
{
	if(this == &other)
		return *this;
	
	**this = *other;
	Pivot(other.Pivot());
}

const int NumbleWord::Sum() const
{
    if(sum >= 0)
        return sum;
    else
        sum = 0;
        
    for(auto i = begin(); i != end(); i++)
        sum += *i;
    return sum;
}

void NumbleWord::sort() const
{
    sort(begin(),  end(), [](int a, int b) {return a > b;};
}

vector<int> &NumbleWord::operator* ()
{
    sum = -1;
    sort();
    return *this;
}

const vector<int>::iterator NumbleWord::GetPivot() const
{
    sort();
    return find(begin(), end(), pivot);
}

void NumbleWord::Pivot(const int p)
{
    pivot = p;
    if(GetPivot() == end())
    {
        push_back(pivot);
    }
}

const NumbleWord getSizedWord(const NumbleWord &dict, const int n)
{
    if (dict.Pivot() < 0 || n <= 0)
        return dict;
    
    NumbleWord ret(dict);
    while(ret.size() > dict.size()-n-(ret.GetPivot() == ret->end()? 1:0)
	{
        ret->pop_back();
	}
	
	if(ret.GetPivot() == ret->end()) // maintains the pivot if necessary
		ret.Pivot(ret.Pivot());
}

/*
const NumbleWord makeWord(const NumbleWord &dict, const int n)
{
    NumbleWord ret = getSizedWord(dict, n);
}
*/

ostream& operator<< (ostream& out, const NumbleWord& nw)
{
	for(auto i = nw->begin(); i != nw->end(); i++)
	{
		out<<*i;
	}
	return out;
}

istream& operator>> (istream& in, NumbleWord& nw)
{
	string tmp;
	in>>tmp;
	nw = tmp;
}