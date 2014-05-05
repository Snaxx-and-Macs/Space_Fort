import processing.serial.*; //import the Serial library so can read from arudino input via serial communication
import spacebrew.*;

int end = 10;    // the number 10 is ASCII for linefeed (end of serial.println), later we will look for this to break up individual messages
String serial;   // declare a new string called 'serial' 
Serial port;  // The serial port, this is a new instance of the Serial class (an Object)

String server="sandbox.spacebrew.cc";
String name="highlands Amebias";
String description ="Client that sends and receives range messages. Range values go from 0 to 1023.";

Spacebrew sb;

int  a_1_val = 0;
int  a_2_val = 0;
int a_3_val = 0;
int a_4_val = 0;
int a_5_val = 0;
int a_6_val = 0;


void setup() {
  
  //serial reading code
  port = new Serial(this, Serial.list()[10], 9600); // initializing the object by assigning a port and baud rate (must match that of Arduino)
  port.clear();  // function from serial library that throws out the first reading, in case we started reading in the middle of a string from Arduino
  serial = port.readStringUntil(end); // function that reads the string from serial port until a println and then assigns string to our string variable (called 'serial')
  serial = null; // initially, the string will be null (empty)
  
  // instantiate the spacebrewConnection variable
  sb = new Spacebrew( this );

  // declare your publishers
  sb.addPublish( "a_1", "range", a_1_val ); 
  sb.addPublish( "a_2", "range", a_2_val ); 
  sb.addPublish( "a_3", "range", a_3_val ); 
  sb.addPublish( "a_4", "range", a_4_val ); 
  sb.addPublish( "a_5", "range", a_5_val ); 
  sb.addPublish( "a_6", "range", a_6_val ); 



  // connect!
  sb.connect(server, name, description );
  
}

void draw() {
  
  //if there is data coming from the serial port read it/ store it
  while (port.available() > 0) { 
    serial = port.readStringUntil(end);
  }
  
  //if the string is not empty, do this
  if (serial != null) {  
        //capsense Input form Arduino, each value is seperated and split depending on the ','
        //and then saved in seperate cells of the array so we can access each 
        String[] a_input = split(serial, ','); 
       //can help to print these to console at this point to check it's working
       println(a_input); 
      
      a_1_val = int(a_input[0]);
      if(a_1_val >100) {
        background(0,0,0);
        sb.send("a_1", a_1_val);
      }
      
       a_2_val = int(a_input[1]);
      if(a_2_val >100) {
        background(255,255,255);
        sb.send("a_2", a_2_val);
      }
      
       a_3_val = int(a_input[2]);
      if(a_3_val >100) {
        background(255,0,255);
        sb.send("a_3", a_3_val);
      }
      
       a_4_val = int(a_input[3]);
      if(a_4_val >100) {
        background(255,255,0);
        sb.send("a_4", a_4_val);
      }
      
       a_5_val = int(a_input[4]);
      if(a_5_val >100) {
        background(255,0,0);
        sb.send("a_5", a_5_val);
      }
      
       a_6_val = int(a_input[5]);
      if(a_6_val >100) {
        background(0,255,0);
        sb.send("a_6", a_6_val);
      }
        
  }
  
  
}
