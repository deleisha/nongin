#include "src/HttpServer.h"

using namespace nongin::Http;

int main()
{
    Server server(std::string("0.0.0.0"), 8000);

    std::cout << "Hello World\n";
    server.run();
    return 0;
}
