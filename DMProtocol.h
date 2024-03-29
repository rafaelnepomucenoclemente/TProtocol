#pragma once

#include "ProtocolBase.h"


//////////////////////////////////////////////////////////////////////
// Database message Protocol

#define DM_ENTERMAPSVR_REQ				(DM_BASE + 0x0001)
// DWORD dwUserID		: User ID
// DWORD dwCharID		: Char ID
// DWORD dwKEY			: Enter key
// DWORD dwIPAddr		: IP address
// WORD wPort			: Port
// BYTE bChannel		: Channel ID

#define DM_ENTERMAPSVR_ACK				(DM_BASE + 0x0002)
// DWORD dwCharID		: Char ID
// DWORD dwKEY			: Enter key
// BYTE bResult			: enum TCONNECT_RESULT value

#define DM_LOADCHAR_REQ					(DM_BASE + 0x0003)
// DWORD dwCharID		: Char ID
// DWORD dwKEY			: Enter key

#define DM_LOADCHAR_ACK					(DM_BASE + 0x0004)
// DWORD dwCharID		: Character ID
// DWORD dwKEY			: Enter key
// BYTE bResult			: enum TCONNECT_RESULT value
// STRING strNAME		: Character name
// BYTE bClass			: Class
// BYTE bLevel			: Level
// BYTE bRace			: Race
// BYTE bSex			: Sex
// BYTE bHair			: Hair
// BYTE bFace			: Face
// BYTE bBody			: Body
// BYTE bPants			: Pants
// BYTE bHand			: Hand
// BYTE bFoot			: Foot
// DWORD dwGold			: Gold
// DWORD dwSilver		: Silver
// DWORD dwCooper		: Cooper
// DWORD dwEXP			: Current EXP
// DWORD dwHP			: Current HP
// DWORD dwMP			: Current MP
// WORD wMapID			: Current map ID
// WORD wPosX			: Position X
// WORD wPosY			: Position Y
// WORD wPosZ			: Position Z
// BYTE bInvenCount		: Inven Count
// {
// BYTE bInvenID		: Inven ID
// WORD wItemID			: Inven item ID
// BYTE bItemCount		: Item Count
// {
// BYTE bItemID			: Item ID
// WORD wItemID			: Item Template ID
// BYTE bCount			: Item Count
// {TMAGIC_MAX
// BYTE bMagicID
// WORD wValue
// DWORD dwTime
// }
// }
// }

#define DM_ROUTE_REQ					(DM_BASE + 0x0005)
// DWORD dwCharID		: Char ID
// DWORD dwKEY			: Enter key
// BYTE bCount
// {
// BYTE bServerID
// }

#define DM_ROUTE_ACK					(DM_BASE + 0x0006)
// DWORD dwCharID		: Char ID
// DWORD dwKEY			: Enter key
// BYTE bCount
// {
// DWORD dwIPAddr
// WORD wPort
// BYTE bServerID
// }

#define DM_SAVECHAR_REQ					(DM_BASE + 0x0007)
// DWORD dwCharID		: Char ID
// DWORD dwKEY			: Enter key
// BYTE bLevel
// DWORD dwGold
// DWORD dwSilver
// DWORD dwCooper
// DWORD dwEXP
// DWORD dwHP
// DWORD dwMP
// WORD wMapID
// WORD wPosX
// WORD wPosY
// WORD wPosZ
// BYTE bInvenCount		: Inven Count
// {
// BYTE bInvenID		: Inven ID
// WORD wItemID			: Inven item ID
// BYTE bItemCount		: Item Count
// {
// BYTE bItemID			: Item ID
// WORD wItemID			: Item Template ID
// BYTE bCount			: Item Count
// BYTE bMagicCount		: Magic Count
// {
// BYTE bMagic
// WORD wValue
// DWORD dwTime
// }
// }
// }
// WORD wACKMsg			: Expected acknowledge message (see remark)
// =======================================
// Remark : wACKMsg
// =======================================
// wACKMsg must be following format and executed on BATCH thread
// DWORD dwCharID
// DWORD dwKEY

#define DM_LOGOUT_REQ					(DM_BASE + 0x0008)
// DWORD dwCharID		: Char ID
// DWORD dwKEY			: Enter key
// DWORD dwUserID		: User ID
// WORD wACKMsg			: Expected acknowledge message (see remark)
// =======================================
// Remark : wACKMsg
// =======================================
// wACKMsg must be following format and executed on BATCH thread
// DWORD dwCharID
// DWORD dwKEY

