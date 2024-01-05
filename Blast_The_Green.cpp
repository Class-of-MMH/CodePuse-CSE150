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
     void moveLeft();

    void moveRight();
};

class Balloon{
public: int x,y;
    char color;

    Balloon(char c):color(c){
        resetPosition();
    }


 void resetPosition(){
        x=rand()%(SCREEN_WIDTH-2)+1;
        y=0;
    }

     void move(){
        y+=BALLOON_SPEED;
        if(y >= SCREEN_HEIGHT-1){
            resetPosition();
        }
    }
};


void drawBalloon(const Balloon& balloon,char*buffer){
    switch(balloon.color){
        case 'g':
            buffer[balloon.x+balloon.y*SCREEN_WIDTH]='G';
            buffer[(balloon.x-1)+(balloon.y+1)*SCREEN_WIDTH]='G';
            buffer[balloon.x+(balloon.y+1)*SCREEN_WIDTH]='G';
            buffer[(balloon.x + 1) + (balloon.y + 1) * SCREEN_WIDTH]='G';
            buffer[balloon.x+(balloon.y+2)*SCREEN_WIDTH]='G';
            break;

        case 'r':
            buffer[balloon.x+balloon.y*SCREEN_WIDTH]='R';
            buffer[(balloon.x-1)+(balloon.y+1)*SCREEN_WIDTH]='R';
            buffer[balloon.x+(balloon.y+1)*SCREEN_WIDTH]='R';
            buffer[(balloon.x+1)+(balloon.y +1)*SCREEN_WIDTH]='R';
            buffer[balloon.x+(balloon.y+2)*SCREEN_WIDTH]='R';
            break;
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
 while(life>0){
        memset(buffer, ' ',SCREEN_WIDTH*SCREEN_HEIGHT);

        drawBoundary(buffer);

        if(balloonTimer% BALLOON_SPEED==0){
            for(int i=0;i<NUM_BALLOONS;++i){
                balloons[i].move();
                drawBalloon(balloons[i],buffer);

                if(balloons[i].y==SCREEN_HEIGHT-2&&abs(balloons[i].x-pin.x)<2){
                    if(balloons[i].color =='g'){
                        score+=10;
                    }else if(balloons[i].color == 'r'){
                        life--;
                    }
                    balloons[i].resetPosition();
                }
            }
        }
  
return 0;
}
