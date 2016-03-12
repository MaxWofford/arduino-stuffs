const int UPPER = 350;
const int MORSELENGTH = 30;
int count = 0;
bool lastState = false;

void setup(){
  Serial.begin(9600);
}

bool check() {
  return (UPPER < analogRead(A0));
}

void loop() {
  delay(10);
  count = count + 1;
  if (lastState != check()) {
    // something changed
    if (lastState) {
      if (count > MORSELENGTH) {
        Serial.print("_ ");
      } else {
        Serial.print(". ");
      }
    } else if (count > MORSELENGTH * 3) {
      Serial.print("     ");
    }
  count = 0;
  lastState = check();
  }
}