#define DM_DORELEASEMAIN_ACK			(DM_BASE + 0x0009)
// DWORD dwCharID
// DWORD dwKEY

#define DM_GUILDUPDATE_REQ				(DM_BASE + 0x000A)
#define DM_GUILDUPDATE_ACK				(DM_BASE + 0x000B)
#define DM_GUILDESTABLISH_REQ			(DM_BASE + 0x000C)
#define DM_GUILDESTABLISH_ACK			(DM_BASE + 0x000D)
#define DM_GUILDDISORGANIZATION_REQ		(DM_BASE + 0x000E)
#define DM_GUILDDISORGANIZATION_ACK		(DM_BASE + 0x000F)
#define DM_CABINETITEM_REQ				(DM_BASE + 0x0010)
#define DM_CABINETITEM_ACK				(DM_BASE + 0x0011)
#define DM_RESETCONNECTION_REQ			(DM_BASE + 0x0012)
#define DM_RESETCONNECTION_ACK			(DM_BASE + 0x0013)
#define DM_RESETCONNROUTE_REQ			(DM_BASE + 0x0014)
#define DM_RESETCONNROUTE_ACK			(DM_BASE + 0x0015)
#define DM_FRIENDLIST_REQ				(DM_BASE + 0x0016)
#define DM_FRIENDLIST_ACK				(DM_BASE + 0x0017)
#define DM_FRIENDINSERT_REQ				(DM_BASE + 0x0018)
#define DM_FRIENDERASE_REQ				(DM_BASE + 0x0019)
#define DM_POSTLIST_REQ					(DM_BASE + 0x001A)
#define DM_POSTLIST_ACK					(DM_BASE + 0x001B)
#define DM_LOCALOCCUPY_REQ				(DM_BASE + 0x001C)
#define DM_LOCALOCCUPY_ACK				(DM_BASE + 0x001D)
#define DM_FRIENDGROUPMAKE_REQ			(DM_BASE + 0x001E)
#define DM_FRIENDGROUPMAKE_ACK			(DM_BASE + 0x001F)
#define DM_FRIENDGROUPDELETE_REQ		(DM_BASE + 0x0020)
#define DM_FRIENDGROUPCHANGE_REQ		(DM_BASE + 0x0021)
#define DM_FRIENDGROUPNAME_REQ			(DM_BASE + 0x0022)
#define DM_POSTRECV_REQ					(DM_BASE + 0x0023)
#define DM_POSTRECV_ACK					(DM_BASE + 0x0024)
#define DM_POSTCANSEND_REQ				(DM_BASE + 0x0025)
#define DM_POSTCANSEND_ACK				(DM_BASE + 0x0026)
#define DM_LOCALINFO_REQ				(DM_BASE + 0x0027)
#define DM_LOCALINFO_ACK				(DM_BASE + 0x0028)

#define DM_POSTDEL_REQ					(DM_BASE + 0x002B)
#define DM_POSTGETITEM_REQ				(DM_BASE + 0x002C)
#define DM_CLEARCURRENTUSER_REQ			(DM_BASE + 0x002D)
#define DM_CREATERECALLMON_REQ			(DM_BASE + 0x002E)
#define DM_CREATERECALLMON_ACK			(DM_BASE + 0x002F)
#define DM_CASTLEOCCUPY_REQ				(DM_BASE + 0x0030)
#define DM_CASTLEOCCUPY_ACK				(DM_BASE + 0x0031)
#define DM_TELEPORT_REQ					(DM_BASE + 0x0032)
#define DM_TELEPORT_ACK					(DM_BASE + 0x0033)
#define DM_RECALLMONDEL_REQ				(DM_BASE + 0x0034)
#define DM_PROTECTEDADD_REQ				(DM_BASE + 0x0035)
#define DM_PROTECTEDADD_ACK				(DM_BASE + 0x0036)
#define DM_PROTECTEDERASE_REQ			(DM_BASE + 0x0037)
#define DM_PROTECTEDLIST_REQ			(DM_BASE + 0x0038)
#define DM_PROTECTEDLIST_ACK			(DM_BASE + 0x0039)
#define DM_CLEARCURRENTUSER_ACK			(DM_BASE + 0x003A)
#define DM_GUILDLEAVE_REQ				(DM_BASE + 0x003B)
#define DM_GUILDEXTINCTION_REQ			(DM_BASE + 0x003C)
#define DM_GUILDEXTINCTION_ACK			(DM_BASE + 0x003D)
#define DM_GUILDKICKOUT_REQ				(DM_BASE + 0x003E)
#define DM_LOGITEM_REQ					(DM_BASE + 0x003F)
#define DM_LOGSKILL_REQ					(DM_BASE + 0x0040)
#define DM_PETDEL_REQ					(DM_BASE + 0x0041)
#define DM_UDPLOG_REQ					(DM_BASE + 0x0042)
#define DM_SMSSEND_REQ					(DM_BASE + 0x0043)
#define DM_SMSSEND_ACK					(DM_BASE + 0x0044)

