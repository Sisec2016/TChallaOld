; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���

#define MyAppName "VideoDownLoad"
#define MyAppVersion "v1.3.4.10.4(widescreen)"
#define MyAppPublisher "�麣��������Զ��Ƽ����޹�˾"
#define MyAppURL "http://www.rmax.com/"
#define MyAppExeName "FastVideo.exe"

[Setup]
; ע: AppId��ֵΪ������ʶ��Ӧ�ó���
; ��ҪΪ������װ����ʹ����ͬ��AppIdֵ��
; (�����µ�GUID����� ����|��IDE������GUID��)
AppId={{92156374-EE64-4A6B-9486-DEB0EFAD5FB3}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName=C:\{#MyAppName}
DefaultGroupName={#MyAppName}
OutputBaseFilename=patch_{#MyAppVersion}
Compression=lzma
ShowLanguageDialog=no
SolidCompression=yes
UsePreviousUserInfo=no
UsePreviousAppDir=no 
UsePreviousGroup=no 
UsePreviousLanguage=no 
UsePreviousSetupType=no 
UsePreviousTasks=no 
DisableDirPage=yes 
DisableFinishedPage=no 
DisableProgramGroupPage=yes 
DisableReadyMemo=yes 
DisableReadyPage=yes 
DisableStartupPrompt=yes 
DisableWelcomePage=no 

[Languages] 
Name: "en"; MessagesFile: "compiler:Default.isl"  
Name: "Chinese"; MessagesFile: "compiler:Languages\ChineseSimplified.isl"  

[Files]   								                            
Source: "C:\VideoDownLoad\FastVideo.exe"; 		          DestDir: "{app}"; Flags: ignoreversion;    Excludes:"unins000.*"  
Source: "C:\VideoDownLoad\VideoService.exe"; 		          DestDir: "{app}"; Flags: ignoreversion;   Excludes:"unins000.*"
Source: "C:\VideoDownLoad\Start.exe"; 		          DestDir: "{app}"; Flags: ignoreversion;   Excludes:"unins000.*"
Source: "C:\VideoDownLoad\factorys\DH\*"; 		      DestDir: "{app}\factorys\DH"; 		Flags: ignoreversion recursesubdirs createallsubdirs;   Excludes:"*.lib;*.pdb"
Source: "C:\VideoDownLoad\factorys\JiaXJ\JXJVideoServer.dll"; 		      DestDir: "{app}\factorys\JiaXJ"; 		Flags: ignoreversion recursesubdirs createallsubdirs;   Excludes:"*.lib;*.pdb"
Source: "C:\VideoDownLoad\factorys\DiZhiPu\DiZhiPuVideoServer.dll"; 		      DestDir: "{app}\factorys\DiZhiPu"; 		Flags: ignoreversion recursesubdirs createallsubdirs;   Excludes:"*.lib;*.pdb"

; ע��: ��Ҫ���κι���ϵͳ�ļ���ʹ�á�Flags: ignoreversion��

[Dirs]
Name: "{app}\log"; 	  Flags: uninsalwaysuninstall
Name: "{app}\file"; 	Flags: uninsalwaysuninstall
