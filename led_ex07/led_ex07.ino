int pins[] = {13, 8, 12, 7};
int state = 0;
void setup()
{
    Serial.begin(9600);
    for (int i = 0; i < 4; i++)
    {
        pinMode(pins[i], OUTPUT);
        digitalWrite(pins[i], LOW);
    }
}
void loop()
{
    for (int i = 0; i < 4; i++)
    {
        if (i == state)
        {
            Serial.print("0 ");
            digitalWrite(pins[i], HIGH);
        }
        else
        {
            Serial.print("X ");
            digitalWrite(pins[i], LOW);
        }
    }
    Serial.println();
    state = (state + 1) % 4;
    delay(1000);
}

// if you got
// Failed to open serial port COM3 due to error: + Error: \\?\c:\Users\Admin\.vscode\extensions\vsciot-vscode.vscode-arduino-0.3.2\out\node_modules\usb-detection\build\Release\detection.node is not a valid Win32 application.
// \\?\c:\Users\Admin\.vscode\extensions\vsciot-vscode.vscode-arduino-0.3.2\out\node_modules\usb-detection\build\Release\detection.node
// then install 1.35 version vscode, and uninstall arduino, c/c++, and install c/c++, arduino again.