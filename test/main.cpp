#include <chrono>
#include "../climate/Climate.hpp"

using namespace std;
using namespace std::chrono;


Climate climate;

int main() {
    //cout << "Start!" << endl;
    cout   << "temperature\tOurTemperature\ttargetTemperature\theatingRelay\tcoolingRelay"<<endl;
    climate.setup();
    bool state = true;
    long startTime = 0;
    long currentMillis;
    long currentMillisFast = 0;
    startTime = 0;
    while (state) {
        currentMillis = duration_cast<milliseconds>(
                system_clock::now().time_since_epoch()
        ).count();
        // currentMillisFast =currentMillis;

        climate.loop(currentMillisFast);
        // updateTemp(currentMillisFast);

        currentMillisFast+=5;
        // debug(currentMillisFast);
        //  if (currentMillisFast - startTime >= hour24) {
        //      break;
        //    }
    }
    return 0;
}