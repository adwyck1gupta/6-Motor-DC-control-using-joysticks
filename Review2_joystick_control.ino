#define SPEED1 13        //Defining the Enable pins 
#define SPEED2 12
#define SPEED3 11
#define SPEED4 10
#define SPEED5 9
#define SPEED6 8
#define mtr1in1 22       // Defining the in pins
#define mtr1in2 23
#define mtr2in1 24
#define mtr2in2 25
#define mtr3in1 26
#define mtr3in2 27
#define mtr4in1 28
#define mtr4in2 29
#define mtr5in1 30
#define mtr5in2 31
#define mtr6in1 32
#define mtr6in2 33
#define mtr_on1 7       // Defining the motor drivers pwm pins
#define mtr_on2 6
#define mtr_on3 5
#define mtr_on4 4
#define mtr_on5 3
#define mtr_on6 2
// add 6 more pins for pwm pin on motor driver that activates the motor ctrl1-6 from D2-D7

int jx1=0;     // AXIS of Joystick
int jx2=0;
int jy1=0;
int jy2=0;
char x;


void setup() {
  // put your setup code here, to run once:

  //Setting pins as OUTPUT and INPUTS
  for (int i=22; i<34; i=i+1){
    pinMode(i, OUTPUT);
  }
  for (int j=8; j<14; j=j+1){
    pinMode(j, OUTPUT);
  }

  for (int k=2; k<8; k=k+1){
    digitalWrite(k, LOW);
  }
  
  for (int p=2; p<8; p=p+1){
    pinMode(p, OUTPUT);
  }

  
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  jx1=analogRead(A0);
  jy1=analogRead(A1);
  jx2=analogRead(A2);
  jy2=analogRead(A3);
  
  jx1=map(jx1, 0, 1023, 0, 255);
  jx2=map(jx2, 0, 1023, 0, 255);
  jy1=map(jy1, 0, 1023, 0, 255);
  jy2=map(jy2, 0, 1023, 0, 255);


  x=Serial.read();
  
  if(x=='1'){

     digitalWrite(mtr_on1, HIGH);
     digitalWrite(mtr_on2, HIGH);     // Pins that turn on the motor driver

     digitalWrite(mtr1in1, HIGH);
     digitalWrite(mtr1in2, LOW);
     analogWrite(SPEED1, jx1);
     digitalWrite(mtr2in1, HIGH);
     digitalWrite(mtr2in2, LOW);
     analogWrite(SPEED2, jx2);
    
  }

    if(x=='2'){

     digitalWrite(mtr_on3, HIGH);
     digitalWrite(mtr_on4, HIGH);     // Pins that turn on the motor driver

     digitalWrite(mtr3in1, HIGH);
     digitalWrite(mtr3in2, LOW);
     analogWrite(SPEED3, jx1);
     digitalWrite(mtr4in1, HIGH);
     digitalWrite(mtr4in2, LOW);
     analogWrite(SPEED4, jx2);
    
  }

      if(x=='3'){

     digitalWrite(mtr_on5, HIGH);
     digitalWrite(mtr_on6, HIGH);     // Pins that turn on the motor driver

     digitalWrite(mtr5in1, HIGH);
     digitalWrite(mtr5in2, LOW);
     analogWrite(SPEED5, jx1);
     digitalWrite(mtr6in1, HIGH);
     digitalWrite(mtr6in2, LOW);
     analogWrite(SPEED6, jx2);
    
  }
}
