#include<iostream>
using namespace std;
int i,j,n;
	int c=0;
int digit[10000];
 extractdigit(int n)
{
	int save=n;

	while(save!=0)//to determine how many digit does the input have
	{
		save=save/10;
		c++;
	}
	
	
	i=c-1;
	while(n!=0)
	{
	
		digit[i]=n%10;
		n=n/10;
		i--;
	}
	
}
int main()
{
	int i,j,n;
	char repeat;

string ar[9]={"***  ","  *  ","*****","    *","*    ","  ** "," * * ","   * ","*   *"};
int zero[5]={2,8,8,8,2};
int one[5]={0,1,1,1,2};
int two[5]={2,3,2,4,2};
int three[5]={2,3,2,3,2};
int four[5]={7,5,6,2,7};
int five[5]={2,4,2,3,2};
int six[5]={2,4,2,8,2};
int seven[5]={2,3,3,3,3};
int eight[5]={2,8,2,8,2};
int nine[5]={2,8,2,3,3};
while(repeat!='n'||repeat!='N')
{//coded by "ASWIN CP".

cout<<"ENTER ANY NUMBER";
cin>>n;
extractdigit(n);

for(i=0;i<5;i++)
{
	for(j=0;j<c;j++)
	{
        
		switch(digit[j])
		{
			case 0:
			{
			cout<<ar[zero[i]];
			break;
		   }
		   	case 1:
			{
			cout<<ar[one[i]];
			break;
		   }	case 2:
			{
			cout<<ar[two[i]];
			break;
		   }	case 3:
			{
			cout<<ar[three[i]];
			break;
		   }	case 4:
			{
			cout<<ar[four[i]];
			break;
		   }	case 5:
			{
			cout<<ar[five[i]];
			break;
		   }
		   	case 6:
			{
			cout<<ar[six[i]];
			break;
		   }	case 7:
			{
			cout<<ar[seven[i]];
			break;
		   }	case 8:
			{
			cout<<ar[eight[i]];
			break;
		   }	case 9:
			{
			cout<<ar[nine[i]];
			break;
		   }
		   
		}
		cout<<"  ";
		
	}
	cout<<"\n";
}
cout<<"DO YOU WANT TO CONTINUE,IF YES PRESS Y ,PRESS N TO EXIT";
cin>>repeat;

}
return 0;//Aswin Cp
}
