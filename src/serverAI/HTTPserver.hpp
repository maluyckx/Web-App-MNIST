#ifndef HTTPSERVER_HPP
#define HTTPSERVER_HPP


#include <string>
#include <sstream>
#include <iostream>

#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/HTTPServer.h>

#include <Poco/Net/HTTPRequestHandlerFactory.h>

#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

using namespace std;

class HTTPserver : public Poco::Util::ServerApplication{
    Poco::UInt16 _port = 2022;//default socket

public:
    HTTPserver(){init_server();}
    int init_server();
};


// Macros to setup maim function to run as app or deamon (service in windows)
POCO_SERVER_MAIN(HTTPserver);


#endif //HTTPSERVER_HPP