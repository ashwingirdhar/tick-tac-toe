#include<iostream>          
#include<conio.h>            
#include<stdlib.h>   
#include <ctime>

using namespace std;     
char tic[3][3];               
int d,e,f,a,t,i,j,x,y;        
void display();               
void user();                  
void newdisp();               
void pc();                    
int check();                  
int horcheck();               
int vercheck();               
int diagcheck();              
int main()                        
{
system("clear");
                
srand(time(NULL));                   
int d=rand()%2;              
for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	tic[i][j]=' ';        
display();                    
d==0?user():pc();             
getch();                      
return 0;                     
}
void display()                
{
for(t=0;t<3;t++)
	{
	cout<<"		"<<tic[t][0]<<" | "<<tic[t][1]<<" | "<<tic[t][2]<<endl;

	if(t!=2)
	cout<<"		--|---|--"<<endl;
	}
}
void user()                  
{
cout<<"	ENTER THE CO-ORDINATES WHERE YOU WANT TO PUT UR 'X' i.e 0,1,2: ";
cin>>x>>y;
if((x<0)||(x>2)&&(y<0)||(y>2))  
	{
	cout<<"	ENTER THE CORRECT CO-ORDINATES "<<endl;
	user();    //user function call
	}
else
	{
	if(tic[x][y]==' ')    
		{
		tic[x][y]='X';  
		newdisp();    
		}
	else
		{
		cout<<"	THIS POSITION IS ALREADY FILLED. CHOOSE SOME OTHER CO-ORDINATES: ";
		user();       l
		}
	}
d=check();            
if(d==0)
pc();                 
else
	{
	cout<<"	YOU ARE THE WINNER"<<endl;
	getche();     

	exit(1);      
	}
}
void newdisp()        {
for(t=0;t<3;t++)
	{
	cout<<"		"<<tic[t][0]<<" | "<<tic[t][1]<<" | "<<tic[t][2]<<endl;

	if(t!=2)
	cout<<"		--|---|--"<<endl;
	}
}
void pc()         {
int f,z;
srand(time(NULL));      
cout<<"	THIS IS THE COMPUTER'S MOVE "<<endl;
for(i=0;i<=20;i++)
	{
	f=rand()%3;
	z=rand()%3;
	if(tic[f][z]==' ')      
		{
		tic[f][z]='O';  
		goto x;         
		}
	else
	continue;               
	}
x:newdisp();                    
d=check();                      
if(d==0)
user();                         
else
	{
	cout<<"	I'M THE WINNER "<<endl;
	getche();           
	exit(1);            
	}
}
check()                     //check function definition
{
horcheck();                
vercheck();                
diagcheck();               
return (d||e||f);
}
horcheck()                 
{
if(((tic[0][0]==tic[0][1])&&(tic[0][1]==tic[0][2])&&(tic[0][1]!=' '))||((tic[1][0]==tic[1][1])&&(tic[1][1]==tic[1][2])&&(tic[1][1]!=' '))||((tic[2][0]==tic[2][1])&&(tic[2][1]==tic[2][2])&&(tic[2][2]!=' ')))
d=1;                       
else                        
d=0;                        
return d;
}
vercheck()                  //vercheck function definition
{
if(((tic[0][0]==tic[1][0])&&(tic[1][0]==tic[2][0])&&(tic[0][0]!=' '))||((tic[0][1]==tic[1][1])&&(tic[1][1]==tic[2][1])&&(tic[0][1]!=' '))||((tic[0][2]==tic[1][2])&&(tic[1][2]==tic[2][2])&&(tic[0][2]!=' ')))
e=1;                        
else                        
e=0;                        
return e;
}
diagcheck()                 
{
if(((tic[0][0]==tic[1][1])&&(tic[1][1]==tic[2][2])&&(tic[0][0]!=' '))||((tic[0][2]==tic[1][1])&&(tic[1][1]==tic[2][0])&&(tic[1][1]!=' ')))
f=1;                        
else                        
f=0;                        
return f;
}


        

