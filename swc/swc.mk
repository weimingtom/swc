##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=swc
ConfigurationName      :=Debug
WorkspacePath          := "D:\CodeLiteWorkspace\swc"
ProjectPath            := "D:\CodeLiteWorkspace\swc\swc"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Administrator
Date                   :=14/01/2016
CodeLitePath           :="D:\Program Files\CodeLite"
LinkerName             :=D:/mingw32/bin/g++.exe
SharedObjectLinkerName :=D:/mingw32/bin/g++.exe -shared -fPIC
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="swc.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=D:/mingw32/bin/windres.exe
LinkOptions            :=  -static
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)comctl32 $(LibrarySwitch)gdi32 $(LibrarySwitch)comdlg32 
ArLibs                 :=  "comctl32" "gdi32" "comdlg32" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := D:/mingw32/bin/ar.exe rcu
CXX      := D:/mingw32/bin/g++.exe
CC       := D:/mingw32/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := D:/mingw32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=D:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/CApp.cpp$(ObjectSuffix) $(IntermediateDirectory)/CChildWnd.cpp$(ObjectSuffix) $(IntermediateDirectory)/CComboBoxExt.cpp$(ObjectSuffix) $(IntermediateDirectory)/CContainer.cpp$(ObjectSuffix) $(IntermediateDirectory)/CControlBarButton.cpp$(ObjectSuffix) $(IntermediateDirectory)/CFolder.cpp$(ObjectSuffix) $(IntermediateDirectory)/CFrame.cpp$(ObjectSuffix) $(IntermediateDirectory)/CFrameMDI.cpp$(ObjectSuffix) $(IntermediateDirectory)/CHeaderView.cpp$(ObjectSuffix) $(IntermediateDirectory)/CHookMenu.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/CMainFrame.cpp$(ObjectSuffix) $(IntermediateDirectory)/CMenuSpawn.cpp$(ObjectSuffix) $(IntermediateDirectory)/CMiniDock.cpp$(ObjectSuffix) $(IntermediateDirectory)/CMiniFrame.cpp$(ObjectSuffix) $(IntermediateDirectory)/CMMedia.cpp$(ObjectSuffix) $(IntermediateDirectory)/COutLook.cpp$(ObjectSuffix) $(IntermediateDirectory)/CSplitter.cpp$(ObjectSuffix) $(IntermediateDirectory)/CTabbed.cpp$(ObjectSuffix) $(IntermediateDirectory)/CToolBarCtrl.cpp$(ObjectSuffix) $(IntermediateDirectory)/CToolButton.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/CWin.cpp$(ObjectSuffix) $(IntermediateDirectory)/CWorkTab.cpp$(ObjectSuffix) $(IntermediateDirectory)/debug.cpp$(ObjectSuffix) $(IntermediateDirectory)/DockManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/main_pwcstudio.cpp$(ObjectSuffix) $(IntermediateDirectory)/NewBValArray.cpp$(ObjectSuffix) 

Objects1=$(IntermediateDirectory)/swc.cpp$(ObjectSuffix) $(IntermediateDirectory)/mdi_WinClass.rc$(ObjectSuffix) $(IntermediateDirectory)/outlookdemo_OutoolkDemo.rc$(ObjectSuffix) $(IntermediateDirectory)/pwcstudio_WinClass.rc$(ObjectSuffix) \
	



Objects=$(Objects0) $(Objects1) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	@echo $(Objects1) >> $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/CApp.cpp$(ObjectSuffix): CApp.cpp $(IntermediateDirectory)/CApp.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteWorkspace/swc/swc/CApp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CApp.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CApp.cpp$(DependSuffix): CApp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CApp.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CApp.cpp$(DependSuffix) -MM "CApp.cpp"

$(IntermediateDirectory)/CApp.cpp$(PreprocessSuffix): CApp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CApp.cpp$(PreprocessSuffix) "CApp.cpp"

$(IntermediateDirectory)/CChildWnd.cpp$(ObjectSuffix): CChildWnd.cpp $(IntermediateDirectory)/CChildWnd.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteWorkspace/swc/swc/CChildWnd.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CChildWnd.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CChildWnd.cpp$(DependSuffix): CChildWnd.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CChildWnd.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CChildWnd.cpp$(DependSuffix) -MM "CChildWnd.cpp"

