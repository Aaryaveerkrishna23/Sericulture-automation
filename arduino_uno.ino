#include "DHT.h"

int relayPin = 8; // Arduino pin connected to relay which connected to fan
#define DHTPIN 12           // Arduino pin connected to relay which connected to DHT sensor
#define DHTTYPE DHT11

const int TEMP_THRESHOLD_UPPER = 31; // upper threshold of temperature, change to your desire value
const int TEMP_THRESHOLD_LOWER = 20; // lower threshold of temperature, change to your desire value
const int Humid_THRESHOLD_UPPER = 95; // upper threshold of humid, change to your desire value
const int Humid_THRESHOLD_LOWER = 80; // lower threshold of humid, change to your desire value

DHT dht(DHTPIN, DHTTYPE);

float temperature;    // temperature in Celsius
float humidity;    // temperature in Celsius

void setup()
{
  Serial.begin(9600); // initialize serial
  dht.begin();        // initialize the sensor
  pinMode(relayPin, OUTPUT);       // initialize digital pin as an output
}

void loop()
{
  // wait a few seconds between measurements.
  delay(8000);

  temperature = dht.readTemperature();;  // read temperature in Celsius
  humidity  = dht.readHumidity();
  
  Serial.print("%  Temperature: ");
  Serial.print(temperature);
  Serial.print("\n%  Humidity: ");
  Serial.print(humidity);
  
delay(1000);
    if (isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    if (temperature > TEMP_THRESHOLD_UPPER) {
      Serial.println("\nTurn the Buzzer on");
      digitalWrite(relayPin, HIGH); // turn on
      delay(10000);
      digitalWrite(relayPin, LOW); // turn off
    } else if (temperature < TEMP_THRESHOLD_LOWER) {
      Serial.println("\nTurn the Buzzer on");
      digitalWrite(relayPin, HIGH); // turn on
      delay(10000);
      digitalWrite(relayPin, LOW); // turn off
    }else if (humidity > Humid_THRESHOLD_UPPER ) {
      Serial.println("\nTurn the Buzzer on");
      digitalWrite(relayPin, HIGH); // turn on
      delay(10000);
      digitalWrite(relayPin, LOW); // turn off
    }else if (humidity < Humid_THRESHOLD_LOWER ) {
      Serial.println("\nTurn the buzzer on");
      digitalWrite(relayPin, HIGH); // turn on
      delay(10000);
      digitalWrite(relayPin, LOW); // turn off
    }
  }
}
