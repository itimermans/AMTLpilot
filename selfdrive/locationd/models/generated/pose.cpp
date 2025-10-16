#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_8820622560039895266) {
   out_8820622560039895266[0] = delta_x[0] + nom_x[0];
   out_8820622560039895266[1] = delta_x[1] + nom_x[1];
   out_8820622560039895266[2] = delta_x[2] + nom_x[2];
   out_8820622560039895266[3] = delta_x[3] + nom_x[3];
   out_8820622560039895266[4] = delta_x[4] + nom_x[4];
   out_8820622560039895266[5] = delta_x[5] + nom_x[5];
   out_8820622560039895266[6] = delta_x[6] + nom_x[6];
   out_8820622560039895266[7] = delta_x[7] + nom_x[7];
   out_8820622560039895266[8] = delta_x[8] + nom_x[8];
   out_8820622560039895266[9] = delta_x[9] + nom_x[9];
   out_8820622560039895266[10] = delta_x[10] + nom_x[10];
   out_8820622560039895266[11] = delta_x[11] + nom_x[11];
   out_8820622560039895266[12] = delta_x[12] + nom_x[12];
   out_8820622560039895266[13] = delta_x[13] + nom_x[13];
   out_8820622560039895266[14] = delta_x[14] + nom_x[14];
   out_8820622560039895266[15] = delta_x[15] + nom_x[15];
   out_8820622560039895266[16] = delta_x[16] + nom_x[16];
   out_8820622560039895266[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4138258066495298222) {
   out_4138258066495298222[0] = -nom_x[0] + true_x[0];
   out_4138258066495298222[1] = -nom_x[1] + true_x[1];
   out_4138258066495298222[2] = -nom_x[2] + true_x[2];
   out_4138258066495298222[3] = -nom_x[3] + true_x[3];
   out_4138258066495298222[4] = -nom_x[4] + true_x[4];
   out_4138258066495298222[5] = -nom_x[5] + true_x[5];
   out_4138258066495298222[6] = -nom_x[6] + true_x[6];
   out_4138258066495298222[7] = -nom_x[7] + true_x[7];
   out_4138258066495298222[8] = -nom_x[8] + true_x[8];
   out_4138258066495298222[9] = -nom_x[9] + true_x[9];
   out_4138258066495298222[10] = -nom_x[10] + true_x[10];
   out_4138258066495298222[11] = -nom_x[11] + true_x[11];
   out_4138258066495298222[12] = -nom_x[12] + true_x[12];
   out_4138258066495298222[13] = -nom_x[13] + true_x[13];
   out_4138258066495298222[14] = -nom_x[14] + true_x[14];
   out_4138258066495298222[15] = -nom_x[15] + true_x[15];
   out_4138258066495298222[16] = -nom_x[16] + true_x[16];
   out_4138258066495298222[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_6211513613161177568) {
   out_6211513613161177568[0] = 1.0;
   out_6211513613161177568[1] = 0.0;
   out_6211513613161177568[2] = 0.0;
   out_6211513613161177568[3] = 0.0;
   out_6211513613161177568[4] = 0.0;
   out_6211513613161177568[5] = 0.0;
   out_6211513613161177568[6] = 0.0;
   out_6211513613161177568[7] = 0.0;
   out_6211513613161177568[8] = 0.0;
   out_6211513613161177568[9] = 0.0;
   out_6211513613161177568[10] = 0.0;
   out_6211513613161177568[11] = 0.0;
   out_6211513613161177568[12] = 0.0;
   out_6211513613161177568[13] = 0.0;
   out_6211513613161177568[14] = 0.0;
   out_6211513613161177568[15] = 0.0;
   out_6211513613161177568[16] = 0.0;
   out_6211513613161177568[17] = 0.0;
   out_6211513613161177568[18] = 0.0;
   out_6211513613161177568[19] = 1.0;
   out_6211513613161177568[20] = 0.0;
   out_6211513613161177568[21] = 0.0;
   out_6211513613161177568[22] = 0.0;
   out_6211513613161177568[23] = 0.0;
   out_6211513613161177568[24] = 0.0;
   out_6211513613161177568[25] = 0.0;
   out_6211513613161177568[26] = 0.0;
   out_6211513613161177568[27] = 0.0;
   out_6211513613161177568[28] = 0.0;
   out_6211513613161177568[29] = 0.0;
   out_6211513613161177568[30] = 0.0;
   out_6211513613161177568[31] = 0.0;
   out_6211513613161177568[32] = 0.0;
   out_6211513613161177568[33] = 0.0;
   out_6211513613161177568[34] = 0.0;
   out_6211513613161177568[35] = 0.0;
   out_6211513613161177568[36] = 0.0;
   out_6211513613161177568[37] = 0.0;
   out_6211513613161177568[38] = 1.0;
   out_6211513613161177568[39] = 0.0;
   out_6211513613161177568[40] = 0.0;
   out_6211513613161177568[41] = 0.0;
   out_6211513613161177568[42] = 0.0;
   out_6211513613161177568[43] = 0.0;
   out_6211513613161177568[44] = 0.0;
   out_6211513613161177568[45] = 0.0;
   out_6211513613161177568[46] = 0.0;
   out_6211513613161177568[47] = 0.0;
   out_6211513613161177568[48] = 0.0;
   out_6211513613161177568[49] = 0.0;
   out_6211513613161177568[50] = 0.0;
   out_6211513613161177568[51] = 0.0;
   out_6211513613161177568[52] = 0.0;
   out_6211513613161177568[53] = 0.0;
   out_6211513613161177568[54] = 0.0;
   out_6211513613161177568[55] = 0.0;
   out_6211513613161177568[56] = 0.0;
   out_6211513613161177568[57] = 1.0;
   out_6211513613161177568[58] = 0.0;
   out_6211513613161177568[59] = 0.0;
   out_6211513613161177568[60] = 0.0;
   out_6211513613161177568[61] = 0.0;
   out_6211513613161177568[62] = 0.0;
   out_6211513613161177568[63] = 0.0;
   out_6211513613161177568[64] = 0.0;
   out_6211513613161177568[65] = 0.0;
   out_6211513613161177568[66] = 0.0;
   out_6211513613161177568[67] = 0.0;
   out_6211513613161177568[68] = 0.0;
   out_6211513613161177568[69] = 0.0;
   out_6211513613161177568[70] = 0.0;
   out_6211513613161177568[71] = 0.0;
   out_6211513613161177568[72] = 0.0;
   out_6211513613161177568[73] = 0.0;
   out_6211513613161177568[74] = 0.0;
   out_6211513613161177568[75] = 0.0;
   out_6211513613161177568[76] = 1.0;
   out_6211513613161177568[77] = 0.0;
   out_6211513613161177568[78] = 0.0;
   out_6211513613161177568[79] = 0.0;
   out_6211513613161177568[80] = 0.0;
   out_6211513613161177568[81] = 0.0;
   out_6211513613161177568[82] = 0.0;
   out_6211513613161177568[83] = 0.0;
   out_6211513613161177568[84] = 0.0;
   out_6211513613161177568[85] = 0.0;
   out_6211513613161177568[86] = 0.0;
   out_6211513613161177568[87] = 0.0;
   out_6211513613161177568[88] = 0.0;
   out_6211513613161177568[89] = 0.0;
   out_6211513613161177568[90] = 0.0;
   out_6211513613161177568[91] = 0.0;
   out_6211513613161177568[92] = 0.0;
   out_6211513613161177568[93] = 0.0;
   out_6211513613161177568[94] = 0.0;
   out_6211513613161177568[95] = 1.0;
   out_6211513613161177568[96] = 0.0;
   out_6211513613161177568[97] = 0.0;
   out_6211513613161177568[98] = 0.0;
   out_6211513613161177568[99] = 0.0;
   out_6211513613161177568[100] = 0.0;
   out_6211513613161177568[101] = 0.0;
   out_6211513613161177568[102] = 0.0;
   out_6211513613161177568[103] = 0.0;
   out_6211513613161177568[104] = 0.0;
   out_6211513613161177568[105] = 0.0;
   out_6211513613161177568[106] = 0.0;
   out_6211513613161177568[107] = 0.0;
   out_6211513613161177568[108] = 0.0;
   out_6211513613161177568[109] = 0.0;
   out_6211513613161177568[110] = 0.0;
   out_6211513613161177568[111] = 0.0;
   out_6211513613161177568[112] = 0.0;
   out_6211513613161177568[113] = 0.0;
   out_6211513613161177568[114] = 1.0;
   out_6211513613161177568[115] = 0.0;
   out_6211513613161177568[116] = 0.0;
   out_6211513613161177568[117] = 0.0;
   out_6211513613161177568[118] = 0.0;
   out_6211513613161177568[119] = 0.0;
   out_6211513613161177568[120] = 0.0;
   out_6211513613161177568[121] = 0.0;
   out_6211513613161177568[122] = 0.0;
   out_6211513613161177568[123] = 0.0;
   out_6211513613161177568[124] = 0.0;
   out_6211513613161177568[125] = 0.0;
   out_6211513613161177568[126] = 0.0;
   out_6211513613161177568[127] = 0.0;
   out_6211513613161177568[128] = 0.0;
   out_6211513613161177568[129] = 0.0;
   out_6211513613161177568[130] = 0.0;
   out_6211513613161177568[131] = 0.0;
   out_6211513613161177568[132] = 0.0;
   out_6211513613161177568[133] = 1.0;
   out_6211513613161177568[134] = 0.0;
   out_6211513613161177568[135] = 0.0;
   out_6211513613161177568[136] = 0.0;
   out_6211513613161177568[137] = 0.0;
   out_6211513613161177568[138] = 0.0;
   out_6211513613161177568[139] = 0.0;
   out_6211513613161177568[140] = 0.0;
   out_6211513613161177568[141] = 0.0;
   out_6211513613161177568[142] = 0.0;
   out_6211513613161177568[143] = 0.0;
   out_6211513613161177568[144] = 0.0;
   out_6211513613161177568[145] = 0.0;
   out_6211513613161177568[146] = 0.0;
   out_6211513613161177568[147] = 0.0;
   out_6211513613161177568[148] = 0.0;
   out_6211513613161177568[149] = 0.0;
   out_6211513613161177568[150] = 0.0;
   out_6211513613161177568[151] = 0.0;
   out_6211513613161177568[152] = 1.0;
   out_6211513613161177568[153] = 0.0;
   out_6211513613161177568[154] = 0.0;
   out_6211513613161177568[155] = 0.0;
   out_6211513613161177568[156] = 0.0;
   out_6211513613161177568[157] = 0.0;
   out_6211513613161177568[158] = 0.0;
   out_6211513613161177568[159] = 0.0;
   out_6211513613161177568[160] = 0.0;
   out_6211513613161177568[161] = 0.0;
   out_6211513613161177568[162] = 0.0;
   out_6211513613161177568[163] = 0.0;
   out_6211513613161177568[164] = 0.0;
   out_6211513613161177568[165] = 0.0;
   out_6211513613161177568[166] = 0.0;
   out_6211513613161177568[167] = 0.0;
   out_6211513613161177568[168] = 0.0;
   out_6211513613161177568[169] = 0.0;
   out_6211513613161177568[170] = 0.0;
   out_6211513613161177568[171] = 1.0;
   out_6211513613161177568[172] = 0.0;
   out_6211513613161177568[173] = 0.0;
   out_6211513613161177568[174] = 0.0;
   out_6211513613161177568[175] = 0.0;
   out_6211513613161177568[176] = 0.0;
   out_6211513613161177568[177] = 0.0;
   out_6211513613161177568[178] = 0.0;
   out_6211513613161177568[179] = 0.0;
   out_6211513613161177568[180] = 0.0;
   out_6211513613161177568[181] = 0.0;
   out_6211513613161177568[182] = 0.0;
   out_6211513613161177568[183] = 0.0;
   out_6211513613161177568[184] = 0.0;
   out_6211513613161177568[185] = 0.0;
   out_6211513613161177568[186] = 0.0;
   out_6211513613161177568[187] = 0.0;
   out_6211513613161177568[188] = 0.0;
   out_6211513613161177568[189] = 0.0;
   out_6211513613161177568[190] = 1.0;
   out_6211513613161177568[191] = 0.0;
   out_6211513613161177568[192] = 0.0;
   out_6211513613161177568[193] = 0.0;
   out_6211513613161177568[194] = 0.0;
   out_6211513613161177568[195] = 0.0;
   out_6211513613161177568[196] = 0.0;
   out_6211513613161177568[197] = 0.0;
   out_6211513613161177568[198] = 0.0;
   out_6211513613161177568[199] = 0.0;
   out_6211513613161177568[200] = 0.0;
   out_6211513613161177568[201] = 0.0;
   out_6211513613161177568[202] = 0.0;
   out_6211513613161177568[203] = 0.0;
   out_6211513613161177568[204] = 0.0;
   out_6211513613161177568[205] = 0.0;
   out_6211513613161177568[206] = 0.0;
   out_6211513613161177568[207] = 0.0;
   out_6211513613161177568[208] = 0.0;
   out_6211513613161177568[209] = 1.0;
   out_6211513613161177568[210] = 0.0;
   out_6211513613161177568[211] = 0.0;
   out_6211513613161177568[212] = 0.0;
   out_6211513613161177568[213] = 0.0;
   out_6211513613161177568[214] = 0.0;
   out_6211513613161177568[215] = 0.0;
   out_6211513613161177568[216] = 0.0;
   out_6211513613161177568[217] = 0.0;
   out_6211513613161177568[218] = 0.0;
   out_6211513613161177568[219] = 0.0;
   out_6211513613161177568[220] = 0.0;
   out_6211513613161177568[221] = 0.0;
   out_6211513613161177568[222] = 0.0;
   out_6211513613161177568[223] = 0.0;
   out_6211513613161177568[224] = 0.0;
   out_6211513613161177568[225] = 0.0;
   out_6211513613161177568[226] = 0.0;
   out_6211513613161177568[227] = 0.0;
   out_6211513613161177568[228] = 1.0;
   out_6211513613161177568[229] = 0.0;
   out_6211513613161177568[230] = 0.0;
   out_6211513613161177568[231] = 0.0;
   out_6211513613161177568[232] = 0.0;
   out_6211513613161177568[233] = 0.0;
   out_6211513613161177568[234] = 0.0;
   out_6211513613161177568[235] = 0.0;
   out_6211513613161177568[236] = 0.0;
   out_6211513613161177568[237] = 0.0;
   out_6211513613161177568[238] = 0.0;
   out_6211513613161177568[239] = 0.0;
   out_6211513613161177568[240] = 0.0;
   out_6211513613161177568[241] = 0.0;
   out_6211513613161177568[242] = 0.0;
   out_6211513613161177568[243] = 0.0;
   out_6211513613161177568[244] = 0.0;
   out_6211513613161177568[245] = 0.0;
   out_6211513613161177568[246] = 0.0;
   out_6211513613161177568[247] = 1.0;
   out_6211513613161177568[248] = 0.0;
   out_6211513613161177568[249] = 0.0;
   out_6211513613161177568[250] = 0.0;
   out_6211513613161177568[251] = 0.0;
   out_6211513613161177568[252] = 0.0;
   out_6211513613161177568[253] = 0.0;
   out_6211513613161177568[254] = 0.0;
   out_6211513613161177568[255] = 0.0;
   out_6211513613161177568[256] = 0.0;
   out_6211513613161177568[257] = 0.0;
   out_6211513613161177568[258] = 0.0;
   out_6211513613161177568[259] = 0.0;
   out_6211513613161177568[260] = 0.0;
   out_6211513613161177568[261] = 0.0;
   out_6211513613161177568[262] = 0.0;
   out_6211513613161177568[263] = 0.0;
   out_6211513613161177568[264] = 0.0;
   out_6211513613161177568[265] = 0.0;
   out_6211513613161177568[266] = 1.0;
   out_6211513613161177568[267] = 0.0;
   out_6211513613161177568[268] = 0.0;
   out_6211513613161177568[269] = 0.0;
   out_6211513613161177568[270] = 0.0;
   out_6211513613161177568[271] = 0.0;
   out_6211513613161177568[272] = 0.0;
   out_6211513613161177568[273] = 0.0;
   out_6211513613161177568[274] = 0.0;
   out_6211513613161177568[275] = 0.0;
   out_6211513613161177568[276] = 0.0;
   out_6211513613161177568[277] = 0.0;
   out_6211513613161177568[278] = 0.0;
   out_6211513613161177568[279] = 0.0;
   out_6211513613161177568[280] = 0.0;
   out_6211513613161177568[281] = 0.0;
   out_6211513613161177568[282] = 0.0;
   out_6211513613161177568[283] = 0.0;
   out_6211513613161177568[284] = 0.0;
   out_6211513613161177568[285] = 1.0;
   out_6211513613161177568[286] = 0.0;
   out_6211513613161177568[287] = 0.0;
   out_6211513613161177568[288] = 0.0;
   out_6211513613161177568[289] = 0.0;
   out_6211513613161177568[290] = 0.0;
   out_6211513613161177568[291] = 0.0;
   out_6211513613161177568[292] = 0.0;
   out_6211513613161177568[293] = 0.0;
   out_6211513613161177568[294] = 0.0;
   out_6211513613161177568[295] = 0.0;
   out_6211513613161177568[296] = 0.0;
   out_6211513613161177568[297] = 0.0;
   out_6211513613161177568[298] = 0.0;
   out_6211513613161177568[299] = 0.0;
   out_6211513613161177568[300] = 0.0;
   out_6211513613161177568[301] = 0.0;
   out_6211513613161177568[302] = 0.0;
   out_6211513613161177568[303] = 0.0;
   out_6211513613161177568[304] = 1.0;
   out_6211513613161177568[305] = 0.0;
   out_6211513613161177568[306] = 0.0;
   out_6211513613161177568[307] = 0.0;
   out_6211513613161177568[308] = 0.0;
   out_6211513613161177568[309] = 0.0;
   out_6211513613161177568[310] = 0.0;
   out_6211513613161177568[311] = 0.0;
   out_6211513613161177568[312] = 0.0;
   out_6211513613161177568[313] = 0.0;
   out_6211513613161177568[314] = 0.0;
   out_6211513613161177568[315] = 0.0;
   out_6211513613161177568[316] = 0.0;
   out_6211513613161177568[317] = 0.0;
   out_6211513613161177568[318] = 0.0;
   out_6211513613161177568[319] = 0.0;
   out_6211513613161177568[320] = 0.0;
   out_6211513613161177568[321] = 0.0;
   out_6211513613161177568[322] = 0.0;
   out_6211513613161177568[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_5417900835208008336) {
   out_5417900835208008336[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_5417900835208008336[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_5417900835208008336[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_5417900835208008336[3] = dt*state[12] + state[3];
   out_5417900835208008336[4] = dt*state[13] + state[4];
   out_5417900835208008336[5] = dt*state[14] + state[5];
   out_5417900835208008336[6] = state[6];
   out_5417900835208008336[7] = state[7];
   out_5417900835208008336[8] = state[8];
   out_5417900835208008336[9] = state[9];
   out_5417900835208008336[10] = state[10];
   out_5417900835208008336[11] = state[11];
   out_5417900835208008336[12] = state[12];
   out_5417900835208008336[13] = state[13];
   out_5417900835208008336[14] = state[14];
   out_5417900835208008336[15] = state[15];
   out_5417900835208008336[16] = state[16];
   out_5417900835208008336[17] = state[17];
}
void F_fun(double *state, double dt, double *out_3421518052388552051) {
   out_3421518052388552051[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3421518052388552051[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3421518052388552051[2] = 0;
   out_3421518052388552051[3] = 0;
   out_3421518052388552051[4] = 0;
   out_3421518052388552051[5] = 0;
   out_3421518052388552051[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3421518052388552051[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3421518052388552051[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3421518052388552051[9] = 0;
   out_3421518052388552051[10] = 0;
   out_3421518052388552051[11] = 0;
   out_3421518052388552051[12] = 0;
   out_3421518052388552051[13] = 0;
   out_3421518052388552051[14] = 0;
   out_3421518052388552051[15] = 0;
   out_3421518052388552051[16] = 0;
   out_3421518052388552051[17] = 0;
   out_3421518052388552051[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3421518052388552051[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3421518052388552051[20] = 0;
   out_3421518052388552051[21] = 0;
   out_3421518052388552051[22] = 0;
   out_3421518052388552051[23] = 0;
   out_3421518052388552051[24] = 0;
   out_3421518052388552051[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3421518052388552051[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3421518052388552051[27] = 0;
   out_3421518052388552051[28] = 0;
   out_3421518052388552051[29] = 0;
   out_3421518052388552051[30] = 0;
   out_3421518052388552051[31] = 0;
   out_3421518052388552051[32] = 0;
   out_3421518052388552051[33] = 0;
   out_3421518052388552051[34] = 0;
   out_3421518052388552051[35] = 0;
   out_3421518052388552051[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3421518052388552051[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3421518052388552051[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3421518052388552051[39] = 0;
   out_3421518052388552051[40] = 0;
   out_3421518052388552051[41] = 0;
   out_3421518052388552051[42] = 0;
   out_3421518052388552051[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3421518052388552051[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3421518052388552051[45] = 0;
   out_3421518052388552051[46] = 0;
   out_3421518052388552051[47] = 0;
   out_3421518052388552051[48] = 0;
   out_3421518052388552051[49] = 0;
   out_3421518052388552051[50] = 0;
   out_3421518052388552051[51] = 0;
   out_3421518052388552051[52] = 0;
   out_3421518052388552051[53] = 0;
   out_3421518052388552051[54] = 0;
   out_3421518052388552051[55] = 0;
   out_3421518052388552051[56] = 0;
   out_3421518052388552051[57] = 1;
   out_3421518052388552051[58] = 0;
   out_3421518052388552051[59] = 0;
   out_3421518052388552051[60] = 0;
   out_3421518052388552051[61] = 0;
   out_3421518052388552051[62] = 0;
   out_3421518052388552051[63] = 0;
   out_3421518052388552051[64] = 0;
   out_3421518052388552051[65] = 0;
   out_3421518052388552051[66] = dt;
   out_3421518052388552051[67] = 0;
   out_3421518052388552051[68] = 0;
   out_3421518052388552051[69] = 0;
   out_3421518052388552051[70] = 0;
   out_3421518052388552051[71] = 0;
   out_3421518052388552051[72] = 0;
   out_3421518052388552051[73] = 0;
   out_3421518052388552051[74] = 0;
   out_3421518052388552051[75] = 0;
   out_3421518052388552051[76] = 1;
   out_3421518052388552051[77] = 0;
   out_3421518052388552051[78] = 0;
   out_3421518052388552051[79] = 0;
   out_3421518052388552051[80] = 0;
   out_3421518052388552051[81] = 0;
   out_3421518052388552051[82] = 0;
   out_3421518052388552051[83] = 0;
   out_3421518052388552051[84] = 0;
   out_3421518052388552051[85] = dt;
   out_3421518052388552051[86] = 0;
   out_3421518052388552051[87] = 0;
   out_3421518052388552051[88] = 0;
   out_3421518052388552051[89] = 0;
   out_3421518052388552051[90] = 0;
   out_3421518052388552051[91] = 0;
   out_3421518052388552051[92] = 0;
   out_3421518052388552051[93] = 0;
   out_3421518052388552051[94] = 0;
   out_3421518052388552051[95] = 1;
   out_3421518052388552051[96] = 0;
   out_3421518052388552051[97] = 0;
   out_3421518052388552051[98] = 0;
   out_3421518052388552051[99] = 0;
   out_3421518052388552051[100] = 0;
   out_3421518052388552051[101] = 0;
   out_3421518052388552051[102] = 0;
   out_3421518052388552051[103] = 0;
   out_3421518052388552051[104] = dt;
   out_3421518052388552051[105] = 0;
   out_3421518052388552051[106] = 0;
   out_3421518052388552051[107] = 0;
   out_3421518052388552051[108] = 0;
   out_3421518052388552051[109] = 0;
   out_3421518052388552051[110] = 0;
   out_3421518052388552051[111] = 0;
   out_3421518052388552051[112] = 0;
   out_3421518052388552051[113] = 0;
   out_3421518052388552051[114] = 1;
   out_3421518052388552051[115] = 0;
   out_3421518052388552051[116] = 0;
   out_3421518052388552051[117] = 0;
   out_3421518052388552051[118] = 0;
   out_3421518052388552051[119] = 0;
   out_3421518052388552051[120] = 0;
   out_3421518052388552051[121] = 0;
   out_3421518052388552051[122] = 0;
   out_3421518052388552051[123] = 0;
   out_3421518052388552051[124] = 0;
   out_3421518052388552051[125] = 0;
   out_3421518052388552051[126] = 0;
   out_3421518052388552051[127] = 0;
   out_3421518052388552051[128] = 0;
   out_3421518052388552051[129] = 0;
   out_3421518052388552051[130] = 0;
   out_3421518052388552051[131] = 0;
   out_3421518052388552051[132] = 0;
   out_3421518052388552051[133] = 1;
   out_3421518052388552051[134] = 0;
   out_3421518052388552051[135] = 0;
   out_3421518052388552051[136] = 0;
   out_3421518052388552051[137] = 0;
   out_3421518052388552051[138] = 0;
   out_3421518052388552051[139] = 0;
   out_3421518052388552051[140] = 0;
   out_3421518052388552051[141] = 0;
   out_3421518052388552051[142] = 0;
   out_3421518052388552051[143] = 0;
   out_3421518052388552051[144] = 0;
   out_3421518052388552051[145] = 0;
   out_3421518052388552051[146] = 0;
   out_3421518052388552051[147] = 0;
   out_3421518052388552051[148] = 0;
   out_3421518052388552051[149] = 0;
   out_3421518052388552051[150] = 0;
   out_3421518052388552051[151] = 0;
   out_3421518052388552051[152] = 1;
   out_3421518052388552051[153] = 0;
   out_3421518052388552051[154] = 0;
   out_3421518052388552051[155] = 0;
   out_3421518052388552051[156] = 0;
   out_3421518052388552051[157] = 0;
   out_3421518052388552051[158] = 0;
   out_3421518052388552051[159] = 0;
   out_3421518052388552051[160] = 0;
   out_3421518052388552051[161] = 0;
   out_3421518052388552051[162] = 0;
   out_3421518052388552051[163] = 0;
   out_3421518052388552051[164] = 0;
   out_3421518052388552051[165] = 0;
   out_3421518052388552051[166] = 0;
   out_3421518052388552051[167] = 0;
   out_3421518052388552051[168] = 0;
   out_3421518052388552051[169] = 0;
   out_3421518052388552051[170] = 0;
   out_3421518052388552051[171] = 1;
   out_3421518052388552051[172] = 0;
   out_3421518052388552051[173] = 0;
   out_3421518052388552051[174] = 0;
   out_3421518052388552051[175] = 0;
   out_3421518052388552051[176] = 0;
   out_3421518052388552051[177] = 0;
   out_3421518052388552051[178] = 0;
   out_3421518052388552051[179] = 0;
   out_3421518052388552051[180] = 0;
   out_3421518052388552051[181] = 0;
   out_3421518052388552051[182] = 0;
   out_3421518052388552051[183] = 0;
   out_3421518052388552051[184] = 0;
   out_3421518052388552051[185] = 0;
   out_3421518052388552051[186] = 0;
   out_3421518052388552051[187] = 0;
   out_3421518052388552051[188] = 0;
   out_3421518052388552051[189] = 0;
   out_3421518052388552051[190] = 1;
   out_3421518052388552051[191] = 0;
   out_3421518052388552051[192] = 0;
   out_3421518052388552051[193] = 0;
   out_3421518052388552051[194] = 0;
   out_3421518052388552051[195] = 0;
   out_3421518052388552051[196] = 0;
   out_3421518052388552051[197] = 0;
   out_3421518052388552051[198] = 0;
   out_3421518052388552051[199] = 0;
   out_3421518052388552051[200] = 0;
   out_3421518052388552051[201] = 0;
   out_3421518052388552051[202] = 0;
   out_3421518052388552051[203] = 0;
   out_3421518052388552051[204] = 0;
   out_3421518052388552051[205] = 0;
   out_3421518052388552051[206] = 0;
   out_3421518052388552051[207] = 0;
   out_3421518052388552051[208] = 0;
   out_3421518052388552051[209] = 1;
   out_3421518052388552051[210] = 0;
   out_3421518052388552051[211] = 0;
   out_3421518052388552051[212] = 0;
   out_3421518052388552051[213] = 0;
   out_3421518052388552051[214] = 0;
   out_3421518052388552051[215] = 0;
   out_3421518052388552051[216] = 0;
   out_3421518052388552051[217] = 0;
   out_3421518052388552051[218] = 0;
   out_3421518052388552051[219] = 0;
   out_3421518052388552051[220] = 0;
   out_3421518052388552051[221] = 0;
   out_3421518052388552051[222] = 0;
   out_3421518052388552051[223] = 0;
   out_3421518052388552051[224] = 0;
   out_3421518052388552051[225] = 0;
   out_3421518052388552051[226] = 0;
   out_3421518052388552051[227] = 0;
   out_3421518052388552051[228] = 1;
   out_3421518052388552051[229] = 0;
   out_3421518052388552051[230] = 0;
   out_3421518052388552051[231] = 0;
   out_3421518052388552051[232] = 0;
   out_3421518052388552051[233] = 0;
   out_3421518052388552051[234] = 0;
   out_3421518052388552051[235] = 0;
   out_3421518052388552051[236] = 0;
   out_3421518052388552051[237] = 0;
   out_3421518052388552051[238] = 0;
   out_3421518052388552051[239] = 0;
   out_3421518052388552051[240] = 0;
   out_3421518052388552051[241] = 0;
   out_3421518052388552051[242] = 0;
   out_3421518052388552051[243] = 0;
   out_3421518052388552051[244] = 0;
   out_3421518052388552051[245] = 0;
   out_3421518052388552051[246] = 0;
   out_3421518052388552051[247] = 1;
   out_3421518052388552051[248] = 0;
   out_3421518052388552051[249] = 0;
   out_3421518052388552051[250] = 0;
   out_3421518052388552051[251] = 0;
   out_3421518052388552051[252] = 0;
   out_3421518052388552051[253] = 0;
   out_3421518052388552051[254] = 0;
   out_3421518052388552051[255] = 0;
   out_3421518052388552051[256] = 0;
   out_3421518052388552051[257] = 0;
   out_3421518052388552051[258] = 0;
   out_3421518052388552051[259] = 0;
   out_3421518052388552051[260] = 0;
   out_3421518052388552051[261] = 0;
   out_3421518052388552051[262] = 0;
   out_3421518052388552051[263] = 0;
   out_3421518052388552051[264] = 0;
   out_3421518052388552051[265] = 0;
   out_3421518052388552051[266] = 1;
   out_3421518052388552051[267] = 0;
   out_3421518052388552051[268] = 0;
   out_3421518052388552051[269] = 0;
   out_3421518052388552051[270] = 0;
   out_3421518052388552051[271] = 0;
   out_3421518052388552051[272] = 0;
   out_3421518052388552051[273] = 0;
   out_3421518052388552051[274] = 0;
   out_3421518052388552051[275] = 0;
   out_3421518052388552051[276] = 0;
   out_3421518052388552051[277] = 0;
   out_3421518052388552051[278] = 0;
   out_3421518052388552051[279] = 0;
   out_3421518052388552051[280] = 0;
   out_3421518052388552051[281] = 0;
   out_3421518052388552051[282] = 0;
   out_3421518052388552051[283] = 0;
   out_3421518052388552051[284] = 0;
   out_3421518052388552051[285] = 1;
   out_3421518052388552051[286] = 0;
   out_3421518052388552051[287] = 0;
   out_3421518052388552051[288] = 0;
   out_3421518052388552051[289] = 0;
   out_3421518052388552051[290] = 0;
   out_3421518052388552051[291] = 0;
   out_3421518052388552051[292] = 0;
   out_3421518052388552051[293] = 0;
   out_3421518052388552051[294] = 0;
   out_3421518052388552051[295] = 0;
   out_3421518052388552051[296] = 0;
   out_3421518052388552051[297] = 0;
   out_3421518052388552051[298] = 0;
   out_3421518052388552051[299] = 0;
   out_3421518052388552051[300] = 0;
   out_3421518052388552051[301] = 0;
   out_3421518052388552051[302] = 0;
   out_3421518052388552051[303] = 0;
   out_3421518052388552051[304] = 1;
   out_3421518052388552051[305] = 0;
   out_3421518052388552051[306] = 0;
   out_3421518052388552051[307] = 0;
   out_3421518052388552051[308] = 0;
   out_3421518052388552051[309] = 0;
   out_3421518052388552051[310] = 0;
   out_3421518052388552051[311] = 0;
   out_3421518052388552051[312] = 0;
   out_3421518052388552051[313] = 0;
   out_3421518052388552051[314] = 0;
   out_3421518052388552051[315] = 0;
   out_3421518052388552051[316] = 0;
   out_3421518052388552051[317] = 0;
   out_3421518052388552051[318] = 0;
   out_3421518052388552051[319] = 0;
   out_3421518052388552051[320] = 0;
   out_3421518052388552051[321] = 0;
   out_3421518052388552051[322] = 0;
   out_3421518052388552051[323] = 1;
}
void h_4(double *state, double *unused, double *out_7947650004784572605) {
   out_7947650004784572605[0] = state[6] + state[9];
   out_7947650004784572605[1] = state[7] + state[10];
   out_7947650004784572605[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_4034925576575149281) {
   out_4034925576575149281[0] = 0;
   out_4034925576575149281[1] = 0;
   out_4034925576575149281[2] = 0;
   out_4034925576575149281[3] = 0;
   out_4034925576575149281[4] = 0;
   out_4034925576575149281[5] = 0;
   out_4034925576575149281[6] = 1;
   out_4034925576575149281[7] = 0;
   out_4034925576575149281[8] = 0;
   out_4034925576575149281[9] = 1;
   out_4034925576575149281[10] = 0;
   out_4034925576575149281[11] = 0;
   out_4034925576575149281[12] = 0;
   out_4034925576575149281[13] = 0;
   out_4034925576575149281[14] = 0;
   out_4034925576575149281[15] = 0;
   out_4034925576575149281[16] = 0;
   out_4034925576575149281[17] = 0;
   out_4034925576575149281[18] = 0;
   out_4034925576575149281[19] = 0;
   out_4034925576575149281[20] = 0;
   out_4034925576575149281[21] = 0;
   out_4034925576575149281[22] = 0;
   out_4034925576575149281[23] = 0;
   out_4034925576575149281[24] = 0;
   out_4034925576575149281[25] = 1;
   out_4034925576575149281[26] = 0;
   out_4034925576575149281[27] = 0;
   out_4034925576575149281[28] = 1;
   out_4034925576575149281[29] = 0;
   out_4034925576575149281[30] = 0;
   out_4034925576575149281[31] = 0;
   out_4034925576575149281[32] = 0;
   out_4034925576575149281[33] = 0;
   out_4034925576575149281[34] = 0;
   out_4034925576575149281[35] = 0;
   out_4034925576575149281[36] = 0;
   out_4034925576575149281[37] = 0;
   out_4034925576575149281[38] = 0;
   out_4034925576575149281[39] = 0;
   out_4034925576575149281[40] = 0;
   out_4034925576575149281[41] = 0;
   out_4034925576575149281[42] = 0;
   out_4034925576575149281[43] = 0;
   out_4034925576575149281[44] = 1;
   out_4034925576575149281[45] = 0;
   out_4034925576575149281[46] = 0;
   out_4034925576575149281[47] = 1;
   out_4034925576575149281[48] = 0;
   out_4034925576575149281[49] = 0;
   out_4034925576575149281[50] = 0;
   out_4034925576575149281[51] = 0;
   out_4034925576575149281[52] = 0;
   out_4034925576575149281[53] = 0;
}
void h_10(double *state, double *unused, double *out_6434353536820436852) {
   out_6434353536820436852[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_6434353536820436852[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_6434353536820436852[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4256257324261286174) {
   out_4256257324261286174[0] = 0;
   out_4256257324261286174[1] = 9.8100000000000005*cos(state[1]);
   out_4256257324261286174[2] = 0;
   out_4256257324261286174[3] = 0;
   out_4256257324261286174[4] = -state[8];
   out_4256257324261286174[5] = state[7];
   out_4256257324261286174[6] = 0;
   out_4256257324261286174[7] = state[5];
   out_4256257324261286174[8] = -state[4];
   out_4256257324261286174[9] = 0;
   out_4256257324261286174[10] = 0;
   out_4256257324261286174[11] = 0;
   out_4256257324261286174[12] = 1;
   out_4256257324261286174[13] = 0;
   out_4256257324261286174[14] = 0;
   out_4256257324261286174[15] = 1;
   out_4256257324261286174[16] = 0;
   out_4256257324261286174[17] = 0;
   out_4256257324261286174[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4256257324261286174[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4256257324261286174[20] = 0;
   out_4256257324261286174[21] = state[8];
   out_4256257324261286174[22] = 0;
   out_4256257324261286174[23] = -state[6];
   out_4256257324261286174[24] = -state[5];
   out_4256257324261286174[25] = 0;
   out_4256257324261286174[26] = state[3];
   out_4256257324261286174[27] = 0;
   out_4256257324261286174[28] = 0;
   out_4256257324261286174[29] = 0;
   out_4256257324261286174[30] = 0;
   out_4256257324261286174[31] = 1;
   out_4256257324261286174[32] = 0;
   out_4256257324261286174[33] = 0;
   out_4256257324261286174[34] = 1;
   out_4256257324261286174[35] = 0;
   out_4256257324261286174[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4256257324261286174[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4256257324261286174[38] = 0;
   out_4256257324261286174[39] = -state[7];
   out_4256257324261286174[40] = state[6];
   out_4256257324261286174[41] = 0;
   out_4256257324261286174[42] = state[4];
   out_4256257324261286174[43] = -state[3];
   out_4256257324261286174[44] = 0;
   out_4256257324261286174[45] = 0;
   out_4256257324261286174[46] = 0;
   out_4256257324261286174[47] = 0;
   out_4256257324261286174[48] = 0;
   out_4256257324261286174[49] = 0;
   out_4256257324261286174[50] = 1;
   out_4256257324261286174[51] = 0;
   out_4256257324261286174[52] = 0;
   out_4256257324261286174[53] = 1;
}
void h_13(double *state, double *unused, double *out_348176217550400228) {
   out_348176217550400228[0] = state[3];
   out_348176217550400228[1] = state[4];
   out_348176217550400228[2] = state[5];
}
void H_13(double *state, double *unused, double *out_3575705631741551648) {
   out_3575705631741551648[0] = 0;
   out_3575705631741551648[1] = 0;
   out_3575705631741551648[2] = 0;
   out_3575705631741551648[3] = 1;
   out_3575705631741551648[4] = 0;
   out_3575705631741551648[5] = 0;
   out_3575705631741551648[6] = 0;
   out_3575705631741551648[7] = 0;
   out_3575705631741551648[8] = 0;
   out_3575705631741551648[9] = 0;
   out_3575705631741551648[10] = 0;
   out_3575705631741551648[11] = 0;
   out_3575705631741551648[12] = 0;
   out_3575705631741551648[13] = 0;
   out_3575705631741551648[14] = 0;
   out_3575705631741551648[15] = 0;
   out_3575705631741551648[16] = 0;
   out_3575705631741551648[17] = 0;
   out_3575705631741551648[18] = 0;
   out_3575705631741551648[19] = 0;
   out_3575705631741551648[20] = 0;
   out_3575705631741551648[21] = 0;
   out_3575705631741551648[22] = 1;
   out_3575705631741551648[23] = 0;
   out_3575705631741551648[24] = 0;
   out_3575705631741551648[25] = 0;
   out_3575705631741551648[26] = 0;
   out_3575705631741551648[27] = 0;
   out_3575705631741551648[28] = 0;
   out_3575705631741551648[29] = 0;
   out_3575705631741551648[30] = 0;
   out_3575705631741551648[31] = 0;
   out_3575705631741551648[32] = 0;
   out_3575705631741551648[33] = 0;
   out_3575705631741551648[34] = 0;
   out_3575705631741551648[35] = 0;
   out_3575705631741551648[36] = 0;
   out_3575705631741551648[37] = 0;
   out_3575705631741551648[38] = 0;
   out_3575705631741551648[39] = 0;
   out_3575705631741551648[40] = 0;
   out_3575705631741551648[41] = 1;
   out_3575705631741551648[42] = 0;
   out_3575705631741551648[43] = 0;
   out_3575705631741551648[44] = 0;
   out_3575705631741551648[45] = 0;
   out_3575705631741551648[46] = 0;
   out_3575705631741551648[47] = 0;
   out_3575705631741551648[48] = 0;
   out_3575705631741551648[49] = 0;
   out_3575705631741551648[50] = 0;
   out_3575705631741551648[51] = 0;
   out_3575705631741551648[52] = 0;
   out_3575705631741551648[53] = 0;
}
void h_14(double *state, double *unused, double *out_8082079656560248553) {
   out_8082079656560248553[0] = state[6];
   out_8082079656560248553[1] = state[7];
   out_8082079656560248553[2] = state[8];
}
void H_14(double *state, double *unused, double *out_71684720235664752) {
   out_71684720235664752[0] = 0;
   out_71684720235664752[1] = 0;
   out_71684720235664752[2] = 0;
   out_71684720235664752[3] = 0;
   out_71684720235664752[4] = 0;
   out_71684720235664752[5] = 0;
   out_71684720235664752[6] = 1;
   out_71684720235664752[7] = 0;
   out_71684720235664752[8] = 0;
   out_71684720235664752[9] = 0;
   out_71684720235664752[10] = 0;
   out_71684720235664752[11] = 0;
   out_71684720235664752[12] = 0;
   out_71684720235664752[13] = 0;
   out_71684720235664752[14] = 0;
   out_71684720235664752[15] = 0;
   out_71684720235664752[16] = 0;
   out_71684720235664752[17] = 0;
   out_71684720235664752[18] = 0;
   out_71684720235664752[19] = 0;
   out_71684720235664752[20] = 0;
   out_71684720235664752[21] = 0;
   out_71684720235664752[22] = 0;
   out_71684720235664752[23] = 0;
   out_71684720235664752[24] = 0;
   out_71684720235664752[25] = 1;
   out_71684720235664752[26] = 0;
   out_71684720235664752[27] = 0;
   out_71684720235664752[28] = 0;
   out_71684720235664752[29] = 0;
   out_71684720235664752[30] = 0;
   out_71684720235664752[31] = 0;
   out_71684720235664752[32] = 0;
   out_71684720235664752[33] = 0;
   out_71684720235664752[34] = 0;
   out_71684720235664752[35] = 0;
   out_71684720235664752[36] = 0;
   out_71684720235664752[37] = 0;
   out_71684720235664752[38] = 0;
   out_71684720235664752[39] = 0;
   out_71684720235664752[40] = 0;
   out_71684720235664752[41] = 0;
   out_71684720235664752[42] = 0;
   out_71684720235664752[43] = 0;
   out_71684720235664752[44] = 1;
   out_71684720235664752[45] = 0;
   out_71684720235664752[46] = 0;
   out_71684720235664752[47] = 0;
   out_71684720235664752[48] = 0;
   out_71684720235664752[49] = 0;
   out_71684720235664752[50] = 0;
   out_71684720235664752[51] = 0;
   out_71684720235664752[52] = 0;
   out_71684720235664752[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_8820622560039895266) {
  err_fun(nom_x, delta_x, out_8820622560039895266);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4138258066495298222) {
  inv_err_fun(nom_x, true_x, out_4138258066495298222);
}
void pose_H_mod_fun(double *state, double *out_6211513613161177568) {
  H_mod_fun(state, out_6211513613161177568);
}
void pose_f_fun(double *state, double dt, double *out_5417900835208008336) {
  f_fun(state,  dt, out_5417900835208008336);
}
void pose_F_fun(double *state, double dt, double *out_3421518052388552051) {
  F_fun(state,  dt, out_3421518052388552051);
}
void pose_h_4(double *state, double *unused, double *out_7947650004784572605) {
  h_4(state, unused, out_7947650004784572605);
}
void pose_H_4(double *state, double *unused, double *out_4034925576575149281) {
  H_4(state, unused, out_4034925576575149281);
}
void pose_h_10(double *state, double *unused, double *out_6434353536820436852) {
  h_10(state, unused, out_6434353536820436852);
}
void pose_H_10(double *state, double *unused, double *out_4256257324261286174) {
  H_10(state, unused, out_4256257324261286174);
}
void pose_h_13(double *state, double *unused, double *out_348176217550400228) {
  h_13(state, unused, out_348176217550400228);
}
void pose_H_13(double *state, double *unused, double *out_3575705631741551648) {
  H_13(state, unused, out_3575705631741551648);
}
void pose_h_14(double *state, double *unused, double *out_8082079656560248553) {
  h_14(state, unused, out_8082079656560248553);
}
void pose_H_14(double *state, double *unused, double *out_71684720235664752) {
  H_14(state, unused, out_71684720235664752);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
