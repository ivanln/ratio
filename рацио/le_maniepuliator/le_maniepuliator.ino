/*void setup()
  {
    pinMode(A0, INPUT);
    Serial.begin(9600);
  }
  
void loop()
  {
    int rotat;
    rotat = analogRead(A0);
    Serial.println(rotat);
  }*/


/*int button = 2;

int led = 8;


void setup() {

pinMode(led, OUTPUT);

pinMode(button, INPUT);

}

void loop(){

if (digitalRead(button) == HIGH) {



}

else {

digitalWrite(led, LOW);

}

}*/


//готовый код: 3 оси 3 кнопки. кнопки: запись, воспроизведение, очистка

#include <Servo.h> 

Servo servo;
Servo servo1;
Servo servo2;


int button;
int button1;

int gradserv[100][3];
int logbut = 0;
int logbut1 = 0;
int logbut2 = 0;
int k = 0;

void setup() {
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(4, INPUT);
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    Serial.begin(9600);

    servo.attach(8);
    servo1.attach(9);
    servo2.attach(10);
}

void loop(){

//
    int rotat;
    rotat = analogRead(A0);

    double grad;
    grad = rotat/5.68333333;
    servo.write(grad);
//
    int rotat1;
    rotat1 = analogRead(A1);

    double grad1;
    grad1 = rotat1/5.68333333;
    servo1.write(grad1);
//
    int rotat2;
    rotat2 = analogRead(A2);

    double grad2;
    grad2 = rotat2/5.68333333;
    servo2.write(grad2);
//








//здесь начинается запись с помощью кнопки 1 и воспроизведение с помощью кнопки 2



if ((digitalRead(2) == HIGH) && (logbut == 0)) //запись
    {
        gradserv[k][0] = grad;
        gradserv[k][1] = grad1;
        gradserv[k][2] = grad2;
        Serial.print(gradserv[k][0]);
        Serial.print(" ");
        Serial.print(gradserv[k][1]);
        Serial.print(" ");
        Serial.print(gradserv[k][2]);
        Serial.print(" ");
        Serial.println(" ");
        
        logbut = 1;
        k++;
    }


if(digitalRead(2) == LOW)
{
  logbut = 0;
  
}





if((digitalRead(3) == HIGH) && (logbut1 == 0)) //воспроизведение
{
     
        for(int j = 0; j<k; j++)
      {
        
        servo.write(gradserv[j][0]);       
        servo1.write(gradserv[j][1]);
        servo2.write(gradserv[j][2]);
        
        Serial.print(gradserv[j][0]);
        Serial.print(" ");
        Serial.print(gradserv[j][1]);
        Serial.print(" ");
        Serial.print(gradserv[j][2]);
        Serial.print(" ");
        Serial.println(" ");
        delay(2000);
      }
        
        
     

logbut1 = 1;

}




if(digitalRead(3) == LOW)
{
  logbut1 = 0;
  
}








if((digitalRead(4) == HIGH) && (logbut2 == 0)) //воспроизведение
{
     
      for(int i = 0; i <= k; i++)
      {
      for (int j = 0; j < 3; j++)
      {
       gradserv[i][j] = NULL;
        
      }
      }


k = 0;
      
logbut2 = 1;

}




if(digitalRead(4) == LOW)
{
  logbut2 = 0;
  
}

















/*if ((digitalRead(button1) == HIGH) && logbut1 == 0) 
    {
          for (int i = 0; i < k; k++)
          {
            servo.write(gradserv[i][0]);
            servo1.write(gradserv[i][0]);
            servo2.write(gradserv[i][0]);
            delay(5000);
          }
          logbut1 = 1;
    }


*/



 /*    
  if (digitalRead(button) == HIGH) 
    {
        stp = grad;
        stp1 = grad1;
        stp2 = grad2;

        int wh = 1;
        while (wh == 1)
        {
              int rotat;
                  rotat = analogRead(A0);
              
                  double grad;
                  grad = rotat/5.68333333;
                  servo.write(grad);
              //
                  int rotat1;
                  rotat1 = analogRead(A1);
              
                  double grad1;
                  grad1 = rotat1/5.68333333;
                  servo1.write(grad1);
              //
                  int rotat2;
                  rotat2 = analogRead(A2);
              
                  double grad2;
                  grad2 = rotat2/5.68333333;
                  servo2.write(grad2);

        
    



          
           if (digitalRead(button) == HIGH) 
             {


              
                s1tp = grad;
                s1tp1 = grad1;
                s1tp2 = grad2;
                wh = 0;
              }
        }
       
    }


if (digitalRead(button1) == HIGH) 
    {
       servo.write(stp);
       servo1.write(stp1);
       servo2.write(stp2);
       delay(5000);
       servo.write(s1tp);
       servo1.write(s1tp1);
       servo2.write(s1tp2);

       
    }



*/







    
    /*Serial.print("rotat = ");
    Serial.println(rotat);
    Serial.print("grad = ");
    Serial.println(grad);
  

}




*/















}




