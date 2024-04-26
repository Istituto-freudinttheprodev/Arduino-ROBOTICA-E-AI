#define SHORT_NOTE 250
#define LONG_NOTE 500
#define SHORT_PAUSE 50
#define LONG_PAUSE 200

// Definizione delle note di pianoforte
#define NOTE_E5 659
#define NOTE_D5 587
#define NOTE_C5 523
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_F5 698
#define NOTE_G5 784

const int buzzerPin = 9;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int melody[] = {
    NOTE_E5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_D5,
    NOTE_E5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_C5,
    NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_G4, NOTE_G4, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5
  };

  int noteDurations[] = {
    2 * SHORT_NOTE, 2 * SHORT_NOTE, SHORT_NOTE, SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE,
    2 * SHORT_NOTE, 2 * SHORT_NOTE, SHORT_NOTE, SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE,
    2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, SHORT_NOTE, SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE, 2 * SHORT_NOTE
  };

  for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
    if (melody[i] == 0) {
      delay(noteDurations[i]);
    } else {
      tone(buzzerPin, melody[i], noteDurations[i]);
      delay(noteDurations[i]);
    }
    noTone(buzzerPin);
    delay(SHORT_PAUSE);
  }

  delay(2 * LONG_PAUSE); // Aggiungi una pausa tra le ripetizioni
}