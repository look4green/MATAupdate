#include "PluginManager.h"
#include "Plugin.h"
#include "Display.h"

// Example plugin — LoRa stub
class LoRaPlugin : public Plugin {
public:
  void init() override {
    drawStatus("LoRa plugin initialized");
  }

  void update() override {
    // Future: LoRa packet capture or decoding
  }

  String getName() override {
    return "LoRa Sniffer";
  }
};

// Plugin registry
#define MAX_PLUGINS 5
Plugin* pluginList[MAX_PLUGINS];
int pluginCount = 0;

void initPlugins() {
  pluginCount = 0;

  // Add active plugin modules here
  pluginList[pluginCount++] = new LoRaPlugin();
  // pluginList[pluginCount++] = new GPSPlugin(); // Future additions

  // Initialize all plugins
  for (int i = 0; i < pluginCount; i++) {
    pluginList[i]->init();
  }
}

void updatePlugins() {
  for (int i = 0; i < pluginCount; i++) {
    pluginList[i]->update();
  }
}

void listPlugins() {
  clearScreen();
  for (int i = 0; i < pluginCount; i++) {
    String msg = "Plugin: " + pluginList[i]->getName();
    drawStatus(msg.c_str());  // ✅ Fixed conversion to const char*
    delay(500);  // Brief visual per module
  }
}