#include "AT_Respect_Diag.h"
#include "MSG_AT_Respect_Diag.h"
#include "ArrayTools.h"
#include "OtherHeader\AT_Respect_Diag_OH.h"

AT_Respect_Diag::AT_Respect_Diag(void)
{
}
AT_Respect_Diag::~AT_Respect_Diag(void)
{
}
//////////////////////////////////////////////////////////////////
bool AT_Respect_Diag::Clear_Adapt_Value(CommandAdorner* Command)
{
		byte response[255]={};
		OBDii.Security_Pass(Command, 1);
		byte SessionFrame[2] = { 0x10, 0x03 };
		OBDii.Send_Receive(sizeof(SessionFrame), SessionFrame, response, sizeof(response));
		OnShowMessage_Messages(ATRespectDiag_conditions, Yes_No, true);
		byte Routine1[4] = { 0x31, 0x01, 0x0B, 0x61 };
		if ((OBDii.Send_Receive(sizeof(Routine1), Routine1, response, sizeof(response)) == NULL) || (response[0] == 0x7F))
			{
				return false; 
			}
		Sleep(500);
		byte Routine2[4] = { 0x31, 0x03, 0x0B, 0x61 };
		if ((OBDii.Send_Receive(sizeof(Routine2), Routine2, response, sizeof(response)) == NULL) || (response[4] != 0x02))
			{
				return false; 
			} 
		Sleep(500); 
		OnShowMessage_Messages(ATRespectDiag_closed_wait, Yes_No, true);
		return true;	 	  
}
////////////////////////////////////////////////////////////////////
bool AT_Respect_Diag::Eol_Range_Sensor(CommandAdorner* Command)
{
	  byte response[255]={};
		OBDii.Security_Pass(Command, 1);
	  byte SessionFrame1[2] = { 0x10, 0x03 };
		OBDii.Send_Receive(sizeof(SessionFrame1),SessionFrame1,response, sizeof(response));
		if(!OnShowMessage_Messages(ATRespectDiag_conditions, Yes_No, true))
			return false;
		byte Routine11[5] = { 0x31, 0x01, 0x0B, 0x62, 0x01 };
		if ((OBDii.Send_Receive(sizeof(Routine11), Routine11, response, sizeof(response)) == NULL) || (response[0] == 0x7F))
			{
				return false; 
			}
		Sleep(500);
		byte Routine21[5] = { 0x31, 0x03, 0x0B, 0x62, 0x01 };
		if ((OBDii.Send_Receive(sizeof(Routine21), Routine21, response, sizeof(response)) == NULL) || (response[4] != 0x02))
		{
			return false; 
		} 
		if(!OnShowMessage_Messages(ATRespectDiag_GearSensor_P_defined_successfully,Yes_No, true))
			return false;
		Sleep(500); 
		byte SessionFrame2[2] = { 0x10, 0x03 };
		OBDii.Send_Receive(sizeof(SessionFrame2),SessionFrame2,response, sizeof(response));
		if(!OnShowMessage_Messages(ATRespectDiag_conditions1, Yes_No, true))
			return false;
		byte Routine12[5] = { 0x31, 0x01, 0x0B, 0x62, 0x02 };
		OBDii.Send_Receive(sizeof(Routine12), Routine12, response, sizeof(response));
		if ((OBDii.Send_Receive(sizeof(Routine12), Routine12, response, sizeof(response)) == NULL) || (response[0] == 0x7F))
			{
				return false; 
			}
		Sleep(500);
		byte Routine22[5] = { 0x31, 0x03, 0x0B, 0x62, 0x02 };
		if ((OBDii.Send_Receive(sizeof(Routine22), Routine22, response, sizeof(response)) == NULL) || (response[4] != 0x02))
		{
			return false; 
		} 
		OnShowMessage_Messages(ATRespectDiag_GearSensor_R_defined_successfully,Yes_No, true);
		Sleep(500); 
		byte SessionFrame3[2] = { 0x10, 0x03 };
		OBDii.Send_Receive(sizeof(SessionFrame3),SessionFrame3,response, sizeof(response));
		if(!OnShowMessage_Messages(ATRespectDiag_conditions2, Yes_No, true))
			return false;
		byte Routine13[5] = { 0x31, 0x01, 0x0B, 0x62, 0x03 };
		if ((OBDii.Send_Receive(sizeof(Routine13), Routine13, response, sizeof(response)) == NULL) || (response[0] == 0x7F))
			{
				return false; 
			}
		Sleep(500);
		byte Routine23[5] = { 0x31, 0x03, 0x0B, 0x62, 0x03 };
		if ((OBDii.Send_Receive(sizeof(Routine23), Routine23, response, sizeof(response)) == NULL) || (response[4] != 0x02))
		{
			return false; 
		} 
		if(!OnShowMessage_Messages(ATRespectDiag_GearSensor_N_defined_successfully,Yes_No, true))
			return false;
		Sleep(500); 
		byte SessionFrame4[2] = { 0x10, 0x03 };
		OBDii.Send_Receive(sizeof(SessionFrame4),SessionFrame4,response, sizeof(response));
		if(!OnShowMessage_Messages(ATRespectDiag_conditions3, Yes_No, true))
			return false;
		byte Routine14[5] = { 0x31, 0x01, 0x0B, 0x62, 0x04 };
		if ((OBDii.Send_Receive(sizeof(Routine14), Routine14, response, sizeof(response)) == NULL) || (response[0] == 0x7F))
			{
				return false; 
			}
		Sleep(500);
		
		byte Routine24[5] = { 0x31, 0x03, 0x0B, 0x62, 0x04 };
		if ((OBDii.Send_Receive(sizeof(Routine24), Routine24, response, sizeof(response)) == NULL) || (response[4] != 0x02))
		{
			return false; 
		} 
		if(!OnShowMessage_Messages(ATRespectDiag_GearSensor_D_defined_successfully,Yes_No, true))
			return false;
		Sleep(500); 
		byte SessionFrame5[2] = { 0x10, 0x03 };
		OBDii.Send_Receive(sizeof(SessionFrame5),SessionFrame5,response, sizeof(response));
		if(!OnShowMessage_Messages(ATRespectDiag_conditions4, Yes_No, true))
			return false;
		byte Routine15[5] = { 0x31, 0x01, 0x0B, 0x62, 0x05 };
		if ((OBDii.Send_Receive(sizeof(Routine15), Routine15, response, sizeof(response)) == NULL) || (response[0] == 0x7F))
			{
				return false; 
			}
		Sleep(500);
		byte Routine25[5] = { 0x31, 0x03, 0x0B, 0x62, 0x05 };
		if ((OBDii.Send_Receive(sizeof(Routine25), Routine25, response, sizeof(response)) == NULL) || (response[4] != 0x02))
		{
			return false; 
		} 
		if(!OnShowMessage_Messages(ATRespectDiag_GearSensor_L_defined_successfully,Yes_No, true))
			return false;
		Sleep(500);  
		OnShowMessage_Messages(ATRespectDiag_closed_wait,Yes_No, true);
		return true;
}
///////////////////////////////////////////////////////////////////////////
bool AT_Respect_Diag::Clear_System_Fault(CommandAdorner* Command)
{
	  byte response[255]={};
	  OBDii.Security_Pass(Command, 1);
		if(!OnShowMessage_Messages(ATRespectDiag_conditions, Yes_No, true))
			return false;
		byte SessionFrame[2] = { 0x10, 0x03 };
		OBDii.Send_Receive(sizeof(SessionFrame), SessionFrame, response, sizeof(response));
		byte Routine1[4] = { 0x31, 0x01, 0x0B, 0x63 };
		if ((OBDii.Send_Receive(sizeof(Routine1), Routine1, response, sizeof(response)) == NULL) || (response[0] == 0x7F))
				{
				return false; 
			  }
		Sleep(500);
		byte Routine2[4] = { 0x31, 0x03, 0x0B, 0x63 };
		if ((OBDii.Send_Receive(sizeof(Routine2), Routine2, response, sizeof(response)) == NULL) || (response[4] != 0x02))
			{
				return false; 
			} 
		Sleep(500); 
		OnShowMessage_Messages(ATRespectDiag_closed_wait,Yes_No, true);
		return true;  
}
//////////////////////////////////////////////////////////////////////////  
bool AT_Respect_Diag::SBW_Self_Tuning(CommandAdorner* Command)
{
	  byte response[255]={};
		OBDii.Security_Pass(Command, 1);
	  if(!OnShowMessage_Messages(ATRespectDiag_conditions, Yes_No, true))
			return false;
		byte SessionFrame[2] = { 0x10, 0x03 };
		OBDii.Send_Receive(sizeof(SessionFrame), SessionFrame, response, sizeof(response));        
		byte Routine1[4] = { 0x31, 0x01, 0x0B, 0x65 };
		if ((OBDii.Send_Receive(sizeof(Routine1), Routine1, response, sizeof(response)) == NULL) || (response[0] == 0x7F))
				{
				return false; 
			  }
		Sleep(500);
		byte Routine2[4] = { 0x31, 0x03, 0x0B, 0x65};
		if ((OBDii.Send_Receive(sizeof(Routine2), Routine2, response, sizeof(response)) == NULL) || (response[0] == 0x7F))
			{
				return false; 
			} 
		Sleep(500);
		OnShowMessage_Messages(ATRespectDiag_closed_wait,Yes_No, true); 
		return true;    
}
////////////////////////////////////////////////////////////////////////////////////////////
bool AT_Respect_Diag::ATDTC(CommandAdorner* Command)
{
    byte res[1424] = {};
		OBDii.Security_Pass(Command, 1);
    u8 res_len = 0;
    u32 code = 0;
    u8 send_buff[3] = { 0x19, 0x02, 0xFF };
		FaultCodeAdorner _FaultCodeAdorner;
		
    res_len =  OBDii.Send_Receive(sizeof(send_buff), send_buff, res, sizeof(res));
		
    if ((res_len < 6) || (res[0] == 0x7F))
    {
        Manager.BreakFlag = true;
        Command->State.IsFaulty = true;
        return true;
    }

    for (int i = 3; (i + 3) < res_len; i += 4)
    {
      code = 0;
			code |= (res[i] << 16);
			code |= (res[i + 1] << 8);
			code |= res[i + 2];

        if (code == 0xFFFF || code == 0x0000)
            continue;

        byte state = res[i + 3];

        if (_FaultCodeAdorner.CheckFault(code, state, Command))
        {
           if (((state & 0x09) == 0x09))
            {
                _FaultCodeAdorner.AddFault(code,null,GetDTCCategory(code, Command->DB->FaultCodeLength),GetDTCinCategoryMode(code,Command->DB->FaultCodeLength));
            }
        }
    }

    _FaultCodeAdorner.ShowFaults(Command, true);
   
    return true;
}
