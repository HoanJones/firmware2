/*
 * main.cpp
 *
 *  Created on: 
 *      Author: chungnt@epi-tech.com.vn
*/
/* ==================================================================== */
/* ========================== include files =========================== */
/* ==================================================================== */

/* Inclusion of system and local header files goes here */
#include "app.h"
#include "wiring_digital.h"
#include "delay.h"
#include "Exti_interrupts.h"
#include "HardwareSerial.h"
#include "Wire.h"
#include "SPI.h"
#include "Network.h"
#include "Mqttclient.h"
/* ==================================================================== */
/* ============================ constants ============================= */
/* ==================================================================== */
const uint8_t sgp30 = 0x58;
/* ==================================================================== */
/* ======================== global variables ========================== */
/* ==================================================================== */
/* Global variables definitions go here */
uint8_t iaq_int[2] = {0x20, 0x03};
uint8_t measure_iaq[2] = {0x20, 0x08};

/* ==================================================================== */
/* ========================== private data ============================ */
/* ==================================================================== */
/* Definition of private datatypes go here */
// static inline uint8_t exti_check = 0;
uint16_t eCO2 = 0;
uint16_t PVOC = 0;
uint8_t buffer[6] = {0};

// char buffer[128] = {};
// int len;

// char buffer1[128] = {};
// int len1;

// int count = 0;

// char ds1307_Data[7];
// char ds1307_DataWrite[7] = {0, 1, 2, 3};

#if(MQTT_EN)
// MqttclientClass Mqttclient;
bool connected = false;
#endif
/* ==================================================================== */
/* ====================== private functions =========================== */
/* ==================================================================== */
/* Function prototypes for private (static) functions go here */
// static void channel5_extiHandler(void)
// {
//     exti_check = 1;
// }

// SPISettings Mysettings(SPI_CLOCK_812KHz, MSBFIRST, SPI_MODE0);

#if(MQTT_EN)
void Mqtt_cb(char topic[], char payload[], unsigned int payloadLen)
{
    LOG_W("/*============= Mqtt callback start =============*/\r\n"); 
    LOG_W("receive topic: %s\r\n", topic);
    LOG_W("receive payload: %s, len: %d\r\n", payload, payloadLen); 
    LOG_W("/*============== Mqtt callback end ==============*/\r\n"); 
}
#endif
/* ==================================================================== */
/* ===================== All functions by section ===================== */
/* ==================================================================== */
/* Functions definitions go here, organised into sections */
void setup(void)
{
    //Network.init();

    pinMode(NETLIGHT_PIN, OUTPUT);
    // pinMode(A76xx_D6, INPUT_PULLUP);
    // attachInterrupt(EXTI_CHANNEL5, channel5_extiHandler, EXTI_FALLING);
    // Serial.begin(115200);
    // Serial1.begin(9600);

    // Wire.lcdInit(0X20);
    // Wire.write(0x68, 0x00, ds1307_DataWrite, 4);

    // SPI.setCsMode(CSmode_GPIO);

    // pinMode(A76xx_D7, OUTPUT);
    // digitalWrite(A76xx_D7, HIGH);

    // SPI.begin();
    
    // SPI.beginTransaction(Mysettings);

    //Mqttclient.begin(DEFAULT_MQTT_IPADD);
    Wire.begin(sgp30<<1);
    Wire.write(sgp30<<1, 0x00, iaq_int, 2);
    delay(10);
}

void loop(void)
{
    delay(1000);
    // digitalToggle(NETLIGHT_PIN);
    // if((connected == 0) && Network.isOnline())
    // {
    //     Mqttclient.connect(DEFAULT_MQTT_CLIENT_NAME, nullptr, nullptr);
    //     Mqttclient.subscribe("chungnt/control", 0);
    //     Mqttclient.subscribe("chungnt/control1", 0);
    //     Mqttclient.subscribe("chungnt/control2", 0);
    //     Mqttclient.onMessage(Mqtt_cb);
    // }

    // connected = Mqttclient.connected();

    // Mqttclient.publish("chungnt/test", 0, 60, "hello chungnt %d", count++);
    // LOG_I("digitalRead = [%d]\r\n", digitalRead(A76xx_D6));
    // if(exti_check == 1)
    // {
    //     exti_check = 0;
    //     LOG_I("channel5_extiHandler\r\n");
    // }
    // Serial.print("Hello\r\n");
    // len = Serial.available();
    // if(len > 0) 
    // {
    //     memset(buffer, 0, sizeof(buffer));
    //     Serial.readBytes(buffer, len);
    //     Serial.print("Serial: %s\r\n", buffer);
    //     LOG_W("Len [%d] Serial: %s\r\n", len, buffer);
    //     if(strstr(buffer, "change"))
    //     {
    //         Serial.setBufferRxSize(40);
    //     }
    // }

    // len1 = Serial1.available();
    // if(len1 > 0) 
    // {
    //     memset(buffer1, 0, sizeof(buffer1));
    //     Serial1.readBytes(buffer1, len1);
    //     Serial1.print("Serial1: %s\r\n", buffer1);
    //     LOG_W("Serial1: %s\r\n", buffer1);
    // }

    // Wire.lcdGotoXY(2, 0);
    // Wire.lcdPrint("Count: %d", count);
    // count++;
    // Wire.read(0x68, 0x00, ds1307_Data, 4);
    // LOG_I("ds1307_Data [0x%02x] [0x%02x] [0x%02x] [0x%02x]\r\n", ds1307_Data[0], ds1307_Data[1], ds1307_Data[2], ds1307_Data[3]);

    // digitalWrite(A76xx_D7, LOW);
    // SPI.transfer(0xAA);
    // SPI.transfer("Hello");
    // digitalWrite(A76xx_D7, HIGH);

    // LOG_W("CSQ: %d, CGREG: %d\r\n", Network.getCSQ(), Network.getCgreg());

    Wire.write(sgp30<<1, 0x00, measure_iaq, 2);
    delay(220);
    Wire.read(sgp30<<1, 0x00, buffer, 1);
    // eCO2 = (buffer[0] << 8) | buffer[1];
    // PVOC = (buffer[3] << 8) | buffer[4];
    //LOG_W("eCO2: %d \tPVOC: %d\r\n", eCO2, PVOC);
    LOG_W("buffer: 0x%02x", buffer[0]);
}
/* ==================================================================== */
/* ========================= private functions ======================== */
/* ==================================================================== */

/*********************************************************************//**
 * @brief   
 * @param
 * @retval  
 ************************************************************************/

