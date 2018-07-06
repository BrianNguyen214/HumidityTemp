#include <Arduino.h>
//need to include the dht library
#include <dht.h>

//the sensor is connected to a digital pin; in this case, it was digital pin #7
#define DHT11_PIN 7
#define Green 8
#define Red 4

//declare an instance of the dht object
dht DHT;

void setup() {
  Serial.begin(9600);
  delay(500);
  pinMode(Green,OUTPUT);
  pinMode(Red,OUTPUT);
  Serial.println("DHT11 Humidity & Temperature Sensor \n");
  delay(1000);
}

//the sensor read the humidity and temperature
//the goal of the algorithm is to read off the data the sensor gets and tell the
//user if the humidity is high (greater than or equal to 20 percent) by
//shining a green LED connected to the system; otherwise, it shines a red
//LED connected to the system

void loop() {

  //here we are just reading the digital pin of the sensor
  DHT.read11(DHT11_PIN);

  if (DHT.humidity >= 20.0){
    digitalWrite(Red,HIGH);
    digitalWrite(Green,LOW);
  }
  else{
    digitalWrite(Red,LOW);
    digitalWrite(Green,HIGH);
  }

  Serial.print("Current humidity = ");
  Serial.print(DHT.humidity);
  //the sensor reports the temperature in Celsius
  Serial.print(" & temperature = ");
  Serial.print(DHT.temperature);
  Serial.println(" C ");
  delay(3000);
}
