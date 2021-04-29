#ifndef __SWITCH_H__
#define __SWITCH_H__

#define ZYIMS_SWITCH_H 1 // TODO: This is dedicated to distinguish the 'switch.h' from the one in the IPTK package.


#if IPTK_SWITCH_H
#define ZYXEL_IPTK_DEBUG_ENABLED 0
#endif //IPTK_SWITCH_H.


//*****************************************************************************************************
//Michael.20121023.001.B: Add to implement the new designed Phone Port CB FSM with the new operation logic
//#define OLD_ZYIMS_VOIP	1
//#define OLD_ZYIMS_VOIP_AGE_1	1
//#define OLD_ZYIMS_VOIP_AGE_2	1
//#define OLD_ZYIMS_VOIP_AGE_3	1
#define NEW_ZYIMS_VOIP	1


//Michael.20150617.003.B: Add to implement a Central Control of all Porting/Developing Phase/Stage-related Compile Flags.
#if defined (ZYXEL_VOICE_PLATFORM_CODE) && defined (PLATFORM_LTQ_CODE) && (ZYXEL_VOICE_PLATFORM_CODE==PLATFORM_LTQ_CODE) //Michael.20150727.003: Add to employ the new defined Platform Code to identify the Platform Type and make the compile flag 'ZYIMS_IS_UNDER_PORTING_DEVELOP_PHASE' is only (auto) defined for one still under the Porting/Developing Phase/Stage.
#define ZYIMS_IS_UNDER_PORTING_DEVELOP_PHASE 1 // TODO: Disable this flag when the Porting/Developing Phase/Stage is over!!
#endif //defined (ZYXEL_VOICE_PLATFORM_CODE) && defined (PLATFORM_MTK_EVA_CODE) && (ZYXEL_VOICE_PLATFORM_CODE==PLATFORM_MTK_EVA_CODE).
//==============================================================
//=== X-ZyIMS VoIP New Platform Porting/Developing Phase/Stage-related Compile Flag(s) ===
//==============================================================
#if ZYIMS_IS_UNDER_PORTING_DEVELOP_PHASE
#define SKIP_THE_STARTUP_PROCEDURE_SERIOUS_ERROR_EXIT			1
#define DSP_AND_PHONE_FUNC_API_MM_TEST_EVENT_HANDLER			0
#define DSP_AND_PHONE_FUNC_API_MM_TEST_GEN_TONE				0
#define DSP_AND_PHONE_FUNC_API_MM_TEST_GEN_RING				0
#define DSP_AND_PHONE_FUNC_API_VOICEAPP_TEST_EVENT_HANDLER	0
#define DSP_AND_PHONE_FUNC_API_VOICEAPP_TEST_GEN_TONE		0
#define DSP_AND_PHONE_FUNC_API_VOICEAPP_TEST_GEN_RING			0
#define PHONE_LOCAL_PHONE_FSM_TEST_STATE_ONLY					0
#define CONFIG_INIT_BOUND_ON_LAN_INTERFACE						0

//--- Set the Debug Message Flag's Default Value for the Porting/Developing Phase/Stage. //Michael.20150617.001: Add to Temporarily Enabling some Debug Message Flag(s) to help debug the X-ZyIMS Start-up Procedure-related issue(s) over the MT7525G MTK/EcoNet platform EVM board.
#ifndef DBG_MSG_FLAG_DEFAULT_PHONE			/* phfsm.c/int phoneDebug; */
#define DBG_MSG_FLAG_DEFAULT_PHONE		1
#endif
#ifndef DBG_MSG_FLAG_DEFAULT_VOICEAPP		/* voiceApp_main.c/int voiceAppDebug; */
#define DBG_MSG_FLAG_DEFAULT_VOICEAPP	1
#endif
#ifndef DBG_MSG_FLAG_DEFAULT_TR104			/* tr104.c/uint8 Tr104Debug; */
#define DBG_MSG_FLAG_DEFAULT_TR104		1
#endif
#ifndef DBG_MSG_FLAG_DEFAULT_MM_RM		/* mm_cfg_init.c/uint8 mmRmDebug; */
#define DBG_MSG_FLAG_DEFAULT_MM_RM		1
#endif
#ifndef DBG_MSG_FLAG_DEFAULT_MM_DSP		/* mm_cfg_init.c/uint8 mmDspDebug; */
#define DBG_MSG_FLAG_DEFAULT_MM_DSP		1
#endif
#ifndef DBG_MSG_FLAG_DEFAULT_MM_RTP		/* mm_cfg_init.c/uint8 mmRtpDebug; */
#define DBG_MSG_FLAG_DEFAULT_MM_RTP		1
#endif
#endif //ZYIMS_IS_UNDER_PORTING_DEVELOP_PHASE.
//Michael.20150617.003.E: Add.


//Michael.20150617.004.B: Add to implement a Central Control of all Debug Message Flags.
//==============================
//=== Debug Message Flag's Default Value ===
//==============================
// TODO: All the following Debug Message Flags COULD be controlled by the "make menuconfig" PROFILE!
#ifndef DBG_MSG_FLAG_DEFAULT_PHONE			/* phfsm.c/int phoneDebug; */
#define DBG_MSG_FLAG_DEFAULT_PHONE		0
#endif
#ifndef DBG_MSG_FLAG_DEFAULT_CCM			/* call_mgnt.c/int ccmDebug; */
#define DBG_MSG_FLAG_DEFAULT_CCM			0
#endif
#ifndef DBG_MSG_FLAG_DEFAULT_SIP			/* Voipccm_sip_itf.c/int sipDebug; */
#define DBG_MSG_FLAG_DEFAULT_SIP			0
#endif
#ifndef DBG_MSG_FLAG_DEFAULT_VOICEAPP		/* voiceApp_main.c/int voiceAppDebug; */
#define DBG_MSG_FLAG_DEFAULT_VOICEAPP	0
#endif
#ifndef DBG_MSG_FLAG_DEFAULT_TR104			/* tr104.c/uint8 Tr104Debug; */
#define DBG_MSG_FLAG_DEFAULT_TR104		0
#endif
#ifndef DBG_MSG_FLAG_DEFAULT_ICF			/* Icf_feature_flags.h // #define ICF_TRACE_ENABLE 1 + #define ICF_DETAILED_DEBUG_TRACE 1 + #define ICF_INTERFACE_TRACE_ENABLE 1 */
#define DBG_MSG_FLAG_DEFAULT_ICF			0
#endif
#ifndef DBG_MSG_FLAG_DEFAULT_MM_RM		/* mm_cfg_init.c/uint8 mmRmDebug; */
#define DBG_MSG_FLAG_DEFAULT_MM_RM		0
#endif
#ifndef DBG_MSG_FLAG_DEFAULT_MM_RTP		/* mm_cfg_init.c/uint8 mmRtpDebug; */
#define DBG_MSG_FLAG_DEFAULT_MM_RTP		0
#endif
#ifndef DBG_MSG_FLAG_DEFAULT_MM_DSP		/* mm_cfg_init.c/uint8 mmDspDebug; */
#define DBG_MSG_FLAG_DEFAULT_MM_DSP		0
#endif
#ifndef DBG_MSG_FLAG_DEFAULT_LOG_DEST		/* voiceApp_main.c + mm_cfg_init.c + debugcli.c // uint8 log_dest; */
#define DBG_MSG_FLAG_DEFAULT_LOG_DEST	0 //0:output to (Local)UART & Telnet/SSH Console, 1:output to File (ZYXEL_VOIP_WRITABLE_PARTITION_DIR "/voice/log").
#endif
//Michael.20150617.004.E: Add.


//Michael.20150121.002.B: Add to improve the process termination handling procedure. This can also be regarded as a corresponding design for the 'Michael.20150121.001'.
//=======================
//=== ZyIMS VoIP Process Info ===
//=======================
#ifndef PROCESS_NAME_IPTK // TODO: It's BETTER to be renamed to 'ZYIMS_PROCESS_NAME_IPTK' and controlled by the "make menuconfig" PROFILE!
#define PROCESS_NAME_IPTK		"icf.exe"
#endif //PROCESS_NAME_IPTK.

#ifndef PROCESS_NAME_MM // TODO: It's BETTER to be renamed to 'ZYIMS_PROCESS_NAME_MM' and controlled by the "make menuconfig" PROFILE!
#define PROCESS_NAME_MM		"mm.exe"
#endif //PROCESS_NAME_MM.

#ifndef PROCESS_NAME_VOICEAPP // TODO: It's BETTER to be renamed to 'ZYIMS_PROCESS_NAME_VOICEAPP' and controlled by the "make menuconfig" PROFILE!
#define PROCESS_NAME_VOICEAPP	"voiceApp"
#endif //PROCESS_NAME_VOICEAPP.

#ifndef PID_FILE_PATH_IPTK // TODO: It's BETTER to be renamed to 'ZYIMS_PID_FILE_PATH_IPTK' and controlled by the "make menuconfig" PROFILE!
#define PID_FILE_PATH_IPTK		"/var/run/icf.pid"
#endif //PID_FILE_PATH_IPTK.

#ifndef PID_FILE_PATH_MM // TODO: It's BETTER to be renamed to 'ZYIMS_PID_FILE_PATH_MM' and controlled by the "make menuconfig" PROFILE!
#define PID_FILE_PATH_MM		"/var/run/mm.pid"
#endif //PID_FILE_PATH_MM.

#ifndef PID_FILE_PATH_VOICEAPP // TODO: It's BETTER to be renamed to 'ZYIMS_PID_FILE_PATH_VOICEAPP' and controlled by the "make menuconfig" PROFILE!
#define PID_FILE_PATH_VOICEAPP	"/var/run/voiceApp.pid" //Michael.20140522.002: Add to support De-Register ALL active VoIP SIP accounts first before doing reboot.
#endif //PID_FILE_PATH_VOICEAPP.
//Michael.20150121.002.E: Add.



//===================================
//=== Integrated (Phone and/or Call) Feature Flag ===
//===================================
//= Note-1: the Feature Flag here is like a central controller or function switch to usually control one or more other feature flag(s) to fulfill/achieve some dedicated/expected (Phone and/or Call) function.
//=         Therefore, a Feature Flag could be moved here to well-form/construct the DEPENDENCY relationship, if necessary and feasible.
//= Note-2: the Feature Flag here is MAYBE corresponding to a Customization feature/function.

//Michael.20171220.001.B: Add the Distinctive Ring-related Feature Flag and Constant definitions, as well as the DEPENDency between them if necessary.
#ifndef ZYXEL_VOIP_DISTINCTIVE_RING_SUPPORT
#define ZYXEL_VOIP_DISTINCTIVE_RING_SUPPORT 1
#endif //ZYXEL_VOIP_DISTINCTIVE_RING_SUPPORT.

#if ZYXEL_VOIP_DISTINCTIVE_RING_SUPPORT
	#define ZYXEL_VOIP_DISTINCTIVE_RING_PROFILE_MAX 9 //including the Splash Ring.

	//NOTE/DEPENDENCY: 'ZYXEL_SIP_HDR_ALERT_INFO_RECEIVE_SUPPORT' is designed to be a stand-alone CALL feature. However, if/once 'ZYXEL_VOIP_DISTINCTIVE_RING_SUPPORT' is enabled, then it MUST be Enabled/Supported accordingly.
	#if !(ZYXEL_SIP_HDR_ALERT_INFO_RECEIVE_SUPPORT)
	#undef ZYXEL_SIP_HDR_ALERT_INFO_RECEIVE_SUPPORT
	#define ZYXEL_SIP_HDR_ALERT_INFO_RECEIVE_SUPPORT	1
	#endif //ZYXEL_SIP_HDR_ALERT_INFO_RECEIVE_SUPPORT.


	/*Following DISTINCTIVE_RINGER_DESCRIPTION_CONFIG will be use in backend All customer flag SHOULD follow zcfg_be defined*/
	#if defined(HAWAIIAN_TELCOM)
		#define ZYXEL_VOIP_DISTINCTIVE_RINGER_DESCRIPTION_CONFIG_AUTO_ADD 1
		#define ZYXEL_VOIP_SPLASH_RINGER_DESCRIPTION_CONFIG_AUTO_ADD 1
	#else
		#define ZYXEL_VOIP_DISTINCTIVE_RINGER_DESCRIPTION_CONFIG_AUTO_ADD 0
		#define ZYXEL_VOIP_SPLASH_RINGER_DESCRIPTION_CONFIG_AUTO_ADD 0
	#endif

	#if ZYXEL_VOIP_DISTINCTIVE_RINGER_DESCRIPTION_CONFIG_AUTO_ADD
		/*Other customer can add in here by #elif defined(XXXX)*/
		#ifdef HAWAIIAN_TELCOM
			#define ZYXEL_VOIP_DISTINCTIVE_RINGER_DESCRIPTION_CONFIG_PATTERN "http://127.0.0.1/nortel/dst_ring_%d" //This will be use to setting Ringer.Description.i.RingFile
			#define ZYXEL_VOIP_DISTINCTIVE_RINGER_DESCRIPTION_CONFIG_NUM 8 //This use to  control how many instance of Ringer.Description.i will be created.
		/*#elif defined(XXX)
			#define ZYXEL_VOIP_DISTINCTIVE_RINGER_DESCRIPTION_CONFIG_PATTERN "http://127.0.0.1/nortel/dst_ring_%d" //This will be use to setting Ringer.Description.i.RingFile
			#define ZYXEL_VOIP_DISTINCTIVE_RINGER_DESCRIPTION_CONFIG_NUM 8 //This use to  control how many instance of Ringer.Description.i will be created.
		*/
		#else //Generic pattern
			#define ZYXEL_VOIP_DISTINCTIVE_RINGER_DESCRIPTION_CONFIG_PATTERN "dst_ring_%d" //This will be use to setting Ringer.Description.i.RingFile
			#define ZYXEL_VOIP_DISTINCTIVE_RINGER_DESCRIPTION_CONFIG_NUM 8 //This use to  control how many instance of Ringer.Description.i will be created.
		#endif
	#endif

	#if ZYXEL_VOIP_SPLASH_RINGER_DESCRIPTION_CONFIG_AUTO_ADD
		/*Other customer can add in here by #elif defined(XXXX)*/
		#ifdef HAWAIIAN_TELCOM
			#define ZYXEL_VOIP_SPLASH_RINGER_DESCRIPTION_CONFIG_PATTERN "http://127.0.0.1/nortel/splash_ring" //This will be use to setting Ringer.Description.i.RingFile
		/*#elif defined(XXX)
			#define ZYXEL_VOIP_DISTINCTIVE_RINGER_DESCRIPTION_CONFIG_PATTERN "http://127.0.0.1/nortel/dst_ring_%d" //This will be use to setting Ringer.Description.i.RingFile
		*/
		#else //Generic pattern
			#define ZYXEL_VOIP_SPLASH_RINGER_DESCRIPTION_CONFIG_PATTERN "splash_ring" //This will be use to setting Ringer.Description.i.RingFile
		#endif
	#endif //#if ZYXEL_VOIP_SPLASH_RINGER_DESCRIPTION_CONFIG_AUTO_ADD
#endif //ZYXEL_VOIP_DISTINCTIVE_RING_SUPPORT.
//Michael.20171220.001.E: Add.

//Michael.20171124.001.B: Add to support the feature that while NO Enabled SIP Acct is Selected, the Phone Port would Behave Like it has NO function - (a)OffHook to play NO Tone (i.e. keep Silence) and (b)the corresponding VoIP LED always keeps in light-OFF no matter OffHook or OnHook states. This feature was first designed & implemented as a Customization Feature for the WIND Italy.
#if ZYPRJ_CUSTOMER_WIND
	//NOTE/DEPENDENCY: 'ZYXEL_PHONE_NO_ENABLED_SIP_ACCT_IS_SELECTED_MAKE_THE_PHONE_PORT_BEHAVE_LIKE_NO_FUNCTION' is designed to be a stand-alone PHONE feature. However, if/once 'ZYPRJ_CUSTOMER_WIND' is enabled, then it MUST be Enabled/Supported accordingly.
	#if !(ZYXEL_PHONE_NO_ENABLED_SIP_ACCT_IS_SELECTED_MAKE_THE_PHONE_PORT_BEHAVE_LIKE_NO_FUNCTION)
	#undef ZYXEL_PHONE_NO_ENABLED_SIP_ACCT_IS_SELECTED_MAKE_THE_PHONE_PORT_BEHAVE_LIKE_NO_FUNCTION
	#define ZYXEL_PHONE_NO_ENABLED_SIP_ACCT_IS_SELECTED_MAKE_THE_PHONE_PORT_BEHAVE_LIKE_NO_FUNCTION	1
	#endif //!(ZYXEL_PHONE_NO_ENABLED_SIP_ACCT_IS_SELECTED_MAKE_THE_PHONE_PORT_BEHAVE_LIKE_NO_FUNCTION).
#endif //ZYPRJ_CUSTOMER_WIND.

#ifndef ZYXEL_PHONE_NO_ENABLED_SIP_ACCT_IS_SELECTED_MAKE_THE_PHONE_PORT_BEHAVE_LIKE_NO_FUNCTION
	//NOTE/DEPENDENCY: 'ZYXEL_PHONE_LED_KEEPS_ALWAYS_OFF_FOR_THE_CASE_NO_ENABLED_SIP_ACCT_IS_SELECTED_OPERATION_SUPPORT' is designed to be a stand-alone PHONE feature. However, if/once 'ZYXEL_PHONE_NO_ENABLED_SIP_ACCT_IS_SELECTED_MAKE_THE_PHONE_PORT_BEHAVE_LIKE_NO_FUNCTION' is enabled, then it MUST be Enabled/Supported accordingly.
	//NOTE/DEPENDENCY: 'ZYXEL_PHONE_TONE_PLAYS_SILENCE_FOR_OFFHOOK_BUT_NO_ENABLED_SIP_ACCT_IS_SELECTED_SUPPORT' is designed to be a stand-alone PHONE feature. However, if/once 'ZYXEL_PHONE_NO_ENABLED_SIP_ACCT_IS_SELECTED_MAKE_THE_PHONE_PORT_BEHAVE_LIKE_NO_FUNCTION' is enabled, then it MUST be Enabled/Supported accordingly.
	#define ZYXEL_PHONE_NO_ENABLED_SIP_ACCT_IS_SELECTED_MAKE_THE_PHONE_PORT_BEHAVE_LIKE_NO_FUNCTION	0
	/** If Enabled, the DEPENDENCY will force the following two feature flags also Enabled:
	 ** (1)ZYXEL_PHONE_LED_KEEPS_ALWAYS_OFF_FOR_THE_CASE_NO_ENABLED_SIP_ACCT_IS_SELECTED_OPERATION_SUPPORT.
	 ** (2)ZYXEL_PHONE_TONE_PLAYS_SILENCE_FOR_OFFHOOK_BUT_NO_ENABLED_SIP_ACCT_IS_SELECTED_SUPPORT.
	 **/
