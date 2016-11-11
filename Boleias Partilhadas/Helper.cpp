#include "Helper.h"




bool readYesOrNo(unsigned char yes, unsigned char no)
{
	char c;

	do
	{
		c = _getch();
	} while (c != yes && c != no);
	return c == yes;
}