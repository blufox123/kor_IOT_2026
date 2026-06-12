// 10번, 12번 핀 세트
const int inputPin1 = 10;
const int outputPin1 = 12;
boolean led_flag1 = LOW;
boolean pre_val1 = HIGH, cur_val1 = HIGH;

// 11번, 13번 핀 세트
const int inputPin2 = 11;
const int outputPin2 = 13;
boolean led_flag2 = LOW;
boolean pre_val2 = HIGH, cur_val2 = HIGH;

void setup() {
  // 1번 세트 설정
  pinMode(inputPin1, INPUT_PULLUP);
  pinMode(outputPin1, OUTPUT);
  digitalWrite(outputPin1, led_flag1);

  // 2번 세트 설정
  pinMode(inputPin2, INPUT_PULLUP);
  pinMode(outputPin2, OUTPUT);
  digitalWrite(outputPin2, led_flag2);
}

void loop() {
  // 1번 세트 로직
  cur_val1 = digitalRead(inputPin1);
  if ((pre_val1 == HIGH) && (cur_val1 == LOW)) {
    led_flag1 = !led_flag1;
    digitalWrite(outputPin1, led_flag1);
    delay(50); // 디바운싱
  }
  pre_val1 = cur_val1;

  // 2번 세트 로직
  cur_val2 = digitalRead(inputPin2);
  if ((pre_val2 == HIGH) && (cur_val2 == LOW)) {
    led_flag2 = !led_flag2;
    digitalWrite(outputPin2, led_flag2);
    delay(50); // 디바운싱
  }
  pre_val2 = cur_val2;
}