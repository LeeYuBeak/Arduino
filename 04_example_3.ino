#define PIN_LED 13
unsigned int count;
int toggle;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(115200);
  while (!Serial) {
    ; // Wait for serial port to connect
  }
  Serial.println("Hello World!");
  count = 0;
  toggle = LOW; // 초기 상태를 LOW로 설정
  digitalWrite(PIN_LED, toggle);
}

void loop() {
  Serial.println(++count);
  toggle = toggle_state(toggle);
  digitalWrite(PIN_LED, toggle);
  delay(1000);
}

int toggle_state(int toggle) {
  return (toggle == LOW) ? HIGH : LOW; // 상태를 반전
}
