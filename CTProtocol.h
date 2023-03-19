#pragma once

#include "ProtocolBase.h"

#define DCSVC_STAT_STOPPED				SERVICE_STOPPED
#define DCSVC_STAT_START_PENDING		SERVICE_START_PENDING
#define DCSVC_STAT_STOP_PENDING			SERVICE_STOP_PENDING
#define DCSVC_STAT_RUNNING				SERVICE_RUNNING
#define DCSVC_STAT_CONTINUE_PENDING		SERVICE_CONTINUE_PENDING
#define DCSVC_STAT_PENDING				SERVICE_PAUSE_PENDING
#define DCSVC_STAT_PAUSED				SERVICE_PAUSED
#define DCSVC_STAT_CANNOTCONTROL		((DWORD)-1)

#define ACK_SUCCESS			0
#define ACK_FAILED			1

#define WORLD_NULL			0
#define SVRGRP_NULL			0
#define SVRID_NULL			0

#define MAKESVRID(a,b,c)	DWORD(DWORD(a) << 16 | DWORD(b) << 8 | DWORD(c))
#define SVRGROUP(a)			BYTE(a >> 16)
#define SVRTYPE(a)			BYTE(a >> 8)
#define SVRID(a)			BYTE(a)

#define SVRGRP_NULL			0
#define SVRGRP_CTLSVR		1
#define SVRGRP_LOGINSVR		2
#define SVRGRP_WORLDSVR		3
#define SVRGRP_MAPSVR		4
#define SVRGRP_PATCHSVR		5
#define SVRGRP_FTPSVR		6
#define SVRGRP_LOG			7
#define SVRGRP_RLYSVR		8
#define SVRGRP_PREFTPSVR	9

#define DEFAULT_CTL_PORT	3615
#define DEFAULT_PATCH_PORT	3715
#define DEFAULT_GM_PORT		3815
#define DEFAULT_LOGIN_PORT	4815
#define DEFAULT_MAP_PORT	5815

typedef enum WORLDPOST_TYPE
{
	WPT_NONE = 0,
	WPT_TACTICSKICK,
	WPT_TACTICSEND,
	WPT_PAYBACK,
	WPT_LOTITEM,
	WPT_TOUTNAMENTPARTYADD
} *LPWORLDPOST_TYPE;

