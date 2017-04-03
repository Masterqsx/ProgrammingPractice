#include<iostream>
#include<cstring>
#include<string>
#include<unistd.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>

using namespace std;

int main(){
  int status = 0, socket_fd = 0;
  addrinfo host_info;
  addrinfo* host_info_list = NULL;
  const char* hostname = "colab-sbx-pvt-22.oit.duke.edu";
  const char* port = "8000";

  memset(&host_info, 0, sizeof(host_info));
  host_info.ai_family = AF_UNSPEC;
  host_info.ai_socktype = SOCK_STREAM;
  //host_info.ai_flags = AI_PASSIVE;
  status = getaddrinfo(hostname, port, &host_info, &host_info_list);

  if (status != 0) {
    cerr << "Error: can not getaddrinfo" << endl;
    abort();
  }
  
  socket_fd = socket(host_info_list->ai_family, host_info_list->ai_socktype, host_info_list->ai_protocol);
  if (socket_fd == -1) {
    cerr << "Error: can not set up socket" <<endl;
    abort();
  }
  if (connect(socket_fd, host_info_list->ai_addr, host_info_list->ai_addrlen) == -1) {
    cerr << "Error: can not set up connection" <<endl;
    abort();
  }
  string buffer = "Hello There! We can start to talk";
  while (1) {
    ::send(socket_fd, buffer.c_str(), strlen(buffer.c_str()) + 1, 0);
    cin >> buffer;
  }
  freeaddrinfo(host_info_list);
  close(socket_fd);
  
  return 0;
}
