#ifndef INC_SIX_STEP_LOGIC_H_
#define INC_SIX_STEP_LOGIC_H_

#include "stm32f4xx.h"   // oder main.h, falls du HAL verwenden willst

/* Pinbelegungen - ANPASSEN JE NACH HARDWARE VERSCHALTUNG */

#define A_IN_PORT   	GPIOA
#define A_IN_PIN   		8
#define A_INH_PORT    	GPIOB
#define A_INH_PIN     	0

#define B_IN_PORT   	GPIOA
#define B_IN_PIN    	9
#define B_INH_PORT    	GPIOB
#define B_INH_PIN     	1

#define C_IN_PORT   	GPIOA
#define C_IN_PIN    	10
#define C_INH_PORT    	GPIOB
#define C_INH_PIN     	2


#define HALL_PORT     	GPIOC
#define HALL_1_PIN    	10
#define HALL_2_PIN    	11
#define HALL_3_PIN    	12

#define BSRR_SET(pin)      (1u << (pin))
#define BSRR_CLR(pin)      (1u << ((pin) + 16))


/* Datentypen / Strukturen */
typedef struct {
    uint8_t A_pos;
    uint8_t A_neg;
    uint8_t B_pos;
    uint8_t B_neg;
    uint8_t C_pos;
    uint8_t C_neg;
} phase_vec_t;

typedef struct {
    uint32_t bsrrA;
    uint32_t bsrrB;
} gpio_vec_t;


/* Funktionen */
uint8_t get_hall_pattern(void);
uint8_t hall_2_sector(uint8_t hallpattern);
phase_vec_t sector_2_vector(uint8_t sector);
gpio_vec_t vector_2_gpio(const phase_vec_t *v);
void set_output_gpio(const gpio_vec_t *g);
void six_step_sequence(void);
void disable_mosfets(void); // Am Anfang der main einfach einmal aufrufen, dass sicher alles aus ist



// bool check_hall_pattern(int hallpatern);

#endif /* INC_SIX_STEP_LOGIC_H_ */



