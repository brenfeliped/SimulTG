package node.application.TesteSimul;

simple TesteSimul like node.application.iApplication {
 parameters: 
 	string applicationID = default ("TesteSimul");
	bool collectTraceInfo = true;
	int priority = default (1);
	int packetHeaderOverhead = default (8);		
	int constantDataPayload = default (0);
	string nextRecipient = default ("0");			         
	double packet_rate = default (0);	
	double startupDelay = default (0);	
    bool broadcastReports = default(false);
	string reportDestination = default ("0");	

 gates:
 	output toCommunicationModule;
	output toSensorDeviceManager;
	input fromCommunicationModule;
	input fromSensorDeviceManager;
	input fromResourceManager;
}


