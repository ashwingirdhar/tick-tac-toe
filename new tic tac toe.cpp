#include<bits/stdc++.h>
#include <ctime>
using namespace std;
void user();
void comp();
bool isMovesLeft();
int minimax();
int evaluate();
char a[3][3];
void display()                
{
for(int t=0;t<3;t++)
	{
	cout<<"		"<<a[t][0]<<" | "<<a[t][1]<<" | "<<a[t][2]<<endl;

	if(t!=2)
	cout<<"		--|---|--"<<endl;
	}
}
void user()     
{
    if(!isMovesLeft())
    {
        cout<<"Its a Draw"<<endl;
        exit(1);
    }
    cout<<"ITS YOUT TURN"<<endl;
cout<<"	ENTER THE CO-ORDINATES : ";
int x,y;
cin>>x>>y;
if((x<0)||(x>2)&&(y<0)||(y>2))  
	{
	cout<<"	ENTER THE CORRECT CO-ORDINATES "<<endl;
	user();    
	}
else
	{
	if(a[x][y]==' ')    
		{
		a[x][y]='O';  
		}
	else
		{
		cout<<"	THIS POSITION IS ALREADY FILLED. CHOOSE SOME OTHER CO-ORDINATES: "<<endl;
		user();       
		}
	}
display();
int d=evaluate();            
	if(d==-10)	
	{
	    cout<<"	YOU ARE THE WINNER"<<endl ;
        exit(1);      
	}
	comp();

}
bool isMovesLeft() 
{ 
    for (int i = 0; i<3; i++) 
        for (int j = 0; j<3; j++) 
            if (a[i][j]==' ') 
                return true; 
    return false; 
} 
int evaluate() 
{ 

    for (int row = 0; row<3; row++) 
    { 
        if (a[row][0]==a[row][1] && 
            a[row][1]==a[row][2]) 
        { 
            if (a[row][0]=='X') 
                return +10; 
            else if (a[row][0]=='O') 
                return -10; 
        } 
    }  
    for (int col = 0; col<3; col++) 
    { 
        if (a[0][col]==a[1][col] && 
            a[1][col]==a[2][col]) 
        { 
            if (a[0][col]=='X') 
                return +10; 
  
            else if (a[0][col]=='O') 
                return -10; 
        } 
    } 
  
    if (a[0][0]==a[1][1] && a[1][1]==a[2][2]) 
    { 
        if (a[0][0]=='X') 
            return +10; 
        else if (a[0][0]=='O') 
            return -10; 
    } 
   if (a[0][2]==a[1][1] && a[1][1]==a[2][0]) 
    { 
        if (a[0][2]=='X') 
            return +10; 
        else if (a[0][2]=='O') 
            return -10; 
    } 
    return 0; 
} 
int minimax(char a[3][3], int depth, bool isMax) 
{ 
    int score = evaluate();  
    if (score == 10 || score==-10) 
        return score; 
   
    if (isMovesLeft()==false) 
        return 0; 
    if (isMax) 
    { 
        int best = -1000; 
  
        for (int i = 0; i<3; i++) 
        { 
            for (int j = 0; j<3; j++) 
            { 
                if (a[i][j]==' ') 
                { 
                    a[i][j] = 'X'; 
   
                    best = max( best, 
                        minimax(a, depth+1, false) ); 
                    a[i][j] = ' '; 
                } 
            } 
        } 
        return best; 
    } 
   
    else
    { 
        int best = 1000; 
  
        for (int i = 0; i<3; i++) 
        { 
            for (int j = 0; j<3; j++) 
            { 
                if (a[i][j]==' ') 
                { 
                    a[i][j] = 'O'; 
  
                    best = min(best, minimax(a, depth+1, true)); 
                    a[i][j] = ' '; 
                } 
            } 
        } 
        return best; 
    } 
} 
  
void comp()
{
     if(!isMovesLeft())
    {
        cout<<"Its a Draw"<<endl;
        exit(1);
    }
    cout<<"ITS COMPUTERS'S TURN"<<endl;
    int bestval=INT_MIN;
    pair<int,int>p;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(a[i][j]==' ')
            {
                a[i][j]='X';
                int best=minimax(a,0,false);
                a[i][j]=' ';
                bestval=max(bestval,best);
                if(best==bestval)
                {
                    p.first=i;
                    p.second=j;
                }
            }
        }
    }
        a[p.first][p.second]='X';
        display();
        if(evaluate()==10)
        {
            cout<<"Computer wins"<<endl;
            exit(1);
        }
        user();
}
int main()
{
    for(int i=0;i<3;i++)
    {
	
    for(int j=0;j<3;j++)
    a[i][j]=' ';
}
    srand(time(NULL));                   
    int d=rand()%2;
    if(d%2==0)
    user();
    else
    comp();    
}
