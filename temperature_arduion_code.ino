#define RT0 10000   //ohm
#define B 3977     //K
//--------------------------
float a=A0;

#define VCC 5  //Supply voltage
#define R 10000   //R=10Kohm

//Variables
float RT, VR, ln, TX, T0, VRT;

void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  T0 = 25 + 273.15;     //temperature to from datasheet, conversion from Celcius to Kelvin
}

void loop() {
  VRT = analogRead(A0);     //Acquisition analog value of VRT
  VRT = (5.00 / 1023.00) * VRT;   //Conversion to voltage
  VR = VCC - VRT;
  RT = VRT / (VR / R);       //Resistance of RT

  ln = log(RT / RT0);
  TX = (1 / ((ln / B) + (1 / T0)));  //Temperature from thermistor
  
  TX = TX - 273.15;           //Conversion to Celcius

  Serial.print("Temperature:");
  Serial.print("\t");
  Serial.print(TX);
  Serial.print("C\t\t");
  Serial.print(TX + 273.15);     //Conversion to Kelvin
  Serial.print("K\t\t");
  Serial.print((TX * 1.8) + 32);   //conversion to Fahrenheit
  Serial.print("F");
  delay(1000);
  
}
