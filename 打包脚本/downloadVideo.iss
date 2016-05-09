; �ű��� Inno Setup �ű��� ���ɣ�
; �йش��� Inno Setup �ű��ļ�����ϸ��������İ����ĵ���

#define MyAppName "VideoDownLoad"
;#define MyAppVersion "v2.0.8.1"
#define MyAppVersion "v1.3.5"
#define MyAppPublisher "��������"
#define MyAppURL "http://www.sisec.com.cn/"
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
OutputBaseFilename=����������{#MyAppVersion}
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
Name: "chinesesimp"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked; OnlyBelowVersion: 0,6.1
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "D:\work\downloadVideo\bin\*.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\work\downloadVideo\bin\fast_video.db"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\work\downloadVideo\bin\auto.bat"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\work\downloadVideo\bin\WinPcap_4_1_3.exe"; DestDir: "{app}"; Flags: ignoreversion  
Source: "D:\work\downloadVideo\bin\*.sys"; DestDir: "{app}"; Flags: ignoreversion

Source: "D:\work\downloadVideo\bin\CodeClient.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\work\downloadVideo\bin\CreateVolume_Client.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\work\downloadVideo\bin\download.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\work\downloadVideo\bin\FastVideo.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\work\downloadVideo\bin\MountVolume_Client.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\work\downloadVideo\bin\Start.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\work\downloadVideo\bin\StartSsd.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\work\downloadVideo\bin\VideoService.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\work\downloadVideo\bin\file\ipListAddress.txt"; DestDir: "{app}\file"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\work\downloadVideo\bin\log"; DestDir: "{app}\log"; Flags: ignoreversion recursesubdirs createallsubdirs 
Source: "D:\work\downloadVideo\bin\DaHuaTool\*"; DestDir: "{app}\DaHuaTool"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\work\downloadVideo\bin\factorys\*"; DestDir: "{app}\factorys"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\work\downloadVideo\bin\hikPlay\*"; DestDir: "{app}\hikPlay"; Flags: ignoreversion recursesubdirs createallsubdirs
;Source: "D:\work\downloadVideo\bin\image\*"; DestDir: "{app}\image"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\work\downloadVideo\bin\platforms\*"; DestDir: "{app}\platforms"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\work\downloadVideo\bin\screenRecord\*"; DestDir: "{app}\screenRecord"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\work\downloadVideo\bin\sqldrivers\*"; DestDir: "{app}\sqldrivers"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "D:\work\downloadVideo\bin\tool\*"; DestDir: "{app}\tool"; Flags: ignoreversion recursesubdirs createallsubdirs
; ע��: ��Ҫ���κι���ϵͳ�ļ���ʹ�á�Flags: ignoreversion��

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{group}\{cm:ProgramOnTheWeb,{#MyAppName}}"; Filename: "{#MyAppURL}"
Name: "{userdesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: quicklaunchicon

[Run]
Filename: "{app}\WinPcap_4_1_3.exe"; Description: "ץ������"; Flags: skipifsilent shellexec runhidden nowait postinstall
Filename: "{app}\auto.bat"; Description: "�Զ�ע��"; Flags: skipifsilent shellexec runhidden nowait postinstall
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent