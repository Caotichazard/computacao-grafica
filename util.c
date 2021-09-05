#include "util.h"
int monitorH = 640;
int monitorW = 480; 


float windowH = 64.0;
float windowW = 48.0;


float worldH = 64.0;
float worldW = 48.0;


void printPoint(point* pointToPrint){
    printf("%f %f %f %d \n", pointToPrint->x, pointToPrint->y, pointToPrint->w, pointToPrint->color);
}

point* parsePoint(point* pointToParse){
    if(pointToParse->x > windowH){
        pointToParse->x = windowH;
    }

    if(pointToParse->x < -windowH){
        pointToParse->x = -windowH;
    }

    if(pointToParse->y > windowW){
        pointToParse->y = windowW;
    }

    if(pointToParse->y < -windowW){
        pointToParse->y = -windowW;
    }

    return pointToParse;
};


int getMonitorH (){
    return monitorH;
}
int getMonitorW (){
    return monitorW;
}

void setMonitorH (int newMonitorH){
    monitorH = newMonitorH;
}
void setMonitorW (int newMonitorW){
    monitorW = newMonitorW;
}



float getWindowH(){
    return windowH;
}
float getWindowW(){
    return windowW;
}

void setWindowH(float newWindowH){
    windowH = newWindowH;
}
void setWindowW(float newWindowW){
    windowW = newWindowW;
}



float getWorldH(){
    return worldH;
};
float getWorldW(){
    return worldW;
};

void setWorldH(float newWorldH){
    worldH = newWorldH;
};
void setWorldW(float newWorldW){
    worldW = newWorldW;

};