#define LDR  17
#define led1 13
#define led2 11
#define led3 9
#define led4 3
#define btn1 4
#define btn2 5
#define buzz 1

int vector[69];
int contagem = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LDR, INPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(buzz, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int first = analogRead(LDR);
  Serial.println(first);
  int button1 = digitalRead(btn1);
  int button2 = digitalRead(btn2);
  int OldMax = 500;
  int OldMin = 0;
  int OldRange = (OldMax - OldMin);
  int NewValue = ((first - OldMin) / (OldRange/15));
  //Serial.println(NewValue);

  if(button1 == LOW) {
    Serial.println("aaaa");
    led(NewValue);
    vector[contagem] = NewValue;
    contagem += 1;
  }

  if(button2 == LOW) {
    for(int i = 0; i<contagem; i+=1){
      int sequence = vector[i];
      led(sequence);
    }
  }

}

void led(int qualquer) {
  if(qualquer == 0){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    tone(buzz,100,1000);
  }
  if(qualquer == 1){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    tone(buzz,200,1000);
  }
  if(qualquer == 2){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    tone(buzz,300,1000);
  }
  if(qualquer == 3){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    tone(buzz,400,1000);
  }
  if(qualquer == 4){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    tone(buzz,500,1000);
  }
  if(qualquer == 5){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    tone(buzz,600,1000);
  }
  if(qualquer == 6){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    tone(buzz,700,1000);
  }
  if(qualquer == 7){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    tone(buzz,800,1000);
  }
  if(qualquer == 8){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    tone(buzz,900,1000);
  }
  if(qualquer == 9){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    tone(buzz,1000,1000);
  }
  if(qualquer == 10){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    tone(buzz,1100,1000);
  }
  if(qualquer == 11){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    tone(buzz,1200,1000);
  }
  if(qualquer == 12){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    tone(buzz,1300,1000);
  }
  if(qualquer == 13){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    tone(buzz,1400,1000);
  }
  if(qualquer == 14){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    tone(buzz,1500,1000);
  }
  if(qualquer == 15){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    tone(buzz,1600,1000);
  }
}