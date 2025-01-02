##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=second-assignment-system32
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=C:/Users/adria/Desktop/second-assignment-system32/second-assignment-system32
ProjectPath            :=C:/Users/adria/Desktop/second-assignment-system32/second-assignment-system32/second-assignment-system32
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/second-assignment-system32
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=adria
Date                   :=1/2/2025
CodeLitePath           :="C:/Program Files/CodeLite"
MakeDirCommand         :=mkdir
LinkerName             :=C:/msys64/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/msys64/mingw64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=C:/Users/adria/Desktop/second-assignment-system32/second-assignment-system32/build-$(WorkspaceConfiguration)/bin
OutputFile             :=..\build-$(WorkspaceConfiguration)\bin\$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/msys64/mingw64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/msys64/mingw64/bin/ar.exe -r
CXX      := C:/msys64/mingw64/bin/g++.exe
CC       := C:/msys64/mingw64/bin/gcc.exe
CXXFLAGS :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
CFLAGS   :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/msys64/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/List.cpp$(ObjectSuffix) $(IntermediateDirectory)/T1.cpp$(ObjectSuffix) $(IntermediateDirectory)/RGBPixelXY.cpp$(ObjectSuffix) $(IntermediateDirectory)/ImageSaver.cpp$(ObjectSuffix) $(IntermediateDirectory)/PixelQueue.cpp$(ObjectSuffix) $(IntermediateDirectory)/TinyImageJM.cpp$(ObjectSuffix) $(IntermediateDirectory)/T2.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Timer.cpp$(ObjectSuffix) $(IntermediateDirectory)/Queue.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/ImageLoaderUI.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@if not exist "$(OutputDirectory)" $(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/List.cpp$(ObjectSuffix): List.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/adria/Desktop/second-assignment-system32/second-assignment-system32/second-assignment-system32/List.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/List.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/List.cpp$(PreprocessSuffix): List.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/List.cpp$(PreprocessSuffix) List.cpp

$(IntermediateDirectory)/T1.cpp$(ObjectSuffix): T1.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/adria/Desktop/second-assignment-system32/second-assignment-system32/second-assignment-system32/T1.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/T1.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/T1.cpp$(PreprocessSuffix): T1.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/T1.cpp$(PreprocessSuffix) T1.cpp

$(IntermediateDirectory)/RGBPixelXY.cpp$(ObjectSuffix): RGBPixelXY.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/adria/Desktop/second-assignment-system32/second-assignment-system32/second-assignment-system32/RGBPixelXY.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RGBPixelXY.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RGBPixelXY.cpp$(PreprocessSuffix): RGBPixelXY.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RGBPixelXY.cpp$(PreprocessSuffix) RGBPixelXY.cpp

$(IntermediateDirectory)/ImageSaver.cpp$(ObjectSuffix): ImageSaver.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/adria/Desktop/second-assignment-system32/second-assignment-system32/second-assignment-system32/ImageSaver.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ImageSaver.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ImageSaver.cpp$(PreprocessSuffix): ImageSaver.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ImageSaver.cpp$(PreprocessSuffix) ImageSaver.cpp

$(IntermediateDirectory)/PixelQueue.cpp$(ObjectSuffix): PixelQueue.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/adria/Desktop/second-assignment-system32/second-assignment-system32/second-assignment-system32/PixelQueue.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PixelQueue.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PixelQueue.cpp$(PreprocessSuffix): PixelQueue.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PixelQueue.cpp$(PreprocessSuffix) PixelQueue.cpp

$(IntermediateDirectory)/TinyImageJM.cpp$(ObjectSuffix): TinyImageJM.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/adria/Desktop/second-assignment-system32/second-assignment-system32/second-assignment-system32/TinyImageJM.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TinyImageJM.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TinyImageJM.cpp$(PreprocessSuffix): TinyImageJM.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TinyImageJM.cpp$(PreprocessSuffix) TinyImageJM.cpp

$(IntermediateDirectory)/T2.cpp$(ObjectSuffix): T2.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/adria/Desktop/second-assignment-system32/second-assignment-system32/second-assignment-system32/T2.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/T2.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/T2.cpp$(PreprocessSuffix): T2.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/T2.cpp$(PreprocessSuffix) T2.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/adria/Desktop/second-assignment-system32/second-assignment-system32/second-assignment-system32/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Timer.cpp$(ObjectSuffix): Timer.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/adria/Desktop/second-assignment-system32/second-assignment-system32/second-assignment-system32/Timer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Timer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Timer.cpp$(PreprocessSuffix): Timer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Timer.cpp$(PreprocessSuffix) Timer.cpp

$(IntermediateDirectory)/Queue.cpp$(ObjectSuffix): Queue.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/adria/Desktop/second-assignment-system32/second-assignment-system32/second-assignment-system32/Queue.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Queue.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Queue.cpp$(PreprocessSuffix): Queue.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Queue.cpp$(PreprocessSuffix) Queue.cpp

$(IntermediateDirectory)/ImageLoaderUI.cpp$(ObjectSuffix): ImageLoaderUI.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/adria/Desktop/second-assignment-system32/second-assignment-system32/second-assignment-system32/ImageLoaderUI.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ImageLoaderUI.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ImageLoaderUI.cpp$(PreprocessSuffix): ImageLoaderUI.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ImageLoaderUI.cpp$(PreprocessSuffix) ImageLoaderUI.cpp

##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


