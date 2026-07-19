#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
	std::cout << "Chat starting..." << std::endl;
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	
	if(socket_fd < 0) {
		std::cout << "Failed" << std::endl;
		return -1;
	}

	close(socket_fd);
	return 0;
}
