#include <Arduino.h>
#include "class/sm.h"
#include "class/timer.h"
#include "component/BLE/BLEServerManager.h"
#include "WiFi.h"

Fsm fsm;
Timer timer;

void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  // Start the timer
  timer.start();

  // Initialize and set up BLE
  BLEServerManager::getInstance()->setup();
}

void loop()
{

  if (timer.elapsed() >= 1000 && WiFi.status() != WL_CONNECTED)
  {
    int n = WiFi.scanNetworks();
    if (n == 0)
    {
      Serial.println("no networks found");
    }
    else
    {
      if (n > 0)
      {

        String listWifi = "{\"SSID\" : [";
        if (n > 10)
        {
          n = 10;
        }

        for (int i = 0; i < n; ++i)
        {
          if (i != 0)
          {
            listWifi = listWifi + ",";
          }
          listWifi = listWifi + "\"" + WiFi.SSID(i) + "\"";
        }
        listWifi = listWifi + "]}";

        BLEServerManager::getInstance()->sendMessage(listWifi);
        Serial.println(listWifi);
      }
    }
    timer.start();
  }
}
