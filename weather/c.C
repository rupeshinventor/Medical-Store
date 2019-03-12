#include<stdio.h>
#include <process.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define n 900   //Program can take upto 200 records if the user wants
//============================================================================================
//structure to store details
struct student
{
 char name[50];
 int temp[20][20],rain[20][20],snow[20][20];
 char str[20];
}stud;
//=============================================================================================
//    FUNCTION TO INSERT RECORDS TO THE FILE
void insert()
{
	int i,j;
 printf("\n\t****************************** Welcome to add records **********************************");
 FILE *fp;
 fp = fopen("rupa.txt", "a+");
 char month[20][20]={{"January"},{"February"},{"March"},{"April"},{"May"},{"June"},{"July"},{"August"},{"September"},{"October"},{"November"},{"December"}};
 printf("\n\tEnter the City name : ");
 fflush(stdin);					//to clear out standard inputs
 gets(stud.name);
 for(j=0;j<3;j++)
 {
 	printf("\n\t\t\tFor year %d\n",j+1);
 for(i=0;i<12;i++)
 {
 printf("\tEnter temperature in celsius of %s: ",month[i]);
 scanf("%d", &stud.temp[j][i]);
}}
printf("\n");
 for(j=0;j<3;j++)
 {
 printf("\n\t\t\tFor year %d\n",j+1);
	for(i=0;i<12;i++)
 {
 printf("\tEnter amount of rainfall in %s: ",month[i]);
 scanf("%d", &stud.rain[j][i]);
}}
printf("\n");
for(j=0;j<3;j++)
{
 	printf("\n\t\t\tFor year %d\n",j+1);
	 for(i=0;i<12;i++)
 {
 printf("\tEnter amount of snowfall in %s: ",month[i]);
 scanf("%d", &stud.snow[j][i]);
}}
 fwrite(&stud, sizeof(stud), 1, fp);
 fclose(fp);
}
//====================================================================================
//    FUNCTION TO DISPLAY RECORDS
void disp()
{
  printf("\n\t****************************** Welcome to display records **********************************");
  int j,i;
  float avg;
  int max,min;
  FILE *fp1;
   char month[20][20]={{"January"},{"February"},{"March"},{"April"},{"May"},{"June"},{"July"},{"August"},{"September"},{"October"},{"November"},{"December"}};
fp1 = fopen("rupa.txt", "r");
while(fread(&stud, sizeof(stud), 1, fp1)==1)
{
		printf("\n\t\t\t\t\t\t\tCity Name : %s",stud.name);
	for(i=0;i<3;i++)
{
 	printf("\n\t\t\t\tFor year %d",i+1);
	 for(j=0;j<12;j++)
 printf("\n\tTemperature in %s: %d ",month[j],stud.temp[i][j]);
}
printf("\n");
for(i=0;i<3;i++)
{
	printf("\n\t\t\t\tFor year %d",i+1);
		for(j=0;j<12;j++)
 printf("\n\tRainfall in %s: %d ",month[j],stud.rain[i][j]);
}
printf("\n");
for(i=0;i<3;i++)
{
	printf("\n\t\t\t\tFor year %d",i+1);
for(j=0;j<12;j++)
	 printf("\n\tsnowfall in %s: %d ",month[j],stud.snow[i][j]);
}
max=stud.temp[0][0];
min=stud.temp[0][0];
for(i=0;i<3;i++)
{
	for(j=0;j<12;j++)
{
if(stud.temp[i][j]>max)
max=stud.temp[i][j];
if(stud.temp[i][j]<min)
min=stud.temp[i][j];
}
avg=(max+min)/2.0;
printf("\n\t\t\t\t\tfor year %d",i+1);
printf("\n\tMaximum temperature= %d",max);
printf("\n\tMinimun temperature= %d",min);
printf("\n\tAverage Temperature= %f",avg);
}
printf("\n");
max=stud.rain[0][0];
min=stud.rain[0][0];
for(i=0;i<3;i++)
{
for(j=0;j<12;j++)
{
if(stud.rain[i][j]>max)
max=stud.rain[i][j];
if(stud.rain[i][j]<min)
min=stud.rain[i][j];
}
avg=(max+min)/2.0;
printf("\n\t\t\t\t\tfor year %d",i+1);
printf("\n\tMaximum Rainfall= %d",max);
printf("\n\tMinimun Rainfall= %d",min);
printf("\n\tAverage Rainfall= %f",avg);
}
printf("\n");
max=stud.snow[0][0];
min=stud.snow[0][0];
for(i=0;i<3;i++)
{
for(j=0;j<12;j++)
{
if(stud.snow[i][j]>max)
max=stud.snow[i][j];
if(stud.snow[i][j]<min)
min=stud.snow[i][j];
}
avg=(max+min)/2.0;
printf("\n\t\t\t\t\tfor year %d",i+1);
printf("\n\tMaximum Rainfall= %d",max);
printf("\n\tMinimun Rainfall= %d",min);
printf("\n\tAverage Rainfall= %f",avg);
}
}
fclose(fp1);
}
//====================================================================================
//FUNCTION TO CHECK THE FILE IS EMPTY OR NOT
int empty()
{
 int c = 0;
 FILE *fp;
 fp = fopen("rupa.txt", "r");
 while (fread(&stud, sizeof(stud), 1, fp))
  c = 1;
 fclose(fp);
 return c;
}
//====================================================================================
//FUNCTION TO TERMINATE THE PROGRAM
void terminate()
{
	printf("\n\n\t\tClosing...........");
	printf("\n\t\t\t\t\t\t............Closing\n");
	printf("\n\t\t\t\t*************** THANK YOU  by-Rupesh Kumar Mishra ***************\n");
	printf("\n\t****************************** Weather Report closed  **********************************");
	exit(1);
}
//====================================================================================
// MAIN PROGRAM
int main()
{
 int c, emp;
 do
 {												//Menu driven program
  printf("\n\t****************************** Welcome to Weather Report *******************************");
  		printf("\n\t\t\tPress 1 to Add Record");
		printf("\n\t\t\tPress 2 to Display Record");
		printf("\n\t\t\tPress 0 to Exit\n");
  printf("\n\t**********************************************************************************************\n");
  printf("\nEnter your choice : ");
  scanf("%d", &c);
  printf("\n");
  switch (c)
  {
  case 1:
   insert();
   break;
  case 2:
   emp = empty();
   if (emp == 0)
   printf("\nThe file is EMPTY\n");
   else
    disp();
   break;
  case 0:
   terminate();
   break;
  default:
   printf("\n\t\t\t**************** Your choice is wrong ****************\nPlease try again...\n");
   break;
  }
 } while (c != 0);
getch();
}
