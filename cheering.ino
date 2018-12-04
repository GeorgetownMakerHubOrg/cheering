//Code Begin

const int SensorSignal = 7; // define integer SensorSignal with value 2 , this is the signal output (S, or OUT) from your sensor (can be any sensor)
const int ledPin = LED_BUILTIN;  // define integer ledPin with value 13 
int sensorValue = 0;

void setup() {
    Serial.begin(115200);
    pinMode(SensorSignal, INPUT);  // declare digital pin 2 as input, this is where you connect the S output from your sensor, this can be any digital pin
    pinMode(ledPin, OUTPUT); // declare digital pin 13 as output, this digital pin is also connected to the Yellow LED on your VMA100 board
}

int previousValue = LOW;
void loop(){

  sensorValue = digitalRead(SensorSignal); // read the value of pin 2, should be high or low
  if(sensorValue != previousValue){ 
    if (sensorValue == HIGH) { digitalWrite(ledPin, HIGH); // set pin 13 (ledPin) according to the value on pin 2
      Serial.println("motion");
    } 
    else { digitalWrite(ledPin, LOW); 
      Serial.println("still");
    }
  }
  previousValue = sensorValue; 
  delay(100);
}
//code End
