#pragma once

#define SIZE_2MM_ORIG            98
#define SIZE_3MM_ORIG            82
#define SIZE_ATA_ORIG           218
#define SIZE_BIC_ORIG           217
#define SIZE_CONVOLUTION_2_ORIG 156
#define SIZE_CONVOLUTION_3_ORIG  29
#define SIZE_COR_ORIG           123
#define SIZE_COV_ORIG           153
#define SIZE_GEMM_ORIG          127
#define SIZE_GES_ORIG           154
#define SIZE_GRA_ORIG            20
#define SIZE_MVT_ORIG           217
#define SIZE_SYR2_ORIG          127
#define SIZE_SYRK_ORIG          156
#define SIZE_CHO_ORIG           128
#define SIZE_DOI_ORIG            20
#define SIZE_GEMV_ORIG          128
#define SIZE_SYM_ORIG            80
#define SIZE_TRM_ORIG           100
#define SIZE_DUR_ORIG           100
#define SIZE_LU_ORIG            128

#ifdef HALF_SIZE
  #define SIZE_2MM            (SIZE_2MM_ORIG            / 2)
  #define SIZE_3MM            (SIZE_3MM_ORIG            / 2)
  #define SIZE_ATA            (SIZE_ATA_ORIG            / 2)
  #define SIZE_BIC            (SIZE_BIC_ORIG            / 2)
  #define SIZE_CONVOLUTION_2  (SIZE_CONVOLUTION_2_ORIG  / 2)
  #define SIZE_CONVOLUTION_3  (SIZE_CONVOLUTION_3_ORIG  / 2)
  #define SIZE_COR            (SIZE_COR_ORIG            / 2)
  #define SIZE_COV            (SIZE_COV_ORIG            / 2)
  #define SIZE_GEMM           (SIZE_GEMM_ORIG           / 2)
  #define SIZE_GES            (SIZE_GES_ORIG            / 2)
  #define SIZE_GRA            (SIZE_GRA_ORIG            / 2)
  #define SIZE_MVT            (SIZE_MVT_ORIG            / 2)
  #define SIZE_SYR2           (SIZE_SYR2_ORIG           / 2)
  #define SIZE_SYRK           (SIZE_SYRK_ORIG           / 2)
  #define SIZE_CHO            (SIZE_CHO_ORIG            / 2)
  #define SIZE_DOI            (SIZE_DOI_ORIG            / 2)
  #define SIZE_GEMV           (SIZE_GEMV_ORIG           / 2)
  #define SIZE_SYM            (SIZE_SYM_ORIG            / 2)
  #define SIZE_TRM            (SIZE_TRM_ORIG            / 2)
  #define SIZE_DUR            (SIZE_DUR_ORIG            / 2)
  #define SIZE_LU             (SIZE_LU_ORIG             / 2)
#else
  #define SIZE_2MM            SIZE_2MM_ORIG
  #define SIZE_3MM            SIZE_3MM_ORIG
  #define SIZE_ATA            SIZE_ATA_ORIG
  #define SIZE_BIC            SIZE_BIC_ORIG
  #define SIZE_CONVOLUTION_2  SIZE_CONVOLUTION_2_ORIG
  #define SIZE_CONVOLUTION_3  SIZE_CONVOLUTION_3_ORIG
  #define SIZE_COR            SIZE_COR_ORIG
  #define SIZE_COV            SIZE_COV_ORIG
  #define SIZE_GEMM           SIZE_GEMM_ORIG
  #define SIZE_GES            SIZE_GES_ORIG
  #define SIZE_GRA            SIZE_GRA_ORIG
  #define SIZE_MVT            SIZE_MVT_ORIG
  #define SIZE_SYR2           SIZE_SYR2_ORIG
  #define SIZE_SYRK           SIZE_SYRK_ORIG
  #define SIZE_CHO            SIZE_CHO_ORIG
  #define SIZE_DOI            SIZE_DOI_ORIG
  #define SIZE_GEMV           SIZE_GEMV_ORIG
  #define SIZE_SYM            SIZE_SYM_ORIG
  #define SIZE_TRM            SIZE_TRM_ORIG
  #define SIZE_DUR            SIZE_DUR_ORIG
  #define SIZE_LU             SIZE_LU_ORIG
#endif
