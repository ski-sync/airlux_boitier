#include "CharacteristicCallbacks.h"
#include "WiFi.h"

int splitSsidPassword(std::string chaine, char caractere)
{
    std::string ssid = "";
    std::string password = "";
    int compteur = 0;
    for (int i = 0; i < chaine.length(); i++)
    {
        if (chaine[i] == caractere)
        {
            compteur++;
        }
        if (compteur == 0)
        {
            ssid = ssid + chaine[i];
        }
        else
        {
            password = password + chaine[i];
        }
    }
    return compteur;
}

void disableBluetooth()
{
    esp_bt_controller_disable();
    esp_bt_controller_deinit();
}

void CharacteristicCallbacks::onWrite(BLECharacteristic *pCharacteristic)
{
    std::string rxValue = pCharacteristic->getValue();
    if (rxValue.length() > 0)
    {
        Serial.println("Received Value: ");
        for (int i = 0; i < rxValue.length(); i++)
            Serial.print(rxValue[i]);

        Serial.println();

        String received_value = rxValue.c_str();
        char password[100] = "";
        char ssid[100] = "";

        int scanned = sscanf(received_value.c_str(), "SSID:%[^;];Mot_de_passe:%[^;];", &ssid, &password);

        if (scanned == 2)
        {
            disableBluetooth();

            WiFi.begin(ssid, password);

            while (WiFi.status() != WL_CONNECTED)
            {
                Serial.print(".");
                delay(100);
            }
            
            Serial.println("\nConnected to WiFi");

            pCharacteristic->setValue("\nConnected");
            pCharacteristic->notify();
        }
    }
}

int CharacteristicCallbacks::compterCaracteres(std::string rxV, char sep)
{
    int count = 0;
    for (int i = 0; i < sizeof(rxV); i++)
    {
        if (rxV[i] == sep)
        {
            count++;
        }
    }
    if (count == 1)
    {
        return 1;
    }
    return 0;
}

String CharacteristicCallbacks::getValue(String data, String key, String separator)
{
    int keyIndex = data.indexOf(key);
    if (keyIndex == -1)
    {
        return "";
    }

    int startIndex = keyIndex + key.length();
    int separatorIndex = data.indexOf(separator, startIndex);
    if (separatorIndex == -1)
    {
        return "";
    }

    return data.substring(startIndex, separatorIndex);
}
