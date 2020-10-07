#include<stdio.h>
int main()
{
	int n,i,j;
	float sum=0,x[10],y[10][10],u,h,xp,p,q;
	printf("\n enter the number of elements: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("\n Enter the value of x[%d] and y[%d][0]: ",i,i);
	scanf("%f%f",&x[i],&y[i][0]);
	}
	printf("\n Enter the value of x at which f(x) is required: ");
	scanf("%f",&xp);
	for(j=1;j<n;j++)
	{
		for(i=0;i<=(n-j);i++)
		{
			y[i][j]=y[i+1][j-1]-y[i][j-1];
		}
	}
	printf("Difference Table\n");
	printf("x\t y\t dy\t d2y\t d3y\t \n");
	for(i=0;i<n;i++)
	{
		printf("%0.2f",x[i]);
		for(j=0;j<n-i;j++)
 		{
 			printf("\t%0.2f",y[i][j]);
 		}
  		printf("\n");
 	}
	h=x[1]-x[0];
	u=(xp-x[0])/h;
	sum=y[0][0];
	p=1;
	q=1;
	for(j=1;j<n;j++)
	{
		p = p*j;
		q = q*(u+1-j);
		sum = sum+(q*y[0][j]/p); 
	}
	printf("\n The value of f(%0.2f)= %0.2f",xp,sum);
}

