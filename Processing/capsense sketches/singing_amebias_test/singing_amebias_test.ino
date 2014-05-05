
#include <CapacitiveSensor.h>

CapacitiveSensor   a_1 = CapacitiveSensor(3,2);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   a_2 = CapacitiveSensor(5,4);        // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
CapacitiveSensor   a_3 = CapacitiveSensor(7,6);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
CapacitiveSensor   a_4 = CapacitiveSensor(9,8); 
CapacitiveSensor   a_5 = CapacitiveSensor(11,10); 
CapacitiveSensor   a_6 = CapacitiveSensor(13,12); 

void setup()                    
{
   cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
}

void loop()                    
{
    long start = millis();
    long total1 =  cs_4_2.capacitiveSensor(30);
    long total2 =  cs_4_6.capacitiveSensor(30);
    long total3 =  cs_4_8.capacitiveSensor(30);

//    Serial.print(millis() - start);        // check on performance in milliseconds
//    Serial.print("\t");                    // tab character for debug windown spacing
//
//    Serial.print(total1);                  // print sensor output 1
//    Serial.print("\t");
//    Serial.print(total2);                  // print sensor output 2
//    Serial.print("\t");
//    Serial.println(total3);                // print sensor output 3

  Serial.print(total1, DEC); 
  Serial.print(",");
  Serial.print(total2, DEC);
  Serial.print(",");
  Serial.print(total3, DEC);
  Serial.print(",");
   Serial.print(total1, DEC); 
  Serial.println();

    delay(100);                             // arbitrary delay to limit data to serial port 
}
