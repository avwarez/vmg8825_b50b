#ifndef __LIB_ZY_SL_H__
#define __LIB_ZY_SL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>


/*========*/
/*  Port  */
/*========*/
#define ZY_SL_MSG_PORT        49999
#define MAP_CONTROLLER_PORT   49998
#define ZY_SL_CLI_PORT        49997

#define MSGSTR(Msgtpye) ({char *str;switch (Msgtpye){\
    case MESSAGE_TOPOLOGY_RESP: str = S_MESSAGE_TOPOLOGY_RESP; break;\
    case MESSAGE_LINK_METRIC_RESP: str = S_MESSAGE_LINK_METRIC_RESP; break;\
    case MESSAGE_AP_CAP_RPT: str = S_MESSAGE_AP_CAP_RPT; break;\
    case MESSAGE_CLIENT_CAP_RPT: str = S_MESSAGE_CLIENT_CAP_RPT; break;\
    case MESSAGE_AP_METRIC_RESP: str = S_MESSAGE_AP_METRIC_RESP; break;\
    case MESSAGE_ASSOC_STA_LINK_METRIC_RESP: str = S_MESSAGE_ASSOC_STA_LINK_METRIC_RESP; break;\
    case MESSAGE_UNASSOC_STA_LINK_METRIC_RESP: str = S_MESSAGE_UNASSOC_STA_LINK_METRIC_RESP; break;\
    case MESSAGE_BEACON_METRIC_RESP: str = S_MESSAGE_BEACON_METRIC_RESP; break;\
    case MESSAGE_CLINET_STEERING_BTM_RPT: str = S_MESSAGE_CLINET_STEERING_BTM_RPT; break;\
    case MESSAGE_OPERATING_CHANNEL_RPT: str = S_MESSAGE_OPERATING_CHANNEL_RPT; break;\
    case MESSAGE_BACKHAUL_STEERING_RESP: str = S_MESSAGE_BACKHAUL_STEERING_RESP; break;\
    case MESSAGE_ZYSL_CLI: str = S_MESSAGE_ZYSL_CLI; break;\
    case MESSAGE_ZYSL_CLI_DATA: str = S_MESSAGE_ZYSL_CLI_DATA; break;\
    case MESSAGE_STA_PROBREQ: str = S_MESSAGE_STA_PROBREQ; break;\
    default: str = "Unknow Msg"; break;\
  };str;})

#define ROUTINE_JOB_PERIOD       10//(sec)
#define MAC_ADDR_LEN              6
#define MAX_RADIO_PER_DEVICE      2
#define MAX_BSS_PER_RADIO         6
#define MAX_STA_PER_BSS          10 //need to verify, used for AssocStaInfo_t & UnAssocStaInfo_t
#define MAX_LINK_NUM              4
#define SOCKET_MAX_LENGTH      8192
#define MAX_SSID_LENGHT      (32+1)
#define MAX_BSS_PER_DEVICE       10
#define MEDIA_TYPE_LEN            2
#define VENDOR_OUI_LEN            3

#if 1 //for broadcom event
#define DOT11_MGMT_HDR_LEN       24   /* d11 management header length */
#define BCM_MSG_IFNAME_MAX    16  /* max length of interface name */
#define WL_CHANSPEC_BAND_MASK   0xc000
#define WL_CHANSPEC_BAND_2G   0x0000
#endif

#define tlv_LinkMetricTxOverhead_len          12
#define tlv_LinkMetricTxPerLink_len           29
#define tlv_BTMReport_min_len                 13
#define tlv_BeaconMetricsResp_min_len          8
#define tlv_BeaconReportElement_min_len       13  //zyxel only
#define tlv_TopologyResponseMDID_len           8  //zyxel only
#define tlv_APHECapabilities_min_len           9

