#define ary_size  4

int led_pin[ary_size] = {5,6,7,8};
int led_size = sizeof(led_pin)/sizeof(led_pin[0]);

// 함수선언
void led_binary(int num);
int myBitRead(int num, int i);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for(int i=0; i<led_size; i++){
    pinMode(led_pin[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // for문을 이용한 반복문
  // 반복회수는 16이고, i값의 변화는 0부터 15(16-1)
  //    초기값  조건식 증가값
  for (int i=0; i<16; i++) {   
    Serial.print(i);
    Serial.print("  ");
    
    // led 출력
    led_binary(i);   // 함수 호출
    delay(1000);
  }
  Serial.println();
}

// 함수구현
void led_binary(int num){
  for(int i=0; i<led_size; i++){
    digitalWrite(led_pin[i], myBitRead(num, i));
    // digitalWrite(led_pin[i], bitRead(num, i));

  }
}

int myBitRead(int num, int i){
  return (((num) >> (i)) & 0x01);
}