$(IntermediateDirectory)/CChildWnd.cpp$(PreprocessSuffix): CChildWnd.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CChildWnd.cpp$(PreprocessSuffix) "CChildWnd.cpp"

$(IntermediateDirectory)/CComboBoxExt.cpp$(ObjectSuffix): CComboBoxExt.cpp $(IntermediateDirectory)/CComboBoxExt.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteWorkspace/swc/swc/CComboBoxExt.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CComboBoxExt.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CComboBoxExt.cpp$(DependSuffix): CComboBoxExt.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CComboBoxExt.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CComboBoxExt.cpp$(DependSuffix) -MM "CComboBoxExt.cpp"

$(IntermediateDirectory)/CComboBoxExt.cpp$(PreprocessSuffix): CComboBoxExt.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CComboBoxExt.cpp$(PreprocessSuffix) "CComboBoxExt.cpp"

$(IntermediateDirectory)/CContainer.cpp$(ObjectSuffix): CContainer.cpp $(IntermediateDirectory)/CContainer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteWorkspace/swc/swc/CContainer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CContainer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CContainer.cpp$(DependSuffix): CContainer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CContainer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CContainer.cpp$(DependSuffix) -MM "CContainer.cpp"

$(IntermediateDirectory)/CContainer.cpp$(PreprocessSuffix): CContainer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CContainer.cpp$(PreprocessSuffix) "CContainer.cpp"

$(IntermediateDirectory)/CControlBarButton.cpp$(ObjectSuffix): CControlBarButton.cpp $(IntermediateDirectory)/CControlBarButton.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteWorkspace/swc/swc/CControlBarButton.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CControlBarButton.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CControlBarButton.cpp$(DependSuffix): CControlBarButton.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CControlBarButton.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CControlBarButton.cpp$(DependSuffix) -MM "CControlBarButton.cpp"

$(IntermediateDirectory)/CControlBarButton.cpp$(PreprocessSuffix): CControlBarButton.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CControlBarButton.cpp$(PreprocessSuffix) "CControlBarButton.cpp"

$(IntermediateDirectory)/CFolder.cpp$(ObjectSuffix): CFolder.cpp $(IntermediateDirectory)/CFolder.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteWorkspace/swc/swc/CFolder.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CFolder.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFolder.cpp$(DependSuffix): CFolder.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CFolder.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CFolder.cpp$(DependSuffix) -MM "CFolder.cpp"

$(IntermediateDirectory)/CFolder.cpp$(PreprocessSuffix): CFolder.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CFolder.cpp$(PreprocessSuffix) "CFolder.cpp"

$(IntermediateDirectory)/CFrame.cpp$(ObjectSuffix): CFrame.cpp $(IntermediateDirectory)/CFrame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteWorkspace/swc/swc/CFrame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CFrame.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFrame.cpp$(DependSuffix): CFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CFrame.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CFrame.cpp$(DependSuffix) -MM "CFrame.cpp"

$(IntermediateDirectory)/CFrame.cpp$(PreprocessSuffix): CFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CFrame.cpp$(PreprocessSuffix) "CFrame.cpp"

$(IntermediateDirectory)/CFrameMDI.cpp$(ObjectSuffix): CFrameMDI.cpp $(IntermediateDirectory)/CFrameMDI.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteWorkspace/swc/swc/CFrameMDI.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CFrameMDI.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CFrameMDI.cpp$(DependSuffix): CFrameMDI.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CFrameMDI.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CFrameMDI.cpp$(DependSuffix) -MM "CFrameMDI.cpp"

$(IntermediateDirectory)/CFrameMDI.cpp$(PreprocessSuffix): CFrameMDI.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CFrameMDI.cpp$(PreprocessSuffix) "CFrameMDI.cpp"

