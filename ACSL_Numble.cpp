#include "WordFinder.h"
#include <sstream>

const string placeTiles(const NumbleWord &horiz, const NumbleWord &vert)
{
	stringstream ret;
	int vertOffSet = horiz.GetPivot() - horiz->begin();
	for(auto i = vert->begin(); i != vert->end(); i++)
	{
		if(i == vert.GetPivot())
		{
			ret<<horiz<<endl;
		}
		else
		{
			for(int s = 0; s < vertOffSet; s++)
				ret<<' ';
			ret<<*i<<endl;
		}
	}
	
	return ret.str();
}

int main(int argc, char **argv)
{
	NumbleWord rawHoriz, rawVert;
	if(argc == 3)
	{
		rawHoriz = string(argv[1]);
		rawVert  = string(argv[2]);
	}
	else
	{
		cin>>rawHoriz;
		cin>>rawVert;
	}
	
	char hBuf[15], vBuf[15], pBuf[15];
	while(!cin.eof())
	{
		cin.getline(hBuf, 15, ',').getline(vBuf, 15, ',').getline(pBuf, 15);
		if(cin.eof())
			break;
		rawHoriz.Pivot(atoi(pBuf));
		rawVert.Pivot(rawHoriz.Pivot());
		WordFinder horiz(rawHoriz, atoi(hBuf));
		WordFinder vert(rawVert, atoi(vBuf));
		cout<<placeTiles(horiz.Find(), vert.Find())<<endl;
	}
	
	return 0;
}