//Message type
#define MESSAGE_TOPOLOGY_RESP                 0x0003
#define MESSAGE_LINK_METRIC_RESP              0x0006
#define MESSAGE_AP_CAP_RPT                    0x8002
#define MESSAGE_OPERATING_CHANNEL_RPT         0x8008
#define MESSAGE_CLIENT_CAP_RPT                0x800A
#define MESSAGE_AP_METRIC_RESP                0x800C
#define MESSAGE_ASSOC_STA_LINK_METRIC_RESP    0x800E
#define MESSAGE_UNASSOC_STA_LINK_METRIC_RESP  0x8010
#define MESSAGE_BEACON_METRIC_RESP            0x8012
#define MESSAGE_CLINET_STEERING_BTM_RPT       0x8015
#define MESSAGE_BACKHAUL_STEERING_RESP        0x801A
#define MESSAGE_ZYSL_CLI                      0xDEB6
#define MESSAGE_ZYSL_CLI_DATA                 0xDEB7
#define MESSAGE_STA_PROBREQ                   0x0044

#define S_MESSAGE_TOPOLOGY_RESP                 "Topology Response"
#define S_MESSAGE_LINK_METRIC_RESP              "Link Metric Response"
#define S_MESSAGE_AP_CAP_RPT                    "Ap Capability Report"
#define S_MESSAGE_CLIENT_CAP_RPT                "Client Capability Report"
#define S_MESSAGE_AP_METRIC_RESP                "Ap Metrics Response"
#define S_MESSAGE_ASSOC_STA_LINK_METRIC_RESP    "Associated Sta Link Metric Response"
#define S_MESSAGE_UNASSOC_STA_LINK_METRIC_RESP  "Unassociated Sta Link Metric Response"
#define S_MESSAGE_BEACON_METRIC_RESP            "Beacon Metric Response"
#define S_MESSAGE_CLINET_STEERING_BTM_RPT       "Client Steering BTM Report"
#define S_MESSAGE_OPERATING_CHANNEL_RPT         "Operating Channel Report"
#define S_MESSAGE_ZYSL_CLI                      "Zyxel Steering Logic CLI"
#define S_MESSAGE_ZYSL_CLI_DATA                 "Zyxel Steering Logic Data"
#define S_MESSAGE_BACKHAUL_STEERING_RESP        "Backhaul Steering Response"
#define S_MESSAGE_STA_PROBREQ                   "Station Probe Request"
//TLV type
#define MSG_END_TLV               0x00
#define DEVICE_INFO_TLV           0x03
#define LINK_METRIC_TX_TLV        0x09
#define AP_OPER_BSS_TLV           0x83
#define AP_RADIOBASICCAP_TLV      0x85
#define AP_HTCAP_TLV              0x86
#define AP_VHTCAP_TLV             0x87
#define AP_HECAP_TLV              0x88
#define OPERATE_CHAN_TLV          0x8F
#define CLIENT_INFO_TLV           0x90
#define CLIENT_CAP_RPT_TLV        0x91
#define AP_MTRX_TLV               0x94
#define ASSOC_STA_LINKMTRX_TLV    0x96
#define UNASSOC_STA_LINKMTRX_TLV  0x98
#define BCN_MTRX_RESP_TLV         0x9A
#define STEERING_BTM_RPT_TLV      0x9C
#define BH_STEERING_RESP_TLV      0x9F
#define VENDOR_SPECIFIC_TLV       0x0B
#define AP_CAP_TLV                0xA1
#define ZY_MDID_TLV               0xC0
#define ASSOC_STA_TRAFFIC_STATS_TLV   0xA2

//CLI
#define ZYSLCLI_TOPDB             0x01
#define ZYSLCLI_RELOAD            0x02
#define ZYSLCLI_STEER_RECORD      0x03
#define ZYSLCLI_CLIENTDB          0x04
#define ZYSLCLI_ALLDB             0x05
#define ZYSLCLI_MONI              0x06
#define ZYSLCLI_BSSLIST           0x07
#define ZYSLCLI_STEERING          0x08
/*
 * Scan through the tlvs, searching for the requested "type"
 * return  0 : found
 *        -1 : found type, could not extract value
 *        -2 : not found
 */

#define TLV_FOUND               0
#define TLV_FOUND_BUT_NO_VALUE -1
#define TLV_NOT_FOUND          -2

/*Capbility Flag*/
#define HE_MAX_MCS_11   0x0002
#define HE_MAX_MCS_9    0x0001
#define HE_MAX_MCS_7    0x0000
#define VHT_MAX_MCS_9   0x0002
#define VHT_MAX_MCS_8   0x0001
#define VHT_MAX_MCS_7   0x0000

