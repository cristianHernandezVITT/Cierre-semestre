#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <HTTPClient.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const char* ssid = "AP-Taller";
const char* password = "Ccomputo0908";
const char* openaiApiKey = "sk-proj-GaXhrLJQVUEnpMlUAD5JT3BlbkFJziy6HO4eTtDngS3AdA9n";

void setup() {
  Serial.begin(115200);
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  Serial.println("Connected to WiFi");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin("https://api.openai.com/v1/engines/davinci-codex/completions");
    http.addHeader("Content-Type", "application/json");
    http.addHeader("Authorization", String("Bearer ") + openaiApiKey);
    
    String payload = "{\"prompt\":\"¿Cuéntame un chiste?\",\"max_tokens\":60,\"temperature\":0.5,\"n\":1,\"stop\":\"\\n\"}";
    
    int httpResponseCode = http.POST(payload);
    
    if (httpResponseCode == HTTP_CODE_OK) {
      String response = http.getString();
      int start = response.indexOf("\"text\":\"") + 8;
      int end = response.indexOf("\",\"index\"");
      String answer = response.substring(start, end);
      
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0, 0);
      display.println(answer);
      display.display();
    } else {
      Serial.println("HTTP request failed");
    }
    
    http.end();
  }
  
  delay(10000); // Wait for 10 seconds before making another request
}