#define DM_GUILDDUTY_REQ				(DM_BASE + 0x0045)
#define DM_GUILDPEER_REQ				(DM_BASE + 0x0046)
#define DM_GUILDMEMBERADD_REQ			(DM_BASE + 0x0047)
#define DM_GUILDARTICLEADD_REQ			(DM_BASE + 0x0048)
#define DM_GUILDARTICLEDEL_REQ			(DM_BASE + 0x0049)
#define DM_GUILDFAME_REQ				(DM_BASE + 0x004A)
#define DM_GUILDLEVEL_REQ				(DM_BASE + 0x004B)
#define DM_GUILDCONTRIBUTION_REQ		(DM_BASE + 0x004C)
#define DM_GUILDCABINETPUTIN_REQ		(DM_BASE + 0x004D)
#define DM_GUILDCABINETPUTIN_ACK		(DM_BASE + 0x004E)
#define DM_GUILDCABINETTAKEOUT_REQ		(DM_BASE + 0x004F)
#define DM_GUILDCABINETTAKEOUT_ACK		(DM_BASE + 0x0050)
#define DM_GUILDCABINETROLLBACK_REQ		(DM_BASE + 0x0051)

#define DM_SAVEITEM_REQ					(DM_BASE + 0x0055)
#define DM_GUILDARTICLEUPDATE_REQ		(DM_BASE + 0x0056)
#define DM_GUILDCABINETMAX_REQ			(DM_BASE + 0x0057)

#define DM_EVENTQUARTER_REQ				(DM_BASE + 0x0058)

#define DM_SAVEEXP_REQ					(DM_BASE + 0x0059)
#define DM_SAVEMONEY_REQ				(DM_BASE + 0x005A)

#define DM_CASHITEMCABINET_REQ			(DM_BASE + 0x005B)
#define DM_CASHITEMCABINET_ACK			(DM_BASE + 0x005C)
#define DM_CASHITEMGET_REQ				(DM_BASE + 0x005D)
#define DM_CASHITEMGET_ACK				(DM_BASE + 0x005E)
#define DM_CASHSHOPITEMLIST_REQ			(DM_BASE + 0x005F)
#define DM_CASHSHOPITEMLIST_ACK			(DM_BASE + 0x0060)
#define DM_CASHITEMBUY_REQ				(DM_BASE + 0x0061)
#define DM_CASHITEMBUY_ACK				(DM_BASE + 0x0062)

#define DM_SOULMATELIST_REQ				(DM_BASE + 0x0063)
#define DM_SOULMATELIST_ACK				(DM_BASE + 0x0064)

#define DM_SOULMATEREG_REQ				(DM_BASE + 0x0065)
#define DM_SOULMATEEND_REQ				(DM_BASE + 0x0066)
#define DM_SOULMATEDEL_REQ				(DM_BASE + 0x0067)

#define DM_GUILDLOAD_REQ				(DM_BASE + 0x0068)
#define DM_GUILDLOAD_ACK				(DM_BASE + 0x0069)
#define DM_ACTEND_REQ					(DM_BASE + 0x006A)
#define DM_CASHCABINETBUY_REQ			(DM_BASE + 0x006B)
#define DM_CASHCABINETBUY_ACK			(DM_BASE + 0x006C)
#define DM_CASHITEMPUTIN_REQ			(DM_BASE + 0x006D)
#define DM_CASHITEMPUTIN_ACK			(DM_BASE + 0x006E)
#define DM_DELETEDEALITEM_REQ			(DM_BASE + 0x006F)
#define DM_POSTINVENITEM_REQ			(DM_BASE + 0x0070)
#define DM_POSTINVENITEM_ACK			(DM_BASE + 0x0071)

