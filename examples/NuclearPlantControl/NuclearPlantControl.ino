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
#include <STIXXXWT.h>
#include <STIXXXWTGUI.h>
#include <image.h>
#include <label.h>

STIXXXWT display;
STIXXXWTGUI gui;
image imgtest;
label lbltest;

char testtext[] = "Lächeln bitte"; //should be utf8

void setup(){
    display.connect(&Serial1,115200);
    delay(200);
    display.sendHandshake(); //get infos
    display.clearScreen();
    gui.begin(&display);
    
    imgtest.init(2,point(100,100),rectangle(50,50,20,20),&gui);
    lbltest.init(rectangle(point(100,100),point()),testtext,&gui);
    lbltest.encoding = STIXXXWT::UTF16Unicode;
    lbltest.font = STIXXXWT::font6_12;
    lbltest.size = STIXXXWT::size48_96;
    lbltest.foreground = color16(255,255,0);
    lbltest.background = color16();
    
    display.clearScreen();
    gui.draw();
}

void loop(){
    display.loop();
    gui.loop();
}
