#include <ESP8266WiFi.h>

// Replace with your Wi-Fi SSID and Password
const char* ssid = "Lenovo TAB 7";
const char* password = "12385674";

// Set the LED pin
const int ledPin = D1;  // GPIO5

WiFiServer server(80);

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // Start with the LED off

  // Start the Serial Monitor
  Serial.begin(115200);
  delay(10);
  
  // Connect to Wi-Fi
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Start the server
  server.begin();
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data
  while (!client.available()) {
    delay(1);
  }
  
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  
  // Match the request
  if (request.indexOf("/LED=ON") != -1)  {
    digitalWrite(ledPin, HIGH);   // Turn the LED on
  }
  if (request.indexOf("/LED=OFF") != -1)  {
    digitalWrite(ledPin, LOW);    // Turn the LED off
  }
  
  // Prepare the response
  String html = "<!DOCTYPE html><html>";
  html += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"></head>";
  html += "<body><h1>ESP8266 LED Control</h1>";
  html += "<p><a href=\"/LED=ON\"><button>Turn On</button></a></p>";
  html += "<p><a href=\"/LED=OFF\"><button>Turn Off</button></a></p>";
  html += "</body></html>";
  
  // Send the response to the client
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");
  client.println();
  client.println(html);
  
  // Close the connection
  client.stop();
  Serial.println("Client disconnected");
}
