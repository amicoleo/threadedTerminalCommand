#include "ofMain.h"

#include "GetImageEmotionThread.hpp"
#include "ofxJSON.h"

class ofApp : public ofBaseApp{

public:

    void setup();
    void update();
    void draw();

    void keyPressed  (int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    
    GetImageEmotionThread imageEmotion;
    
    ofImage photo, emotionPhoto;
    ofVideoGrabber grabber;
    string faceEmotion;
    
};