#define dot11ax 0x04
#define dot11ac 0x02
#define dot11n  0x01
/*HE capability*/
#define AP_HECAP_FLAG_160MHZ      0x00000001
#define AP_HECAP_FLAG_80P80MHZ    0x00000002

#define ZyVendSpecOui     "\xFC\xF5\x28"


typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned char uint8;
typedef unsigned int uint32;
typedef signed int int32;
/*========================*/
/*  Msg Struct for parsing*/
/*========================*/
typedef struct libzySL_msg_s{
  unsigned short Msg_type;
  char buffer[8190];
} __attribute__((__packed__)) libzySL_msg_t;

typedef struct tlv_s{
  unsigned char type;
  unsigned short length;
} __attribute__((__packed__)) zytlv_t; // attribute -> compress structure size

typedef struct TopologyBSS_s {
  unsigned char BSSID[MAC_ADDR_LEN];
  unsigned char SSID_len;
  char SSID[MAX_SSID_LENGHT];
  unsigned short MDID;
}  __attribute__((__packed__)) TopologyBSS_t;

typedef struct TopologyRadio_s {
  unsigned char Radio_MAC[MAC_ADDR_LEN];
  unsigned char BSS_Counts;
  TopologyBSS_t BSS[MAX_BSS_PER_RADIO];
}  __attribute__((__packed__)) TopologyRadio_t;

typedef struct TopologyResp_s {
  unsigned short Msg_type;
  unsigned char Device_ALMAC[MAC_ADDR_LEN];
  unsigned char Radio_Counts;
  unsigned char Media_type[MEDIA_TYPE_LEN];
  unsigned char Vendor_OUI[VENDOR_OUI_LEN];
  TopologyRadio_t Radio[MAX_RADIO_PER_DEVICE];
} __attribute__((__packed__)) TopologyResp_t;

typedef struct LinkMetricPair_s {
  unsigned char Intf_MAC[MAC_ADDR_LEN];           //MAC address of an interface in the receiving 1905.1 AL, which connects to an interface in the neighbor 1905.1 AL
  unsigned char Neighbor_Intf_MAC[MAC_ADDR_LEN];  //MAC address of a 1905.1 interface in a neighbor 1905.1 device, which connects to a 1905.1 interface in the receiving 1905.1 device
  unsigned short phyrate;
} __attribute__((__packed__)) LinkMetricPair_t;

typedef struct LinkMetricsResp_s {
  unsigned short Msg_type;
  unsigned char Device_ALMAC[MAC_ADDR_LEN];       //1905.1 AL MAC address of the device that transmits the response message that contains this TLV
  unsigned char Neighbor_ALMAC[MAC_ADDR_LEN];     //1905.1 AL MAC address of the neighbor whose link metric is reported in this TLV
  LinkMetricPair_t LinkPair[MAX_LINK_NUM];
} __attribute__((__packed__)) LinkMetricsResp_t;

typedef struct RadioCapability_s {
  unsigned char Radio_MAC[MAC_ADDR_LEN];
  unsigned char OpClass;
  unsigned char supportBW;
  unsigned char shortGI;//|-160-|-80-|-40-|-20-|
  unsigned char TxNss;
  unsigned char RxNss;
  unsigned char support_phytype; //dot11ax, dot11ac, dot11n
  unsigned char max_mcs;
  unsigned char max_transmit_power;
} __attribute__((__packed__)) RadioCapability_t;

typedef struct ApCapabilityRpt_s {
  unsigned short Msg_type;
  unsigned char Device_MAC[MAC_ADDR_LEN];
  unsigned char Radio_Counts;
  unsigned char ApCap_UnaosStaRpt;
  RadioCapability_t Radio[MAX_RADIO_PER_DEVICE];
} __attribute__((__packed__)) ApCapabilityRpt_t;

typedef struct ClientCapabilityRpt_s {
  unsigned short Msg_type;
  unsigned char BSSID[MAC_ADDR_LEN];
  unsigned char STA_MAC[MAC_ADDR_LEN];
  unsigned char supphytype;
  unsigned char curphytype;
  unsigned char support11v;   //0: unsupport; 1:support
  unsigned char bandwidthHT;  //bit 0: 20M, bit 1: 40M
  unsigned char bandwidthVHT; //bit 0: 20M, bit 1: 40M, bit 2: 80M, bit 3: 160 or 80+80
  unsigned char sgiHT;        //short guard interval for 20 and 40, bit 1: 20; bit 2: 40
  unsigned char sgiVHT;       //short guard interval for 80
  unsigned char HT_MCS[16];
  unsigned char VHT_MCS[8];
  unsigned char max_mcs;
} __attribute__((__packed__)) ClientCapabilityRpt_t;

