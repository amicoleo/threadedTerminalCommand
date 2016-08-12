//
//  GetImageEmotionThread.hpp
//  uploadImageOnline
//
//  Created by Leonardo Amico on 11/08/2016.
//
//

#ifndef GetImageEmotionThread_hpp
#define GetImageEmotionThread_hpp

#include "ofMain.h"

class GetImageEmotionThread: public ofThread{
public:
    
    GetImageEmotionThread(){
        requestSent = false;
    }
    void sendRequest(string _imageFilename){
        imageFilename = _imageFilename;
        requestSent = true;
        this->startThread();
        
    }
    bool isResponseArrived(){
        if (!this->isThreadRunning() && requestSent) {
            requestSent = false;
            return true;
        }
        return false;
    }
    string getResponse(){
        return response;
    }
    
private:
    void threadedFunction(){
        //Do python stuff
        ofDisableDataPath();
        response = ofSystem("python imageEmotion.py "+imageFilename);
        ofEnableDataPath();

    }
    string response;
    bool requestSent;
    string imageFilename;
    
};

#endif /* GetImageEmotionThread_hpp */
