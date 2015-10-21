#ifndef NONGIN_HTTP_ACCEPTOR_H
#define NONGIN_HTTP_ACCEPTOR_H

#include <iostream>
#include <memory>
#include "libuv/include/uv.h"


namespace nongin {
namespace Http {


class Acceptor
{

    public:
	Acceptor( std::string addr, int port);
	~Acceptor();
	bool bind();
	int listen();
	accept();
	disconnect();
	bool unbind();

    private:
	//loop this acceptor works with
	uv_loop_t *loop_;

	uv_tcp_t  *socket_;
	std::string listenAddr_;
	int port;
};


}
}

#endif
