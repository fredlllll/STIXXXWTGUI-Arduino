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
#ifndef IMAGE_h
#define IMAGE_h

#include <STIXXXWTGUI.h>

class image : public GUIElement{
public:
    image(){}
    
    void init(uint16_t pictureID, point sourceTopLeft, rectangle area, STIXXXWTGUI *gui){
        visible = true;
        this->area = area;
        this->gui = gui;
        this->sourceTopLeft = sourceTopLeft;
        region = spriteSheetRegion(pictureID,rectangle(sourceTopLeft,point(sourceTopLeft.x+area.width(),sourceTopLeft.y+area.height())),gui);
        gui->addElement(this);
    }

    point sourceTopLeft;
    void handleFingerDown(point p){}
    void handleFingerUp(point p){}
    void handleFingerHold(point p){}
    void loop(){}
    void draw(){
        region.drawAt(area.topLeft);
    }
private:
    spriteSheetRegion region;
};

#endif