#pragma once

#include <d3d11.h>
#include <d3d11on12.h>
#include <d3d12.h>
#include <d3d9.h>
#include <d3dkmthk.h>
#include <windows.graphics.directx.direct3d11.interop.h>

namespace geecore::detail::proxies
{
using CreateDirect3D11DeviceFromDXGIDeviceType = decltype(&::CreateDirect3D11DeviceFromDXGIDevice);
using CreateDirect3D11SurfaceFromDXGISurfaceType = decltype(&::CreateDirect3D11SurfaceFromDXGISurface);
using D3D11CoreCreateDeviceType = void (*)();
using D3D11CoreCreateLayeredDeviceType = void (*)();
using D3D11CoreGetLayeredDeviceSizeType = void (*)();
using D3D11CoreRegisterLayersType = void (*)();
using D3D11CreateDeviceType = decltype(&::D3D11CreateDevice);
using D3D11CreateDeviceAndSwapChainType = decltype(&::D3D11CreateDeviceAndSwapChain);
using D3D11CreateDeviceForD3D12Type = void (*)();
using D3D11On12CreateDeviceType = decltype(&::D3D11On12CreateDevice);
using D3DKMTCloseAdapterType = decltype(&::D3DKMTCloseAdapter);
using D3DKMTCreateAllocationType = decltype(&::D3DKMTCreateAllocation);
using D3DKMTCreateContextType = decltype(&::D3DKMTCreateContext);
using D3DKMTCreateDeviceType = decltype(&::D3DKMTCreateDevice);
using D3DKMTCreateSynchronizationObjectType = decltype(&::D3DKMTCreateSynchronizationObject);
using D3DKMTDestroyAllocationType = decltype(&::D3DKMTDestroyAllocation);
using D3DKMTDestroyContextType = decltype(&::D3DKMTDestroyContext);
using D3DKMTDestroyDeviceType = decltype(&::D3DKMTDestroyDevice);
using D3DKMTDestroySynchronizationObjectType = decltype(&::D3DKMTDestroySynchronizationObject);
using D3DKMTEscapeType = decltype(&::D3DKMTEscape);
using D3DKMTGetContextSchedulingPriorityType = decltype(&::D3DKMTGetContextSchedulingPriority);
using D3DKMTGetDeviceStateType = decltype(&::D3DKMTGetDeviceState);
using D3DKMTGetDisplayModeListType = decltype(&::D3DKMTGetDisplayModeList);
using D3DKMTGetMultisampleMethodListType = decltype(&::D3DKMTGetMultisampleMethodList);
using D3DKMTGetRuntimeDataType = decltype(&::D3DKMTGetRuntimeData);
using D3DKMTGetSharedPrimaryHandleType = decltype(&::D3DKMTGetSharedPrimaryHandle);
using D3DKMTLockType = decltype(&::D3DKMTLock);
using D3DKMTOpenAdapterFromHdcType = decltype(&::D3DKMTOpenAdapterFromHdc);
using D3DKMTOpenResourceType = decltype(&::D3DKMTOpenResource);
using D3DKMTPresentType = decltype(&::D3DKMTPresent);
using D3DKMTQueryAdapterInfoType = decltype(&::D3DKMTQueryAdapterInfo);
using D3DKMTQueryAllocationResidencyType = decltype(&::D3DKMTQueryAllocationResidency);
using D3DKMTQueryResourceInfoType = decltype(&::D3DKMTQueryResourceInfo);
using D3DKMTRenderType = decltype(&::D3DKMTRender);
using D3DKMTSetAllocationPriorityType = decltype(&::D3DKMTSetAllocationPriority);
using D3DKMTSetContextSchedulingPriorityType = decltype(&::D3DKMTSetContextSchedulingPriority);
using D3DKMTSetDisplayModeType = decltype(&::D3DKMTSetDisplayMode);
using D3DKMTSetDisplayPrivateDriverFormatType = decltype(&::D3DKMTSetDisplayPrivateDriverFormat);
using D3DKMTSetGammaRampType = decltype(&::D3DKMTSetGammaRamp);
using D3DKMTSetVidPnSourceOwnerType = decltype(&::D3DKMTSetVidPnSourceOwner);
using D3DKMTSignalSynchronizationObjectType = decltype(&::D3DKMTSignalSynchronizationObject);
using D3DKMTUnlockType = decltype(&::D3DKMTUnlock);
using D3DKMTWaitForSynchronizationObjectType = decltype(&::D3DKMTWaitForSynchronizationObject);
using D3DKMTWaitForVerticalBlankEventType = decltype(&::D3DKMTWaitForVerticalBlankEvent);
using D3DPerformance_BeginEventType = void (*)();
using D3DPerformance_EndEventType = void (*)();
using D3DPerformance_GetStatusType = void (*)();
using D3DPerformance_SetMarkerType = void (*)();
using EnableFeatureLevelUpgradeType = void (*)();
using OpenAdapter10Type = void (*)();
using OpenAdapter10_2Type = void (*)();

extern CreateDirect3D11DeviceFromDXGIDeviceType CreateDirect3D11DeviceFromDXGIDevice;
extern CreateDirect3D11SurfaceFromDXGISurfaceType CreateDirect3D11SurfaceFromDXGISurface;
extern D3D11CoreCreateDeviceType D3D11CoreCreateDevice;
extern D3D11CoreCreateLayeredDeviceType D3D11CoreCreateLayeredDevice;
extern D3D11CoreGetLayeredDeviceSizeType D3D11CoreGetLayeredDeviceSize;
extern D3D11CoreRegisterLayersType D3D11CoreRegisterLayers;
extern D3D11CreateDeviceType D3D11CreateDevice;
extern D3D11CreateDeviceAndSwapChainType D3D11CreateDeviceAndSwapChain;
extern D3D11CreateDeviceForD3D12Type D3D11CreateDeviceForD3D12;
extern D3D11On12CreateDeviceType D3D11On12CreateDevice;
extern D3DKMTCloseAdapterType D3DKMTCloseAdapter;
extern D3DKMTCreateAllocationType D3DKMTCreateAllocation;
extern D3DKMTCreateContextType D3DKMTCreateContext;
extern D3DKMTCreateDeviceType D3DKMTCreateDevice;
extern D3DKMTCreateSynchronizationObjectType D3DKMTCreateSynchronizationObject;
extern D3DKMTDestroyAllocationType D3DKMTDestroyAllocation;
extern D3DKMTDestroyContextType D3DKMTDestroyContext;
extern D3DKMTDestroyDeviceType D3DKMTDestroyDevice;
extern D3DKMTDestroySynchronizationObjectType D3DKMTDestroySynchronizationObject;
extern D3DKMTEscapeType D3DKMTEscape;
extern D3DKMTGetContextSchedulingPriorityType D3DKMTGetContextSchedulingPriority;
extern D3DKMTGetDeviceStateType D3DKMTGetDeviceState;
extern D3DKMTGetDisplayModeListType D3DKMTGetDisplayModeList;
extern D3DKMTGetMultisampleMethodListType D3DKMTGetMultisampleMethodList;
extern D3DKMTGetRuntimeDataType D3DKMTGetRuntimeData;
extern D3DKMTGetSharedPrimaryHandleType D3DKMTGetSharedPrimaryHandle;
extern D3DKMTLockType D3DKMTLock;
extern D3DKMTOpenAdapterFromHdcType D3DKMTOpenAdapterFromHdc;
extern D3DKMTOpenResourceType D3DKMTOpenResource;
extern D3DKMTPresentType D3DKMTPresent;
extern D3DKMTQueryAdapterInfoType D3DKMTQueryAdapterInfo;
extern D3DKMTQueryAllocationResidencyType D3DKMTQueryAllocationResidency;
extern D3DKMTQueryResourceInfoType D3DKMTQueryResourceInfo;
extern D3DKMTRenderType D3DKMTRender;
extern D3DKMTSetAllocationPriorityType D3DKMTSetAllocationPriority;
extern D3DKMTSetContextSchedulingPriorityType D3DKMTSetContextSchedulingPriority;
extern D3DKMTSetDisplayModeType D3DKMTSetDisplayMode;
extern D3DKMTSetDisplayPrivateDriverFormatType D3DKMTSetDisplayPrivateDriverFormat;
extern D3DKMTSetGammaRampType D3DKMTSetGammaRamp;
extern D3DKMTSetVidPnSourceOwnerType D3DKMTSetVidPnSourceOwner;
extern D3DKMTSignalSynchronizationObjectType D3DKMTSignalSynchronizationObject;
extern D3DKMTUnlockType D3DKMTUnlock;
extern D3DKMTWaitForSynchronizationObjectType D3DKMTWaitForSynchronizationObject;
extern D3DKMTWaitForVerticalBlankEventType D3DKMTWaitForVerticalBlankEvent;
extern D3DPerformance_BeginEventType D3DPerformance_BeginEvent;
extern D3DPerformance_EndEventType D3DPerformance_EndEvent;
extern D3DPerformance_GetStatusType D3DPerformance_GetStatus;
extern D3DPerformance_SetMarkerType D3DPerformance_SetMarker;
extern EnableFeatureLevelUpgradeType EnableFeatureLevelUpgrade;
extern OpenAdapter10Type OpenAdapter10;
extern OpenAdapter10_2Type OpenAdapter10_2;
} // namespace geecore::detail::proxies
