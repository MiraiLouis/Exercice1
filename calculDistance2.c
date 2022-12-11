#include "main.h"

int calculDistance2(int x1, int x2, int x3, int x4, int x5, int x6, int x7, int x8, int y1, int y2, int y3, int y4, int y5, int y6, int y7, int y8){
	if (x1==0)
	{
		y1=0;
	}
	if (x2==0)
	{
		y2=0;
	}
	if (x3==0)
	{
		y3=0;
	}
	if (x4==0)
	{
		y4=0;
	}
	if (x5==0)
	{
		y5=0;
	}
	if (x6==0)
	{
		y6=0;
	}
	if (x7==0)
	{
		y7=0;
	}
	if (x8==0)
	{
		y8=0;
	}
	return sqrt(pow((x1-y1),2)+pow((x2-y2),2)+pow((x3-y3),2)+pow((x4-y4),2)+pow((x5-y5),2)+pow((x6-y6),2)+pow((x7-y7),2)+pow((x8-y8),2));
}

