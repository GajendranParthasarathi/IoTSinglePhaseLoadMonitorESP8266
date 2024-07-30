#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <PZEM004Tv30.h>
#include <Wire.h>

PZEM004Tv30 pzem(D1, D2);
PZEM004Tv30 pzem1(D3, D4);   
PZEM004Tv30 pzem2(D5, D6);
PZEM004Tv30 pzem3(D7, D8); 
PZEM004Tv30 pzem4(D9, D10);

//#define WIFI_SSID "PGCJio"
//#define WIFI_PASSWORD "987654321"
#define WIFI_SSID "PGCJio"
#define WIFI_PASSWORD "987654321"
//#define WIFI_SSID "KCEDHRUVA22"
//#define WIFI_PASSWORD "eeed2022"

void setup() {
 Serial.begin(9600);
 pinMode(LED_BUILTIN,OUTPUT);
 WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
 Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
   
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  digitalWrite(LED_BUILTIN,0);
   delay(15000);
  digitalWrite(LED_BUILTIN,1);
}
void loop() {
  if(WiFi.status()== WL_CONNECTED){
        
      WiFiClient client;
      HTTPClient http;    //Declare object of class HTTPClient 
                                                                                  /* after 4000 count or 800 milli seconds (0.8 second), do the calculation and display value*/
    float voltage1 = pzem.voltage();
    float current1 = pzem.current();
    float power1 = pzem.power();
    float energy1 = pzem.energy();
    float frequency1 = pzem.frequency(); 
    float pf1= pzem.pf(); 

    float voltage2 = pzem1.voltage();
    float current2 = pzem1.current();
    float power2 = pzem1.power();
    float energy2= pzem1.energy();
    float frequency2 = pzem1.frequency(); 
    float pf2 = pzem1.pf();

    float voltage3 = pzem2.voltage();
    float current3 = pzem2.current();
    float power3 = pzem2.power();
    float energy3 = pzem2.energy();
    float frequency3 = pzem2.frequency(); 
    float pf3 = pzem2.pf();

    float voltage4 = pzem3.voltage();
    float current4 = pzem3.current();
    float power4 = pzem3.power();
    float energy4 = pzem3.energy();
    float frequency4 = pzem3.frequency(); 
    float pf4 = pzem3.pf();

    float voltage5 = pzem4.voltage();
    float current5 = pzem4.current();
    float power5 = pzem4.power();
    float energy5 = pzem4.energy();
    float frequency5 = pzem4.frequency(); 
    float pf5 = pzem4.pf();
    
String VoltagePost1,CurrentPost1,PowerPost1,FrequencyPost1,PowerFactorPost1,EnergyPost1,
       VoltagePost2,CurrentPost2,PowerPost2,FrequencyPost2,PowerFactorPost2,EnergyPost2,
       VoltagePost3,CurrentPost3,PowerPost3,FrequencyPost3,PowerFactorPost3,EnergyPost3,
       VoltagePost4,CurrentPost4,PowerPost4,FrequencyPost4,PowerFactorPost4,EnergyPost4,
       VoltagePost5,CurrentPost5,PowerPost5,FrequencyPost5,PowerFactorPost5,EnergyPost5,postData;

 double Voltage=voltage1;
 double  Current=current1;
  double  Power=power1;
   double  Frequency=frequency1;
   double  PowerFactor=pf1;
   double  Energy=energy1;

    double Voltage1=voltage2;
 double  Current1=current2;
  double  Power1=power2;
   double  Frequency1=frequency2;
   double  PowerFactor1=pf2;
   double  Energy1=energy2;

    double Voltage2=voltage3;
 double  Current2=current3;
  double  Power2=power3;
   double  Frequency2=frequency3;
   double  PowerFactor2=pf3;
   double  Energy2=energy3;

    double Voltage3=voltage4;
 double  Current3=current4;
  double  Power3=power4;
   double  Frequency3=frequency4;
   double  PowerFactor3=pf4;
   double  Energy3=energy4;

    double Voltage4=voltage5;
 double  Current4=current5;
  double  Power4=power5;
   double  Frequency4=frequency5;
   double  PowerFactor4=pf5;
   double  Energy4=energy5;
   
delay(1000);
//Post Data
  VoltagePost1 = String(Voltage);  
  CurrentPost1 = String(Current);   
  PowerPost1 = String(Power);
  FrequencyPost1 = String(Frequency);
  PowerFactorPost1 = String(PowerFactor);
  EnergyPost1 = String(Energy);

   VoltagePost2 = String(Voltage1);  
  CurrentPost2 = String(Current1);   
  PowerPost2 = String(Power1);
  FrequencyPost2 = String(Frequency1);
  PowerFactorPost2 = String(PowerFactor1);
  EnergyPost2 = String(Energy1);

   VoltagePost3 = String(Voltage2);  
  CurrentPost3 = String(Current2);   
  PowerPost3 = String(Power2);
  FrequencyPost3 = String(Frequency2);
  PowerFactorPost3 = String(PowerFactor2);
  EnergyPost3 = String(Energy2);

   VoltagePost4 = String(Voltage3);  
  CurrentPost4 = String(Current3);   
  PowerPost4 = String(Power3);
  FrequencyPost4 = String(Frequency3);
  PowerFactorPost4 = String(PowerFactor3);
  EnergyPost4 = String(Energy3);

   VoltagePost5 = String(Voltage4);  
  CurrentPost5 = String(Current4);   
  PowerPost5 = String(Power4);
  FrequencyPost5 = String(Frequency4);
  PowerFactorPost5 = String(PowerFactor4);
  EnergyPost5= String(Energy4);
  
  postData ="Voltage1=" + VoltagePost1 + "&Current1=" + CurrentPost1 +"&Power1=" + PowerPost1+"&Frequency1=" + FrequencyPost1+"&PowerFactor1=" + PowerFactorPost1+"&Energy1=" + EnergyPost1+
            "&Voltage2=" + VoltagePost2 + "&Current2=" + CurrentPost2 +"&Power2=" + PowerPost2+"&Frequency2=" + FrequencyPost2+"&PowerFactor2=" + PowerFactorPost2+"&Energy2=" + EnergyPost2+
            "&Voltage3=" + VoltagePost3 + "&Current3=" + CurrentPost3 +"&Power3=" + PowerPost3+"&Frequency3=" + FrequencyPost3+"&PowerFactor3=" + PowerFactorPost3+"&Energy3=" + EnergyPost3+
            "&Voltage4=" + VoltagePost4 + "&Current4=" + CurrentPost4 +"&Power4=" + PowerPost4+"&Frequency4=" + FrequencyPost4+"&PowerFactor4=" + PowerFactorPost4+"&Energy4=" + EnergyPost4+
            "&Voltage5=" + VoltagePost5 + "&Current5=" + CurrentPost5 +"&Power5=" + PowerPost5+"&Frequency5=" + FrequencyPost5+"&PowerFactor5=" + PowerFactorPost5+"&Energy5=" + EnergyPost5;
 //http.begin(client,"http://pgcresearch.co.in/PG/KCE/StaffRoom_InsertDB.php");
 http.begin(client, "http://pgcresearch.co.in/PG/RengaIllam/InsertDBRegaIllamHall2.php");
// http.begin(client,"http://pgcresearch.co.in/PG/KCE/InsertDB.php");
 //http.begin(client,"http://pgcresearch.pavantech.in/KCEStaffRoom/InsertDB.php");
   
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");    //Specify content-type header
 
  int httpCode = http.POST(postData);   //Send the request
  String payload = http.getString();    //Get the response payload

 
  Serial.println(httpCode);   //Print HTTP return code
  Serial.println(payload);    //Print request response payload
  //Serial.println("Lamp_ID=" + Lamp_IDPost + "Status=" + StatusPost + "latitude=" + latitudePost +"longitude=" + longitudePost + "info=" + infoPost+"icon=" + iconPost);
  Serial.println("Voltage1=" + VoltagePost1 + "&Current1=" + CurrentPost1 +"&Power1=" + PowerPost1+"&Frequency1=" + FrequencyPost1+"&PowerFactor1=" + PowerFactorPost1+"&Energy1=" + EnergyPost1+
                 "&Voltage2=" + VoltagePost2 + "&Current2=" + CurrentPost2 +"&Power2=" + PowerPost2+"&Frequency2=" + FrequencyPost2+"&PowerFactor2=" + PowerFactorPost2+"&Energy2=" + EnergyPost2+
                 "&Voltage3=" + VoltagePost3 + "&Current3=" + CurrentPost3 +"&Power3=" + PowerPost3+"&Frequency3=" + FrequencyPost3+"&PowerFactor3=" + PowerFactorPost3+"&Energy3=" + EnergyPost3+
                 "&Voltage4=" + VoltagePost4 + "&Current4=" + CurrentPost4 +"&Power4=" + PowerPost4+"&Frequency4=" + FrequencyPost4+"&PowerFactor4=" + PowerFactorPost4+"&Energy4=" + EnergyPost4+
                 "&Voltage5=" + VoltagePost5 + "&Current5=" + CurrentPost5 +"&Power5=" + PowerPost5+"&Frequency5=" + FrequencyPost5+"&PowerFactor5=" + PowerFactorPost5+"&Energy5=" + EnergyPost5);

  http.end();  //Close connection

  delay(7000);  //Here there is 4 seconds delay plus 1 second delay below, so Post Data at every 5 seconds
 
          }
}
