#include <chrono>
#include "../climate/Menu.hpp"
#include "../climate/PageGroup.hpp"
#include "../climate/PageValue.hpp"
#include "../climate/FloatChanger.hpp"

static const int daySeconds = 86400;
using namespace std;
using namespace std::chrono;


int main() {
    cout << "Test menu" << endl;
    char inputChar;
    bool state = true;


    float tempGis = 0;
    float tempCof = 0;

    float humGis = 0;
    float humCof = 0;

    float co2Gis = 0;
    float co2Cof = 0;

    PageBase *tPages[] = {
            new PageValue("G", new FloatChanger(&tempGis, 0, 10, 0.1)),
            new PageValue("C", new FloatChanger(&tempCof, 0, 10, 0.1))
    };
    PageGroup *tGroup = new PageGroup("T", tPages, 2);

    PageBase *hPages[] = {
            new PageValue("G", new FloatChanger(&humGis, 0, 10, 0.1)),
            new PageValue("C", new FloatChanger(&humCof, 0, 10, 0.1))
    };
    PageGroup *hGroup = new PageGroup("H", hPages, 2);

    PageBase *co2Pages[] = {
            new PageValue("G", new FloatChanger(&co2Gis, 0, 10, 0.1)),
            new PageValue("C", new FloatChanger(&co2Cof, 0, 10, 0.1))
    };
    PageGroup *co2Group = new PageGroup("CO2", co2Pages, 2);

    PageBase *mainPages[] = {
            tGroup,
            hGroup,
            co2Group
    };
    PageGroup *mainGroup = new PageGroup(mainPages, 3);

    Menu menu(1, mainGroup);

    while (state) {

        cout << menu.getCurrentPage()->getRender() << endl;


        cin >> inputChar;
        if (inputChar == 'q') {
            state = false;
        }

        //  cout << inputChar << endl;

        switch (inputChar) {
            case '+': {
                menu.up();
                break;
            }
            case '-': {
                menu.down();
                break;
            }
            case 'e': {
                menu.enter();
                break;
            }
            default:
                break;
        }


    }
    return 0;
}