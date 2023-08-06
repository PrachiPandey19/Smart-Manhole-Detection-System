#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial
#include <Blynk.h>
#include <ESP8266WiFi.h>
char auth[] = BLYNK_AUTH_TOKEN;         
char ssid[] = "";  
char pass[] = "";     
WidgetLED led(V0);         
void setup() {        
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  Blynk.begin(auth, ssid, pass,"blr1.blynk.cloud"); "blr1.blynk.cloud" to connect to the banglore server 
    while (WiFi.status() != WL_CONNECTE
  {
    delay(500);
    Serial.print("."); 
  }
  Serial.println("");
  Serial.println("WiFi connected");
  server.begin();
  Serial.println("Server started");
  Serial.println(WiFi.localIP());  
  
}

void loop() {
  Blynk.run();
  float mgswitch=0,ultrasonic=0,gassensor=0;
 
  if(Serial.available()>0)
  {
   String data=Serial.readStringUntil('\n');  
   String a[]={" "," "," "};
   int i=0;int c=0;
    while (c<data.length()) {      
      if(data.charAt(c)==','){
      i++;c++;
      }
        a[i]+=data.charAt(c);
        c++;
    }
    mgswitch=a[0].toFloat();
    ultrasonic=a[1].toFloat();
    gassensor=a[2].toFloat();
  }
  Serial.println(mgswitch);
  Serial.println(ultrasonic);
  Serial.println(gassensor);
  Blynk.virtualWrite(V1, ultrasonic);   virtual pin 1 (V1)
  Blynk.virtualWrite(V2, gassensor);  virtual pin 1 (V1)
  if(mgswitch==0)
  led.off();
  else
  led.on();
  delay(500);
}
