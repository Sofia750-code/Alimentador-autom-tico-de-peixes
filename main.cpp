#include <Arduino.h>
#include <Wire.h>
#include <RTClib.h>
#include <Stepper.h>

RTC_DS3231 rtc;

// motor 28BYJ-48
const int stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution, 23, 18, 19, 5);

// controle de tempo
unsigned long ultimoAlimento = 0;
const unsigned long intervalo = 5000; // 5 segundos

void alimentarPeixe() {

  Serial.println("Liberando comida...");

  // gira um compartimento
  myStepper.step(146);

  // desliga as bobinas do motor
  digitalWrite(5, LOW);
  digitalWrite(18, LOW);
  digitalWrite(19, LOW);
  digitalWrite(23, LOW);
}

void setup() {

  Serial.begin(115200);
  Wire.begin();

  if (!rtc.begin()) {
    Serial.println("RTC nao encontrado!");
    while (1);
  }

  // AJUSTA O HORARIO DO RTC (rode apenas uma vez)
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  myStepper.setSpeed(10);

  pinMode(5, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(23, OUTPUT);

  Serial.println("Sistema iniciado!");
}

void loop() {

  DateTime now = rtc.now();

  Serial.print("Hora: ");
  Serial.print(now.hour());
  Serial.print(":");
  Serial.print(now.minute());
  Serial.print(":");
  Serial.println(now.second());

  // alimenta a cada 5 segundos
  if (millis() - ultimoAlimento >= intervalo) {

    alimentarPeixe();
    ultimoAlimento = millis();

  }

  delay(1000);
}
