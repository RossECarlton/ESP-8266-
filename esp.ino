#include <SoftwareSerial.h>
SoftwareSerial ESPserial(2, 3); // RX | TX
 
void setup() 
{
  pinMode(13, OUTPUT); //setup led
  
    Serial.begin(115200);     // communication with the host computer
    ESPserial.begin(115200);
    while (!Serial)   { ; }
    delay(2000);
 
   ESPserial.write("AT+RST\r\n");
   if ( ESPserial.available() )   {  Serial.write( ESPserial.read() );  }
   delay(1000);
  ESPserial.write("AT+CWMODE=2\r\n");
  if ( ESPserial.available() )   {  Serial.write( ESPserial.read() );  }
   
  delay(1000);
   
   ESPserial.write("AT+CIPMUX=1\r\n");
   if ( ESPserial.available() )   {  Serial.write( ESPserial.read() );  }
  
  delay(1000);
   ESPserial.write("AT+CIPSERVER=1,80\r\n");
  if ( ESPserial.available() )   {  Serial.write( ESPserial.read() );  }

    
   
  
  delay(1000);
   
   ESPserial.write('AT+CWSAP="CA","1234test",5,2');

  
    
 
    Serial.println("");
    Serial.println("Remember to to set Both NL & CR in the serial monitor.");
    Serial.println("Ready");
    Serial.println("");    
}
   
 
void loop() 
{

  
    // listen for communication from the ESP8266 and then write it to the serial monitor
    if ( ESPserial.available() )   {  Serial.write( ESPserial.read() );  }
 
    // listen for user input and send it to the ESP8266
    if ( Serial.available() )       {  ESPserial.write( Serial.read() ); }
    

    
}



