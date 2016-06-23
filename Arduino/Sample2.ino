// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// MCP23017_I2CR16G5LE
// This code is designed to work with the MCP23017_I2CR16G5LE_10A I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/Relay-Controller?sku=MCP23017_I2CR16G5LE_10A#tabs-0-product_tabset-2

#include <Wire.h>

// MCP23017_I2CR16G5LE I2C address is 0x20(32)
#define Addr 0x20

int data;
void setup()
{
  // Initialise I2C communication as MASTER
  Wire.begin();
  // Initialise serial communication, set baud rate = 9600
  Serial.begin(9600);

  // Start I2C Transmission
  Wire.beginTransmission(Addr);
  // Select IODIRA register
  Wire.write(0x00);
  // All pins of port-A are configured as output
  Wire.write(0x00);
  // Stop I2C transmission
  Wire.endTransmission();

  // Start I2C Transmission
  Wire.beginTransmission(Addr);
  // Select IODIRB register
  Wire.write(0x01);
  // All pins of port-B are configured as output
  Wire.write(0x00);
  // Stop I2C transmission
  Wire.endTransmission();
  delay(500);
}

void loop()
{
  // Turning all relays ON, one by one
  data = 0x01;
  for (int i = 0; i < 8; i++)
  {
    // Start I2C Transmission
    Wire.beginTransmission(Addr);
    // Select GPIOA register
    Wire.write(0x12);
    // All pins of port-A are set to logic HIGH
    Wire.write(data);
    // Stop I2C transmission
    Wire.endTransmission();

    // Output data to serial monitor
    Serial.print("Turning Relay ");
    Serial.print(i);
    Serial.println(" of Port-A ON");
    data = data << 1;
    data = data + 1;
    delay(500);
  }

  data = 0x01;
  for (int i = 0; i < 8; i++)
  {
    // Start I2C Transmission
    Wire.beginTransmission(Addr);
    // Select GPIOB register
    Wire.write(0x13);
    // All pins of port-B are set to logic HIGH
    Wire.write(data);
    // Stop I2C transmission
    Wire.endTransmission();

    // Output data to serial monitor
    Serial.print("Turning Relay ");
    Serial.print(i);
    Serial.println(" of Port-B ON");
    data = data << 1;
    data = data + 1;
    delay(500);
  }

  // Turning all relays OFF, one by one
  data = 0xFE;
  for (int i = 0; i < 8; i++)
  {
    // Start I2C Transmission
    Wire.beginTransmission(Addr);
    // Select GPIOA register
    Wire.write(0x12);
    // All pins of port-A are set to logic LOW
    Wire.write(data);
    // Stop I2C transmission
    Wire.endTransmission();

    // Output data to serial monitor
    Serial.print("Turning Relay ");
    Serial.print(i);
    Serial.println(" of Port-A OFF");
    data = data << 1;
    delay(500);
  }

  data = 0xFE;
  for (int i = 0; i < 8; i++)
  {
    // Start I2C Transmission
    Wire.beginTransmission(Addr);
    // Select GPIOB register
    Wire.write(0x13);
    // All pins of port-B are set to logic LOW
    Wire.write(data);
    // Stop I2C transmission
    Wire.endTransmission();

    // Output data to serial monitor
    Serial.print("Turning Relay ");
    Serial.print(i);
    Serial.println(" of Port-B OFF");
    data = data << 1;
    delay(500);
  }
}