#endif //ZYXEL_PHONE_NO_ENABLED_SIP_ACCT_IS_SELECTED_MAKE_THE_PHONE_PORT_BEHAVE_LIKE_NO_FUNCTION.
//Michael.20171124.001.E: Add.



//===========================================
//=== Phone Port Type Support Control's (Compile) Switch Flag ===
//===========================================
#ifndef ZYXEL_PHONE_EACH_TYPE_CH_NUM_MAX
	#define ZYXEL_PHONE_EACH_TYPE_CH_NUM_MAX 8 //NOTE: SHOULD >= max {ZYXEL_PHONE_XXX_CH_NUM_DEFAULT}!!
#endif //ZYXEL_PHONE_EACH_TYPE_CH_NUM_MAX.

//------------------------------------------(Phone: FXS)
#ifndef ZYXEL_PHONE_FXS_CH_NUM_DEFAULT
	#define ZYXEL_PHONE_FXS_CH_NUM_DEFAULT	2
#endif //ZYXEL_PHONE_FXS_CH_NUM_DEFAULT.
//------
#ifndef ZYXEL_PHONE_FXS_SUPPORT
	#define ZYXEL_PHONE_FXS_SUPPORT	1
#endif //ZYXEL_PHONE_FXS_SUPPORT.
#ifdef ZYXEL_PHONE_FXS_SUPPORT
	//#define ZYXEL_PHONE_FXS_SLIC_TYPE
	//------
	#ifndef ZYXEL_PHONE_FXS_CH_NUM
		#define ZYXEL_PHONE_FXS_CH_NUM ZYXEL_PHONE_FXS_CH_NUM_DEFAULT
	#endif //ZYXEL_PHONE_FXS_CH_NUM.
	//------
	#ifndef NUM_FXS_CHANNELS // TODO: To-Be-Removed!!!
		#define NUM_FXS_CHANNELS ZYXEL_PHONE_FXS_CH_NUM
	#endif //NUM_FXS_CHANNELS.
#endif //ZYXEL_PHONE_FXS_SUPPORT.

//------------------------------------------(Phone: FXO)
#ifndef ZYXEL_PHONE_FXO_CH_NUM_DEFAULT
	#define ZYXEL_PHONE_FXO_CH_NUM_DEFAULT	0
#endif //ZYXEL_PHONE_FXO_CH_NUM_DEFAULT.
//------
//#define ZYXEL_PHONE_FXO_SUPPORT	1 //SHOULD be controlled by the Makefile!
#ifdef ZYXEL_PHONE_FXO_SUPPORT
	//#define ZYXEL_PHONE_FXO_DAA_TYPE
	#ifndef ZYXEL_PHONE_FXO_CH_NUM
		#define ZYXEL_PHONE_FXO_CH_NUM ZYXEL_PHONE_FXO_CH_NUM_DEFAULT
	#endif //ZYXEL_PHONE_FXO_CH_NUM.
	#ifndef NUM_FXO_CHANNELS // TODO: To-Be-Removed!!!
		#define NUM_FXO_CHANNELS ZYXEL_PHONE_FXO_CH_NUM
	#endif //NUM_FXO_CHANNELS.
#endif //ZYXEL_PHONE_FXO_SUPPORT.

//------------------------------------------(Phone: FXO_LIFELINE)
//#define ZYXEL_PHONE_FXO_LIFELINE_SUPPORT	1 //SHOULD be controlled by the Makefile!

//------------------------------------------
//#define ZYXEL_FXO_DSPRELAY
//#define ZYXEL_LIFELINE_AUTODETECT

//------------------------------------------(Phone: DECT)
#ifndef ZYXEL_PHONE_DECT_CH_NUM_DEFAULT
	#define ZYXEL_PHONE_DECT_CH_NUM_DEFAULT	0
#endif //ZYXEL_PHONE_DECT_CH_NUM_DEFAULT.
//------
#ifndef ZYXEL_PHONE_DECT_CHIP_DSPG_CMBS_CH_NUM
	#define ZYXEL_PHONE_DECT_CHIP_DSPG_CMBS_CH_NUM 2
#endif //ZYXEL_PHONE_DECT_CHIP_DSPG_CMBS_CH_NUM.
//------
//#define ZYXEL_PHONE_DECT_SUPPORT	1 //SHOULD be controlled by the Makefile!
#ifdef ZYXEL_PHONE_DECT_SUPPORT
	//#define ZYXEL_PHONE_DECT_CHIP_TYPE
	#ifndef ZYXEL_PHONE_DECT_CH_NUM
		#define ZYXEL_PHONE_DECT_CH_NUM ZYXEL_PHONE_DECT_CH_NUM_DEFAULT // TODO: If the DECT Chip Type=DSPG CMBS DCX81, MAY define to 'ZYXEL_PHONE_DECT_CHIP_DSPG_CMBS_CH_NUM (2)'!
	#endif //ZYXEL_PHONE_DECT_CH_NUM.

	//Michael.20141210.001.B: Add by moving from the 'Endpoint_itf.c'.
	#ifndef DECT_BS_AUTO_FW_UPDATE_ENABLE
		#define DECT_BS_AUTO_FW_UPDATE_ENABLE 1
	#endif //DECT_BS_AUTO_FW_UPDATE_ENABLE.
	//Michael.20141210.001.E: Add by moving from the 'Endpoint_itf.c'.

	//Michael.20141210.001.B: Add.
	#if DECT_BS_AUTO_FW_UPDATE_ENABLE
		#ifndef ZYXEL_DECT_BS_FW_IMAGE
		#define ZYXEL_DECT_BS_FW_IMAGE "dectBS.bin"
		#endif //ZYXEL_DECT_BS_FW_IMAGE.

		#ifndef ZYXEL_DECT_BS_FW_IMAGE_ZIPPED_TARBALL
		#define ZYXEL_DECT_BS_FW_IMAGE_ZIPPED_TARBALL "dectBS.bin.tgz"
		#endif //ZYXEL_DECT_BS_FW_IMAGE_ZIPPED_TARBALL.

		#ifndef ZYXEL_DECT_BS_FW_IMAGE_INSTALL_DIR
		#define ZYXEL_DECT_BS_FW_IMAGE_INSTALL_DIR "/etc/dect"
		#endif //ZYXEL_DECT_BS_FW_IMAGE_INSTALL_DIR.

		//Choose Only either one of the following two - different DECT (BS) Chip FW Image encapsulation file formats.
		#define ZYXEL_DECT_BS_FW_IMAGE_FILE_PATH (ZYXEL_DECT_BS_FW_IMAGE_INSTALL_DIR "/" ZYXEL_DECT_BS_FW_IMAGE)
		//#define ZYXEL_DECT_BS_FW_IMAGE_FILE_PATH (ZYXEL_DECT_BS_FW_IMAGE_INSTALL_DIR "/" ZYXEL_DECT_BS_FW_IMAGE_ZIPPED_TARBALL)

		#if 0
		#ifndef ZYXEL_DECT_BS_FW_IMAGE_VER
		#define ZYXEL_DECT_BS_FW_IMAGE_VER "3.638"
		#endif //ZYXEL_DECT_BS_FW_IMAGE_VER.

		#ifndef ZYXEL_DECT_BS_FW_IMAGE_BUILD_NUM
		#define ZYXEL_DECT_BS_FW_IMAGE_BUILD_NUM "0327"
		#endif //ZYXEL_DECT_BS_FW_IMAGE_BUILD_NUM.
		#endif //0.
	#endif //DECT_BS_AUTO_FW_UPDATE_ENABLE.
	//Michael.20141210.001.E: Add.

	//---Temporary Usage---
	//#define ZYXEL_PHONE_DECT_TO2_IMPLEMENT	1
	//#define ZYXEL_PHONE_DECT_NICK_LU_MODIFY	1
#endif //ZYXEL_PHONE_DECT_SUPPORT.

//------------------------------------------(Phone: ISDN_NT)
//#define ZYXEL_PHONE_ISDN_NT_SUPPORT	1 //SHOULD be controlled by the Makefile!
#ifdef ZYXEL_PHONE_ISDN_NT_SUPPORT
	//#define ZYXEL_PHONE_ISDN_NT_TYPE
	#ifndef ZYXEL_PHONE_ISDN_NT_CH_NUM_DEFAULT
		#define ZYXEL_PHONE_ISDN_NT_CH_NUM_DEFAULT	0
	#endif //ZYXEL_PHONE_ISDN_NT_CH_NUM_DEFAULT.
	#ifndef ZYXEL_PHONE_ISDN_NT_CH_NUM
		#define ZYXEL_PHONE_ISDN_NT_CH_NUM ZYXEL_PHONE_ISDN_NT_CH_NUM_DEFAULT
	#endif //ZYXEL_PHONE_ISDN_NT_CH_NUM.
#endif //ZYXEL_PHONE_ISDN_NT_SUPPORT.

//------------------------------------------(Phone: ISDN_TE)
//#define ZYXEL_PHONE_ISDN_TE_SUPPORT	1 //SHOULD be controlled by the Makefile!
#ifdef ZYXEL_PHONE_ISDN_TE_SUPPORT
	//#define ZYXEL_PHONE_ISDN_TE_TYPE
	#ifndef ZYXEL_PHONE_ISDN_TE_CH_NUM_DEFAULT
		#define ZYXEL_PHONE_ISDN_TE_CH_NUM_DEFAULT	0
	#endif //ZYXEL_PHONE_ISDN_TE_CH_NUM_DEFAULT.
	#ifndef ZYXEL_PHONE_ISDN_TE_CH_NUM
		#define ZYXEL_PHONE_ISDN_TE_CH_NUM ZYXEL_PHONE_ISDN_TE_CH_NUM_DEFAULT
	#endif //ZYXEL_PHONE_ISDN_TE_CH_NUM.
#endif //ZYXEL_PHONE_ISDN_TE_SUPPORT.


//=============================
//=== Local Phone Port VoIP LED Control ===
//=============================
/*** VoIP/Phone LED Operation Special Logic-(4): WIND Customization (ZyIMS Internal Feature Flag Only). ***/
/*==(4a)==*/
//Michael.20171124.001.B: Add to support the feature that while NO Enabled SIP Acct is Selected, the Phone Port would Behave Like it has NO function - (a)OffHook to play NO Tone (i.e. keep Silence) and (b)the corresponding VoIP LED always keeps in light-OFF no matter OffHook or OnHook states. This feature was first designed & implemented as a Customization Feature for the WIND Italy.
#if ZYXEL_PHONE_NO_ENABLED_SIP_ACCT_IS_SELECTED_MAKE_THE_PHONE_PORT_BEHAVE_LIKE_NO_FUNCTION
	//NOTE/DEPENDENCY: 'ZYXEL_PHONE_LED_KEEPS_ALWAYS_OFF_FOR_THE_CASE_NO_ENABLED_SIP_ACCT_IS_SELECTED_OPERATION_SUPPORT' is designed to be a stand-alone PHONE feature. However, if/once 'ZYXEL_PHONE_NO_ENABLED_SIP_ACCT_IS_SELECTED_MAKE_THE_PHONE_PORT_BEHAVE_LIKE_NO_FUNCTION' is enabled, then it MUST be Enabled/Supported accordingly.
	#if !(ZYXEL_PHONE_LED_KEEPS_ALWAYS_OFF_FOR_THE_CASE_NO_ENABLED_SIP_ACCT_IS_SELECTED_OPERATION_SUPPORT)
	#undef ZYXEL_PHONE_LED_KEEPS_ALWAYS_OFF_FOR_THE_CASE_NO_ENABLED_SIP_ACCT_IS_SELECTED_OPERATION_SUPPORT
	#define ZYXEL_PHONE_LED_KEEPS_ALWAYS_OFF_FOR_THE_CASE_NO_ENABLED_SIP_ACCT_IS_SELECTED_OPERATION_SUPPORT	1
	#endif //!(ZYXEL_PHONE_LED_KEEPS_ALWAYS_OFF_FOR_THE_CASE_NO_ENABLED_SIP_ACCT_IS_SELECTED_OPERATION_SUPPORT).
#endif //ZYXEL_PHONE_NO_ENABLED_SIP_ACCT_IS_SELECTED_MAKE_THE_PHONE_PORT_BEHAVE_LIKE_NO_FUNCTION.

#ifndef ZYXEL_PHONE_LED_KEEPS_ALWAYS_OFF_FOR_THE_CASE_NO_ENABLED_SIP_ACCT_IS_SELECTED_OPERATION_SUPPORT
	#define ZYXEL_PHONE_LED_KEEPS_ALWAYS_OFF_FOR_THE_CASE_NO_ENABLED_SIP_ACCT_IS_SELECTED_OPERATION_SUPPORT	0
#endif //ZYXEL_PHONE_LED_KEEPS_ALWAYS_OFF_FOR_THE_CASE_NO_ENABLED_SIP_ACCT_IS_SELECTED_OPERATION_SUPPORT.
//Michael.20171124.001.E: Add.

/*==(4b)==*/
//Michael.20171110.001.B: Add to support to Re-define to Make the Amber VoIP LED stand-for or represent the corresponding Phone Port's Selected (Outgoing Call) SIP Account is "Enabled but UnRegistered (due to maybe (a)Register Fail (NOT Registered yet), or (b)Manually DeRegsitered)", rather than "Registered and also getting the MWI". This feature was first designed & implemented as a Customization Feature for the WIND Italy.
#if ZYPRJ_CUSTOMER_WIND
	//NOTE/DEPENDENCY: 'ZYXEL_PHONE_LED_AMBER_LED_STANDS_FOR_SELECTED_SIP_ACCT_ENABLED_BUT_UNREGISTERED_OPERATION_SUPPORT' is designed to be a stand-alone PHONE feature. However, if/once 'ZYPRJ_CUSTOMER_WIND' is enabled, then it MUST be Enabled/Supported accordingly.
	#if !(ZYXEL_PHONE_LED_AMBER_LED_STANDS_FOR_SELECTED_SIP_ACCT_ENABLED_BUT_UNREGISTERED_OPERATION_SUPPORT)
	#undef ZYXEL_PHONE_LED_AMBER_LED_STANDS_FOR_SELECTED_SIP_ACCT_ENABLED_BUT_UNREGISTERED_OPERATION_SUPPORT
	#define ZYXEL_PHONE_LED_AMBER_LED_STANDS_FOR_SELECTED_SIP_ACCT_ENABLED_BUT_UNREGISTERED_OPERATION_SUPPORT	1
	#endif //!(ZYXEL_PHONE_LED_AMBER_LED_STANDS_FOR_SELECTED_SIP_ACCT_ENABLED_BUT_UNREGISTERED_OPERATION_SUPPORT).
#endif //ZYPRJ_CUSTOMER_WIND.

#ifndef ZYXEL_PHONE_LED_AMBER_LED_STANDS_FOR_SELECTED_SIP_ACCT_ENABLED_BUT_UNREGISTERED_OPERATION_SUPPORT
	#define ZYXEL_PHONE_LED_AMBER_LED_STANDS_FOR_SELECTED_SIP_ACCT_ENABLED_BUT_UNREGISTERED_OPERATION_SUPPORT	0
#endif //ZYXEL_PHONE_LED_AMBER_LED_STANDS_FOR_SELECTED_SIP_ACCT_ENABLED_BUT_UNREGISTERED_OPERATION_SUPPORT.
//Michael.20171110.001.E: Add.

/*==(4c)==*/
//Michael.20171229.001.B: Add to enhance 'ZYXEL_PHONE_LED_AMBER_LED_STANDS_FOR_SELECTED_SIP_ACCT_ENABLED_BUT_UNREGISTERED_OPERATION_SUPPORT' able to decide/control whether the AMBER VoIP LED has to BLINK or Not while the Phone Port is OffHooked or RINGing under the AMBER LED condition. This VoIP LED detail operation logic control feature was (originally) designed to meet WIND's requirement since they request to have AMBER LED Always Solid ON at that condition to prevent the BLINK behavior from giving the end-users wrong impression that there are traffic passing through.
#if ZYPRJ_CUSTOMER_WIND
	//NOTE/DEPENDENCY: 'ZYXEL_PHONE_LED_WHEN_AMBER_CONDITION_OFFHOOK_AND_RINGING_NO_BLINK_SUPPORT' is designed to be a stand-alone PHONE feature. However, if/once 'ZYPRJ_CUSTOMER_WIND' is enabled, then it MUST be Enabled/Supported accordingly.
	#if !(ZYXEL_PHONE_LED_WHEN_AMBER_CONDITION_OFFHOOK_AND_RINGING_NO_BLINK_SUPPORT)
	#undef ZYXEL_PHONE_LED_WHEN_AMBER_CONDITION_OFFHOOK_AND_RINGING_NO_BLINK_SUPPORT
	#define ZYXEL_PHONE_LED_WHEN_AMBER_CONDITION_OFFHOOK_AND_RINGING_NO_BLINK_SUPPORT	1
	#endif //!(ZYXEL_PHONE_LED_WHEN_AMBER_CONDITION_OFFHOOK_AND_RINGING_NO_BLINK_SUPPORT).
#endif //ZYPRJ_CUSTOMER_WIND.

#ifndef ZYXEL_PHONE_LED_WHEN_AMBER_CONDITION_OFFHOOK_AND_RINGING_NO_BLINK_SUPPORT
	#define ZYXEL_PHONE_LED_WHEN_AMBER_CONDITION_OFFHOOK_AND_RINGING_NO_BLINK_SUPPORT 0
