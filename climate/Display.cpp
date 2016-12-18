#include "Display.hpp"

Display::Display(char displayDataPin, char displayClkPin, char displayCsPin, int intervalChange, int interval, Values *values)    {
  this->displayDataPin = displayDataPin;
  this->displayClkPin = displayClkPin;
  this->displayCsPin = displayCsPin;
  this->interval = interval;
  this->intervalChange = intervalChange;
  this->values = values;
  this->ledControl = new LedControl(displayDataPin, displayClkPin, displayCsPin);

  ledControl->shutdown(0, false);
  ledControl->setScanLimit(0, 8);
  ledControl->setIntensity(0, 15);
  ledControl->clearDisplay(0);
}

void Display::update(unsigned long currentMillis) {

  if ( values->isAfterChange(currentMillis)) {
    if ( (currentMillis - previousMillis) < intervalChange) {
      return;
    }
    ledControl->clearDisplay(0);
    showTemp(values->targetTemperature );
    showHeating(values->targetHumidity);

  } else {
    if ( (currentMillis - previousMillis) < interval) {
      return;
    }
    ledControl->clearDisplay(0);
    showTemp(values->temperature);
    showHeating(values->humidity);
    values->changeTimeStamp = 0;
  }
  previousMillis = currentMillis;

}


void Display::showTemp( float temp) {
  showNumber(temp, 7);
}
void Display::showHeating( float heating) {
  showNumber(heating, 3);
}


void Display::showNumber( float number, int startDig)
{
  // Serial.print("number: ");
  //  Serial.print(number);
  if (number == 0) {
    showDigit( 0, startDig - 3, false) ; // отображаем 0 в правом разряде
  } else {
    // отображаем значение, соответствующее каждой цифре
    // крайняя левая цифра 0, правая на единицу меньше, чем число позиций

    showDigit( (int)number % 10, startDig - 2, true) ;
    int nextNumber = (int)number / 10;

    int i = nextNumber % 10;
    if (i > 0) {
      showDigit( nextNumber % 10, startDig - 1, false) ;
    }


    int dec = 0;
    if (number > 1) {

      //    Serial.print("  (int)number: ");
      //    Serial.print((int)number);

      dec = (number - (int)number) * 10;
    } else {
      dec = number  * 10.0f;
    }


    //   Serial.print("  dec: ");
    //  Serial.print(dec);
    //Serial.print("  digit: ");
    // Serial.print(digit);
    showDigit( dec, startDig - 3, false) ;
  }
  //  Serial.println();
}

// Отображаем заданное число на данном разряде 7-сегментного индикатора
void Display:: showDigit( int oneNumber, int digit, bool dot)
{

  ledControl->setDigit(0, digit, oneNumber, dot);
}






