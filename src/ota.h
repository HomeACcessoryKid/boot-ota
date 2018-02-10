#ifndef __OTA_H__
#define __OTA_H__

#define HOST "github.com"
#define HTTPS_PORT 443
#define LOCAL_PORT_START 49152
#define FAILED "failed\n"
#define OK "OK\n"
#define REQUESTHEAD "GET /"
#define REQUESTTAIL " HTTP/1.1\r\nHost: "
#define CRLFCRLF "\r\n\r\n"
#define RECV_BUF_LEN 1025  // current length of amazon URL 724
#define RANGE "\r\nRange: bytes="
#define MAXVERSIONLEN 16
#define SNTP_SERVERS 	"0.pool.ntp.org", "1.pool.ntp.org", \
						"2.pool.ntp.org", "3.pool.ntp.org"

/*struct version_t {
    int major;
    int minor;
    int patch;
}
*/
typedef struct {
    char hash[20];
    char sign[20];
} signature_t;

typedef unsigned char byte;

void ota_init();

int ota_compare(char* newv, char* oldv);

int   ota_load_main_app(char * url, char * version, char * name);

void  ota_set_validate(int onoff);

char* ota_get_version(char * url);

int   ota_get_file(char * url, char * version, char * name, int sector); //number of bytes 

int   ota_get_hash(char * url, char * version, char * name, signature_t signature);

int   ota_verify_hash(int sector,char * hash, int filesize);
    
int   ota_verify_signature(signature_t signature);

void  ota_swap_cert_sector();

void  ota_write_status0();

void  ota_reboot();

#endif // __OTA_H__
