
int slump; // Hur många LEDs ska vara tända

void setup() {

    // Ställ in alla lysdiodernas portar (2 - 7)
    for (int i = 2; i <= 7; i++ ) {
        pinMode(i, OUTPUT);
    }

    // Ställ in tryckknappens port
    pinMode(8, INPUT_PULLUP);
    slump = 0;
}

void loop() {
    // Om knappen är nedtryckt
    if(digitalRead(8) == LOW) {

        // Slumpa ett tal 0-5
        slump = random(6);

        // Sätt portar 2-7 till LOW (stäng av dioderna)
        for (int i = 2; i <= 7; i++) {
            digitalWrite(i, LOW);
        }

        // Vänta väldigt kort tid
        delay(10);

    // Knappen är inte nedtryckt
    } else {

        // tänd lysdioder från 2 till slump+2
        for (int i = 2; i <= slump+2; i++) {
            digitalWrite(i, HIGH);
        }
    }
}
