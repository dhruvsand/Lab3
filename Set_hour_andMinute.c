


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

int set_Minute(void){
	minute = 0;
	while(PB0 == 0x00){
		if (PB1 == 0x01){
			minute = abs(minute - 1);
			
			if(minute == 0){
				minute = 60;
			}
		}
		if(PB2 == 0x02){
			minute = abs(minute + 1) % 60;
			if(minute == 0){
				minute = 1;
			}
		}
	
		
		
		
	}
}
int set_Hour(){
hour = 0;
	while(PB0 == 0x00){
		if (PB1 == 0x01){
			hour = abs(hour - 1);
			
			if(hour == 0){
				hour = 12;
			}
		}
		if(PB2 == 0x02){
			minute = abs(hour + 1) % 12;
			if(hour == 0){
				hour = 1;
			}
		}
	
		
		
		
	}
}
void Set_Timer(void){
	int set_minute_flag;
	int set_hour_flag;
	
	set_Hour();
	set_Minute();
}
	

}
	
