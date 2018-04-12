
#define DEBUG false

#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>




ESP8266WiFiMulti WiFiMulti;
String urlJam = "http://ristie.ub.ac.id/io/dokter/jam.txt";
String urlBuka = "http://ristie.ub.ac.id/io/dokter/buka.txt";
String urlRaw = "http://ristie.ub.ac.id/io/dokter/raw.txt";
String dataBuka, dataJam, dataRaw, dataBukaBaru, dataJamBaru, dataRawBaru;
unsigned long previousMillis = 0;
long interval = 20000;

char *ssid = "Re;LieF";
char *pass = "test1234";

void setup() {

  Serial.begin(115200);
  pinMode(0,OUTPUT);

delay (1000);
  Serial.println();
  Serial.print ("#MMenghubungkan ke ");
  Serial.println (ssid);

  for (uint8_t t = 4; t > 0; t--) {
    //Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(ssid, pass);

}

void loop() {
  getData();
  cek();
  delay(500);
    unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;   

    if(dataBuka=="1")
    {
    String jam = "#MBuka Sampai Jam " + dataJamBaru + " ";
    Serial.println(jam);
    }
    
  }
  

}
void getData()
{
  // cek WiFI
  if ((WiFiMulti.run() == WL_CONNECTED)) {
    HTTPClient http;
    if (DEBUG) Serial.print("[HTTP] begin...\n");
    http.begin(urlJam); //HTTP
    if (DEBUG) Serial.print("[HTTP] GET...\n");
    int httpCode = http.GET();
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      if (DEBUG) Serial.printf("[HTTP] GET... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK) {
        dataJamBaru = http.getString();
      }
    } else {
      if (DEBUG) Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }

  if ((WiFiMulti.run() == WL_CONNECTED)) {
    HTTPClient http;
    if (DEBUG) Serial.print("[HTTP] begin...\n");
    http.begin(urlBuka); //HTTP
    if (DEBUG) Serial.print("[HTTP] GET...\n");
    int httpCode = http.GET();
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      if (DEBUG) Serial.printf("[HTTP] GET... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK) {
        dataBukaBaru = http.getString();
        if (DEBUG) Serial.println(dataBukaBaru);
      }
    } else {
      if (DEBUG) Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }
  
  if ((WiFiMulti.run() == WL_CONNECTED)) {
    HTTPClient http;
    if (DEBUG) Serial.print("[HTTP] begin...\n");
    http.begin(urlRaw); //HTTP
    if (DEBUG) Serial.print("[HTTP] GET...\n");
    int httpCode = http.GET();
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      if (DEBUG) Serial.printf("[HTTP] GET... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK) {
        dataRawBaru = http.getString();
      }
    } else {
      if (DEBUG) Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }
}

void cek()
{
  if (DEBUG) Serial.println(dataJamBaru);
  if (DEBUG) Serial.println(dataJam);
  if (DEBUG) Serial.println(dataBukaBaru);
  if (DEBUG) Serial.println(dataBuka);
  if (DEBUG) Serial.println(dataRaw);
  if (DEBUG) Serial.println(dataRawBaru);

    if (dataBukaBaru != dataBuka)
  {
    String buka = "#b" + dataBukaBaru;
    Serial.println(buka);
    dataBuka = dataBukaBaru;
  }
  delay(100);
  
  if (dataJamBaru != dataJam)
  {
    String jam = "#MBuka Sampai Jam " + dataJamBaru + " ";
    Serial.println(jam);
    dataJam = dataJamBaru;
  }
  delay(100);
  
  if (dataRawBaru != dataRaw)
  {
    String raw = "#" + dataRawBaru;
    Serial.println(raw);
    dataRaw = dataRawBaru;
  }
  
  if (dataBuka=="1")
  {
    digitalWrite(0,LOW);
    //Serial.println("D LOW");
  } else {
    digitalWrite(0,HIGH);
    
    //Serial.println("D HIGH");
  }
}

