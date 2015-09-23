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
#ifndef GUIELEMENT_h
#define GUIELEMENT_h

#include <STIXXXWTGUI.h>

class STIXXXWTGUI;

class GUIElement{
public:
    STIXXXWTGUI *gui;
    rectangle area;
    bool visible;
    
    //GUIElement(bool visible,rectangle area, STIXXXWTGUI *gui):gui(gui),area(area),visible(visible){}
    GUIElement(){}
    virtual void handleFingerDown(point p)=0;
    virtual void handleFingerUp(point p)=0;
    virtual void handleFingerHold(point p)=0;
    virtual void loop()=0;
    virtual void draw()=0;
};

#endif