$(IntermediateDirectory)/CHeaderView.cpp$(ObjectSuffix): CHeaderView.cpp $(IntermediateDirectory)/CHeaderView.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteWorkspace/swc/swc/CHeaderView.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CHeaderView.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CHeaderView.cpp$(DependSuffix): CHeaderView.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CHeaderView.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CHeaderView.cpp$(DependSuffix) -MM "CHeaderView.cpp"

$(IntermediateDirectory)/CHeaderView.cpp$(PreprocessSuffix): CHeaderView.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CHeaderView.cpp$(PreprocessSuffix) "CHeaderView.cpp"

$(IntermediateDirectory)/CHookMenu.cpp$(ObjectSuffix): CHookMenu.cpp $(IntermediateDirectory)/CHookMenu.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteWorkspace/swc/swc/CHookMenu.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CHookMenu.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CHookMenu.cpp$(DependSuffix): CHookMenu.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CHookMenu.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CHookMenu.cpp$(DependSuffix) -MM "CHookMenu.cpp"

$(IntermediateDirectory)/CHookMenu.cpp$(PreprocessSuffix): CHookMenu.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CHookMenu.cpp$(PreprocessSuffix) "CHookMenu.cpp"

$(IntermediateDirectory)/CMainFrame.cpp$(ObjectSuffix): CMainFrame.cpp $(IntermediateDirectory)/CMainFrame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteWorkspace/swc/swc/CMainFrame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CMainFrame.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CMainFrame.cpp$(DependSuffix): CMainFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CMainFrame.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CMainFrame.cpp$(DependSuffix) -MM "CMainFrame.cpp"

$(IntermediateDirectory)/CMainFrame.cpp$(PreprocessSuffix): CMainFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CMainFrame.cpp$(PreprocessSuffix) "CMainFrame.cpp"

$(IntermediateDirectory)/CMenuSpawn.cpp$(ObjectSuffix): CMenuSpawn.cpp $(IntermediateDirectory)/CMenuSpawn.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteWorkspace/swc/swc/CMenuSpawn.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CMenuSpawn.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CMenuSpawn.cpp$(DependSuffix): CMenuSpawn.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CMenuSpawn.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CMenuSpawn.cpp$(DependSuffix) -MM "CMenuSpawn.cpp"

$(IntermediateDirectory)/CMenuSpawn.cpp$(PreprocessSuffix): CMenuSpawn.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CMenuSpawn.cpp$(PreprocessSuffix) "CMenuSpawn.cpp"

$(IntermediateDirectory)/CMiniDock.cpp$(ObjectSuffix): CMiniDock.cpp $(IntermediateDirectory)/CMiniDock.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteWorkspace/swc/swc/CMiniDock.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CMiniDock.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CMiniDock.cpp$(DependSuffix): CMiniDock.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CMiniDock.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CMiniDock.cpp$(DependSuffix) -MM "CMiniDock.cpp"

$(IntermediateDirectory)/CMiniDock.cpp$(PreprocessSuffix): CMiniDock.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CMiniDock.cpp$(PreprocessSuffix) "CMiniDock.cpp"

$(IntermediateDirectory)/CMiniFrame.cpp$(ObjectSuffix): CMiniFrame.cpp $(IntermediateDirectory)/CMiniFrame.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteWorkspace/swc/swc/CMiniFrame.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CMiniFrame.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CMiniFrame.cpp$(DependSuffix): CMiniFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CMiniFrame.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CMiniFrame.cpp$(DependSuffix) -MM "CMiniFrame.cpp"

$(IntermediateDirectory)/CMiniFrame.cpp$(PreprocessSuffix): CMiniFrame.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CMiniFrame.cpp$(PreprocessSuffix) "CMiniFrame.cpp"

$(IntermediateDirectory)/CMMedia.cpp$(ObjectSuffix): CMMedia.cpp $(IntermediateDirectory)/CMMedia.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteWorkspace/swc/swc/CMMedia.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CMMedia.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CMMedia.cpp$(DependSuffix): CMMedia.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CMMedia.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CMMedia.cpp$(DependSuffix) -MM "CMMedia.cpp"

$(IntermediateDirectory)/CMMedia.cpp$(PreprocessSuffix): CMMedia.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CMMedia.cpp$(PreprocessSuffix) "CMMedia.cpp"

