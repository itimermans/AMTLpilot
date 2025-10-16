#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_8820622560039895266);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_4138258066495298222);
void pose_H_mod_fun(double *state, double *out_6211513613161177568);
void pose_f_fun(double *state, double dt, double *out_5417900835208008336);
void pose_F_fun(double *state, double dt, double *out_3421518052388552051);
void pose_h_4(double *state, double *unused, double *out_7947650004784572605);
void pose_H_4(double *state, double *unused, double *out_4034925576575149281);
void pose_h_10(double *state, double *unused, double *out_6434353536820436852);
void pose_H_10(double *state, double *unused, double *out_4256257324261286174);
void pose_h_13(double *state, double *unused, double *out_348176217550400228);
void pose_H_13(double *state, double *unused, double *out_3575705631741551648);
void pose_h_14(double *state, double *unused, double *out_8082079656560248553);
void pose_H_14(double *state, double *unused, double *out_71684720235664752);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}