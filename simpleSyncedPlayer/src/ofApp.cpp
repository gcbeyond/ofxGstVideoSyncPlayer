#include "ofApp.h"

#define MASTER_CLOCK_SYNC_PORT 12366 ///> The port that will be used from GStreamer for master-slave clock synchronization.
#define MASTER_OSC_RCV_PORT 12777 ///> The port that the master listens for incoming osc messages from the clients.
#define SLAVE_OSC_SND_PORT MASTER_OSC_RCV_PORT ///> The osc send port of the slave should be the same as the receive port of the master.
#define SLAVE_OSC_RCV_PORT 12789 ///> You can choose any valid port for the slave to receive. Be carefull to choose a different one if you have multiple clients running on the same machine.

//--------------------------------------------------------------
void ofApp::setup(){
    //ofSetLogLevel(OF_LOG_VERBOSE);

    ///> Call the appropriate init function depending on if you are on a master or a slave.
    ///> The IP should be the same in both cases and it refers to the IP the master is running.

    //player.initAsMaster("127.0.0.1", MASTER_CLOCK_SYNC_PORT, MASTER_OSC_RCV_PORT);
    player.initAsSlave("127.0.0.1", MASTER_CLOCK_SYNC_PORT, SLAVE_OSC_RCV_PORT, SLAVE_OSC_SND_PORT);
    player.load("fingers.mov");
    player.loop(true);
    player.play();
}

//--------------------------------------------------------------
void ofApp::update(){

    player.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    player.draw(ofPoint(0,0));

    ///>master
    //player.drawSubsection(0.0f, 0.0f, player.getWidth()/2.0f, player.getHeight(), 0.0f, 0.0f);
    ///>client
    //player.drawSubsection(0.0f, 0.0f, player.getWidth()/2.0f, player.getHeight(), player.getWidth()/2.0f, 0.0f);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    if( key == 'p' ){
        player.pause();
    }
    else if( key == 's' ){
        player.play();
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