$(IntermediateDirectory)/COutLook.cpp$(ObjectSuffix): COutLook.cpp $(IntermediateDirectory)/COutLook.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteWorkspace/swc/swc/COutLook.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/COutLook.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/COutLook.cpp$(DependSuffix): COutLook.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/COutLook.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/COutLook.cpp$(DependSuffix) -MM "COutLook.cpp"

$(IntermediateDirectory)/COutLook.cpp$(PreprocessSuffix): COutLook.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/COutLook.cpp$(PreprocessSuffix) "COutLook.cpp"

$(IntermediateDirectory)/CSplitter.cpp$(ObjectSuffix): CSplitter.cpp $(IntermediateDirectory)/CSplitter.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteWorkspace/swc/swc/CSplitter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CSplitter.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CSplitter.cpp$(DependSuffix): CSplitter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CSplitter.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CSplitter.cpp$(DependSuffix) -MM "CSplitter.cpp"

$(IntermediateDirectory)/CSplitter.cpp$(PreprocessSuffix): CSplitter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CSplitter.cpp$(PreprocessSuffix) "CSplitter.cpp"

$(IntermediateDirectory)/CTabbed.cpp$(ObjectSuffix): CTabbed.cpp $(IntermediateDirectory)/CTabbed.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteWorkspace/swc/swc/CTabbed.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CTabbed.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CTabbed.cpp$(DependSuffix): CTabbed.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CTabbed.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CTabbed.cpp$(DependSuffix) -MM "CTabbed.cpp"

$(IntermediateDirectory)/CTabbed.cpp$(PreprocessSuffix): CTabbed.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CTabbed.cpp$(PreprocessSuffix) "CTabbed.cpp"

$(IntermediateDirectory)/CToolBarCtrl.cpp$(ObjectSuffix): CToolBarCtrl.cpp $(IntermediateDirectory)/CToolBarCtrl.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteWorkspace/swc/swc/CToolBarCtrl.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CToolBarCtrl.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CToolBarCtrl.cpp$(DependSuffix): CToolBarCtrl.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CToolBarCtrl.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CToolBarCtrl.cpp$(DependSuffix) -MM "CToolBarCtrl.cpp"

$(IntermediateDirectory)/CToolBarCtrl.cpp$(PreprocessSuffix): CToolBarCtrl.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CToolBarCtrl.cpp$(PreprocessSuffix) "CToolBarCtrl.cpp"

$(IntermediateDirectory)/CToolButton.cpp$(ObjectSuffix): CToolButton.cpp $(IntermediateDirectory)/CToolButton.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteWorkspace/swc/swc/CToolButton.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CToolButton.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CToolButton.cpp$(DependSuffix): CToolButton.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CToolButton.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CToolButton.cpp$(DependSuffix) -MM "CToolButton.cpp"

$(IntermediateDirectory)/CToolButton.cpp$(PreprocessSuffix): CToolButton.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CToolButton.cpp$(PreprocessSuffix) "CToolButton.cpp"

$(IntermediateDirectory)/CWin.cpp$(ObjectSuffix): CWin.cpp $(IntermediateDirectory)/CWin.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteWorkspace/swc/swc/CWin.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CWin.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CWin.cpp$(DependSuffix): CWin.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CWin.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CWin.cpp$(DependSuffix) -MM "CWin.cpp"

$(IntermediateDirectory)/CWin.cpp$(PreprocessSuffix): CWin.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CWin.cpp$(PreprocessSuffix) "CWin.cpp"

$(IntermediateDirectory)/CWorkTab.cpp$(ObjectSuffix): CWorkTab.cpp $(IntermediateDirectory)/CWorkTab.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteWorkspace/swc/swc/CWorkTab.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CWorkTab.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CWorkTab.cpp$(DependSuffix): CWorkTab.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CWorkTab.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CWorkTab.cpp$(DependSuffix) -MM "CWorkTab.cpp"

$(IntermediateDirectory)/CWorkTab.cpp$(PreprocessSuffix): CWorkTab.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CWorkTab.cpp$(PreprocessSuffix) "CWorkTab.cpp"