typedef struct AssocStaMetricsResp_s {
  unsigned short Msg_type;
  unsigned char STA_MAC[MAC_ADDR_LEN];
  unsigned int Uplink_rate;               //Estimated MAC Data Rate in downlink (in Mb/s)
  unsigned int Downlink_rate;             //Estimated MAC Data Rate in uplink (in Mb/s)
  unsigned char RCPI;                     //Uplink RCPI for STA
  unsigned char BSSID[MAC_ADDR_LEN];      //STA associated BSS's Bssid
  unsigned int BytesSent;
  unsigned int BytesReceived;
  unsigned int PacketsSent;
  unsigned int PacketsReceived;
  unsigned int TxPacketsErrors;
  unsigned int RxPacketsErrors;
  unsigned int RetransCount;
} __attribute__((__packed__)) AssocStaMetricsResp_t;

typedef struct UnAssocStaInfo_s {
  unsigned char STA_MAC[MAC_ADDR_LEN];
  unsigned char ChannelNum;               //A single channel number in Operating Class on which the RCPI measurement for STA was made
  unsigned char RCPI;                     //Uplink RCPI for STA
} __attribute__((__packed__)) UnAssocStaInfo_t;

typedef struct ApMetricsPerBss_s {
  unsigned char BSSID[MAC_ADDR_LEN];
  unsigned char ChannelUtility;
  unsigned char Sta_Counts;               //For record station number, zyxel only
  unsigned short assocSta_count;
  AssocStaMetricsResp_t AssocSta[MAX_STA_PER_BSS];
} __attribute__((__packed__)) ApMetricsPerBss_t;

typedef struct ApMetricsResp_s {
  unsigned short Msg_type;
  unsigned char bss_Counts;
  ApMetricsPerBss_t ApMetricsBss[MAX_STA_PER_BSS];
} __attribute__((__packed__)) ApMetricsResp_t;

typedef struct UnAssocStaMetricsRsp_s {
  unsigned short Msg_type;
  unsigned char Device_MAC[MAC_ADDR_LEN];
  unsigned char OpClass;
  UnAssocStaInfo_t UnAssocSta[MAX_STA_PER_BSS];
} __attribute__((__packed__)) UnAssocStaMetricsResp_t;

typedef struct BeaconMetricsResp_s {
  unsigned short Msg_type;
  unsigned char Device_MAC[MAC_ADDR_LEN];
  unsigned char STA_MAC[MAC_ADDR_LEN];      //MAC address of the associated STA for which the Beacon Report information is requested.
  unsigned char Num_elements;               //Number of measurement report elements included in this TLV.
  unsigned char RCPI;
  unsigned char RSNI;
} __attribute__((__packed__)) BeaconMetricsResp_t;

typedef struct ClientSteeringBTMRpt_s {
  unsigned short Msg_type;
  unsigned char BSSID[MAC_ADDR_LEN];
  unsigned char STA_MAC[MAC_ADDR_LEN];
  unsigned char BTM_result;
  unsigned char Target_BSSID[MAC_ADDR_LEN];
} __attribute__((__packed__)) ClientSteeringBTMRpt_t;

typedef struct BHSteeringResp_s {
  unsigned short Msg_type;
  unsigned char STA[MAC_ADDR_LEN];
  unsigned char TBSS[MAC_ADDR_LEN];
  unsigned char BHResultCode;
} __attribute__((__packed__)) BHSteeringResp_t;

typedef struct OperatingChanRpt_s {
  unsigned short Msg_type;
  unsigned char Radio[MAC_ADDR_LEN];
  unsigned char OpClassNum; //Number of current operating classes. Current only one.
  unsigned char OpClass;
  unsigned char CurChan;
  unsigned char cur_transmit_power;
} __attribute__((__packed__)) OperatingChanRpt_t;

