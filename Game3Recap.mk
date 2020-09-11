##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Game3Recap
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/mohamed/Desktop/MY_CODE/Game_Project
ProjectPath            :=/home/mohamed/Desktop/MY_CODE/Game_Project/Game3Recap
IntermediateDirectory  :=../build-$(ConfigurationName)/Game3Recap
OutDir                 :=../build-$(ConfigurationName)/Game3Recap
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=mohamed
Date                   :=15/08/20
CodeLitePath           :=/home/mohamed/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)SFML_STATIC 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)/home/mohamed/Desktop/SFML-2.5.1-linux-gcc-64-bit/SFML-2.5.1/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)sfml-graphics $(LibrarySwitch)sfml-audio $(LibrarySwitch)sfml-window $(LibrarySwitch)sfml-network $(LibrarySwitch)sfml-system 
ArLibs                 :=  "sfml-graphics" "sfml-audio" "sfml-window" "sfml-network" "sfml-system" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/home/mohamed/Desktop/SFML-2.5.1-linux-gcc-64-bit/SFML-2.5.1/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS := -std=c++17 -Wall -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/Game3Recap/main.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Game3Recap/Game.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Game3Recap/Enemy.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Game3Recap/Bullet.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Game3Recap/Player.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Game3Recap/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/Game3Recap"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/Game3Recap"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/Game3Recap/.d:
	@mkdir -p "../build-$(ConfigurationName)/Game3Recap"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Game3Recap/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/Game3Recap/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mohamed/Desktop/MY_CODE/Game_Project/Game3Recap/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Game3Recap/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Game3Recap/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Game3Recap/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/Game3Recap/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Game3Recap/main.cpp$(PreprocessSuffix) main.cpp

../build-$(ConfigurationName)/Game3Recap/Game.cpp$(ObjectSuffix): Game.cpp ../build-$(ConfigurationName)/Game3Recap/Game.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mohamed/Desktop/MY_CODE/Game_Project/Game3Recap/Game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Game3Recap/Game.cpp$(DependSuffix): Game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Game3Recap/Game.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Game3Recap/Game.cpp$(DependSuffix) -MM Game.cpp

../build-$(ConfigurationName)/Game3Recap/Game.cpp$(PreprocessSuffix): Game.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Game3Recap/Game.cpp$(PreprocessSuffix) Game.cpp

../build-$(ConfigurationName)/Game3Recap/Enemy.cpp$(ObjectSuffix): Enemy.cpp ../build-$(ConfigurationName)/Game3Recap/Enemy.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mohamed/Desktop/MY_CODE/Game_Project/Game3Recap/Enemy.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Enemy.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Game3Recap/Enemy.cpp$(DependSuffix): Enemy.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Game3Recap/Enemy.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Game3Recap/Enemy.cpp$(DependSuffix) -MM Enemy.cpp

../build-$(ConfigurationName)/Game3Recap/Enemy.cpp$(PreprocessSuffix): Enemy.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Game3Recap/Enemy.cpp$(PreprocessSuffix) Enemy.cpp

../build-$(ConfigurationName)/Game3Recap/Bullet.cpp$(ObjectSuffix): Bullet.cpp ../build-$(ConfigurationName)/Game3Recap/Bullet.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mohamed/Desktop/MY_CODE/Game_Project/Game3Recap/Bullet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Bullet.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Game3Recap/Bullet.cpp$(DependSuffix): Bullet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Game3Recap/Bullet.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Game3Recap/Bullet.cpp$(DependSuffix) -MM Bullet.cpp

../build-$(ConfigurationName)/Game3Recap/Bullet.cpp$(PreprocessSuffix): Bullet.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Game3Recap/Bullet.cpp$(PreprocessSuffix) Bullet.cpp

../build-$(ConfigurationName)/Game3Recap/Player.cpp$(ObjectSuffix): Player.cpp ../build-$(ConfigurationName)/Game3Recap/Player.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mohamed/Desktop/MY_CODE/Game_Project/Game3Recap/Player.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Player.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Game3Recap/Player.cpp$(DependSuffix): Player.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Game3Recap/Player.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Game3Recap/Player.cpp$(DependSuffix) -MM Player.cpp

../build-$(ConfigurationName)/Game3Recap/Player.cpp$(PreprocessSuffix): Player.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Game3Recap/Player.cpp$(PreprocessSuffix) Player.cpp


-include ../build-$(ConfigurationName)/Game3Recap//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


