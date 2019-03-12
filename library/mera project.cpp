#include<bits/stdc++.h>
using namespace std;
class sample{
public:
int age;
double feet;
double inches;
double height;
double weight;
		void male();
		void female();
 	//	double calculate_bmi(double weight ,double height);
       //// void showbmi()	{  cout<<"BMI: "<<calculate_bmi(weight,height)<<endl;  }

};
void sample::female()
{
	cout<<"Enter your Age:";
	cin>>age;
	cout<<"Enter weight"<<endl;
    cout<<"Pounds(1kg=2.2lbs):"<<endl;
    cin>>weight;
    cout<<"Enter height"<<endl;
    cout<<"Feet:"<<endl;
    cin>>feet;
    cout<<"Inches:"<<endl;
    cin>>inches;
    height = (feet * 12) + inches;
  
}
void sample::male()
{
	cout<<"Enter your Age:";
	cin>>age;
	cout<<"Enter weight"<<endl;
    cout<<"Pounds:"<<endl;
    cin>>weight;
    cout<<"Enter height"<<endl;
    cout<<"Feet:"<<endl;
    cin>>feet;
    cout<<"Inches:"<<endl;
    cin>>inches;
	height = (feet * 12) + inches;
//	void showdata()
}


/////////   BMI /////////////


class BMI:public sample
{
	double bmi;
	public:
		void calbmi()
		{
			bmi=(weight*703)/(height*height);
			cout<<"BMI="<<bmi<<"  ";
			if(bmi<18.5){cout<<"(Underweight)";}
			else if(bmi>=18.5 && bmi<=24.9){cout<<"(Healthy weight";}
			else if(bmi>=25 && bmi<=29.9){cout<<"(\Overweight";}
			else {cout<<"Obese";}
		}
		
};
class BMR:public sample
{   public:
	double bmr;
		void calbmr()
		{
			bmr = 655 + (4.35 * weight) + (4.7 * height) - (4.7 * age);
			cout<<"BMR:"<<bmr;
		}
};
class AMR: public BMR
{  public:
	double amr;
		void calamr()
		{
			cout << "\n\n";
cout << "Please select your activity level; " << endl;
cout << "-----------------------------------" << endl;
cout << "1. Little to no exercise " << endl;
cout << "2. Light exercise (1-3 days per week) " << endl;
cout << "3. Moderate exercise ( 3-5 days per week) " << endl;
cout << "4. Heavy exercise ( 6-7 days per week ) " << endl;
cout << "5. Very heavy exercise (twice per day, extra heavy workouts) " << endl;
cout << "\n\n" << "Please enter the number to the left of your activity" ;
int selection;
cin>>selection;
calbmr();
if (selection == 1)
{
           int amr = bmr * 1.2;
           cout << "\n\n";
           cout << "Your BMR is: " << bmr << endl;
           cout << "Your AMR is: " << amr << endl;
}

if (selection == 2)
{
           int amr = bmr * 1.375;
           cout << "\n\n";
           cout << "Your BMR is: " << bmr << endl;
           cout << "Your AMR is: " << amr << endl;
}

if (selection == 3)
{
           int amr = bmr * 1.55;
           cout << "\n\n";
           cout << "Your BMR is: " << bmr << endl;
           cout << "Your AMR is: " << amr << endl;
}

if (selection == 4)
{
           int amr = bmr * 1.475;
           cout << "\n\n";
           cout << "Your BMR is: " << bmr << endl;
           cout << "Your AMR is: " << amr << endl;
}

if (selection == 5)
{
           int amr = bmr * 1.9;
           cout << "\n\n";
           cout << "Your BMR is: " << bmr << endl;
           cout << "Your AMR is: " << amr << endl;
}


		}
};
int main()
{   BMI o1;
    BMR o2;
    AMR o3;
	int gender;
	cout << "\n\n" << "Let's get started." << endl;
    cout << "\n\n" << "What is your gender? (1 for female, and 2 for male): ";
    cin >> gender;
    
    while (gender <=0 || gender >= 3)
	{ 
	cout << "\n\n" << "I'm sorry, you entered something other than 1 or 2." << endl;
    cout << "\n\n" << "Please indicate if you are male or female." << endl;
    cout << "by entering 1 for female or 2 for male: ";
    cin >> gender;
    }
    if(gender==1){ o1.female();}
	else{ o1.male(); }
	A:
	cout<<"\nEnter you choice:\n\n\n";
	cout<<"1. BMI"<<endl;
	cout<<"2. BMR"<<endl;
	cout<<"3. AMR"<<endl;
	cout<<"4. CBL"<<endl;
	int n;
	cin>>n;
	switch(n)
	{
		case 1:o1.calbmi();
		break;
	
		case 2:o2.calbmr();
		break;
		
		case 3:o3.calamr();
		break;
		
		default :cout<<"You have entered a wrong option";
		goto A;
	
	}
	
	
}
