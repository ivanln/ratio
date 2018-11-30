#include <StaticThreadController.h>
#include <Thread.h>
#include <ThreadController.h>

#include <Servo.h>

Servo servo;
Servo servo1;
Servo servo2;
Servo servo3;

int rotat;
double grad;
int rotat1;
double grad1;
int rotat2;
double grad2;
int rotat3;
double grad3;

int button;
int button1;

byte gradserv[200][4];
int logbut = 0;
int logbut1 = 0;
int logbut2 = 0;
int k = 0;

Thread ledThread = Thread();


void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  Serial.begin(9600);

  servo.attach(8);
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);


  ledThread.onRun(ledBlink);  // назначаем потоку задачу
  ledThread.setInterval(50); // задаём интервал срабатывания, мсек

}


void ledBlink() {
  gradserv[k][0] = grad;
  gradserv[k][1] = grad1;
  gradserv[k][2] = grad2;
  gradserv[k][3] = grad3;
  Serial.print(gradserv[k][0]);
  Serial.print(" ");
  Serial.print(gradserv[k][1]);
  Serial.print(" ");
  Serial.print(gradserv[k][2]);
  Serial.print(" ");
  Serial.print(gradserv[k][3]);
  Serial.print(" ");
  Serial.println(" ");
  k++;
}




void loop() {

  //

  rotat = analogRead(A0);
  rotat1 = analogRead(A1);
  rotat2 = analogRead(A2);
  rotat3 = analogRead(A3);

  grad = rotat / 5.68333333;
  servo.write(grad);
  grad1 = rotat1 / 5.68333333;
  servo1.write(grad1);
  grad2 = rotat2 / 5.68333333;
  servo2.write(grad2);
  grad3 = rotat3 / 5.68333333;
  servo3.write(grad3);


  if ((digitalRead(2) == HIGH) && (logbut == 0)) //запись
  {

    while (digitalRead(3) == LOW)
    {
      //

  rotat = analogRead(A0);
  rotat1 = analogRead(A1);
  rotat2 = analogRead(A2);
  rotat3 = analogRead(A3);

  grad = rotat / 5.68333333;
  servo.write(grad);
  grad1 = rotat1 / 5.68333333;
  servo1.write(grad1);
  grad2 = rotat2 / 5.68333333;
  servo2.write(grad2);
  grad3 = rotat3 / 5.68333333;
  servo3.write(grad3);



      if (ledThread.shouldRun())
        ledThread.run(); // запускаем поток
    }
    logbut = 1;
  }


  if (digitalRead(2) == LOW)
  {
    logbut = 0;

  }


  if ((digitalRead(4) == HIGH) && (logbut == 0)) //воспр
  {
    for (int t = 0; t < k; t++)
    {
      servo.write(gradserv[t][0]);
      servo1.write(gradserv[t][1]);
      servo2.write(gradserv[t][2]);
      servo3.write(gradserv[t][3]);
      Serial.print(gradserv[t][0]);
      Serial.print(" ");
      Serial.print(gradserv[t][1]);
      Serial.print(" ");
      Serial.print(gradserv[t][2]);
      Serial.print(" ");
      Serial.print(gradserv[t][3]);
      Serial.print(" ");
      Serial.println(" ");
      delay(50);
      
    }
    logbut2 = 1;
  }


  if (digitalRead(4) == LOW)
  {
    logbut2 = 0;

  }

















}










