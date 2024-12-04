##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=second-assignment-system32
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=/Users/crestas/second-assignment-system32/second-assignment-system32
ProjectPath            :=/Users/crestas/second-assignment-system32/second-assignment-system32/second-assignment-system32
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/second-assignment-system32
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Adrián Morales Rodríguez
Date                   :=03/12/2024
CodeLitePath           :=/Users/crestas/.codelite
MakeDirCommand         :=mkdir -p
LinkerName             :=gcc
SharedObjectLinkerName :=gcc -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=/Users/crestas/second-assignment-system32/second-assignment-system32/build-$(WorkspaceConfiguration)/bin
OutputFile             :=../build-$(WorkspaceConfiguration)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
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
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
CFLAGS   :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := llvm-as


##
## User defined environment variables
##
CodeLiteDir:=/Applications/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/RGBPixelXY.cpp$(ObjectSuffix) $(IntermediateDirectory)/Queue.cpp$(ObjectSuffix) $(IntermediateDirectory)/TinyImageJM.cpp$(ObjectSuffix) $(IntermediateDirectory)/PixelQueue.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@$(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/RGBPixelXY.cpp$(ObjectSuffix): RGBPixelXY.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/crestas/second-assignment-system32/second-assignment-system32/second-assignment-system32/RGBPixelXY.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RGBPixelXY.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RGBPixelXY.cpp$(PreprocessSuffix): RGBPixelXY.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RGBPixelXY.cpp$(PreprocessSuffix) RGBPixelXY.cpp

$(IntermediateDirectory)/Queue.cpp$(ObjectSuffix): Queue.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/crestas/second-assignment-system32/second-assignment-system32/second-assignment-system32/Queue.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Queue.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Queue.cpp$(PreprocessSuffix): Queue.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Queue.cpp$(PreprocessSuffix) Queue.cpp

$(IntermediateDirectory)/TinyImageJM.cpp$(ObjectSuffix): TinyImageJM.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/crestas/second-assignment-system32/second-assignment-system32/second-assignment-system32/TinyImageJM.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TinyImageJM.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TinyImageJM.cpp$(PreprocessSuffix): TinyImageJM.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TinyImageJM.cpp$(PreprocessSuffix) TinyImageJM.cpp

$(IntermediateDirectory)/PixelQueue.cpp$(ObjectSuffix): PixelQueue.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/crestas/second-assignment-system32/second-assignment-system32/second-assignment-system32/PixelQueue.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PixelQueue.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PixelQueue.cpp$(PreprocessSuffix): PixelQueue.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PixelQueue.cpp$(PreprocessSuffix) PixelQueue.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/crestas/second-assignment-system32/second-assignment-system32/second-assignment-system32/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


