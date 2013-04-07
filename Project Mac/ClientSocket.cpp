#include <stdio.h>

#include "ClientSocket.h"

#ifdef SOCKETS_NAMESPACE
namespace SOCKETS_NAMESPACE {
#endif
	
ClientSocket::ClientSocket(SocketHandler& h,const std::string& cmd)
:TcpSocket(h)
,m_cmd(cmd)
{
	SetLineProtocol();
}


ClientSocket::~ClientSocket()
{
}


void ClientSocket::OnConnect()
{
	Send(m_cmd + "\n");
}

void ClientSocket::OnReconnect()
{
	Send(m_cmd + "\n");
}



void ClientSocket::OnLine(const std::string& line)
{
	printf("Reply from server: '%s'\n",line.c_str());
	if (line.size())
	{
	}
	else
	{
		SetCloseAndDelete();
	}
}

#ifdef SOCKETS_NAMESPACE
}
#endif


