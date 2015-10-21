#ifndef HTTP_CONNECTION_H_
#define HTTP_CONNECTION_H_

namespace nongin {
namespace Http {

class Connection
{
    public:
    Connection();

    private:
    uv_tcp_t *clientSocket_;

    http_parser parser_;

    HttpRequest request_;

    HttpResponse response_;

    uv_write_t writer_;

    Server *server_;
};

}}



#endif
