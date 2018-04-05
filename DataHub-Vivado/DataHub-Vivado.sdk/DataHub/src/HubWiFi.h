#ifndef HUB_WIFI_H
#define HUB_WIFI_H

#include "Messages.h"

// Forward declarations
class UDPSocket;
class UDPServer;
#define IPSTATUS uint32_t

//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
// Sockets for each of the nodes
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------

// A maximum of 4 nodes will attempt to connect to the HUB
#define MAX_CONNECTED_NODES 4

// Instantiation of the server class
static UDPServer hubServer;
// Worker socket
static UDPSocket udpSocket;
// Additional sockets for the server (1 per node)
static UDPSocket nodeSockets[MAX_CONNECTED_NODES];

// TODO: check if these need to be extern
// Stores the number of nodes that are connected to the Hub
static uint8_t numConnectedNodes;

// TODO: need one more data structure to keep track of specifically who is connected so some can be rejected

// A data structure that will keep track of how many health 
// msgs a particular node has missed
static int numSysHealthNotAcked[MAX_CONNECTED_NODES];

//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
// System Health
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------

// A data structure to keep the current system health
static SystemHealthPayload currentSysHealth;

//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
// Sensor Data
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------

////////////////////////////////////////////////////////////////
// 	Summary:
// 		The struct and size to be used for sensor data
//
// 	Returns:
// 		N/A
static const uint16_t SENSOR_DATA_SIZE = 1019;
typedef uint8_t SensorData[SENSOR_DATA_SIZE];
struct SensorDataPayload
{
    uint8_t sensorID;
    SensorData sensorData;
};

////////////////////////////////////////////////////////////////
// 	Summary:
// 		An attempt at establishing a connection
//		to the network specified in Config.h will be made
//
// 	Returns:
// 		TRUE -> if a connection to the Data Hub was established
// 		FALSE -> if a connection to the Data Hub was not established
bool Connect(UDPSocket* udpSocket, IPSTATUS* status);

////////////////////////////////////////////////////////////////	
// 	NOTE: 
//		This function is not guaranteed to finish execution
//		within the specified time if it is busy responding
//		to a message it received.
bool WiFiListenForXMillisAndRespond(UDPSocket* udpSocket, uint32_t waitTime_ms);

void HandleConnReq(Message* msg, UDPSocket* udpSocket);
bool SendHealth(Message* msg, UDPSocket* udpSocket); 	 
bool DistribHealthToConnectedNodes(Message* msg, UDPSocket* udpSocket);

//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
// Helper Functions
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
bool SendMessage(Message* msg, UDPSocket* udpSocket, IPSTATUS* status, SensorNodeIds destId);
bool WaitXMillisForMsgOfSpecifiedType(uint32_t waitTime_ms, MsgTypes typeWanted, Message* msg, UDPSocket* udpSocket);
uint32_t RecvMessage(Message* msg, UDPSocket* udpSocket);
uint32_t ElapsedMilliSeconds(uint32_t start, uint32_t current);
void PrintSensorNodeId(SensorNodeIds id);
void PrintMsgTypeAndDest(MsgTypes msgType, SensorNodeIds destId);
void PrintMsgType(MsgTypes msgType);

#endif // HUB_WIFI_H