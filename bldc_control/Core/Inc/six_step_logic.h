

#ifndef INC_SIX_STEP_LOGIC_H_
#define INC_SIX_STEP_LOGIC_H_


int get_hall_pattern(void);

int hall_2_sector(int hallpatern);

int sector_2_vector(int sector);

int vector_2_gpio(int voltagevector);

void set_output_gpio(int bitmask);

// bool check_hall_pattern(int hallpatern);

#endif /* INC_SIX_STEP_LOGIC_H_ */



