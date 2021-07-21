
#include "TesteSimul.h"

Define_Module(TesteSimul);

void TesteSimul::startup()
{
  trace() << " inicio";
  packet_rate = par("packet_rate");
  recipientAddress = par("nextRecipient").stringValue();
  startupDelay = par("startupDelay");
  packet_spacing = 1 / packet_rate;
  dataSN = 0;

  setTimer(SEND_PACKET, packet_spacing + startupDelay);
}

void TesteSimul::fromNetworkLayer(ApplicationPacket *rcvPacket, const char *source, double rssi, double lqi)
{
  int sequenceNumber = rcvPacket->getSequenceNumber();
  trace() << "Pacote " << sequenceNumber << " recebido do no " << source;
}

void TesteSimul::timerFiredCallback(int index)
{
  switch (index)
  {
  case SEND_PACKET:
  {
    int tamanho = rand() % 2000;
    trace() << "Mandando pacote " << dataSN;
    trace() << "Tamanho pacote " << tamanho; // Tamanho sem header
    toNetworkLayer(createGenericDataPacket(0, dataSN), par("nextRecipient"));
    dataSN++;
    setTimer(SEND_PACKET, packet_spacing);
    break;
  }
  }
}

void TesteSimul::finishSpecific()
{
  trace() << "fim";
}
