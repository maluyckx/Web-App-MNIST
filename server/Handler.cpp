#include "Handler.hpp"





void Handler::ErrorHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response){
		        response.setChunkedTransferEncoding(true);
				std::cout << response.getStatus()<< std::endl;
				response.setContentType("text/html");
				response.sendFile("sourceHtmlCss/code.html","text/html");
	};

//##################################################IMAGE REQUEST###################################################


void Handler::ImageHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response){
	std::string way ="image/";
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
		//gestion d'image
		if(request.getMethod() == "SEND") {
			return new ImageHandler();
			//Handwritting analyse
			const char type = request.getURI()[0];
			if (type == '0'){
				return new ImageHandler();
			}
			//a voir si le jeu se fait
			//start game
			else if (type == '1'){}
			//Game analyse
			else if (type == '2'){}
			else if (type == '3'){}
		}
		else{
			return new ErrorHandler();
		}
	}