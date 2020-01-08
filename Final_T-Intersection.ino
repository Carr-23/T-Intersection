#include <Servo.h>

int val = 0;
int rot = 0;

int ldrSensor = 0;
int irSensor = 0;
int timer = 0;
Servo myservo;
int time;
int time1;
int changeTime;
void setup() {
  time = millis ();
  time1 = millis ();
  //time
  changeTime = time + 2000;
  // put your setup code here, to run once:
  pinMode (1, OUTPUT); //green
  pinMode (2, OUTPUT); //yellow
  pinMode (3, OUTPUT); //red
  // 2 TRAFFIC LIGHTS ACROSS FROM EACH OTHER

  pinMode (5, OUTPUT); //green
  pinMode (6, OUTPUT); //yellow
  pinMode (7, OUTPUT); //red
  // 1 SOLO TRAFFIC LIGHT
  pinMode (9, OUTPUT);
  // 1 SOLO STREET LIGHT
  pinMode (12, OUTPUT);
  // green light ped
  pinMode (13, INPUT);
  // 1 BUTTON
  // 1 IR SENSOR
  pinMode (8, OUTPUT); //green
  myservo.attach (4);
  //SERVO

}

void button() {

  if (changeTime <= time + timer)
  {
    if (changeTime <= time - 3000 + timer)
    {

      if (changeTime <= time - 4000 + timer)
      {

      }
      else
      {
        val = digitalRead(13);  // read input value
        if (val == 1)
        {
          timer = -1500; // check if the input is HIGH (button released)
        }
      }

    }
    else
    {
      val = digitalRead(13);  // read input value
      if (val == 1)
      {
        timer = -1500; // check if the input is HIGH (button released)
      }
    }
  }
  else
  {
    val = digitalRead(13);  // read input value
    if (val == 1)
    {
      timer = 1500; // check if the input is HIGH (button released)
    }
  }
}







void lights () {
  time = millis ();

  if (changeTime <= time + timer)
  {
    if (changeTime <= time - 1000 + timer)
    {
      if (changeTime <= time - 3000 + timer)
      {
        if (changeTime <= time - 4000 + timer)
        {
          digitalWrite (3, LOW);
          digitalWrite (6, LOW);
          digitalWrite (12, LOW);
          //Eveything OFF
          changeTime = time + 2000;
          timer = 0;
        }
        else
        {
          digitalWrite (5, LOW);
          digitalWrite (6, HIGH);
          digitalWrite (12, HIGH);
          //RED ON YELLOW ON
        }
      }
      else
      {
        digitalWrite (2, LOW);
        digitalWrite (7, LOW);
        digitalWrite (12, LOW);

        digitalWrite (3, HIGH);
        digitalWrite (5, HIGH);
      }
    }
    else
    {
      digitalWrite (1, LOW);
      digitalWrite (2, HIGH);
      //YELLOW ON RED ON
    }
  }
  else
  {
    digitalWrite (1, HIGH);
    digitalWrite (7, HIGH);
    digitalWrite (12, HIGH);
    //GREEN ON RED ON
  }
}


void ldr () {
  ldrSensor = analogRead(A0);
  if (ldrSensor < 20)
  {
    digitalWrite (9, HIGH);
  }
  else
  {
    digitalWrite (9, LOW);
  }
}

void ir () {
  digitalWrite(8, HIGH);

  irSensor = analogRead(A2);
  Serial.println (irSensor);
  if (irSensor < 80)
  {
    if (rot == 0)
    {
      myservo.write (180);
      rot = 1;
    }

  }

  if (irSensor > 100)
  {
    if (rot == 1)
    {
      myservo.write (0);
      rot = 0;
    }
  }
}



void loop () {
  lights ();
  button();
  ldr();
  ir();
}
