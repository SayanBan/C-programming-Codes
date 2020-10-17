#include<iostream>
#include<conio.h>
#include<graphics.h>
void flood(int x, int y, int new_col, int old_col) 
{ 
    if (getpixel(x, y) == old_col)
	{ 
        putpixel(x, y, new_col); 
        	
        flood(x + 1, y, new_col, old_col); 
        
       
        flood(x - 1, y, new_col, old_col); 
        
       
        flood(x, y + 1, new_col, old_col); 
        
        
        flood(x, y - 1, new_col, old_col); 
    } 
}
int main()
{
	int gd=DETECT,gm,i,p=0;
	initgraph(&gd,&gm,NULL);
	i=0;
	
	//Frame
	line(0,0,0,500);
	line(639,0,639,500);
	line(0,0,639,0);
	line(0,500,639,500);
	
	
		//Car Body
		line(50,370,95,370);
		arc(110,370,0,180,20);
		line(125,370,225,370);
		arc(240,370,0,180,20);
		line(255,370,300,370);
		line(300,370,300,350);
		line(300,350,240,330);
		line(240,330,200,300);
		line(110,300,202,300);
		line(110,300,80,330);
		line(80,330,50,340);
		line(50,340,50,370);
	
		
		//Window
		line(165+i,305,165+i,330);
		line(165+i,330,230+i,330);
		line(230+i,330,195+i,305);
		line(195+i,305,165+i,305);
		flood(166,306,15,0);
		
		line(160+i,305,160+i,330);
		line(160+i,330,95+i,330);
		line(95+i,330,120+i,305);
		line(120+i,305,160+i,305);	
		
		//Wheel
		circle(110+i,370,17);
		circle(240+i,370,17);
		
		//Road
		line(0,420,639,420);
		line(0,330,80,330);
		line(240,330,639,330);
		
		
		rectangle(0,360,40,370);
		rectangle(350,360,400,370);
		rectangle(450,360,500,370);
		rectangle(550,360,600,370);		
		
		//land boundary
		line(0,200,370,200);
		line(580,200,639,200);
		
		//Mountain
		line(0,200,200,100);
		line(200,100,370,200);
		
		line(285,150,480,100);
		line(480,100,639,200);
		
		//Sun
		circle(250,50,25);
		
		//River
		setcolor(1);
		line(0,215,200,215);
		arc(200,246,0,90,30);
		
		arc(200,246,270,360,30);
		line(150,276,200,276);
		
		arc(150,276,270,360,20);
		line(0,295,150,295);
		
		//Cloud
		setcolor(15);
		arc(639,60,90,180,50);
		arc(600,85,90,180,30);
		arc(610,85,180,270,40);
		line(605,124,639,124);	
		
		//House
		line(350,230,400,150);
		line(400,150,450,230);
		line(400,150,550,150);
		line(550,150,600,230);
		line(450,230,600,230);
		line(352,228,352,320);
		rectangle(450,230,600,320);
		line(352,320,450,320);
		
		rectangle(500,250,550,320);
		
		circle(400,200,15);
		rectangle(370,250,420,290);
		line(395,250,395,290);
		
		
		
		//Car Colouring
		flood(111,301,4,0);
		flood(121,306,15,0);
		flood(1,361,15,0);
		flood(351,361,15,0);
		flood(451,361,15,0);
		flood(551,361,15,0);
		
		//Road Colouring
		flood(1,331,8,0);
		
		//Mountain Colouring
		flood(150,150,6,0);		
		flood(350,150,6,0);
		
		//Sun Colouring
		flood(251,51,14,0);
			
		//Sky Colouring
		flood(1,1,11,0);
		
		//River Colouring
		flood(1,216,1,0);
		
		//Cloud Colouring
		flood(601,61,15,0);
		
		//Land Colouring
		flood(1,421,10,0);
		flood(1,201,10,0);
		
		//House Colour
		flood(410,151,4,0);
		flood(410,231,12,0);
		flood(451,231,12,0);
		flood(401,201,14,0);
		flood(371,251,6,0);
		flood(396,251,6,0);
		flood(501,251,6,0);
		
		
		//Bird
		setcolor(0);
		arc(400,50,0,90,10);
		arc(420,50,90,180,10);
		
		arc(440,50,0,90,10);
		arc(460,50,90,180,10);
		
		arc(430,70,0,90,10);
		arc(450,70,90,180,10);
		
		
	getch();
	return 0;
}
