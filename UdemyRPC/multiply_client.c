//
// Created by aslan on 25.11.18.
//
#include <memory.h>
#include <stdio.h>
#include "rpc_common.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void rpc_send_recv( ser_buff_t *client_send_ser_buffer, ser_buff_t client_rscv_ser_buffer){

    struct sockaddr_in dest;
    int sockfd=0, rc=0, recv_size=0;
    int addr_len;
    dest.sin_family = AF_INET;
    dest.sin_port=htons(RPC_SERVER_PORT)
    struct  hostent *host= (struct hostent *) gethostbyname(RPC_SERVER_IP);
    dest.sin_addr= *((struct in_addr*)host->h_name)
     addr_len= sizeof(struct sockaddr)

    sockfd=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(sockfd==-1){
        printf("socket creation failed\n");
        return -1;
    }

    rc=sendto( sockfd, client_send_ser_buffer->b,
            get_serialized_buffer_length(client_send_ser_buffer),
            0, ( struct sockaddr *) &dest, sizeof(struct sockaddr));
    printf("%s(): %d bytes sent\m", __FUNCTION__, rc);
}


ser_buff_t * multiply_client_stub_marshall(int a, int b){
    ser_buff_t *client_send_ser_buffer= NULL;
    init_serialized_buffer_of_defined_size(&client_send_ser_buffer, MAX_RECV_SEND_RPC_BUFF_SIZE)
    serialize_data(client_send_ser_buffer,(char *) &a, sizeof(int))
    serialize_data(client_send_ser_buffer,(char *) &b, sizeof(int))
    return  client_send_ser_buffer;
}


int multiply_rpc(int a , int b){

    ser_buff_t *client_side_ser_buffer = multiply_client_stub_marshall(a,b);
    ser_buff_t *client_recv_ser_buffer=NULL;
    init_serialized_buffer_of_defined_size(&client_recv_ser_buffer, MAX_RECV_SEND_RPC_BUFF_SIZE)
    rpc_send_recv(client_side_ser_buffer, client_recv_ser_buffer)

    free_serialized_buffer(client_side_ser_buffer);
    client_side_ser_buffer=NULL;

}

int main(int argc, char **argv){
    int a,b;
    printf("enter first number:");
    scanf("%d",&a)
    printf("enter second number:");
    scanf("%d",&b)

    //Step 1: Invoke the rpc
    int res = multiply_rpc(a,b);

}
