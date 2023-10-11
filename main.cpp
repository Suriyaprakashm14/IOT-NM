#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
// Replace with your network credentials
Const char* ssid = “Your_SSID”;
Const char* password = “Your_PASSWORD”;
WebServer server(80);
// Initialize OLED display
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Void setup() {
// Connect to Wi-Fi
WiFi.begin(ssid, password);
While (WiFi.status() != WL_CONNECTED) {
Delay(1000);
Serial.println(“Connecting to WiFi…”);
}
// Initialize OLED display
If(!display.begin(SSD1306_I2C_ADDRESS, OLED_RESET)) {
Serial.println(F(“SSD1306 allocation failed”));
For(;;);
}
Display.display();
Delay(2000);
// Web server routes
Server.on(“/”, HTTP_GET, handleRoot);
Server.begin();
Serial.println(“HTTP server started”);
}
Void loop() {
Server.handleClient();
}
Void handleRoot() {
Display.clearDisplay();
Display.setTextSize(1);
Display.setTextColor(SSD1306_WHITE);
Display.setCursor(0, 0);
Display.println(“Welcome to Traffic”);
Display.println(“Management System”);
Display.display();
Server.send(200, “text/html”, “Welcome to Traffic Management System”);
}
