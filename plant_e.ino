include <Adafruit_BMP085.h>
Adafruit_BMP085 bmp;
void setup() {
  Serial.begin(9600);
  if (!bmp.begin()) {
  Serial.println("Could not find a valid BMP085 sensor, check wiring!");
  while (1) {}
  }
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
}
  
void loop() {
  digitalWrite(D0,LOW);
  digitalWrite(D1,LOW);
    Serial.print("Temperature = ");
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");
    
    Serial.print("Pressure = ");
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");
    Serial.print("Altitude = ");
    Serial.print(bmp.readAltitude());
    Serial.println(" meters");

    Serial.print("Pressure at sealevel (calculated) = ");
    Serial.print(bmp.readSealevelPressure());
    Serial.println(" Pa");
    Serial.print("Real altitude = ");
    Serial.print(bmp.readAltitude(101500));
    Serial.println(" meters");
    
    Serial.println();
    delay(500);
    if(bmp.readTemperature()<25)
    {
      digitalWrite(D0,HIGH);
      digitalWrite(D1,LOW);
    }
    else if(bmp.readTemperature()>30)
    {
      digitalWrite(D0,LOW);
      digitalWrite(D1,HIGH);
    }
    else
    {
       digitalWrite(D0,HIGH);
      digitalWrite(D1,HIGH);
    }
}
