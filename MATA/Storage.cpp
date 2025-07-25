#include "Storage.h"
#include <SD.h>
#include <ArduinoJson.h>
#include "Display.h"
#include "AppState.h"
#include "RF.h"

bool initStorage() {
  if (!SD.begin()) {
    drawStatus("SD init failed");
    return false;
  }
  drawStatus("SD ready");
  return true;
}

bool loadProfile(const String& filename) {
  File file = SD.open("/profiles/" + filename);
  if (!file) {
    drawStatus("Profile not found");
    return false;
  }

  StaticJsonDocument<256> doc;
  DeserializationError error = deserializeJson(doc, file);
  file.close();

  if (error) {
    drawStatus("Profile format error");
    return false;
  }

  String modeStr = doc["mode"];
  int chan = doc["targetChannel"];
  int duration = doc["duration"];
  String power = doc["powerLevel"];

  // Mode dispatch
  if (modeStr == "DEAUTH_ATTACK") {
    setNRFFrequency(chan);
    currentState = DEAUTH_ATTACK;
  } else if (modeStr == "PACKET_SNIFF") {
    currentState = PACKET_SNIFF;
  } else {
    currentState = STATUS_SCREEN;
  }

  String msg = "Loaded: " + filename;
  drawStatus(msg.c_str());  // ✅ Safe conversion

  return true;
}

void listFiles(const String& folder) {
  File dir = SD.open(folder);
  if (!dir) {
    drawStatus("Folder not found");
    return;
  }

  clearScreen();
  while (true) {
    File entry = dir.openNextFile();
    if (!entry) break;

    String filename = String(entry.name());
    String msg = "Found: " + filename;
    drawStatus(msg.c_str());  // ✅ Safe conversion
    delay(500);

    entry.close();
  }
}

void logEvent(const String& data) {
  File log = SD.open("/logs/events.txt", FILE_APPEND);
  if (!log) return;
  log.println(data);
  log.close();
}