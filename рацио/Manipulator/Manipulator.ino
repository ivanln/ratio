


  
#define REMOTEXY_MODE__HARDSERIAL
#include <RemoteXY.h> 
#define REMOTEXY_SERIAL Serial 
#define REMOTEXY_SERIAL_SPEED 9600  
#pragma pack(push, 1) 
uint8_t RemoteXY_CONF[] = 
  { 255,4,0,0,0,68,0,8,175,0,
  4,128,48,43,49,13,2,26,4,0,
  22,8,12,48,2,26,4,0,4,8,
  12,48,2,26,129,0,5,2,19,10,
  17,90,83,69,0,129,0,67,58,29,
  4,17,65,110,100,114,105,105,32,82,
  111,122,104,107,111,118,0,4,0,82,
  9,8,28,2,26 }; 
   
  
struct { 

    
  int8_t slider_2; 
  int8_t slider_3; 
  int8_t slider_1;  
  int8_t slider_4;  

   
  uint8_t connect_flag; 
} RemoteXY; 
#pragma pack(pop) 


#include <Servo.h> // библиотека для работы с сервоприводами
Servo myservo1, myservo2, myservo3, myservo4; // подлючить сервоприводы
void setup()  
{ 
  RemoteXY_Init ();  
   RemoteXY.slider_1 = 50;//установить слайдеры в среднее положение
   RemoteXY.slider_2 = 50;//установить слайдеры в среднее положение
   RemoteXY.slider_3 = 50;//установить слайдеры в среднее положение
    myservo1.attach(3); //пин сервопривода
  myservo2.attach(5);//пин сервопривода
  myservo3.attach(6);//пин сервопривода
  myservo4.attach(9);//пин сервопривода
  
   
} 

void loop()  
{  
  RemoteXY_Handler (); 
   int ms = RemoteXY.slider_1*20+500;//формула вычисления (взята из сайта RemoteXY) 
  myservo1.writeMicroseconds(ms);// повернуть сервопривод в зависимости от положения слайдера 
  int ms2 = RemoteXY.slider_2*20+500; //формула вычисления (взята из сайта RemoteXY) 
  myservo2.writeMicroseconds(ms2);// повернуть сервопривод в зависимости от положения слайдера 
  int ms3 = RemoteXY.slider_3*20+500; //формула вычисления (взята из сайта RemoteXY) 
  myservo3.writeMicroseconds(ms3);// повернуть сервопривод в зависимости от положения слайдера 
  int ms4 = RemoteXY.slider_4*20+500; //формула вычисления (взята из сайта RemoteXY) 
  myservo4.writeMicroseconds(ms4);// повернуть сервопривод в зависимости от положения слайдера 
  


}


