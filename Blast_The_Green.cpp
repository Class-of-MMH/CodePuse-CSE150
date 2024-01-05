#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<conio.h>
#include<iostream>
using namespace std;

const int SCREEN_WIDTH=40;
const int SCREEN_HEIGHT=25;
const int NUM_BALLOONS=4;
const int PIN_SPEED=5;
const int BALLOON_SPEED=1;

class Pin{
public:int x;

    Pin():x(SCREEN_WIDTH/2){}

      void moveLeft(){
        if(x>1){
            x -=PIN_SPEED;
        }
    }

     void moveRight(){
        if(x<SCREEN_WIDTH-2){
            x+=PIN_SPEED;
        }
    }
};
void drawPin(const Pin&pin,char*buffer){
    buffer[pin.x+(SCREEN_HEIGHT-2)*SCREEN_WIDTH]='^';
}

void drawBoundary(char*buffer){
    for (int i = 0;i <SCREEN_WIDTH;++i){
        buffer[i]='#';
        buffer[i+(SCREEN_HEIGHT-1)*SCREEN_WIDTH]='#';
    }

    for (int i=1;i<SCREEN_HEIGHT-1;++i){
        buffer[i*SCREEN_WIDTH]='#';
        buffer[i*SCREEN_WIDTH+SCREEN_WIDTH-1]='#';
    }
}

int main(){
  
cout<<"Instructions: "<<endl;
cout<<"***" <<endl;
cout<<endl;
cout<<"##If pin hits G  create shape \nyou win 10 point"<<endl;
cout<<"##If pin hits R  create shape \nyou lose 1 life"<<endl;
cout << "##Press right and left arrow keys \nto move the pin."<<endl;
cout<<"##The game is end when the life become  0 "<<endl;
cout<<endl;
system("pause");
srand(static_cast<unsigned>(time(0)));
char*buffer=new char[SCREEN_WIDTH*SCREEN_HEIGHT];
memset(buffer, ' ', SCREEN_WIDTH*SCREEN_HEIGHT);
Balloon balloons[NUM_BALLOONS]={'g', 'r', 'g'};
Pin pin;
  
int balloonTimer=0;
int score=0;
int life=3;
  
return 0;
}
