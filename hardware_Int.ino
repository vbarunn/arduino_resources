const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;
int flag=0;
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, FALLING);
}

void loop() {
  digitalWrite(ledPin, state);
  if(flag==1){
 flag=0;
 Serial.println("Interupt");
  }
}

void blink() {
  flag=1;
  state = !state;
}
