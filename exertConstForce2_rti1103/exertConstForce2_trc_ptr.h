  /*********************** dSPACE target specific file *************************

   Header file exertConstForce2_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1103 6.5 (10-May-2010)
   Sun Oct 09 18:43:40 2016

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

  *****************************************************************************/
  #ifndef RTI_HEADER_exertConstForce2_trc_ptr_h_
  #define RTI_HEADER_exertConstForce2_trc_ptr_h_
  /* Include the model header file. */
  #include "exertConstForce2.h"
  #include "exertConstForce2_private.h"

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
              EXTERN_C volatile  real_T *p_exertConstForce2_B_real_T_0;
              EXTERN_C volatile  real_T *p_exertConstForce2_B_real_T_1;
              EXTERN_C volatile  uint32_T *p_exertConstForce2_B_uint32_T_2;
              EXTERN_C volatile  uint16_T *p_exertConstForce2_B_uint16_T_3;
              EXTERN_C volatile  uint16_T *p_exertConstForce2_B_uint16_T_4;
              EXTERN_C volatile  uint8_T *p_exertConstForce2_B_uint8_T_5;
              EXTERN_C volatile  real_T *p_exertConstForce2_P_real_T_0;
              EXTERN_C volatile  uint16_T *p_exertConstForce2_P_uint16_T_1;
              EXTERN_C volatile  uint8_T *p_exertConstForce2_P_uint8_T_2;
              EXTERN_C volatile  real_T *p_exertConstForce2_DWork_real_T_0;
              EXTERN_C volatile  uint32_T *p_exertConstForce2_DWork_uint32_T_1;

   #define RTI_INIT_TRC_POINTERS() \
              p_exertConstForce2_B_real_T_0 = &exertConstForce2_B.SFunction1;\
              p_exertConstForce2_B_real_T_1 = &exertConstForce2_B.SFunction;\
              p_exertConstForce2_B_uint32_T_2 = &exertConstForce2_B.motionInd2;\
              p_exertConstForce2_B_uint16_T_3 = &exertConstForce2_B.Product1;\
              p_exertConstForce2_B_uint16_T_4 = &exertConstForce2_B.motionInd1;\
              p_exertConstForce2_B_uint8_T_5 = &exertConstForce2_B.Compare;\
              p_exertConstForce2_P_real_T_0 = &exertConstForce2_P.Constant1_Value[0];\
              p_exertConstForce2_P_uint16_T_1 = &exertConstForce2_P.Constant_Value_k;\
              p_exertConstForce2_P_uint8_T_2 = &exertConstForce2_P.motionInd1_Gain;\
              p_exertConstForce2_DWork_real_T_0 = &exertConstForce2_DWork.UD_DSTATE;\
              p_exertConstForce2_DWork_uint32_T_1 = &exertConstForce2_DWork.Add_DWORK1;\

   #endif                       /* RTI_HEADER_exertConstForce2_trc_ptr_h_ */
