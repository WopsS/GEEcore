#pragma once

#include <Windows.h>

// Order is important for "mmsystem.h" and "mmddk.h".
#include <mmsystem.h>

#include <mmddk.h>

#undef PlaySound

namespace geecore::detail::proxies
{
using CloseDriverType = decltype(&::CloseDriver);
using DefDriverProcType = decltype(&::DefDriverProc);
using DriverCallbackType = decltype(&::DriverCallback);
using DrvGetModuleHandleType = decltype(&::DrvGetModuleHandle);
using GetDriverModuleHandleType = decltype(&::GetDriverModuleHandle);
using OpenDriverType = decltype(&::OpenDriver);
using PlaySoundType = decltype(&::PlaySoundA);
using PlaySoundAType = decltype(&::PlaySoundA);
using PlaySoundWType = decltype(&::PlaySoundW);
using SendDriverMessageType = decltype(&::SendDriverMessage);
using WOWAppExitType = void (*)();
using auxGetDevCapsAType = decltype(&::auxGetDevCapsA);
using auxGetDevCapsWType = decltype(&::auxGetDevCapsW);
using auxGetNumDevsType = decltype(&::auxGetNumDevs);
using auxGetVolumeType = decltype(&::auxGetVolume);
using auxOutMessageType = decltype(&::auxOutMessage);
using auxSetVolumeType = decltype(&::auxSetVolume);
using joyConfigChangedType = decltype(&::joyConfigChanged);
using joyGetDevCapsAType = decltype(&::joyGetDevCapsA);
using joyGetDevCapsWType = decltype(&::joyGetDevCapsW);
using joyGetNumDevsType = decltype(&::joyGetNumDevs);
using joyGetPosType = decltype(&::joyGetPos);
using joyGetPosExType = decltype(&::joyGetPosEx);
using joyGetThresholdType = decltype(&::joyGetThreshold);
using joyReleaseCaptureType = decltype(&::joyReleaseCapture);
using joySetCaptureType = decltype(&::joySetCapture);
using joySetThresholdType = decltype(&::joySetThreshold);
using mciDriverNotifyType = decltype(&::mciDriverNotify);
using mciDriverYieldType = decltype(&::mciDriverYield);
using mciExecuteType = void (*)();
using mciFreeCommandResourceType = decltype(&::mciFreeCommandResource);
using mciGetCreatorTaskType = decltype(&::mciGetCreatorTask);
using mciGetDeviceIDAType = decltype(&::mciGetDeviceIDA);
using mciGetDeviceIDFromElementIDAType = decltype(&::mciGetDeviceIDFromElementIDA);
using mciGetDeviceIDFromElementIDWType = decltype(&::mciGetDeviceIDFromElementIDW);
using mciGetDeviceIDWType = decltype(&::mciGetDeviceIDW);
using mciGetDriverDataType = decltype(&::mciGetDriverData);
using mciGetErrorStringAType = decltype(&::mciGetErrorStringA);
using mciGetErrorStringWType = decltype(&::mciGetErrorStringW);
using mciGetYieldProcType = decltype(&::mciGetYieldProc);
using mciLoadCommandResourceType = decltype(&::mciLoadCommandResource);
using mciSendCommandAType = decltype(&::mciSendCommandA);
using mciSendCommandWType = decltype(&::mciSendCommandW);
using mciSendStringAType = decltype(&::mciSendStringA);
using mciSendStringWType = decltype(&::mciSendStringW);
using mciSetDriverDataType = decltype(&::mciSetDriverData);
using mciSetYieldProcType = decltype(&::mciSetYieldProc);
using midiConnectType = decltype(&::midiConnect);
using midiDisconnectType = decltype(&::midiDisconnect);
using midiInAddBufferType = decltype(&::midiInAddBuffer);
using midiInCloseType = decltype(&::midiInClose);
using midiInGetDevCapsAType = decltype(&::midiInGetDevCapsA);
using midiInGetDevCapsWType = decltype(&::midiInGetDevCapsW);
using midiInGetErrorTextAType = decltype(&::midiInGetErrorTextA);
using midiInGetErrorTextWType = decltype(&::midiInGetErrorTextW);
using midiInGetIDType = decltype(&::midiInGetID);
using midiInGetNumDevsType = decltype(&::midiInGetNumDevs);
using midiInMessageType = decltype(&::midiInMessage);
using midiInOpenType = decltype(&::midiInOpen);
using midiInPrepareHeaderType = decltype(&::midiInPrepareHeader);
using midiInResetType = decltype(&::midiInReset);
using midiInStartType = decltype(&::midiInStart);
using midiInStopType = decltype(&::midiInStop);
using midiInUnprepareHeaderType = decltype(&::midiInUnprepareHeader);
using midiOutCacheDrumPatchesType = decltype(&::midiOutCacheDrumPatches);
using midiOutCachePatchesType = decltype(&::midiOutCachePatches);
using midiOutCloseType = decltype(&::midiOutClose);
using midiOutGetDevCapsAType = decltype(&::midiOutGetDevCapsA);
using midiOutGetDevCapsWType = decltype(&::midiOutGetDevCapsW);
using midiOutGetErrorTextAType = decltype(&::midiOutGetErrorTextA);
using midiOutGetErrorTextWType = decltype(&::midiOutGetErrorTextW);
using midiOutGetIDType = decltype(&::midiOutGetID);
using midiOutGetNumDevsType = decltype(&::midiOutGetNumDevs);
using midiOutGetVolumeType = decltype(&::midiOutGetVolume);
using midiOutLongMsgType = decltype(&::midiOutLongMsg);
using midiOutMessageType = decltype(&::midiOutMessage);
using midiOutOpenType = decltype(&::midiOutOpen);
using midiOutPrepareHeaderType = decltype(&::midiOutPrepareHeader);
using midiOutResetType = decltype(&::midiOutReset);
using midiOutSetVolumeType = decltype(&::midiOutSetVolume);
using midiOutShortMsgType = decltype(&::midiOutShortMsg);
using midiOutUnprepareHeaderType = decltype(&::midiOutUnprepareHeader);
using midiStreamCloseType = decltype(&::midiStreamClose);
using midiStreamOpenType = decltype(&::midiStreamOpen);
using midiStreamOutType = decltype(&::midiStreamOut);
using midiStreamPauseType = decltype(&::midiStreamPause);
using midiStreamPositionType = decltype(&::midiStreamPosition);
using midiStreamPropertyType = decltype(&::midiStreamProperty);
using midiStreamRestartType = decltype(&::midiStreamRestart);
using midiStreamStopType = decltype(&::midiStreamStop);
using mixerCloseType = decltype(&::mixerClose);
using mixerGetControlDetailsAType = decltype(&::mixerGetControlDetailsA);
using mixerGetControlDetailsWType = decltype(&::mixerGetControlDetailsW);
using mixerGetDevCapsAType = decltype(&::mixerGetDevCapsA);
using mixerGetDevCapsWType = decltype(&::mixerGetDevCapsW);
using mixerGetIDType = decltype(&::mixerGetID);
using mixerGetLineControlsAType = decltype(&::mixerGetLineControlsA);
using mixerGetLineControlsWType = decltype(&::mixerGetLineControlsW);
using mixerGetLineInfoAType = decltype(&::mixerGetLineInfoA);
using mixerGetLineInfoWType = decltype(&::mixerGetLineInfoW);
using mixerGetNumDevsType = decltype(&::mixerGetNumDevs);
using mixerMessageType = decltype(&::mixerMessage);
using mixerOpenType = decltype(&::mixerOpen);
using mixerSetControlDetailsType = decltype(&::mixerSetControlDetails);
using mmDrvInstallType = decltype(&::mmDrvInstall);
using mmGetCurrentTaskType = decltype(&::mmGetCurrentTask);
using mmTaskBlockType = decltype(&::mmTaskBlock);
using mmTaskCreateType = decltype(&::mmTaskCreate);
using mmTaskSignalType = decltype(&::mmTaskSignal);
using mmTaskYieldType = decltype(&::mmTaskYield);
using mmioAdvanceType = decltype(&::mmioAdvance);
using mmioAscendType = decltype(&::mmioAscend);
using mmioCloseType = decltype(&::mmioClose);
using mmioCreateChunkType = decltype(&::mmioCreateChunk);
using mmioDescendType = decltype(&::mmioDescend);
using mmioFlushType = decltype(&::mmioFlush);
using mmioGetInfoType = decltype(&::mmioGetInfo);
using mmioInstallIOProcAType = decltype(&::mmioInstallIOProcA);
using mmioInstallIOProcWType = decltype(&::mmioInstallIOProcW);
using mmioOpenAType = decltype(&::mmioOpenA);
using mmioOpenWType = decltype(&::mmioOpenW);
using mmioReadType = decltype(&::mmioRead);
using mmioRenameAType = decltype(&::mmioRenameA);
using mmioRenameWType = decltype(&::mmioRenameW);
using mmioSeekType = decltype(&::mmioSeek);
using mmioSendMessageType = decltype(&::mmioSendMessage);
using mmioSetBufferType = decltype(&::mmioSetBuffer);
using mmioSetInfoType = decltype(&::mmioSetInfo);
using mmioStringToFOURCCAType = decltype(&::mmioStringToFOURCCA);
using mmioStringToFOURCCWType = decltype(&::mmioStringToFOURCCW);
using mmioWriteType = decltype(&::mmioWrite);
using mmsystemGetVersionType = void (*)();
using sndPlaySoundAType = decltype(&::sndPlaySoundA);
using sndPlaySoundWType = decltype(&::sndPlaySoundW);
using timeBeginPeriodType = decltype(&::timeBeginPeriod);
using timeEndPeriodType = decltype(&::timeEndPeriod);
using timeGetDevCapsType = decltype(&::timeGetDevCaps);
using timeGetSystemTimeType = decltype(&::timeGetSystemTime);
using timeGetTimeType = decltype(&::timeGetTime);
using timeKillEventType = decltype(&::timeKillEvent);
using timeSetEventType = decltype(&::timeSetEvent);
using waveInAddBufferType = decltype(&::waveInAddBuffer);
using waveInCloseType = decltype(&::waveInClose);
using waveInGetDevCapsAType = decltype(&::waveInGetDevCapsA);
using waveInGetDevCapsWType = decltype(&::waveInGetDevCapsW);
using waveInGetErrorTextAType = decltype(&::waveInGetErrorTextA);
using waveInGetErrorTextWType = decltype(&::waveInGetErrorTextW);
using waveInGetIDType = decltype(&::waveInGetID);
using waveInGetNumDevsType = decltype(&::waveInGetNumDevs);
using waveInGetPositionType = decltype(&::waveInGetPosition);
using waveInMessageType = decltype(&::waveInMessage);
using waveInOpenType = decltype(&::waveInOpen);
using waveInPrepareHeaderType = decltype(&::waveInPrepareHeader);
using waveInResetType = decltype(&::waveInReset);
using waveInStartType = decltype(&::waveInStart);
using waveInStopType = decltype(&::waveInStop);
using waveInUnprepareHeaderType = decltype(&::waveInUnprepareHeader);
using waveOutBreakLoopType = decltype(&::waveOutBreakLoop);
using waveOutCloseType = decltype(&::waveOutClose);
using waveOutGetDevCapsAType = decltype(&::waveOutGetDevCapsA);
using waveOutGetDevCapsWType = decltype(&::waveOutGetDevCapsW);
using waveOutGetErrorTextAType = decltype(&::waveOutGetErrorTextA);
using waveOutGetErrorTextWType = decltype(&::waveOutGetErrorTextW);
using waveOutGetIDType = decltype(&::waveOutGetID);
using waveOutGetNumDevsType = decltype(&::waveOutGetNumDevs);
using waveOutGetPitchType = decltype(&::waveOutGetPitch);
using waveOutGetPlaybackRateType = decltype(&::waveOutGetPlaybackRate);
using waveOutGetPositionType = decltype(&::waveOutGetPosition);
using waveOutGetVolumeType = decltype(&::waveOutGetVolume);
using waveOutMessageType = decltype(&::waveOutMessage);
using waveOutOpenType = decltype(&::waveOutOpen);
using waveOutPauseType = decltype(&::waveOutPause);
using waveOutPrepareHeaderType = decltype(&::waveOutPrepareHeader);
using waveOutResetType = decltype(&::waveOutReset);
using waveOutRestartType = decltype(&::waveOutRestart);
using waveOutSetPitchType = decltype(&::waveOutSetPitch);
using waveOutSetPlaybackRateType = decltype(&::waveOutSetPlaybackRate);
using waveOutSetVolumeType = decltype(&::waveOutSetVolume);
using waveOutUnprepareHeaderType = decltype(&::waveOutUnprepareHeader);
using waveOutWriteType = decltype(&::waveOutWrite);
using PlaySoundStubType = decltype(&::PlaySoundA);

extern CloseDriverType CloseDriver;
extern DefDriverProcType DefDriverProc;
extern DriverCallbackType DriverCallback;
extern DrvGetModuleHandleType DrvGetModuleHandle;
extern GetDriverModuleHandleType GetDriverModuleHandle;
extern OpenDriverType OpenDriver;
extern PlaySoundType PlaySound;
extern PlaySoundAType PlaySoundA;
extern PlaySoundWType PlaySoundW;
extern SendDriverMessageType SendDriverMessage;
extern WOWAppExitType WOWAppExit;
extern auxGetDevCapsAType auxGetDevCapsA;
extern auxGetDevCapsWType auxGetDevCapsW;
extern auxGetNumDevsType auxGetNumDevs;
extern auxGetVolumeType auxGetVolume;
extern auxOutMessageType auxOutMessage;
extern auxSetVolumeType auxSetVolume;
extern joyConfigChangedType joyConfigChanged;
extern joyGetDevCapsAType joyGetDevCapsA;
extern joyGetDevCapsWType joyGetDevCapsW;
extern joyGetNumDevsType joyGetNumDevs;
extern joyGetPosType joyGetPos;
extern joyGetPosExType joyGetPosEx;
extern joyGetThresholdType joyGetThreshold;
extern joyReleaseCaptureType joyReleaseCapture;
extern joySetCaptureType joySetCapture;
extern joySetThresholdType joySetThreshold;
extern mciDriverNotifyType mciDriverNotify;
extern mciDriverYieldType mciDriverYield;
extern mciExecuteType mciExecute;
extern mciFreeCommandResourceType mciFreeCommandResource;
extern mciGetCreatorTaskType mciGetCreatorTask;
extern mciGetDeviceIDAType mciGetDeviceIDA;
extern mciGetDeviceIDFromElementIDAType mciGetDeviceIDFromElementIDA;
extern mciGetDeviceIDFromElementIDWType mciGetDeviceIDFromElementIDW;
extern mciGetDeviceIDWType mciGetDeviceIDW;
extern mciGetDriverDataType mciGetDriverData;
extern mciGetErrorStringAType mciGetErrorStringA;
extern mciGetErrorStringWType mciGetErrorStringW;
extern mciGetYieldProcType mciGetYieldProc;
extern mciLoadCommandResourceType mciLoadCommandResource;
extern mciSendCommandAType mciSendCommandA;
extern mciSendCommandWType mciSendCommandW;
extern mciSendStringAType mciSendStringA;
extern mciSendStringWType mciSendStringW;
extern mciSetDriverDataType mciSetDriverData;
extern mciSetYieldProcType mciSetYieldProc;
extern midiConnectType midiConnect;
extern midiDisconnectType midiDisconnect;
extern midiInAddBufferType midiInAddBuffer;
extern midiInCloseType midiInClose;
extern midiInGetDevCapsAType midiInGetDevCapsA;
extern midiInGetDevCapsWType midiInGetDevCapsW;
extern midiInGetErrorTextAType midiInGetErrorTextA;
extern midiInGetErrorTextWType midiInGetErrorTextW;
extern midiInGetIDType midiInGetID;
extern midiInGetNumDevsType midiInGetNumDevs;
extern midiInMessageType midiInMessage;
extern midiInOpenType midiInOpen;
extern midiInPrepareHeaderType midiInPrepareHeader;
extern midiInResetType midiInReset;
extern midiInStartType midiInStart;
extern midiInStopType midiInStop;
extern midiInUnprepareHeaderType midiInUnprepareHeader;
extern midiOutCacheDrumPatchesType midiOutCacheDrumPatches;
extern midiOutCachePatchesType midiOutCachePatches;
extern midiOutCloseType midiOutClose;
extern midiOutGetDevCapsAType midiOutGetDevCapsA;
extern midiOutGetDevCapsWType midiOutGetDevCapsW;
extern midiOutGetErrorTextAType midiOutGetErrorTextA;
extern midiOutGetErrorTextWType midiOutGetErrorTextW;
extern midiOutGetIDType midiOutGetID;
extern midiOutGetNumDevsType midiOutGetNumDevs;
extern midiOutGetVolumeType midiOutGetVolume;
extern midiOutLongMsgType midiOutLongMsg;
extern midiOutMessageType midiOutMessage;
extern midiOutOpenType midiOutOpen;
extern midiOutPrepareHeaderType midiOutPrepareHeader;
extern midiOutResetType midiOutReset;
extern midiOutSetVolumeType midiOutSetVolume;
extern midiOutShortMsgType midiOutShortMsg;
extern midiOutUnprepareHeaderType midiOutUnprepareHeader;
extern midiStreamCloseType midiStreamClose;
extern midiStreamOpenType midiStreamOpen;
extern midiStreamOutType midiStreamOut;
extern midiStreamPauseType midiStreamPause;
extern midiStreamPositionType midiStreamPosition;
extern midiStreamPropertyType midiStreamProperty;
extern midiStreamRestartType midiStreamRestart;
extern midiStreamStopType midiStreamStop;
extern mixerCloseType mixerClose;
extern mixerGetControlDetailsAType mixerGetControlDetailsA;
extern mixerGetControlDetailsWType mixerGetControlDetailsW;
extern mixerGetDevCapsAType mixerGetDevCapsA;
extern mixerGetDevCapsWType mixerGetDevCapsW;
extern mixerGetIDType mixerGetID;
extern mixerGetLineControlsAType mixerGetLineControlsA;
extern mixerGetLineControlsWType mixerGetLineControlsW;
extern mixerGetLineInfoAType mixerGetLineInfoA;
extern mixerGetLineInfoWType mixerGetLineInfoW;
extern mixerGetNumDevsType mixerGetNumDevs;
extern mixerMessageType mixerMessage;
extern mixerOpenType mixerOpen;
extern mixerSetControlDetailsType mixerSetControlDetails;
extern mmDrvInstallType mmDrvInstall;
extern mmGetCurrentTaskType mmGetCurrentTask;
extern mmTaskBlockType mmTaskBlock;
extern mmTaskCreateType mmTaskCreate;
extern mmTaskSignalType mmTaskSignal;
extern mmTaskYieldType mmTaskYield;
extern mmioAdvanceType mmioAdvance;
extern mmioAscendType mmioAscend;
extern mmioCloseType mmioClose;
extern mmioCreateChunkType mmioCreateChunk;
extern mmioDescendType mmioDescend;
extern mmioFlushType mmioFlush;
extern mmioGetInfoType mmioGetInfo;
extern mmioInstallIOProcAType mmioInstallIOProcA;
extern mmioInstallIOProcWType mmioInstallIOProcW;
extern mmioOpenAType mmioOpenA;
extern mmioOpenWType mmioOpenW;
extern mmioReadType mmioRead;
extern mmioRenameAType mmioRenameA;
extern mmioRenameWType mmioRenameW;
extern mmioSeekType mmioSeek;
extern mmioSendMessageType mmioSendMessage;
extern mmioSetBufferType mmioSetBuffer;
extern mmioSetInfoType mmioSetInfo;
extern mmioStringToFOURCCAType mmioStringToFOURCCA;
extern mmioStringToFOURCCWType mmioStringToFOURCCW;
extern mmioWriteType mmioWrite;
extern mmsystemGetVersionType mmsystemGetVersion;
extern sndPlaySoundAType sndPlaySoundA;
extern sndPlaySoundWType sndPlaySoundW;
extern timeBeginPeriodType timeBeginPeriod;
extern timeEndPeriodType timeEndPeriod;
extern timeGetDevCapsType timeGetDevCaps;
extern timeGetSystemTimeType timeGetSystemTime;
extern timeGetTimeType timeGetTime;
extern timeKillEventType timeKillEvent;
extern timeSetEventType timeSetEvent;
extern waveInAddBufferType waveInAddBuffer;
extern waveInCloseType waveInClose;
extern waveInGetDevCapsAType waveInGetDevCapsA;
extern waveInGetDevCapsWType waveInGetDevCapsW;
extern waveInGetErrorTextAType waveInGetErrorTextA;
extern waveInGetErrorTextWType waveInGetErrorTextW;
extern waveInGetIDType waveInGetID;
extern waveInGetNumDevsType waveInGetNumDevs;
extern waveInGetPositionType waveInGetPosition;
extern waveInMessageType waveInMessage;
extern waveInOpenType waveInOpen;
extern waveInPrepareHeaderType waveInPrepareHeader;
extern waveInResetType waveInReset;
extern waveInStartType waveInStart;
extern waveInStopType waveInStop;
extern waveInUnprepareHeaderType waveInUnprepareHeader;
extern waveOutBreakLoopType waveOutBreakLoop;
extern waveOutCloseType waveOutClose;
extern waveOutGetDevCapsAType waveOutGetDevCapsA;
extern waveOutGetDevCapsWType waveOutGetDevCapsW;
extern waveOutGetErrorTextAType waveOutGetErrorTextA;
extern waveOutGetErrorTextWType waveOutGetErrorTextW;
extern waveOutGetIDType waveOutGetID;
extern waveOutGetNumDevsType waveOutGetNumDevs;
extern waveOutGetPitchType waveOutGetPitch;
extern waveOutGetPlaybackRateType waveOutGetPlaybackRate;
extern waveOutGetPositionType waveOutGetPosition;
extern waveOutGetVolumeType waveOutGetVolume;
extern waveOutMessageType waveOutMessage;
extern waveOutOpenType waveOutOpen;
extern waveOutPauseType waveOutPause;
extern waveOutPrepareHeaderType waveOutPrepareHeader;
extern waveOutResetType waveOutReset;
extern waveOutRestartType waveOutRestart;
extern waveOutSetPitchType waveOutSetPitch;
extern waveOutSetPlaybackRateType waveOutSetPlaybackRate;
extern waveOutSetVolumeType waveOutSetVolume;
extern waveOutUnprepareHeaderType waveOutUnprepareHeader;
extern waveOutWriteType waveOutWrite;
extern PlaySoundStubType PlaySoundStub;
} // namespace geecore::detail::proxies
