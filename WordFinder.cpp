#include "WordFinder.h"

WordFinder::WordFinder(const NumbleWord& word, const NumbleWord &swaps): word(word), swaps(swaps) {};

WordFinder::WordFinder(const NumbleWord& raw, const int n): word(getSizedWord(raw, n))
{
	for(auto i = raw->cbegin()+(word->cend()-word->cbegin()); i != raw->cend(); i++)
		swaps->push_back(*i);
		
#ifdef FINDER_DEBUG
	cout<<"raw: "<<raw<<endl<<"word: "<<word<<endl<<"swaps: "<<swaps<<endl;
#endif
}

const NumbleWord WordFinder::TestSwap(const long long &subWord, const long long &subSwap)
{
#ifdef FINDER_DEBUG
	cout<<word<<": TestSwap("<<subWord<<", "<<subSwap<<")"<<endl;
#endif
	if(1<<(word->end() - word.GetPivot()) & subWord)
		return word;
	
	if(!subSwap || !subWord)
		return word;
	
	int w = 0;
	for(; w < word->size() && !(1<<w & subWord); w++);

	int s = 0;
	for(; s < swaps->size() && !(1<<s & subSwap); s++);
	
	swap(word->at(w), swaps->at(s));
	const NumbleWord ret(TestSwap(subWord ^ 1<<w, subSwap ^ 1<<s));
	swap(word->at(w), swaps->at(s));
	return ret;
}

const NumbleWord WordFinder::Find()
{
	int max = 0;
	NumbleWord best(word);
	for(int w = 0; w < 1<<word->size(); w++) // subset iteration
	{
		for(int s = 0; s < 1<<swaps->size(); s++)  // is actually quite interesting
		{
			const NumbleWord tmp(TestSwap(w, s));
#ifdef FINDER_DEBUG
			cout<<tmp<<" with sum "<<tmp.Sum()<<endl;
#endif
			if(tmp.Sum() % 5 == 0 && tmp.Sum() > max)
			{
				max = tmp.Sum();
				best = tmp;
			}
		}
	}
	if(max == 0)
		best->clear();
	return best;
}