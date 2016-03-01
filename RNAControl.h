#ifndef RNAControl_h
#define RNAControl_h

#include "Arduino.h"

#define SAIDAS 4
#define ENTRADAS 2
#define VLR_BIAS 1
#define TX_APR 1
#define EPOCAS 10000
#define CJ_TREIN 49
#define N_OCULTA_1 4
#define N_OCULTA_2 8
#define N_OCULTA_3 5

typedef struct neuronio
{
    float soma;
    float sinal;
} neuron_t;

class RNAControl
{
	public:
		RNAControl();
		void setPitch(float pitch);
		void setRoll(float roll);
		void run();
		float getAileronAngle();
		float getElevatorAngle();
		float getThrottle();

	private:

		//RNA
		neuron_t n_camada_oculta_1[N_OCULTA_1];
		neuron_t n_camada_oculta_2[N_OCULTA_2];
		neuron_t n_camada_oculta_3[N_OCULTA_3];
		neuron_t n_saida[SAIDAS];
		float w_oculta0_oculta1[ENTRADAS + 1][N_OCULTA_1];
		float w_oculta1_oculta2[N_OCULTA_1 + 1][N_OCULTA_2];
		float w_oculta2_oculta3[N_OCULTA_2 + 1][N_OCULTA_3];
		float w_oculta3_oculta4[N_OCULTA_3+1][SAIDAS];

		void propaga_sinal_frente(float v_entradas[ENTRADAS]);
		float f_sigmoid(float x);
		float f_tansigmoid(float x);
		float f_purelin(float x);
		void inicializa_neuronios();
		float erro(float desejado, float saida);
		float random_number();

		//Entradas
		float _pitch;
		float _roll;

		//Saidas
		float _aileronAngle;
		float _elevatorAngle;
		float _throttle;

		void _setup();
};

#endif
