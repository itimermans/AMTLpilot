#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_1274560327679420140);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_7078231132908780549);
void pose_H_mod_fun(double *state, double *out_3160026192531771035);
void pose_f_fun(double *state, double dt, double *out_4428667581613203302);
void pose_F_fun(double *state, double dt, double *out_6306269892704480251);
void pose_h_4(double *state, double *unused, double *out_780706365605131756);
void pose_H_4(double *state, double *unused, double *out_3914187194586483642);
void pose_h_10(double *state, double *unused, double *out_4218786315389702128);
void pose_H_10(double *state, double *unused, double *out_2207618639460829152);
void pose_h_13(double *state, double *unused, double *out_3970942575106541800);
void pose_H_13(double *state, double *unused, double *out_6921925670806367045);
void pose_h_14(double *state, double *unused, double *out_8889913689112628377);
void pose_H_14(double *state, double *unused, double *out_7877428050925968171);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}