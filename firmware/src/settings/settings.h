#include <Arduino.h>
#include <Preferences.h>
#include <nvs_flash.h>

boolean getSettings(void);
void saveUsername(String newUserName);
void saveWifiSSID(String wifiSSID);
void saveWifiPassword(String wifiPassword);
void saveUI(bool useBLE);
void saveTxPower(int txPower);
void saveLoraFrq(int loraFrq);
void saveSpreadingFactor(int spreadFactor);
void saveDutyCycle(double dutyCycle);
void saveInterval(long interval);
void saveGPS(long period);

extern String username;
extern String wifiSSID;
extern String wifiPassword;
extern bool useBLE;
extern int txPower;
extern int loraFrq;
extern int spreadingFactor;
extern double dutyCycle;
extern long routeInterval;
extern long beaconPeriod;
