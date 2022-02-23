#include "Handler.hpp"





void Handler::ErrorHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response){
		        response.setChunkedTransferEncoding(true);
				std::cout << response.getStatus()<< std::endl;
				std::ostream& responseStream = response.send();
				responseStream << -2;
	};

//##################################################IMAGE REQUEST###################################################


void Handler::FetchHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response){
	//forme le chemin !
	std::string id ="response/";
	int i =1;
	while (request.getURI()[i]){
		id +=request.getURI()[i];
		i++;
	}
	id+=".txt";
	//va lire dans le fichier contenant la reponse
	std::fstream file_response;
	std::string resp;
	file_response.open(id, std::ios::in);
	file_response >> resp;
	file_response.close();
	//renvois une reponse
	std::ostream& responseStream = response.send();
	responseStream << resp;


	//delete ??
	remove(id.c_str());
}



void Handler::ImageHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response){
	std::string way ="image/";
	//int number= rand();
	int i =0;
	std::string type="";//type de message envoye
	while (request.getURI()[i] != '_'){
		type += request.getURI()[i];
		i++;
	}
	i++;
	std::string nbRandom = "";//identifiant du message envoye
	while (request.getURI()[i] != '_'){
		nbRandom += request.getURI()[i];
		i++;
	}
	i++;
	way = way+ nbRandom + ".png"; //definis le chemin et numero de l'image.
	//mets l'image dans le fichier png
	std::fstream my_file;
	my_file.open(way, std::ios::out);
	while (request.getURI()[i]){
		my_file << request.getURI()[i];
		i++;
	}
	
	my_file.close();

	int answer_ia= -1;//appelle de fonction pour L'IA et je donne le chemin de l'image a analiser
	
	//mets la reponse dans un fichier pur L'API
	std::string resp = "response/" + nbRandom + ".txt";
	my_file.open(resp, std::ios::out);
	my_file << answer_ia;
	my_file.close();

	remove(way.c_str());
}





Poco::Net::HTTPRequestHandler* Handler::HandlerFactory::createRequestHandler(const Poco::Net::HTTPServerRequest &request){
         // choose response based uri
		//  Poco::Util::AbstractConfiguration::Keys elements;
		std::cout << "request"<< request.getURI() << " size :"<< request.getURI().size() << " method:"<< request.getMethod()  <<" Type:" << request.getContentType()<< std::endl;
		//  std::string mot= request.getURI();
		//  request.splitElements(mot,elements ,false);
		//  if(elements.size()>0) std::cout << "Size:  "  <<elements.size()<< "SPlit:" << elements[0] << std::endl;
		//
		//gestion d'image
		if(request.getMethod() == "GET") {
			return new FetchHandler();
		}
		if(request.getMethod() == "SEND") {
			return new ImageHandler();
			//Handwritting analyse


			//maquette pour le jeu
		// 	const char type = request.getURI()[0];
		// 	if (type == '0'){
		// 		return new ImageHandler();
		// 	}
		// 	//a voir si le jeu se fait
		// 	//start game
		// 	else if (type == '1'){}
		// 	//Game analyse
		// 	else if (type == '2'){}
		// 	else if (type == '3'){}
		// }
		}
		else{
			return new ErrorHandler();
		}
}