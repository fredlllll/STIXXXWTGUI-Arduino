/**********************************************************************************************
 * Arduino STIXXXWTGUI Library - Version 1.0.0
 * by Frederik Gelder <frederik.gelder@freenet.de>
 *
 * Copyright 2015 Frederik Gelder
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 **********************************************************************************************/

#include <STIXXXWTGUI.h>

void STIXXXWTGUIhandleTouchPressHold(void* arg, uint8_t *data, int16_t len){
    STIXXXWTGUI* gui = (STIXXXWTGUI*)arg;
    point p = *(point*)(data+2);
    gui->handleTouchPressHold(p);
}

void STIXXXWTGUIhandleTouchRelease(void* arg, uint8_t *data, int16_t len){
    STIXXXWTGUI* gui = (STIXXXWTGUI*)arg;
    point p = *(point*)(data+2);
    gui->handleTouchRelease(p);
}

STIXXXWTGUI::STIXXXWTGUI(size_t capacity): elements(capacity){
    
}

void STIXXXWTGUI::begin(STIXXXWT* display){
    _display=display;
    display->setCommandListener(STIXXXWT::touchPressHold,&STIXXXWTGUIhandleTouchPressHold,this);
	display->setCommandListener(STIXXXWT::touchRelease,&STIXXXWTGUIhandleTouchRelease,this);
}

void STIXXXWTGUI::handleTouchPressHold(point p){
    if(!fingerDown){
        fingerDown = true;
        for(int i =0; i< elements.size();i++){
            elements[i]->handleFingerDown(p);
            elements[i]->handleFingerHold(p);
        }
    }else{
        for(int i =0; i< elements.size();i++){
            elements[i]->handleFingerHold(p);
        }
    }
}

void STIXXXWTGUI::handleTouchRelease(point p){
    fingerDown = false;
    for(int i =0; i< elements.size();i++){
        elements[i]->handleFingerUp(p);
    }
}

void STIXXXWTGUI::loop(){
    for(int i =0; i< elements.size();i++){
        elements[i]->loop();
    }
}

void STIXXXWTGUI::draw(){
    for(int i =0; i< elements.size();i++){
        elements[i]->draw();
    }
}

void STIXXXWTGUI::addElement(GUIElement* e){
    elements.push_back(e);
}

void STIXXXWTGUI::removeElement(GUIElement* e){
    elements.erase(e);
}
