#include "Hackiebox.h"

void Hackiebox::setup() {  
    Log.init(LOG_LEVEL_VERBOSE, 115200);
    Log.info("Booting Hackiebox...");

    _boxPower.begin();
    _boxPower.setSdPower(true);
    _boxPower.setOtherPower(true);

    _boxLEDs.begin();
    _boxLEDs.testLEDs();

    _boxBattery.begin();
    _boxBattery.loop();

    _boxEars.begin();


    /*
    _wifi = WrapperWiFi(WIFI_SSID, WIFI_PASS);
    _wifi.begin();

    _server = WrapperWebServer();
    _server.begin();
    */

    Log.info("Hackiebox started!");
}

void Hackiebox::loop() {  
    _boxBattery.loop();
    _boxEars.loop();
    _boxPower.loop();
    //_server.handle();
}