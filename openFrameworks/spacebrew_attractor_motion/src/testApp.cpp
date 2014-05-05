#include "testApp.h"
ofMesh mesh;
//--------------------------------------------------------------
void testApp::setup(){
    
    geode.loadMovie("geode.mov");
    geode.play();
    
    ofSetFrameRate(60);
    string host = Spacebrew::SPACEBREW_CLOUD; // "localhost";
    string name = "snaxx & macs attractors";
    string description = "It's amazing";
    
    spacebrew.addSubscribe("meebVal1", "range");// just typing "boolean" also works
    spacebrew.addSubscribe("meebVal2", "range");// just typing "boolean" also works
    spacebrew.addSubscribe("meebVal3", "range");// just typing "boolean" also works
    spacebrew.addSubscribe("motionSensor", "boolean");
    spacebrew.connect( host, name, description );
    Spacebrew::addListener(this, spacebrew);
    //something new here for git
}
//--------------------------------------------------------------
void testApp::update(){
    geode.update();
    
    
}
//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(255, 255, 255, 255);
    geode.draw(0, 0, ofGetWidth(), ofGetHeight());
    //ofSetColor(255, 255, 255, 255 );
    
    ofSetColor(255);
    
    //____initial attractor valuers/setup
    
    float a = 1.4;
    float b = 1.56;
    float c = 1.40 +sin(ofGetElapsedTimef());
    float d = -6.56;
    
    float x0, y0, x1, y1 = 0;
    x0 = y0 = x1 = y1 = 0;
    
    ///___options for key interaction with attractors-------
    
    
    
    if (A2Value > threshold){
        
        ofSetColor(255, 0, 255);
        
    }
    
    //cout<<A2Value<<endl;
    
    else if (A1Value > threshold){
        
        ofSetColor(255, 0, 255);
        
    }
    
    //cout<<A1Value<<endl;
    
    if(balloonValue > threshold){
        
        ofSetColor(255, 0, 255);
        
        
    }
    
    cout<<balloonValue<<endl;
    
    if (balloonValue < 20){
        ofSetColor(0);
    }
    
    
	//----drawing the attractor------
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofScale(150, 150, 200);
    
    if(motionSensor == true || (motionSensor == false && timer < timeAmount) ) {
        
        if (A2Value > threshold){
            ofSetColor(255, 0, 255);
        }
        else if (A1Value > threshold) {
            ofSetColor(0, 255, 255);
        } else if (balloonValue > threshold) {
            ofSetColor(0, 0, 255);
        }
        else {
            ofSetColor(255);
        }
    
        for (int i=0; i<numPoints; i++) {
        x1 = sin(a * y0) - cos(b * x0);
        y1 = sin(c * x0) - cos(d * y0);
        
        ofFill();
        ofLine(x1, y1, x1+0.01, y1);
        
        x0 = x1;
        y0 = y1;
        
        
    }
    } else if (motionSensor == false && timer > timeAmount) {
        ofSetColor(255, 255, 255, 255);
        ofSetBackgroundColor(255, 255, 255);
    }
}
//--------------------------------------------------------------
void testApp::onMessage( Spacebrew::Message & m ){
    if ( m.name == "meebVal1" ){
        //int sliderXValue = m.valueRange();
        A1Value = ofToInt(m.value);
        //cout << A1Value<< endl;
        
    }
    
    if ( m.name == "meebVal2" ){
        //int sliderXValue = m.valueRange();
        A2Value = ofToInt(m.value);
        //cout << A2Value << endl;
        
    }
    
    if ( m.name == "meebVal3" ){
        //int sliderXValue = m.valueRange();
        balloonValue = ofToInt(m.value);
        cout << balloonValue << endl;
        
    }
    
    if( m.name == "motionSensor"){
        
        //cout << "motionSensor: " << m.value << endl;
        
        if(m.value == "true"){
            motionSensor = true;
            cout << "moving" << endl;
            timerTrue = (int)ofGetElapsedTimef();
        } else if (m.value == "false") {
            cout << "notMoving" << endl;
            motionSensor = false;
            timer = (int)ofGetElapsedTimef()-timerTrue;
            cout << timer << endl;
        }
    }
}
//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if (key =='a'){
        
        flip = true;
        
    }
    
    else if(key == 'b'){
        
        add = true;
    }
    
}
//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    if (key =='a'){
        
        flip = false;
        
    }
    
    else if(key == 'b'){
        add = false;
    }
    
    
}
//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}
//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}
//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}
//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}
//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}
//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}
//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo info){
    
}