#define DM_SAVECHARBASE_REQ				(DM_BASE + 0x0072)
#define DM_CHECKCHANGENAME_REQ			(DM_BASE + 0x0073)
#define DM_CHECKCHANGENAME_ACK			(DM_BASE + 0x0074)
#define DM_STOPTHECLOCK_REQ				(DM_BASE + 0x0075)
#define DM_STOPTHECLOCK_ACK				(DM_BASE + 0x0076)

#define DM_RESERVEDPOSTSEND_REQ			(DM_BASE + 0x0077)  
#define DM_RESERVEDPOSTRECV_ACK			(DM_BASE + 0x0078)  
#define DM_HEROSELECT_REQ				(DM_BASE + 0x0079) 
#define DM_HEROSELECT_ACK				(DM_BASE + 0x007A) 
#define DM_CLEARMAPCURRENTUSER_REQ		(DM_BASE + 0x007B)

#define DM_SOULMATEREG_ACK				(DM_BASE + 0x007C)
#define DM_SOULMATEEND_ACK				(DM_BASE + 0x007D)
#define DM_SOULMATEDEL_ACK				(DM_BASE + 0x007E)
#define DM_FRIENDERASE_ACK				(DM_BASE + 0x007F)

#define DM_QUESTSENDPOST_REQ			(DM_BASE + 0x0080)

#define DM_ITEMFIND_REQ					(DM_BASE + 0x0081)
#define DM_ITEMSTATE_REQ				(DM_BASE + 0x0082)
#define DM_ITEMSTATE_ACK				(DM_BASE + 0x0083)
#define DM_GUILDPVPOINT_REQ				(DM_BASE + 0x0084)
#define DM_GUILDPOINTREWARD_REQ			(DM_BASE + 0x0085)
#define DM_PVPRECORD_REQ				(DM_BASE + 0x0086)
#define DM_CASTLEAPPLY_REQ				(DM_BASE + 0x0087)
#define DM_LOADPOSTMESSAGE_REQ			(DM_BASE + 0x0088)
#define DM_LOADPOSTMESSAGE_ACK			(DM_BASE + 0x0089)
#define DM_CASHITEMSALE_REQ				(DM_BASE + 0x008A)
#define DM_CASHITEMSALE_ACK				(DM_BASE + 0x008B)

#define DM_AUCTIONREG_REQ				(DM_BASE + 0x008C)
#define DM_AUCTIONREG_ACK				(DM_BASE + 0x008D)
#define DM_AUCTIONEND_REQ				(DM_BASE + 0x008E)
#define DM_AUCTIONEND_ACK				(DM_BASE + 0x008F)
#define DM_AUCTIONREGCANCEL_REQ			(DM_BASE + 0x0090)
#define DM_AUCTIONREGCANCEL_ACK			(DM_BASE + 0x0091)
#define DM_AUCTIONBID_REQ				(DM_BASE + 0x0092)
#define DM_AUCTIONBID_ACK				(DM_BASE + 0x0093)
#define DM_AUCTIONBUYDIRECT_REQ			(DM_BASE + 0x0094)
#define DM_AUCTIONBUYDIRECT_ACK			(DM_BASE + 0x0095)

#define DM_GUILDWANTEDADD_REQ			(DM_BASE + 0x0096)
#define DM_GUILDWANTEDDEL_REQ			(DM_BASE + 0x0097)
#define DM_GUILDVOLUNTEERING_REQ		(DM_BASE + 0x0098)
#define DM_GUILDVOLUNTEERINGDEL_REQ		(DM_BASE + 0x0099)
#define DM_GUILDTACTICSWANTEDADD_REQ	(DM_BASE + 0x009A)
#define DM_GUILDTACTICSWANTEDDEL_REQ	(DM_BASE + 0x009B)
#define DM_GUILDTACTICSADD_REQ			(DM_BASE + 0x009C)
#define DM_GUILDTACTICSADD_ACK			(DM_BASE + 0x009D)
#define DM_GUILDTACTICSDEL_REQ			(DM_BASE + 0x009E)
#define DM_GUILDTACTICSDEL_ACK			(DM_BASE + 0x009F)
#define DM_TACTICSPOINT_REQ				(DM_BASE + 0x00A0)
#define DM_GAINCASHBONUS_REQ			(DM_BASE + 0x00A1)
#define DM_GAINCASHBONUS_ACK			(DM_BASE + 0x00A2)

