#ifndef Hackiebox_h
#define Hackiebox_h

#include "BaseHeader.h"

#include <ThreadController.h>

#include <hw_ints.h>
#include <driverlib/wdt.h>
#include <driverlib/rom_map.h>
#include <driverlib/prcm.h>

#include "BoxAccelerometer.h"
#include "BoxBattery.h"
#include "BoxButtonEars.h"
#include "BoxDAC.h"
#include "BoxEvents.h"
#include "BoxLEDs.h"
#include "BoxPower.h"
#include "BoxRFID.h"
#include "BoxSD.h"

#include "WrapperWiFi.h"
#include "WrapperWebServer.h"

#include "LogStream.h"

class Hackiebox { 
    public:

        void
            setup(),
            loop();
        
        bool
            watchdog_start(),
            watchdog_isFed();
        void
            watchdog_stop(),
            watchdog_feed(),
            watchdog_unfeed();


        BoxAccelerometer boxAccel;
        BoxBattery boxBattery;
        BoxButtonEars boxEars; 
        BoxDAC boxDAC;
        BoxLEDs boxLEDs;
        BoxPower boxPower;
        BoxRFID boxRFID;
        BoxSD boxSD;
        WrapperWiFi boxWiFi;
        WrapperWebServer webServer;

        LogStream logStream;

    private:/*
        typedef void (*fAPPWDTDevCallbk)();
        void 
            watchdog_handler();*/
        
        bool _watchdog_fed;
        ThreadController _threadController;
};
extern Hackiebox Box;

#endif
