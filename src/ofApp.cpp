
bool requesting = false;

#include "ofApp.h"
  
void ofApp::setup(){
    
	ofSetVerticalSync(true);
    
    grabber.setup(640, 480);
    photo.allocate(640, 480, OF_IMAGE_COLOR);
    
    faceEmotion = "";
    
}

  
void ofApp::update(){
    
    if (imageEmotion.isResponseArrived()){
        ofxJSONElement json = ofxJSONElement(imageEmotion.getResponse());
        cout<<"Emotion scores\n"<<json[0]["scores"]<<endl;
        float anger = json[0]["scores"]["anger"].asFloat();
        float disgust = json[0]["scores"]["disgust"].asFloat();
        float happiness = json[0]["scores"]["happiness"].asFloat();
        float surprise = json[0]["scores"]["surprise"].asFloat();
        
        faceEmotion = "anger: "+ofToString(anger)+" - disgust: "+ofToString(disgust)+" - happiness: "+ofToString(happiness)+" surprise: "+ofToString(surprise);
        
        
        requesting = false;
    }
    
    grabber.update();
    if (grabber.isFrameNew()) photo.setFromPixels(grabber.getPixels());

}

  
void ofApp::draw(){
    
    string info;
    if (requesting) {
        ofSetBackgroundColor(ofColor::blue);
        info = "Processing web request...";
    }
    else{
        ofSetBackgroundColor(ofColor::green);
        info = "Click mouse for analizing emotion on your face";
    }
    
    ofPushStyle();
    ofSetColor(ofColor::red);
    ofDrawBitmapString(info, 50, 20);
    ofDrawBitmapString(ofGetFrameRate(), 50, 40);
    ofDrawBitmapString(faceEmotion, 50, 60);
    ofPopStyle();
    
    emotionPhoto.draw(50, 70);
    photo.draw(50 + 640 + 10, 70, 320, 240);
}
  
void ofApp::keyPressed  (int key){
}

  
void ofApp::mouseMoved(int x, int y ){
}

  
void ofApp::mouseDragged(int x, int y, int button){
}

  
void ofApp::mousePressed(int x, int y, int button){
}

  
void ofApp::mouseReleased(int x, int y, int button){
    
    ofDisableDataPath();
    emotionPhoto = photo;
    emotionPhoto.save("photo.jpg"); //This returns ofDirectory: createDirectory() error - it's not meant to use the resource path
    ofEnableDataPath();
    imageEmotion.sendRequest("photo.jpg");
    requesting = true;
}

  
void ofApp::windowResized(int w, int h){

}

