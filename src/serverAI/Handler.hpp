#ifndef HANDLER_HPP
#define HANDLER_HPP

#include <string>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <iostream>
#include <Python.h>


#include <Poco/Util/ServerApplication.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/HTTPServer.h>

#include <Poco/Net/HTTPRequestHandlerFactory.h>

#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

namespace Handler{

//First page
class ErrorHandler: public Poco::Net::HTTPRequestHandler{
public:
	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
};

class FetchHandler: public Poco::Net::HTTPRequestHandler{
public:
	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
};

//Image Gestion

class ImageHandler: public Poco::Net::HTTPRequestHandler{
public:
	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response);
};


//  Url Router
class HandlerFactory : public Poco::Net::HTTPRequestHandlerFactory{
	//attribut for global AI ?

	//attribut for own AI
	//IAGame
public:
	Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest &request);
};




}
#endif