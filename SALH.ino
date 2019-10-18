#include <IRremote.h>
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
int x;
int a=1;
int b=1;
int c=1;
int d=1;
int e=1;
int f=1;
int senserPin = A1;
int reading;
float voltage;
float temperatureC;
 int Buzzer = 10;
  int Pin1 = 9;
  int Pin2 = A0;
int Sensor = 400;
void setup()
{
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); 
  Serial.println("Enabled IRin");
  pinMode(2,OUTPUT);
   pinMode(3,OUTPUT);
   pinMode(4,OUTPUT); 
   pinMode(5,OUTPUT); 
   pinMode(6,OUTPUT);
   pinMode(7,OUTPUT);
    pinMode(8,OUTPUT);
     digitalWrite(2,HIGH);
      digitalWrite(3,HIGH);
       digitalWrite(4,HIGH);
        digitalWrite(5,HIGH);
         digitalWrite(6,HIGH);
          digitalWrite(7,HIGH);
          pinMode(Pin1,INPUT);  
pinMode(Pin2,INPUT);
pinMode(Buzzer,OUTPUT); 
}

void loop() {

  
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
   
    if(results.value== 543002735){
      if(a==0){
      digitalWrite(2,HIGH);
      a=1;
      }
      else{
      digitalWrite(2,LOW);
      a=0;
      }
      }
       if(results.value== 543012935 ){
     if(b==0){
      digitalWrite(3,HIGH);
      b=1;
      }
      else{
      digitalWrite(3,LOW);
      b=0;
      }
      }
       if(results.value== 543029255 ){
 if(c==0){
      digitalWrite(4,HIGH);
      c=1;
      }
      else{
      digitalWrite(4,LOW);
     c=0;
      }
      }
       if(results.value== 543010895  ){
      if(d==0){
      digitalWrite(5,HIGH);
      d=1;
      }
      else{
      digitalWrite(5,LOW);
      d=0;
      }
      }
       if(results.value== 543004775  ){
     if(e==0){
      digitalWrite(6,HIGH);
      e=1;
      }
      else{
      digitalWrite(6,LOW);
      e=0;
      }
      }
       if(results.value== 543021095 ){
   if(f==0){
      digitalWrite(7,HIGH);
      f=1;
      }
      else{
      digitalWrite(7,LOW);
      f=0;
      }
      }
    irrecv.resume(); 
    
  }


 reading = analogRead(senserPin);
voltage =  reading *5.0/ 1024;
//Serial.print(voltage);
//Serial.println("volts");
temperatureC = (voltage)*100;
Serial.println(temperatureC);
// delay(400);
if(temperatureC>40){
  digitalWrite(8,HIGH);
  delay(1000);
}
else{
   digitalWrite(8,LOW);
  }

int val1=digitalRead(Pin1);
  int val2=analogRead(Pin2);
  
  Serial.print(val2);
   Serial.println("rate");
if(val2>=Sensor)
{
  digitalWrite(Buzzer,HIGH);
   
}
else

{
digitalWrite(Buzzer,LOW);
}



}
