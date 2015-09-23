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
#ifndef LABEL_h
#define LABEL_h

#include <STIXXXWTGUI.h>

class label : public GUIElement{
public:
    fontType font;
    bool useForegroundColor,useBackgroundColor,horizontalDisplay,recoverBackground;
    textEncoding encoding;
    characterSize size;
    color16 foreground,background;

    label(){
        font = STIXXXWT::font6_12;
    }
    
    void init(rectangle area, wchar_t *text, uint16_t textlen, STIXXXWTGUI *gui){
        visible = true;
        this->area = area;
        this->gui = gui;
        this->text = text;
        this->textlen = textlen;
    }

    point sourceTopLeft;
    void handleFingerDown(point p){}
    void handleFingerUp(point p){}
    void handleFingerHold(point p){}
    void loop(){}
    void draw(){
        gui->display()->displayText(area.topLeft, font, useForegroundColor, useBackgroundColor, horizontalDisplay, recoverBackground, encoding, size, foreground, background, text, textlen);
    }
    
    void setText(wchar_t *text,uint16_t textlen){
        this->text = text;
        this->textlen = textlen;
    }
private:
    wchar_t *text;
    uint16_t textlen;
};

#endif