#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display width and height
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The I2C address can vary (0x3C or 0x3D). Use an I2C scanner sketch to find it if unsure.
#define SSD1315_I2C_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1); // -1 indicates no reset pin

void setup() {
  Serial.begin(115200);

  // Initialize the OLED display
  if(!display.begin(SSD1306_SWITCHCAPVCC, SSD1315_I2C_ADDRESS)) { // Address 0x3C for SSD1315 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Clear the buffer
  display.clearDisplay();

  // Set text color and size
  display.setTextColor(SSD1306_WHITE); // Set text color to white
  display.setTextSize(1);             // Set text size (1 is smallest)

  // Set cursor position and print text
  display.setCursor(0,0);             // Set cursor to top-left corner
  display.println("Hello, Arduino!");
  display.println("OLED Display");
  display.println("Test");

  // Display the buffer contents
  display.display();
}

void loop() {
  // Add your dynamic display updates here
}
