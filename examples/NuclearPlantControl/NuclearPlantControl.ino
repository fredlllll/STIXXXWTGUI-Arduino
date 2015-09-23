

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

wchar_t testtext[] = L"Ola estas loco";

void setup(){
    display.connect(&Serial,19200);
    display.sendHandshake(); //get infos
    display.clearScreen();
    gui.begin(&display);
    
    imgtest.init(2,point(20,20),rectangle(0,0,20,20),&gui);
    lbltest.init(rectangle(point(100,100),point()),testtext,sizeof(testtext)/2,&gui);
    
    display->clear();
    gui.draw();
}

void loop(){
    display.loop();
    gui.loop();
}