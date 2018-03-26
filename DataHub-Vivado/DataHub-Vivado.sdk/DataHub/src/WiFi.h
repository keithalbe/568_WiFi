#ifndef WIFI_H
#define WIFI_H

#include "Messages.h"

// Forward declarations
class UDPSocket;
#define IPSTATUS uint32_t

////////////////////////////////////////////////////////////////
// 	Summary:
// 		Handles all initialization needed for the WiFi Pmod
//
// 	Returns:
// 		VOID
void InitWiFi();

////////////////////////////////////////////////////////////////
// 	Summary:
// 		IF DATA HUB -> An attempt at establishing a connection
//		to the network specified in Config.h will be made
//
// 		IF SENSOR NODE -> An attempt at establishing a
//		connection to the network specified in Config.h will be
// 		made, and attempt to establish a connection with the
//		Data Hub
//
// 	Returns:
// 		TRUE -> if a connection to the Data Hub was established
// 		FALSE -> if a connection to the Data Hub was not established
bool Connect(UDPSocket* udpSocket, IPSTATUS* status);

////////////////////////////////////////////////////////////////
// 	Summary:
// 		Sends a connection request to the Data Hub. If the hub
// 		does not respond with a system health message within 1
//		second, then the connection attempt will be deemed a
//		failure
//
// 	Returns:
// 		TRUE -> if a connection to the Data Hub was established
// 		FALSE -> if a connection to the Data Hub was not
//		established
bool ConnectToHub(UDPSocket* udpSocket, IPSTATUS* status);

////////////////////////////////////////////////////////////////
// 	Summary:
// 		Register each sensor belonging to the current node
// 		one-by-one allowing 250ms for the Data Hub to respond
// 		to confirm the registration of each sensor. Any
// 		registration is only deemed a success if the
//		registration is acknowledged by the Data Hub.
//
// 	Returns:
// 		TRUE -> if all sensors were successfully registered
// 		FALSE -> if any sensor could not be registered
bool RegisterSensors(UDPSocket* udpSocket, IPSTATUS* status);

void StoreSystemHealthState(Message* sysHealthMsg);

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

#endif // WIFI_H