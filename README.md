# Contador de vida MGT (Magic The Gatherin)

Um dispositivo eletrônico para contar as vidas de dois jogadores de MGT com estilo cyberpunk.

# Tinkercad
- https://www.tinkercad.com/things/4IUuWrgkwlP-counter

# TODO
- [x] `POC` Tinkercad com 2x 7 segments display
- [x] `POC` Tinkercad com add button
- [x] `POC` Tinkercad com sub button
- [x] `POC` Tinkercad com reset button
- [ ] `POC` Tinkercad com PCF8574
- [ ] `POC` Tinkercad com 4 displays e 6 buttons
- [ ] `POC` Fisico com 2x 7 segments display
- [ ] `POC` Fisico com add button
- [ ] `POC` Fisico com sub button
- [ ] `POC` Fisico com reset button
- [ ] `POC` Fisico com PCF8574
- [ ] `POC` Fisico com 4 displays e 6 buttons
- [ ] `POC` Fisico sem a placa do Arduino e usando uma pilha
- [ ] Setar o máximo e mínimo de vida sendo 0 e 99 no c
- [ ] Definir o design
- [ ] Construir a primeira versão fisica

# Ideias
###### Eletrônica / Arduino / Tinkercad
- <s>Fazer em dois módulos separados cada um com um display</s>
- <s>Fazer um switch com uma alavanca pequena para os mesmos botões alterarem os dois lados</s>
- Usar o PCF8574 para economizar portas
- Outros leds de enfeite (pensar nas portas que eles vão usar)
- Uma forma gráfica (com leds) de mostrar a porcentagem da vida (proporcional a 20 pontos)
- Usar uma bateria pequena como aquela redondinha de 3v

###### Material / Construção / Estilo
- A própria estrutura de fios e soldas formar um dispositivo exposto bem cyberpunk
- Usar outro objeto bem legal e característico improvisado
- Muitos leds
- Usar uma placa de circuito mesmo mas pintar ela com spray com cores neon
- <s>Colocar um buser para soar alguma coisa quando a vida estiver baixa</s>

# Código
```
char A=10,B=2,C=3,D=4,E=5,F=6,G=7;
char digit1=8,digit2=9;
char addButton=11, subButton=12, resetButton=13;

int currentNumber = 20;

byte lastAddBState, lastSubBState, lastResetBState;

char numbers[10] = {
  0b0111111,
  0b0000110,
  0b1011011,
  0b1001111,
  0b1100110,
  0b1101101,
  0b1111101,
  0b0000111,
  0b1111111,
  0b1101111
};

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
    
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  
  pinMode(addButton, INPUT);
  pinMode(subButton, INPUT);
  pinMode(resetButton, INPUT);
  
  digitalWrite(digit1, LOW);
  digitalWrite(digit2, LOW);
  
  lastAddBState = digitalRead(addButton);
  lastSubBState = digitalRead(subButton);
  lastResetBState = digitalRead(resetButton);
  
  Serial.begin(9600);
}

void loop() {
  byte addBState = digitalRead(addButton);
  byte subBState = digitalRead(subButton);
  byte resetBState = digitalRead(resetButton);
  
  if (addBState != lastAddBState && addBState == HIGH) {
    currentNumber += 1;
  }
  
  if (subBState != lastSubBState && subBState == HIGH) {
    currentNumber -= 1;
  }
  
  if (resetBState != lastResetBState && resetBState == HIGH) {
    currentNumber = 20;
  }

  lastAddBState = addBState;
  lastSubBState = subBState;
  lastResetBState = resetBState;
  
  char d1 = currentNumber / 10;
  char d2 = currentNumber % 10;
  
  digitalWrite(digit1, LOW);
  digitalWrite(digit2, LOW);
  number(numbers[d1]);
  digitalWrite(digit1, HIGH);
  digitalWrite(digit2, LOW);
  
  delay(10);
    
  

  digitalWrite(digit1, LOW);
  digitalWrite(digit2, LOW);
  number(numbers[d2]);
  digitalWrite(digit1, LOW);
  digitalWrite(digit2, HIGH);
  
  delay(10);
}

void number(int num) {
  
  digitalWrite(A, num & 0b0000001);
  digitalWrite(B, num & 0b0000010);
  digitalWrite(C, num & 0b0000100);
  digitalWrite(D, num & 0b0001000);
  digitalWrite(E, num & 0b0010000);
  digitalWrite(F, num & 0b0100000);
  digitalWrite(G, num & 0b1000000);
}

// 0 = 0b0111111
// 1 = 0b0000110
// 2 = 0b1011011
// 3 = 0b1001111
// 4 = 0b1100110
// 5 = 0b1101101
// 6 = 0b1111101
// 7 = 0b0000111
// 8 = 0b1111111
// 9 = 0b1101111
```

# Lista de Materiais
- Arduino
- `2x` Displays de 7 segmentos
- `6x` Push Buttons

# Referências

Contador sem botões
- https://www.youtube.com/watch?v=fZEkisltjMQ
- https://www.youtube.com/watch?v=rH2aJZNqYcQ

Contador sem Arduino (simples de fazer mas não serve porque não da pra subtrair do contador)
- https://www.youtube.com/watch?v=5cRS2lRKSAg

Contador sem Arduino de dois dígitos (simples de fazer mas não serve porque não da pra subtrair do contador)
- https://www.youtube.com/watch?v=V1SdCgZvbzA

Truque para usar no push button (debounce)
- https://www.youtube.com/watch?v=ZoaUlquC6x8

Como usar o Arduino fora da placa
- https://www.youtube.com/watch?v=4KMgb_S4bF4

Como usar o extensor de portas PCF8574 para Arduino
- https://www.youtube.com/watch?v=dRb5mAvJfCo
- https://www.youtube.com/watch?v=usPiM_vv-rc
- https://www.youtube.com/watch?v=r-3p-weAtOY

Contadores de vida MTG
- https://github.com/mprosk/mtg_life_counter
- https://www.hackster.io/news/hexentronics-releases-electronic-dice-timer-and-life-counter-for-card-and-board-games-f8d0f96f8e9e
- https://www.google.com/imgres?imgurl=https%3A%2F%2Fclay.ch%2Fwp-content%2Fuploads%2F2021%2F11%2FMTG-Lifecounter-4-Player-Commander-01-scaled.jpg&imgrefurl=https%3A%2F%2Fclay.ch%2Fprodukt%2Fmtg-lifecounter-4-player%2F&tbnid=QurRptWFmbnecM&vet=10CAIQxiAoAGoXChMIsKLv6PrU_QIVAAAAAB0AAAAAEAg..i&docid=GLDRg-MtMykYNM&w=2560&h=2560&itg=1&q=cyberpunk%20MGT%20life%20counter&client=ubuntu&ved=0CAIQxiAoAGoXChMIsKLv6PrU_QIVAAAAAB0AAAAAEAg
- https://www.youtube.com/watch?v=t6Y_GCoSUt4

Todos os tipos de dado D&D em um dispositivo
- https://www.digikey.com/en/maker/projects/all-dungeons-and-dragons-dice-in-one-device/7f0a5df5e8144a67a1707f0b45166c76
