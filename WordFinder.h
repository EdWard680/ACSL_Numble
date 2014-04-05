#ifndef _WORD_FINDER_H_
#define _WORD_FINDER_H_

#include "Numble.h"

//#define FINDER_DEBUG

class WordFinder
{
private:
	NumbleWord word, swaps;
	
private:
	const NumbleWord TestSwap(const long long &subWord, const long long &subSwap);
	
public:
	WordFinder(const NumbleWord& word, const NumbleWord& swaps);
	WordFinder(const NumbleWord& raw, const int n);
	
public:
	const NumbleWord Find();
};

#endif