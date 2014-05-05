
import processing.serial.*;

import cc.arduino.*;

Arduino arduino;

import spacebrew.*;

String server="sandbox.spacebrew.cc";
String name="Snaxx_n_macs_motionSensor";
String description ="Motion Sensor";

Spacebrew sb;

color off = color(4, 79, 111);
color on = color(84, 145, 158);

void setup() {
  size(470, 280);

  // instantiate the spacebrewConnection variable
  sb = new Spacebrew( this );

  // declare your publishers
  sb.addPublish( "motionSensor", "boolean", true );
  
  // connect to spacebre
  sb.connect(server, name, description );
  
  //----------motion sensor--------------
  arduino = new Arduino(this, Arduino.list()[8], 57600);
  arduino.pinMode(2, Arduino.INPUT);
}

void draw() {
  background(off);
  stroke(on);
  
  // Draw a filled box for each digital pin that's HIGH (5 volts).
  //for (int i = 0; i <= 13; i++) {
    if (arduino.digitalRead(2) == Arduino.HIGH){
      fill(on);
      sb.send( "motionSensor", true);
    }
    else {
      fill(off);
      sb.send( "motionSensor", false);
    }
      
    rect(420 - 2 * 30, 30, 20, 20);
  //}

  // Draw a circle whose size corresponds to the value of an analog input.
   noFill();
   
   print("sensor 2: ");
   println(arduino.digitalRead(2));
}
