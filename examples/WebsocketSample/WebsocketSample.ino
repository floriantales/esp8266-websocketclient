#include "WebSocketClient.h"
#include "ESP8266WiFi.h"

WebSocketClient ws(true);	// Set true for wss

void setup() {
	Serial.begin(115200);
	Serial.println();
	WiFi.begin("MyWifi", "secret");

	Serial.print("Connecting");
	while (WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print(".");
	}
	Serial.println();
}

void loop() {
	if (!ws.isConnected()) {
		Serial.println("Connecting to websocket ..");
		ws.connect("echo.websocket.org", "/", 443);
	} else {
		Serial.println("Sending to websocket ..");
		ws.send("hello");

		String msg;
		if (ws.getMessage(msg)) {
			Serial.printf("WS Response : %s \n", msg.c_str());
		}
	}
	delay(500);
}
