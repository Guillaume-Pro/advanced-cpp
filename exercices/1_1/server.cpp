#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

constexpr int PORT = 8080;

void demarrerServeur() {
    int server_fd, new_socket;
    long valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
      
    // Création du socket du serveur
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("La création du socket a échoué");
        exit(EXIT_FAILURE);
    }
  
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
      
    memset(address.sin_zero, '\0', sizeof address.sin_zero);
      
    // Attachement du socket à un port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("Échec du bind");
        exit(EXIT_FAILURE);
    }
  
    // Serveur en écoute
    if (listen(server_fd, 10) < 0) {
        perror("Échec de l'écoute");
        exit(EXIT_FAILURE);
    }
  
    std::cout << "Serveur en attente de connexions..." << std::endl;
  
    // Acceptation d'une connexion
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("Échec de l'acceptation");
        exit(EXIT_FAILURE);
    }
  
    char buffer[30000] = {0};
    valread = read(new_socket, buffer, 30000);
    std::cout << "Commande reçue : " << buffer << std::endl;
    write(new_socket, "Commande reçue\n", strlen("Commande reçue\n"));
    std::cout << "Réponse envoyée" << std::endl;
  
    close(new_socket);
    close(server_fd);
}

int main() {
    demarrerServeur();
    return 0;
}
