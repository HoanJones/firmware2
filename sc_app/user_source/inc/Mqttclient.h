/*
 * Mqttclient.h
 *
 *  Created on: 
 *      Author: chungnt@epi-tech.com.vn
 *
 *      
*/
#ifdef __cplusplus
extern "C"
{
#endif

#ifndef _MQTTCLIENT_H_
#define _MQTTCLIENT_H_


/* ==================================================================== */
/* ========================== include files =========================== */
/* ==================================================================== */
/* Inclusion of system and local header files goes here */
#include "simcom_api.h"
#include <stdint.h>
#include <stdarg.h>
#include "variant.h"

#if(MQTT_EN)
/* ==================================================================== */
/* ============================ constants ============================= */
/* ==================================================================== */
/* #define and enum statements go here */
enum
{
  SERVER_TYPE_NO_SSL = 0,
  SERVER_TYPE_SSL = 1
};

typedef void (*connclost)(int clientIdx, int cause);
typedef void (*MQTTClientCallbackSimple)(char topic[], char payload[], unsigned int payloadLen);
// typedef void (*MQTTClientCallbackAdvanced)(MQTTClient *client, char topic[], char bytes[], int length);

#define DEFAULT_MQTT_CLIENT_NAME	  "chungnt"
#define DEFAULT_MQTT_CLI_IDX		    0
#define DEFAULT_MQTT_IPADD			    "broker.hivemq.com"
#define DEFAULT_MQTT_PORT			      1883
#define DEFAULT_MQTT_KEEP_TIME		  60
#define DEFAULT_MQTT_CLEAN_SESSION	1
#define DEFAULT_MQTT_QOS			      0
#define DEFAULT_MQTT_USERNAME		    "chungnt"
#define DEFAULT_MQTT_PASSWORD		    "12345678"
/* ==================================================================== */
/* ========================== public data ============================= */
/* ==================================================================== */
/* Definition of public (external) data types go here */
class MqttclientClass
{ 
  private:
    int clientIdx = 0;
    char *clientID = nullptr;
    int serverType = SERVER_TYPE_NO_SSL;
    char *serverAddr = nullptr;
    int port = 1883;
    int keepAliveTime = 60;
    int cleanSession = 1;
    char *username = nullptr;
    char *password = nullptr;
    int qos = 0;

    char **subtopic;
    int subtopicIdx = 0;

  public:
    connclost connclostCb;
    bool isConnected = false;
    MQTTClientCallbackSimple cbSimple = nullptr;

    MqttclientClass();
    void begin(const char _hostname[]) { this->begin(_hostname, 1883); }
    void begin(const char _hostname[], int _port);

    void setClientId(const char _clientID[]);
    void setServerType(int serverType);
    void setHost(const char _serverAddr[], int port);
    void setKeepAlive(int keepAliveTime); 
    void setCleanSession(int cleanSession);
    void setUserName(const char _username[]);
    void setPassword(const char _password[]);
    void setConnLostCb(connclost _cb);
    
    int connect(const char _clientID[], const char _username[], const char _password[]);
    bool connected();
    int subscribe(const char _topic[], int _qos);
    void onMessage(MQTTClientCallbackSimple _callback);
    int publish(const char _topic[], int _qos, const char _payload[]) {
      publish(_topic, _qos, 60, _payload);
    }
    // int publish(const char _topic[], int _qos, int _timeout, const char _payload[]);
    int publish(const char _topic[], int _qos, int _timeout, const char* _payload, ...);
};

#define MQTT_Callback_Check_Null       ((Mqttclient.cbSimple == nullptr)?1:0)
#define MQTT_Callback_Process(a, b, c) Mqttclient.cbSimple(a, b, c)

extern MqttclientClass Mqttclient;
/* ==================================================================== */
/* ======================= public functions =========================== */
/* ==================================================================== */
/* Function prototypes for public (external) functions go here */


#endif
#ifdef __cplusplus
}
#endif

#endif