#endif //ZYXEL_PHONE_LED_WHEN_AMBER_CONDITION_OFFHOOK_AND_RINGING_NO_BLINK_SUPPORT.
//Michael.20171229.001.E: Add.


/*** VoIP/Phone LED Operation Special Logic-(1): Only GREEN LED per Port. ***/
//Michael.20171110.001.B: Add to support to Re-define to Make the Amber VoIP LED stand-for or represent the corresponding Phone Port's Selected (Outgoing Call) SIP Account is "Enabled but UnRegistered (due to maybe (a)Register Fail (NOT Registered yet), or (b)Manually DeRegsitered)", rather than "Registered and also getting the MWI". This feature was first designed & implemented as a Customization Feature for the WIND Italy.
// TODO: the following DEPENDENCY description & relationship MUST be Removed, especially after the 'ZYXEL_PHONE_LED_MWI_IS_STILL_PRESENTED_BY_NORMAL_GREEN_LED_OPERATION_SUPPORT' has been created & defined!!!
#if ZYXEL_PHONE_LED_AMBER_LED_STANDS_FOR_SELECTED_SIP_ACCT_ENABLED_BUT_UNREGISTERED_OPERATION_SUPPORT
	//NOTE/DEPENDENCY: 'ZYXEL_PHONE_LED_ONLY_GREEN_REG_LED_PER_PORT_OPERATION_SUPPORT' is designed to be a stand-alone PHONE feature. However, if/once 'ZYXEL_PHONE_LED_AMBER_LED_STANDS_FOR_SELECTED_SIP_ACCT_ENABLED_BUT_UNREGISTERED_OPERATION_SUPPORT' is enabled, then it MUST be Enabled/Supported accordingly.
	#if !(ZYXEL_PHONE_LED_ONLY_GREEN_REG_LED_PER_PORT_OPERATION_SUPPORT)
	#undef ZYXEL_PHONE_LED_ONLY_GREEN_REG_LED_PER_PORT_OPERATION_SUPPORT
	#define ZYXEL_PHONE_LED_ONLY_GREEN_REG_LED_PER_PORT_OPERATION_SUPPORT 1
	#endif //!(ZYXEL_PHONE_LED_ONLY_GREEN_REG_LED_PER_PORT_OPERATION_SUPPORT).
#endif //ZYXEL_PHONE_LED_AMBER_LED_STANDS_FOR_SELECTED_SIP_ACCT_ENABLED_BUT_UNREGISTERED_OPERATION_SUPPORT.
//Michael.20171110.001.E: Add.

//Michael.20151203.001.B: Modify to rename the feature (compile) flag 'ZYXEL_PHONE_SINGLE_LED_OPERATION_SUPPORT' to 'ZYXEL_PHONE_LED_ONLY_GREEN_REG_LED_PER_PORT_OPERATION_SUPPORT'.
//#ifndef ZYXEL_PHONE_SINGLE_LED_OPERATION_SUPPORT //Michael.20150526.001: Add to Enhance to Support Single LED Operation for one Local Phone Port.
//#define ZYXEL_PHONE_SINGLE_LED_OPERATION_SUPPORT 0
//#endif //ZYXEL_PHONE_SINGLE_LED_OPERATION_SUPPORT.
#ifndef ZYXEL_PHONE_LED_ONLY_GREEN_REG_LED_PER_PORT_OPERATION_SUPPORT
	#define ZYXEL_PHONE_LED_ONLY_GREEN_REG_LED_PER_PORT_OPERATION_SUPPORT 0
#endif //ZYXEL_PHONE_LED_ONLY_GREEN_REG_LED_PER_PORT_OPERATION_SUPPORT.
//Michael.20151203.001.E: Modify.


/*** VoIP/Phone LED Operation Special Logic-(2): RED (Fail) LED related. ***/
/*==(2a)==*/
//Michael.20151207.001.B: Add to support the Amber VoIP Phone LED is composed of lightening-up the Green & Red LEDs simultaneously.
#ifndef ZYXEL_PHONE_LED_AMBER_MWI_LED_IS_COMPOSED_OF_GREEN_AND_RED_LED_OPERATION_SUPPORT
	#define ZYXEL_PHONE_LED_AMBER_MWI_LED_IS_COMPOSED_OF_GREEN_AND_RED_LED_OPERATION_SUPPORT 0
#endif //ZYXEL_PHONE_LED_AMBER_MWI_LED_IS_COMPOSED_OF_GREEN_AND_RED_LED_OPERATION_SUPPORT.

/*==(2b)==*/
#if ZYXEL_PHONE_LED_AMBER_MWI_LED_IS_COMPOSED_OF_GREEN_AND_RED_LED_OPERATION_SUPPORT
	//NOTE/DEPENDENCY: 'ZYXEL_PHONE_LED_RED_FAIL_LED_OPERATION_SUPPORT' is designed to be a stand-alone PHONE feature. However, if/once 'ZYXEL_PHONE_LED_AMBER_MWI_LED_IS_COMPOSED_OF_GREEN_AND_RED_LED_OPERATION_SUPPORT' is enabled, then it MUST be Enabled/Supported accordingly.
	#if !(ZYXEL_PHONE_LED_RED_FAIL_LED_OPERATION_SUPPORT)
	#undef ZYXEL_PHONE_LED_RED_FAIL_LED_OPERATION_SUPPORT
	#define ZYXEL_PHONE_LED_RED_FAIL_LED_OPERATION_SUPPORT 1
	#endif //!(ZYXEL_PHONE_LED_RED_FAIL_LED_OPERATION_SUPPORT).
#endif //ZYXEL_PHONE_LED_AMBER_MWI_LED_IS_COMPOSED_OF_GREEN_AND_RED_LED_OPERATION_SUPPORT.
//Michael.20151207.001.E: Add.

/*** VoIP/Phone LED Operation Capability - Fail/Error Indication dedicated LED. ***/
#ifndef ZYXEL_PHONE_LED_RED_FAIL_LED_OPERATION_SUPPORT //Michael.20151207.002: Add to support the Red Fail VoIP Phone LED.
	//NOTE/DEPENDENCY: 'ZYXEL_PHONE_LED_RED_FAIL_LED_OPERATION_SUPPORT' is designed to be a stand-alone PHONE feature. However, if/once 'ZYXEL_PHONE_LED_AMBER_MWI_LED_IS_COMPOSED_OF_GREEN_AND_RED_LED_OPERATION_SUPPORT' is enabled, then it MUST be Enabled/Supported accordingly.
	#define ZYXEL_PHONE_LED_RED_FAIL_LED_OPERATION_SUPPORT 0
#endif //ZYXEL_PHONE_LED_RED_FAIL_LED_OPERATION_SUPPORT.


/*** VoIP/Phone LED Operation Special Logic-(3): Joint/Common Used Single Set (Bi-Color) LED. ***/
#ifndef ZYXEL_PHONE_LED_SINGLE_SET_LED_COMMON_USED_BY_SEVERAL_PORTS_OPERATION_SUPPORT //Michael.20151203.002: Add to prepare the feature (compile) flag & its corresponding "make menuconfig" entry for the future usage & function implement.
	#define ZYXEL_PHONE_LED_SINGLE_SET_LED_COMMON_USED_BY_SEVERAL_PORTS_OPERATION_SUPPORT 0
#endif //ZYXEL_PHONE_LED_SINGLE_SET_LED_COMMON_USED_BY_SEVERAL_PORTS_OPERATION_SUPPORT.

//Michael.20171106.001.B: Add to support the feature that - A Single Set LED (usually composed of the Green & Amber color ones) Commonly used by Several Phone Ports (p.s. 'All FXS' Phone Ports now, by default).
#if ZYXEL_PHONE_LED_SINGLE_SET_LED_COMMON_USED_BY_SEVERAL_PORTS_OPERATION_SUPPORT
	#ifndef COMMON_USED_SINGLE_SET_VOIP_LED_PHY_ID
	#define COMMON_USED_SINGLE_SET_VOIP_LED_PHY_ID 0 //NOTE: Currently, this is designed to be FIXED at the First Set VoIP LED, i.e. PhyId=0.
	#endif //COMMON_USED_SINGLE_SET_VOIP_LED_PHY_ID.
#endif //ZYXEL_PHONE_LED_SINGLE_SET_LED_COMMON_USED_BY_SEVERAL_PORTS_OPERATION_SUPPORT.
//Michael.20171106.001.E: Add.

//Michael.20171124.002.B: Add to enhance 'PHONE_LED_SINGLE_SET_LED_COMMON_USED_BY_SEVERAL_PORTS_OPERATION_SUPPORT' able to change the VoIP LED FuncType(ColorType) Priority to support the feature where the Amber-color does NOT represent the MWI.
#define ZYXEL_PHONE_LED_FUNC_TYPE_PRIORITY_LOW_TO_HIGH_IS_GREEN_AMBER_RED_SUPPORT 0 //Default Priority.
#define ZYXEL_PHONE_LED_FUNC_TYPE_PRIORITY_LOW_TO_HIGH_IS_AMBER_GREEN_RED_SUPPORT 1
#ifndef ZYXEL_PHONE_LED_FUNC_TYPE_PRIORITY
	#define ZYXEL_PHONE_LED_FUNC_TYPE_PRIORITY	ZYXEL_PHONE_LED_FUNC_TYPE_PRIORITY_LOW_TO_HIGH_IS_GREEN_AMBER_RED_SUPPORT
#endif //ZYXEL_PHONE_LED_FUNC_TYPE_PRIORITY.

#if ZYPRJ_CUSTOMER_WIND
	//NOTE/DEPENDENCY: 'ZYXEL_PHONE_LED_FUNC_TYPE_PRIORITY' is designed to be a stand-alone PHONE feature. However, if/once 'ZYPRJ_CUSTOMER_WIND' is enabled, then it MUST be Enabled/Supported accordingly.
	#if !(ZYXEL_PHONE_LED_FUNC_TYPE_PRIORITY)
	#undef ZYXEL_PHONE_LED_FUNC_TYPE_PRIORITY
	#define ZYXEL_PHONE_LED_FUNC_TYPE_PRIORITY	ZYXEL_PHONE_LED_FUNC_TYPE_PRIORITY_LOW_TO_HIGH_IS_AMBER_GREEN_RED_SUPPORT
	#endif //!(ZYXEL_PHONE_LED_FUNC_TYPE_PRIORITY).
#endif //ZYPRJ_CUSTOMER_WIND.
//Michael.20171124.002.E: Add.


//Michael.20171114.001.B: Add to support to skip the VoIP LED Control Request which is totally the Same as the Current Operation Status (since the 'Michael.20171030.001' had made the PhoneSB able to record the VoIP LED Operation Status).
#ifndef ZYXEL_PHONE_LED_SKIP_THE_VOIP_LED_CTRL_REQ_SAME_AS_THE_CURRENT_OP_STATUS
	#define ZYXEL_PHONE_LED_SKIP_THE_VOIP_LED_CTRL_REQ_SAME_AS_THE_CURRENT_OP_STATUS 0
#endif //ZYXEL_PHONE_LED_SKIP_THE_VOIP_LED_CTRL_REQ_SAME_AS_THE_CURRENT_OP_STATUS.
//Michael.20171114.001.E: Add.



//========================
//=== Misc (Compile) Switch Flag ===
//========================
#define Yushiuan_hardcode_temporary
#define SPECIAL_DESIGN_NOTATION //Michael.20130701.001: Add to mark/note some special designs of the operation logic.
//Michael.20121023.001.E: Add to implement the new designed Phone Port CB FSM with the new operation logic
//*****************************************************************************************************

#ifdef OLD_ZYIMS_VOIP_AGE_1 //Michael.20121023.001 *****************************************************************
/*_____ SLIC TYPE _________________________________________*/
#define SLIC_NONE		0
#define SLIC_SI3210		1
#define SLIC_SI3220		2
#define SLIC_SI3215		3
#define SLIC_PEF4268	4

/*_____DECT TYPE_________________________________________*/
#define DECT_NONE	0
#define WB_3519		1

/*_____ DAA Type _________________________________________*/
#define DAA_NONE	0
#define DAA_SI3019	1
#define DAA_SI3011	2

/*_____ Voice DSP Type _________________________________________*/
#define VDSP_NONE		0
#define VDSP_TI5402		1
#define VDSP_TI5409		2
#define VDSP_VP1001		3
#define VDSP_TI921		4
#define VDSP_PMC4200	5
#define VDSP_DANUBE	6
#define VDSP_BRCM6358	7

/*_____ Caller ID Type _________________________________________*/
#define Polarity_Reverse		0
#define First_Ring			1

/*_____ Caller ID Payload Type _________________________________________*/
#define CID_DTMF			0
#define CID_FSK				1

//--------------------------------------------
/* The following definition must be reference through TR104*/
//#define FXO			0
//#define FXO_DSPRELAY	0
//#define PH_SLIC_NUM_CHANNELS		1
//#define PH_FXS_NUM_CHANNELS	PH_SLIC_NUM_CHANNELS
#ifndef PH_DECT_NUM_CHANNELS
	#define PH_DECT_NUM_CHANNELS	0
#endif
//#define PH_DAA_NUM_CHANNELS		0
//#define PH_FXO_NUM_CHANNELS	PH_DAA_NUM_CHANNELS
//#define PH_TOTAL_NUM_CHANNELS		(PH_FXS_NUM_CHANNELS + PH_FXO_NUM_CHANNELS)
//#define LIFELINE_AUTODETECT 		1	/* LifeLine Auto chcek */
//--------------------------------------------
#define SUPPORT_SLIC	SLIC_NONE
#ifndef SUPPORT_DECT
	#define SUPPORT_DECT	DECT_NONE
#endif
#define SUPPORT_DAA	DAA_NONE
#define SUPPORT_VDSP	VDSP_BRCM6358
//--------------------------------------------
#define CALLERID_TYPE		First_Ring
#define CALLERID_PAYLOAD	CID_FSK
//--------------------------------------------
#define STOP_RING_BY_FW	1
//--------------------------------------------

/*_____ Trunk Definition ____________________________________*/
#define TRUNK340			0
#define TRUNK350			1
#define TRUNK350NEW		2
#define TRUNK370			3
#define TRUNK_DEFINE		TRUNK370

/* Eric Chen, merge from Jacky */
#define LONG_DEFINED
#endif //OLD_ZYIMS_VOIP_AGE_1 //Michael.20121023.001 *****************************************************************


//==================================< System & Platform.
//Michael.20141121.002.B: Add to do enhancements (some ones are the preparation for the future) along with the BRCM SDK 416L02A support task.
#ifndef ZYXEL_VOIP_WRITABLE_PARTITION_DIR // TODO: It's BETTER to be controlled by the "make menuconfig" PROFILE.
	#define ZYXEL_VOIP_WRITABLE_PARTITION_DIR "/data" //NOTE: the directory "/data" is the default one for writable partition in the BRCM platform.
#endif //ZYXEL_VOIP_WRITABLE_PARTITION_DIR.
//Michael.20141121.002.E: Add.

//SteveChan.20160524 Add
#ifndef ZYXEL_VOIP_TMP_DIR
	#define ZYXEL_VOIP_TMP_DIR "/tmp"
#endif

//Michael.20141210.001.B: Add to do enhancements (some ones are the preparation for the future) along with the BRCM SDK 416L02A support task.
#ifndef ZYXEL_VOIP_ZYIMS_INSTALL_BIN_DIR // TODO: It's BETTER to be controlled by the "make menuconfig" PROFILE.
	#define ZYXEL_VOIP_ZYIMS_INSTALL_BIN_DIR "/usr/bin" //NOTE: the directory "/usr/bin" is the default one for the ZyIMS VoIP Application.
#endif //ZYXEL_VOIP_ZYIMS_INSTALL_BIN_DIR.
//Michael.20141210.001.E: Add.


/* VoIP */
//--------------------------------------------
//#define VOIP			1
//#define VOIP_NEW		1
//#define VOIP_PHASEII	1


//==================================< SIP
//#define VOIP_SIP		1
//#ifdef VOIP_SIP
//#define VOIPSIPACCOUNT		2
#ifndef ZYXEL_SIP_PROFILE_NUM_MAX
//Michael.20140520.001.B: Modify to support 10 SIP accounts by 1 Voice Profile with Max 10 Voice Lines.
#ifdef ZYPRJ_CUSTOMER_SUNRISE	// TODO: It's BETTER to be controlled by the "make menuconfig" PROFILE, NOT the Customization Compile Flag!
	#define ZYXEL_SIP_PROFILE_NUM_MAX 1
#else
	#define ZYXEL_SIP_PROFILE_NUM_MAX 2
#endif
//Michael.20140520.001.E: Modify to support 10 SIP accounts by 1 Voice Profile with Max 10 Voice Lines.
#endif //ZYXEL_SIP_PROFILE_NUM_MAX.

#ifndef APPS_ZYIMS_PROFILE_NUM //referred by 'icf_defs.h' & 'mm_core_fsm_defs.h'.
	#define APPS_ZYIMS_PROFILE_NUM	ZYXEL_SIP_PROFILE_NUM_MAX  // TODO: it's better to replace all usage of 'APPS_ZYIMS_PROFILE_NUM' to 'ZYXEL_SIP_PROFILE_NUM_MAX'.
#endif //APPS_ZYIMS_PROFILE_NUM.

#ifndef ZYXEL_SIP_LINE_PER_PROFILE_NUM_MAX
//Michael.20140520.001.B: Modify to support 10 SIP accounts by 1 Voice Profile with Max 10 Voice Lines.
#ifdef ZYPRJ_CUSTOMER_SUNRISE	// TODO: It's BETTER to be controlled by the "make menuconfig" PROFILE, NOT the Customization Compile Flag!
	#define ZYXEL_SIP_LINE_PER_PROFILE_NUM_MAX 10
#else
	#define ZYXEL_SIP_LINE_PER_PROFILE_NUM_MAX 4
#endif
//Michael.20140520.001.E: Modify to support 10 SIP accounts by 1 Voice Profile with Max 10 Voice Lines.
#endif //ZYXEL_SIP_LINE_PER_PROFILE_NUM_MAX.

