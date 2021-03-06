#ifndef SIMSTRUCT_SLEXEC_BLOCK_RUNTIME_SERVICE_H
#define SIMSTRUCT_SLEXEC_BLOCK_RUNTIME_SERVICE_H

/**
 * @file slexec_block_runtime_service.h
 *
 * This header is the exported C interface to the simulink execution engine
 * (slexec_simbridge) that provides block runtime services. This file should be
 * included from simstruct (and no earlier) so that we have access to
 * preprocessor variables. 
 *
 * Note that this header file should be placed in the simstruct folder, and its
 * implementations are in the simbridge module.
 * 
 */

/* Copyright 2017 The MathWorks, Inc. */

/* Guard against early inclusions */
#ifndef _SIMSTRUCT
#error "This file should be included from simstruc.h"
#endif

#ifdef BUILDING_SLEXEC_SIMBRIDGE
 /* being included from inside slexec_simbridge module */
  #include "package.h"
  #define SLEXEC_SIMBRIDGE_PUBLISHED_C extern "C" DLL_EXPORT_SYM
#else
 /* being included from outside, such as raccel code */
  #if defined(__cplusplus)
 /* Needed for non-inlined C++ S-functions */
    #define SLEXEC_SIMBRIDGE_PUBLISHED_C extern "C"
  #else 
    #define SLEXEC_SIMBRIDGE_PUBLISHED_C extern
  #endif
#endif

/* Block runtime service keys */
typedef enum {
    SLEXEC_BLK_RTS_SET_NUM_TICKS_TO_NEXT_SAMPLE_HIT_FOR_VDR,
    SLEXEC_BLK_RTS_GET_NUM_TICKS_TO_NEXT_SAMPLE_HIT_FOR_VDR
} _slexecBlkRTSType;

/* Type declarations */
typedef int_T  (*_slexecBlkRTSGateway) (SimStruct*        S,
                                        _slexecBlkRTSType type,
                                        int_T             arg1,
                                        void*             arg2);

/* Macro utilities */
#define _slexecSafelyCallBlkRTSGatewayStart(S) \
    (((S)->mdlInfo->blkRTSGateway==NULL) ? 0 : ((*(S)->mdlInfo->blkRTSGateway)
#define _slexecSafelyCallBlkRTSGatewayEnd ))

#define _slexecSetBlkRTSGateway(S,fcn)   \
    (S)->mdlInfo->blkRTSGateway = (fcn)

/* Block runtime service function */
SLEXEC_SIMBRIDGE_PUBLISHED_C int _slexecBlockRuntimeServiceGateway(SimStruct*        S,
                                                                   _slexecBlkRTSType blkRTSType,
                                                                   int               arg1,
                                                                   void*             arg2);

/* Published block runtime service macros */

/*
 * This macro is used to set the number of ticks to the next sample hit for
 * variable discrete rate in the block.  
 *
 * sti is the sample time index of the variable discrete rate in the block, and
 * numTicks is the the next ticks to the next sample hit.
 *
 */
#define ssSetNumTicksToNextSampleHitForVariableDiscrete(S, sti, numTicks)                                                 \
{                                                                                                                         \
      size_t tmp = (size_t) numTicks;                                                                                     \
      _slexecSafelyCallBlkRTSGatewayStart(S)(S, SLEXEC_BLK_RTS_SET_NUM_TICKS_TO_NEXT_SAMPLE_HIT_FOR_VDR, (int) sti, &tmp) \
      _slexecSafelyCallBlkRTSGatewayEnd;                                                                                  \
}

/*
 * This macro is used to get the number of ticks to the next sample hit for
 * variable discrete rate in the block.
 *
 * sti is the sample time index of the variable discrete rate in the block.
 *
 */
#define ssGetNumTicksToNextSampleHitForVariableDiscrete(S, sti)                                                                   \
{                                                                                                                                 \
      _slexecSafelyCallBlkRTSGatewayStart(S)(S, SLEXEC_BLK_RTS_GET_NUM_TICKS_TO_NEXT_SAMPLE_HIT_FOR_VDR, (int) sti, (void*) NULL) \
      _slexecSafelyCallBlkRTSGatewayEnd;                                                                                          \
}

#endif 
