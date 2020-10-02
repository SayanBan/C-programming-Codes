#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>


int n=0;
int *pixels=NULL; 
void Export2Pixels(int *pixels, int n)
{
  FILE *fp = fopen("Pixels_mpcircle.txt", "w");
  fprintf(fp,"centre= %d ,%d\n",pixels[0], pixels[1]);
  fprintf(fp,"radius= %d\n\n",pixels[3]-pixels[2]);
  fprintf(fp, " x,  y\n");
  
  for(int i=0; i<n; i++)
  {
   fprintf(fp, "%d, %d\n", pixels[2*i+0], pixels[2*i+1]);
  }

  fclose(fp);
  printf("Pixel coordinates exported to Pixels.txt successfully!\n");
}


void ExportSVG(int *pixels, int n, int width, int height)
{
    int scale = 10;
    int margin = 100;
    int i;
    int x1 = pixels[0], x2 = pixels[0];
    int y1 = pixels[1], y2 = pixels[1];
    for(i=1; i<n; i++){
        if(x1>pixels[2*i+0]) x1=pixels[2*i+0]; 
        if(x2<pixels[2*i+0]) x2=pixels[2*i+0];
        if(y1>pixels[2*i+1]) y1=pixels[2*i+1]; 
        if(y2<pixels[2*i+1]) y2=pixels[2*i+1];
    }
    x1 *=scale; x2 *=scale;
    y1 *=scale; y2 *=scale;
  
  FILE *fp = fopen("Circle.svg", "w");

  fprintf(fp, "<svg width=\"%d\" height=\"%d\" viewBox=\"0 0 %d %d\" fill=\"none\" xmlns=\"http://www.w3.org/2000/svg\"  version=\"1.1\">",
               width,height,width,height);
    for(i=0; i<n; i++)
    {
        fprintf(fp,"\n<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill:blue;stroke:red;stroke-width:.30;fill-opacity:0.76;stroke-opacity:0.90\"/>", scale*pixels[2*i+0]-x1+100, scale*pixels[2*i+1]-y1+100, scale, scale);
    }
    
  fprintf(fp, "\n </svg>\n");
  fclose(fp);
  printf("SVG created successfully!\n");
}

void ExportHTML(int *pixels, int n, int width, int height)
{
  int scale = 10;
    int margin = 100;
    int i;
    int x1 = pixels[0], x2 = pixels[0];
    int y1 = pixels[1], y2 = pixels[1];
    for(i=1; i<n; i++){
        if(x1>pixels[2*i+0]) x1=pixels[2*i+0]; 
        if(x2<pixels[2*i+0]) x2=pixels[2*i+0];
        if(y1>pixels[2*i+1]) y1=pixels[2*i+1]; 
        if(y2<pixels[2*i+1]) y2=pixels[2*i+1];
    }
    x1 *=scale; x2 *=scale;
    y1 *=scale; y2 *=scale;
  
  FILE *fp = fopen("Circle.html", "w");
  fprintf(fp, "<!DOCTYPE html>\n<html>\n<body>\n");   
  
  
  fprintf(fp, "<svg width=\"%d\" height=\"%d\" viewBox=\"0 0 %d %d\" fill=\"none\" xmlns=\"http://www.w3.org/2000/svg\"  version=\"1.1\">",
               width,height,width,height);
    for(i=0; i<n; i++)
    {
        fprintf(fp,"\n<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill:blue;stroke:red;stroke-width:.30;fill-opacity:0.76;stroke-opacity:0.90\"/>", scale*pixels[2*i+0]-x1+100, scale*pixels[2*i+1]-y1+100, scale, scale);
    }

    fprintf(fp, "\n </svg>\n");
    fprintf(fp, "\n</body>\n</html>\n");
    fclose(fp);
  
  printf("HTML created successfully!\n");
}

int *midPointCircleDraw(int x_c, int y_c, int r,int *n)
{
 int x,y,p;
 x=0;y=r;
 p=1.25-r;
  int *pixels = (int*)malloc(8*(x_c+1)*sizeof(int));
    int m=0;

    pixels[2*m+0]=x_c;
   pixels[2*m+1]=y_c;
  m++;
   pixels[2*m+0]=x+x_c;
   pixels[2*m+1]=y+y_c;
  m++;
   pixels[2*m+0]=x+x_c;
   pixels[2*m+1]=-y+y_c;
  m++;
  pixels[2*m+0]=y+x_c;
   pixels[2*m+1]=x+y_c;
  m++;
  pixels[2*m+0]=-y+x_c;
  pixels[2*m+1]=x+y_c;
   m++;
 while(x<y)
 {
  if(p<0) 
   p=p+2*x+1;
  else
  {
   p=p+2*x-2*y+1;
   y=y-1;
  }
  x=x+1;

  pixels[2*m+0]=x+x_c;
  pixels[2*m+1]=y+y_c;
  m++;
  pixels[2*m+0]=x+x_c;
  pixels[2*m+1]=-y+y_c;
  m++;
  pixels[2*m+0]=-x+x_c;
  pixels[2*m+1]=y+y_c;
  m++;
  pixels[2*m+0]=-x+x_c;
  pixels[2*m+1]=-y+y_c;
  m++;
  pixels[2*m+0]=y+x_c;
  pixels[2*m+1]=x+y_c;
  m++;
  pixels[2*m+0]=y+x_c;
  pixels[2*m+1]=-x+y_c;
  m++;
  pixels[2*m+0]=-y+x_c;
  pixels[2*m+1]=x+y_c;
  m++;
  pixels[2*m+0]=-y+x_c;
  pixels[2*m+1]=-x+y_c;
  m++;
 }
 *n=m;
 printf("\nNumber of pixels = %d\n", *n);
 return pixels;
}
void display()
{
    for(int i=0;i<n;i++)
    {
        putpixel(pixels[2*i+0],pixels[2*i+1],7);
    }
    printf("Waiting for you to close the display-window...\n");
}

int main()
{
    int gd=DETECT,gm,r,x_c,y_c;
    printf("\nEnter the co-ordinate of Centre of Circle::");
    scanf("%d%d",&x_c,&y_c);
    printf("\nEnter the radius of the circle::");
    scanf("%d",&r);
    initgraph(&gd,&gm,NULL);
    // To draw a circle of radius r centred at (x_c, y_c) with radius r
    pixels=midPointCircleDraw(x_c,y_c,r,&n);
    int width=5000;
    int height=5000;
    ExportSVG(pixels, n, width, height);
    ExportHTML(pixels, n, width, height);
    Export2Pixels(pixels, n);

    display();
     while (!kbhit( ))
    {
        delay(200);
    }
    return 0;
}