typedef enum SERVER_MESSAGE
{
	MSG_POSTINVENITEM = 1,
	MSG_LOCAL_REWARD,
	MSG_CASTLE_REWARD,
	PREMIUM_PETNAME,
	TMS_NORECEIVER,
	NAME_OPERATOR,
	MSG_CHAR_LOGOUT,
	MSG_GUILDPOINT_TAKE,
	MSG_PRESENT_TITLE,
	MSG_PRESENT_MESSAGE,
	MSG_ITEMERROR_TITLE,
	MSG_ITEMERROR_MESSAGE,
	MSG_AUCTION_OPERATOR,	 // ��� �߰���
	MSG_AUCTION_FAIL,		 // �ŷ��� �̷������ �ʾҽ��ϴ�.
	MSG_AUCTION_BIDSUCCESS,  // �����Ͻ� ��ǰ�� �����߽��ϴ�.
	MSG_AUCTION_PRICE,		 // �ŷ��� ���������� �̷�������ϴ�.
	MSG_AUCTION_REGCANCEL,	 // ����� ��ҵ� ��ǰ�Դϴ�.
	MSG_AUCTION_BIDFAIL,	 // ������ �����Ͽ����ϴ�.
	MSG_AUCTION_OTHERBIDDER, // ���� �����ڰ� ��Ÿ�����ϴ�.
	MSG_AUCTION_OTHERWIN,	 // ��ǰ�� �ٸ� �п��� �����Ǿ����ϴ�
	MSG_AUCTION_FAIL_BODY,			// ������ �Ⱓ ���� %s�� ���� �����ڰ� ��Ÿ���� �ʾ� �ŷ��� �̷������ ���߽��ϴ�.�ݼ۵� ��ǰ�� Ȯ�����ֽñ� �ٶ��ϴ�. 
	MSG_AUCTION_BIDSUCCESS_BODY,	// %s�� �����Ǽ̽��ϴ�. ������ �����Ǿ� �ִ� ��ǰ�� Ȯ�����ֽñ� �ٶ��ϴ�.
	MSG_AUCTION_PRICE_BODY,			// %s ��ǰ�� ���������� �ǸŵǾ����ϴ�. ������ �����Ǿ� �ִ� �ݾ��� Ȯ�����ֽñ� �ٶ��ϴ�.(����� �̿� ������� �����˴ϴ�)
	MSG_AUCTION_REGCANCEL_BODY,		// ����忡�� ����� ��ҵ� %s�Դϴ�. ������ �����Ǿ� �ִ� ��ǰ�� Ȯ�����ֽñ� �ٶ��ϴ�.
	MSG_AUCTION_BIDFAIL_BODY,		// ����� �̿뿡 ������ ��� �˼��մϴ�. %s�� �����ϼ̴� �ݾ��� ������ �����Ǿ� ������ Ȯ�����ֽñ� �ٶ��ϴ�.
	MSG_AUCTION_OTHERBIDDER_BODY,	// �����Ͻ� %s�� ���� �����ڰ� ��Ÿ�����ϴ�.���Ͻ� ��� ��� ����ڸ� ���� ���� �ݾ����� �ٽ� �����Ͻ� �� �ֽ��ϴ�.	
	MSG_AUCTION_OTHERBUY_BODY,		// %s ��ǰ�� �ٸ� �п��� �����Ǿ����ϴ�.
	MSG_AUCTION_DROP_BODY,			// %s ��ǰ�� ����� ��ҵǾ����ϴ�. �����ϼ̴� �ݾ��� ������ �����Ǿ� ������ Ȯ�����ֽñ� �ٶ��ϴ�.
	MSG_AUCTION_REGCANCEL_DROP,		// �����Ͻ� ��ǰ�� ����� ��ҵǾ����ϴ�.
	MSG_TACTICS_TITLE,				// �뺴 ������ ���޵Ǿ����ϴ�.
	MSG_TACTICS_MESSAGE,			// [%s]����� �뺴���� ���Ǽ̽��ϴ�. ��� �������� �ذ� ���� ��� ������ ���� �� �����ϴ�. ���� Ȱ�� ��Ź�帳�ϴ�.
	MSG_TACTICSKICK_TITLE,			// �뺴 �ذ�
	MSG_TACTICSKICK_MESSAGE,		// �뺴���ν��� �ڰ� ��Ƿ� �ذ��Ͽ����ϴ�. ��� ������ ������ �� �����ϴ�.
	MSG_TACTICSEND_TITLE,			// �뺴 ��� ������ ���޵Ǿ����ϴ�.
	MSG_TACTICSEND_MESSAGE,			// [%d] ������ ���޵Ǿ����ϴ�. �������� Ȱ���� ����帮�� �����ε� ���� ���� ��Ź�帳�ϴ�.
	MSG_HALLOFHERO_TITLE,		
	MSG_HALLOFHERO_MESSAGE,		
	TNMT_PAYBACK_TITLE,				// ��ʸ�Ʈ ���� Ż��.
	TNMT_PAYBACK_MESSAGE,			// ��ʸ�Ʈ ���߿��� Ż���Ǿ� ȯ�ұ��� ���޵Ǿ����ϴ�. ������ȸ�� �̿��� �ֽñ� �ٶ��ϴ�.
	TNMT_WIN_TITLE,
	TNMT_WIN_MESSAGE,
	TNMT_BATTING_TITLE,
	TNMT_BATTING_MESSAGE,
	MSG_MISSION_REWARD,
	RPS_REWARD_TITLE,
	RPS_REWARD_MESSAGE,
	ARENA_WIN_TITLE,
	ARENA_WIN_MESSAGE,
	TNMT_PARTYADD_TITLE,
	TNMT_PARTYADD_MESSAGE,
	MSG_SKYGARDEN_OCCUPY
};

