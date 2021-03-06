#include "Numble.h"

NumbleWord::NumbleWord(const string &s, const int p)  // error checking left to callers
{
    reserve(s.size());
    bool zero = false;
    for(auto c = s.begin(); c != s.end(); c++) // omg c++
    {
        if(*c >= '0' && *c <= '9')
        {
            if(*c == '0')
            {
                if(!zero)
                    zero = true;
                else
                    continue;
            }
            push_back(int(*c-'0'));
			sum += back();
        }
    }
    
    if(p < 0 && size() > 0)
        Pivot(at(0));
    else
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

void NumbleWord::sort() //const
{
    using std::sort;
    sort(begin(), end(), [](int a, int b) {return bool(a > b);});
}

vector<int> &NumbleWord::operator* ()
{
    sum = -1;
    sort();
    return *this;
}

vector<int>::const_iterator NumbleWord::GetPivot()
{
    sort();
    return find(begin(), end(), pivot);
}

void NumbleWord::Pivot(const int p)
{
    if((pivot = p) < 0)
        return;
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
    while(ret->size() > n-(ret.GetPivot() == ret->end() && ret.Pivot() >= 0))
    {
        ret->pop_back();
    }
    
    if(ret.GetPivot() == ret->end()) // maintains the pivot if necessary
        ret.Pivot(ret.Pivot());
        
    return ret;
}

ostream& operator<< (ostream& out, const NumbleWord& nw)
{
    for(auto i = nw->cbegin(); i != nw->cend(); i++)
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