#ifndef APPS_ZYIMS_LINE_PER_PROFILE_NUM //referred by 'icf_defs.h' & 'mm_core_fsm_defs.h'.
	#define APPS_ZYIMS_LINE_PER_PROFILE_NUM	ZYXEL_SIP_LINE_PER_PROFILE_NUM_MAX  // TODO: it's better to replace all usage of 'APPS_ZYIMS_LINE_PER_PROFILE_NUM' to 'ZYXEL_SIP_LINE_PER_PROFILE_NUM_MAX'.
#endif //APPS_ZYIMS_LINE_PER_PROFILE_NUM.


//--------------------------------------------(SIP: SIP Header)
//#define USER_AGENT_HDR  ""
#define ZYXEL_SIP_HDR_USER_AGENT_NAME_DEFAULT "ZyXEL Communications Corp. SIP Client - ZyIMS VoIP"

#ifndef ZYXEL_SIP_HDR_P_ACCESS_NETWORK_INFO_SUPPORT
#define ZYXEL_SIP_HDR_P_ACCESS_NETWORK_INFO_SUPPORT 1 //However, you can dynamically switch this header ON/OFF by Filling/Clearing the corresponding Data Model paremeters: (1)Device.Services.VoiceService.{i}.VoiceProfile.{i}.X_ZYXEL_P_AccessNetworkInfo, (2)Device.Services.VoiceService.{i}.X_ZYXEL_Common.P_AccessNetworkInfo.
#endif //ZYXEL_SIP_HDR_P_ACCESS_NETWORK_INFO_SUPPORT

//Michael.20171006.001.B: Add to support to receive/retrieve and parse the <Alert-Info> header content presented in the Incoming SIP Message.
#ifndef ZYXEL_SIP_HDR_ALERT_INFO_RECEIVE_SUPPORT
//NOTE/DEPENDENCY: 'ZYXEL_SIP_HDR_ALERT_INFO_RECEIVE_SUPPORT' is designed to be a stand-alone CALL feature. However, if/once 'ZYXEL_VOIP_DISTINCTIVE_RING_SUPPORT' is enabled, then it MUST be Enabled/Supported accordingly.
#define ZYXEL_SIP_HDR_ALERT_INFO_RECEIVE_SUPPORT 1
#endif //ZYXEL_SIP_HDR_ALERT_INFO_RECEIVE_SUPPORT.

#if ZYXEL_SIP_HDR_ALERT_INFO_RECEIVE_SUPPORT
	#define ZYXEL_SIP_HDR_ALERT_INFO_STR "Alert-Info"
#endif //ZYXEL_SIP_HDR_ALERT_INFO_RECEIVE_SUPPORT.
//Michael.20171006.001.E: Add.


//--------------------------------------------(SIP: Register & De-Register)
//Michael.20170926.001.B: Add by removing from the below section "(SIP: Special & Customization Config)".
//Michael.20140522.001.B: Add to support De-Register ALL active VoIP SIP accounts first before doing reboot.
#ifndef ZYXEL_SIP_DEREGISTER_ALL_ACCT_BEFORE_SHUTDOWN_SUPPORT
#define ZYXEL_SIP_DEREGISTER_ALL_ACCT_BEFORE_SHUTDOWN_SUPPORT 1
#endif //ZYXEL_SIP_DEREGISTER_ALL_ACCT_BEFORE_SHUTDOWN_SUPPORT.
//Michael.20140522.001.E: Add.
//Michael.20170926.001.E: Add.

//----------
//Michael.20170926.001.B: Add to Reserve an VoIP IOP BitFlag '(1 << 8)' to Support to DeRegister Local Contact Only.
#ifndef ZYXEL_SIP_DEREGISTER_LOCAL_CONTACT_ONLY_SUPPORT
#define ZYXEL_SIP_DEREGISTER_LOCAL_CONTACT_ONLY_SUPPORT 1
#endif //ZYXEL_SIP_DEREGISTER_LOCAL_CONTACT_ONLY_SUPPORT.
//Michael.20170926.001.E: Add.


//--------------------------------------------(SIP: Call Session Count/Number)
#define MULTI_SIP_SESSION		1  // TODO: it's better to renamed to 'ZYXEL_SIP_MULTI_SESSION_SUPPORT'.
//Michael.20130820.006.B: Add.
#ifndef ZYXEL_SIP_SESSION_PER_LINE_NUM_MAX
	#define ZYXEL_SIP_SESSION_PER_LINE_NUM_MAX 2
#endif //ZYXEL_SIP_SESSION_PER_LINE_NUM_MAX.
//Michael.20130820.006.E: Add.

#ifndef ZYXEL_SIP_SESSION_CONCURRENT_NUM_MAX
#ifdef ZYPRJ_CUSTOMER_SUNRISE	// TODO: It's BETTER to be controlled by the "make menuconfig" PROFILE, NOT the Customization Compile Flag!
	#define ZYXEL_SIP_SESSION_CONCURRENT_NUM_MAX 2
#else
	#define ZYXEL_SIP_SESSION_CONCURRENT_NUM_MAX 10
#endif //ZYPRJ_CUSTOMER_SUNRISE.
#endif //ZYXEL_SIP_SESSION_CONCURRENT_NUM_MAX.


//--------------------------------------------(SIP: Protocol Spec/Standard related Feature)
/*RFC-3262: PRACK*/
#define ZYXEL_SIP_PRACK_FOR_INCALL_SUPPORT_SOFT_REQUIRE_MODE_AND_REDEFINE_KEYWORD_SUPPORTED_FOR_IT 1 //Michael.20160807.001: Add to support a Soft-"REQUIRE" PRACK mode for the InCall case to establish a Non-PRACK Call for the condition {InCallPrack:NO_PRACK, LocalPrackCfg:REQUIRE} and Re-define the un-used "SUPPORTED" mode keyword for it. [Redmine#17963 & #25639, with referring to #3455(eITS#140600827)].


//--------------------------------------------(SIP: Server Discover & Auto Config)
//Michael.20130616.001.B: Add.
//#define ZYXEL_SIP_IPV4_DHCP_OPTION120_SUPPORT	1
//#define ZYXEL_SIP_IPV6_DHCP_OPTION21_SUPPORT	1
#define ZYXEL_SIP_DNS_SRV_SUPPORT	1
//#define ZYXEL_SIP_DNS_SRV_SUPPORT_OLD 1
#if defined(ZYXEL_SIP_DNS_SRV_SUPPORT) || defined(ZYXEL_SIP_DNS_SRV_SUPPORT_OLD) //Move from 'voiceApp_iptk_api.h'.
	#define DNSSRV_PROFILE_NUM      ZYXEL_SIP_PROFILE_NUM_MAX
	#define DNSSRV_ENTRY_NUM        10
#endif //ZYXEL_SIP_DNS_SRV_SUPPORT.

#if defined(ZYXEL_SIP_DNS_SRV_SUPPORT) && defined(ZYXEL_SIP_DNS_SRV_SUPPORT_OLD)
#error "<<Error>> Cannot define ZYXEL_SIP_DNS_SRV_SUPPORT and ZYXEL_SIP_DNS_SRV_SUPPORT_OLD at same time."
#endif
//Steve. 2015-01-21 Add ZYXEL_SIP_DNS_SRV_SUPPORT_OLD to control old DNS SRV routine. And do define check
//Michael.20130616.001.E: Add.

//--------------------------------------------(SIP: Keep-alive/HeatBeat)
//Michael.20170705.001.B: Add by removing from the below (section: IPTK).
#if defined(IPTK_REL_8_0) || defined(IPTK_REL_8_2_2)

#ifndef HEARTBEAT_MECHANISM_ENABLE
#define HEARTBEAT_MECHANISM_ENABLE	0	/* 1:on , 0:off */
#endif //HEARTBEAT_MECHANISM_ENABLE.

#endif //defined(IPTK_REL_8_0) || defined(IPTK_REL_8_2_2).
//Michael.20170705.001.E: Add.

//--------------------------------------------(SIP: NAT Traversal)
//#define SIP_OVER_TCP_SUPPORT	1
//#define STUN_SUPPORT	1  // TODO: it's better to renamed to 'ZYXEL_SIP_STUN_SUPPORT'.


//--------------------------------------------(SIP: Special & Customization Config)
#ifdef ZYPRJ_CUSTOMER_SUNRISE	// TODO: It's BETTER to be controlled by the "make menuconfig" PROFILE, NOT the Customization Compile Flag!
#define ZYXEL_SIP_AUTH_DATA_FORCE_QOP_TO_AUTH 1
#endif //ZYPRJ_CUSTOMER_SUNRISE.

#if ZYXEL_SIP_AUTH_DATA_FORCE_QOP_TO_AUTH
#define ZYXEL_SIP_AUTH_DATA_QOP_ENFORCE_TYPE "auth" //Option: "auth-int", "auth-conf", "auth". yushiuan add 2015/03/20.
#else //use "auth-int" by default
#define ZYXEL_SIP_AUTH_DATA_QOP_ENFORCE_TYPE "auth-int" //normal case , Option: "auth-int", "auth-conf", "auth". yushiuan add 2015/03/20.
#endif //ZYPRJ_CUSTOMER_SUNRISE.

#if 0 //Michael.20170926.001: Remarked to be remove to the the above section "(SIP: Register & De-Register)".
//----------
//Michael.20140522.001.B: Add to support De-Register ALL active VoIP SIP accounts first before doing reboot.
#ifndef ZYXEL_SIP_DEREGISTER_ALL_ACCT_BEFORE_SHUTDOWN_SUPPORT
#define ZYXEL_SIP_DEREGISTER_ALL_ACCT_BEFORE_SHUTDOWN_SUPPORT 1
#endif //ZYXEL_SIP_DEREGISTER_ALL_ACCT_BEFORE_SHUTDOWN_SUPPORT.
//Michael.20140522.001.E: Add.
#endif // 0.

//----------
//Michael.20141006.001.B: Add to support the successive SIP register session gap mechanism.
#ifndef ZYXEL_SIP_SUCCESSIVE_REGISTER_SESSION_TIME_GAP_SUPPORT // TODO: It's controlled by the "make menuconfig" PROFILE!
	#define ZYXEL_SIP_SUCCESSIVE_REGISTER_SESSION_TIME_GAP_SUPPORT 0
#endif //ZYXEL_SIP_SUCCESSIVE_REGISTER_SESSION_TIME_GAP_SUPPORT.

#if ZYXEL_SIP_SUCCESSIVE_REGISTER_SESSION_TIME_GAP_SUPPORT
	#ifndef DEFAULT_TIMER_SUCCESSIVE_SIP_REGISTER_SESSION_TIME_GAP
	#define DEFAULT_TIMER_SUCCESSIVE_SIP_REGISTER_SESSION_TIME_GAP 4 //second(s).
	#endif //DEFAULT_TIMER_SUCCESSIVE_SIP_REGISTER_SESSION_TIME_GAP.

	#define DEFAULT_TIMER_SUCCESSIVE_SIP_REGISTER_SESSION_TIME_GAP_MAX 5 //second(s).
#endif //ZYXEL_SIP_SUCCESSIVE_REGISTER_SESSION_TIME_GAP_SUPPORT.
//Michael.20141006.001.E: Add.

//Michael.20150303.001.B: Add to enhance the 'Michael.20141006.001' to isolate the Successive SIP REGISTER Session Gap mechanism for the SIP De-Register procedure.
#ifndef ZYXEL_SIP_SUCCESSIVE_REGISTER_SESSION_TIME_GAP_SUPPORT_FOR_DEREGISTER
	#define ZYXEL_SIP_SUCCESSIVE_REGISTER_SESSION_TIME_GAP_SUPPORT_FOR_DEREGISTER 0
#endif //ZYXEL_SIP_SUCCESSIVE_REGISTER_SESSION_TIME_GAP_SUPPORT_FOR_DEREGISTER.
//Michael.20150303.001.E: Add.

//--------------------------------------------
//#endif //VOIP_SIP


//==================================< MM/Media (DSP & Codec & RTP Hybrid feature/issue/config...)


//==================================< MM/DSP (DSP & Phone Port Driver)
//Michael.20160303.001.B: Add to De-Init DSP & Phone Port Driver at MM module start-up procedure to ensure NO Abnormally-Left Previous DSP & Phone Port Driver is running for this-time ZyIMS VoIP.
#ifndef ZYXEL_VOICE_MM_DEINIT_DSP_AND_PHONE_PORT_DRV_AT_STARTUP_SUPPORT
#define ZYXEL_VOICE_MM_DEINIT_DSP_AND_PHONE_PORT_DRV_AT_STARTUP_SUPPORT 1
#endif //ZYXEL_VOICE_MM_DEINIT_DSP_AND_PHONE_PORT_DRV_AT_STARTUP_SUPPORT.
//Michael.20160303.001.E: Add.


//==================================< MM/DSP (DSP & Phone API Architcture Re-orgainzation)
#if defined (ZYXEL_VOICE_PLATFORM_CODE) && defined (PLATFORM_MTK_EVA_CODE) && (ZYXEL_VOICE_PLATFORM_CODE==PLATFORM_MTK_EVA_CODE) //Michael.20150727.003: Add to employ the new defined Platform Code to identify the Platform Type and make the compile flag 'ZYIMS_IS_UNDER_PORTING_DEVELOP_PHASE' is only (auto) defined for one still under the Porting/Developing Phase/Stage.
#define USING_DSP_API_FROM_SINGLE_PROCESS 1 //For Control DSP From One process, Econet Must Enable This. 2015-09-01 Steve
#else
#define USING_DSP_API_FROM_SINGLE_PROCESS 0
#endif //#if defined (ZYXEL_VOICE_PLATFORM_CODE) && defined (PLATFORM_MTK_EVA_CODE) && (ZYXEL_VOICE_PLATFORM_CODE==PLATFORM_MTK_EVA_CODE).


//==================================< MM/DSP (Jitter Buffer Size, (L)EC, PLC, DRC or AGC, ..., etc.)


//Michael.20130715.001.B: Add.
//==================================< MM/Codec (including some SIP signaling related DSP features, e.g. VAD+SilenceSuppression+CNG, ptime, DTMF-relay..., etc.)
//NOTE: the 'ZYXEL_CODEC_XXXXXX_TYPE_COUNT' SHOULD sync with the (1)'~/apps/zcfg/libzcfg_be/libzcfg_be_voice/zcfg_be_voice.c/voiceCodecTable[]'
//		and (2)the definition of "typedef enum{...}CODEC_TYPE" in both (i)'~/xChange/dslx_common/voice_res_gw/codec/codec.h' & (ii)'~/ZyIMS/driver_itf/h/endpt.h'.
#define DEFAULT_CODEC_PARAM_AUDIO_SAMPLING_RATE		8000 //unit:Hz.
#define DEFAULT_CODEC_PARAM_COMMON_PREFERRED_PTIME	20 //unit:ms. //Michael.20140419.003: Add to have/implement a common preferred/default ptime for all codecs.


/**********************************************/
/********** Codec Support/Capability Info **********/
/**********************************************/
/*** G.711 ((a)G.711U, (b)G.711A) ***/
#ifndef ZYXEL_CODEC_G711_SUPPORT
#define ZYXEL_CODEC_G711_SUPPORT		1
#endif //ZYXEL_CODEC_G711_SUPPORT.


/*** G.729 ***/
#ifndef ZYXEL_CODEC_G729_SUPPORT
#define ZYXEL_CODEC_G729_SUPPORT		0
#endif //ZYXEL_CODEC_G729_SUPPORT.


/*** G.722 ***/
#ifndef ZYXEL_CODEC_G722_SUPPORT
#define ZYXEL_CODEC_G722_SUPPORT		1
#endif //ZYXEL_CODEC_G722_SUPPORT.


/*** G.723.1 (Dual rate speech coder for multimedia communications transmitting at 5.3 and 6.3 kbps) ***/
/* NOTE-1: The standard G.723 is obsolete and has been superseded by G.726. */
/* NOTE-2: Obsoleted in BRCM SDK 4.16L.05. */
#ifndef ZYXEL_CODEC_G7231_SUPPORT
#define ZYXEL_CODEC_G7231_SUPPORT	0	//Michael.20130715.001: Modify from '1' to '0' to DISABLE this codec for the Work-around Solution to compensate the Improper Codec 'Capability' & 'Priority' setting to the MM module.
#endif //ZYXEL_CODEC_G7231_SUPPORT.


/*** G.726 ((a)G.726-16 kbps, (b)G.726-24 kbps, (c)G.726-32 kbps, (d)G.726-40 kbps) ***/
#ifndef ZYXEL_CODEC_G726_SUPPORT
#define ZYXEL_CODEC_G726_SUPPORT		1
#endif //ZYXEL_CODEC_G726_SUPPORT.

//Michael.20161005.001.B: Add to support configuring diverse G.726 Codec Sub-Types (in different bit rates) individually.
#if ZYXEL_CODEC_G726_SUPPORT
	#ifndef ZYXEL_CODEC_G726_SUPPORT_G726_32_ONLY
	#define ZYXEL_CODEC_G726_SUPPORT_G726_32_ONLY 0
	#endif //ZYXEL_CODEC_G726_SUPPORT_G726_32_ONLY.

	#if ZYXEL_CODEC_G726_SUPPORT_G726_32_ONLY
		#undef ZYXEL_CODEC_G726_16_SUPPORT
		#undef ZYXEL_CODEC_G726_24_SUPPORT
		#undef ZYXEL_CODEC_G726_32_SUPPORT
		#undef ZYXEL_CODEC_G726_40_SUPPORT
		#define ZYXEL_CODEC_G726_16_SUPPORT 0
		#define ZYXEL_CODEC_G726_24_SUPPORT 0
		#define ZYXEL_CODEC_G726_32_SUPPORT 1
		#define ZYXEL_CODEC_G726_40_SUPPORT 0
	#else
		#ifndef ZYXEL_CODEC_G726_16_SUPPORT
			#define ZYXEL_CODEC_G726_16_SUPPORT 0
		#endif //ZYXEL_CODEC_G726_16_SUPPORT.

		#ifndef ZYXEL_CODEC_G726_24_SUPPORT
			#define ZYXEL_CODEC_G726_24_SUPPORT 1
		#endif //ZYXEL_CODEC_G726_24_SUPPORT.

		#ifndef ZYXEL_CODEC_G726_32_SUPPORT
			#define ZYXEL_CODEC_G726_32_SUPPORT 1
		#endif //ZYXEL_CODEC_G726_32_SUPPORT.

		#ifndef ZYXEL_CODEC_G726_40_SUPPORT
			#define ZYXEL_CODEC_G726_40_SUPPORT 0
		#endif //ZYXEL_CODEC_G726_40_SUPPORT.
	#endif //ZYXEL_CODEC_G726_SUPPORT_G726_32_ONLY.

