#include <SoftwareSerial.h>
int RST_PIN = 12;
SoftwareSerial gprsSerial(7, 8);

void setup(){
  Serial.begin(9600);
  Serial.print("Start "); 
}

void loop(){
  
  sendToServer();
}

void sendToServer() {
  
gprsSerial.begin(9600);
 
  Serial.println("Config SIM900...");
  delay(1000);
  Serial.println("Done!...");
  gprsSerial.flush();
   Serial.println("1!...");
  Serial.flush();

  // attach or detach from GPRS service 
  gprsSerial.println("AT+CGATT?");
  delay(100);
  toSerial();
Serial.println("2!...");

  // bearer settings
  gprsSerial.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");
  delay(500);
  toSerial();
Serial.println("3!...");
  // bearer settings
  gprsSerial.println("AT+SAPBR=3,1,\"APN\",\"INTERNET\"");
  delay(500);
  toSerial();
Serial.println("4!...");
  // bearer settings
  gprsSerial.println("AT+SAPBR=1,1");
  delay(500);
  toSerial();
  Serial.println("5!...");

  gprsSerial.println("AT+HTTPINIT");
   delay(1000); 
   toSerial(); 
   String url = "http://picosoftbd.com/savedata.php?Data=Hello World";
     Serial.println(url);
   // set http param value
   gprsSerial.println("AT+HTTPPARA=\"URL\",\""+url+"\"");
   delay(2000);
   toSerial();

   // set http action type 0 = GET, 1 = POST, 2 = HEAD
   gprsSerial.println("AT+HTTPACTION=0");
   delay(5000);
   toSerial();

   // read server response
   gprsSerial.println("AT+HTTPREAD"); 
   delay(1000);
   toSerial();

   gprsSerial.println("");
   gprsSerial.println("AT+HTTPTERM");
   toSerial();
   delay(500);

   gprsSerial.println("");
   delay(1000);
}

void toSerial()
{
  while(gprsSerial.available()!=0)
  {
    Serial.write(gprsSerial.read());
  }
}


void GSMRest() {
  digitalWrite(RST_PIN, LOW);
  delay(100);
  digitalWrite(RST_PIN, HIGH);
}
