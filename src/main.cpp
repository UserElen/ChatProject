#include <iostream>
#include <sys/types.h> //for socket
#include <sys/socket.h> //for socket
#include <unistd.h> // close socket
#include <netinet/in.h> //INADDR_ANY
#include <arpa/inet.h> 
#include <cstdio> //for perror()

int main()
{
	std::cout << "Chat starting..." << std::endl;
	
	//the fd number, creating the server sockeT
	//AF_INET-ipv4 protocol
	//SOCK_STEAM TCP socket
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in address; //creating struct object for defining socket address
	address.sin_family = AF_INET; //ipv4
	address.sin_port = htons(8080); //port number
	address.sin_addr.s_addr = htonl(INADDR_ANY); //any IP

	
	if(socket_fd < 0) {
		std::cerr << "failed socket return";
		return -1;
	}
	
	int bind_socket = bind(socket_fd, reinterpret_cast<const struct sockaddr*>(&address), sizeof(address));

	if(bind_socket < 0) {
		std::cerr << "failed bind";
		return -1;
	}

	int listen_var = listen(socket_fd, 3);
	if(listen_var < 0) {
		std::cerr << "failed to listen";
		return -1;
	}
	std::cin.get();
	close(socket_fd);
	return 0;
}
