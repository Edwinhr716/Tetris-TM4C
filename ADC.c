// ADC.c
// Runs on LM4F120/TM4C123
// Provide functions that initialize ADC0
// Student names: change this to your names or look very silly
// Last modification date: change this to the last modification date or look very silly

#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"

// ADC initialization function 
// Input: none
// Output: none
// measures from PD2, analog channel 5
//void ADC_Init(void){  uint32_t delay;
//	SYSCTL_RCGCADC_R |= 0x0001;
//	SYSCTL_RCGCSSI_R |= 0x01;
//	delay = SYSCTL_RCGCADC_R;
//	delay = SYSCTL_RCGCADC_R;
//	delay = SYSCTL_RCGCADC_R;
//	SYSCTL_RCGCGPIO_R |= 0x08;
//	while((SYSCTL_PRGPIO_R&0x08) != 0x08){}
//	GPIO_PORTD_DIR_R &= ~0x06;
//	GPIO_PORTD_AFSEL_R |= 0x06;
//	GPIO_PORTD_DEN_R &= ~0x06;
//	GPIO_PORTD_AMSEL_R |= 0x06;
//	

//	ADC0_PC_R &= ~0xF;
//	ADC0_PC_R |= 0x01; //Configures for 125k (Speed)
//	ADC0_SSPRI_R = 0x3210; //Sets priority in each of the Sequences, 3 for SEQ0, 2 fro SEQ1, 1 for SEQ2, and 0 for SEQ3
//	ADC0_ACTSS_R &= ~0x0004;// Disable sequencer for now
//	ADC0_EMUX_R &= ~0xF000; //Set bits 15-12 to zero, to say that it is a software trigger
//	ADC0_SSMUX2_R = (ADC0_SSMUX2_R&0xFFFFFF00) + 0x56; //Set channel number to 5
//	ADC0_SSCTL2_R = 0x0060; //No temperature sensor, END0 (bit 1) set 1 (on sampling, set flag), bit 2 says only 1 sample
//	ADC0_IM_R &= ~0x0004;
//	ADC0_ACTSS_R |= 0x0004;	//Enable sequencer3 
//	


//}

////------------ADC_In------------
//// Busy-wait Analog to digital conversion
//// Input: none
//// Output: 12-bit result of ADC conversion
//// measures from PD2, analog channel 5
//void ADC_In2(uint32_t data[2]){ 
//	ADC0_PSSI_R = 0x0004; //Start ADC 
//	while((ADC0_RIS_R & 0x04)==0){}; //Busy wait synchronization, and its waiting for when the ADC conversion is complete
//	data[0] = ADC0_SSFIFO2_R &0xFFF;//PD1
//	data[1] = ADC0_SSFIFO2_R &0xFFF;//PD2
//	ADC0_ISC_R = 0x0004; //Clears flag
//}

void ADC_Init(void){ uint32_t delay;
	SYSCTL_RCGCADC_R |= 0x0001;
	SYSCTL_RCGCSSI_R |= 0x01;
	delay = SYSCTL_RCGCADC_R;
	delay = SYSCTL_RCGCADC_R;
	delay = SYSCTL_RCGCADC_R;
	SYSCTL_RCGCGPIO_R |= 0x08;
	while((SYSCTL_PRGPIO_R&0x08) != 0x08){}
	GPIO_PORTD_DIR_R &= ~0x08;
	GPIO_PORTD_AFSEL_R |= 0x08;
	GPIO_PORTD_DEN_R &= ~0x08;
	GPIO_PORTD_AMSEL_R |= 0x08;
	

	ADC0_PC_R &= ~0xF;
	ADC0_PC_R |= 0x01; //Configures for 125k (Speed)
	ADC0_SSPRI_R = 0x123; //Sets priority in each of the Sequences, 3 for SEQ0, 2 fro SEQ1, 1 for SEQ2, and 0 for SEQ3
	ADC0_ACTSS_R &= ~0x0008;// Disable sequencer for now
	ADC0_EMUX_R &= ~0xF000; //Set bits 15-12 to zero, to say that it is a software trigger
	ADC0_SSMUX3_R = (ADC0_SSMUX3_R&0xFFFFFFF0) + 5; //Set channel number to 5
	ADC0_SSCTL3_R = 0x006; //No temperature sensor, END0 (bit 1) set 1 (on sampling, set flag), bit 2 says only 1 sample
	ADC0_IM_R &= ~0x0008;
	ADC0_ACTSS_R |= 0x0008;	//Enable sequencer3 
	

}

//------------ADC_In------------
// Busy-wait Analog to digital conversion
// Input: none
// Output: 12-bit result of ADC conversion
// measures from PD2, analog channel 5
uint32_t ADC_In(void){  uint32_t data;
	ADC0_PSSI_R = 0x0008; //Start ADC 
	while((ADC0_RIS_R & 0x08)==0){}; //Busy wait synchronization, and its waiting for when the ADC conversion is complete
	data = ADC0_SSFIFO3_R &0xFFF;
	ADC0_ISC_R = 0x0008; //Clears flag

  return data; // remove this, replace with real code
}

