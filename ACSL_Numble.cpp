#include "Numble.h"

int main(int argc, char **argv)
{
	for(int i = 1; i < argc; i++)
	{
		cout<<NumbleWord(argv[i])<<endl;
	}
	
	return 0;
}