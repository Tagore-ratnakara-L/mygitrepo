#include <RadioHead.h>
#include <RHCRC.h>
#include <RHDatagram.h>
#include <RHEncryptedDriver.h>
#include <RHGenericDriver.h>
#include <RHGenericSPI.h>
#include <RHHardwareSPI.h>
#include <RHMesh.h>
#include <RHNRFSPIDriver.h>
#include <RHReliableDatagram.h>
#include <RHRouter.h>
#include <RHSoftwareSPI.h>
#include <RHSPIDriver.h>
#include <RHTcpProtocol.h>
#include <RH_ASK.h>
#include <RH_CC110.h>
#include <RH_E32.h>
#include <RH_MRF89.h>
#include <RH_NRF24.h>
#include <RH_NRF51.h>
#include <RH_NRF905.h>
#include <RH_RF22.h>
#include <RH_RF24.h>
#include <RH_RF69.h>
#include <RH_RF95.h>
#include <RH_Serial.h>
#include <RH_TCP.h>

#include <RH_ASK.h> // Include RadioHead Amplitude Shift Keying Library
#include <SPI.h> // Include dependant SPI Library

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;

void setup()
{
// Initialize ASK Object
rf_driver.init();
// Setup Serial Monitor
Serial.begin(9600);
}

void loop()
{
const char *msg = "Hello World";
rf_driver.send((uint8_t *)msg, strlen(msg));
rf_driver.waitPacketSent();
{
// Message Transmitted
Serial.println("Message Transmitted: ");
delay(1000);
}
}