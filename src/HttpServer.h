#ifndef NONGIN_HTTP_SERVER_H
#define NONGIN_HTTP_SERVER_H

#include <iostream>
#include "libuv/include/uv.h"
namespace nongin
{
namespace Http
{


class Server
{

    public:
	Server( std::string addr, int port);
	~Server();
	bool run();

	static void handle_connect(uv_stream_t *server, int status);
    private:
	uv_loop_t *loop_;
	uv_tcp_t *socket_;
	std::string listenAddr_;
	int port;
};


}
}

#endif
