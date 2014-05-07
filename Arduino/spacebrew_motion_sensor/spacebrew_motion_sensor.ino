int pirPin = 2; //digital 2

void setup(){
 Serial.begin(9600); 
 pinMode(pirPin, INPUT);
}


void loop(){
  int pirVal = digitalRead(pirPin);

  //Serial.println(pirVal); 
  
  if(pirVal == HIGH){ //was motion detected
    Serial.println("Motion Detected"); 
    Serial.print("pirVal: ");
    Serial.println(pirVal); 
    delay(2000); 
  }

}