#else //ZYXEL_CODEC_G726_SUPPORT.

	/*The following definitions are to ensure the 'ZYXEL_CODEC_G726_TYPE_COUNT' defined in the below are always available*/
	#undef ZYXEL_CODEC_G726_16_SUPPORT
	#undef ZYXEL_CODEC_G726_24_SUPPORT
	#undef ZYXEL_CODEC_G726_32_SUPPORT
	#undef ZYXEL_CODEC_G726_40_SUPPORT
	#define ZYXEL_CODEC_G726_16_SUPPORT 0
	#define ZYXEL_CODEC_G726_24_SUPPORT 0
	#define ZYXEL_CODEC_G726_32_SUPPORT 0
	#define ZYXEL_CODEC_G726_40_SUPPORT 0
#endif //ZYXEL_CODEC_G726_SUPPORT.
//Michael.20161005.001.E: Add.


/*** G.728 ***/
#ifndef ZYXEL_CODEC_G728_SUPPORT
#define ZYXEL_CODEC_G728_SUPPORT		0	//Michael.20130715.001: Modify from '1' to '0' to DISABLE this codec for the Work-around Solution to compensate the Improper Codec 'Capability' & 'Priority' setting to the MM module.
#endif //ZYXEL_CODEC_G728_SUPPORT.


/*** iLBC (Internet Low Bit-rate speech Codec: (a)20ms frame/15.2 kbps, (b)30ms frame/13.3 kbps) ***/
/* NOTE: Obsoleted in BRCM SDK 4.16L.05. */
#ifndef ZYXEL_CODEC_ILBC_SUPPORT
#define ZYXEL_CODEC_ILBC_SUPPORT		0
#endif //ZYXEL_CODEC_ILBC_SUPPORT.


/*** BV16 (BRCM BroadVoice - 16 kbps (Narrowband)) ***/
/* NOTE: Obsoleted in BRCM SDK 4.16L.05. */
#ifndef ZYXEL_CODEC_BV16_SUPPORT
#define ZYXEL_CODEC_BV16_SUPPORT		0
#endif //ZYXEL_CODEC_BV16_SUPPORT.


/*** BV32 (BRCM BroadVoice - 32 kbps (Wideband)) ***/
/* NOTE: Obsoleted in BRCM SDK 4.16L.05. */
#ifndef ZYXEL_CODEC_BV32_SUPPORT
#define ZYXEL_CODEC_BV32_SUPPORT		0
#endif //ZYXEL_CODEC_BV32_SUPPORT.


/*** LPCM-NB (Linear PCM - Narrowband @ 128 Kbps) ***/
#ifndef ZYXEL_CODEC_LPCM_NB_SUPPORT
#define ZYXEL_CODEC_LPCM_NB_SUPPORT	0
#endif //ZYXEL_CODEC_LPCM_NB_SUPPORT.


/*** LPCM-WB (Linear PCM - Wideband @ 256 Kbps) ***/
#ifndef ZYXEL_CODEC_LPCM_WB_SUPPORT
#define ZYXEL_CODEC_LPCM_WB_SUPPORT	0
#endif //ZYXEL_CODEC_LPCM_WB_SUPPORT.


/*** GSM-AMR ***/
#ifndef ZYXEL_CODEC_GSMAMR_SUPPORT
#define ZYXEL_CODEC_GSMAMR_SUPPORT	0
#endif //ZYXEL_CODEC_GSMAMR_SUPPORT.


/*** AMR-WB ***/
#ifndef ZYXEL_CODEC_AMRWB_SUPPORT
#define ZYXEL_CODEC_AMRWB_SUPPORT	0
#endif //ZYXEL_CODEC_AMRWB_SUPPORT.


/*** T.38 FAX Relay ***/
#ifndef ZYXEL_CODEC_FAX_SUPPORT
#define ZYXEL_CODEC_FAX_SUPPORT		1
#endif //ZYXEL_CODEC_FAX_SUPPORT.

#if ZYXEL_CODEC_FAX_SUPPORT
//*** The following definitions are refering to the structure: icf_types.h/icf_config_t38_attrib_param_st ***
#define DEFAULT_CODEC_PARAM_T38_VERSION					0		/* [0]ICF_T38_1998, [1]ICF_T38_2000, [2]ICF_T38_2002*/
#define DEFAULT_CODEC_PARAM_T38_BITRATE					14400	/* [NNN]ICF_T38_[NNN]_BIT_PER_SEC, where NNN=2400, 4800, 7200, 9600, 14400, 33600 */
#define DEFAULT_CODEC_PARAM_T38_RATE_MANAGEMENT		1		/* [0]ICF_T38_RATE_MANAGEMENT_LOCAL, [1]ICF_T38_RATE_MANAGEMENT_TRANSFERRED */
#define DEFAULT_CODEC_PARAM_T38_UDP_BUFFSIZE_MAX		1800
#define DEFAULT_CODEC_PARAM_T38_UDP_PACKETSIZE_MAX	130
#define DEFAULT_CODEC_PARAM_T38_ERR_CORRECTION			0x01	/* [0x01]ICF_T38_ERROR_CORR_REDUNDANCY, [0x02]ICF_T38_ERROR_CORR_FEC */
#endif //ZYXEL_CODEC_FAX_SUPPORT.


/*** Telephone-Event (NTE: Named Telephone Event) / RFC-2833 (obsoleted) + RFC-4733 & RFC-4734 (update 4733) ***/
#ifndef ZYXEL_CODEC_NTE_SUPPORT //Named Telephone-Event
#define ZYXEL_CODEC_NTE_SUPPORT		1
#endif //ZYXEL_CODEC_NTE_SUPPORT.
//Michael.20130715.001.E: Add.



/********** Each Type Codec Count **********/
#define ZYXEL_CODEC_G711_TYPE_COUNT		2
#define ZYXEL_CODEC_G729_TYPE_COUNT		1
#define ZYXEL_CODEC_G722_TYPE_COUNT		1
#define ZYXEL_CODEC_G7231_TYPE_COUNT		1
//Michael.20161005.001.B: Modify to support configuring diverse G.726 Codec Sub-Types (in different bit rates) individually.
//#define ZYXEL_CODEC_G726_TYPE_COUNT		2
#define ZYXEL_CODEC_G726_TYPE_COUNT		(ZYXEL_CODEC_G726_16_SUPPORT + ZYXEL_CODEC_G726_24_SUPPORT + ZYXEL_CODEC_G726_32_SUPPORT + ZYXEL_CODEC_G726_40_SUPPORT)
//Michael.20161005.001.E: Modify.
#define ZYXEL_CODEC_G728_TYPE_COUNT		1
#define ZYXEL_CODEC_ILBC_TYPE_COUNT		1
#define ZYXEL_CODEC_BV16_TYPE_COUNT		1
#define ZYXEL_CODEC_BV32_TYPE_COUNT		1
#define ZYXEL_CODEC_LPCM_NB_TYPE_COUNT	1
#define ZYXEL_CODEC_LPCM_WB_TYPE_COUNT	1
#define ZYXEL_CODEC_GSMAMR_TYPE_COUNT	8
#define ZYXEL_CODEC_AMRWB_TYPE_COUNT	9
#define ZYXEL_CODEC_FAX_TYPE_COUNT		1
#define ZYXEL_CODEC_NTE_TYPE_COUNT		1


/********** Codec (Usage) Priority **********/
//Michael.20130726.001.B: Add to define the Codec Default Priority.
//The following codec list is also refering & sync to the codec definition by "typedef enum{...}CODEC_TYPE" in both (i)'~/xChange/dslx_common/voice_res_gw/codec/codec.h' & (ii)'~/ZyIMS/driver_itf/h/endpt.h'.
#define ZYXEL_CODEC_PRIORITY_NONE		100
#if ZYXEL_CODEC_G711_SUPPORT
#define ZYXEL_CODEC_PRIORITY_PCMU		1
#define ZYXEL_CODEC_PRIORITY_PCMA		2
#endif //ZYXEL_CODEC_G711_SUPPORT.
#if ZYXEL_CODEC_G729_SUPPORT
#define ZYXEL_CODEC_PRIORITY_G729		ZYXEL_CODEC_PRIORITY_NONE
#define ZYXEL_CODEC_PRIORITY_G729E	ZYXEL_CODEC_PRIORITY_NONE
#endif //ZYXEL_CODEC_G729_SUPPORT.
#if ZYXEL_CODEC_G722_SUPPORT
#define ZYXEL_CODEC_PRIORITY_G722MODE1		5
#endif //ZYXEL_CODEC_G722_SUPPORT.
#if ZYXEL_CODEC_G7231_SUPPORT
#define ZYXEL_CODEC_PRIORITY_G7231_53			ZYXEL_CODEC_PRIORITY_NONE
#define ZYXEL_CODEC_PRIORITY_G7231_63			6
#define ZYXEL_CODEC_PRIORITY_G7231A_53		ZYXEL_CODEC_PRIORITY_NONE
#define ZYXEL_CODEC_PRIORITY_G7231A_63		ZYXEL_CODEC_PRIORITY_NONE
#define ZYXEL_CODEC_PRIORITY_G7231_53_VAR	ZYXEL_CODEC_PRIORITY_NONE
#define ZYXEL_CODEC_PRIORITY_G7231_63_VAR	ZYXEL_CODEC_PRIORITY_NONE
#endif //ZYXEL_CODEC_G7231_SUPPORT.
#if ZYXEL_CODEC_G726_SUPPORT
#define ZYXEL_CODEC_PRIORITY_G726_16	ZYXEL_CODEC_PRIORITY_NONE
#define ZYXEL_CODEC_PRIORITY_G726_24	3
#define ZYXEL_CODEC_PRIORITY_G726_32	4
#define ZYXEL_CODEC_PRIORITY_G726_40	ZYXEL_CODEC_PRIORITY_NONE
#endif //ZYXEL_CODEC_G726_SUPPORT.
#if ZYXEL_CODEC_G728_SUPPORT
#define ZYXEL_CODEC_PRIORITY_G728		7
#endif //ZYXEL_CODEC_G728_SUPPORT.
#if ZYXEL_CODEC_ILBC_SUPPORT
#define ZYXEL_CODEC_PRIORITY_ILBC_20	ZYXEL_CODEC_PRIORITY_NONE
#define ZYXEL_CODEC_PRIORITY_ILBC_30	12
#endif //ZYXEL_CODEC_ILBC_SUPPORT.
#if ZYXEL_CODEC_BV16_SUPPORT
#define ZYXEL_CODEC_PRIORITY_BV16		8
#endif //ZYXEL_CODEC_BV16_SUPPORT.
#if ZYXEL_CODEC_BV32_SUPPORT
#define ZYXEL_CODEC_PRIORITY_BV32		9
#endif //ZYXEL_CODEC_BV32_SUPPORT.
#if ZYXEL_CODEC_LPCM_NB_SUPPORT
#define ZYXEL_CODEC_PRIORITY_LINPCM128	ZYXEL_CODEC_PRIORITY_NONE
#endif //ZYXEL_CODEC_LPCM_NB_SUPPORT.
#if ZYXEL_CODEC_LPCM_WB_SUPPORT
#define ZYXEL_CODEC_PRIORITY_LINPCM256	10
#endif //ZYXEL_CODEC_LPCM_WB_SUPPORT.
#if ZYXEL_CODEC_GSMAMR_SUPPORT
#define ZYXEL_CODEC_PRIORITY_GSMAMR_12K	ZYXEL_CODEC_PRIORITY_NONE
#define ZYXEL_CODEC_PRIORITY_GSMAMR_10K	ZYXEL_CODEC_PRIORITY_NONE
#define ZYXEL_CODEC_PRIORITY_GSMAMR_795	ZYXEL_CODEC_PRIORITY_NONE
#define ZYXEL_CODEC_PRIORITY_GSMAMR_740	ZYXEL_CODEC_PRIORITY_NONE
#define ZYXEL_CODEC_PRIORITY_GSMAMR_670	ZYXEL_CODEC_PRIORITY_NONE
#define ZYXEL_CODEC_PRIORITY_GSMAMR_590	ZYXEL_CODEC_PRIORITY_NONE
#define ZYXEL_CODEC_PRIORITY_GSMAMR_515	ZYXEL_CODEC_PRIORITY_NONE
#define ZYXEL_CODEC_PRIORITY_GSMAMR_475	ZYXEL_CODEC_PRIORITY_NONE
#endif //ZYXEL_CODEC_GSMAMR_SUPPORT.
#if ZYXEL_CODEC_AMRWB_SUPPORT
#define ZYXEL_CODEC_PRIORITY_AMRWB_66	ZYXEL_CODEC_PRIORITY_NONE
#define ZYXEL_CODEC_PRIORITY_AMRWB_885	ZYXEL_CODEC_PRIORITY_NONE
#define ZYXEL_CODEC_PRIORITY_AMRWB_1265	ZYXEL_CODEC_PRIORITY_NONE
#define ZYXEL_CODEC_PRIORITY_AMRWB_1425	ZYXEL_CODEC_PRIORITY_NONE
#define ZYXEL_CODEC_PRIORITY_AMRWB_1585	ZYXEL_CODEC_PRIORITY_NONE
#define ZYXEL_CODEC_PRIORITY_AMRWB_1825	ZYXEL_CODEC_PRIORITY_NONE
#define ZYXEL_CODEC_PRIORITY_AMRWB_1985	ZYXEL_CODEC_PRIORITY_NONE
#define ZYXEL_CODEC_PRIORITY_AMRWB_2305	ZYXEL_CODEC_PRIORITY_NONE
#define ZYXEL_CODEC_PRIORITY_AMRWB_2385	ZYXEL_CODEC_PRIORITY_NONE
#endif //ZYXEL_CODEC_AMRWB_SUPPORT.
//Michael.20130726.001.E: Add to define the Codec Default Priority.

//--------------------------------------------(MM/Codec: Codec Selection feature/rule/policy)
#define CODEC_THIRD_SELECTION	1

//--------------------------------------------(MM/Codec: Codec usage related feature/issue - DTMF-relay mode relaated, ...)
#define ZYXEL_CODEC_TELEPHONE_EVENT_PT_NUM_MUST_IN_DYNAMIC_CODEC_NUM_RANGE 1 //Michael.20151111.002: Add to improve the DTMF mode operation logic or debug message.

//Michael.20151111.001.B: Add to make the DTMF digit tone also able to be carried and transported 'InBand' through the RTP stream while using G.729 codec.
#ifndef ZYXEL_DSP_FORCE_TO_USE_RFC2833_DTMF_MODE_FOR_DRIVER_LIMITED_OR_HIGH_INFO_LOSSY_COMPRESSION_CODEC
	#define ZYXEL_DSP_FORCE_TO_USE_RFC2833_DTMF_MODE_FOR_DRIVER_LIMITED_OR_HIGH_INFO_LOSSY_COMPRESSION_CODEC 0
#endif //ZYXEL_DSP_FORCE_TO_USE_RFC2833_DTMF_MODE_FOR_DRIVER_LIMITED_OR_HIGH_INFO_LOSSY_COMPRESSION_CODEC.
//Michael.20151111.001.E: Add.
//--------------------------------------------


//==================================< MM/RTP
//**************************************************************************
//* NOTE: there are some DEFAULT Value definitions for MM in 'mm_core_fsm_defs.h'!!
//**************************************************************************
//#define RTP			1
#define ZYXEL_VOICE_RTP_PORT_RANGE 20 //Michael.20160308.001: Add to have a common definition of the RTP Port Usage Range for the ZyIMS VoIP.
//--------------------------------------------
#if ZYXEL_VOICE_KSOCKET_RTP
	#define KSOCKET_RTP_SUPPORT	1
#else
	#define KSOCKET_RTP_SUPPORT	0
#endif //ZYXEL_VOICE_KSOCKET_RTP.
//#define KSOCKET_RTP_ENABLE 1
//--------------------------------------------
//Amber.20170908: Add for the handling policy of the content item 'CNANE' of the RTCP message type 'SDES' (by the 'mm_core_rtcp.c/rtcpModifySdes()').
#define RTCP_SDES_ITEM_CNAME_USE_THE_TEXT_FROM_CFG_DATA_SUPPORT 1
#define RTCP_SDES_ITEM_CNAME_USE_THE_TEXT_FROM_CFG_DATA_BUT_REJECT_NULL_STR 1
//--------------------------------------------
#if ZYXEL_VOICE_SUPPORT_SRTP
	#define SRTP_SUPPORT	1
#else
	#define SRTP_SUPPORT	0
#endif //ZYXEL_VOICE_SUPPORT_SRTP.
//--------------------------------------------
#if SUPPORT_412_VOICE //Broadcom Platform Only!! -- to indicate if support Broadcom Software Package Release R412.
	#define SUPPORT_412		1
#else
	#define SUPPORT_412		0
#endif //SUPPORT_412_VOICE.
//--------------------------------------------
//Michael.20150204.001.B: Add to support the RTP Stats Info Periodical Dump during the DSP Channel Open Phase for the debugging purpose.
#ifndef ZYXEL_VOICE_RTP_STATS_PERIODIC_DUMP_DURING_DSP_CHAN_OPEN_SUPPORT
	#define ZYXEL_VOICE_RTP_STATS_PERIODIC_DUMP_DURING_DSP_CHAN_OPEN_SUPPORT 0
#endif //ZYXEL_VOICE_RTP_STATS_PERIODIC_DUMP_DURING_DSP_CHAN_OPEN_SUPPORT.

