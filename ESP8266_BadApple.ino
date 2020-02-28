#include <ESP8266WiFi.h>
#include <U8g2lib.h>
#include <U8x8lib.h>
const char* Ssid     = "iCOMgx";
const char* Password = "sshiki123";

const char* Server = "192.168.31.177";
const int Port = 715;

short Status = 0;
uint8_t apple[1024]={}; //128 * 64 / 8 = 1024
WiFiClient client;

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);


void setup() {
  WiFi.begin(Ssid, Password);
  u8g2.begin();
}

void loop() {
  if(Status==0 && WiFi.status()==WL_CONNECTED)
  {
    Status=1;
    client.connect(Server, Port);
  }
  while(client.available()){ 
    client.read(apple,1024);
    delay(70);
    u8g2.clearBuffer();
    u8g2.drawXBMP(0, 0, 128, 64, apple);
    u8g2.sendBuffer();
  }
}
