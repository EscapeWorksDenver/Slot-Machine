// Pins for button leds
const int leds[] = {22, 24, 26, 28, 30};
// Pins for buttons
const int buttons[] = {23, 25, 27, 29, 31};
// Pins of the button needed to be pressed in order
const int sequence[] ={31, 25, 23, 29, 27, 31, 25};
// Variable of current index within sequence
int step = 0;

void setup() {
  //Start Serial
  Serial.begin(9600);
  //Initialize all pins at once
  for (int x = 0; x < 5; x++) {
    pinMode(leds[x], OUTPUT);
    pinMode(buttons[x], INPUT_PULLUP);
  }
}

void loop() {
  //Check each button
  for (int x = 0; x < 5; x++) {
    //If button is being pressed
    if (digitalRead(buttons[x]) == LOW) {
      //Toggle led for that button
      digitalWrite(leds[x], LOW);
      //If the button that is being pressed is the correct button in the sequence
      if (buttons[x] == sequence[step]) {
        //Increase index
        step++;

        //If final button is pressed
        if (step == 7) {
          //Solve puzzle
          win();
        }
        //Button debounce
        delay(200);
      } else {
        //If button was not in order, reset index
        step = 0;
      }
    } else {
      //All leds on when no button pressed
      digitalWrite(leds[x], HIGH);
    }
  }
}

//Function to solve puzzle
void win() {
  //Reset index
  step = 0;
  //Blink all button leds
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

