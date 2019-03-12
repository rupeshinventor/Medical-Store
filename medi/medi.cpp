#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<string.h>
using namespace std;
class medicine
{
	public:
	int medino;
	char name[25];
	float price;
	int mquantity;
	medicine()                      
	{
	    medino=0;
		strcpy(name,"");
		price=0;
		mquantity=0;
	}
	void getdata()
	{	
	cout<<"\nEnter medicine number= ";
	cin>>medino;
	cout<<"\nEnter medicine name= ";
	fflush(stdin);
	gets(name);
	cout<<"\nEnter medicine price = ";
	cin>>price;
	cout<<"\nEnter quantity of medicine= ";
	cin>>mquantity;
	}
	int getmedino()
	{
		return medino;
	}
};
int main()
{
	system("color A1");
	medicine obj,obj1; 
	ifstream fin;
	ofstream fout;
	int n1,n2,n;
	char my='n';
	char flag='f',confirm;
	char f,usr[50],usrc[100]="rupesh";
	char pass[9],passc[9]="password";
	cout<<"\n\n\n\n\n\n\n\t\t\t\tEnter Username: ";
	fflush(stdin);
	gets(usr);
	cout<<"\n\t\t\t\tEnter password: ";
	for(int i=0;i<8;i++)
	{
		pass[i]=getch();
		cout<<"*";
	}
	if(strcmp(usr,usrc)==0 || strcmp(pass,passc)==0 )
	{
	do
	{
		cout<<"\n\n\t\n----------WELCOME TO MEDICINE RECORD MANAGEMENT SYSTEM ----------";
		cout<<"\t\n-----------------------By: Rupesh Mishra ------------------------";
		cout<<"\t\n---------------- Lovely Professional University -----------------";
		cout<<"\n\n\t\t\t1.Add Record";
		cout<<"\n\t\t\t2.Append Record";
		cout<<"\n\t\t\t3.Search Record";
		cout<<"\n\t\t\t4.Display Record";
		cout<<"\n\t\t\t5.Delete Record";
		cout<<"\n\t\t\t6.Exit";
		f = 'n';
		cout<<"\nEnter your choice:";
		cin>>n;
		switch(n)
		{
			case 1:
				{
				fout.open("medicine.dat",ios::out|ios::binary);
				obj.getdata();
				fout.write((char *)&obj,sizeof(obj));
				fout.close();
				}
				break;
			case 2:
				{
				fin.open("medicine.dat",ios::in|ios::binary);
				while(fin)
				{
					fin.read((char*)&obj1,sizeof(obj1));
				}
				fin.close();
				fout.open("medicine.dat",ios::app|ios::binary);
				obj.getdata();
				fout.write((char *)&obj,sizeof(obj));
				fout.close();
				break;
				}
			case 3:
				{	
				cout<<"Enter the medicine No: ";
				cin>>n1;
				fin.open("medicine.dat",ios::in|ios::binary);
				while(!fin.eof())
				{
					fin.read((char*)&obj1,sizeof(obj1));
					if(obj1.getmedino()==n1)
					{
						cout<<"\tMedicine NUMBER= "<<obj1.medino;
						cout<<"\n\tNAME OF Medicine= "<<obj1.name;
						cout<<"\n\tMedicine PRICE="<<obj1.price;
						cout<<"\n\tNo. of QUANTITY="<<obj1.mquantity;
						cout<<"\n\t\t*****SEARCH IS SUCCESSFUL*****";
						f='y';
						break;
					}
				}
				fin.close();
				if(f=='n')
					cout<<"\n!!!!!SEARCH IS NOT SUCCESSFUL!!!!!";
				break;
				}
			case 4:
				{
				fin.open("medicine.dat",ios::in|ios::binary);
				while(!fin.eof())
				{
					fin.read((char*)&obj1,sizeof(obj1));
					if(fin.eof())
					{
						break;
					}
						cout<<"\tMedicine NUMBER= "<<obj1.medino;
						cout<<"\n\tNAME OF Medicine= "<<obj1.name;
						cout<<"\n\tMedicine PRICE="<<obj1.price;
						cout<<"\n\tNo. of QUANTITY="<<obj1.mquantity;
				}
				fin.close();
				getch();
				break;
				}
			case 5:
				{	
				cout<<"Enter the medicine no: ";
				cin>>n2;
				fin.open("medicine.dat",ios::in|ios::binary);
				fout.open("temp.dat",ios::out|ios::binary);
				while(!fin.eof())
				{
					fin.read((char*)& obj1,sizeof(obj1));
					if(fin.eof())
					{
						break;
					}
					if(obj1.getmedino()==n2)
					{
							cout<<"\tMedicine NUMBER= "<<obj1.medino;
						cout<<"\n\tNAME OF Medicine= "<<obj1.name;
						cout<<"\n\tMedicine PRICE="<<obj1.price;
						cout<<"\n\tNo. of QUANTITY="<<obj1.mquantity;
						flag='t';
						cout<<"\n\nConfirm that(y/n):";
						cin>>confirm;
						if(confirm=='n')
						    {
							   fout.write((char *)&obj1,sizeof(obj1));
								cout<<"\nRecord not deleted";
								break;
							}
							   cout<<"\nRecord deleted";
							   getch();
					}
					else
						fout.write((char *)&obj1,sizeof(obj1));
				}
				if(flag=='f')
					cout<<"Record not found";
				fin.close();
				fout.close();
				remove("medicine.dat");
				rename("temp.dat","medicine.dat");
				break;
				}
			case 6: 
			
				   cout<<"THANK YOU!";
				   exit(0);
				   break;
			default:
				cout<<"WRONG CHOICE";
				break;
			     }
	}while(n!=6);	
}
else
cout<<"\nWrong username or password.";
return 0;
}
