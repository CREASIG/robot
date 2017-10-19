/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Serveur.cpp
 * Author: eric
 * 
 * Created on 5 octobre 2017, 13:27
 */

#include "Serveur.h"
//#include "exception/ServeurException.h"

Serveur::Serveur(Echange *echange) {
    this->echange = echange;
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    // create a socket
    // socket(int domain, int type, int protocol)
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
//    if (sockfd < 0)
//        throw ServeurException("Erreur lors de l'ouverture du port");

    // clear address structure
    bzero((char *) &serv_addr, sizeof (serv_addr));

    portno = 8080;

    /* setup the host_addr structure for use in bind call */
    // server byte order
    serv_addr.sin_family = AF_INET;

    // automatically be filled with current host's IP address
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // convert short integer value for port must be converted into network byte order
    serv_addr.sin_port = htons(portno);

    // bind(int fd, struct sockaddr *local_addr, socklen_t addr_length)
    // bind() passes file descriptor, the address structure, 
    // and the length of the address structure
    // This bind() call will bind  the socket to the current IP address on port, portno
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof (serv_addr)) < 0)
        fprintf(stderr, "ERROR on binding");

    // This listen() call tells the socket to listen to the incoming connections.
    // The listen() function places all incoming connection into a backlog queue
    // until accept() call accepts the connection.
    // Here, we set the maximum size for the backlog queue to 5.
    listen(sockfd, 5);

    // The accept() call actually accepts an incoming connection
    clilen = sizeof (cli_addr);

    // This accept() function will write the connecting client's address info 
    // into the the address structure and the size of that structure is clilen.
    // The accept() returns a new socket file descriptor for the accepted connection.
    // So, the original socket file descriptor can continue to be used 
    // for accepting new connections while the new socker file descriptor is used for
    // communicating with the connected client.
    while (true) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0)
            fprintf(stderr, "ERROR on accept");

        bzero(buffer, 256);

        n = read(newsockfd, buffer, 255);
        if (n < 0) fprintf(stderr, "ERROR reading from socket");
        string texte(buffer);
        if (texte.substr(0, 9) == "GET PARAM") {
            string a = echange->getInformation();
            send(newsockfd, a.c_str(), a.size(), 0);
        } else if (texte.substr(0, 9) == "GET DEBUG") {
            string a = echange->getDebug();
            send(newsockfd, a.c_str(), a.size(), 0);
        } else if (texte.substr(0, 3) == "SET") {
            echange->setParametre(string(texte.substr(4, texte.size() - 4).c_str()));
        } else {

        }
        close(newsockfd);
    }
    close(sockfd);
}

Serveur::Serveur(const Serveur& orig) {
}

Serveur::~Serveur() {
}

