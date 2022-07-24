#include <DHT.h>
#include <WiFi.h>        // Include the Wi-Fi library



#define RELAY_BUZZER_PIN  2  // ESP32 pin GIOP27, which connects to the IN pin of relay
#define DHT_SENSOR_PIN  15 // ESP32 pin GIOP21 connected to DHT11 sensor
#define DHT_SENSOR_TYPE DHT11

#define TEMP_UPPER_THRESHOLD  20 // upper temperature threshold
#define TEMP_LOWER_THRESHOLD  15 // lower temperature threshold

#define Humid_UPPER_THRESHOLD  100 // upper temperature threshold
#define Humid_LOWER_THRESHOLD  65 // lower temperature threshold

// -------------------------------------------
const char* ssid     = "Burhanuddin";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "burhan001";     // The password of the Wi-Fi network

char thingSpeakAddress[] = "api.thingspeak.com";

String APIKey = "QWN6SQ0Z75QM68BY";              //enter your channel's Write API Key

const int updateThingSpeakInterval = 20 * 1000;  // 20 second interval at which to update ThingSpeak

DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);


void setup() {
  Serial.begin(115200);         // Start the Serial communication to send messages to the computer
  delay(10);
  Serial.println('\n');
  
  WiFi.begin(ssid, password);             // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(ssid);

  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(500);
    Serial.print('.');
  }

  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP()); 
  
  dht_sensor.begin(); // initialize the DHT sensor
  
}


// ---------------------------------------------------------

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
