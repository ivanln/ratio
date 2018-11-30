#include <Servo.h>

#include <StaticThreadController.h>
#include <Thread.h>
#include <ThreadController.h>
Thread ledThread = Thread();


#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX
int slider[4];
int motor1, motor2;
int button[3];
int i;
String packetStr;

int logbut = 0;
int logbut1 = 0;
int logbut2 = 0;
bool gradserv[100][6];
int k = 0;
Thread ledThread = Thread();
int grad;
int grad1;
int grad2;
int grad3;
int t;

Servo servo, servo1, servo2, servo3;




void setup() {
  Serial.begin(9600);
  mySerial.begin(4800);
  servo1.attach(8);
  servo.attach(9);
  servo1.attach(10);
  servo1.attach(11);


  ledThread.onRun(ledBlink);  // назначаем потоку задачу
  ledThread.setInterval(50); // задаём интервал срабатывания, мсек

}

void ledBlink() {
  gradserv[k][0] = slider[0] * 18 / 10;
  gradserv[k][1] = slider[1] * 18 / 10;
  gradserv[k][2] = slider[2] * 18 / 10;
  gradserv[k][3] = slider[3] * 18 / 10;
  //gradserv[k][4] = motor1;
  //gradserv[k][5] = motor2;
  /*Serial.print(gradserv[k][0]);
    Serial.print(" ");
    Serial.print(gradserv[k][1]);
    Serial.print(" ");
    Serial.print(gradserv[k][2]);
    Serial.print(" ");
    Serial.print(gradserv[k][3]);
    Serial.println(" ");*/
  k++;
}





void loop() {
  while (1) {
    readserial1();
    showdata();
    //Пишем код->

    //двигаем серваки
    servo.write(slider[0] * 18 / 10);// повернуть сервопривод в зависимости от положения слайдера
    servo1.write(slider[1] * 18 / 10);
    servo2.write(slider[2] * 18 / 10);
    servo3.write(slider[3] * 18 / 10);

    if ((button[0] == 1) && (logbut == 0))
    {
      //здесь будет запись

      while (button[0] == 0)
      {


        servo.write(slider[0] * 18 / 10);// повернуть сервопривод в зависимости от положения слайдера
        servo1.write(slider[1] * 18 / 10);
        servo2.write(slider[2] * 18 / 10);
        servo3.write(slider[3] * 18 / 10);




        if (ledThread.shouldRun())
          ledThread.run(); // запускаем поток
      }
      logbut = 1;
    }

    if (button[0] == 0)
    {
      logbut = 0;
    }








    if ((button[1] == 1) && (logbut1 == 0))
    {
      for (int i = 0; i <= k; i++)
      {

        servo.write(gradserv[i][0]);
        servo1.write(gradserv[i][1]);
        servo2.write(gradserv[i][2]);
        servo3.write(gradserv[i][3]);
        delay(50);

      }
      logbut1 = 1;
    }
    // TODO you loop code
    // используйте структуру RemoteXY для передачи данных

    if (button[1] == 0)
    {
      logbut1 = 0;
    }



    if ((button[2] == 1) && (logbut2 == 0))
    {
      for (int j = 0; j <= k; j++)
      {
        gradserv[j][0] = 0;
        gradserv[j][1] = 0;
        gradserv[j][2] = 0;
        gradserv[j][3] = 0;
      }
      k = 0;
    }

    if (button[1] == 0)
    {
      logbut2 = 0;
    }



  }
}


void readserial1 () {
  if (mySerial.available() > 0) {
    packetStr = mySerial.readStringUntil('|');
    sscanf(packetStr.c_str(), "%d:%d:%d:%d:%d:%d:%d:%d:%d",
           &slider[0], &slider[1], &slider[2], &slider[3],
           &motor1, &motor2,
           &button[0], &button[1], &button[2]
          );
  }
}
void showdata() {
  for (i = 0; i <= 3; i++) {
    Serial.print(slider[i]);
    Serial.print(" ");
  }
  Serial.print(motor1);
  Serial.print(" ");
  Serial.print(motor2);
  Serial.print(" ");
  for (i = 0; i <= 2; i++) {
    Serial.print(button[i]);
    Serial.print(" ");
  }
  Serial.println();
}

