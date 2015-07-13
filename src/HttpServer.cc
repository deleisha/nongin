#include <cassert>
#include <cstdlib>
#include <cstdio>
#include "HttpServer.h"

namespace nongin {
namespace Http {

Server::Server(std::string addr, int p)
    :loop_(uv_default_loop())
    , socket_(new uv_tcp_t)
    , listenAddr_(addr)
    , port(p)
{
    uv_tcp_init(loop_, socket_);
    socket_->data = this;

    struct sockaddr_in bind_addr;
    int r = uv_ip4_addr(listenAddr_.c_str(), port, &bind_addr);
    assert(!r);

    r = uv_tcp_bind(socket_, (struct sockaddr*)&bind_addr, 0);
    if( r ) {
	fprintf( stderr, "bind: %s\n", uv_strerror(r));
	delete socket_;
	abort();
    }
}

Server::~Server()
{
    delete socket_;
}

bool Server::run()
{

    int rv = uv_listen((uv_stream_t*)socket_, 128, handle_connect);
    if( rv ) {
	fprintf( stderr, "listen: %s\n", uv_strerror(rv));
	return false;
    }

    //always return 0 for UV_RUN_DEFAULT
    uv_run(loop_, UV_RUN_DEFAULT);
    return true;
}

void Server::handle_connect(uv_stream_t *stream, int status)
{
    if(status) {
	return;
    }
    //aceept or reject the connection request
    Server *svc = (Server*)stream->data;
}

}}
