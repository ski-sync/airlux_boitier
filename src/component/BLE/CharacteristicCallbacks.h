#ifndef CHARACTERISTIC_CALLBACKS_H
#define CHARACTERISTIC_CALLBACKS_H

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

class CharacteristicCallbacks : public BLECharacteristicCallbacks
{
    void onWrite(BLECharacteristic *pCharacteristic);
    int compterCaracteres(std::string rxV, char sep);
    std::string* splitssid(std::string ssid);
    String getValue(String data, String key, String separator);
};

#endif // CHARACTERISTIC_CALLBACKS_H