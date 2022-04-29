SHELL := cmd.exe
CYGWIN=nontsec
export PATH := C:\Program Files\Semeru\jdk-11.0.14.101-openj9\bin;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Program Files\NVIDIA Corporation\NVIDIA NvDLISR;C:\Program Files\MATLAB\R2021b\runtime\win64;C:\Program Files\MATLAB\R2021b\bin;C:\Program Files\MATLAB\R2021a\runtime\win64;C:\Program Files\MATLAB\R2021a\bin;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\MinGW\bin;C:\Program Files (x86)\ZED SDK\dependencies\freeglut_2.8\x64;C:\Program Files (x86)\ZED SDK\dependencies\glew-1.12.0\x64;C:\Program Files (x86)\ZED SDK\dependencies\opencv_3.1.0\x64;C:\Program Files (x86)\ZED SDK\bin;C:\Program Files\Git\cmd;C:\Program Files\MATLAB\R2019b\runtime\win64;C:\Program Files\MATLAB\R2019b\bin;C:\Users\PC\AppData\Local\Programs\Python\Python310\Scripts\;C:\Users\PC\AppData\Local\Programs\Python\Python310\;C:\Users\PC\AppData\Local\Microsoft\WindowsApps;C:\Users\PC\AppData\Local\Programs\MiKTeX\miktex\bin\x64\;C:\Program Files\Bandizip\;C:\Users\PC\AppData\Local\Programs\Microsoft VS Code\bin;C:\Program Files (x86)\Common Files\Hilscher GmbH\TLRDecode;C:\Program Files\ngrok;C:\Users\PC\AppData\Local\Programs\Python\Python310\Scripts\;C:\Users\PC\AppData\Local\Programs\Python\Python310\;C:\Users\PC\AppData\Local\Microsoft\WindowsApps;C:\Users\PC\AppData\Local\Programs\MiKTeX\miktex\bin\x64\;C:\Program Files\Bandizip\;C:\Users\PC\AppData\Local\Programs\Microsoft VS Code\bin;C:\Program Files (x86)\Common Files\Hilscher GmbH\TLRDecode;C:\Program Files\ngrok
export AS_BUILD_MODE := BuildAndTransfer
export AS_VERSION := 4.5.2.102
export AS_COMPANY_NAME :=  
export AS_USER_NAME := PC
export AS_PATH := C:/BrAutomation/AS45
export AS_BIN_PATH := C:/BrAutomation/AS45/Bin-en
export AS_PROJECT_PATH := Z:/HYEONGJUN\ KIM/Hyundai_Heavy_Industry/BR_Projects/AS_Target_Simulink_Test_Jenkins
export AS_PROJECT_NAME := AS_Target_Simulink_Test
export AS_SYSTEM_PATH := C:/BrAutomation/AS/System
export AS_VC_PATH := C:/BrAutomation/AS45/AS/VC
export AS_TEMP_PATH := Z:/HYEONGJUN\ KIM/Hyundai_Heavy_Industry/BR_Projects/AS_Target_Simulink_Test_Jenkins/Temp
export AS_CONFIGURATION := Config1
export AS_BINARIES_PATH := Z:/HYEONGJUN\ KIM/Hyundai_Heavy_Industry/BR_Projects/AS_Target_Simulink_Test_Jenkins/Binaries
export AS_GNU_INST_PATH := C:/BrAutomation/AS45/AS/GnuInst/V4.1.2
export AS_GNU_BIN_PATH := $(AS_GNU_INST_PATH)/bin
export AS_GNU_INST_PATH_SUB_MAKE := C:/BrAutomation/AS45/AS/GnuInst/V4.1.2
export AS_GNU_BIN_PATH_SUB_MAKE := $(AS_GNU_INST_PATH_SUB_MAKE)/bin
export AS_INSTALL_PATH := C:/BrAutomation/AS45
export WIN32_AS_PATH := "C:\BrAutomation\AS45"
export WIN32_AS_BIN_PATH := "C:\BrAutomation\AS45\Bin-en"
export WIN32_AS_PROJECT_PATH := "Z:\HYEONGJUN KIM\Hyundai_Heavy_Industry\BR_Projects\AS_Target_Simulink_Test_Jenkins"
export WIN32_AS_SYSTEM_PATH := "C:\BrAutomation\AS\System"
export WIN32_AS_VC_PATH := "C:\BrAutomation\AS45\AS\VC"
export WIN32_AS_TEMP_PATH := "Z:\HYEONGJUN KIM\Hyundai_Heavy_Industry\BR_Projects\AS_Target_Simulink_Test_Jenkins\Temp"
export WIN32_AS_BINARIES_PATH := "Z:\HYEONGJUN KIM\Hyundai_Heavy_Industry\BR_Projects\AS_Target_Simulink_Test_Jenkins\Binaries"
export WIN32_AS_GNU_INST_PATH := "C:\BrAutomation\AS45\AS\GnuInst\V4.1.2"
export WIN32_AS_GNU_BIN_PATH := "$(WIN32_AS_GNU_INST_PATH)\\bin" 
export WIN32_AS_INSTALL_PATH := "C:\BrAutomation\AS45"

.suffixes:

ProjectMakeFile:

	@'$(AS_BIN_PATH)/BR.AS.AnalyseProject.exe' '$(AS_PROJECT_PATH)/AS_Target_Simulink_Test.apj' -t '$(AS_TEMP_PATH)' -c '$(AS_CONFIGURATION)' -o '$(AS_BINARIES_PATH)'   -sfas -buildMode 'BuildAndTransfer'   

