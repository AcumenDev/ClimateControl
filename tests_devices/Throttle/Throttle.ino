#include <Servo.h> //Подключаем библиотеку Servo

Servo motor;
byte value = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Подключаем серву на 10 пин
  motor.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    // read the incoming byte:
    value = Serial.parseInt();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(value, DEC);
     motor.write(value);
  }
  
  for (int i = 0; i <= 180; i++) {

    motor.write(i);
    delay(30);
  }

  for (int i = 180; i >= 0; i--) {

    motor.write(i);
    delay(30);
  }

  // Печатаем на монитор
  // Serial.println(analogRead(sensePin));
  //  int val = analogRead(sensePin);// Создаем переменную val для чтения analogRead
  // val= constrain(val,230 ,699);// Ограничиваем диапазон работы датчика посмотрев его на мониторе
  // int motorAngl = map(value, 0, 1024, 180, 0); //Преобразуем диапазон выдаваемый датчиком в диапазон углов сервы
  //Serial.print("motorAngl: ");
  //Serial.println(motorAngl, DEC);
  //motor.write(value);// Устанавливаем серву на угол который получаем через преобразование

}
