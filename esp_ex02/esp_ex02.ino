#include <WifiUtil.h>
const char SSID[] = "TP-Link_1450";
const char PASSWORD[] = "01039964667";
WifiUtil wifi(2, 3);
void setup()
{
    Serial.begin(9600);
    wifi.init(SSID, PASSWORD);
}
void loop()
{
    if (wifi.check())
    { // WIFI 연결 확인
        ;
    }
}