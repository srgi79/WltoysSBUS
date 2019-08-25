#define minPos 1840+20
#define migPos 3100
#define maxPos 3100-20

int analVal = 0;

void setup() {
  pinMode(PA7, INPUT_ANALOG);

  Serial.begin(115200);
  Serial.println("Setup finished");
}

void loop() {
  analVal = analogRead(PA7);
  //Serial.println(analVal);
  if (analVal <= minPos) {
    Serial.println("minPos");
  }
  else if (migPos - 50 <= analVal <= migPos + 50) {
    Serial.println("migPos");
  }
  if (analVal >= maxPos) {
    Serial.println("maxPos");
  }
  delay(2); //min 2ms
}
