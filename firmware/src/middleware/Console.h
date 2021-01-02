#ifndef CONSOLE_H
#define CONSOLE_H

#include "../DisasterMiddleware.h"
#include "../DisasterClient.h"
#ifndef SIM
#include "../DisasterHistory.h"
#endif

#include <vector>
#include <string>

class Console : public DisasterMiddleware
{
#ifndef SIM
  String username = "";
  String buffer = "";
  DisasterHistory *history = NULL;
#endif

public:
#ifdef SIM
    Console();
#else
    Console(DisasterHistory *h = NULL)
        : DisasterMiddleware(), history(h){};
#endif
    void printf(const char* format, ...);

    void setup();

    void usage();
    void getUsage();
    void uiUsage();
    void wifiSSIDUsage();
    void wifiPasswordUsage();
    void txpowerUsage();
    void lorafrqUsage();
    void sfUsage();
    void dutyUsage();
    void intervalUsage();
    void gpsUsage();
    void setUsage();

    void get(std::vector<char *> args);

    void uiSet();
    void wifiSSIDSet(std::vector<char *> args);
    void wifiPasswordSet(std::vector<char *> args);
    void txpowerSet(std::vector<char *> args);
    void lorafrqSet(std::vector<char *> args);
    void sfSet(std::vector<char *> args);
    void dutySet(std::vector<char *> args);
    void intervalSet(std::vector<char *> args);
    void gpsSet(std::vector<char *> args);
    void set(std::vector<char *> args);

    void transmit(DisasterClient *client, struct Datagram datagram, size_t len);
    void receive(struct Datagram datagram, size_t len);

private:
    void processLine(char *message, size_t len);
    void printBanner();
    void printPrompt();

    int sessionConnected;
};

#endif
