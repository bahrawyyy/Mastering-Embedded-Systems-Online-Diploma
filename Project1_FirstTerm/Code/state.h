#ifndef _STATE_H_
#define _STATE_H_




// Definition of states
// To be used in further blocks and states



#define STATE_Define(_stateFunc_) void ST_##_stateFunc_()
#define STATE(_stateFunc_) ST_##_stateFunc_

// States Connections
void SET_Pressure_Val(int PressureVal);
void High_Pressure_Detect(int Val);



#endif