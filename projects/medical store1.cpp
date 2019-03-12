
#include<iostream>
using namespace std;
#include<conio.h>
const int m=20;
class medical
{
	//==============class object.....============
	int amount[m],pris[m],k,a,b,amount1;
	int code,code1,cod[m],s,last;
	public:
		float price,price1;
		medical(void);
		void sell_medicine(void);
		void total_medicine(void);
		void add_old_medicine(void);
		void add_new_medicine(void);
		void show(void);
};
medical::medical(void)
{
	s=0;a=10;b=40;last=5;amount[0]=0;
	for(int k=0;k<last;k++)
	{
		s=s+1;
		b=b+10;
		cod[k]=s;
		amount[k]=a;
		pris[k]=b;
	}
}
void medical::add_old_medicine(void)
{
	cout<<"enter medicine:";
	cin>>code1;
	cout<<"enter price:";
	cin>>price1;
	for(k=0;k<last;k++)
	{
		if(code1==cod[k])
		{
			a=a+1;
			amount[k]=a;
			pris[k]=price1;
		}
		else
		cout<<"sorry this medicine is not available.\n";
	}
}
void medical::add_new_medicine(void)
{
	cout<<"enter medicine code:";
	cin>>code1;
	cout<<"enter amount of that medicine:";
	cin>>amount1;
	cout<<"enter medicine price:";
	cin>>price1;
	cod[last]=code1;
	amount[last]=amount1;
	pris[last]=price1;
	last++;
	
}
void medical::show(void)
{
	for(k=0;k<last;k++)
	{
		cout<<"\nCODE"<<cod[k]<<"\t";
		cout<<"\nAMOUNT"<<amount[k]<<"\t";
		cout<<"\nPRICE"<<pris[k]<<"\t";
		
	}
	
}
void medical::sell_medicine(void)
{
	cout<<"enter product code:\n";
	cin>>code;
	cout<<"enter product price:\n";
	cin>>price;
	
}
void medical::total_medicine(void)
{
	cout<<"\n\nITEM CODE:"<<code<<"\n\nITEM PRICE:"<<price;
	
}
int main()
{
	medical med[10];
	static int j=0;
	int x,i=0,p,s=0;
	do{
		//==============file handling.....===================
			cout<<"\nWELCOME TO  MEDICAL STORE MANAGEMENT SYSTEM\n\n\n\n"; 
		cout<<"\nENTER YOUR CHOICE:\n";
		cout<<"\n1.show all medicine:";
		cout<<"\n2.add old medicine:";
		cout<<"\n3.add new medicine:";
		cout<<"\n4.sell an medicine:";
		cout<<"\n5.total sold meicine:";
		cout<<"\n6.show total medicine sold:";
		cout<<"\n7.QUIT:";
		cout<<"\n\t\t";
		cin>>x;
		
		switch(x)
		{
			//==============switch case...==============
			case 1: med[i].show();
			break;
			case 2: med[i].add_old_medicine();
			med[i].show();
			break;
			case 3: med[i].add_new_medicine();
			med[i].show();
			break;
			case 4: med[i].sell_medicine();
			i++;j++;
			break;
			case 5: 
			{
				cout<<"TOTAL SSOLD MEDICINE:";
				s=0;
				for(p=0;p<j;p++)
				{
					s=s+med[p].price;
				}
				cout<<"s";
			
			
			}
			break;
			case 6:
				for(i=0;i<j;i++)
				{
					med[i].total_medicine();
				}
				break;
				case 7:
						cout<<"THANK YOU!";
				   exit(0);
			default:
				system("cls");
				cout<<"WRONG CHOICE";
					break;
			
			
		}
	}
	while(x!=7);
	getch();
	return 0;
}