#define CT_OPLOGIN_REQ						(CT_CONTROL + 0x0001)
#define CT_OPLOGIN_ACK						(CT_CONTROL + 0x0002)
#define CT_SVRTYPELIST_ACK					(CT_CONTROL + 0x0003)
#define CT_MACHINELIST_ACK					(CT_CONTROL + 0x0004)
#define CT_GROUPLIST_ACK					(CT_CONTROL + 0x0005)
#define CT_SERVICESTAT_REQ					(CT_CONTROL + 0x0006)
#define CT_SERVICESTAT_ACK					(CT_CONTROL + 0x0007)
#define CT_SERVICECONTROL_REQ				(CT_CONTROL + 0x0008)
#define CT_SERVICECONTROL_ACK				(CT_CONTROL + 0x0009)
#define CT_NEWCONNECT_REQ					(CT_CONTROL + 0x001A)
#define CT_SERVICECHANGE_REQ				(CT_CONTROL + 0x001B)
#define CT_SERVICECHANGE_ACK				(CT_CONTROL + 0x001C)
#define CT_SERVICEMONITOR_REQ				(CT_CONTROL + 0x001D)
#define CT_SERVICEMONITOR_ACK				(CT_CONTROL + 0x001E)
#define CT_TIMER_REQ						(CT_CONTROL + 0x001F)
#define CT_SERVICEDATA_ACK					(CT_CONTROL + 0x0020)
#define CT_SERVICEUPLOADSTART_REQ			(CT_CONTROL + 0x0021)
#define CT_SERVICEUPLOADSTART_ACK			(CT_CONTROL + 0x0022)
#define CT_SERVICEUPLOAD_REQ				(CT_CONTROL + 0x0023)
#define CT_SERVICEUPLOAD_ACK				(CT_CONTROL + 0x0024)
#define CT_SERVICEUPLOADEND_REQ				(CT_CONTROL + 0x0025)
#define CT_SERVICEUPLOADEND_ACK				(CT_CONTROL + 0x0026)
#define CT_UPDATEPATCH_REQ					(CT_CONTROL + 0x0027)
#define CT_UPDATEPATCH_ACK					(CT_CONTROL + 0x0028)

