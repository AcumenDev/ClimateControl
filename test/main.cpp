#include <chrono>
#include "../climate/Climate.hpp"
#include "ClimateChangeService.hpp"

static const int daySeconds = 86400;
using namespace std;
using namespace std::chrono;


Climate climate;

int main() {
    //cout << "Start!" << endl;
    freopen("output", "w", stdout);
    cout <<
         "currentSeconds\ttemperature\thumidity\ttargetTemperature\ttargetHumidity\thumidification_relay\theating_relay\tcooling_relay"
         <<
         endl;
    climate.setup();

    ClimateChangeService *changeService = new ClimateChangeService(new DHT(1, 1), climate.values);

    bool state = true;
    unsigned long startTime = 0;
    unsigned long currentSeconds;
    unsigned long currentMillis = 0;
    startTime = 0;
    while (state) {
        if (currentMillis/1000 >= daySeconds * 1) {
            break;
        }
        currentSeconds = duration_cast<milliseconds>(
                system_clock::now().time_since_epoch()
        ).count() / 1000;
        // currentMillisFast =currentSeconds;

        climate.loop(currentMillis);
        // updateTemp(currentMillisFast);
        changeService->update(currentMillis);
        currentMillis += 1;
        // debug(currentMillisFast);
        //  if (currentMillisFast - startTime >= hour24) {
        //      break;
        //    }
    }
    return 0;
}