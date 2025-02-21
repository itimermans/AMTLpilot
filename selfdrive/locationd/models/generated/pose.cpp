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
void err_fun(double *nom_x, double *delta_x, double *out_1072602497373551517) {
   out_1072602497373551517[0] = delta_x[0] + nom_x[0];
   out_1072602497373551517[1] = delta_x[1] + nom_x[1];
   out_1072602497373551517[2] = delta_x[2] + nom_x[2];
   out_1072602497373551517[3] = delta_x[3] + nom_x[3];
   out_1072602497373551517[4] = delta_x[4] + nom_x[4];
   out_1072602497373551517[5] = delta_x[5] + nom_x[5];
   out_1072602497373551517[6] = delta_x[6] + nom_x[6];
   out_1072602497373551517[7] = delta_x[7] + nom_x[7];
   out_1072602497373551517[8] = delta_x[8] + nom_x[8];
   out_1072602497373551517[9] = delta_x[9] + nom_x[9];
   out_1072602497373551517[10] = delta_x[10] + nom_x[10];
   out_1072602497373551517[11] = delta_x[11] + nom_x[11];
   out_1072602497373551517[12] = delta_x[12] + nom_x[12];
   out_1072602497373551517[13] = delta_x[13] + nom_x[13];
   out_1072602497373551517[14] = delta_x[14] + nom_x[14];
   out_1072602497373551517[15] = delta_x[15] + nom_x[15];
   out_1072602497373551517[16] = delta_x[16] + nom_x[16];
   out_1072602497373551517[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2245523438332106519) {
   out_2245523438332106519[0] = -nom_x[0] + true_x[0];
   out_2245523438332106519[1] = -nom_x[1] + true_x[1];
   out_2245523438332106519[2] = -nom_x[2] + true_x[2];
   out_2245523438332106519[3] = -nom_x[3] + true_x[3];
   out_2245523438332106519[4] = -nom_x[4] + true_x[4];
   out_2245523438332106519[5] = -nom_x[5] + true_x[5];
   out_2245523438332106519[6] = -nom_x[6] + true_x[6];
   out_2245523438332106519[7] = -nom_x[7] + true_x[7];
   out_2245523438332106519[8] = -nom_x[8] + true_x[8];
   out_2245523438332106519[9] = -nom_x[9] + true_x[9];
   out_2245523438332106519[10] = -nom_x[10] + true_x[10];
   out_2245523438332106519[11] = -nom_x[11] + true_x[11];
   out_2245523438332106519[12] = -nom_x[12] + true_x[12];
   out_2245523438332106519[13] = -nom_x[13] + true_x[13];
   out_2245523438332106519[14] = -nom_x[14] + true_x[14];
   out_2245523438332106519[15] = -nom_x[15] + true_x[15];
   out_2245523438332106519[16] = -nom_x[16] + true_x[16];
   out_2245523438332106519[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_1209108603363600393) {
   out_1209108603363600393[0] = 1.0;
   out_1209108603363600393[1] = 0.0;
   out_1209108603363600393[2] = 0.0;
   out_1209108603363600393[3] = 0.0;
   out_1209108603363600393[4] = 0.0;
   out_1209108603363600393[5] = 0.0;
   out_1209108603363600393[6] = 0.0;
   out_1209108603363600393[7] = 0.0;
   out_1209108603363600393[8] = 0.0;
   out_1209108603363600393[9] = 0.0;
   out_1209108603363600393[10] = 0.0;
   out_1209108603363600393[11] = 0.0;
   out_1209108603363600393[12] = 0.0;
   out_1209108603363600393[13] = 0.0;
   out_1209108603363600393[14] = 0.0;
   out_1209108603363600393[15] = 0.0;
   out_1209108603363600393[16] = 0.0;
   out_1209108603363600393[17] = 0.0;
   out_1209108603363600393[18] = 0.0;
   out_1209108603363600393[19] = 1.0;
   out_1209108603363600393[20] = 0.0;
   out_1209108603363600393[21] = 0.0;
   out_1209108603363600393[22] = 0.0;
   out_1209108603363600393[23] = 0.0;
   out_1209108603363600393[24] = 0.0;
   out_1209108603363600393[25] = 0.0;
   out_1209108603363600393[26] = 0.0;
   out_1209108603363600393[27] = 0.0;
   out_1209108603363600393[28] = 0.0;
   out_1209108603363600393[29] = 0.0;
   out_1209108603363600393[30] = 0.0;
   out_1209108603363600393[31] = 0.0;
   out_1209108603363600393[32] = 0.0;
   out_1209108603363600393[33] = 0.0;
   out_1209108603363600393[34] = 0.0;
   out_1209108603363600393[35] = 0.0;
   out_1209108603363600393[36] = 0.0;
   out_1209108603363600393[37] = 0.0;
   out_1209108603363600393[38] = 1.0;
   out_1209108603363600393[39] = 0.0;
   out_1209108603363600393[40] = 0.0;
   out_1209108603363600393[41] = 0.0;
   out_1209108603363600393[42] = 0.0;
   out_1209108603363600393[43] = 0.0;
   out_1209108603363600393[44] = 0.0;
   out_1209108603363600393[45] = 0.0;
   out_1209108603363600393[46] = 0.0;
   out_1209108603363600393[47] = 0.0;
   out_1209108603363600393[48] = 0.0;
   out_1209108603363600393[49] = 0.0;
   out_1209108603363600393[50] = 0.0;
   out_1209108603363600393[51] = 0.0;
   out_1209108603363600393[52] = 0.0;
   out_1209108603363600393[53] = 0.0;
   out_1209108603363600393[54] = 0.0;
   out_1209108603363600393[55] = 0.0;
   out_1209108603363600393[56] = 0.0;
   out_1209108603363600393[57] = 1.0;
   out_1209108603363600393[58] = 0.0;
   out_1209108603363600393[59] = 0.0;
   out_1209108603363600393[60] = 0.0;
   out_1209108603363600393[61] = 0.0;
   out_1209108603363600393[62] = 0.0;
   out_1209108603363600393[63] = 0.0;
   out_1209108603363600393[64] = 0.0;
   out_1209108603363600393[65] = 0.0;
   out_1209108603363600393[66] = 0.0;
   out_1209108603363600393[67] = 0.0;
   out_1209108603363600393[68] = 0.0;
   out_1209108603363600393[69] = 0.0;
   out_1209108603363600393[70] = 0.0;
   out_1209108603363600393[71] = 0.0;
   out_1209108603363600393[72] = 0.0;
   out_1209108603363600393[73] = 0.0;
   out_1209108603363600393[74] = 0.0;
   out_1209108603363600393[75] = 0.0;
   out_1209108603363600393[76] = 1.0;
   out_1209108603363600393[77] = 0.0;
   out_1209108603363600393[78] = 0.0;
   out_1209108603363600393[79] = 0.0;
   out_1209108603363600393[80] = 0.0;
   out_1209108603363600393[81] = 0.0;
   out_1209108603363600393[82] = 0.0;
   out_1209108603363600393[83] = 0.0;
   out_1209108603363600393[84] = 0.0;
   out_1209108603363600393[85] = 0.0;
   out_1209108603363600393[86] = 0.0;
   out_1209108603363600393[87] = 0.0;
   out_1209108603363600393[88] = 0.0;
   out_1209108603363600393[89] = 0.0;
   out_1209108603363600393[90] = 0.0;
   out_1209108603363600393[91] = 0.0;
   out_1209108603363600393[92] = 0.0;
   out_1209108603363600393[93] = 0.0;
   out_1209108603363600393[94] = 0.0;
   out_1209108603363600393[95] = 1.0;
   out_1209108603363600393[96] = 0.0;
   out_1209108603363600393[97] = 0.0;
   out_1209108603363600393[98] = 0.0;
   out_1209108603363600393[99] = 0.0;
   out_1209108603363600393[100] = 0.0;
   out_1209108603363600393[101] = 0.0;
   out_1209108603363600393[102] = 0.0;
   out_1209108603363600393[103] = 0.0;
   out_1209108603363600393[104] = 0.0;
   out_1209108603363600393[105] = 0.0;
   out_1209108603363600393[106] = 0.0;
   out_1209108603363600393[107] = 0.0;
   out_1209108603363600393[108] = 0.0;
   out_1209108603363600393[109] = 0.0;
   out_1209108603363600393[110] = 0.0;
   out_1209108603363600393[111] = 0.0;
   out_1209108603363600393[112] = 0.0;
   out_1209108603363600393[113] = 0.0;
   out_1209108603363600393[114] = 1.0;
   out_1209108603363600393[115] = 0.0;
   out_1209108603363600393[116] = 0.0;
   out_1209108603363600393[117] = 0.0;
   out_1209108603363600393[118] = 0.0;
   out_1209108603363600393[119] = 0.0;
   out_1209108603363600393[120] = 0.0;
   out_1209108603363600393[121] = 0.0;
   out_1209108603363600393[122] = 0.0;
   out_1209108603363600393[123] = 0.0;
   out_1209108603363600393[124] = 0.0;
   out_1209108603363600393[125] = 0.0;
   out_1209108603363600393[126] = 0.0;
   out_1209108603363600393[127] = 0.0;
   out_1209108603363600393[128] = 0.0;
   out_1209108603363600393[129] = 0.0;
   out_1209108603363600393[130] = 0.0;
   out_1209108603363600393[131] = 0.0;
   out_1209108603363600393[132] = 0.0;
   out_1209108603363600393[133] = 1.0;
   out_1209108603363600393[134] = 0.0;
   out_1209108603363600393[135] = 0.0;
   out_1209108603363600393[136] = 0.0;
   out_1209108603363600393[137] = 0.0;
   out_1209108603363600393[138] = 0.0;
   out_1209108603363600393[139] = 0.0;
   out_1209108603363600393[140] = 0.0;
   out_1209108603363600393[141] = 0.0;
   out_1209108603363600393[142] = 0.0;
   out_1209108603363600393[143] = 0.0;
   out_1209108603363600393[144] = 0.0;
   out_1209108603363600393[145] = 0.0;
   out_1209108603363600393[146] = 0.0;
   out_1209108603363600393[147] = 0.0;
   out_1209108603363600393[148] = 0.0;
   out_1209108603363600393[149] = 0.0;
   out_1209108603363600393[150] = 0.0;
   out_1209108603363600393[151] = 0.0;
   out_1209108603363600393[152] = 1.0;
   out_1209108603363600393[153] = 0.0;
   out_1209108603363600393[154] = 0.0;
   out_1209108603363600393[155] = 0.0;
   out_1209108603363600393[156] = 0.0;
   out_1209108603363600393[157] = 0.0;
   out_1209108603363600393[158] = 0.0;
   out_1209108603363600393[159] = 0.0;
   out_1209108603363600393[160] = 0.0;
   out_1209108603363600393[161] = 0.0;
   out_1209108603363600393[162] = 0.0;
   out_1209108603363600393[163] = 0.0;
   out_1209108603363600393[164] = 0.0;
   out_1209108603363600393[165] = 0.0;
   out_1209108603363600393[166] = 0.0;
   out_1209108603363600393[167] = 0.0;
   out_1209108603363600393[168] = 0.0;
   out_1209108603363600393[169] = 0.0;
   out_1209108603363600393[170] = 0.0;
   out_1209108603363600393[171] = 1.0;
   out_1209108603363600393[172] = 0.0;
   out_1209108603363600393[173] = 0.0;
   out_1209108603363600393[174] = 0.0;
   out_1209108603363600393[175] = 0.0;
   out_1209108603363600393[176] = 0.0;
   out_1209108603363600393[177] = 0.0;
   out_1209108603363600393[178] = 0.0;
   out_1209108603363600393[179] = 0.0;
   out_1209108603363600393[180] = 0.0;
   out_1209108603363600393[181] = 0.0;
   out_1209108603363600393[182] = 0.0;
   out_1209108603363600393[183] = 0.0;
   out_1209108603363600393[184] = 0.0;
   out_1209108603363600393[185] = 0.0;
   out_1209108603363600393[186] = 0.0;
   out_1209108603363600393[187] = 0.0;
   out_1209108603363600393[188] = 0.0;
   out_1209108603363600393[189] = 0.0;
   out_1209108603363600393[190] = 1.0;
   out_1209108603363600393[191] = 0.0;
   out_1209108603363600393[192] = 0.0;
   out_1209108603363600393[193] = 0.0;
   out_1209108603363600393[194] = 0.0;
   out_1209108603363600393[195] = 0.0;
   out_1209108603363600393[196] = 0.0;
   out_1209108603363600393[197] = 0.0;
   out_1209108603363600393[198] = 0.0;
   out_1209108603363600393[199] = 0.0;
   out_1209108603363600393[200] = 0.0;
   out_1209108603363600393[201] = 0.0;
   out_1209108603363600393[202] = 0.0;
   out_1209108603363600393[203] = 0.0;
   out_1209108603363600393[204] = 0.0;
   out_1209108603363600393[205] = 0.0;
   out_1209108603363600393[206] = 0.0;
   out_1209108603363600393[207] = 0.0;
   out_1209108603363600393[208] = 0.0;
   out_1209108603363600393[209] = 1.0;
   out_1209108603363600393[210] = 0.0;
   out_1209108603363600393[211] = 0.0;
   out_1209108603363600393[212] = 0.0;
   out_1209108603363600393[213] = 0.0;
   out_1209108603363600393[214] = 0.0;
   out_1209108603363600393[215] = 0.0;
   out_1209108603363600393[216] = 0.0;
   out_1209108603363600393[217] = 0.0;
   out_1209108603363600393[218] = 0.0;
   out_1209108603363600393[219] = 0.0;
   out_1209108603363600393[220] = 0.0;
   out_1209108603363600393[221] = 0.0;
   out_1209108603363600393[222] = 0.0;
   out_1209108603363600393[223] = 0.0;
   out_1209108603363600393[224] = 0.0;
   out_1209108603363600393[225] = 0.0;
   out_1209108603363600393[226] = 0.0;
   out_1209108603363600393[227] = 0.0;
   out_1209108603363600393[228] = 1.0;
   out_1209108603363600393[229] = 0.0;
   out_1209108603363600393[230] = 0.0;
   out_1209108603363600393[231] = 0.0;
   out_1209108603363600393[232] = 0.0;
   out_1209108603363600393[233] = 0.0;
   out_1209108603363600393[234] = 0.0;
   out_1209108603363600393[235] = 0.0;
   out_1209108603363600393[236] = 0.0;
   out_1209108603363600393[237] = 0.0;
   out_1209108603363600393[238] = 0.0;
   out_1209108603363600393[239] = 0.0;
   out_1209108603363600393[240] = 0.0;
   out_1209108603363600393[241] = 0.0;
   out_1209108603363600393[242] = 0.0;
   out_1209108603363600393[243] = 0.0;
   out_1209108603363600393[244] = 0.0;
   out_1209108603363600393[245] = 0.0;
   out_1209108603363600393[246] = 0.0;
   out_1209108603363600393[247] = 1.0;
   out_1209108603363600393[248] = 0.0;
   out_1209108603363600393[249] = 0.0;
   out_1209108603363600393[250] = 0.0;
   out_1209108603363600393[251] = 0.0;
   out_1209108603363600393[252] = 0.0;
   out_1209108603363600393[253] = 0.0;
   out_1209108603363600393[254] = 0.0;
   out_1209108603363600393[255] = 0.0;
   out_1209108603363600393[256] = 0.0;
   out_1209108603363600393[257] = 0.0;
   out_1209108603363600393[258] = 0.0;
   out_1209108603363600393[259] = 0.0;
   out_1209108603363600393[260] = 0.0;
   out_1209108603363600393[261] = 0.0;
   out_1209108603363600393[262] = 0.0;
   out_1209108603363600393[263] = 0.0;
   out_1209108603363600393[264] = 0.0;
   out_1209108603363600393[265] = 0.0;
   out_1209108603363600393[266] = 1.0;
   out_1209108603363600393[267] = 0.0;
   out_1209108603363600393[268] = 0.0;
   out_1209108603363600393[269] = 0.0;
   out_1209108603363600393[270] = 0.0;
   out_1209108603363600393[271] = 0.0;
   out_1209108603363600393[272] = 0.0;
   out_1209108603363600393[273] = 0.0;
   out_1209108603363600393[274] = 0.0;
   out_1209108603363600393[275] = 0.0;
   out_1209108603363600393[276] = 0.0;
   out_1209108603363600393[277] = 0.0;
   out_1209108603363600393[278] = 0.0;
   out_1209108603363600393[279] = 0.0;
   out_1209108603363600393[280] = 0.0;
   out_1209108603363600393[281] = 0.0;
   out_1209108603363600393[282] = 0.0;
   out_1209108603363600393[283] = 0.0;
   out_1209108603363600393[284] = 0.0;
   out_1209108603363600393[285] = 1.0;
   out_1209108603363600393[286] = 0.0;
   out_1209108603363600393[287] = 0.0;
   out_1209108603363600393[288] = 0.0;
   out_1209108603363600393[289] = 0.0;
   out_1209108603363600393[290] = 0.0;
   out_1209108603363600393[291] = 0.0;
   out_1209108603363600393[292] = 0.0;
   out_1209108603363600393[293] = 0.0;
   out_1209108603363600393[294] = 0.0;
   out_1209108603363600393[295] = 0.0;
   out_1209108603363600393[296] = 0.0;
   out_1209108603363600393[297] = 0.0;
   out_1209108603363600393[298] = 0.0;
   out_1209108603363600393[299] = 0.0;
   out_1209108603363600393[300] = 0.0;
   out_1209108603363600393[301] = 0.0;
   out_1209108603363600393[302] = 0.0;
   out_1209108603363600393[303] = 0.0;
   out_1209108603363600393[304] = 1.0;
   out_1209108603363600393[305] = 0.0;
   out_1209108603363600393[306] = 0.0;
   out_1209108603363600393[307] = 0.0;
   out_1209108603363600393[308] = 0.0;
   out_1209108603363600393[309] = 0.0;
   out_1209108603363600393[310] = 0.0;
   out_1209108603363600393[311] = 0.0;
   out_1209108603363600393[312] = 0.0;
   out_1209108603363600393[313] = 0.0;
   out_1209108603363600393[314] = 0.0;
   out_1209108603363600393[315] = 0.0;
   out_1209108603363600393[316] = 0.0;
   out_1209108603363600393[317] = 0.0;
   out_1209108603363600393[318] = 0.0;
   out_1209108603363600393[319] = 0.0;
   out_1209108603363600393[320] = 0.0;
   out_1209108603363600393[321] = 0.0;
   out_1209108603363600393[322] = 0.0;
   out_1209108603363600393[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_8624036399976517093) {
   out_8624036399976517093[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_8624036399976517093[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_8624036399976517093[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_8624036399976517093[3] = dt*state[12] + state[3];
   out_8624036399976517093[4] = dt*state[13] + state[4];
   out_8624036399976517093[5] = dt*state[14] + state[5];
   out_8624036399976517093[6] = state[6];
   out_8624036399976517093[7] = state[7];
   out_8624036399976517093[8] = state[8];
   out_8624036399976517093[9] = state[9];
   out_8624036399976517093[10] = state[10];
   out_8624036399976517093[11] = state[11];
   out_8624036399976517093[12] = state[12];
   out_8624036399976517093[13] = state[13];
   out_8624036399976517093[14] = state[14];
   out_8624036399976517093[15] = state[15];
   out_8624036399976517093[16] = state[16];
   out_8624036399976517093[17] = state[17];
}
void F_fun(double *state, double dt, double *out_5901697688031158800) {
   out_5901697688031158800[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5901697688031158800[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5901697688031158800[2] = 0;
   out_5901697688031158800[3] = 0;
   out_5901697688031158800[4] = 0;
   out_5901697688031158800[5] = 0;
   out_5901697688031158800[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5901697688031158800[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5901697688031158800[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5901697688031158800[9] = 0;
   out_5901697688031158800[10] = 0;
   out_5901697688031158800[11] = 0;
   out_5901697688031158800[12] = 0;
   out_5901697688031158800[13] = 0;
   out_5901697688031158800[14] = 0;
   out_5901697688031158800[15] = 0;
   out_5901697688031158800[16] = 0;
   out_5901697688031158800[17] = 0;
   out_5901697688031158800[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5901697688031158800[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5901697688031158800[20] = 0;
   out_5901697688031158800[21] = 0;
   out_5901697688031158800[22] = 0;
   out_5901697688031158800[23] = 0;
   out_5901697688031158800[24] = 0;
   out_5901697688031158800[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5901697688031158800[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5901697688031158800[27] = 0;
   out_5901697688031158800[28] = 0;
   out_5901697688031158800[29] = 0;
   out_5901697688031158800[30] = 0;
   out_5901697688031158800[31] = 0;
   out_5901697688031158800[32] = 0;
   out_5901697688031158800[33] = 0;
   out_5901697688031158800[34] = 0;
   out_5901697688031158800[35] = 0;
   out_5901697688031158800[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5901697688031158800[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5901697688031158800[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5901697688031158800[39] = 0;
   out_5901697688031158800[40] = 0;
   out_5901697688031158800[41] = 0;
   out_5901697688031158800[42] = 0;
   out_5901697688031158800[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5901697688031158800[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5901697688031158800[45] = 0;
   out_5901697688031158800[46] = 0;
   out_5901697688031158800[47] = 0;
   out_5901697688031158800[48] = 0;
   out_5901697688031158800[49] = 0;
   out_5901697688031158800[50] = 0;
   out_5901697688031158800[51] = 0;
   out_5901697688031158800[52] = 0;
   out_5901697688031158800[53] = 0;
   out_5901697688031158800[54] = 0;
   out_5901697688031158800[55] = 0;
   out_5901697688031158800[56] = 0;
   out_5901697688031158800[57] = 1;
   out_5901697688031158800[58] = 0;
   out_5901697688031158800[59] = 0;
   out_5901697688031158800[60] = 0;
   out_5901697688031158800[61] = 0;
   out_5901697688031158800[62] = 0;
   out_5901697688031158800[63] = 0;
   out_5901697688031158800[64] = 0;
   out_5901697688031158800[65] = 0;
   out_5901697688031158800[66] = dt;
   out_5901697688031158800[67] = 0;
   out_5901697688031158800[68] = 0;
   out_5901697688031158800[69] = 0;
   out_5901697688031158800[70] = 0;
   out_5901697688031158800[71] = 0;
   out_5901697688031158800[72] = 0;
   out_5901697688031158800[73] = 0;
   out_5901697688031158800[74] = 0;
   out_5901697688031158800[75] = 0;
   out_5901697688031158800[76] = 1;
   out_5901697688031158800[77] = 0;
   out_5901697688031158800[78] = 0;
   out_5901697688031158800[79] = 0;
   out_5901697688031158800[80] = 0;
   out_5901697688031158800[81] = 0;
   out_5901697688031158800[82] = 0;
   out_5901697688031158800[83] = 0;
   out_5901697688031158800[84] = 0;
   out_5901697688031158800[85] = dt;
   out_5901697688031158800[86] = 0;
   out_5901697688031158800[87] = 0;
   out_5901697688031158800[88] = 0;
   out_5901697688031158800[89] = 0;
   out_5901697688031158800[90] = 0;
   out_5901697688031158800[91] = 0;
   out_5901697688031158800[92] = 0;
   out_5901697688031158800[93] = 0;
   out_5901697688031158800[94] = 0;
   out_5901697688031158800[95] = 1;
   out_5901697688031158800[96] = 0;
   out_5901697688031158800[97] = 0;
   out_5901697688031158800[98] = 0;
   out_5901697688031158800[99] = 0;
   out_5901697688031158800[100] = 0;
   out_5901697688031158800[101] = 0;
   out_5901697688031158800[102] = 0;
   out_5901697688031158800[103] = 0;
   out_5901697688031158800[104] = dt;
   out_5901697688031158800[105] = 0;
   out_5901697688031158800[106] = 0;
   out_5901697688031158800[107] = 0;
   out_5901697688031158800[108] = 0;
   out_5901697688031158800[109] = 0;
   out_5901697688031158800[110] = 0;
   out_5901697688031158800[111] = 0;
   out_5901697688031158800[112] = 0;
   out_5901697688031158800[113] = 0;
   out_5901697688031158800[114] = 1;
   out_5901697688031158800[115] = 0;
   out_5901697688031158800[116] = 0;
   out_5901697688031158800[117] = 0;
   out_5901697688031158800[118] = 0;
   out_5901697688031158800[119] = 0;
   out_5901697688031158800[120] = 0;
   out_5901697688031158800[121] = 0;
   out_5901697688031158800[122] = 0;
   out_5901697688031158800[123] = 0;
   out_5901697688031158800[124] = 0;
   out_5901697688031158800[125] = 0;
   out_5901697688031158800[126] = 0;
   out_5901697688031158800[127] = 0;
   out_5901697688031158800[128] = 0;
   out_5901697688031158800[129] = 0;
   out_5901697688031158800[130] = 0;
   out_5901697688031158800[131] = 0;
   out_5901697688031158800[132] = 0;
   out_5901697688031158800[133] = 1;
   out_5901697688031158800[134] = 0;
   out_5901697688031158800[135] = 0;
   out_5901697688031158800[136] = 0;
   out_5901697688031158800[137] = 0;
   out_5901697688031158800[138] = 0;
   out_5901697688031158800[139] = 0;
   out_5901697688031158800[140] = 0;
   out_5901697688031158800[141] = 0;
   out_5901697688031158800[142] = 0;
   out_5901697688031158800[143] = 0;
   out_5901697688031158800[144] = 0;
   out_5901697688031158800[145] = 0;
   out_5901697688031158800[146] = 0;
   out_5901697688031158800[147] = 0;
   out_5901697688031158800[148] = 0;
   out_5901697688031158800[149] = 0;
   out_5901697688031158800[150] = 0;
   out_5901697688031158800[151] = 0;
   out_5901697688031158800[152] = 1;
   out_5901697688031158800[153] = 0;
   out_5901697688031158800[154] = 0;
   out_5901697688031158800[155] = 0;
   out_5901697688031158800[156] = 0;
   out_5901697688031158800[157] = 0;
   out_5901697688031158800[158] = 0;
   out_5901697688031158800[159] = 0;
   out_5901697688031158800[160] = 0;
   out_5901697688031158800[161] = 0;
   out_5901697688031158800[162] = 0;
   out_5901697688031158800[163] = 0;
   out_5901697688031158800[164] = 0;
   out_5901697688031158800[165] = 0;
   out_5901697688031158800[166] = 0;
   out_5901697688031158800[167] = 0;
   out_5901697688031158800[168] = 0;
   out_5901697688031158800[169] = 0;
   out_5901697688031158800[170] = 0;
   out_5901697688031158800[171] = 1;
   out_5901697688031158800[172] = 0;
   out_5901697688031158800[173] = 0;
   out_5901697688031158800[174] = 0;
   out_5901697688031158800[175] = 0;
   out_5901697688031158800[176] = 0;
   out_5901697688031158800[177] = 0;
   out_5901697688031158800[178] = 0;
   out_5901697688031158800[179] = 0;
   out_5901697688031158800[180] = 0;
   out_5901697688031158800[181] = 0;
   out_5901697688031158800[182] = 0;
   out_5901697688031158800[183] = 0;
   out_5901697688031158800[184] = 0;
   out_5901697688031158800[185] = 0;
   out_5901697688031158800[186] = 0;
   out_5901697688031158800[187] = 0;
   out_5901697688031158800[188] = 0;
   out_5901697688031158800[189] = 0;
   out_5901697688031158800[190] = 1;
   out_5901697688031158800[191] = 0;
   out_5901697688031158800[192] = 0;
   out_5901697688031158800[193] = 0;
   out_5901697688031158800[194] = 0;
   out_5901697688031158800[195] = 0;
   out_5901697688031158800[196] = 0;
   out_5901697688031158800[197] = 0;
   out_5901697688031158800[198] = 0;
   out_5901697688031158800[199] = 0;
   out_5901697688031158800[200] = 0;
   out_5901697688031158800[201] = 0;
   out_5901697688031158800[202] = 0;
   out_5901697688031158800[203] = 0;
   out_5901697688031158800[204] = 0;
   out_5901697688031158800[205] = 0;
   out_5901697688031158800[206] = 0;
   out_5901697688031158800[207] = 0;
   out_5901697688031158800[208] = 0;
   out_5901697688031158800[209] = 1;
   out_5901697688031158800[210] = 0;
   out_5901697688031158800[211] = 0;
   out_5901697688031158800[212] = 0;
   out_5901697688031158800[213] = 0;
   out_5901697688031158800[214] = 0;
   out_5901697688031158800[215] = 0;
   out_5901697688031158800[216] = 0;
   out_5901697688031158800[217] = 0;
   out_5901697688031158800[218] = 0;
   out_5901697688031158800[219] = 0;
   out_5901697688031158800[220] = 0;
   out_5901697688031158800[221] = 0;
   out_5901697688031158800[222] = 0;
   out_5901697688031158800[223] = 0;
   out_5901697688031158800[224] = 0;
   out_5901697688031158800[225] = 0;
   out_5901697688031158800[226] = 0;
   out_5901697688031158800[227] = 0;
   out_5901697688031158800[228] = 1;
   out_5901697688031158800[229] = 0;
   out_5901697688031158800[230] = 0;
   out_5901697688031158800[231] = 0;
   out_5901697688031158800[232] = 0;
   out_5901697688031158800[233] = 0;
   out_5901697688031158800[234] = 0;
   out_5901697688031158800[235] = 0;
   out_5901697688031158800[236] = 0;
   out_5901697688031158800[237] = 0;
   out_5901697688031158800[238] = 0;
   out_5901697688031158800[239] = 0;
   out_5901697688031158800[240] = 0;
   out_5901697688031158800[241] = 0;
   out_5901697688031158800[242] = 0;
   out_5901697688031158800[243] = 0;
   out_5901697688031158800[244] = 0;
   out_5901697688031158800[245] = 0;
   out_5901697688031158800[246] = 0;
   out_5901697688031158800[247] = 1;
   out_5901697688031158800[248] = 0;
   out_5901697688031158800[249] = 0;
   out_5901697688031158800[250] = 0;
   out_5901697688031158800[251] = 0;
   out_5901697688031158800[252] = 0;
   out_5901697688031158800[253] = 0;
   out_5901697688031158800[254] = 0;
   out_5901697688031158800[255] = 0;
   out_5901697688031158800[256] = 0;
   out_5901697688031158800[257] = 0;
   out_5901697688031158800[258] = 0;
   out_5901697688031158800[259] = 0;
   out_5901697688031158800[260] = 0;
   out_5901697688031158800[261] = 0;
   out_5901697688031158800[262] = 0;
   out_5901697688031158800[263] = 0;
   out_5901697688031158800[264] = 0;
   out_5901697688031158800[265] = 0;
   out_5901697688031158800[266] = 1;
   out_5901697688031158800[267] = 0;
   out_5901697688031158800[268] = 0;
   out_5901697688031158800[269] = 0;
   out_5901697688031158800[270] = 0;
   out_5901697688031158800[271] = 0;
   out_5901697688031158800[272] = 0;
   out_5901697688031158800[273] = 0;
   out_5901697688031158800[274] = 0;
   out_5901697688031158800[275] = 0;
   out_5901697688031158800[276] = 0;
   out_5901697688031158800[277] = 0;
   out_5901697688031158800[278] = 0;
   out_5901697688031158800[279] = 0;
   out_5901697688031158800[280] = 0;
   out_5901697688031158800[281] = 0;
   out_5901697688031158800[282] = 0;
   out_5901697688031158800[283] = 0;
   out_5901697688031158800[284] = 0;
   out_5901697688031158800[285] = 1;
   out_5901697688031158800[286] = 0;
   out_5901697688031158800[287] = 0;
   out_5901697688031158800[288] = 0;
   out_5901697688031158800[289] = 0;
   out_5901697688031158800[290] = 0;
   out_5901697688031158800[291] = 0;
   out_5901697688031158800[292] = 0;
   out_5901697688031158800[293] = 0;
   out_5901697688031158800[294] = 0;
   out_5901697688031158800[295] = 0;
   out_5901697688031158800[296] = 0;
   out_5901697688031158800[297] = 0;
   out_5901697688031158800[298] = 0;
   out_5901697688031158800[299] = 0;
   out_5901697688031158800[300] = 0;
   out_5901697688031158800[301] = 0;
   out_5901697688031158800[302] = 0;
   out_5901697688031158800[303] = 0;
   out_5901697688031158800[304] = 1;
   out_5901697688031158800[305] = 0;
   out_5901697688031158800[306] = 0;
   out_5901697688031158800[307] = 0;
   out_5901697688031158800[308] = 0;
   out_5901697688031158800[309] = 0;
   out_5901697688031158800[310] = 0;
   out_5901697688031158800[311] = 0;
   out_5901697688031158800[312] = 0;
   out_5901697688031158800[313] = 0;
   out_5901697688031158800[314] = 0;
   out_5901697688031158800[315] = 0;
   out_5901697688031158800[316] = 0;
   out_5901697688031158800[317] = 0;
   out_5901697688031158800[318] = 0;
   out_5901697688031158800[319] = 0;
   out_5901697688031158800[320] = 0;
   out_5901697688031158800[321] = 0;
   out_5901697688031158800[322] = 0;
   out_5901697688031158800[323] = 1;
}
void h_4(double *state, double *unused, double *out_3851884155319722838) {
   out_3851884155319722838[0] = state[6] + state[9];
   out_3851884155319722838[1] = state[7] + state[10];
   out_3851884155319722838[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_454947601308887786) {
   out_454947601308887786[0] = 0;
   out_454947601308887786[1] = 0;
   out_454947601308887786[2] = 0;
   out_454947601308887786[3] = 0;
   out_454947601308887786[4] = 0;
   out_454947601308887786[5] = 0;
   out_454947601308887786[6] = 1;
   out_454947601308887786[7] = 0;
   out_454947601308887786[8] = 0;
   out_454947601308887786[9] = 1;
   out_454947601308887786[10] = 0;
   out_454947601308887786[11] = 0;
   out_454947601308887786[12] = 0;
   out_454947601308887786[13] = 0;
   out_454947601308887786[14] = 0;
   out_454947601308887786[15] = 0;
   out_454947601308887786[16] = 0;
   out_454947601308887786[17] = 0;
   out_454947601308887786[18] = 0;
   out_454947601308887786[19] = 0;
   out_454947601308887786[20] = 0;
   out_454947601308887786[21] = 0;
   out_454947601308887786[22] = 0;
   out_454947601308887786[23] = 0;
   out_454947601308887786[24] = 0;
   out_454947601308887786[25] = 1;
   out_454947601308887786[26] = 0;
   out_454947601308887786[27] = 0;
   out_454947601308887786[28] = 1;
   out_454947601308887786[29] = 0;
   out_454947601308887786[30] = 0;
   out_454947601308887786[31] = 0;
   out_454947601308887786[32] = 0;
   out_454947601308887786[33] = 0;
   out_454947601308887786[34] = 0;
   out_454947601308887786[35] = 0;
   out_454947601308887786[36] = 0;
   out_454947601308887786[37] = 0;
   out_454947601308887786[38] = 0;
   out_454947601308887786[39] = 0;
   out_454947601308887786[40] = 0;
   out_454947601308887786[41] = 0;
   out_454947601308887786[42] = 0;
   out_454947601308887786[43] = 0;
   out_454947601308887786[44] = 1;
   out_454947601308887786[45] = 0;
   out_454947601308887786[46] = 0;
   out_454947601308887786[47] = 1;
   out_454947601308887786[48] = 0;
   out_454947601308887786[49] = 0;
   out_454947601308887786[50] = 0;
   out_454947601308887786[51] = 0;
   out_454947601308887786[52] = 0;
   out_454947601308887786[53] = 0;
}
void h_10(double *state, double *unused, double *out_4952883853120045650) {
   out_4952883853120045650[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_4952883853120045650[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_4952883853120045650[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_8285666223292782819) {
   out_8285666223292782819[0] = 0;
   out_8285666223292782819[1] = 9.8100000000000005*cos(state[1]);
   out_8285666223292782819[2] = 0;
   out_8285666223292782819[3] = 0;
   out_8285666223292782819[4] = -state[8];
   out_8285666223292782819[5] = state[7];
   out_8285666223292782819[6] = 0;
   out_8285666223292782819[7] = state[5];
   out_8285666223292782819[8] = -state[4];
   out_8285666223292782819[9] = 0;
   out_8285666223292782819[10] = 0;
   out_8285666223292782819[11] = 0;
   out_8285666223292782819[12] = 1;
   out_8285666223292782819[13] = 0;
   out_8285666223292782819[14] = 0;
   out_8285666223292782819[15] = 1;
   out_8285666223292782819[16] = 0;
   out_8285666223292782819[17] = 0;
   out_8285666223292782819[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_8285666223292782819[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_8285666223292782819[20] = 0;
   out_8285666223292782819[21] = state[8];
   out_8285666223292782819[22] = 0;
   out_8285666223292782819[23] = -state[6];
   out_8285666223292782819[24] = -state[5];
   out_8285666223292782819[25] = 0;
   out_8285666223292782819[26] = state[3];
   out_8285666223292782819[27] = 0;
   out_8285666223292782819[28] = 0;
   out_8285666223292782819[29] = 0;
   out_8285666223292782819[30] = 0;
   out_8285666223292782819[31] = 1;
   out_8285666223292782819[32] = 0;
   out_8285666223292782819[33] = 0;
   out_8285666223292782819[34] = 1;
   out_8285666223292782819[35] = 0;
   out_8285666223292782819[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_8285666223292782819[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_8285666223292782819[38] = 0;
   out_8285666223292782819[39] = -state[7];
   out_8285666223292782819[40] = state[6];
   out_8285666223292782819[41] = 0;
   out_8285666223292782819[42] = state[4];
   out_8285666223292782819[43] = -state[3];
   out_8285666223292782819[44] = 0;
   out_8285666223292782819[45] = 0;
   out_8285666223292782819[46] = 0;
   out_8285666223292782819[47] = 0;
   out_8285666223292782819[48] = 0;
   out_8285666223292782819[49] = 0;
   out_8285666223292782819[50] = 1;
   out_8285666223292782819[51] = 0;
   out_8285666223292782819[52] = 0;
   out_8285666223292782819[53] = 1;
}
void h_13(double *state, double *unused, double *out_602560879508380423) {
   out_602560879508380423[0] = state[3];
   out_602560879508380423[1] = state[4];
   out_602560879508380423[2] = state[5];
}
void H_13(double *state, double *unused, double *out_2757326224023445015) {
   out_2757326224023445015[0] = 0;
   out_2757326224023445015[1] = 0;
   out_2757326224023445015[2] = 0;
   out_2757326224023445015[3] = 1;
   out_2757326224023445015[4] = 0;
   out_2757326224023445015[5] = 0;
   out_2757326224023445015[6] = 0;
   out_2757326224023445015[7] = 0;
   out_2757326224023445015[8] = 0;
   out_2757326224023445015[9] = 0;
   out_2757326224023445015[10] = 0;
   out_2757326224023445015[11] = 0;
   out_2757326224023445015[12] = 0;
   out_2757326224023445015[13] = 0;
   out_2757326224023445015[14] = 0;
   out_2757326224023445015[15] = 0;
   out_2757326224023445015[16] = 0;
   out_2757326224023445015[17] = 0;
   out_2757326224023445015[18] = 0;
   out_2757326224023445015[19] = 0;
   out_2757326224023445015[20] = 0;
   out_2757326224023445015[21] = 0;
   out_2757326224023445015[22] = 1;
   out_2757326224023445015[23] = 0;
   out_2757326224023445015[24] = 0;
   out_2757326224023445015[25] = 0;
   out_2757326224023445015[26] = 0;
   out_2757326224023445015[27] = 0;
   out_2757326224023445015[28] = 0;
   out_2757326224023445015[29] = 0;
   out_2757326224023445015[30] = 0;
   out_2757326224023445015[31] = 0;
   out_2757326224023445015[32] = 0;
   out_2757326224023445015[33] = 0;
   out_2757326224023445015[34] = 0;
   out_2757326224023445015[35] = 0;
   out_2757326224023445015[36] = 0;
   out_2757326224023445015[37] = 0;
   out_2757326224023445015[38] = 0;
   out_2757326224023445015[39] = 0;
   out_2757326224023445015[40] = 0;
   out_2757326224023445015[41] = 1;
   out_2757326224023445015[42] = 0;
   out_2757326224023445015[43] = 0;
   out_2757326224023445015[44] = 0;
   out_2757326224023445015[45] = 0;
   out_2757326224023445015[46] = 0;
   out_2757326224023445015[47] = 0;
   out_2757326224023445015[48] = 0;
   out_2757326224023445015[49] = 0;
   out_2757326224023445015[50] = 0;
   out_2757326224023445015[51] = 0;
   out_2757326224023445015[52] = 0;
   out_2757326224023445015[53] = 0;
}
void h_14(double *state, double *unused, double *out_4184554177841208073) {
   out_4184554177841208073[0] = state[6];
   out_4184554177841208073[1] = state[7];
   out_4184554177841208073[2] = state[8];
}
void H_14(double *state, double *unused, double *out_3537736033604260082) {
   out_3537736033604260082[0] = 0;
   out_3537736033604260082[1] = 0;
   out_3537736033604260082[2] = 0;
   out_3537736033604260082[3] = 0;
   out_3537736033604260082[4] = 0;
   out_3537736033604260082[5] = 0;
   out_3537736033604260082[6] = 1;
   out_3537736033604260082[7] = 0;
   out_3537736033604260082[8] = 0;
   out_3537736033604260082[9] = 0;
   out_3537736033604260082[10] = 0;
   out_3537736033604260082[11] = 0;
   out_3537736033604260082[12] = 0;
   out_3537736033604260082[13] = 0;
   out_3537736033604260082[14] = 0;
   out_3537736033604260082[15] = 0;
   out_3537736033604260082[16] = 0;
   out_3537736033604260082[17] = 0;
   out_3537736033604260082[18] = 0;
   out_3537736033604260082[19] = 0;
   out_3537736033604260082[20] = 0;
   out_3537736033604260082[21] = 0;
   out_3537736033604260082[22] = 0;
   out_3537736033604260082[23] = 0;
   out_3537736033604260082[24] = 0;
   out_3537736033604260082[25] = 1;
   out_3537736033604260082[26] = 0;
   out_3537736033604260082[27] = 0;
   out_3537736033604260082[28] = 0;
   out_3537736033604260082[29] = 0;
   out_3537736033604260082[30] = 0;
   out_3537736033604260082[31] = 0;
   out_3537736033604260082[32] = 0;
   out_3537736033604260082[33] = 0;
   out_3537736033604260082[34] = 0;
   out_3537736033604260082[35] = 0;
   out_3537736033604260082[36] = 0;
   out_3537736033604260082[37] = 0;
   out_3537736033604260082[38] = 0;
   out_3537736033604260082[39] = 0;
   out_3537736033604260082[40] = 0;
   out_3537736033604260082[41] = 0;
   out_3537736033604260082[42] = 0;
   out_3537736033604260082[43] = 0;
   out_3537736033604260082[44] = 1;
   out_3537736033604260082[45] = 0;
   out_3537736033604260082[46] = 0;
   out_3537736033604260082[47] = 0;
   out_3537736033604260082[48] = 0;
   out_3537736033604260082[49] = 0;
   out_3537736033604260082[50] = 0;
   out_3537736033604260082[51] = 0;
   out_3537736033604260082[52] = 0;
   out_3537736033604260082[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_1072602497373551517) {
  err_fun(nom_x, delta_x, out_1072602497373551517);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2245523438332106519) {
  inv_err_fun(nom_x, true_x, out_2245523438332106519);
}
void pose_H_mod_fun(double *state, double *out_1209108603363600393) {
  H_mod_fun(state, out_1209108603363600393);
}
void pose_f_fun(double *state, double dt, double *out_8624036399976517093) {
  f_fun(state,  dt, out_8624036399976517093);
}
void pose_F_fun(double *state, double dt, double *out_5901697688031158800) {
  F_fun(state,  dt, out_5901697688031158800);
}
void pose_h_4(double *state, double *unused, double *out_3851884155319722838) {
  h_4(state, unused, out_3851884155319722838);
}
void pose_H_4(double *state, double *unused, double *out_454947601308887786) {
  H_4(state, unused, out_454947601308887786);
}
void pose_h_10(double *state, double *unused, double *out_4952883853120045650) {
  h_10(state, unused, out_4952883853120045650);
}
void pose_H_10(double *state, double *unused, double *out_8285666223292782819) {
  H_10(state, unused, out_8285666223292782819);
}
void pose_h_13(double *state, double *unused, double *out_602560879508380423) {
  h_13(state, unused, out_602560879508380423);
}
void pose_H_13(double *state, double *unused, double *out_2757326224023445015) {
  H_13(state, unused, out_2757326224023445015);
}
void pose_h_14(double *state, double *unused, double *out_4184554177841208073) {
  h_14(state, unused, out_4184554177841208073);
}
void pose_H_14(double *state, double *unused, double *out_3537736033604260082) {
  H_14(state, unused, out_3537736033604260082);
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
