#include "HTTPserver.hpp"
#include "Handler.hpp"


using namespace std;

int HTTPserver::init_server(){
	Poco::Net::ServerSocket socket(_port);



    Poco::Net::HTTPServerParams *pParams = new Poco::Net::HTTPServerParams();
    //Sets the maximum number of queued connections.
    pParams->setMaxQueued(100);
    //Sets the maximum number of simultaneous threads available for this Server
    pParams->setMaxThreads(120);
          // Instanciate HandlerFactory
    Poco::Net::HTTPServer server(new Handler::HandlerFactory, socket, pParams);
	server.start();
	std::cout << "STARTING SERVER..." << std::endl;
	waitForTerminationRequest();
    std::cout << "CLOSING SERVER..." << std::endl;
    server.stop();

    return EXIT_OK;
}

//int main(){}