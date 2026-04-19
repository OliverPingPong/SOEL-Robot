// SOEL Robot - Control básico con botones

const int botonEncender = 2;
const int botonApagar = 3;

bool robotActivo = false;

void setup() {
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
    Serial.println("El robot está funcionando...");
  } else {
    Serial.println("El robot está apagado...");
  }

  delay(1000);
}
