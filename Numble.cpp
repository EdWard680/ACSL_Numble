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
        }
        sum += back();
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

const NumbleWord bruteForce(const NumbleWord &word, const NumbleWord &dict)  // quick code, long run time, aka fallback
{
    NumbleWord swaps;
    for(auto i = dict->cbegin()+(word->cend()-word->cbegin()); i != dict->cend(); i++)
    {
        swaps.push_back(*i);
    }
    
    int max = 0;
    const int best = (word.Sum()/5)*5;
    for(auto i = word.back(); i != word.begin(); i--)
    {
        for(auto j = word.begin(); j != word.end(); j++)
    }
    
}


const NumbleWord makeWord(const NumbleWord &dict, const int n)
{
    NumbleWord ret = getSizedWord(dict, n);
    if(ret.Sum() % 5 == 0)
    {
        return ret;
    }
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