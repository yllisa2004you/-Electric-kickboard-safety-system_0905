#define LED 53 // LED을 통해서 2인 이상 탑승했는지 확인하기 위함, LED 핀을 의미

int speed = 6; // 모터드라이버 속도를 조절하기 위한 디지털핀
int In1 = 5; // 모터를 구동하기 위한 모터
int In2 = 4; // 모터를 구동하기 위한 모터

void setup() {
  pinMode(LED,OUTPUT); // LED 핀 정의


  pinMode(speed,OUTPUT); // 모터 드라이버 속도, 핀 정의
  pinMode(In1,OUTPUT); // 모터 드라이버 방향 제어 핀 정의
  pinMode(In2,OUTPUT); // 모터 드라이버 방향 제어 핀 정의

  ////////DC모터 방향 제어////////
  digitalWrite(In1,HIGH); 
  digitalWrite(In2,LOW);


  analogWrite(speed,0); // 모터 회전 속도, 0 = 무회전
}
 
void loop() {

    
  int push_count = 0; //압력 센서 눌린 개수를 저정하기 위함
  for(int i = 1;i<=16;i++){ // 1~16번 압력센서 접근
    // 1~16 -> i, i번째 압력센서 값 확인
    int value = analogRead(i);
    // 값 경계, 3보다 크면 발에 눌린 것으로 확인, 조건 만족할 시, push_count 1씩 증가
    if(value >=3)
      push_count++;
  }
  
  // 압전센서 4개이상 눌렸는가?
  if(push_count >= 4){
    // LED 불 키고, DC 모터 멈춤
    digitalWrite(LED,HIGH);
    analogWrite(speed,0);
  }

  else{// 4개 이하 눌렸는가?
    // LED 불 끄고, DC 모터 작동
    analogWrite(speed,255);
    digitalWrite(LED,LOW);
  }

 // 과부화 방지 delaydd
  delay(100);
}