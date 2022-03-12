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
	std::string id = request.getURI();
	std::string way ="";
	int i =1;
	while (id[i]) {
		way+=id[i];
		i++;
		}



	//va lire dans le fichier contenant la reponse
	std::fstream file_response;
	std::string resp;
	file_response.open(way, std::ios::in);
	file_response >> resp;
	file_response.close();
	//renvois une reponse
	std::ostream& responseStream = response.send();
	responseStream << resp;
	//delete ??
	remove(way.c_str());
}



void Handler::ImageHandler::handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response){

	std::string id = request.getURI();
	
	std::string way ="";
	int i =1;
	while (id[i]) {
		way+=id[i];
		i++;
		}
	//recupere le coprs
	std::istream &postrequest = request.stream();
	int length = request.getContentLength();
	char* buffer = new char[length];
	postrequest.read(buffer, length);


	//cree l'image
	std::fstream my_file;
	my_file.open(way, std::ios::out);
	my_file << buffer;
	my_file.close();


	//appelle python
	//creation du l'objet python
	Py_Initialize();
	PyObject* myModuleString = PyUnicode_FromString((char*) "nom du fichier python");
	PyObject* myModule = PyImport_Import(myModuleString);
	//creation des objet fonction et argument
	PyObject* myFunction = PyObject_GetAttrString(myModule,"non de la fonction a mettre");
	PyObject* args = PyTuple_Pack(1,way);//1,PyFloat_FromDouble(2.0));
	//lancement
	PyObject* myResult  = PyObject_CallObject(myFunction, args);

	remove(way.c_str());
}





Poco::Net::HTTPRequestHandler* Handler::HandlerFactory::createRequestHandler(const Poco::Net::HTTPServerRequest &request){
		//gestion d'image
		if(request.getMethod() == "GET") {
			return new FetchHandler();
		}
		if(request.getMethod() == "POST") {
			return new ImageHandler();
			//Handwritting analyse
		}
		else{
			return new ErrorHandler();
		}
}