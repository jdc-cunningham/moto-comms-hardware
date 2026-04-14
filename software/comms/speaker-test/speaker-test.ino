#include "AudioTools.h"
#include "BluetoothA2DPSink.h"

#define DIN_PIN 18   // serial data
#define LRCK_PIN 27  // word select
#define BCLK_PIN 19  // serial clock

I2SStream i2s;
BluetoothA2DPSink a2dp_sink(i2s);

void setup() {
  Serial.begin(115200);
  AudioLogger::instance().begin(Serial, AudioLogger::Info);

  auto config = i2s.defaultConfig();
  config.pin_bck = BCLK_PIN;

  config.pin_ws = LRCK_PIN;
  config.pin_data = DIN_PIN;  
  i2s.begin(config);

  a2dp_sink.start("MyMusic1");
}

void loop() { }