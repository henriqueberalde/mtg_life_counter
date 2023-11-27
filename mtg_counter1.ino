int pinSegments[7] = {8, 6, 7, 9, 10, 11, 12};
int pinDigits[4] = {2, 3, 4, 5};
int digits[10][7] = {
  //A    B    C    D    E    F    G
  {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,LOW}, // 0
  {LOW, HIGH,HIGH,LOW, LOW, LOW, LOW}, // 1
  {HIGH,HIGH,LOW, HIGH,HIGH,LOW, HIGH},// 2
  {HIGH,HIGH,HIGH,HIGH,LOW, LOW, HIGH},// 3
  {LOW, HIGH,HIGH,LOW, LOW, HIGH,HIGH},// 4
  {HIGH,LOW, HIGH,HIGH,LOW, HIGH,HIGH},// 5
  {HIGH,LOW, HIGH,HIGH,HIGH,HIGH,HIGH},// 6
  {HIGH,HIGH,HIGH,LOW, LOW, LOW, LOW}, // 7
  {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH},// 8
  {HIGH,HIGH,HIGH,LOW, LOW, HIGH,HIGH},// 9
};
int numbers[2] = {20, 20};
int numbersInDigits[4];

int pinButton[3] = {1, 13, 0};
int buttonState[3] = {HIGH, HIGH, HIGH};
int lastButtonState[3] = {LOW, LOW, LOW};
unsigned long lastDebounceTime[3] = {0, 0, 0};
unsigned long debounceDelay = 45;

int pinSitchLever = {A5};
int direction = HIGH;

void setup() {
  Serial.begin(9600);
  int i;

  for (i = 0; i < 7; i++) {
    pinMode(pinSegments[i], OUTPUT);
  }

  for (i = 0; i < 4; i++) {
    pinMode(pinDigits[i], OUTPUT);
  }
  
  for (i = 0; i < 2; i++) {
    pinMode(pinButton[i], INPUT_PULLUP);
  }
  
  pinMode(pinSitchLever, INPUT_PULLUP);
}

void resetPinDigits() {
  int i;
  for (i = 0; i < 4; i++) {
  	digitalWrite(pinDigits[i], HIGH);
  }
}

void resetPinSegments() {
  int i;
  for (i = 0; i < 7; i++) {
  	digitalWrite(pinSegments[i], LOW);
  }
}

void setNumbersInDigits() {
  int i;
  for (i = 0; i < 2; i++) {
  	int d1 = numbers[i] % 10;
    int d2 = numbers[i] / 10;
    
    int index = i*2;
    numbersInDigits[index] = d1;
    numbersInDigits[index+1] = d2;
  }
}

int calcNumber(int value) {
  int newValue = value;
  
  if (direction == HIGH) {
    newValue--;
  }
  else {
    newValue++;
  }
  
  if (newValue >= 100) {
    newValue = 0;
  }
  
  if (newValue < 0) {
    newValue = 99;
  }
  
  return newValue;
}

void loop() {
  int i;

  // Digits
  for (i = 0; i < 4; i++) {
    setNumbersInDigits();
    
    resetPinDigits();
    resetPinSegments();
    
    digitalWrite(pinDigits[i], LOW);
    
    int j;
    for (j = 0; j < 7; j++) {
      digitalWrite(pinSegments[j], digits[numbersInDigits[i]][j]);
    }
  	
    delay(5);
  }
  
  // Buttons
  for (i = 0; i < 3; i++) {
    int buttonValue = digitalRead(pinButton[i]);
    
    if (buttonValue != lastButtonState[i]) {
      lastDebounceTime[i] = millis();
    }

    if ((millis() - lastDebounceTime[i]) > debounceDelay) {
      if (buttonValue != buttonState[i]) {
        buttonState[i] = buttonValue;
		Serial.println(i+1);
        if (buttonState[i] == LOW) {
          Serial.println(i+1);
          if (i > 1) {
            numbers[0] = 20;
            numbers[1] = 20;
          }
          else {
            int newValue = calcNumber(numbers[i]);
          	numbers[i] = newValue;
          }
        }
      }
    }
    lastButtonState[i] = buttonValue;
  }
  
  // Switch Lever
  direction = digitalRead(pinSitchLever);
}