////////////////////////////////////////////////////////////////
////// ���·� CT_ANNOUNCEMENT /////////////////////////////////
#define CT_ANNOUNCEMENT_REQ					(CT_CONTROL + 0x0029)
#define CT_ANNOUNCEMENT_ACK					(CT_CONTROL + 0x002A)
////// ���·� CT_USERKICKOUT //////////////////////////////////
#define CT_USERKICKOUT_REQ					(CT_CONTROL + 0x002B)
#define CT_USERKICKOUT_ACK					(CT_CONTROL + 0x002C)
////// ���·� CT_USERMOVE /////////////////////////////////////
#define CT_USERMOVE_REQ						(CT_CONTROL + 0x002D)
#define CT_USERMOVE_ACK						(CT_CONTROL + 0x002E)
////// ���·� CT_AUTHORITY ////////////////////////////////////
#define CT_AUTHORITY_ACK					(CT_CONTROL + 0x002F)
////// ���·� CT_STLOGIN ////////////////////////////////////
#define CT_STLOGIN_REQ						(CT_CONTROL + 0x0030)
#define CT_STLOGIN_ACK						(CT_CONTROL + 0x0031)
////// ���·� CT_ACCOUNTINPUT ////////////////////////////////
#define CT_ACCOUNTINPUT_REQ					(CT_CONTROL + 0x0032)
#define CT_ACCOUNTINPUT_ACK					(CT_CONTROL + 0x0033)
////// ���·� CT_PLATFORM     ////////////////////////////////
#define CT_PLATFORM_REQ						(CT_CONTROL + 0x0034)
#define CT_PLATFORM_ACK						(CT_CONTROL + 0x0035)
////// ���·� CT_MONSPAWNFIND ////////////////////////////////
#define CT_MONSPAWNFIND_REQ					(CT_CONTROL + 0x0036)
#define CT_MONSPAWNFIND_ACK					(CT_CONTROL + 0x0037)
////// ���·� CT_MONACTION    ////////////////////////////////
#define CT_MONACTION_REQ					(CT_CONTROL + 0x0038)
#define CT_MONACTION_ACK					(CT_CONTROL + 0x0039)
////// ���·� CT_USERPROTECTED  //////////////////////////////
#define CT_USERPROTECTED_REQ				(CT_CONTROL + 0x003A)
#define CT_USERPROTECTED_ACK				(CT_CONTROL + 0x003B)
////// ���·� CT_CHARMSG    ////////////////////////////////
#define CT_CHARMSG_REQ						(CT_CONTROL + 0x003C)
#define CT_CHARMSG_ACK						(CT_CONTROL + 0x003D)
////// ���·� CT_LOCALGUILDCHANGE    ////////////////////////////////
#define CT_LOCALGUILDCHANGE_REQ				(CT_CONTROL + 0x003E)
#define CT_LOCALGUILDCHANGE_ACK				(CT_CONTROL + 0x003F)
////// ���·� CT_LOCALINIT    ////////////////////////////////
#define CT_LOCALINIT_REQ					(CT_CONTROL + 0x0040)
#define CT_LOCALINIT_ACK					(CT_CONTROL + 0x0041)

#define CT_USERPOSITION_REQ					(CT_CONTROL + 0x0043)
// BYTE		bWorld
// STRING	strTargetName
// STRING	strGMName

#define CT_USERPOSITION_ACK					(CT_CONTROL + 0x0044)
// STRING	strTargetName
// STRING	strGMName

#define CT_SERVICECLOSE_REQ					(CT_CONTROL + 0x0045)

