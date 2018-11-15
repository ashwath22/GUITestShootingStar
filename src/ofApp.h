#pragma once

/*
 This example demonstrates the particles emmiter
 with attraction and spinning forces,
 and also with friction.
 
 It's the example 03-ParticlesForces from the book
 "Mastering openFrameworks: Creative Coding Demystified",
 Chapter 3 - Building a Simple Particle System
 */

#include "ofMain.h"
#include "ofxGui.h"


//Particle class
class Particle {
public:
    Particle();                //Class constructor
    void setup();              //Start particle
    void update( float dt );   //Recalculate physics
    void draw();               //Draw particle
    
    ofParameterGroup particleParameters;
//    ofParameter<ofPoint> pos; //position
//    ofParameter<ofPoint> vel; //velocity
//    ofParameter<float> time; //time of living
//    ofParameter<float> lifeTime; //allowed lifetime
    bool live;                 //Is particle live
    ofPoint pos;               //Position
    ofPoint vel;               //Velocity
    float time;                //Time of living
    float lifeTime;            //Allowed lifetime
    
};

//Control parameters class
class Params {
public:
    void setup();
    ofParameterGroup paramParameters;
    ofPoint eCenter; //Emitter center
    ofParameter<float> eRad; //Emitter radius
    ofParameter<float> velRad; //Initial velocity limit
    ofParameter<float> lifeTime;     //Lifetime in seconds
    
    ofParameter<float> rotate;   //Direction rotation speed in angles per second
    
    ofParameter<float> force;       //Attraction/repulsion force inside emitter
    ofParameter<float> spinning;    //Spinning force inside emitter
    ofParameter<float> friction;    //Friction, in the range [0, 1]

    
//    ofPoint eCenter;    //Emitter center
//    float eRad;         //Emitter radius
//    float velRad;       //Initial velocity limit
//    float lifeTime;     //Lifetime in seconds
//
//    float rotate;   //Direction rotation speed in angles per second
//
//    float force;       //Attraction/repulsion force inside emitter
//    float spinning;    //Spinning force inside emitter
//    float friction;    //Friction, in the range [0, 1]
};

extern Params params; //Declaration a of global variable


//openFrameworks' class
class ofApp : public ofBaseApp{
    public:
        void setup();
        void update();
        void draw();
        ofFbo fbo;            //Off-screen buffer for trails
        vector<Particle> p;      //Particles
    
//        float history;        //Control parameter for trails
//        float bornRate;       //Particles born rate per second
//        float bornCount;      //Integrated number of particles to born
    
        float time0;          //Time value for computing dt
        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y);
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
        void clearScreen();

    ofxPanel gui;
    ofxButton clear;
    
    ofParameter<float> history;        //Control parameter for trails
    ofParameter<float> bornRate;       //Particles born rate per second
    ofParameter<float> bornCount;      //Integrated number of particles to born
    ofParameterGroup parameterGroup;   //ofParameterGroup appParameters;
    ofParameterGroup parameterGroup2;   //ofParameterGroup appParameters;
    
    ofEasyCam cam;
};
