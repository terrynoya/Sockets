#include "ClientSocket.h"
#include "C++Sockets/StdoutLog.h"

int main(int argc,char *argv[])
{
	if (true)
	{
		sockets::StdoutLog *log = new sockets::StdoutLog();
		
		sockets::SocketHandler h(log);
		sockets::ClientSocket cc(h,"Test Socket");
		
		cc.SetConnectTimeout(1);
		cc.SetConnectionRetry(-1);	// Always
		
		cc.SetReconnect(true);
		
		cc.Open("127.0.0.1", 4001);
		// Add after Open
		h.Add(&cc);
		h.Select(1,0);
		while (h.GetCount())
		{
			h.Select(1,0);
		}
	}
}
