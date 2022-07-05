#include<cstdlib>
#include<iostream>
#include<conio.h>

using namespace std;

bool gameOver;

int a = 1000000;

const int width = 20;
const int height =20;
int x, y, fruitX, fruitY, score;

int TailX[100], TailY[100];
int Tail_length ;

enum direction {STOP =0, LEFT, RIGHT, UP, DOWN};

direction dir;

void delay()
{
    
    for(int i=0; i<a; i++)
    {}

    a-=100;

}
void Setup()
{
    gameOver = false;
    x= width/2;
    y=height/2;
    fruitX = rand()%width;
    fruitY = rand()%height;
    score =0;
    Tail_length= 0;
}

void Draw()
{
    system("cls");
    for(int i=0; i<width+2; i++)
    {
        cout<<"#";
    }
    cout<<endl;

    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            
            if(j==0) 
                cout<<"#";
            if(i==y && j ==x) 
                cout<<"O";
            else if(i==fruitY &&j==fruitX) 
                cout<<"F";
            else
            {
               bool print =false;

               for(int temp=0; temp<Tail_length; temp++)
               {
                   if(j==TailX[temp] && i==TailY[temp])
                   {
                       cout<<"o";
                       print = true;
                   } 
               }
               
               if(!print)
                   cout<<" ";
            } 
                

            if(j== width-1) cout<<"#";
            
        }

        cout<<endl;
    }

    for(int i=0; i<width+2; i++)
    {
        cout<<"#";
    }
    cout<<endl;

    cout<<"Score : " <<score<<endl;
}

void Input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
        case 'a' : 
           dir = LEFT;
           break;

        case 'w' :
           dir = UP;
           break;

        case 'd' :
           dir = RIGHT;
           break;

        case 's' :
          dir = DOWN;
          break;
        case 'x' :
          dir =STOP;
          gameOver =true;
          break;
        }

        
    }
}

void Logic()
{
    int prevx =TailX[0];
    int prevy =TailY[0];
    int prev2X, prev2Y;
    
    TailX[0] = x;
    TailY[0] =y;

    for(int i=1; i<Tail_length; i++)
    { 
        prev2X = TailX[i];
        prev2Y = TailY[i];

        TailX[i] = prevx;
        TailY[i] = prevy;

        prevx = prev2X;
        prevy = prev2Y; 
    }

    switch (dir)
    {
    case LEFT :
        x--;
        break;

    case RIGHT :
        x++;
        break;
    
    case UP :
        y--;
        break;
    case DOWN :
        y++;
        break;
    }

    if(x<0 || x>width || y<0 || y>height) gameOver =true;

    for(int i=0; i<Tail_length; i++)
    {
        if(TailX[i] == x && TailY[i] == y) gameOver=true;
    }

    if(x==fruitX && y==fruitY)
    {
        score+=10;
        fruitX = rand()%width;
        fruitY = rand()%height;
        Tail_length++;
    }
}

int main()
{
    Setup();

    while(!gameOver)
    {
        delay();
        Draw();
        Input();
        Logic();
    }
    
    cout<<"Game Ended!";
    return 0;
}