#if ZYXEL_VOICE_RTP_STATS_PERIODIC_DUMP_DURING_DSP_CHAN_OPEN_SUPPORT
	#define DEFAULT_TIMER_DURATION_RTP_STATS_PERIODIC_DUMP_INTERVAL 5 //second(s).
#endif //ZYXEL_VOICE_RTP_STATS_PERIODIC_DUMP_DURING_DSP_CHAN_OPEN_SUPPORT.
//Michael.20150204.001.E: Add.


//==================================< IPTK
#if 0 //Michael.20170705.001.B: Remarked to be removed to the above.
//#ifdef IPTK_REL_8_0
#if defined(IPTK_REL_8_0) || defined(IPTK_REL_8_2_2)
//Michael.20160216.002.B: Modify to also include & open these two IPTK Old-version-related Compile Flags (IPTK_REL_7_1 & IPTK_REL_8_0) to include the related source code for the ZyIMS running with IPTK v8.2.2.
//#define HEARTBEAT_MECHANISM_ENABLE	1	/* 1:on , 0:off */
#define HEARTBEAT_MECHANISM_ENABLE	0	/* 1:on , 0:off */
//Michael.20160216.002.E: Modify.
//#endif //IPTK_REL_8_0.
#endif //Michael.20170705.001.E: Remarked.
#endif //defined(IPTK_REL_8_0) || defined(IPTK_REL_8_2_2).
//--------------------------------------------


//==================================< SIP & MM/RTP Common or Generic
//--------------------------------------------(SIP & MM/RTP: iptables CHAIN (name) definition for the iptables-related features: (a)Firewall, (b)MultiWAN Interface Binding, (c), )
#define IPTABLES_RULE_CHAIN_VOIP_INPUT			"VOIP_INPUT"
#define IPTABLES_RULE_CHAIN_VOIP_PREROUTING		"VOIP_PREROUTING"
#define IPTABLES_RULE_CHAIN_VOIP_PORTPROTECT	"VOIP_PORTPROTECT"
#define IPTABLES_RULE_CHAIN_VOIP_PORTRESERVE		"VOIP_PORTRESERVE"
#define IPTABLES_RULE_CHAIN_VOIP_IP_ROUTE2		"IP_ROUTE2_VOIP"
#define IPTABLES_RULE_CHAIN_VOIP_QOS				"QOS_VOIP" //Michael.20160303.002: Add to support the OPAL-trunk Basic & Generic Default VoIP QoS mechanism.

//--------------------------------------------(SIP & MM/RTP: Firewall)
//Michael.20160309.001.B: Add for the Minor Bugfix: add the DEPENDENCY that if/once 'BUILD_IGNORE_DIRECT_IP' is enabled, the 'ZYXEL_VOIP_FIREWALL_RULE_SUPPORT' MUST be Enabled/Supported accordingly. This is because the function(s) of 'BUILD_IGNORE_DIRECT_IP' are all enclosed by the compile flag 'ZYXEL_VOIP_FIREWALL_RULE_SUPPORT'.
#if BUILD_IGNORE_DIRECT_IP //Depend
	//NOTE/DEPENDENCY: 'ZYXEL_VOIP_FIREWALL_RULE_SUPPORT' is designed to be a stand-alone System-level feature. However, if/once 'BUILD_IGNORE_DIRECT_IP' is enabled, then it MUST be Enabled/Supported accordingly...This is because the function(s) of 'BUILD_IGNORE_DIRECT_IP' are all enclosed by the compile flag 'ZYXEL_VOIP_FIREWALL_RULE_SUPPORT'.
	#if !(ZYXEL_VOIP_FIREWALL_RULE_SUPPORT)
	#undef ZYXEL_VOIP_FIREWALL_RULE_SUPPORT
	#define ZYXEL_VOIP_FIREWALL_RULE_SUPPORT	1
	#endif //!(ZYXEL_VOIP_FIREWALL_RULE_SUPPORT).
#endif //BUILD_IGNORE_DIRECT_IP.
//Michael.20160309.001.E: Add

#ifndef ZYXEL_VOIP_FIREWALL_RULE_SUPPORT
	//NOTE/DEPENDENCY: 'ZYXEL_VOIP_FIREWALL_RULE_SUPPORT' is designed to be a stand-alone System-level feature. However, if/once 'BUILD_IGNORE_DIRECT_IP' is enabled, then it MUST be Enabled/Supported accordingly...This is because the function(s) of 'BUILD_IGNORE_DIRECT_IP' are all enclosed by the compile flag 'ZYXEL_VOIP_FIREWALL_RULE_SUPPORT'.
	#define ZYXEL_VOIP_FIREWALL_RULE_SUPPORT	1
#endif //ZYXEL_VOIP_FIREWALL_RULE_SUPPORT.

#if ZYXEL_VOIP_FIREWALL_RULE_SUPPORT
	//#define ZYXEL_VOIP_HANDLE_FIREWALL_RULE_BASE_NATIVELY	1
	//----------------------------------------
	//#define BUILD_IGNORE_DIRECT_IP		0	//Block Non-Proxy P2P (Direct) Call //NOW, it's directly & totally controlled by the Makefile!
	//----------------------------------------
	#if 0 //Michael.20160314.001: Add to remove the DEPENDENCY between the two compile flags - 'ZYXEL_VOIP_FIREWALL_RULE_SUPPORT' and 'ZYXEL_VOIP_WAN_PORT_RESERVE_SUPPORT'.
	//NOTE/DEPENDENCY: 'ZYXEL_VOIP_WAN_PORT_RESERVE_SUPPORT' is designed to be a stand-alone SIP-ALG-related feature. However, if/once 'ZYXEL_VOIP_FIREWALL_RULE_SUPPORT' is enabled, then it MUST be Enabled/Supported accordingly.
	#if !(ZYXEL_VOIP_WAN_PORT_RESERVE_SUPPORT)
	#undef ZYXEL_VOIP_WAN_PORT_RESERVE_SUPPORT
	#define ZYXEL_VOIP_WAN_PORT_RESERVE_SUPPORT	1	//to Against SIP-ALG.
	#endif //!(ZYXEL_VOIP_WAN_PORT_RESERVE_SUPPORT).
	#endif // 0.
#endif //ZYXEL_VOIP_FIREWALL_RULE_SUPPORT.

//--------------------------------------------(SIP & MM/RTP: Port Reserve)
#ifndef ZYXEL_VOIP_WAN_PORT_RESERVE_SUPPORT
	#define ZYXEL_VOIP_WAN_PORT_RESERVE_SUPPORT	1	//to Against SIP-ALG.
#endif //ZYXEL_VOIP_WAN_PORT_RESERVE_SUPPORT.

#if ZYXEL_VOIP_WAN_PORT_RESERVE_SUPPORT
	//#define ZYXEL_VOIP_HANDLE_WAN_PORT_RESERVE_RULE_BASE_NATIVELY	1 //Michael.20160310.004: Add to support to init the Rule Base Chain for the VoIP (WAN) Port Reserve function.
	//----------------------------------------
	#define RTP_PORT_RESERVE_RANGE ZYXEL_VOICE_RTP_PORT_RANGE //Michael.20160308.001: Modify from '20' to 'ZYXEL_VOICE_RTP_PORT_RANGE'.
	#define PORT_RESERVE_MASQUERADE_UDP_PORT_MIN 60000
	#define PORT_RESERVE_MASQUERADE_UDP_PORT_MAX 60100
#endif //ZYXEL_VOIP_WAN_PORT_RESERVE_SUPPORT.

//--------------------------------------------(SIP & MM/RTP: QoS Marking: (a)TOS or DSCP, (b)Netfilter Packet Mark)
//Michael.20160303.002.B: Add to support the OPAL-trunk Basic & Generic Default VoIP QoS mechanism.
#ifndef ZYXEL_VOIP_OPAL_BASIC_DEFAULT_VOIP_QOS_SUPPORT
	#define ZYXEL_VOIP_OPAL_BASIC_DEFAULT_VOIP_QOS_SUPPORT 0 //Disabled Temporarily now, and wait for the "OPAL-trunk Basic & Generic Default VoIP QoS mechanism" is well implemented (then) to Enabled by default again.
#endif //ZYXEL_VOIP_OPAL_BASIC_DEFAULT_VOIP_QOS_SUPPORT.

#if ZYXEL_VOIP_OPAL_BASIC_DEFAULT_VOIP_QOS_SUPPORT
	//#define ZYXEL_VOIP_HANDLE_OPAL_BASIC_DEFAULT_VOIP_QOS_RULE_BASE_NATIVELY	1
	//----------------------------------------
	#define ZYXEL_OPAL_BASIC_DEFAULT_VOIP_QOS_PKT_MARK_VALUE_FOR_HIGHEST_PRIORITY 0x7
	#define ZYXEL_VOIP_QOS_MARK_VALUE ZYXEL_OPAL_BASIC_DEFAULT_VOIP_QOS_PKT_MARK_VALUE_FOR_HIGHEST_PRIORITY
#endif //ZYXEL_VOIP_OPAL_BASIC_DEFAULT_VOIP_QOS_SUPPORT.

#ifndef ZYXEL_VOIP_QOS_MARK_VALUE
	#define ZYXEL_VOIP_QOS_MARK_VALUE 0
#endif //ZYXEL_VOIP_QOS_MARK_VALUE.
//Michael.20160303.002.E: Add.


//--------------------------------------------(SIP & MM/RTP: MultiWAN Interface Binding: Voice (SIP) Profile-based Static/Fixed Route)
//#define VOIP_ROUTE_SELECT			1
//--------------------------------------------
#ifndef ZYXEL_VOIP_INTF_BINDING_SUPPORT
	#define ZYXEL_VOIP_INTF_BINDING_SUPPORT	1
#endif //ZYXEL_VOIP_INTF_BINDING_SUPPORT.

#if ZYXEL_VOIP_INTF_BINDING_SUPPORT
	//#define ZYXEL_VOIP_HANDLE_INTF_BINDING_RULE_BASE_NATIVELY	1
	//----------------------------------------
	//Michael.20140522.004.B: Add to force the ICMP packet generated locally and targeted to the SIP server to be bounded on the corresponding Voice Profile Active Bound Interface.
	#ifdef ZYPRJ_CUSTOMER_SUNRISE	// TODO: It's BETTER to be controlled by the "make menuconfig" PROFILE, NOT the Customization Compile Flag!
	#define ZYXEL_VOIP_FORCE_LOCAL_ICMP_TO_SIP_SERVER_TOBE_INTF_BOUNDED 1
	#endif //ZYPRJ_CUSTOMER_SUNRISE
	//Michael.20140522.004.E: Add.
#endif //ZYXEL_VOIP_INTF_BINDING_SUPPORT.
//--------------------------------------------

//--------------------------------------------(SIP & MM/RTP: Stand-alone VLAN Tagging)
//#define VLAN_TAG_VOIP		1
//--------------------------------------------


//==================================< Phone Control.
#define phStartCIDRing	phStartRing2	//Michael.20140103.002: Add to extend 'Michael.20130626.003'.
#define slicStartCIDRing	slicStartRing2	//Michael.20140103.002: Add to extend 'Michael.20130626.003'.
#define PhoneStartCIDRing	PhoneStartRing2 //Michael.20130626.003: Add to have a alias name 'PhoneStartCIDRing()' for 'Endpoint_itf.c/PhoneStartRing2()'.

//==================================< Phone Event Handler Control
/*For Econet to solve RFC2833 not generate when mm not handle phone event 2015-08-27 Steve.     *
  *This will receive DSP phone event in MM and send to voiceApp by IPC                                         */
#define ZYXEL_PHONE_EVENT_HANDLE_IN_MM_AND_SEND_TO_VOICEAPP 1

#define PHONE_EVENT_CHANNEL_PATH "/var/phone_event.channel"  //Phone event IPC file


//==================================< Tone (for Phone/Call/Customization Feature usage).
//NOTE: Ref & MUST SYNC to 'tr104_object.h/TONE_EVENT_DIAL(2), _SPECIALDIAL(13), _STUTTERDIAL(7), _SPECIALINFO(14), _REORDER(6), _CONGESTION(16), _BUSY(0)'.
//      where the Tone Event Enum definitions from 0~20 are defined in the TR-104 data model for the object: .VoiceService.{i}.VoiceProfile.{i}.Tone.Event.{i}.Function.
#define ZYXEL_VOIP_FEATURE_TONE_BUSY					0
#define ZYXEL_VOIP_FEATURE_TONE_CONFIRMATION		1
#define ZYXEL_VOIP_FEATURE_TONE_DIAL					2
#define ZYXEL_VOIP_FEATURE_TONE_MESSAGEWAITING		3
#define ZYXEL_VOIP_FEATURE_TONE_OFFHOOKWARNING	4
#define ZYXEL_VOIP_FEATURE_TONE_RINGBACK				5
#define ZYXEL_VOIP_FEATURE_TONE_REORDER				6
#define ZYXEL_VOIP_FEATURE_TONE_STUTTERDIAL			7
#define ZYXEL_VOIP_FEATURE_TONE_CALLWT				21 //Michael.20150909.001: Add to support the CLI (framework): Tone, Ring, LED and VMWI signal control.
#define ZYXEL_VOIP_FEATURE_TONE_ALERTINGSIGNAL		12
#define ZYXEL_VOIP_FEATURE_TONE_SPECIALDIAL			13
#define ZYXEL_VOIP_FEATURE_TONE_SPECIALINFO			14
#define ZYXEL_VOIP_FEATURE_TONE_RELEASE				15
#define ZYXEL_VOIP_FEATURE_TONE_CONGESTION			16

//==================================< Ring (for Phone/Call/Customization Feature usage).
#define ZYIMS_CLI_TYPE_DO_ACTION_PHONE_RING_CTRL_RING_ID_SUPPORT 1


//==================================< Phone Feature: (a)Country/Region-code related, (b)MWI & VMWI & Caller-ID(CID|CLID) / CLIP, (c)Dialing related.

/*define region default support value in main region table. This will cause all region be supported in main region table when .config not define ZYXEL_REGION_SUPPORT_DEFAULT.*
 *If don't want to enable all region. Should use "-DZYXEL_REGION_SUPPORT_DEFAULT=0" and "-DZYXEL_REGION_SUPPORT_XX=1" to add each region support in compile time.    *
 *Ex: "-DZYXEL_REGION_SUPPORT_US=1" means enable USA support. 2015-9-15 Steve                                                                                                                       */
#ifndef ZYXEL_REGION_SUPPORT_DEFAULT
	#define ZYXEL_REGION_SUPPORT_DEFAULT 1
#endif //ZYXEL_REGION_SUPPORT_DEFAULT.

//#define SUPPORT_COUNTRY_CODE	1
//Michael.20141121.002.B: Modify to do enhancements (some ones are the preparation for the future) along with the BRCM SDK 416L02A support task.
//#define ZYXEL_DEFAULT_COUNTRY_REGION "US" //Country Region: NORTHAMERICA(US) <==> Country Code: 17.
//#define ZYXEL_DEFAULT_COUNTRY_CODE 17 //Country Region: NORTHAMERICA(US) <==> Country Code: 17.
#define ZYXEL_DEFAULT_COUNTRY_CODE_ISO3166_1_ALPHA2 "US"
#define ZYXEL_DEFAULT_COUNTRY_CODE_ISO3166_1_ALPHA3 "USA"
#define ZYXEL_DEFAULT_COUNTRY_CODE ZYXEL_DEFAULT_COUNTRY_CODE_ISO3166_1_ALPHA2
#define ZYXEL_DEFAULT_COUNTRY_ID 17 //Country Region: NORTHAMERICA(US) <==> Country Code: 17.
	/* In the BRCM platform, the Country Id enumerated (macro) number is defined in the '$(BRCM xChange)/dslx_common/voice_res_gw/inc/vrgCountry.h' in the format "VRG_COUNTRY_$(CountryName)" by
	  * (i)#define COUNTRY_ARCHIVE_MAKE_NAME(country) VRG_COUNTRY_##country + (ii)including '$(BRCM xChange)/dslx_common/voice_res_gw/inc/countryArchive.h'.
	  * However, the Country Id enumerated (macro) number is NOT a fixed number and will vary/change based-on the Country Support definition in the '$(BRCM xChange)/dslx_common/voice_res_gw/inc/vrgCountryCfg.h' (or vrgCountryCfgCustom.h).
	  * For the dynamic locale provisioning, there is a table ('$(BRCM VODSL)/telephonyProfiles/tpProfilesMaps.c/countryMap[]') to map the (i)Country Id enumerated (macro) number and the (ii)ISO 3166-1 Alpha-3 three-letter Country Codes.
	  */
//Michael.20141121.002.E: Modify.

//Michael.20141121.002.B: Add to do enhancements (some ones are the preparation for the future) along with the BRCM SDK 416L02A support task.
#ifndef BRCM_VOIP_PHONE_DYNAMIC_LOCALE_PROVISIONING_SUPPORT // TODO: It's BETTER to be controlled by the "make menuconfig" PROFILE, or according to the BRCM SDK Version Info defined in the "make menuconfig" PROFILE.
	#define BRCM_VOIP_PHONE_DYNAMIC_LOCALE_PROVISIONING_SUPPORT 1 //NOTE: After the BRCM SDK v.416L02 (included), the Dynamic Locale Provisioning MUST be employed to successfully init the BRCM DSP & Phone Port driver!
#endif //BRCM_VOIP_PHONE_DYNAMIC_LOCALE_PROVISIONING_SUPPORT.
//Michael.20141121.002.E: Add.

//Michael.20141210.001.B: Add to do enhancements (some ones are the preparation for the future) along with the BRCM SDK 416L02A support task.
#if BRCM_VOIP_PHONE_DYNAMIC_LOCALE_PROVISIONING_SUPPORT
#ifndef BRCM_VOIP_PHONE_DYNAMIC_LOCALE_PROVISIONING_PROFILE_DIR
	#define BRCM_VOIP_PHONE_DYNAMIC_LOCALE_PROVISIONING_PROFILE_DIR "/etc/telephonyProfiles.d"
