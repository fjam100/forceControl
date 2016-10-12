/***************************************************************************

   Source file exertConstForce_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1103 6.5 (10-May-2010)
   Tue Sep 20 16:57:36 2016

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "exertConstForce_trc_ptr.h"

/* Definition of Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_exertConstForce_B_real_T_0 = 0;
volatile real_T *p_exertConstForce_B_real_T_1 = 0;
volatile real_T *p_exertConstForce_P_real_T_0 = 0;
volatile real_T *p_exertConstForce_DWork_real_T_0 = 0;