#define CT_RECONNECT_REQ					(CT_CONTROL + 0x0046)
#define CT_DISCONNECT_REQ					(CT_CONTROL + 0x0048)
#define CT_SERVICEAUTOSTART_REQ				(CT_CONTROL + 0x004A)
#define CT_SERVICEAUTOSTART_ACK				(CT_CONTROL + 0x004B)
#define CT_CHATBAN_REQ						(CT_CONTROL + 0x004C)
#define CT_CHATBAN_ACK						(CT_CONTROL + 0x004D)
#define CT_SERVICEDATACLEAR_REQ				(CT_CONTROL + 0x004E)
#define CT_SERVICEDATACLEAR_ACK				(CT_CONTROL + 0x004F)
#define CT_ITEMFIND_REQ						(CT_CONTROL + 0x0050)
#define CT_ITEMFIND_ACK						(CT_CONTROL + 0x0051)
#define CT_ITEMSTATE_REQ					(CT_CONTROL + 0x0052)
#define CT_ITEMSTATE_ACK					(CT_CONTROL + 0x0053)
#define CT_CHATBANLIST_REQ					(CT_CONTROL + 0x0054)
#define CT_CHATBANLIST_ACK					(CT_CONTROL + 0x0055)
#define CT_CHATBANLISTDEL_REQ				(CT_CONTROL + 0x0056)
#define CT_CHATBANLISTDEL_ACK				(CT_CONTROL + 0x0057)
#define CT_CTRLSVR_REQ						(CT_CONTROL + 0x0058)
#define CT_CASTLEINFO_REQ					(CT_CONTROL + 0x0059)
#define CT_CASTLEINFO_ACK					(CT_CONTROL + 0x005A)
#define CT_CASTLEGUILDCHG_REQ				(CT_CONTROL + 0x005B)
#define CT_CASTLEGUILDCHG_ACK				(CT_CONTROL + 0x005C)
#define CT_CASTLEENABLE_REQ					(CT_CONTROL + 0x005D)
#define CT_CASTLEENABLE_ACK					(CT_CONTROL + 0x005E)
#define CT_EVENTUPDATE_REQ					(CT_CONTROL + 0x005F)
#define CT_EVENTUPDATE_ACK					(CT_CONTROL + 0x0060)
#define CT_EVENTCHANGE_REQ					(CT_CONTROL + 0x0061)
#define CT_EVENTCHANGE_ACK					(CT_CONTROL + 0x0062)
#define CT_EVENTLIST_REQ					(CT_CONTROL + 0x0063)
#define CT_EVENTLIST_ACK					(CT_CONTROL + 0x0064)
#define CT_EVENTMSG_REQ						(CT_CONTROL + 0x0065)
#define CT_EVENTMSG_ACK						(CT_CONTROL + 0x0066)
#define CT_EVENTDEL_REQ						(CT_CONTROL + 0x0067)
#define CT_CASHSHOPSTOP_REQ					(CT_CONTROL + 0x0068)
#define CT_CASHITEMSALE_REQ					(CT_CONTROL + 0x0069)
#define CT_CASHITEMSALE_ACK					(CT_CONTROL + 0x006A)
#define CT_CASHITEMLIST_REQ					(CT_CONTROL + 0x006B)
#define CT_CASHITEMLIST_ACK					(CT_CONTROL + 0x006C)
#define CT_EVENTQUARTERUPDATE_REQ			(CT_CONTROL + 0x006D)  
#define CT_EVENTQUARTERUPDATE_ACK			(CT_CONTROL + 0x006E)
#define CT_EVENTQUARTERLIST_REQ				(CT_CONTROL + 0x006F)
#define CT_EVENTQUARTERLIST_ACK				(CT_CONTROL + 0x0070)

#define CT_TOURNAMENTEVENT_REQ				(CT_CONTROL + 0x0071)
#define CT_TOURNAMENTEVENT_ACK				(CT_CONTROL + 0x0072)
#define CT_HELPMESSAGE_REQ					(CT_CONTROL + 0x0073)
#define CT_RPSGAMEDATA_REQ					(CT_CONTROL + 0x0074)
#define CT_RPSGAMEDATA_ACK					(CT_CONTROL + 0x0075)
// WORD wCount
// {
//		BYTE bType
//		BYTE bWinCount
//		BYTE bWinProb
//		BYTE bDrawProb
//		BYTE bLoseProb
//		WORD wWinKeep
//		WORD wWinPeriod
// }
#define CT_RPSGAMECHANGE_REQ				(CT_CONTROL + 0x0076)
// WORD wCount
// {
//		BYTE bType
//		BYTE bWinCount
//		BYTE bWinProb
//		BYTE bDrawProb
//		BYTE bLoseProb
//		WORD wWinKeep
//		WORD wWinPeriod
// }
#define CT_PREVERSIONTABLE_REQ				(CT_CONTROL + 0x0077)
#define CT_PREVERSIONTABLE_ACK				(CT_CONTROL + 0x0078)
#define CT_PREVERSIONUPDATE_REQ				(CT_CONTROL + 0x0079)

#define CT_INSTALLVERSION_REQ				(CT_CONTROL + 0x007A)
#define CT_INSTALLVERSION_ACK				(CT_CONTROL + 0x007B)
#define CT_INSTALLVERSIONUPDATE_REQ			(CT_CONTROL + 0x007C)

