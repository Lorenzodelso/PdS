#include <iostream>
#include "NetworkServer.h"

int main() {
    NetworkServer server;
    SharedEditor ed1(server);
    SharedEditor ed2(server);

    ed1.localInsert(0,'c');
    ed1.localInsert(1,'a');
    ed1.localInsert(2,'t');

    server.dispatchMessages();
    std::cout << ed1.to_string() << std::endl;
    std::cout << ed2.to_string() << std::endl;

    ed1.localInsert(1,'h');
    ed2.localErase(1);

    server.dispatchMessages();
    std::cout << ed1.to_string() << std::endl;
    std::cout << ed2.to_string() << std::endl;

    return 0;
}