typedef struct zySLCli_msg_s {
  unsigned short Msg_type;
  unsigned char CmdID;
  unsigned char stamac[MAC_ADDR_LEN];
  unsigned char bssid[MAC_ADDR_LEN];
} __attribute__((__packed__)) zySLCli_msg_t;

typedef struct ProbeReq_s {
  unsigned short Msg_type;
  unsigned short int Curr_band;
  unsigned char stamac[MAC_ADDR_LEN];
  unsigned char BSSID[MAC_ADDR_LEN];
  int32 rssi;
  char buffer[4076];
} __attribute__((__packed__)) ProbeReq_t;

void zySL_Wrapper_reg(void);
int zySL_Msg_init(unsigned int init_port);
void zySL_Msg_deinit(void);
void zySL_Msg_recv(libzySL_msg_t *msg);
void zySL_Msg_send(unsigned short msg_type, void *msg, unsigned int dst_port);
void zySL_Msg_parser(unsigned short msg_type, unsigned char *pbuf, unsigned int dst_port, unsigned char *mac);
void zySL_Msg_free(unsigned short msg_type);
int process_tlv(unsigned short msg_type, unsigned char *pbuf, void *pmem, unsigned char *mac);
bool GetEngDbgFlag(void);

int tlv_DeviceInfo_extract(unsigned char *pvalue, TopologyResp_t *pTopologyResp);
int tlv_LinkMetricTx_extract(unsigned char *pvalue, LinkMetricsResp_t *pLinkMetricsResp, unsigned short len);
int tlv_APOperationBss_extract(unsigned char *pvalue, TopologyResp_t *pTopologyResp, unsigned short len);
int tlv_APRadioBasicCapabilities_extract(unsigned char *pvalue, ApCapabilityRpt_t *ApCapRpt);
int tlv_APHTCapabilities_extract(unsigned char *pvalue, ApCapabilityRpt_t *ApCapRpt);
int tlv_APVHTCapabilities_extract(unsigned char *pvalue, ApCapabilityRpt_t *ApCapRpt);
int tlv_APHECapabilities_extract(unsigned char *pvalue, ApCapabilityRpt_t *ApCapRpt, unsigned short len);
int tlv_ClientInfo_extract(unsigned char *pvalue, ClientCapabilityRpt_t *pCliCapRpt);
int tlv_ClientCapabilityReport_extract(unsigned char *pvalue, ClientCapabilityRpt_t *pCliCapRpt, unsigned short len);
int tlv_APMetrics_extract(unsigned char *pvalue, ApMetricsResp_t *pApMetricsResp, int bss_idx);
int tlv_AssociStaLinkMetric_extract(unsigned char *pvalue, ApMetricsResp_t *pApMetricsResp, int bss_idx);
int tlv_AssociStaLinkMetric2_extract(unsigned char *pvalue, AssocStaMetricsResp_t *pAssocStaMetricsResp);
int tlv_UnAssociStaLinkMetric_extract(unsigned char *pvalue, UnAssocStaMetricsResp_t *pUnAssocStaMetricsResp,
  unsigned short len, unsigned char *device_mac);
int tlv_APCapabilities_extract(unsigned char *pvalue, ApCapabilityRpt_t *ApCapRpt, unsigned char *device_mac);
int tlv_BeaconMetricsResp_extract(unsigned char *pvalue, BeaconMetricsResp_t *pBeaconMetricsResp,
  unsigned short len, unsigned char *device_mac);
int tlv_SteeringBTMReport_extract(unsigned char *pvalue, ClientSteeringBTMRpt_t *pClientSteeringBTMRpt, unsigned short len);
int tlv_OperatingChannelReport_extract(unsigned char *pvalue, OperatingChanRpt_t *pOperatingChanRpt, unsigned short len);
int tlv_BHSteeringResp_extract(unsigned char *pvalue, BHSteeringResp_t *pBHSteeringResp, unsigned short len);
int tlv_VendorSpecific_extract(unsigned char *pvalue, TopologyResp_t *pTopologyResp, unsigned short len);
int management_RequestFrame_extract(unsigned char *pvalue, ClientCapabilityRpt_t *pCliCapRpt, int totlen);
int tlv_AssociStaTrafficStats_extract(unsigned char *pvalue, ApMetricsResp_t *pApMetricsResp, int bss_idx);
#endif