#endif //BRCM_VOIP_PHONE_DYNAMIC_LOCALE_PROVISIONING_PROFILE_DIR.
#endif //BRCM_VOIP_PHONE_DYNAMIC_LOCALE_PROVISIONING_SUPPORT.
//Michael.20141210.001.E: Add.

//--------------------------------------------
//#define HOWLER_TONE			1	//OffHook Warning-Tone.
//#define HOWLER_TONE_SUPPORT	1	//OffHook Warning-Tone.
#if (HOWLER_TONE) || (HOWLER_TONE_SUPPORT)
	#define HOWLER_TONE_STEP_LEVEL_SUPPORT	0
#endif //(HOWLER_TONE) || (HOWLER_TONE_SUPPORT).
//--------------------------------------------
#ifndef ZYXEL_VOIP_MWI_SUPPORT // TODO: It's BETTER to be controlled by the "make menuconfig" PROFILE, or according to the BRCM SDK Version Info defined in the "make menuconfig" PROFILE.
	#define ZYXEL_VOIP_MWI_SUPPORT	1 // TODO: SHOULD use this as a (conditional) compile flag to isolate these codes to realize the MWI feature!
#endif //ZYXEL_VOIP_MWI_SUPPORT.
#if ZYXEL_VOIP_MWI_SUPPORT
	#define ZYXEL_MWI_BY_NEW_MSG_COUNT_AND_STATUS		0 //Default
	#define ZYXEL_MWI_BY_NEW_MSG_COUNT_OR_STATUS		1
	#define ZYXEL_MWI_BY_NEW_MSG_COUNT_ONLY			2
	#define ZYXEL_MWI_BY_NEW_MSG_STATUS_ONLY			3
	/*MWI Parsing Method Customization*/
	#if ZYPRJ_CUSTOMER_SOLARUS //US Solarus.
		#define ZYXEL_MWI_NEW_MSG_LOGIC ZYXEL_MWI_BY_NEW_MSG_STATUS_ONLY
	#elif ZYPRJ_CUSTOMER_WIND //WIND Italy. //Michael.20170321.001: Add to support parsing the MWI info in the SIP NOTIFY issued by WIND Italy's SIP server (Alcatel-Lucent-HPSS v3.0.3).
		#define ZYXEL_MWI_NEW_MSG_LOGIC ZYXEL_MWI_BY_NEW_MSG_STATUS_ONLY
	#else
		//Michael.20170721.001.B: Modify to change the 'Default' MWI Status Decision Logic from a rigorous rule 'ZYXEL_MWI_BY_NEW_MSG_COUNT_AND_STATUS' to a (more) relaxed one 'ZYXEL_MWI_BY_NEW_MSG_COUNT_OR_STATUS' to support more/most VoIP platforms by default.
		//#define ZYXEL_MWI_NEW_MSG_LOGIC ZYXEL_MWI_BY_NEW_MSG_COUNT_AND_STATUS  //Default Method.
		#define ZYXEL_MWI_NEW_MSG_LOGIC ZYXEL_MWI_BY_NEW_MSG_COUNT_OR_STATUS  //Default Method.
		//Michael.20170721.001.E: Modify.
	#endif //#if ZYPRJ_CUSTOMER_SOLARUS

	#define ZYXEL_VISUAL_MWI_SUPPORT	1 //Visual MWI (VMWI).

	//Michael.20170914.001.B: Add to Support the Out-of-Dialog (OOD) NOTIFY for MWI withOut sending SUBSCRIBE first.
	//#if ZYPRJ_CUSTOMER_TISCALI
	//	#define ZYXEL_VOIP_MWI_OOD_NOTIFY_WO_SUBSCRIBE_SUPPORT 1
	//#else
	//	#define ZYXEL_VOIP_MWI_OOD_NOTIFY_WO_SUBSCRIBE_SUPPORT 0
	//#endif //ZYPRJ_CUSTOMER_TISCALI.
	//Michael.20170914.001.E: Add.
#endif //ZYXEL_VOIP_MWI_SUPPORT.
//--------------------------------------------
 //Michael.20150709.001.B: Add to support the VMWI API.
#ifndef ZYXEL_PHONE_VMWI_SUPPORT // TODO: It's BETTER to be controlled by the "make menuconfig" PROFILE, or according to the BRCM SDK Version Info defined in the "make menuconfig" PROFILE.
	#define ZYXEL_PHONE_VMWI_SUPPORT 1
#endif //ZYXEL_PHONE_VMWI_SUPPORT.
#if ZYXEL_PHONE_VMWI_SUPPORT
	#define VISUAL_MWI 1 //For Legacy Code Support.
	#define ZYXEL_PHONE_VMWI_ONLY_ONHOOK_STATE_SUPPORT 1 //NOTE: MUST ALWAYS be ON(1) due to the physical limitation!! This is learned from the Practical Experiment Result (a.k.a Experience) based-on BRCM platform's VMWI APIs on (2015.07.14, Mon.).
#endif //ZYXEL_PHONE_VMWI_SUPPORT.
 //Michael.20150709.001.E: Add.
//--------------------------------------------
#define ZYXEL_PHONE_CLID_COPY_PHONENUMBER_TO_SUBSTITUTE_THE_EMPTY_DISPLAYNAME_PART_SUPPORT 1 //Michael.20180320.001: Add to make Caller-ID (CLID) support to Copy the PhoneNumber part content to substitute the EMPTY DisplayName part info to improve to prevent/avoid the CLIP Display IOP issue of some Telephone-sets (e.g. Siemens Euroset 5020).
//--------------------------------------------
#define DIAL_PLAN          		1	/* for DialPlan Support */
//--------------------------------------------
// TODO: <<NOTE>> If want to disable this feature, SHOULD also consider how to disable the corresponding WebGUI page either!!==> It's BETTER & RECOMMENDED to control it by the "make menuconfig" PROFILE.
#ifndef SPEED_DIAL
	#define SPEED_DIAL			1	/* for Speed dial/Phone book Support */
#endif //SPEED_DIAL.
//--------------------------------------------
#define ZYXEL_CALL_REDIAL_SUPPORT	1	/* Call Re-Dial */
//--------------------------------------------
#define ZYXEL_CALL_RETURN_SUPPORT	1	/* Call Return feature used with phone config */
//--------------------------------------------
// TODO: <<NOTE>> If want to disable this feature, SHOULD also consider how to disable the corresponding WebGUI page either!!==> It's BETTER & RECOMMENDED to control it by the "make menuconfig" PROFILE.
#ifndef ZYXEL_CALL_POLICY_HANDLE_SUPPORT
	#define ZYXEL_CALL_POLICY_HANDLE_SUPPORT		1	/* Curtis 20140122: Add Call Policy Book -- for call policy book support */
#endif //ZYXEL_CALL_POLICY_HANDLE_SUPPORT.
#if ZYXEL_CALL_POLICY_HANDLE_SUPPORT
	/* Decide/choose One Response Code (among the following three) for the Incoming Call Block/Reject function:
	  * Note: If more than one is enabled, Only-One will be applied, the preference/priority is shown as their presence order! */
	#define ZYXEL_CALL_POLICY_HANDLE_INCOMING_CALL_BLOCK_RESP_CODE_488_NOT_ACCEPTABLE_HERE	1
	//#define ZYXEL_CALL_POLICY_HANDLE_INCOMING_CALL_BLOCK_RESP_CODE_403_FORBIDDEN				1
	//#define ZYXEL_CALL_POLICY_HANDLE_INCOMING_CALL_BLOCK_RESP_CODE_480_TEMP_UNAVAILABLE		1
#endif //ZYXEL_CALL_POLICY_HANDLE_SUPPORT.
//--------------------------------------------
// TODO: <<NOTE>> If want to disable this feature, SHOULD also consider how to disable the corresponding WebGUI page either!!==> It's BETTER & RECOMMENDED to control it by the "make menuconfig" PROFILE.
#ifndef ZYXEL_INTERNAL_PHONEBOOK_SUPPORT
	#define ZYXEL_INTERNAL_PHONEBOOK_SUPPORT	1	//2013/05/02 Michael.Lin Add. Should be related to 'INTERNAL_CALL' Call Feature! //2014/01/24 ,yushiuan porting.
#endif //ZYXEL_INTERNAL_PHONEBOOK_SUPPORT.
//--------------------------------------------
//#define PSTN_PHONEBOOK	1
//--------------------------------------------
//#define VDSP_DETECT_DIAL_DIGITS	1
//--------------------------------------------
//#define VOIP_CONFIG_BY_TELEPHONE_KEYPAD	1	//2014/01/08 Michael.Lin Add.
//--------------------------------------------


//==================================< Phone Feature: (c)Phone FSM.
#define PHONE_INCOMMING_CALL_OPEN_CHANNEL_BEFORE_CHANGETO_ANSWER 1 //**Must be Enabled on MTK/EcoNet platform!!


//==================================< Phone Feature: Customization or Special.
//Michael.20171124.001.B: Add to support the feature that while NO Enabled SIP Acct is Selected, the Phone Port would Behave Like it has NO function - (a)OffHook to play NO Tone (i.e. keep Silence) and (b)the corresponding VoIP LED always keeps in light-OFF no matter OffHook or OnHook states. This feature was first designed & implemented as a Customization Feature for the WIND Italy.
#if ZYXEL_PHONE_NO_ENABLED_SIP_ACCT_IS_SELECTED_MAKE_THE_PHONE_PORT_BEHAVE_LIKE_NO_FUNCTION
	//NOTE/DEPENDENCY: 'ZYXEL_PHONE_TONE_PLAYS_SILENCE_FOR_OFFHOOK_BUT_NO_ENABLED_SIP_ACCT_IS_SELECTED_SUPPORT' is designed to be a stand-alone PHONE feature. However, if/once 'ZYXEL_PHONE_NO_ENABLED_SIP_ACCT_IS_SELECTED_MAKE_THE_PHONE_PORT_BEHAVE_LIKE_NO_FUNCTION' is enabled, then it MUST be Enabled/Supported accordingly.
	#if !(ZYXEL_PHONE_TONE_PLAYS_SILENCE_FOR_OFFHOOK_BUT_NO_ENABLED_SIP_ACCT_IS_SELECTED_SUPPORT)
	#undef ZYXEL_PHONE_TONE_PLAYS_SILENCE_FOR_OFFHOOK_BUT_NO_ENABLED_SIP_ACCT_IS_SELECTED_SUPPORT
	#define ZYXEL_PHONE_TONE_PLAYS_SILENCE_FOR_OFFHOOK_BUT_NO_ENABLED_SIP_ACCT_IS_SELECTED_SUPPORT	1
	#endif //!(ZYXEL_PHONE_TONE_PLAYS_SILENCE_FOR_OFFHOOK_BUT_NO_ENABLED_SIP_ACCT_IS_SELECTED_SUPPORT).
#endif //ZYXEL_PHONE_NO_ENABLED_SIP_ACCT_IS_SELECTED_MAKE_THE_PHONE_PORT_BEHAVE_LIKE_NO_FUNCTION.

#ifndef ZYXEL_PHONE_TONE_PLAYS_SILENCE_FOR_OFFHOOK_BUT_NO_ENABLED_SIP_ACCT_IS_SELECTED_SUPPORT
	#define ZYXEL_PHONE_TONE_PLAYS_SILENCE_FOR_OFFHOOK_BUT_NO_ENABLED_SIP_ACCT_IS_SELECTED_SUPPORT	0
#endif //ZYXEL_PHONE_TONE_PLAYS_SILENCE_FOR_OFFHOOK_BUT_NO_ENABLED_SIP_ACCT_IS_SELECTED_SUPPORT.
//Michael.20171124.001.E: Add.



//==================================< Call Feature
//#define ZYXEL_DONT_SUPPORT_INTERNAL_CALL	0
//--------------------------------------------
//Michael.20141210.001.B: Modify to do enhancements (some ones are the preparation for the future) along with the BRCM SDK 416L02A support task.
#ifndef ZYXEL_EMBEDDED_IVR_SUPPORT // TODO: It's BETTER to be controlled by the "make menuconfig" PROFILE.
	#define ZYXEL_EMBEDDED_IVR_SUPPORT	0	//Old name: EMBEDDED_IVR.
#endif //ZYXEL_EMBEDDED_IVR_SUPPORT.

#if ZYXEL_EMBEDDED_IVR_SUPPORT
	#ifndef MM_IVR_VO_REC_SYS_DEFAULT
	#define MM_IVR_VO_REC_SYS_DEFAULT "ivrsys.bin"
	#endif //MM_IVR_VO_REC_SYS_DEFAULT.

	#ifndef MM_IVR_SYS_TONE_HOWLER
	#define MM_IVR_SYS_TONE_HOWLER "howler_ulaw.bin"
	#endif //MM_IVR_SYS_TONE_HOWLER.

	//#define IVRCHECKCODEC_BUGFIX	1	//used in some old code(s).
	//#define EMBEDDED_IVR		//used in some old code(s).
	//#define ZYXEL_IVR_PORTING	//used in '$(BRCM_VODSL)/voip/util/boardioctl/ivrFlashIoctl.c/BroadcomFlashWriteIvr() + BroadcomFlashReadIvr()'.
	#define INC_NAND_FLASH_DRIVER	1	//Able to Direct Access(Read/Write) the (Flash-based) File System for the IVR Recorded/Recording Voice Media. Used in '$(ZyIMS)/driver_itf/src/flash_itf.c/flashIvrRead() + flashIvrWrite()'.

	//#define N0_IVRUSR_PATH 0	//used in (1)'$(ZyIMS)/mm/core/(i)src/mm_core_ivr.c & (ii)h/mm_core_ivr.h', (2)'$(ZyIMS)/voice/(i)src/ivrcmd.c & (ii)h/ivrcmd.h'.
	#define ZYXEL_EMBEDDED_IVR_VOICE_REC_FILE_USR (ZYXEL_VOIP_WRITABLE_PARTITION_DIR "/ivr_data_usr")
	#define ZYXEL_EMBEDDED_IVR_VOICE_REC_FILE_SYS (ZYXEL_VOIP_WRITABLE_PARTITION_DIR "/ivr_data_sys")
	#define ZYXEL_EMBEDDED_IVR_VOICE_REC_FILE_SYS_DEFAULT (ZYXEL_VOIP_ZYIMS_INSTALL_BIN_DIR "/" MM_IVR_VO_REC_SYS_DEFAULT)
	#define ZYXEL_EMBEDDED_IVR_SYS_TONE_HOWLER (ZYXEL_VOIP_ZYIMS_INSTALL_BIN_DIR "/" MM_IVR_SYS_TONE_HOWLER)
#endif //ZYXEL_EMBEDDED_IVR_SUPPORT.
//Michael.20141210.001.E: Modify.

//--------------------------------------------(MOH:Music-On-Hold Generation Support)
#if ZYXEL_EMBEDDED_IVR_SUPPORT //Michael.20141210.001: Add to Modify.
	#ifndef ZYXEL_VOIP_MUSIC_ON_HOLD_SUPPORT
	#define ZYXEL_VOIP_MUSIC_ON_HOLD_SUPPORT	1	//Old name: MUSIC_ON_HOLD.
	#endif //ZYXEL_VOIP_MUSIC_ON_HOLD_SUPPORT.
#endif //ZYXEL_EMBEDDED_IVR_SUPPORT.

//--------------------------------------------(EM:Early-Media Generation Support)
#if ZYXEL_EMBEDDED_IVR_SUPPORT //Michael.20141210.001: Add to Modify.
	#ifndef ZYXEL_VOIP_EARLY_MEDIA_SUPPORT
	#define ZYXEL_VOIP_EARLY_MEDIA_SUPPORT		1	//Old name: EARLY_MEDIA.
	#endif //ZYXEL_VOIP_EARLY_MEDIA_SUPPORT.

	//#define DEFAULT_EARLYMEDIA_RINGTONE	1	//used in '$(ZyIMS)/mm/core/h/mm_core_ivr.h' + '$(ZyIMS)/mm/common/h/ivr_common.h'.
	#define EARLY_MEDIA_NO_CHANGE_SDP	1	//used in '$(ZyIMS)/mm/core/src/voice_dsp_core_fsm.c'.
#endif //ZYXEL_EMBEDDED_IVR_SUPPORT.

//--------------------------------------------(Un-registered state Outgoing Call, Non-Proxy P2P (Direct) Call, and Emergency Call-related)
//Michael.20150309.001.B: Add to Support the Emergency Number Phonebook and Append the SIP header "Priority: high" for an Outgoing Emergency Number Call.
#ifndef ZYXEL_VOIP_EMERGENCY_CALL_SUPPORT // TODO: It's controlled by the "make menuconfig" PROFILE!
	#define ZYXEL_VOIP_EMERGENCY_CALL_SUPPORT 0
#endif //ZYXEL_VOIP_EMERGENCY_CALL_SUPPORT.

#if ZYXEL_VOIP_EMERGENCY_CALL_SUPPORT
	#ifndef ZYXEL_VOIP_EMERGENCY_NUMBER_PHONEBOOK_SUPPORT
	#define ZYXEL_VOIP_EMERGENCY_NUMBER_PHONEBOOK_SUPPORT 1
	#endif //ZYXEL_VOIP_EMERGENCY_NUMBER_PHONEBOOK_SUPPORT.

	//NOTE/DEPENDENCY: 'ZYXEL_VOIP_SIP_UNREG_OUT_CALL_TO_SAME_SERVER_SUPPORT' is designed to be a stand-alone CALL feature. However, if/once 'ZYXEL_VOIP_EMERGENCY_CALL_SUPPORT' is enabled, then it MUST be Enabled/Supported accordingly.
	#if !(ZYXEL_VOIP_SIP_UNREG_OUT_CALL_TO_SAME_SERVER_SUPPORT)
	#undef ZYXEL_VOIP_SIP_UNREG_OUT_CALL_TO_SAME_SERVER_SUPPORT
	#define ZYXEL_VOIP_SIP_UNREG_OUT_CALL_TO_SAME_SERVER_SUPPORT 1
	#endif //!(ZYXEL_VOIP_SIP_UNREG_OUT_CALL_TO_SAME_SERVER_SUPPORT).
#endif //ZYXEL_VOIP_EMERGENCY_CALL_SUPPORT.
//Michael.20150309.001.E: Add.


