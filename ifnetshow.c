#include <stdio.h>
#include <ifaddrs.h>
#include <arpa/inet.h>

int main() {
	struct ifaddrs *ifaddr;

	getifaddrs(&ifaddr);
	while(ifaddr){
		if (ifaddr->ifa_addr && ifaddr->ifa_addr->sa_family == AF_INET) {
			printf("%s: %s\n", ifaddr->ifa_name, inet_ntoa(((struct sockaddr_in *)ifaddr->ifa_addr)->sin_addr));
		}
		ifaddr = ifaddr->ifa_next;
	}
	return 0;
}


