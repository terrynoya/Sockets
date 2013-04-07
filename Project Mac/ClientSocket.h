#ifndef _CLIENTSOCKET_H
#define _CLIENTSOCKET_H

#include "C++Sockets/SocketHandler.h"
#include "C++Sockets/TcpSocket.h"

#ifdef SOCKETS_NAMESPACE
namespace SOCKETS_NAMESPACE {
#endif
	
class ClientSocket : public TcpSocket
{
public:
	ClientSocket(SocketHandler& ,const std::string& );
	~ClientSocket();

	void OnConnect();
	void OnReconnect();
	void OnLine(const std::string& );

private:
	std::string m_cmd;
};

#ifdef SOCKETS_NAMESPACE
}
#endif

#endif // _CLIENTSOCKET_H
