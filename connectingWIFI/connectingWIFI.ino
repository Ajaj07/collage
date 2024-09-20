#include <ESP8266WiFi.h>

const char* ssid = "Lenovo TAB 7";       // Replace with your Wi-Fi SSID
const char* password = "12385674";   // Replace with your Wi-Fi Password

void setup() {
  Serial.begin(115200);   // Start Serial Monitor
  delay(10);
  
  Serial.println("Setup started");  // Debugging line
  Serial.println("Connecting to WiFi...");
  
  // Connect to Wi-Fi network
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());   // Print the IP address
}

void loop() {
  // Add your main code here, to run repeatedly:
}
