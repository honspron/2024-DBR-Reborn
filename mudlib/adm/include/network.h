#ifndef __NETWORK_H 
#define __NETWORK_H 
 
#include <socket.h> 
#include <config.h>
 
#define MUD                       0 
#define STREAM                    1 
#define DATAGRAM                  2 
 
/*old
#define PORT_UDP                  (query_host_port() + 8) 
*/
#define PORT_UDP 8016
 
/*old
#define SERVER_ADDR               "207.227.182.222" 
#define SERVER_PORT               5567
*/
#define SERVER_ADDR "50.38.11.140"
#define SERVER_PORT 5567
/*
#define SERVER_ADDR "155.254.17.154"
#define SERVER_PORT 4209
*/
 
#define MAX_PINGS                 9999 
 
#define SERVICE_UDP_STARTUP       "startup" 
#define SERVICE_UDP_SHUTDOWN      "shutdown" 
#define SERVICE_UDP_PING_Q        "ping_q" 
#define SERVICE_UDP_PING_A        "ping_a" 
#define SERVICE_UDP_SUPPORT_Q     "support_q" 
#define SERVICE_UDP_SUPPORT_A     "support_a" 
#define SERVICE_UDP_RWHO_Q        "rwho_q" 
#define SERVICE_UDP_RWHO_A        "rwho_a" 
#define SERVICE_UDP_MAIL_Q        "mail_q"
#define SERVICE_UDP_MAIL_A        "mail_a"
#define SERVICE_UDP_MUDLIST_Q     "mudlist_q" 
#define SERVICE_UDP_MUDLIST_A     "mudlist_a" 
#define SERVICE_UDP_FINGER_Q      "gfinger_q" 
#define SERVICE_UDP_FINGER_A      "gfinger_a" 
#define SERVICE_UDP_LOCATE_Q      "locate_q" 
#define SERVICE_UDP_LOCATE_A      "locate_a" 
#define SERVICE_UDP_INTERMUD      "gwizmsg" 
#define SERVICE_UDP_AFFIRMATION_A "affirmation_a" 
#define SERVICE_UDP_WARNING       "warning" 
#define SERVICE_UDP_TELL          "gtell" 
 
#define INTERMUD_CHANNELS         ({ "intercre", "darkelib", "darkechat" }) 
#define INTERCHANNELS             ([ "CREATOR": "intercre", "darkelib":"darkelib", "darkechat":"darkechat" ])
 
#define TCP_SERVICES              ({}) 
 
#define START_MSG sprintf("||NAME:%s||PORTUDP:%d||MUDLIB:%s||VERSION:%s\
||HOST:%s||PORT:%d||TIME:%s||DRIVER:%s", mud_name(), PORT_UDP,\
mudlib(),mudlib_version(),query_host_name(), query_host_port(), ctime(time()),\
version())
 
#endif /* __NETWORK_H */
