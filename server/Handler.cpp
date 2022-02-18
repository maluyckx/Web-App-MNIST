#include "Handler.hpp"





void Handler::MyPageHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response){
		        response.setChunkedTransferEncoding(true);
				std::cout << response.getStatus()<< std::endl;
				response.setContentType("text/html");
				response.sendFile("sourceHtmlCss/code.html","text/html");
	};






void Handler::MyCssHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response){
		        response.setChunkedTransferEncoding(true);
				std::cout << response.getStatus()<< std::endl;
				response.setContentType("text/css");
				response.sendFile("sourceHtmlCss/code.css","text/css");
	};






void Handler::ErroPageHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response){
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
	}


void Handler::TestPageHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response){
		        response.setChunkedTransferEncoding(true);
				response.setContentType("text/html");

				std::ostream& responseStream = response.send();

				responseStream << "<html><head><head><title>My  HTTP Server in C++ </title></head>";
				responseStream << "<body><h1>Hello World 2</h1><p>";
				responseStream << "";
				responseStream << "</p></body></html>";
	};


//##################################################IMAGE REQUEST###################################################


void Handler::ImageHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response){
	std::string way ="asserimage/";
	std::string name ="lol.png"; //a definir
	way = way + name;
	std::fstream my_file;
	my_file.open(name, std::ios::out);
	my_file << request.getURI();
	request.getContentLength();
	my_file.close();

	//appelle de fonction pour L'IA et je donne le chemin de l'image a analiser


	remove(way.c_str());
}





Poco::Net::HTTPRequestHandler* Handler::HandlerFactory::createRequestHandler(const Poco::Net::HTTPServerRequest &request){
         // choose response based uri
		 Poco::Util::AbstractConfiguration::Keys elements;
		 std::cout << "request"<< request.getURI() << " size :"<< request.getURI().size() << " method:"<< request.getMethod()  <<" Type:" << request.getContentType()<< std::endl;
		 std::string mot= request.getURI();
		 request.splitElements(mot,elements ,false);
		 if(elements.size()>0) std::cout << "Size:  "  <<elements.size()<< "SPlit:" << elements[0] << std::endl;
		//
		if (request.getMethod() == "GET"){
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
		//gestion d'image
		else if(request.getMethod() == "SEND") {
			return new ImageHandler();
			//Handwritting analyse
			const char type = request.getURI()[0];
			if (type == '0'){}
			//start game
			else if (type == '1'){}
			//Game analyse
			else if (type == '2'){}
			else if (type == '3'){}
		}
	}