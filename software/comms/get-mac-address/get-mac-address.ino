// google AI summary code
#include "BluetoothSerial.h"
#include "esp_bt_device.h" // Essential for accessing the address

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Address_Test"); // Name to show in discovery

  delay(1000); // Give time for setup

  // Retrieve and print the address
  const uint8_t* point = esp_bt_dev_get_address();
  Serial.print("Bluetooth Device Address: ");
  for (int i = 0; i < 6; i++) {
    char str[3];
    sprintf(str, "%02X", point[i]);
    Serial.print(str);
    if (i < 5) Serial.print(":");
  }
}

void loop() {}
