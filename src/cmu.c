//***********************************************************************************
// Include files
//***********************************************************************************
#include "cmu.h"

//***********************************************************************************
// defined files
//***********************************************************************************


//***********************************************************************************
// global variables
//***********************************************************************************


//***********************************************************************************
// prototypes
//***********************************************************************************
void cmu_open(void){
	CMU_OscillatorEnable(cmuOsc_HFRCO, true, true);
	CMU_HFRCOBandSet(cmuHFRCOFreq_38M0Hz);
	EFM_ASSERT(CMU_HFRCOFreqGet() == cmuHFRCOFreq_38M0Hz);
	CMU_ClockEnable(cmuClock_HFPER, true);
	CMU_ClockEnable(cmuClock_CORELE, true);
}

