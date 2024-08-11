#include <WiFi.h>
#include <ESPAsyncWebServer.h>

// Set up the WiFi credentials
const char* ssid = "NADER_SERVER";
const char* password = "12345678";

// Create an AsyncWebServer object
AsyncWebServer server(80);

void setup() {
  // Start the serial communication
  Serial.begin(115200);

  // Set up the WiFi Access Point
  WiFi.softAP(ssid, password);
  
  // Print the IP address of the Access Point
  Serial.println("Access Point Started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  // Serve a simple HTML page on the root path
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", "<html><body><h1>hi</h1></body></html>");
  });

  // Start the server
  server.begin();
}

void loop() {
  // Nothing to do here
}
