#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_1072602497373551517);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2245523438332106519);
void pose_H_mod_fun(double *state, double *out_1209108603363600393);
void pose_f_fun(double *state, double dt, double *out_8624036399976517093);
void pose_F_fun(double *state, double dt, double *out_5901697688031158800);
void pose_h_4(double *state, double *unused, double *out_3851884155319722838);
void pose_H_4(double *state, double *unused, double *out_454947601308887786);
void pose_h_10(double *state, double *unused, double *out_4952883853120045650);
void pose_H_10(double *state, double *unused, double *out_8285666223292782819);
void pose_h_13(double *state, double *unused, double *out_602560879508380423);
void pose_H_13(double *state, double *unused, double *out_2757326224023445015);
void pose_h_14(double *state, double *unused, double *out_4184554177841208073);
void pose_H_14(double *state, double *unused, double *out_3537736033604260082);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}