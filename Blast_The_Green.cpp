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

  
return 0;
}
