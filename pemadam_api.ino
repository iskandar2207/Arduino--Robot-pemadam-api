int echo1 = A4;
int trig1 = A5;
int echo2 = A2;
int trig2 =A3;
int echo3 =A0;
int trig3 =A1;
int in1 = 8;
int in2 = 9;
int in3= 10;
int in4=11;
int enA = 7;
int enB= 12;
#define MAX 100
int ABS= 500;
int jarak_kiri = 0, jarak_kanan =0, tengah=0;
//int api        =500; // NILAI TOLERANSI CAHAYA API (0-1024)
//#define FLAME_SENSOR 4 //connect FLAME_SENSOR to digital pin3
//#define KIPAS 2
#define BUZZER 5
const int sensorPin = 4; 
const int outputPin = 2; 
int bacasensor = 0;

void maju(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, ABS);
  analogWrite(enB, ABS);

  Serial.println("robot maju");
}

void mundur(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, ABS);
  analogWrite(enB, ABS);
  Serial.println("robot mundur");
}
void belok_kiri(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, ABS);
  analogWrite(enB, ABS);
  Serial.println("robot belok kiri");
}
void belok_kanan(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, ABS);
  analogWrite(enB, ABS);
  Serial.println("robot belok kanan");
  }
  void stopp(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
   analogWrite(enA, LOW);
  analogWrite(enB, LOW);
Serial.println("robot stop");  }
   int test_jarakkiri(){
    digitalWrite (trig1,LOW);
    delayMicroseconds(2);
    digitalWrite (trig1,HIGH);
    delayMicroseconds(20);
    digitalWrite (trig1,LOW);
    float Fdistance = pulseIn (echo1, HIGH);
    delay (10);
    Fdistance = Fdistance / 29 / 2;
    return(int) Fdistance;
  }
  int test_jaraktengah(){
    digitalWrite (trig2,LOW);
    delayMicroseconds(2);
    digitalWrite (trig2,HIGH);
    delayMicroseconds(20);
    digitalWrite (trig2,LOW);
    float Fdistance = pulseIn (echo2, HIGH);
    delay (10);
    Fdistance = Fdistance / 29 / 2;
    return(int) Fdistance;
  }
  int test_jarakkanan(){
  digitalWrite (trig3,LOW);
    delayMicroseconds(2);
    digitalWrite (trig3,HIGH);
    delayMicroseconds(20);
    digitalWrite (trig3,LOW);
    float Fdistance = pulseIn (echo3, HIGH);
    delay (10);
    Fdistance = Fdistance / 29 / 2;
    return(int) Fdistance;
  }
void setup(){
  pinMode (echo1, INPUT);
  pinMode (trig1, OUTPUT);
  pinMode (echo2, INPUT);
  pinMode (trig2, OUTPUT);
  pinMode (echo3, INPUT);
  pinMode (trig3, OUTPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  pinMode (enA, OUTPUT);
  pinMode (enB, OUTPUT);
  
 
 pinMode(outputPin, OUTPUT);
pinMode(sensorPin, INPUT);
   pinMode(BUZZER,OUTPUT);
  // digitalWrite(KIPAS,LOW);
   //digitalWrite(BUZZER,LOW);
  Serial.begin(9600);
}

void loop() {

jarak_kiri = test_jarakkiri();
delay(10);
tengah = test_jaraktengah();
delay (10);
jarak_kanan = test_jarakkanan();
delay(10);
// if(jarak_kiri==0){
  //  jarak_kiri=MAX;
  //}
  //if(tengah==0){
    //tengah=MAX;
  //}
  //if(jarak_kanan==0){
    //jarak_kanan=MAX;
  //}
Serial.println("jarak_kiri\tengah\jarak_kanan\status\n");
Serial.print("jarak_kiri");
Serial.print("cm\t\t");
Serial.print("tengah");
Serial.print("cm\t\t");

bacasensor = digitalRead(sensorPin);

if (bacasensor == LOW){
  stopp();
digitalWrite(outputPin, LOW);
delay(6000);
Serial.println("Terdeteksi Panas Api");
}
else {
   digitalWrite(outputPin, HIGH);
   Serial.println("Tidak Terdeteksi Panas Api");
      if(tengah<=15){//(jarak_kiri<=5 && tengah<=5 && jarak_kanan<=5){
        mundur();
      }
      else if((tengah<=35) && (jarak_kiri<=350)){
        belok_kanan();
      }
      else if((tengah<=35) && (jarak_kanan<=350)){
        belok_kiri();
      }
      else if(jarak_kiri<=35){
        belok_kanan();
      }
      else if(jarak_kanan<=35){
        belok_kiri();
      }
      //else if(tengah<=5){
      //  mundur();
      //}
else{
maju();
      }
  }
}
