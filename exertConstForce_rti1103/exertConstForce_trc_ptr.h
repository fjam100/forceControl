  /*********************** dSPACE target specific file *************************

   Header file exertConstForce_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1103 6.5 (10-May-2010)
   Tue Sep 20 16:57:36 2016

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

  *****************************************************************************/
  #ifndef RTI_HEADER_exertConstForce_trc_ptr_h_
  #define RTI_HEADER_exertConstForce_trc_ptr_h_
  /* Include the model header file. */
  #include "exertConstForce.h"
  #include "exertConstForce_private.h"

  #ifdef EXTERN_C
  #undef EXTERN_C
  #endif

  #ifdef __cplusplus
  #define EXTERN_C                       extern "C"
  #else
  #define EXTERN_C                       extern
  #endif

  /*
   *  Declare the global TRC pointers
   */
              EXTERN_C volatile  real_T *p_exertConstForce_B_real_T_0;
              EXTERN_C volatile  real_T *p_exertConstForce_B_real_T_1;
              EXTERN_C volatile  real_T *p_exertConstForce_P_real_T_0;
              EXTERN_C volatile  real_T *p_exertConstForce_DWork_real_T_0;

   #define RTI_INIT_TRC_POINTERS() \
              p_exertConstForce_B_real_T_0 = &exertConstForce_B.SFunction;\
              p_exertConstForce_B_real_T_1 = &exertConstForce_B.encGainY;\
              p_exertConstForce_P_real_T_0 = &exertConstForce_P.uForce_Value;\
              p_exertConstForce_DWork_real_T_0 = &exertConstForce_DWork.UD_DSTATE;\

   #endif                       /* RTI_HEADER_exertConstForce_trc_ptr_h_ */
