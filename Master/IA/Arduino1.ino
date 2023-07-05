// Esta es la parte declarativa del código
int vble;
float tension;

void setup() {
  Serial.begin(9600);
  //pinMode(A1, INPUT);
}

void loop() {
  //Serial.println("Hello world!");
  //delay(500);

  vble = analogRead(A1);
  tension = (vble*5.00)/1023;

  Serial.print(tension); 
  Serial.print(",");
  Serial.print(tension+1.5);
}
