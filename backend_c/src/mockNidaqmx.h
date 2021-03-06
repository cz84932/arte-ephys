// Provide the functions of nidaqmx.h, but without
// any nidaq cards.  Simulate data.

#include <stdint.h>

#define CVICDECL
#define CVICALLBACK CVICDECL

// TODO: check
typedef int TaskHandle;
typedef double float64;
typedef int_32 int32;

typedef int32 (CVICALLBACK *DAQmxEveryNSamplesEventCallbackPtr)(TaskHandle taskHandle, int32 everyNsamplesEventType, uInt32 nSamples, void *callbackData);

typedef int32 (CVICALLBACK *DAQmxDoneEventCallbackPtr)(TaskHandle taskHandle, int32 status, void *callbackData);


// TODO: check types
int DAQmxCreateTask( char*,     // taskname
                     TaskHandle // output arg.
                     );

int DAQmxCreateAIVoltageChan ( TaskHandle,
                               char*,   // channel name
                               char*,   // "" (?)
                               ???,     // DAQmx_Val_RSE,
                               ???,     // NEURAL_DAQ_V_MIN
                               ???,     // NEURAL_DAQ_V_MAX
                               ???,     // DAQmx_Val_Volts
                               void* ); // NULL

int DAQmxCfgSampClkTiming( TaskHandle, 
                           char*, // ""
                           int,   // samp_rate (32000?)
                           ???,   // DAQmx_Val_Acquired_Into_Buffer
                           ???,   // DAQmx_Val_ContSamps,
                           int )  // bufferSize
                           

int DAQmxSetRefClkSrc( TaskHandle, 
                       char* ); // "OnboardClock"
                       

int DAQmxGetRefClkRate( TaskHandle, 
                        int& ); // output arg (32000?)

int GetTerminalNameWithDevPrefix( TaskHandle, 
                                  char*,   // "ai/StartTrigger"
                                  char* ); // output argument

int DAQmxRegisterEveryNSamplesEvent( TaskHandle,
                                     ???,     // DAQmx_Val_Acquired_Into_Buffer
                                     int,     // 32
                                     int,     // 0
                                     ???,     // int32 CVICALLBACK EveryNCallback ?
                                     void* ); // output arg DATA

// EveryNCallback should have signature like:
// int32 CVICALLBACK EveryNCallback(TaskHandle th, 
//                                  int32  everyNSamplesEventType,
//                                  uInt32 nSamples,
//                                  void*  callbackData); 

int DAQmxRegisterDoneEvent ( TaskHandle, 
                             int, // 0
                             ???, // DoneCallback
                             void * ); // ?? &master_daq

// DoneCallback should have signature like:
// int32 CVICALLBACK DoneCallback (TaskHandle ts,
//                                 int32      status,
//                                 void*      callbackData);
