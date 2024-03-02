//
// Created by guillaume on 25/02/24.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

constexpr int PORT = 8080;

void connectToServer() {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};

    // Création du socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\nErreur de création du socket \n");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Conversion des adresses IPv4 et IPv6 de texte en binaire
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        printf("\nAdresse invalide / Adresse non supportée \n");
        return;
    }

    // Connexion au serveur
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnexion échouée \n");
        return;
    }
    send(sock, hello, strlen(hello), 0);
    printf("Message envoyé\n");
    valread = read(sock, buffer, 1024);
    printf("Réponse du serveur : %s\n", buffer);

    close(sock);
}

int main() {
    connectToServer();
    return 0;
}
