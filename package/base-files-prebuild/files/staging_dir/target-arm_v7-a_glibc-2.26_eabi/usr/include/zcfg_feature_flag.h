
/* Device.X_ZYXEL_FEATRUE_FLAG.Flag */
#define EOGRE_TUNNEL                                   (1 << 0)
#define ZYCFGFILTER_RESTORE_WITHOUT_CHANGE_ACS_INFO    (1 << 1)
#define HIDE_WLANGUESTAP_TAP                           (1 << 2)
#define CUSTOMIZATION_LOGO_ZAP                         (1 << 3)
#define WIZARD_CCWAN                                   (1 << 4)
#define SET_MAC_TO_PPP_password                        (1 << 5)

#define CUSTOMIZATION_LOGO_DIGI                        (1 << 7)

enum {
  IPIFACE_DSCPMARK_V4 = 1,                  // enable IP.Interface default IPv4 DSCP 
  IPIFACE_DSCPMARK_V4_QOS_1ST = 1 << 1    // bit enabled, utilize QoS DSCPMark first while there's QoS DSCPMark configured
                                           // bit disabled, utilize IP.Interface DSCPMark instead, even through there's QoS DSCPMark configured 
  //IPIFACE_DSCPMARK_V4_DSCP_2_802_1P 
  //IPIFACE_DSCPMARK_V6,
  //IPIFACE_DSCPMARK_V6_QOS_1ST,
  //IPIFACE_DSCPMARK_V6_DSCP_2_802_1P 
};

