void alarm_call(void){
	int port_b_check;
	port_b_check = PB3;
	if(PB3 == 0x08){
		PB3 = 0x00;
	else{
		PB3 = 0x08;
	}
	
}
void Timer0A_Handler(void){
  TIMER0_ICR_R = TIMER_ICR_TATOCINT;    // acknowledge timer0A timeout
  PF2 ^= 0x04;                   // profile
  PF2 ^= 0x04;                   // profile

	
  PF2 ^= 0x04;                   // profile
	
	if(snooze_counter < 10 && snooze_flag ==0){
		snooze_counter = snooze_counter + 1;
	}
	if(snooze_counter == 10){
		snooze_counter = 0;
		snooze_flag = 0;
		alarm_on_flag = 1;
	}
	if(alarm_flag== 1){
		TIMER0_TAILR_R = 199999; //about 4 HZ
		alarm_call();
	}
	else{
		TIMER0_TAILR_R = 799999;
	}
	
	
}
	
