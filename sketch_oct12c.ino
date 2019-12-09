#include "DHT.h"
#define dht_apin A0
#define DHTPIN 2     // what pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11 
DHT dht(DHTPIN, DHTTYPE);
String voice;
int led1=8;
int led2=9;
int led3=10;
int led4=11;
void alloff()
{
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  
}
void allon()
{
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
}




void setup() {
  Serial.begin(9600);
  delay(500);
  Serial.println("dht11 HUMIDITY & TEMPERATURE SENSOR \n\n");
  delay(1000);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  dht.begin();

}

void loop() {
  while(Serial.available())
  {
    voice=Serial.readString();
    voice.toLowerCase();
    Serial.println(voice);
  }
if(voice=="all on") {allon();}
else if(voice == "all off" || voice=="all of" || voice == "call off") {alloff();}
else if(voice=="tv on") {Serial.println("HELLO");digitalWrite(led1,HIGH);}
else if(voice=="fan on") {digitalWrite(led2,HIGH);}
else if(voice=="computer on") {digitalWrite(led3,HIGH);}
else if(voice=="ac on") {digitalWrite(led4,HIGH);}

else if(voice=="tv off" || voice=="tv of") {digitalWrite(led1,LOW);}
else if(voice=="fan off" || voice=="fan of") {digitalWrite(led2,LOW);}
else if(voice=="computer off" || voice=="computer of") {digitalWrite(led3,LOW);}
else if(voice=="ac off" || voice=="ac of") {digitalWrite(led4,LOW);}

Serial.print("Current Humidity = ");
Serial.print(dht.readHumidity());
Serial.print("%");
Serial.print("Temperature = ");
Serial.print(dht.readTemperature());
Serial.println("C    ");
delay(3000);
voice="";



}
