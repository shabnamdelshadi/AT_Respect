#ifndef __AT_RESPECT_DIAG_H
#define __AT_RESPECT_DIAG_H

#include "rayanmessage.h"
#include "Algorithm.h"

class AT_Respect_Diag : public BaseAlgorithm
{
public:
	virtual bool InternalSwitchCase(CommandAdorner* Command);
	const static u16 Class_ID;
	AT_Respect_Diag(void);
	~AT_Respect_Diag(void);

	bool ATDTC(CommandAdorner* Command);
	bool Clear_Adapt_Value(CommandAdorner* Command);
	bool Eol_Range_Sensor(CommandAdorner* Command);
	bool Clear_System_Fault(CommandAdorner* Command);
	bool SBW_Self_Tuning(CommandAdorner* Command);
	bool Delay_Actuator(CommandAdorner* Command);
private:
	bool delay_exitsuported(u32 delay, char* msg, bool show_timer);
	
};
#endif //__AT_Respect_Diag_H
