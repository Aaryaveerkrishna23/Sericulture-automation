#include <WiFi.h>        // Include the Wi-Fi library
#define RXp2 16
#define TXp2 17

const char* ssid     = "Burhanuddin";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "burhan001";     // The password of the Wi-Fi network

void setup() {
  Serial.begin(115200);         // Start the Serial communication to send messages to the computer
  delay(10);
  Serial.println('\n');
  
  WiFi.begin(ssid, password);             // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(ssid);

  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(10000);
    Serial.print('.');
  }

  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer

  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
}

void loop() {
    Serial.println("Message Received from Arduino: ");
    Serial.println(Serial2.readString());
    delay(20000);
}