$(IntermediateDirectory)/debug.cpp$(ObjectSuffix): debug.cpp $(IntermediateDirectory)/debug.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteWorkspace/swc/swc/debug.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/debug.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/debug.cpp$(DependSuffix): debug.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/debug.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/debug.cpp$(DependSuffix) -MM "debug.cpp"

$(IntermediateDirectory)/debug.cpp$(PreprocessSuffix): debug.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/debug.cpp$(PreprocessSuffix) "debug.cpp"

$(IntermediateDirectory)/DockManager.cpp$(ObjectSuffix): DockManager.cpp $(IntermediateDirectory)/DockManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteWorkspace/swc/swc/DockManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DockManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DockManager.cpp$(DependSuffix): DockManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DockManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/DockManager.cpp$(DependSuffix) -MM "DockManager.cpp"

$(IntermediateDirectory)/DockManager.cpp$(PreprocessSuffix): DockManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DockManager.cpp$(PreprocessSuffix) "DockManager.cpp"

$(IntermediateDirectory)/main_pwcstudio.cpp$(ObjectSuffix): main_pwcstudio.cpp $(IntermediateDirectory)/main_pwcstudio.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteWorkspace/swc/swc/main_pwcstudio.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main_pwcstudio.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main_pwcstudio.cpp$(DependSuffix): main_pwcstudio.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main_pwcstudio.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main_pwcstudio.cpp$(DependSuffix) -MM "main_pwcstudio.cpp"

$(IntermediateDirectory)/main_pwcstudio.cpp$(PreprocessSuffix): main_pwcstudio.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main_pwcstudio.cpp$(PreprocessSuffix) "main_pwcstudio.cpp"

$(IntermediateDirectory)/NewBValArray.cpp$(ObjectSuffix): NewBValArray.cpp $(IntermediateDirectory)/NewBValArray.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteWorkspace/swc/swc/NewBValArray.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/NewBValArray.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/NewBValArray.cpp$(DependSuffix): NewBValArray.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/NewBValArray.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/NewBValArray.cpp$(DependSuffix) -MM "NewBValArray.cpp"

$(IntermediateDirectory)/NewBValArray.cpp$(PreprocessSuffix): NewBValArray.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/NewBValArray.cpp$(PreprocessSuffix) "NewBValArray.cpp"

$(IntermediateDirectory)/swc.cpp$(ObjectSuffix): swc.cpp $(IntermediateDirectory)/swc.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/CodeLiteWorkspace/swc/swc/swc.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/swc.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/swc.cpp$(DependSuffix): swc.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/swc.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/swc.cpp$(DependSuffix) -MM "swc.cpp"

$(IntermediateDirectory)/swc.cpp$(PreprocessSuffix): swc.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/swc.cpp$(PreprocessSuffix) "swc.cpp"

$(IntermediateDirectory)/mdi_WinClass.rc$(ObjectSuffix): mdi/WinClass.rc
	$(RcCompilerName) -i "D:/CodeLiteWorkspace/swc/swc/mdi/WinClass.rc" $(RcCmpOptions)   $(ObjectSwitch)$(IntermediateDirectory)/mdi_WinClass.rc$(ObjectSuffix) $(RcIncludePath)
$(IntermediateDirectory)/outlookdemo_OutoolkDemo.rc$(ObjectSuffix): outlookdemo/OutoolkDemo.rc
	$(RcCompilerName) -i "D:/CodeLiteWorkspace/swc/swc/outlookdemo/OutoolkDemo.rc" $(RcCmpOptions)   $(ObjectSwitch)$(IntermediateDirectory)/outlookdemo_OutoolkDemo.rc$(ObjectSuffix) $(RcIncludePath)
$(IntermediateDirectory)/pwcstudio_WinClass.rc$(ObjectSuffix): pwcstudio/WinClass.rc
	$(RcCompilerName) -i "D:/CodeLiteWorkspace/swc/swc/pwcstudio/WinClass.rc" $(RcCmpOptions)   $(ObjectSwitch)$(IntermediateDirectory)/pwcstudio_WinClass.rc$(ObjectSuffix) $(RcIncludePath)

-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


