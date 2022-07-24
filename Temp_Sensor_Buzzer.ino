#include <DHT.h>

#define RELAY_BUZZER_PIN  2  // ESP32 pin GIOP27, which connects to the IN pin of relay
#define DHT_SENSOR_PIN  15 // ESP32 pin GIOP21 connected to DHT11 sensor
#define DHT_SENSOR_TYPE DHT11

#define TEMP_UPPER_THRESHOLD  20 // upper temperature threshold
#define TEMP_LOWER_THRESHOLD  15 // lower temperature threshold

#define Humid_UPPER_THRESHOLD  100 // upper temperature threshold
#define Humid_LOWER_THRESHOLD  65 // lower temperature threshold

DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

void setup() {
  Serial.begin(9600); // initialize serial
  dht_sensor.begin(); // initialize the DHT sensor
}

void loop() {
  float temperature = dht_sensor.readTemperature();;  // read temperature in Celsius
  float humidity  = dht_sensor.readHumidity();
 Serial.println(temperature);
 Serial.println(humidity);
  if (isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    if (temperature > TEMP_UPPER_THRESHOLD) {
      Serial.println("Turn the Buzzer on");
      digitalWrite(RELAY_BUZZER_PIN, HIGH); // turn on
      delay(10000);
      digitalWrite(RELAY_BUZZER_PIN, LOW); // turn off
    } else if (temperature < TEMP_LOWER_THRESHOLD) {
      Serial.println("Turn the Buzzer on");
      digitalWrite(RELAY_BUZZER_PIN, HIGH); // turn on
      delay(10000);
      digitalWrite(RELAY_BUZZER_PIN, LOW); // turn off
    }else if (humidity > Humid_UPPER_THRESHOLD ) {
      Serial.println("Turn the Buzzer on");
      digitalWrite(RELAY_BUZZER_PIN, HIGH); // turn on
      delay(10000);
      digitalWrite(RELAY_BUZZER_PIN, LOW); // turn off
    }else if (humidity < Humid_LOWER_THRESHOLD ) {
      Serial.println("Turn the buzzer on");
      digitalWrite(RELAY_BUZZER_PIN, HIGH); // turn on
      delay(10000);
      digitalWrite(RELAY_BUZZER_PIN, LOW); // turn off
    }
  }

  // wait a 2 seconds between readings
  delay(2000);
}
