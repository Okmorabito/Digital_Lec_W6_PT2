int ledPin1 = 29;
int brightnessPotPin = A14;
int buttonPin1 = 35;
int brightnessPotValue = 0;
int ledBrightness = 0;
bool buttonOn = false;
bool lastButtonState = LOW;
bool buttonState = LOW;
int currentState = 0;
long lastDelayTime = 0;
long delayTime = 50;


void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(buttonPin1, INPUT);
}

void loop() {
  checkButton();
}

void checkButton() {
  currentState = digitalRead(buttonPin1);
  if (currentState != lastButtonState) {
    lastDelayTime = millis();
  }
  if ((millis() - lastDelayTime) > delayTime) {  // checks if button state has changed, if so it responds as such
    if (currentState != buttonState) {
      buttonState = currentState;

      if (buttonState == HIGH) {
        buttonOn = !buttonOn;
      }
    }
  }
  lastButtonState = currentState;
  if (buttonOn == true) {
    brightnessPotValue = analogRead(brightnessPotPin);
    ledBrightness = map(brightnessPotValue, 0, 1023, 0, 255);  //maps button if on and turns LED off if button state is low
    analogWrite(ledPin1, ledBrightness);
  } else {
    analogWrite(ledPin1, 0);
  }
}
