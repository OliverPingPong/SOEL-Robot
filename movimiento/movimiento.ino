// SOEL Robot - Movimiento básico

#include <Servo.h>

Servo cabeza;

const int botonEncender = 2;
const int botonApagar = 3;

bool robotActivo = false;

void setup() {
  cabeza.attach(9);

  pinMode(botonEncender, INPUT_PULLUP);
  pinMode(botonApagar, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(botonEncender) == LOW) {
    robotActivo = true;
    Serial.println("Robot ENCENDIDO");
    delay(300);
  }

  if (digitalRead(botonApagar) == LOW) {
    robotActivo = false;
    Serial.println("Robot APAGADO");
    delay(300);
  }

  if (robotActivo) {
    // Movimiento simple
    cabeza.write(60);
    delay(500);
    cabeza.write(120);
    delay(500);
  } else {
    cabeza.write(90); // posición neutral
  }
}
