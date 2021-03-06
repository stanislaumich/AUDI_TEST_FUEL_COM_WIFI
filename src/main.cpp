//для загрузки жать большой ресет он общий

#include <Arduino.h>
#include <GyverPortal.h>
GyverPortal portal;
String t;
// билдер страницы
void build() {
  String s;
  BUILD_BEGIN(s);
  add.THEME(GP_DARK);

  // кнопка отправляет текст из поля txt
  add.TEXT("txt", "");
  add.BUTTON_MINI("btn", "Send", "txt");
  add.BREAK();
  
  add.AREA_LOG(50);
  
  BUILD_END();
}

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin("ZTE54", "121211119");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(WiFi.localIP());

  portal.attachBuild(build);
  portal.start();
  portal.log.start(30);   // размер буфера
}

void loop() {
portal.tick();
while(Serial.available()>0){
t=Serial.readString();
}
//portal.log.println(t);
  if (portal.click("btn")) {
    // отправляем обратно в "монитор" содержимое поля, оно пришло по клику кнопки
    //portal.log.println(portal.getString("btn"));
    portal.log.println(t);
  }
  //delay(1000);
}