#include "Numble.h"

int main(int argc, char **argv)
{
	for(int i = 1; 2*i < argc; i++)
	{
		cout<<getSizedWord(NumbleWord(argv[2*i-1]), atoi(argv[2*i]))<<endl;
	}
	
	return 0;
}