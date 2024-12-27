#include <stdio.h>
#include <ifaddrs.h>
#include <arpa/inet.h>

int main() {
	struct ifaddrs *ifaddr;

	getifaddrs(&ifaddr);
	while(ifaddr){
		if (ifaddr->ifa_addr && ifaddr->ifa_addr->sa_family == AF_INET) {
			char ip[INET_ADDRSTRLEN];
			char netmask[INET_ADDRSTRLEN];

			// Convert the IP address to string
			inet_ntop(AF_INET, &((struct sockaddr_in *)ifaddr->ifa_addr)->sin_addr, ip, INET_ADDRSTRLEN);
			// Convert the netmask to string
			inet_ntop(AF_INET, &((struct sockaddr_in *)ifaddr->ifa_netmask)->sin_addr, netmask, INET_ADDRSTRLEN);
			printf("Int %s: IP=%s, Netmask=%s\n", ifaddr->ifa_name, ip , netmask);
		}            
		ifaddr = ifaddr->ifa_next;
	}
	return 0;
}


