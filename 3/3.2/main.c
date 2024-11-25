#include "ip2.h"

#define ARG_COUNT 4

int main(int argc, char** argv) {
	if (argc != ARG_COUNT) {
        printf("Программа требует 3 аргумента: <ip_src> <mask (ex: 24)> <количество пакетов>...\n");
        exit(1);	
    }
    
    unsigned int i = 0;
    const unsigned int ip_src = convert_mask_to_u_int(argv[1]);
    const unsigned int mask = gen_net_mask(atoi(argv[2]));
    const unsigned int packets_num = atoi(argv[3]);
    
    printf("Input information:\n");
    printf("\tIP source = "); printip(ip_src, stdout); printf("\n");
    printf("\tIP mask = "); printmask(mask, stdout); printf("\n");
    printf("\tNumber of packets = %u\n", packets_num); 
    
    // Create packets
    packet_t packets_list[packets_num];
    
    // Init packets
    for (i = 0; i < packets_num; i++) {
    	packets_list[i].ip_src = ip_src;
    	packets_list[i].ip_dst = gen_rand_ip();
    }
    
    /* Print packets list
    printf("Packets list:\n");
    printf("No.    | IP source     | IP destenation\n");
    for (i = 0; i < packets_num; i++) {
    	printf("%6u\t", i);
    	printip(packets_list[i].ip_src, stdout); printf("\t");
    	printip(packets_list[i].ip_dst, stdout); printf("\n");
    }
    */
    
    // Count packets with same subnet in ip_src and ip_dst
    unsigned int same_count = 0;
    
    // Calculate statistic
    for (i = 0; i < packets_num; i++) {
    	if (!ipcmp(ip_src, packets_list[i].ip_dst, mask)) same_count++;
    }
    
    // Printf statistic
    printf("%lf in the same subnet", same_count / packets_num * 100);

    return 0;
}
