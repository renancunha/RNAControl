#include "Arduino.h"
#include "RNAControl.h"

RNAControl::RNAControl()
{
	_setup();
}

void RNAControl::_setup()
{

	srand(1);
    inicializa_neuronios();

    w_oculta0_oculta1[0][0] = -1.1155;
    w_oculta0_oculta1[0][1] = -1.4654;
    w_oculta0_oculta1[0][2] = -0.83953;
    w_oculta0_oculta1[0][3] = 7.6034;
    w_oculta0_oculta1[1][0] = -0.5907;
    w_oculta0_oculta1[1][1] = 3.6899;
    w_oculta0_oculta1[1][2] = 2.0117;
    w_oculta0_oculta1[1][3] = -6.8423;
    w_oculta0_oculta1[2][0] = 1.3959;
    w_oculta0_oculta1[2][1] = -0.16223;
    w_oculta0_oculta1[2][2] = 0.2818;
    w_oculta0_oculta1[2][3] = 0.020451;
    w_oculta1_oculta2[0][0] = 0.64861;
    w_oculta1_oculta2[0][1] = -2.2437;
    w_oculta1_oculta2[0][2] = 0.31146;
    w_oculta1_oculta2[0][3] = 0.81512;
    w_oculta1_oculta2[0][4] = 5.8125;
    w_oculta1_oculta2[0][5] = 1.1929;
    w_oculta1_oculta2[0][6] = 1.2636;
    w_oculta1_oculta2[0][7] = 1.0341;
    w_oculta1_oculta2[1][0] = 1.9591;
    w_oculta1_oculta2[1][1] = 6.2138;
    w_oculta1_oculta2[1][2] = -0.58394;
    w_oculta1_oculta2[1][3] = 7.222;
    w_oculta1_oculta2[1][4] = -1.2567;
    w_oculta1_oculta2[1][5] = -0.85745;
    w_oculta1_oculta2[1][6] = 1.9892;
    w_oculta1_oculta2[1][7] = 0.14801;
    w_oculta1_oculta2[2][0] = 0.62163;
    w_oculta1_oculta2[2][1] = 1.4042;
    w_oculta1_oculta2[2][2] = -1.0194;
    w_oculta1_oculta2[2][3] = -0.49022;
    w_oculta1_oculta2[2][4] = 5.9143;
    w_oculta1_oculta2[2][5] = -7.3938;
    w_oculta1_oculta2[2][6] = 0.37433;
    w_oculta1_oculta2[2][7] = -1.4166;
    w_oculta1_oculta2[3][0] = -0.13042;
    w_oculta1_oculta2[3][1] = 0.16125;
    w_oculta1_oculta2[3][2] = 2.5369;
    w_oculta1_oculta2[3][3] = 2.0065;
    w_oculta1_oculta2[3][4] = 8.4744;
    w_oculta1_oculta2[3][5] = 1.5455;
    w_oculta1_oculta2[3][6] = 0.16371;
    w_oculta1_oculta2[3][7] = -1.8029;
    w_oculta1_oculta2[4][0] = 0.11875;
    w_oculta1_oculta2[4][1] = 0.55582;
    w_oculta1_oculta2[4][2] = 0.54088;
    w_oculta1_oculta2[4][3] = 3.586;
    w_oculta1_oculta2[4][4] = 4.7505;
    w_oculta1_oculta2[4][5] = 0.040591;
    w_oculta1_oculta2[4][6] = -0.55062;
    w_oculta1_oculta2[4][7] = 4.0282;
    w_oculta2_oculta3[0][0] = 2.61;
    w_oculta2_oculta3[0][1] = 2.3381;
    w_oculta2_oculta3[0][2] = 1.6886;
    w_oculta2_oculta3[0][3] = 0.2385;
    w_oculta2_oculta3[0][4] = 1.4736;
    w_oculta2_oculta3[1][0] = 1.5484;
    w_oculta2_oculta3[1][1] = -0.7589;
    w_oculta2_oculta3[1][2] = 0.78206;
    w_oculta2_oculta3[1][3] = 7.0646;
    w_oculta2_oculta3[1][4] = 0.53614;
    w_oculta2_oculta3[2][0] = -1.7156;
    w_oculta2_oculta3[2][1] = 2.7426;
    w_oculta2_oculta3[2][2] = 0.81698;
    w_oculta2_oculta3[2][3] = 1.0494;
    w_oculta2_oculta3[2][4] = 0.19752;
    w_oculta2_oculta3[3][0] = 2.1809;
    w_oculta2_oculta3[3][1] = -0.059842;
    w_oculta2_oculta3[3][2] = 2.5493;
    w_oculta2_oculta3[3][3] = -0.12249;
    w_oculta2_oculta3[3][4] = 0.58539;
    w_oculta2_oculta3[4][0] = 4.0771;
    w_oculta2_oculta3[4][1] = 0.21717;
    w_oculta2_oculta3[4][2] = 1.8207;
    w_oculta2_oculta3[4][3] = 10.2346;
    w_oculta2_oculta3[4][4] = -0.0021602;
    w_oculta2_oculta3[5][0] = 1.3947;
    w_oculta2_oculta3[5][1] = -0.1111;
    w_oculta2_oculta3[5][2] = -1.9656;
    w_oculta2_oculta3[5][3] = 0.70702;
    w_oculta2_oculta3[5][4] = 2.3384;
    w_oculta2_oculta3[6][0] = 1.6063;
    w_oculta2_oculta3[6][1] = -0.0031496;
    w_oculta2_oculta3[6][2] = 0.26402;
    w_oculta2_oculta3[6][3] = 0.39745;
    w_oculta2_oculta3[6][4] = -0.0044333;
    w_oculta2_oculta3[7][0] = 2.4305;
    w_oculta2_oculta3[7][1] = 1.1176;
    w_oculta2_oculta3[7][2] = -0.93679;
    w_oculta2_oculta3[7][3] = 5.9611;
    w_oculta2_oculta3[7][4] = -0.48149;
    w_oculta2_oculta3[8][0] = 0.629;
    w_oculta2_oculta3[8][1] = -0.58458;
    w_oculta2_oculta3[8][2] = 0.9847;
    w_oculta2_oculta3[8][3] = -0.48328;
    w_oculta2_oculta3[8][4] = -4.2956;
    w_oculta3_oculta4[0][0] = -1.7257;
    w_oculta3_oculta4[0][1] = 5.7257e-16;
    w_oculta3_oculta4[0][2] = -1.7113;
    w_oculta3_oculta4[0][3] = -7.1405e-16;
    w_oculta3_oculta4[1][0] = 0.66295;
    w_oculta3_oculta4[1][1] = -9.5325e-16;
    w_oculta3_oculta4[1][2] = -4.8248;
    w_oculta3_oculta4[1][3] = 9.004e-16;
    w_oculta3_oculta4[2][0] = 1.5226;
    w_oculta3_oculta4[2][1] = -3.6179e-17;
    w_oculta3_oculta4[2][2] = -9.2949;
    w_oculta3_oculta4[2][3] = -4.3571e-17;
    w_oculta3_oculta4[3][0] = 0.40939;
    w_oculta3_oculta4[3][1] = 3.4083e-16;
    w_oculta3_oculta4[3][2] = -1.3476;
    w_oculta3_oculta4[3][3] = -3.0864e-16;
    w_oculta3_oculta4[4][0] = -0.0012828;
    w_oculta3_oculta4[4][1] = -8.3559e-18;
    w_oculta3_oculta4[4][2] = -0.023204;
    w_oculta3_oculta4[4][3] = 5.0403e-17;
    w_oculta3_oculta4[5][0] = -15.553;
    w_oculta3_oculta4[5][1] = 4.944e-17;
    w_oculta3_oculta4[5][2] = -0.36965;
    w_oculta3_oculta4[5][3] = -1.2637e-17;

}

