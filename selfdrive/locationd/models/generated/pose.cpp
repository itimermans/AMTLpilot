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
void err_fun(double *nom_x, double *delta_x, double *out_1274560327679420140) {
   out_1274560327679420140[0] = delta_x[0] + nom_x[0];
   out_1274560327679420140[1] = delta_x[1] + nom_x[1];
   out_1274560327679420140[2] = delta_x[2] + nom_x[2];
   out_1274560327679420140[3] = delta_x[3] + nom_x[3];
   out_1274560327679420140[4] = delta_x[4] + nom_x[4];
   out_1274560327679420140[5] = delta_x[5] + nom_x[5];
   out_1274560327679420140[6] = delta_x[6] + nom_x[6];
   out_1274560327679420140[7] = delta_x[7] + nom_x[7];
   out_1274560327679420140[8] = delta_x[8] + nom_x[8];
   out_1274560327679420140[9] = delta_x[9] + nom_x[9];
   out_1274560327679420140[10] = delta_x[10] + nom_x[10];
   out_1274560327679420140[11] = delta_x[11] + nom_x[11];
   out_1274560327679420140[12] = delta_x[12] + nom_x[12];
   out_1274560327679420140[13] = delta_x[13] + nom_x[13];
   out_1274560327679420140[14] = delta_x[14] + nom_x[14];
   out_1274560327679420140[15] = delta_x[15] + nom_x[15];
   out_1274560327679420140[16] = delta_x[16] + nom_x[16];
   out_1274560327679420140[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7078231132908780549) {
   out_7078231132908780549[0] = -nom_x[0] + true_x[0];
   out_7078231132908780549[1] = -nom_x[1] + true_x[1];
   out_7078231132908780549[2] = -nom_x[2] + true_x[2];
   out_7078231132908780549[3] = -nom_x[3] + true_x[3];
   out_7078231132908780549[4] = -nom_x[4] + true_x[4];
   out_7078231132908780549[5] = -nom_x[5] + true_x[5];
   out_7078231132908780549[6] = -nom_x[6] + true_x[6];
   out_7078231132908780549[7] = -nom_x[7] + true_x[7];
   out_7078231132908780549[8] = -nom_x[8] + true_x[8];
   out_7078231132908780549[9] = -nom_x[9] + true_x[9];
   out_7078231132908780549[10] = -nom_x[10] + true_x[10];
   out_7078231132908780549[11] = -nom_x[11] + true_x[11];
   out_7078231132908780549[12] = -nom_x[12] + true_x[12];
   out_7078231132908780549[13] = -nom_x[13] + true_x[13];
   out_7078231132908780549[14] = -nom_x[14] + true_x[14];
   out_7078231132908780549[15] = -nom_x[15] + true_x[15];
   out_7078231132908780549[16] = -nom_x[16] + true_x[16];
   out_7078231132908780549[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_3160026192531771035) {
   out_3160026192531771035[0] = 1.0;
   out_3160026192531771035[1] = 0.0;
   out_3160026192531771035[2] = 0.0;
   out_3160026192531771035[3] = 0.0;
   out_3160026192531771035[4] = 0.0;
   out_3160026192531771035[5] = 0.0;
   out_3160026192531771035[6] = 0.0;
   out_3160026192531771035[7] = 0.0;
   out_3160026192531771035[8] = 0.0;
   out_3160026192531771035[9] = 0.0;
   out_3160026192531771035[10] = 0.0;
   out_3160026192531771035[11] = 0.0;
   out_3160026192531771035[12] = 0.0;
   out_3160026192531771035[13] = 0.0;
   out_3160026192531771035[14] = 0.0;
   out_3160026192531771035[15] = 0.0;
   out_3160026192531771035[16] = 0.0;
   out_3160026192531771035[17] = 0.0;
   out_3160026192531771035[18] = 0.0;
   out_3160026192531771035[19] = 1.0;
   out_3160026192531771035[20] = 0.0;
   out_3160026192531771035[21] = 0.0;
   out_3160026192531771035[22] = 0.0;
   out_3160026192531771035[23] = 0.0;
   out_3160026192531771035[24] = 0.0;
   out_3160026192531771035[25] = 0.0;
   out_3160026192531771035[26] = 0.0;
   out_3160026192531771035[27] = 0.0;
   out_3160026192531771035[28] = 0.0;
   out_3160026192531771035[29] = 0.0;
   out_3160026192531771035[30] = 0.0;
   out_3160026192531771035[31] = 0.0;
   out_3160026192531771035[32] = 0.0;
   out_3160026192531771035[33] = 0.0;
   out_3160026192531771035[34] = 0.0;
   out_3160026192531771035[35] = 0.0;
   out_3160026192531771035[36] = 0.0;
   out_3160026192531771035[37] = 0.0;
   out_3160026192531771035[38] = 1.0;
   out_3160026192531771035[39] = 0.0;
   out_3160026192531771035[40] = 0.0;
   out_3160026192531771035[41] = 0.0;
   out_3160026192531771035[42] = 0.0;
   out_3160026192531771035[43] = 0.0;
   out_3160026192531771035[44] = 0.0;
   out_3160026192531771035[45] = 0.0;
   out_3160026192531771035[46] = 0.0;
   out_3160026192531771035[47] = 0.0;
   out_3160026192531771035[48] = 0.0;
   out_3160026192531771035[49] = 0.0;
   out_3160026192531771035[50] = 0.0;
   out_3160026192531771035[51] = 0.0;
   out_3160026192531771035[52] = 0.0;
   out_3160026192531771035[53] = 0.0;
   out_3160026192531771035[54] = 0.0;
   out_3160026192531771035[55] = 0.0;
   out_3160026192531771035[56] = 0.0;
   out_3160026192531771035[57] = 1.0;
   out_3160026192531771035[58] = 0.0;
   out_3160026192531771035[59] = 0.0;
   out_3160026192531771035[60] = 0.0;
   out_3160026192531771035[61] = 0.0;
   out_3160026192531771035[62] = 0.0;
   out_3160026192531771035[63] = 0.0;
   out_3160026192531771035[64] = 0.0;
   out_3160026192531771035[65] = 0.0;
   out_3160026192531771035[66] = 0.0;
   out_3160026192531771035[67] = 0.0;
   out_3160026192531771035[68] = 0.0;
   out_3160026192531771035[69] = 0.0;
   out_3160026192531771035[70] = 0.0;
   out_3160026192531771035[71] = 0.0;
   out_3160026192531771035[72] = 0.0;
   out_3160026192531771035[73] = 0.0;
   out_3160026192531771035[74] = 0.0;
   out_3160026192531771035[75] = 0.0;
   out_3160026192531771035[76] = 1.0;
   out_3160026192531771035[77] = 0.0;
   out_3160026192531771035[78] = 0.0;
   out_3160026192531771035[79] = 0.0;
   out_3160026192531771035[80] = 0.0;
   out_3160026192531771035[81] = 0.0;
   out_3160026192531771035[82] = 0.0;
   out_3160026192531771035[83] = 0.0;
   out_3160026192531771035[84] = 0.0;
   out_3160026192531771035[85] = 0.0;
   out_3160026192531771035[86] = 0.0;
   out_3160026192531771035[87] = 0.0;
   out_3160026192531771035[88] = 0.0;
   out_3160026192531771035[89] = 0.0;
   out_3160026192531771035[90] = 0.0;
   out_3160026192531771035[91] = 0.0;
   out_3160026192531771035[92] = 0.0;
   out_3160026192531771035[93] = 0.0;
   out_3160026192531771035[94] = 0.0;
   out_3160026192531771035[95] = 1.0;
   out_3160026192531771035[96] = 0.0;
   out_3160026192531771035[97] = 0.0;
   out_3160026192531771035[98] = 0.0;
   out_3160026192531771035[99] = 0.0;
   out_3160026192531771035[100] = 0.0;
   out_3160026192531771035[101] = 0.0;
   out_3160026192531771035[102] = 0.0;
   out_3160026192531771035[103] = 0.0;
   out_3160026192531771035[104] = 0.0;
   out_3160026192531771035[105] = 0.0;
   out_3160026192531771035[106] = 0.0;
   out_3160026192531771035[107] = 0.0;
   out_3160026192531771035[108] = 0.0;
   out_3160026192531771035[109] = 0.0;
   out_3160026192531771035[110] = 0.0;
   out_3160026192531771035[111] = 0.0;
   out_3160026192531771035[112] = 0.0;
   out_3160026192531771035[113] = 0.0;
   out_3160026192531771035[114] = 1.0;
   out_3160026192531771035[115] = 0.0;
   out_3160026192531771035[116] = 0.0;
   out_3160026192531771035[117] = 0.0;
   out_3160026192531771035[118] = 0.0;
   out_3160026192531771035[119] = 0.0;
   out_3160026192531771035[120] = 0.0;
   out_3160026192531771035[121] = 0.0;
   out_3160026192531771035[122] = 0.0;
   out_3160026192531771035[123] = 0.0;
   out_3160026192531771035[124] = 0.0;
   out_3160026192531771035[125] = 0.0;
   out_3160026192531771035[126] = 0.0;
   out_3160026192531771035[127] = 0.0;
   out_3160026192531771035[128] = 0.0;
   out_3160026192531771035[129] = 0.0;
   out_3160026192531771035[130] = 0.0;
   out_3160026192531771035[131] = 0.0;
   out_3160026192531771035[132] = 0.0;
   out_3160026192531771035[133] = 1.0;
   out_3160026192531771035[134] = 0.0;
   out_3160026192531771035[135] = 0.0;
   out_3160026192531771035[136] = 0.0;
   out_3160026192531771035[137] = 0.0;
   out_3160026192531771035[138] = 0.0;
   out_3160026192531771035[139] = 0.0;
   out_3160026192531771035[140] = 0.0;
   out_3160026192531771035[141] = 0.0;
   out_3160026192531771035[142] = 0.0;
   out_3160026192531771035[143] = 0.0;
   out_3160026192531771035[144] = 0.0;
   out_3160026192531771035[145] = 0.0;
   out_3160026192531771035[146] = 0.0;
   out_3160026192531771035[147] = 0.0;
   out_3160026192531771035[148] = 0.0;
   out_3160026192531771035[149] = 0.0;
   out_3160026192531771035[150] = 0.0;
   out_3160026192531771035[151] = 0.0;
   out_3160026192531771035[152] = 1.0;
   out_3160026192531771035[153] = 0.0;
   out_3160026192531771035[154] = 0.0;
   out_3160026192531771035[155] = 0.0;
   out_3160026192531771035[156] = 0.0;
   out_3160026192531771035[157] = 0.0;
   out_3160026192531771035[158] = 0.0;
   out_3160026192531771035[159] = 0.0;
   out_3160026192531771035[160] = 0.0;
   out_3160026192531771035[161] = 0.0;
   out_3160026192531771035[162] = 0.0;
   out_3160026192531771035[163] = 0.0;
   out_3160026192531771035[164] = 0.0;
   out_3160026192531771035[165] = 0.0;
   out_3160026192531771035[166] = 0.0;
   out_3160026192531771035[167] = 0.0;
   out_3160026192531771035[168] = 0.0;
   out_3160026192531771035[169] = 0.0;
   out_3160026192531771035[170] = 0.0;
   out_3160026192531771035[171] = 1.0;
   out_3160026192531771035[172] = 0.0;
   out_3160026192531771035[173] = 0.0;
   out_3160026192531771035[174] = 0.0;
   out_3160026192531771035[175] = 0.0;
   out_3160026192531771035[176] = 0.0;
   out_3160026192531771035[177] = 0.0;
   out_3160026192531771035[178] = 0.0;
   out_3160026192531771035[179] = 0.0;
   out_3160026192531771035[180] = 0.0;
   out_3160026192531771035[181] = 0.0;
   out_3160026192531771035[182] = 0.0;
   out_3160026192531771035[183] = 0.0;
   out_3160026192531771035[184] = 0.0;
   out_3160026192531771035[185] = 0.0;
   out_3160026192531771035[186] = 0.0;
   out_3160026192531771035[187] = 0.0;
   out_3160026192531771035[188] = 0.0;
   out_3160026192531771035[189] = 0.0;
   out_3160026192531771035[190] = 1.0;
   out_3160026192531771035[191] = 0.0;
   out_3160026192531771035[192] = 0.0;
   out_3160026192531771035[193] = 0.0;
   out_3160026192531771035[194] = 0.0;
   out_3160026192531771035[195] = 0.0;
   out_3160026192531771035[196] = 0.0;
   out_3160026192531771035[197] = 0.0;
   out_3160026192531771035[198] = 0.0;
   out_3160026192531771035[199] = 0.0;
   out_3160026192531771035[200] = 0.0;
   out_3160026192531771035[201] = 0.0;
   out_3160026192531771035[202] = 0.0;
   out_3160026192531771035[203] = 0.0;
   out_3160026192531771035[204] = 0.0;
   out_3160026192531771035[205] = 0.0;
   out_3160026192531771035[206] = 0.0;
   out_3160026192531771035[207] = 0.0;
   out_3160026192531771035[208] = 0.0;
   out_3160026192531771035[209] = 1.0;
   out_3160026192531771035[210] = 0.0;
   out_3160026192531771035[211] = 0.0;
   out_3160026192531771035[212] = 0.0;
   out_3160026192531771035[213] = 0.0;
   out_3160026192531771035[214] = 0.0;
   out_3160026192531771035[215] = 0.0;
   out_3160026192531771035[216] = 0.0;
   out_3160026192531771035[217] = 0.0;
   out_3160026192531771035[218] = 0.0;
   out_3160026192531771035[219] = 0.0;
   out_3160026192531771035[220] = 0.0;
   out_3160026192531771035[221] = 0.0;
   out_3160026192531771035[222] = 0.0;
   out_3160026192531771035[223] = 0.0;
   out_3160026192531771035[224] = 0.0;
   out_3160026192531771035[225] = 0.0;
   out_3160026192531771035[226] = 0.0;
   out_3160026192531771035[227] = 0.0;
   out_3160026192531771035[228] = 1.0;
   out_3160026192531771035[229] = 0.0;
   out_3160026192531771035[230] = 0.0;
   out_3160026192531771035[231] = 0.0;
   out_3160026192531771035[232] = 0.0;
   out_3160026192531771035[233] = 0.0;
   out_3160026192531771035[234] = 0.0;
   out_3160026192531771035[235] = 0.0;
   out_3160026192531771035[236] = 0.0;
   out_3160026192531771035[237] = 0.0;
   out_3160026192531771035[238] = 0.0;
   out_3160026192531771035[239] = 0.0;
   out_3160026192531771035[240] = 0.0;
   out_3160026192531771035[241] = 0.0;
   out_3160026192531771035[242] = 0.0;
   out_3160026192531771035[243] = 0.0;
   out_3160026192531771035[244] = 0.0;
   out_3160026192531771035[245] = 0.0;
   out_3160026192531771035[246] = 0.0;
   out_3160026192531771035[247] = 1.0;
   out_3160026192531771035[248] = 0.0;
   out_3160026192531771035[249] = 0.0;
   out_3160026192531771035[250] = 0.0;
   out_3160026192531771035[251] = 0.0;
   out_3160026192531771035[252] = 0.0;
   out_3160026192531771035[253] = 0.0;
   out_3160026192531771035[254] = 0.0;
   out_3160026192531771035[255] = 0.0;
   out_3160026192531771035[256] = 0.0;
   out_3160026192531771035[257] = 0.0;
   out_3160026192531771035[258] = 0.0;
   out_3160026192531771035[259] = 0.0;
   out_3160026192531771035[260] = 0.0;
   out_3160026192531771035[261] = 0.0;
   out_3160026192531771035[262] = 0.0;
   out_3160026192531771035[263] = 0.0;
   out_3160026192531771035[264] = 0.0;
   out_3160026192531771035[265] = 0.0;
   out_3160026192531771035[266] = 1.0;
   out_3160026192531771035[267] = 0.0;
   out_3160026192531771035[268] = 0.0;
   out_3160026192531771035[269] = 0.0;
   out_3160026192531771035[270] = 0.0;
   out_3160026192531771035[271] = 0.0;
   out_3160026192531771035[272] = 0.0;
   out_3160026192531771035[273] = 0.0;
   out_3160026192531771035[274] = 0.0;
   out_3160026192531771035[275] = 0.0;
   out_3160026192531771035[276] = 0.0;
   out_3160026192531771035[277] = 0.0;
   out_3160026192531771035[278] = 0.0;
   out_3160026192531771035[279] = 0.0;
   out_3160026192531771035[280] = 0.0;
   out_3160026192531771035[281] = 0.0;
   out_3160026192531771035[282] = 0.0;
   out_3160026192531771035[283] = 0.0;
   out_3160026192531771035[284] = 0.0;
   out_3160026192531771035[285] = 1.0;
   out_3160026192531771035[286] = 0.0;
   out_3160026192531771035[287] = 0.0;
   out_3160026192531771035[288] = 0.0;
   out_3160026192531771035[289] = 0.0;
   out_3160026192531771035[290] = 0.0;
   out_3160026192531771035[291] = 0.0;
   out_3160026192531771035[292] = 0.0;
   out_3160026192531771035[293] = 0.0;
   out_3160026192531771035[294] = 0.0;
   out_3160026192531771035[295] = 0.0;
   out_3160026192531771035[296] = 0.0;
   out_3160026192531771035[297] = 0.0;
   out_3160026192531771035[298] = 0.0;
   out_3160026192531771035[299] = 0.0;
   out_3160026192531771035[300] = 0.0;
   out_3160026192531771035[301] = 0.0;
   out_3160026192531771035[302] = 0.0;
   out_3160026192531771035[303] = 0.0;
   out_3160026192531771035[304] = 1.0;
   out_3160026192531771035[305] = 0.0;
   out_3160026192531771035[306] = 0.0;
   out_3160026192531771035[307] = 0.0;
   out_3160026192531771035[308] = 0.0;
   out_3160026192531771035[309] = 0.0;
   out_3160026192531771035[310] = 0.0;
   out_3160026192531771035[311] = 0.0;
   out_3160026192531771035[312] = 0.0;
   out_3160026192531771035[313] = 0.0;
   out_3160026192531771035[314] = 0.0;
   out_3160026192531771035[315] = 0.0;
   out_3160026192531771035[316] = 0.0;
   out_3160026192531771035[317] = 0.0;
   out_3160026192531771035[318] = 0.0;
   out_3160026192531771035[319] = 0.0;
   out_3160026192531771035[320] = 0.0;
   out_3160026192531771035[321] = 0.0;
   out_3160026192531771035[322] = 0.0;
   out_3160026192531771035[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_4428667581613203302) {
   out_4428667581613203302[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_4428667581613203302[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_4428667581613203302[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_4428667581613203302[3] = dt*state[12] + state[3];
   out_4428667581613203302[4] = dt*state[13] + state[4];
   out_4428667581613203302[5] = dt*state[14] + state[5];
   out_4428667581613203302[6] = state[6];
   out_4428667581613203302[7] = state[7];
   out_4428667581613203302[8] = state[8];
   out_4428667581613203302[9] = state[9];
   out_4428667581613203302[10] = state[10];
   out_4428667581613203302[11] = state[11];
   out_4428667581613203302[12] = state[12];
   out_4428667581613203302[13] = state[13];
   out_4428667581613203302[14] = state[14];
   out_4428667581613203302[15] = state[15];
   out_4428667581613203302[16] = state[16];
   out_4428667581613203302[17] = state[17];
}
void F_fun(double *state, double dt, double *out_6306269892704480251) {
   out_6306269892704480251[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6306269892704480251[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6306269892704480251[2] = 0;
   out_6306269892704480251[3] = 0;
   out_6306269892704480251[4] = 0;
   out_6306269892704480251[5] = 0;
   out_6306269892704480251[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6306269892704480251[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6306269892704480251[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6306269892704480251[9] = 0;
   out_6306269892704480251[10] = 0;
   out_6306269892704480251[11] = 0;
   out_6306269892704480251[12] = 0;
   out_6306269892704480251[13] = 0;
   out_6306269892704480251[14] = 0;
   out_6306269892704480251[15] = 0;
   out_6306269892704480251[16] = 0;
   out_6306269892704480251[17] = 0;
   out_6306269892704480251[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6306269892704480251[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6306269892704480251[20] = 0;
   out_6306269892704480251[21] = 0;
   out_6306269892704480251[22] = 0;
   out_6306269892704480251[23] = 0;
   out_6306269892704480251[24] = 0;
   out_6306269892704480251[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6306269892704480251[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6306269892704480251[27] = 0;
   out_6306269892704480251[28] = 0;
   out_6306269892704480251[29] = 0;
   out_6306269892704480251[30] = 0;
   out_6306269892704480251[31] = 0;
   out_6306269892704480251[32] = 0;
   out_6306269892704480251[33] = 0;
   out_6306269892704480251[34] = 0;
   out_6306269892704480251[35] = 0;
   out_6306269892704480251[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6306269892704480251[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6306269892704480251[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6306269892704480251[39] = 0;
   out_6306269892704480251[40] = 0;
   out_6306269892704480251[41] = 0;
   out_6306269892704480251[42] = 0;
   out_6306269892704480251[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6306269892704480251[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6306269892704480251[45] = 0;
   out_6306269892704480251[46] = 0;
   out_6306269892704480251[47] = 0;
   out_6306269892704480251[48] = 0;
   out_6306269892704480251[49] = 0;
   out_6306269892704480251[50] = 0;
   out_6306269892704480251[51] = 0;
   out_6306269892704480251[52] = 0;
   out_6306269892704480251[53] = 0;
   out_6306269892704480251[54] = 0;
   out_6306269892704480251[55] = 0;
   out_6306269892704480251[56] = 0;
   out_6306269892704480251[57] = 1;
   out_6306269892704480251[58] = 0;
   out_6306269892704480251[59] = 0;
   out_6306269892704480251[60] = 0;
   out_6306269892704480251[61] = 0;
   out_6306269892704480251[62] = 0;
   out_6306269892704480251[63] = 0;
   out_6306269892704480251[64] = 0;
   out_6306269892704480251[65] = 0;
   out_6306269892704480251[66] = dt;
   out_6306269892704480251[67] = 0;
   out_6306269892704480251[68] = 0;
   out_6306269892704480251[69] = 0;
   out_6306269892704480251[70] = 0;
   out_6306269892704480251[71] = 0;
   out_6306269892704480251[72] = 0;
   out_6306269892704480251[73] = 0;
   out_6306269892704480251[74] = 0;
   out_6306269892704480251[75] = 0;
   out_6306269892704480251[76] = 1;
   out_6306269892704480251[77] = 0;
   out_6306269892704480251[78] = 0;
   out_6306269892704480251[79] = 0;
   out_6306269892704480251[80] = 0;
   out_6306269892704480251[81] = 0;
   out_6306269892704480251[82] = 0;
   out_6306269892704480251[83] = 0;
   out_6306269892704480251[84] = 0;
   out_6306269892704480251[85] = dt;
   out_6306269892704480251[86] = 0;
   out_6306269892704480251[87] = 0;
   out_6306269892704480251[88] = 0;
   out_6306269892704480251[89] = 0;
   out_6306269892704480251[90] = 0;
   out_6306269892704480251[91] = 0;
   out_6306269892704480251[92] = 0;
   out_6306269892704480251[93] = 0;
   out_6306269892704480251[94] = 0;
   out_6306269892704480251[95] = 1;
   out_6306269892704480251[96] = 0;
   out_6306269892704480251[97] = 0;
   out_6306269892704480251[98] = 0;
   out_6306269892704480251[99] = 0;
   out_6306269892704480251[100] = 0;
   out_6306269892704480251[101] = 0;
   out_6306269892704480251[102] = 0;
   out_6306269892704480251[103] = 0;
   out_6306269892704480251[104] = dt;
   out_6306269892704480251[105] = 0;
   out_6306269892704480251[106] = 0;
   out_6306269892704480251[107] = 0;
   out_6306269892704480251[108] = 0;
   out_6306269892704480251[109] = 0;
   out_6306269892704480251[110] = 0;
   out_6306269892704480251[111] = 0;
   out_6306269892704480251[112] = 0;
   out_6306269892704480251[113] = 0;
   out_6306269892704480251[114] = 1;
   out_6306269892704480251[115] = 0;
   out_6306269892704480251[116] = 0;
   out_6306269892704480251[117] = 0;
   out_6306269892704480251[118] = 0;
   out_6306269892704480251[119] = 0;
   out_6306269892704480251[120] = 0;
   out_6306269892704480251[121] = 0;
   out_6306269892704480251[122] = 0;
   out_6306269892704480251[123] = 0;
   out_6306269892704480251[124] = 0;
   out_6306269892704480251[125] = 0;
   out_6306269892704480251[126] = 0;
   out_6306269892704480251[127] = 0;
   out_6306269892704480251[128] = 0;
   out_6306269892704480251[129] = 0;
   out_6306269892704480251[130] = 0;
   out_6306269892704480251[131] = 0;
   out_6306269892704480251[132] = 0;
   out_6306269892704480251[133] = 1;
   out_6306269892704480251[134] = 0;
   out_6306269892704480251[135] = 0;
   out_6306269892704480251[136] = 0;
   out_6306269892704480251[137] = 0;
   out_6306269892704480251[138] = 0;
   out_6306269892704480251[139] = 0;
   out_6306269892704480251[140] = 0;
   out_6306269892704480251[141] = 0;
   out_6306269892704480251[142] = 0;
   out_6306269892704480251[143] = 0;
   out_6306269892704480251[144] = 0;
   out_6306269892704480251[145] = 0;
   out_6306269892704480251[146] = 0;
   out_6306269892704480251[147] = 0;
   out_6306269892704480251[148] = 0;
   out_6306269892704480251[149] = 0;
   out_6306269892704480251[150] = 0;
   out_6306269892704480251[151] = 0;
   out_6306269892704480251[152] = 1;
   out_6306269892704480251[153] = 0;
   out_6306269892704480251[154] = 0;
   out_6306269892704480251[155] = 0;
   out_6306269892704480251[156] = 0;
   out_6306269892704480251[157] = 0;
   out_6306269892704480251[158] = 0;
   out_6306269892704480251[159] = 0;
   out_6306269892704480251[160] = 0;
   out_6306269892704480251[161] = 0;
   out_6306269892704480251[162] = 0;
   out_6306269892704480251[163] = 0;
   out_6306269892704480251[164] = 0;
   out_6306269892704480251[165] = 0;
   out_6306269892704480251[166] = 0;
   out_6306269892704480251[167] = 0;
   out_6306269892704480251[168] = 0;
   out_6306269892704480251[169] = 0;
   out_6306269892704480251[170] = 0;
   out_6306269892704480251[171] = 1;
   out_6306269892704480251[172] = 0;
   out_6306269892704480251[173] = 0;
   out_6306269892704480251[174] = 0;
   out_6306269892704480251[175] = 0;
   out_6306269892704480251[176] = 0;
   out_6306269892704480251[177] = 0;
   out_6306269892704480251[178] = 0;
   out_6306269892704480251[179] = 0;
   out_6306269892704480251[180] = 0;
   out_6306269892704480251[181] = 0;
   out_6306269892704480251[182] = 0;
   out_6306269892704480251[183] = 0;
   out_6306269892704480251[184] = 0;
   out_6306269892704480251[185] = 0;
   out_6306269892704480251[186] = 0;
   out_6306269892704480251[187] = 0;
   out_6306269892704480251[188] = 0;
   out_6306269892704480251[189] = 0;
   out_6306269892704480251[190] = 1;
   out_6306269892704480251[191] = 0;
   out_6306269892704480251[192] = 0;
   out_6306269892704480251[193] = 0;
   out_6306269892704480251[194] = 0;
   out_6306269892704480251[195] = 0;
   out_6306269892704480251[196] = 0;
   out_6306269892704480251[197] = 0;
   out_6306269892704480251[198] = 0;
   out_6306269892704480251[199] = 0;
   out_6306269892704480251[200] = 0;
   out_6306269892704480251[201] = 0;
   out_6306269892704480251[202] = 0;
   out_6306269892704480251[203] = 0;
   out_6306269892704480251[204] = 0;
   out_6306269892704480251[205] = 0;
   out_6306269892704480251[206] = 0;
   out_6306269892704480251[207] = 0;
   out_6306269892704480251[208] = 0;
   out_6306269892704480251[209] = 1;
   out_6306269892704480251[210] = 0;
   out_6306269892704480251[211] = 0;
   out_6306269892704480251[212] = 0;
   out_6306269892704480251[213] = 0;
   out_6306269892704480251[214] = 0;
   out_6306269892704480251[215] = 0;
   out_6306269892704480251[216] = 0;
   out_6306269892704480251[217] = 0;
   out_6306269892704480251[218] = 0;
   out_6306269892704480251[219] = 0;
   out_6306269892704480251[220] = 0;
   out_6306269892704480251[221] = 0;
   out_6306269892704480251[222] = 0;
   out_6306269892704480251[223] = 0;
   out_6306269892704480251[224] = 0;
   out_6306269892704480251[225] = 0;
   out_6306269892704480251[226] = 0;
   out_6306269892704480251[227] = 0;
   out_6306269892704480251[228] = 1;
   out_6306269892704480251[229] = 0;
   out_6306269892704480251[230] = 0;
   out_6306269892704480251[231] = 0;
   out_6306269892704480251[232] = 0;
   out_6306269892704480251[233] = 0;
   out_6306269892704480251[234] = 0;
   out_6306269892704480251[235] = 0;
   out_6306269892704480251[236] = 0;
   out_6306269892704480251[237] = 0;
   out_6306269892704480251[238] = 0;
   out_6306269892704480251[239] = 0;
   out_6306269892704480251[240] = 0;
   out_6306269892704480251[241] = 0;
   out_6306269892704480251[242] = 0;
   out_6306269892704480251[243] = 0;
   out_6306269892704480251[244] = 0;
   out_6306269892704480251[245] = 0;
   out_6306269892704480251[246] = 0;
   out_6306269892704480251[247] = 1;
   out_6306269892704480251[248] = 0;
   out_6306269892704480251[249] = 0;
   out_6306269892704480251[250] = 0;
   out_6306269892704480251[251] = 0;
   out_6306269892704480251[252] = 0;
   out_6306269892704480251[253] = 0;
   out_6306269892704480251[254] = 0;
   out_6306269892704480251[255] = 0;
   out_6306269892704480251[256] = 0;
   out_6306269892704480251[257] = 0;
   out_6306269892704480251[258] = 0;
   out_6306269892704480251[259] = 0;
   out_6306269892704480251[260] = 0;
   out_6306269892704480251[261] = 0;
   out_6306269892704480251[262] = 0;
   out_6306269892704480251[263] = 0;
   out_6306269892704480251[264] = 0;
   out_6306269892704480251[265] = 0;
   out_6306269892704480251[266] = 1;
   out_6306269892704480251[267] = 0;
   out_6306269892704480251[268] = 0;
   out_6306269892704480251[269] = 0;
   out_6306269892704480251[270] = 0;
   out_6306269892704480251[271] = 0;
   out_6306269892704480251[272] = 0;
   out_6306269892704480251[273] = 0;
   out_6306269892704480251[274] = 0;
   out_6306269892704480251[275] = 0;
   out_6306269892704480251[276] = 0;
   out_6306269892704480251[277] = 0;
   out_6306269892704480251[278] = 0;
   out_6306269892704480251[279] = 0;
   out_6306269892704480251[280] = 0;
   out_6306269892704480251[281] = 0;
   out_6306269892704480251[282] = 0;
   out_6306269892704480251[283] = 0;
   out_6306269892704480251[284] = 0;
   out_6306269892704480251[285] = 1;
   out_6306269892704480251[286] = 0;
   out_6306269892704480251[287] = 0;
   out_6306269892704480251[288] = 0;
   out_6306269892704480251[289] = 0;
   out_6306269892704480251[290] = 0;
   out_6306269892704480251[291] = 0;
   out_6306269892704480251[292] = 0;
   out_6306269892704480251[293] = 0;
   out_6306269892704480251[294] = 0;
   out_6306269892704480251[295] = 0;
   out_6306269892704480251[296] = 0;
   out_6306269892704480251[297] = 0;
   out_6306269892704480251[298] = 0;
   out_6306269892704480251[299] = 0;
   out_6306269892704480251[300] = 0;
   out_6306269892704480251[301] = 0;
   out_6306269892704480251[302] = 0;
   out_6306269892704480251[303] = 0;
   out_6306269892704480251[304] = 1;
   out_6306269892704480251[305] = 0;
   out_6306269892704480251[306] = 0;
   out_6306269892704480251[307] = 0;
   out_6306269892704480251[308] = 0;
   out_6306269892704480251[309] = 0;
   out_6306269892704480251[310] = 0;
   out_6306269892704480251[311] = 0;
   out_6306269892704480251[312] = 0;
   out_6306269892704480251[313] = 0;
   out_6306269892704480251[314] = 0;
   out_6306269892704480251[315] = 0;
   out_6306269892704480251[316] = 0;
   out_6306269892704480251[317] = 0;
   out_6306269892704480251[318] = 0;
   out_6306269892704480251[319] = 0;
   out_6306269892704480251[320] = 0;
   out_6306269892704480251[321] = 0;
   out_6306269892704480251[322] = 0;
   out_6306269892704480251[323] = 1;
}
void h_4(double *state, double *unused, double *out_780706365605131756) {
   out_780706365605131756[0] = state[6] + state[9];
   out_780706365605131756[1] = state[7] + state[10];
   out_780706365605131756[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_3914187194586483642) {
   out_3914187194586483642[0] = 0;
   out_3914187194586483642[1] = 0;
   out_3914187194586483642[2] = 0;
   out_3914187194586483642[3] = 0;
   out_3914187194586483642[4] = 0;
   out_3914187194586483642[5] = 0;
   out_3914187194586483642[6] = 1;
   out_3914187194586483642[7] = 0;
   out_3914187194586483642[8] = 0;
   out_3914187194586483642[9] = 1;
   out_3914187194586483642[10] = 0;
   out_3914187194586483642[11] = 0;
   out_3914187194586483642[12] = 0;
   out_3914187194586483642[13] = 0;
   out_3914187194586483642[14] = 0;
   out_3914187194586483642[15] = 0;
   out_3914187194586483642[16] = 0;
   out_3914187194586483642[17] = 0;
   out_3914187194586483642[18] = 0;
   out_3914187194586483642[19] = 0;
   out_3914187194586483642[20] = 0;
   out_3914187194586483642[21] = 0;
   out_3914187194586483642[22] = 0;
   out_3914187194586483642[23] = 0;
   out_3914187194586483642[24] = 0;
   out_3914187194586483642[25] = 1;
   out_3914187194586483642[26] = 0;
   out_3914187194586483642[27] = 0;
   out_3914187194586483642[28] = 1;
   out_3914187194586483642[29] = 0;
   out_3914187194586483642[30] = 0;
   out_3914187194586483642[31] = 0;
   out_3914187194586483642[32] = 0;
   out_3914187194586483642[33] = 0;
   out_3914187194586483642[34] = 0;
   out_3914187194586483642[35] = 0;
   out_3914187194586483642[36] = 0;
   out_3914187194586483642[37] = 0;
   out_3914187194586483642[38] = 0;
   out_3914187194586483642[39] = 0;
   out_3914187194586483642[40] = 0;
   out_3914187194586483642[41] = 0;
   out_3914187194586483642[42] = 0;
   out_3914187194586483642[43] = 0;
   out_3914187194586483642[44] = 1;
   out_3914187194586483642[45] = 0;
   out_3914187194586483642[46] = 0;
   out_3914187194586483642[47] = 1;
   out_3914187194586483642[48] = 0;
   out_3914187194586483642[49] = 0;
   out_3914187194586483642[50] = 0;
   out_3914187194586483642[51] = 0;
   out_3914187194586483642[52] = 0;
   out_3914187194586483642[53] = 0;
}
void h_10(double *state, double *unused, double *out_4218786315389702128) {
   out_4218786315389702128[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_4218786315389702128[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_4218786315389702128[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_2207618639460829152) {
   out_2207618639460829152[0] = 0;
   out_2207618639460829152[1] = 9.8100000000000005*cos(state[1]);
   out_2207618639460829152[2] = 0;
   out_2207618639460829152[3] = 0;
   out_2207618639460829152[4] = -state[8];
   out_2207618639460829152[5] = state[7];
   out_2207618639460829152[6] = 0;
   out_2207618639460829152[7] = state[5];
   out_2207618639460829152[8] = -state[4];
   out_2207618639460829152[9] = 0;
   out_2207618639460829152[10] = 0;
   out_2207618639460829152[11] = 0;
   out_2207618639460829152[12] = 1;
   out_2207618639460829152[13] = 0;
   out_2207618639460829152[14] = 0;
   out_2207618639460829152[15] = 1;
   out_2207618639460829152[16] = 0;
   out_2207618639460829152[17] = 0;
   out_2207618639460829152[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_2207618639460829152[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_2207618639460829152[20] = 0;
   out_2207618639460829152[21] = state[8];
   out_2207618639460829152[22] = 0;
   out_2207618639460829152[23] = -state[6];
   out_2207618639460829152[24] = -state[5];
   out_2207618639460829152[25] = 0;
   out_2207618639460829152[26] = state[3];
   out_2207618639460829152[27] = 0;
   out_2207618639460829152[28] = 0;
   out_2207618639460829152[29] = 0;
   out_2207618639460829152[30] = 0;
   out_2207618639460829152[31] = 1;
   out_2207618639460829152[32] = 0;
   out_2207618639460829152[33] = 0;
   out_2207618639460829152[34] = 1;
   out_2207618639460829152[35] = 0;
   out_2207618639460829152[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_2207618639460829152[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_2207618639460829152[38] = 0;
   out_2207618639460829152[39] = -state[7];
   out_2207618639460829152[40] = state[6];
   out_2207618639460829152[41] = 0;
   out_2207618639460829152[42] = state[4];
   out_2207618639460829152[43] = -state[3];
   out_2207618639460829152[44] = 0;
   out_2207618639460829152[45] = 0;
   out_2207618639460829152[46] = 0;
   out_2207618639460829152[47] = 0;
   out_2207618639460829152[48] = 0;
   out_2207618639460829152[49] = 0;
   out_2207618639460829152[50] = 1;
   out_2207618639460829152[51] = 0;
   out_2207618639460829152[52] = 0;
   out_2207618639460829152[53] = 1;
}
void h_13(double *state, double *unused, double *out_3970942575106541800) {
   out_3970942575106541800[0] = state[3];
   out_3970942575106541800[1] = state[4];
   out_3970942575106541800[2] = state[5];
}
void H_13(double *state, double *unused, double *out_6921925670806367045) {
   out_6921925670806367045[0] = 0;
   out_6921925670806367045[1] = 0;
   out_6921925670806367045[2] = 0;
   out_6921925670806367045[3] = 1;
   out_6921925670806367045[4] = 0;
   out_6921925670806367045[5] = 0;
   out_6921925670806367045[6] = 0;
   out_6921925670806367045[7] = 0;
   out_6921925670806367045[8] = 0;
   out_6921925670806367045[9] = 0;
   out_6921925670806367045[10] = 0;
   out_6921925670806367045[11] = 0;
   out_6921925670806367045[12] = 0;
   out_6921925670806367045[13] = 0;
   out_6921925670806367045[14] = 0;
   out_6921925670806367045[15] = 0;
   out_6921925670806367045[16] = 0;
   out_6921925670806367045[17] = 0;
   out_6921925670806367045[18] = 0;
   out_6921925670806367045[19] = 0;
   out_6921925670806367045[20] = 0;
   out_6921925670806367045[21] = 0;
   out_6921925670806367045[22] = 1;
   out_6921925670806367045[23] = 0;
   out_6921925670806367045[24] = 0;
   out_6921925670806367045[25] = 0;
   out_6921925670806367045[26] = 0;
   out_6921925670806367045[27] = 0;
   out_6921925670806367045[28] = 0;
   out_6921925670806367045[29] = 0;
   out_6921925670806367045[30] = 0;
   out_6921925670806367045[31] = 0;
   out_6921925670806367045[32] = 0;
   out_6921925670806367045[33] = 0;
   out_6921925670806367045[34] = 0;
   out_6921925670806367045[35] = 0;
   out_6921925670806367045[36] = 0;
   out_6921925670806367045[37] = 0;
   out_6921925670806367045[38] = 0;
   out_6921925670806367045[39] = 0;
   out_6921925670806367045[40] = 0;
   out_6921925670806367045[41] = 1;
   out_6921925670806367045[42] = 0;
   out_6921925670806367045[43] = 0;
   out_6921925670806367045[44] = 0;
   out_6921925670806367045[45] = 0;
   out_6921925670806367045[46] = 0;
   out_6921925670806367045[47] = 0;
   out_6921925670806367045[48] = 0;
   out_6921925670806367045[49] = 0;
   out_6921925670806367045[50] = 0;
   out_6921925670806367045[51] = 0;
   out_6921925670806367045[52] = 0;
   out_6921925670806367045[53] = 0;
}
void h_14(double *state, double *unused, double *out_8889913689112628377) {
   out_8889913689112628377[0] = state[6];
   out_8889913689112628377[1] = state[7];
   out_8889913689112628377[2] = state[8];
}
void H_14(double *state, double *unused, double *out_7877428050925968171) {
   out_7877428050925968171[0] = 0;
   out_7877428050925968171[1] = 0;
   out_7877428050925968171[2] = 0;
   out_7877428050925968171[3] = 0;
   out_7877428050925968171[4] = 0;
   out_7877428050925968171[5] = 0;
   out_7877428050925968171[6] = 1;
   out_7877428050925968171[7] = 0;
   out_7877428050925968171[8] = 0;
   out_7877428050925968171[9] = 0;
   out_7877428050925968171[10] = 0;
   out_7877428050925968171[11] = 0;
   out_7877428050925968171[12] = 0;
   out_7877428050925968171[13] = 0;
   out_7877428050925968171[14] = 0;
   out_7877428050925968171[15] = 0;
   out_7877428050925968171[16] = 0;
   out_7877428050925968171[17] = 0;
   out_7877428050925968171[18] = 0;
   out_7877428050925968171[19] = 0;
   out_7877428050925968171[20] = 0;
   out_7877428050925968171[21] = 0;
   out_7877428050925968171[22] = 0;
   out_7877428050925968171[23] = 0;
   out_7877428050925968171[24] = 0;
   out_7877428050925968171[25] = 1;
   out_7877428050925968171[26] = 0;
   out_7877428050925968171[27] = 0;
   out_7877428050925968171[28] = 0;
   out_7877428050925968171[29] = 0;
   out_7877428050925968171[30] = 0;
   out_7877428050925968171[31] = 0;
   out_7877428050925968171[32] = 0;
   out_7877428050925968171[33] = 0;
   out_7877428050925968171[34] = 0;
   out_7877428050925968171[35] = 0;
   out_7877428050925968171[36] = 0;
   out_7877428050925968171[37] = 0;
   out_7877428050925968171[38] = 0;
   out_7877428050925968171[39] = 0;
   out_7877428050925968171[40] = 0;
   out_7877428050925968171[41] = 0;
   out_7877428050925968171[42] = 0;
   out_7877428050925968171[43] = 0;
   out_7877428050925968171[44] = 1;
   out_7877428050925968171[45] = 0;
   out_7877428050925968171[46] = 0;
   out_7877428050925968171[47] = 0;
   out_7877428050925968171[48] = 0;
   out_7877428050925968171[49] = 0;
   out_7877428050925968171[50] = 0;
   out_7877428050925968171[51] = 0;
   out_7877428050925968171[52] = 0;
   out_7877428050925968171[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_1274560327679420140) {
  err_fun(nom_x, delta_x, out_1274560327679420140);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7078231132908780549) {
  inv_err_fun(nom_x, true_x, out_7078231132908780549);
}
void pose_H_mod_fun(double *state, double *out_3160026192531771035) {
  H_mod_fun(state, out_3160026192531771035);
}
void pose_f_fun(double *state, double dt, double *out_4428667581613203302) {
  f_fun(state,  dt, out_4428667581613203302);
}
void pose_F_fun(double *state, double dt, double *out_6306269892704480251) {
  F_fun(state,  dt, out_6306269892704480251);
}
void pose_h_4(double *state, double *unused, double *out_780706365605131756) {
  h_4(state, unused, out_780706365605131756);
}
void pose_H_4(double *state, double *unused, double *out_3914187194586483642) {
  H_4(state, unused, out_3914187194586483642);
}
void pose_h_10(double *state, double *unused, double *out_4218786315389702128) {
  h_10(state, unused, out_4218786315389702128);
}
void pose_H_10(double *state, double *unused, double *out_2207618639460829152) {
  H_10(state, unused, out_2207618639460829152);
}
void pose_h_13(double *state, double *unused, double *out_3970942575106541800) {
  h_13(state, unused, out_3970942575106541800);
}
void pose_H_13(double *state, double *unused, double *out_6921925670806367045) {
  H_13(state, unused, out_6921925670806367045);
}
void pose_h_14(double *state, double *unused, double *out_8889913689112628377) {
  h_14(state, unused, out_8889913689112628377);
}
void pose_H_14(double *state, double *unused, double *out_7877428050925968171) {
  H_14(state, unused, out_7877428050925968171);
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