#define DM_MONTHRANKSAVE_REQ			(DM_BASE + 0x00A3)
#define DM_MONTHRANKSAVE_ACK			(DM_BASE + 0x00A4)
#define DM_WARLORDSAY_REQ				(DM_BASE + 0x00A5)
#define DM_WARLORDSAY_ACK				(DM_BASE + 0x00A6)

#define DM_CLEARDATA_REQ				(DM_BASE + 0x00A7)
#define DM_CLEARDATA_ACK				(DM_BASE + 0x00A8)
 
#define DM_EVENTQUARTERLIST_REQ			(DM_BASE + 0x00A9)
#define DM_EVENTQUARTERLIST_ACK			(DM_BASE + 0x00AA)
#define DM_EVENTQUARTERUPDATE_REQ		(DM_BASE + 0x00AB)
#define DM_EVENTQUARTERUPDATE_ACK		(DM_BASE + 0x00AC)

#define DM_MONTHPVPOINTRESET_REQ		(DM_BASE + 0x00AD)
#define DM_POSTVIEW_REQ					(DM_BASE + 0x00AE)
#define DM_POSTVIEW_ACK					(DM_BASE + 0x00AF)
#define DM_POSTDEL_ACK					(DM_BASE + 0x00B0)
#define DM_POSTBILL_REQ					(DM_BASE + 0x00B1)
#define DM_POSTBILLUPDATE_REQ			(DM_BASE + 0x00B2)
#define DM_POSTBILLUPDATE_ACK			(DM_BASE + 0x00B3)

#define DM_GETCHARINFO_REQ				(DM_BASE + 0x00B3)
#define DM_GETCHARINFO_ACK				(DM_BASE + 0x00B4)
#define DM_TOURNAMENTPAYBACK_REQ		(DM_BASE + 0x00B5)
#define DM_TOURNAMENTPAYBACK_ACK		(DM_BASE + 0x00B6)
#define DM_TOURNAMENTRESULT_REQ			(DM_BASE + 0x00B7)
#define DM_TOURNAMENTREWARD_REQ			(DM_BASE + 0x00B8)
#define DM_TOURNAMENTREWARD_ACK			(DM_BASE + 0x00B9)
#define DM_TOURNAMENTAPPLY_REQ			(DM_BASE + 0x00BA)
#define DM_TOURNAMENTCLEAR_REQ			(DM_BASE + 0x00BB)
#define DM_TOURNAMENTEVENTCHARINFO_REQ	(DM_BASE + 0x00BC)
#define DM_TNMTEVENTSCHEDULEADD_REQ		(DM_BASE + 0x00BD)
#define DM_TNMTEVENTSCHEDULEDEL_REQ		(DM_BASE + 0x00BE)
#define DM_TNMTEVENTENTRYADD_REQ		(DM_BASE + 0x00BF)
#define DM_SAVECHARPOSITION_REQ			(DM_BASE + 0x00C0)
#define DM_SAVECHARPOSITION_ACK			(DM_BASE + 0x00C1)
#define DM_HELPMESSAGE_REQ				(DM_BASE + 0x00C2)

#define DM_MISSIONOCCUPY_REQ			(DM_BASE + 0x00C3)
#define DM_MISSIONOCCUPY_ACK			(DM_BASE + 0x00C4)
#define DM_RPSGAMERECORD_REQ			(DM_BASE + 0x00C5)

#define DM_TOURNAMENTSTATUS_REQ			(DM_BASE + 0x00C6)
#define DM_ACTIVECHARUPDATE_REQ			(DM_BASE + 0x00C7)
#define DM_ACTIVECHARUPDATE_ACK			(DM_BASE + 0x00C8)

#define DM_CMGIFT_REQ					(DM_BASE + 0x00C9)
#define DM_CMGIFT_ACK					(DM_BASE + 0x00CA)
#define DM_CMGIFTLOG_REQ				(DM_BASE + 0x00CB)
#define DM_CMGIFTCHARTUPDATE_REQ		(DM_BASE + 0x00CC)
#define DM_CMGIFTCHARTUPDATE_ACK		(DM_BASE + 0x00CD)

#define DM_SKYGARDENOCCUPY_REQ			(DM_BASE + 0x00CE)
#define DM_SKYGARDENOCCUPY_ACK			(DM_BASE + 0x00CF)