void RNAControl::run()
{
	float entradas[] = {_roll, _pitch};
	propaga_sinal_frente(entradas);

	_aileronAngle = n_saida[0].sinal;
	_elevatorAngle = n_saida[2].sinal;
	_throttle = n_saida[1].sinal;
}

void RNAControl::setPitch(float pitch)
{
	_pitch = pitch;
}

void RNAControl::setRoll(float roll)
{
	_roll = roll;
}

float RNAControl::getThrottle()
{
    return _throttle;
}

float RNAControl::getAileronAngle()
{
    return _aileronAngle;
}

float RNAControl::getElevatorAngle()
{
	return _elevatorAngle;
}

float RNAControl::f_sigmoid(float x)
{
    return (1 / (1 + exp(-x)));
}

float RNAControl::f_tansigmoid(float x)
{
    return (2/(1+exp(-2*x))-1);
}

float RNAControl::f_purelin(float x) 
{
    return x;
}

void RNAControl::propaga_sinal_frente(float v_entradas[ENTRADAS])
{
    int i,j;
    for(i=0; i<N_OCULTA_1; i++)
    {
        n_camada_oculta_1[i].soma = 0;
        n_camada_oculta_1[i].soma += w_oculta0_oculta1[0][i]*VLR_BIAS;
        for(j=1; j<ENTRADAS + 1; j++)
        {
            n_camada_oculta_1[i].soma+= w_oculta0_oculta1[j][i]*v_entradas[j-1];
        }
        n_camada_oculta_1[i].sinal = f_tansigmoid(n_camada_oculta_1[i].soma);
    }

    
    for(i=0; i<N_OCULTA_2; i++)
    {
        n_camada_oculta_2[i].soma = 0;
        n_camada_oculta_2[i].soma += w_oculta1_oculta2[0][i]*VLR_BIAS;

        for(j=0; j<N_OCULTA_1; j++)
        {
            n_camada_oculta_2[i].soma+= w_oculta1_oculta2[j+1][i]*n_camada_oculta_1[j].sinal;
        }

        n_camada_oculta_2[i].sinal = f_tansigmoid(n_camada_oculta_2[i].soma);
    }

    for(i=0; i<N_OCULTA_3; i++)
    {
        n_camada_oculta_3[i].soma = 0;
        n_camada_oculta_3[i].soma += w_oculta2_oculta3[0][i]*VLR_BIAS;

        for(j=0; j<N_OCULTA_2; j++)
        {
            n_camada_oculta_3[i].soma+= w_oculta2_oculta3[j+1][i]*n_camada_oculta_2[j].sinal;
        }

        n_camada_oculta_3[i].sinal = f_tansigmoid(n_camada_oculta_3[i].soma);
    }

    for(i=0; i<SAIDAS; i++)
    {
        n_saida[i].soma = 0;
        n_saida[i].soma += w_oculta3_oculta4[0][i]*VLR_BIAS;

        for(j=0; j<N_OCULTA_3; j++)
        {
            n_saida[i].soma+= w_oculta3_oculta4[j+1][i]*n_camada_oculta_3[j].sinal;
        }

        n_saida[i].sinal = f_sigmoid(n_saida[i].soma);
    }
    
    /*
    for(i=0; i<SAIDAS; i++)
    {
        n_saida[i].soma = 0;
        n_saida[i].soma += w_oculta1_oculta2[0][i]*VLR_BIAS;

        for(j=0; j<N_OCULTA_1; j++)
        {
            n_saida[i].soma+= w_oculta1_oculta2[j+1][i]*n_camada_oculta_1[j].sinal;
        }

        n_saida[i].sinal = n_saida[i].soma;
    }
    */
}

float RNAControl::random_number()
{
    return (rand()%10)/10.0;
}

void RNAControl::inicializa_neuronios()
{
    int i;
    for(i = 0; i<N_OCULTA_1; i++)
    {
        n_camada_oculta_1[i].soma = 0;
        n_camada_oculta_1[i].sinal = 0;
    }
    for(i = 0; i<N_OCULTA_2; i++)
    {
        n_camada_oculta_2[i].soma = 0;
        n_camada_oculta_2[i].sinal = 0;
    }
    for(i = 0; i<SAIDAS; i++)
    {
        n_saida[i].soma = 0;
        n_saida[i].sinal = 0;
    }
}