#include "Numble.h"

NumbleWord::NumbleWord(const string &s, const int indexOfPivot): vector<int>(s.size())  // error checking left to callers
{
    for(auto c = s.begin(); c != s.end(); c++) // omg c++
    {
      if(*c >= '0' && *c <= '9')
          push_back(int(*c-'0'));
    }
    
    pivot = (*this)[indexOfPivot];
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
    return &*find(begin(), end(), pivot);
}

const NumbleWord makeWord(const NumbleWord &dict, const int n)
{
    if (dict.GetPivot() < 0 || n <= 0)
        return dict;
    
    
}