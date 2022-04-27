<?xml version="1.0" encoding="utf-8"?>
<?AutomationStudio Version=4.5.2.102?>
<SwConfiguration CpuAddress="SL1" xmlns="http://br-automation.co.at/AS/SwConfiguration">
  <TaskClass Name="Cyclic#1">
    <Task Name="pend_ctrl" Source="Controller.pend_ctrl.prg" Memory="UserROM" Language="ANSIC" AdditionalIncludeDirectories="\Logical\MATLAB_includes\R2019b\" BuildOptions="-lm -D MODEL=pend_ctrl_lin -D NUMST=1 -D NCSTATES=0 -D HAVESTDIO -D MODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -D CLASSIC_INTERFACE=0 -D ALLOCATIONFCN=0 -D TID01EQ=0 -D TERMFCN=1 -D ONESTEPFCN=0 -D MAT_FILE=0 -D MULTI_INSTANCE_CODE=0 -D INTEGER_CODE=0 -D MT=0 " Debugging="false" />
    <Task Name="pend_mod" Source="Model.pend_mod.prg" Memory="UserROM" Language="ANSIC" AdditionalIncludeDirectories="\Logical\MATLAB_includes\R2019b\" BuildOptions="-lm -D MODEL=pend_mod_nlin -D NUMST=2 -D NCSTATES=4 -D HAVESTDIO -D MODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -D CLASSIC_INTERFACE=0 -D ALLOCATIONFCN=0 -D TID01EQ=1 -D TERMFCN=1 -D ONESTEPFCN=0 -D MAT_FILE=0 -D MULTI_INSTANCE_CODE=0 -D INTEGER_CODE=0 -D MT=0 " Debugging="false" />
  </TaskClass>
  <TaskClass Name="Cyclic#2" />
  <TaskClass Name="Cyclic#3" />
  <TaskClass Name="Cyclic#4" />
  <TaskClass Name="Cyclic#5" />
  <TaskClass Name="Cyclic#6" />
  <TaskClass Name="Cyclic#7" />
  <TaskClass Name="Cyclic#8" />
  <Binaries>
    <BinaryObject Name="TCData" Source="" Memory="SystemROM" Language="Binary" />
    <BinaryObject Name="udbdef" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="ashwac" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="Role" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="ashwd" Source="" Memory="SystemROM" Language="Binary" />
    <BinaryObject Name="arconfig" Source="" Memory="SystemROM" Language="Binary" />
    <BinaryObject Name="sysconf" Source="" Memory="SystemROM" Language="Binary" />
    <BinaryObject Name="iomap" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="User" Source="" Memory="UserROM" Language="Binary" />
    <BinaryObject Name="asfw" Source="" Memory="SystemROM" Language="Binary" />
    <BinaryObject Name="OpcUaMap" Source="" Memory="UserROM" Language="Binary" />
  </Binaries>
  <Libraries>
    <LibraryObject Name="brsystem" Source="Libraries.brsystem.lby" Memory="UserROM" Language="binary" Debugging="true" />
    <LibraryObject Name="runtime" Source="Libraries.runtime.lby" Memory="UserROM" Language="binary" Debugging="true" />
    <LibraryObject Name="sys_lib" Source="Libraries.sys_lib.lby" Memory="UserROM" Language="binary" Debugging="true" />
    <LibraryObject Name="AsTCP" Source="Libraries.AsTCP.lby" Memory="UserROM" Language="Binary" Debugging="false" />
    <LibraryObject Name="AsArLog" Source="Libraries.AsArLog.lby" Memory="UserROM" Language="Binary" Debugging="false" />
    <LibraryObject Name="pctr_fun" Source="Libraries.pctr_fun.lby" Memory="UserROM" Language="ANSIC" AdditionalIncludeDirectories="\Logical\MATLAB_includes\R2019b\" BuildOptions="-lm -D MODEL=pend_ctrl_fun -D NUMST=1 -D NCSTATES=0 -D HAVESTDIO -D MODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -D CLASSIC_INTERFACE=0 -D ALLOCATIONFCN=0 -D TID01EQ=0 -D TERMFCN=1 -D ONESTEPFCN=1 -D MAT_FILE=0 -D MULTI_INSTANCE_CODE=1 -D INTEGER_CODE=0 -D MT=0 " Debugging="false" />
  </Libraries>
</SwConfiguration>