#include "display_visualiser.h"

void initDisplay(){
    Wire.begin();

    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("ERROR: Screen SSD1306 not found."));
        
        pinMode(LED_BUILTIN, OUTPUT);

        while(true) {
            digitalWrite(LED_BUILTIN, HIGH); delay(100);
            digitalWrite(LED_BUILTIN, LOW); delay(100);
        }
    }

    Serial.println(F("SUCCESS: Screen initialized successfully."));

    display.clearDisplay();
    delay(100);
}

void display_measurement(int measurement, std::optional<String> infoMsg){
    display.clearDisplay();
    display.setCursor(0, 0);
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);

    display.println(F("Moisture sensor"));
    display.println(F("---------------"));

    display.print(F("Moisture: "));
    display.print(measurement);
    display.println(F("%"));

    if(infoMsg.has_value()){
        display.println(F("-------------"));
        display.println(infoMsg.value());
        display.println(F("------------------"));
    }

    display.display();
}