#define CT_CMGIFT_REQ						(CT_CONTROL + 0x007D)
#define CT_CMGIFT_ACK						(CT_CONTROL + 0x007E)
#define CT_CMGIFTLIST_REQ					(CT_CONTROL + 0x007F)
#define CT_CMGIFTLIST_ACK					(CT_CONTROL + 0x0080)
#define CT_CMGIFTCHARTUPDATE_REQ			(CT_CONTROL + 0x0081)
//#define CT_USERMOVE_REQ2					(CT_CONTROL + 0x0082)
//#define CT_USERPOSITION_REQ2				(CT_CONTROL + 0x0083)



////////////////////////////////////////////////////////////////
////// CT_PATCH ///////////////////////////////////////////////
///////////////////////////////////////////////////////////////
#define CT_PATCH_REQ						(CT_PATCH + 0x0001)
#define CT_PATCH_ACK						(CT_PATCH + 0x0002)
#define CT_PATCHEND_REQ						(CT_PATCH + 0x0003)
#define CT_PATCHEND_ACK						(CT_PATCH + 0x0004)
#define CT_PATCHSTART_REQ					(CT_PATCH + 0x0005)
#define CT_PREPATCH_REQ						(CT_PATCH + 0x0006)
#define CT_PREPATCH_ACK						(CT_PATCH + 0x0007)
#define CT_NEWPATCH_REQ						(CT_PATCH + 0x000A)
#define CT_NEWPATCH_ACK						(CT_PATCH + 0x000B)
#define CT_PREPATCHCOMPLETE_REQ				(CT_PATCH + 0x000C)

//////////////////////////////////////////////////////////////////////
// TRelaySvr/TWorldSvr Protocol
#define RW_RELAYSVR_REQ						(RW_RELAY + 0x0001)
// WORD wSvrID
#define RW_RELAYSVR_ACK						(RW_RELAY + 0x0002)
// WORD wCount
// {
//		DWORD dwOperatorID
// }
#define RW_ENTERCHAR_REQ					(RW_RELAY + 0x0003)
// DWORD dwCharID
// STRING strName
#define RW_ENTERCHAR_ACK					(RW_RELAY + 0x0004)
// DWORD dwCharID
// STRING strName
// BYTE bResult
// BYTE bCountry
// DWORD dwGuildID
// BYTE bGuildDuty
// WORD wPartyID
// DWORD dwPartyChiefID
// WORD wCorpsID
// DWORD m_dwGeneralID
#define RW_PARTYADD_ACK						(RW_RELAY + 0x0005)
// DWORD dwCharID
// WORD wPartyID
// DWORD dwChiefID
#define RW_PARTYDEL_ACK						(RW_RELAY + 0x0006)
// DWORD dwCharID
// WORD wPartyID
// DWORD dwChief
#define RW_PARTYCHGCHIEF_ACK				(RW_RELAY + 0x0007)
// WORD wPartyID
// DWORD dwChief
#define RW_GUILDADD_ACK						(RW_RELAY + 0x0008)
// DWORD dwCharID
// DWORD dwGuildID
// DWORD dwMasterID
#define RW_GUILDDEL_ACK						(RW_RELAY + 0x0009)
// DWORD dwCharID
// DWORD dwGuildID
#define RW_GUILDCHGMASTER_ACK				(RW_RELAY + 0x000A)
// DWORD dwGuildID
// DWORD dwMasterID
#define RW_CORPSJOIN_ACK					(RW_RELAY + 0x000B)
// WORD wPartyID
// WORD wCorpsID
// WORD wCommander
#define RW_RELAYCONNECT_REQ					(RW_RELAY + 0x000C)
// DWORD dwCharID
#define RW_CHANGENAME_ACK					(RW_RELAY + 0x000D)
// DWORD dwCharID
// STRING strName
#define RW_TACTICSADD_ACK					(RW_RELAY + 0x000E)
#define RW_TACTICSDEL_ACK					(RW_RELAY + 0x000F)
#define RW_CHATBAN_ACK						(RW_RELAY + 0x0010)
// CString strName
// WORD wMinute
#define RW_CHANGEMAP_ACK					(RW_RELAY + 0x0011)