//Michael.20141022.001.B: Add to support making the Un-Registered SIP account issue the outgoing call SIP INVITE to the same server target as the one during Registered state.
#ifndef ZYXEL_VOIP_SIP_UNREG_OUT_CALL_TO_SAME_SERVER_SUPPORT // TODO: It's controlled by the "make menuconfig" PROFILE!
	//NOTE/DEPENDENCY: 'ZYXEL_VOIP_SIP_UNREG_OUT_CALL_TO_SAME_SERVER_SUPPORT' is designed to be a stand-alone CALL feature. However, if/once 'ZYXEL_VOIP_EMERGENCY_CALL_SUPPORT' is enabled, then it MUST be Enabled/Supported accordingly.
	#define ZYXEL_VOIP_SIP_UNREG_OUT_CALL_TO_SAME_SERVER_SUPPORT 0
#endif //ZYXEL_VOIP_SIP_UNREG_OUT_CALL_TO_SAME_SERVER_SUPPORT.

#if ZYXEL_VOIP_SIP_UNREG_OUT_CALL_TO_SAME_SERVER_SUPPORT
	#define ZYXEL_VOIP_SIP_UNREG_OUT_CALL_DIAL_TONE_TYPE 13 //Ref to 'tr104_object.h/TONE_EVENT_DIAL(2), _SPECIALDIAL(13), _STUTTERDIAL(7), _SPECIALINFO(14), _REORDER(6), _CONGESTION(16), _BUSY(0)'.
	#define IS_ZYXEL_VOIP_SIP_UNREG_OUT_CALL_EMERGENCY_CALL 1 //Michael.20150210.001: Add to enhance the Emergency Call feature.
	#define ZYXEL_VOIP_SIP_OUT_CALL_LINE_EARLY_DETERMINED_ON_OFFHOOK 1 //Michael.20141021.001: Add for the OLD BRCM/ZyIMS VoIP to enhance the Dialing state operation logic, especially the associated (Registered or Enabled) SIP line/account determine logic.
#endif //ZYXEL_VOIP_SIP_UNREG_OUT_CALL_TO_SAME_SERVER_SUPPORT.
//Michael.20141022.001.E: Add.

#if 0 //Removed to the top for the Feature-DEPENDENCY consideration.
//Michael.20171220.001.B: Add the Distinctive Ring-related Feature Flag and Constant definitions, as well as the DEPENDency between them if necessary.
#ifndef ZYXEL_VOIP_DISTINCTIVE_RING_SUPPORT
#define ZYXEL_VOIP_DISTINCTIVE_RING_SUPPORT 1
#endif //ZYXEL_VOIP_DISTINCTIVE_RING_SUPPORT.
//Michael.20171220.001.E: Add.
#endif // 0.


//--------------------------------------------(The operation logic of the following conditional compile MAY lead to Error situtaion!)
//#ifdef EARLY_MEDIA
//	#define IVR	1
//#endif
//#ifdef EMBEDDED_IVR
//	#define IVR	1
//#endif
//--------------------------------------------
#define CALL_TRANSFER			1
#define ZYNOS_CALL_TRANSFER	1	//support for Blind-Transfer, Consult-Transfer
#define ZYXEL_VOIP_CALL_TRANSFER_TRANSFEROR_SEND_OUT_BYE_TO_TRANSFEREE	1	//20171031.Amber: Add for Call Transfer Feature Change about Transferor send out bye to Transferee to disconnect the First Call.
//--------------------------------------------
//#define CALL_FORWARD		1
//--------------------------------------------
//#define THREE_WAY_CALL	1
#define CALL_CONFERENCE	1
//--------------------------------------------
#define DO_NOT_DISTURB		1	/* Do not disturb support */
//--------------------------------------------
#define CCBS_SUPPORT		1	//Web Dial?	//CCBS: Call Completion (i.e. Call back?) on Busy Subscriber.
//#define ZYXEL_WEB_DIAL_SUPPORT	1
//--------------------------------------------
//#define CALL_PARK_PICKUP		1
//--------------------------------------------
//Michael.NOTE.20130423.001: This feature is achieved/fullfilled by using 'ZLD_Scripts' in Lantiq/ZyIMS VoIP!
//Michael.NOTE.20131231.001: This feature is originated from ISDN and similar to the 'Call Park & Pickup' - it can put a call on hold for three minutes, during which time you can pick it up again at a different place.
//#define TERMINAL_PORTABILITY	1
//--------------------------------------------


//--------------------------------------------(Call Feature: Special & Customization, as well as the one(s) that MAY depend on that Special or Customization one(s).)
//=== ZYPRJ_CUSTOMER_SUNRISE ===
#ifdef ZYPRJ_CUSTOMER_SUNRISE		// TODO: It's BETTER to be controlled by the "make menuconfig" PROFILE, NOT the Customization Compile Flag!
	#define ZYXEL_CALL_HOLD_ANNOUNCE_TONE_SUPPORT	1

	#define ZYXEL_FEATURE_SERVER_SIDE_FEATURE_CONFIG_CALL_SUPPORT				1
	#define ZYXEL_FEATURE_SERVER_SIDE_FEATURE_CONFIG_CALL_REMOVE_LAST_POUND	1
	#define ZYXEL_FEATURE_SERVER_SIDE_FEATURE_CONFIG_CALL_SWAP_FEATURE_KEY		1
#endif //ZYPRJ_CUSTOMER_SUNRISE.


//=== ZYPRJ_CUSTOMER_SUPERONLINE ===
/*SuperOnline customization feature : config silence suppression and comfort noise seprately , normally , they are configed togther.
   If  silence suppression enable , it means CPE will send " CN packet " to peer side while talking state , and if comfort noise enable ,
   it means CPE receive the CN packet , CPE DSP will generate comfort noise , yushiuan , 2014/11/10*/

//#ifndef SUPERONLINE_CUSTOMIZATION
	//#define SUPERONLINE_CUSTOMIZATION 1
//#endif

//#ifdef SUPERONLINE_CUSTOMIZATION
#if ZYPRJ_CUSTOMER_SUPERONLINE
	//VAD+SilenceSuppression+CNG.
	#define SILENCE_SUPPRESSION_AND_COMFORT_NOISE_CNOFIG_SEPARATELY 1
#else
	//VAD+SilenceSuppression+CNG.
	#define SILENCE_SUPPRESSION_AND_COMFORT_NOISE_CNOFIG_SEPARATELY 0
#endif //ZYPRJ_CUSTOMER_SUPERONLINE.


//=== ZYPRJ_CUSTOMER_WIND ===
#ifndef ZYXEL_VOICE_FAX_MODE_G711_PT_DISABLE_T38_CAP
	//NOTE/DEPENDENCY: 'ZYXEL_VOICE_FAX_MODE_G711_PT_DISABLE_T38_CAP' is designed to be a stand-alone CALL feature. However, if/once 'ZYXEL_VOICE_CONFIG_TR069_FAXT38_ENABLE_MAPPING_TO_FAXMODE' is enabled, then it MUST be Enabled/Supported accordingly.
	#define ZYXEL_VOICE_FAX_MODE_G711_PT_DISABLE_T38_CAP 0
#endif //ZYXEL_VOICE_FAX_MODE_G711_PT_DISABLE_T38_CAP.


//Michael.20151109.001.B: Add to support the feature that One SIP Acct is totally occupied by the First Associated Local Phone Port. This feature is originally requested by the WIND(@Italy) project.
#if ZYPRJ_CUSTOMER_WIND
	//NOTE/DEPENDENCY: 'ZYXEL_VOIP_SIP_ACCT_OCCUPIED_BY_THE_FIRST_ASSOCIATED_LOCAL_PHONE_PORT' is designed to be a stand-alone CALL feature. However, if/once 'ZYPRJ_CUSTOMER_WIND' is enabled, then it MUST be Enabled/Supported accordingly.
	#if !(ZYXEL_VOIP_SIP_ACCT_OCCUPIED_BY_THE_FIRST_ASSOCIATED_LOCAL_PHONE_PORT)
	#undef ZYXEL_VOIP_SIP_ACCT_OCCUPIED_BY_THE_FIRST_ASSOCIATED_LOCAL_PHONE_PORT
	#define ZYXEL_VOIP_SIP_ACCT_OCCUPIED_BY_THE_FIRST_ASSOCIATED_LOCAL_PHONE_PORT	1
	#endif //!(ZYXEL_VOIP_SIP_ACCT_OCCUPIED_BY_THE_FIRST_ASSOCIATED_LOCAL_PHONE_PORT).
#endif //ZYPRJ_CUSTOMER_WIND.

#ifndef ZYXEL_VOIP_SIP_ACCT_OCCUPIED_BY_THE_FIRST_ASSOCIATED_LOCAL_PHONE_PORT
	#define ZYXEL_VOIP_SIP_ACCT_OCCUPIED_BY_THE_FIRST_ASSOCIATED_LOCAL_PHONE_PORT	0
#endif //ZYXEL_VOIP_SIP_ACCT_OCCUPIED_BY_THE_FIRST_ASSOCIATED_LOCAL_PHONE_PORT.

#if ZYXEL_VOIP_SIP_ACCT_OCCUPIED_BY_THE_FIRST_ASSOCIATED_LOCAL_PHONE_PORT
	//NOTE/DEPENDENCY: 'ZYXEL_VOIP_PHONE_USING_THE_SIP_ACCT_MUST_BE_IN_THE_DL_PHONE_SELECT_BITMAP' is designed to be a stand-alone CALL feature. However, if/once 'ZYXEL_VOIP_SIP_ACCT_OCCUPIED_BY_THE_FIRST_ASSOCIATED_LOCAL_PHONE_PORT' is enabled, then it MUST be Enabled/Supported accordingly.
	#if !(ZYXEL_VOIP_PHONE_USING_THE_SIP_ACCT_MUST_BE_IN_THE_DL_PHONE_SELECT_BITMAP)
	#undef ZYXEL_VOIP_PHONE_USING_THE_SIP_ACCT_MUST_BE_IN_THE_DL_PHONE_SELECT_BITMAP
	#define ZYXEL_VOIP_PHONE_USING_THE_SIP_ACCT_MUST_BE_IN_THE_DL_PHONE_SELECT_BITMAP	1
	#endif //!(ZYXEL_VOIP_PHONE_USING_THE_SIP_ACCT_MUST_BE_IN_THE_DL_PHONE_SELECT_BITMAP).
	//----------
	#define ZYXEL_VOIP_PHONE_SIP_ACCT_OCCUPY_BY_DEFAULT_SELECT_ONE	0 //Make the default value 0 match to the requirement from & defined by the WIND Italy.
	#define ZYXEL_VOIP_PHONE_SIP_ACCT_OCCUPY_BY_JUST_DIAL_IN_ONE		0 //Make the default value 0 match to the requirement from & defined by the WIND Italy.
	#define ZYXEL_VOIP_PHONE_SIP_ACCT_OCCUPY_BY_JUST_UTILIZED_ONE		1
	#define ZYXEL_VOIP_PHONE_SIP_ACCT_OCCUPY_BY_NONE					2
	#define ZYXEL_VOIP_PHONE_DIALING_STATE_SIP_ACCT_OCCUPY_TYPE	ZYXEL_VOIP_PHONE_SIP_ACCT_OCCUPY_BY_DEFAULT_SELECT_ONE
	#define ZYXEL_VOIP_PHONE_RINGING_STATE_SIP_ACCT_OCCUPY_TYPE	ZYXEL_VOIP_PHONE_SIP_ACCT_OCCUPY_BY_JUST_DIAL_IN_ONE
	#define ZYXEL_VOIP_PHONE_DISC_STATE_SIP_ACCT_OCCUPY_TYPE		ZYXEL_VOIP_PHONE_SIP_ACCT_OCCUPY_BY_DEFAULT_SELECT_ONE
	//----------
	//Michael.20190219.004.B: Modify to co-operate with 'Michael.20190219.001', 'Michael.20190219.002', and 'Michael.20190219.003' tofix the issue [eITS#190100027][#91342]The 'AddBusyTone' feature SHOULD play the FastBusy-tone (a.k.a Congestion-tone) instead of the Busy-tone.
	//#define ZYXEL_VOIP_SIP_ACCT_OCCUPIED_NOTIFY_TONE_TYPE	0 //Ref to 'tr104_object.h/TONE_EVENT_DIAL(2), _SPECIALDIAL(13), _STUTTERDIAL(7), _SPECIALINFO(14), _REORDER(6), _CONGESTION(16), _BUSY(0)'.
	#define ZYXEL_VOIP_SIP_ACCT_OCCUPIED_NOTIFY_TONE_TYPE	0 //Ref to 'phfsm.h/PHONE_PORT_SB_TONE_CONGESTION(0), _BUSY(1), _DIAL(2), _RINGBACK(3), _SPECIAL_DIAL(4), _MWI_STUTTER(5), _CALL_WAITING(6), _REORDER(7), _HOWLER(8), _RELEASE(9), _INFORMATION(10), _POSITIVE_ACK(11), _NEGATIVE_ACK(12), _SILENCE(13).
	//Michael.20190219.004.E: Modify.
#endif //ZYXEL_VOIP_SIP_ACCT_OCCUPIED_BY_THE_FIRST_ASSOCIATED_LOCAL_PHONE_PORT.
//Michael.20151109.001.E: Add.

#ifndef ZYXEL_VOIP_PHONE_USING_THE_SIP_ACCT_MUST_BE_IN_THE_DL_PHONE_SELECT_BITMAP //Michael.20151113.001: Add to support the feature that the Phone is using the SIP Acct MUST of course be the member of the IncomingCall-to-MultiplePhone GroupRing, no matter it is originally belonging to or not.
	//NOTE/DEPENDENCY: 'ZYXEL_VOIP_PHONE_USING_THE_SIP_ACCT_MUST_BE_IN_THE_DL_PHONE_SELECT_BITMAP' is designed to be a stand-alone CALL feature. However, if/once 'ZYXEL_VOIP_SIP_ACCT_OCCUPIED_BY_THE_FIRST_ASSOCIATED_LOCAL_PHONE_PORT' is enabled, then it MUST be Enabled/Supported accordingly.
	#define ZYXEL_VOIP_PHONE_USING_THE_SIP_ACCT_MUST_BE_IN_THE_DL_PHONE_SELECT_BITMAP	0
#endif //ZYXEL_VOIP_PHONE_USING_THE_SIP_ACCT_MUST_BE_IN_THE_DL_PHONE_SELECT_BITMAP.



//==================================< Log, Record, State & Statistics.
#define CALLHISTORY_SUPPORT	1
#define NEW_VOICE_DATABASE	1 //2014-09-29 Steve. Add
//--------------------------------------------
#define CENTRALIZE_LOG			1
#define VOIP_SYSLOG				1 /*Jason , syslog*/
#define CALL_STATUS_SUPPORT	1 //yushian add , to replace CENTRALIZE_LOG.
//--------------------------------------------
//#define MISSED_CALL_EMAIL_NOTIFICATION 1
//#define SMTP_AUTH				1
//--------------------------------------------
//#define ZYXEL_VOIP_CONFIG_AND_STATS_SUPPORT	1	//2013/05/02 Michael.Lin Add.
//--------------------------------------------
#ifndef ZYXEL_VOIP_INUSE_IGNORE_PHONE_OFFHOOK
	#define ZYXEL_VOIP_INUSE_IGNORE_PHONE_OFFHOOK 1
#endif //ZYXEL_VOIP_INUSE_IGNORE_PHONE_OFFHOOK.
//--------------------------------------------


//==================================< Config.
#ifndef ZYXEL_VOICE_CONFIG_TR069_FAXT38_ENABLE_MAPPING_TO_FAXMODE
	#define ZYXEL_VOICE_CONFIG_TR069_FAXT38_ENABLE_MAPPING_TO_FAXMODE	0
#endif //ZYXEL_VOICE_CONFIG_TR069_FAXT38_ENABLE_MAPPING_TO_FAXMODE.

#if ZYXEL_VOICE_CONFIG_TR069_FAXT38_ENABLE_MAPPING_TO_FAXMODE
	//NOTE/DEPENDENCY: 'ZYXEL_VOICE_FAX_MODE_G711_PT_DISABLE_T38_CAP' is designed to be a stand-alone CALL feature. However, if/once 'ZYXEL_VOICE_CONFIG_TR069_FAXT38_ENABLE_MAPPING_TO_FAXMODE' is enabled, then it MUST be Enabled/Supported accordingly.
	#if !(ZYXEL_VOICE_FAX_MODE_G711_PT_DISABLE_T38_CAP)
	#undef ZYXEL_VOICE_FAX_MODE_G711_PT_DISABLE_T38_CAP
	#define ZYXEL_VOICE_FAX_MODE_G711_PT_DISABLE_T38_CAP	1
	#endif //!(ZYXEL_VOICE_FAX_MODE_G711_PT_DISABLE_T38_CAP).
#endif //ZYXEL_VOICE_CONFIG_TR069_FAXT38_ENABLE_MAPPING_TO_FAXMODE.

#ifndef ZYXEL_VOICE_CONFIG_TR069_SIP_PHONE_MAPPING_BY_STD_PHY_REFERENCE_LIST
	#define ZYXEL_VOICE_CONFIG_TR069_SIP_PHONE_MAPPING_BY_STD_PHY_REFERENCE_LIST	0
#endif //ZYXEL_VOICE_CONFIG_TR069_SIP_PHONE_MAPPING_BY_STD_PHY_REFERENCE_LIST.



//==================================< FW Upgrade & Config/Provisioning.
//#define AUTOPRO				1
//#define AUTOPRO_PINCODE		1
//#define HTTP_AUTO_PROVISION	1
//#define TFTP_CLNT				1		/* TFTP Client Support */
//--------------------------------------------


//==================================< Debug & Test.
//#define VOIP_TE_TEST		1
//--------------------------------------------
//#define VOIP_IAD_DEBUG	1
//--------------------------------------------


//==================================< Unknown Feature!!
//#define ENABLE_CACHE		1
//--------------------------------------------
//#define DONT_REINVITE_AFTER_REBOOT_FIX	1
//--------------------------------------------

#endif //__SWITCH_H__
