#include "Numble.h"

NumbleWord::NumbleWord(const string &s, const int indexOfPivot): vector<int>(s.size())  // error checking left to callers
{
    for(auto c = s.begin(); c != s.end(); c++) // omg c++
        push_back(*c);
    
    pivot = &(*this)[indexOfPivot];
}

const int NumbleWord::sum()
{
    if(sum >= 0)
        return sum;
    else
        sum = 0;
        
    for(auto i = begin(); i != end(); i++)
        sum += *i;
    return sum;
}

vector<int> * const NumbleWord::operator-> ()
{
    sum = -1;
    sort(begin(), end());
    return this;
}

int * const NumbleWord::getPivot()
{
    return find(begin(), end(), pivot);
}

const NumbleWord makeWord(const NumbleWord &dict, const int n)
{
    NumbleWord ret;
}