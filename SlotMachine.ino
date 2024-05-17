const int leds[] = {22, 24, 26, 28, 30};
const int buttons[] = {23, 25, 27, 29, 31};
const int sequence[] ={31, 25, 23, 29, 27, 31, 25};
int step = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int x = 0; x < 5; x++) {
    pinMode(leds[x], OUTPUT);
    pinMode(buttons[x], INPUT_PULLUP);
  }
}

void loop() {
  // Serial.println(step);
  for (int x = 0; x < 5; x++) {
    if (digitalRead(buttons[x]) == LOW) {
      digitalWrite(leds[x], LOW);
      if (buttons[x] == sequence[step]) {
        Serial.println(step);
        step++;

        if (step == 7) {
          win();
        }
        delay(200);
      } else {
        step = 0;
        Serial.println(step);
      }
    } else {
      digitalWrite(leds[x], HIGH);
    }
  }
}

void win() {
  step = 0;
  for (int i = 0; i < 5; i++) {
    digitalWrite(leds[i], LOW);
  }
  delay(300);
  for (int x = 0; x < 5; x++) {
    digitalWrite(leds[x], HIGH);
  }
  delay(300);
  for (int y = 0; y < 5; y++) {
    digitalWrite(leds[y], LOW);
  }
  delay(300);
  for (int a = 0; a < 5; a++) {
    digitalWrite(leds[a], HIGH);
    }
  delay(300);
  for (int s = 0; s < 5; s++) {
    digitalWrite(leds[s], LOW);
  }
  delay(300);
  for (int g = 0; g < 5; g++) {
    digitalWrite(leds[g], HIGH);
  }
}

