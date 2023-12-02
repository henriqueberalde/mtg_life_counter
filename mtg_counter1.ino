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

int pinButton[4] = {1, 0, 13, A5};
int buttonState[4] = {HIGH, HIGH, HIGH, HIGH};
int lastButtonState[4] = {LOW, LOW, LOW, LOW};
unsigned long lastDebounceTime[4] = {0, 0, 0, 0};
unsigned long debounceDelay = 45;

void setup() {
  Serial.begin(9600);
  int i;

  for (i = 0; i < 7; i++) {
    pinMode(pinSegments[i], OUTPUT);
  }

  for (i = 0; i < 4; i++) {
    pinMode(pinDigits[i], OUTPUT);
  }
  
  for (i = 0; i < 4; i++) {
    pinMode(pinButton[i], INPUT_PULLUP);
  }
  
  numbers[0] = 20;
  numbers[1] = 20;
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

int calcNumber(int value, bool add) {
  int newValue = value;
  
  if (add) {
    newValue++;
  }
  else {
    newValue--;
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
  for (i = 0; i < 4; i++) {
    int buttonValue = digitalRead(pinButton[i]);
    
    if (buttonValue != lastButtonState[i]) {
      lastDebounceTime[i] = millis();
    }

    if ((millis() - lastDebounceTime[i]) > debounceDelay) {
      if (buttonValue != buttonState[i]) {
        buttonState[i] = buttonValue;
        if (buttonState[i] == LOW) {
          int newValue;
          switch(i) {
            case 0:
              // ADD DIGIT 1
              Serial.println("ADD DIGIT 1");
              newValue = calcNumber(numbers[0], true);
          	  numbers[0] = newValue;
              break;
            case 1:
              // sub DIGIT 1
              Serial.println("SUB DIGIT 1");
              newValue = calcNumber(numbers[0], false);
          	  numbers[0] = newValue;
              break;
            case 2:
              // ADD DIGIT 2
              Serial.println("ADD DIGIT 2");
              newValue = calcNumber(numbers[1], true);
          	  numbers[1] = newValue;
              break;
            case 3:
              // sub DIGIT 2
              Serial.println("SUB DIGIT 2");
              newValue = calcNumber(numbers[1], false);
          	  numbers[1] = newValue;
              break;
          }
        }
      }
    }
    lastButtonState[i] = buttonValue;
  }
}
