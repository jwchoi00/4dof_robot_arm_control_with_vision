void setup() {
  Serial.begin(115200);  // Serial 통신 초기화
}

void loop() {
  if (Serial.available() > 0) {  // 수신 데이터가 있을 때
    String receivedData = Serial.readStringUntil('\n');  // 줄바꿈 기준으로 데이터 읽기
    Serial.print("Received: ");
    Serial.println(receivedData);  // 받은 데이터를 다시 출력 (테스트용)
    
    // 데이터에 따라 행동 정의
    if (receivedData == 1000) {
      digitalWrite(LED_BUILTIN, HIGH);  // LED 켜기
    } else if (receivedData == "LED_OFF") {
      digitalWrite(LED_BUILTIN, LOW);   // LED 끄기
    }
  }
}
