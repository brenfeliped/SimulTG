
#ifndef _TesteSimul_H_
#define _TesteSimul_H_

#include "VirtualApplication.h"

#define REPROGRAM_PACKET_NAME "Teste Simul reprogram packet"
#define REPORT_PACKET_NAME "Teste Simul report packet"


using namespace std;

enum TesteSimulTestTimers {
	SEND_PACKET = 1
};

class TesteSimul :public VirtualApplication {
	private:
		double packet_rate;
		string recipientAddress;
		double startupDelay;
		float packet_spacing;
		int dataSN;
	
 	protected:
		virtual void startup();
		void finishSpecific();
		void fromNetworkLayer(ApplicationPacket *, const char *, double RSSI, double LQI);
	    void timerFiredCallback(int index);
};

#endif				
