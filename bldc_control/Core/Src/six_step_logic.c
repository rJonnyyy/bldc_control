#include "six_step_logic.h"

/* aktuelles hallpattern einlesen */
uint8_t get_hall_pattern(void) {
	uint32_t idr = HALL_PORT->IDR;
	uint8_t h1 = (idr >> HALL_1_PIN) & 1u;
	uint8_t h2 = (idr >> HALL_2_PIN) & 1u;
	uint8_t h3 = (idr >> HALL_3_PIN) & 1u;
	return (uint8_t) ((h3<<2)|(h2<<1)|h1);
}


/* Aktuelles hallpattern -> Sektor bestimmen */
uint8_t hall_2_sector(uint8_t hallpattern) {
    static const uint8_t sector_lut[8] = {
    		0, /*000-0*/
			1, /*001-1*/
			5, /*010-2*/
			6, /*011-3*/
			3, /*100-4*/
			2, /*101-5*/
 			4, /*110-6*/
			0  /*111-7*/
    }; // muss angepasst werden, das hallpattern (also z.B. die Zahl 2-010) ist hier der index ! an den jeweiligen Eintrag muss dann die entsprechende Sektornummer geschrieben werden
    hallpattern = hallpattern & 0x07;
    uint8_t sector = sector_lut[hallpattern];
    return sector;
}



/* bisschen unnötig ein neuen Datentyp einzuführen usw */
/* sector -> nächsten notwendigen Vektor bestimmen - Drehrichtung hat hier auch was zu sagen aber lass mal gut sein */
/* wenn Sektor 1: BC stellen - nur eine Drehrichtung bisher - Abhängig, wo man Sektor 1 definiert. */
/*
phase_vec_t sector_2_vector(uint8_t sector) {
    phase_vec_t vv = {0};
    switch (sector) {
        case 1: vv.B_pos=1; vv.C_neg=1; break; // 1: BC
        case 2: vv.B_pos=1; vv.A_neg=1; break; // 2: BA
        case 3: vv.C_pos=1; vv.A_neg=1; break; // 3: CA
        case 4: vv.C_pos=1; vv.B_neg=1; break; // 4: CB
        case 5: vv.A_pos=1; vv.B_neg=1; break; // 5: AB
        case 6: vv.A_pos=1; vv.C_neg=1; break; // 6: AC
        default:  break; // alles null
    }
    return vv;
} */












gpio_vec_t vector_2_gpio(const phase_vec_t *v);
void set_output_gpio(const gpio_vec_t *g);
void six_step_sequence(void);
void disable_mosfets(void);
