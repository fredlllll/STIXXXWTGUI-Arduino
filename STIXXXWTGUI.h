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

#ifndef STIXXXWTGUI_h
#define STIXXXWTGUI_h
#define LIBRARY_VERSION    1.0.0
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
#include <stdint.h>
#include <STIXXXWT.h>
#ifndef STIXXXWT_h
 #error Please include the STIXXXWT.h file directly in your sketch or this library will not work
#endif
#include <simplevector.h>
#include <GUIElement.h>

class STIXXXWTGUI
{
  public:
    STIXXXWTGUI(size_t capacity = 10);
    
    void begin(STIXXXWT *display);
    
    void handleTouchPressHold(point p);
    void handleTouchRelease(point p);
    
    void loop();
    void draw();
    STIXXXWT *display(){return _display;}
  private:
    STIXXXWT *_display;
    simplevector<GUIElement*> elements;
    bool fingerDown;
};

struct spriteSheetRegion{
    uint16_t pictureID;
    rectangle area;
    STIXXXWTGUI *gui;
    
    spriteSheetRegion(){}
    spriteSheetRegion(uint16_t pictureID,rectangle area,STIXXXWTGUI* gui):pictureID(pictureID),area(area),gui(gui){}
    spriteSheetRegion(const spriteSheetRegion& other):pictureID(other.pictureID),area(other.area),gui(other.gui){}
    
    void drawAt(point at){
        gui->display()->displayImagePartAt(0x71, pictureID, area.topLeft, area.bottomRight, at);
    }
};

#endif

