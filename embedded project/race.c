#include "race.h"
//#include "Nokia5110.h"




void Enemies(int h, int v1,int v2, int r1, int r2){

	Nokia5110_ClearBuffer();
	
	if (r1 & (1<<0))
		Nokia5110_PrintBMP(49,v1, cars, 0);
	if (r1 & (1<<1))
		Nokia5110_PrintBMP(33,v1, cars, 0);
	if (r1 & (1<<2))
		Nokia5110_PrintBMP(17,v1, cars, 0);
	if (r1 & (1<<3))
		Nokia5110_PrintBMP(1,v1, cars, 0);
	
	
	if (r2 & (1<<0))
		Nokia5110_PrintBMP(49,v2, cars, 0);
	if (r2 & (1<<1))
		Nokia5110_PrintBMP(33,v2, cars, 0);
	if (r2 & (1<<2))
		Nokia5110_PrintBMP(17,v2, cars, 0);
	if (r2 & (1<<3))
		Nokia5110_PrintBMP(1 ,v2, cars, 0);
	


	
		Nokia5110_PrintBMP(h, 47, car, 0); // player ship middle bottom
		
		Nokia5110_PrintBMP(0, 20, border, 0); // player ship middle bottom
		Nokia5110_PrintBMP(0,40 , border, 0); // player ship middle bottom
			
		Nokia5110_PrintBMP(64, 20, border, 0); // player ship middle bottom
		Nokia5110_PrintBMP(64,40 , border, 0); // player ship middle bottom
		Nokia5110_DisplayBuffer();     // draw buffer
		

}

 
/*end of file*/

