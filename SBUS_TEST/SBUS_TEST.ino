/*
 * CH2 GAS
 * CH4 Direccio
 * Mapejat Motor: gas = map(sbus._channels[2], 172, 1811, 0, 65535); 
 * PWM Motor: pwmWrite(motor, gas);
 */


//#include <WEMOS_Motor.h>
#include <SBUS.h>

#define motorPin PA8
#define lowLimit 0
#define highLimit 50
#define migPos 100

int sumCH = 0;
int pwm;
int servo;
unsigned int gas = 0;

//Motor shiled I2C Address: 0x30
//PWM frequency: 1000Hz(1kHz)
//Motor M1(0x30,_MOTOR_A, 1000);//Motor A

SBUS sbus(Serial2); //Green SBUS on PB11 (uninverted)

void setup()
{  
  pinMode(motorPin, PWM); 
  pinMode(PA7, INPUT_ANALOG);
  
  sbus.begin();
  setupTimer2();
  
  Serial.begin(115200);
  Serial.println("Setup finished");
}

void loop()
{
  delay(300);
  sumCH = 0;
  for (int i = 1; i >= 16; i++) {
    sumCH = sumCH + sbus._channels[i];
  }
  if (sumCH == 0) {
    Serial.println("NOT CONNECTED");
  }
  else {
    printSBUSStatus();
  }
  // Servo control proces
  //servo = map(analogRead(PA7), 0, 4095, 0, 100); 
  //Serial.println(servo);
  //servoControl(servo);
  // Motor control proces
  //gas = map(sbus._channels[2], 172, 1811, 0, 65535);
  //pwmWrite(motorPin, gas);
}
/*
void servoControl(int potPosition) {
  M1.setmotor( _CW, pwm);
  M1.setmotor(_CCW, pwm);
  M1.setmotor(_STOP);
  M1.setmotor(_SHORT_BRAKE);
  M1.setmotor(_STANDBY);
}
*/

void setupTimer2()
{
  Timer2.setMode(TIMER_CH1, TIMER_OUTPUTCOMPARE);
  Timer2.setPeriod(249);
  Timer2.setCompare(TIMER_CH1, 1);
  Timer2.attachInterrupt(TIMER_CH1, sbusProcess);
}

void printSBUSStatus()
{
  Serial.print("Ch1  ");
  Serial.println(sbus._channels[1]);
  Serial.print("Ch2  ");
  Serial.println(sbus._channels[2]);
  Serial.print("Ch3  ");
  Serial.println(sbus._channels[3]);
  Serial.print("Ch4  ");
  Serial.println(sbus._channels[4]);
  Serial.print("Ch5  ");
  Serial.println(sbus._channels[5]);
  Serial.print("Ch6  ");
  Serial.println(sbus._channels[6]);
  Serial.print("Ch7  ");
  Serial.println(sbus._channels[7]);
  Serial.print("Ch8  ");
  Serial.println(sbus._channels[8]);
  Serial.print("Ch9  ");
  Serial.println(sbus._channels[9]);
  Serial.print("Ch10 ");
  Serial.println(sbus._channels[10]);
  Serial.print("Ch11 ");
  Serial.println(sbus._channels[11]);
  Serial.print("Ch12 ");
  Serial.println(sbus._channels[12]);
  Serial.print("Ch13 ");
  Serial.println(sbus._channels[13]);
  Serial.print("Ch14 ");
  Serial.println(sbus._channels[14]);
  Serial.print("Ch15 ");
  Serial.println(sbus._channels[15]);
  Serial.print("Ch16 ");
  Serial.println(sbus._channels[16]);
  Serial.println();
}


void sbusProcess()
{
  sbus.process();
}
