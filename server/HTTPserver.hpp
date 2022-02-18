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


// Page renderer for / uri

class MyPageHandler: public Poco::Net::HTTPRequestHandler
{
public:

	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)override{
		        response.setChunkedTransferEncoding(true);
				std::cout << response.getStatus()<< std::endl;
				response.setContentType("text/html");
				response.sendFile("/home/coucou/Personnal_Code/Web_site/openclassroom/code.html","text/html");
				
				//responseStream << 
				// responseStream << "<html><head><head><title>My  HTTP Server in C++ </title></head>";
				// responseStream << "<body><h1>Hello World</h1><p>";
				// responseStream << "";
				// responseStream << "</p></body></html>";
	};
};


class MyCssHandler :public Poco::Net::HTTPRequestHandler {


public:
	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response){
		        response.setChunkedTransferEncoding(true);
				std::cout << response.getStatus()<< std::endl;
				response.setContentType("text/css");
				response.sendFile("/home/coucou/Personnal_Code/Web_site/openclassroom/code.css","text/css");
				
				//responseStream << 
				// responseStream << "<html><head><head><title>My  HTTP Server in C++ </title></head>";
				// responseStream << "<body><h1>Hello World</h1><p>";
				// responseStream << "";
				// responseStream << "</p></body></html>";
	};
	
};


// Page renderer for /Test uri

class TestPageHandler: public Poco::Net::HTTPRequestHandler
{
public:

	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response){
		        response.setChunkedTransferEncoding(true);
				response.setContentType("text/html");

				std::ostream& responseStream = response.send();

				responseStream << "<html><head><head><title>My  HTTP Server in C++ </title></head>";
				responseStream << "<body><h1>Hello World 2</h1><p>";
				responseStream << "";
				responseStream << "</p></body></html>";
	};
};

class ErroPageHandler: public Poco::Net::HTTPRequestHandler
{
public:

	void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response){
		        response.setChunkedTransferEncoding(true);
		        //Sets mime type text/html application/json etc.
		        response.setContentType("text/html");
                //Sets the response status 404, 200 etc.
				response.setStatus("404");

				//opens the file stream
				std::ostream& responseStream = response.send();

				responseStream << "<html><head><head><title>My  HTTP Server in C++ </title></head>";
				responseStream << "<body><h1>PAGE NOT FOUND, SORRY!</h1><p>";
				responseStream << "";
				responseStream << "</p></body></html>";
	};
};

//  Url Router
class HandlerFactory : public Poco::Net::HTTPRequestHandlerFactory
{
public:

	Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest &request){
         // choose response based uri
		 Poco::Util::AbstractConfiguration::Keys elements;
		 std::cout << "request"<< request.getURI() << " method:"<< request.getMethod()  <<" Type:" << request.getContentType()<< std::endl;
		 std::string mot= request.getURI();
		 request.splitElements(mot,elements ,false);
		 if(elements.size()>0) std::cout << "Size:  "  <<elements.size()<< "SPlit:" << elements[0] << std::endl;
		if(request.getURI()=="/"){

			return new MyPageHandler();
		}
		if (request.getURI() =="/code.css"){
			return new MyCssHandler();
		}
		if(request.getURI()=="/test"){

			return new TestPageHandler();
		}
         //uri not recognized
		return new ErroPageHandler();
	}
};





// Macros to setup maim function to run as app or deamon (service in windows)
POCO_SERVER_MAIN(HTTPserver);


#endif //HTTPSERVER_HPP