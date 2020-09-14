const int redPin = 9;   // RED
const int greenPin = 10; // GREEN
const int bluePin = 11;  // BLUE
void setup()
{
    randomSeed(analogRead(A0)); // random number return
}
void loop()
{
    analogWrite(redPin, random(256));
    analogWrite(greenPin, random(256));
    analogWrite(bluePin, random(256));
    delay(1000);
}