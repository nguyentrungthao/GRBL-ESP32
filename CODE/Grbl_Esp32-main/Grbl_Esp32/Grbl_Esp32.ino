/*
  Grbl_ESP32.ino - Header for system level commands and real-time processes
  Part of Grbl
  Copyright (c) 2014-2016 Sungeun K. Jeon for Gnea Research LLC

  2018 -	Bart Dring This file was modified for use on the ESP32
          CPU. Do not use this with Grbl for atMega328P

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

//! đã sửa đổi ở file WebSocKets.cpp  tại  .../document/Arduino/libraries/ArduinoWebSocket
//! đã sửa đổi ở file I2SOut.cpp      tại ./src/
//! đã sửa đổi ở file Stepper.cpp     tại ./src/
//! đã sửa đổi ở file task.h          tại ./src/
//! đã sửa đổi ở file Serial.cpp      tại ./src/
#include "src/Grbl.h"

void setup() {
  grbl_init();
  xTaskCreate(xTaskMain, "task main", 2048, NULL, 1, NULL);
}
// vòng loop là task có độ ưu tiên 1
void loop() {
  run_once();
  uint8_t i = 0;
}

void xTaskMain(void* pvPrameter) {
  pinMode(2, OUTPUT);
  while (1) {
    grbl_send_str("G0 X10 Y10 Z10");
    digitalWrite(2, 1);
    delay(100);
    digitalWrite(2, 0);
    delay(100);
  }
}
