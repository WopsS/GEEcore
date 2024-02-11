#include <geecore/detail/proxies/D3d11Proxy.hpp>

#include <geecore/detail/proxies/D3d11Proxy.functions.hpp>

std::wstring_view geecore::detail::D3d11Proxy::name() const
{
    return L"d3d11";
}

void geecore::detail::D3d11Proxy::resolve_exports() const
{
    proxies::CreateDirect3D11DeviceFromDXGIDevice =
        get_proc_address<proxies::CreateDirect3D11DeviceFromDXGIDeviceType>("CreateDirect3D11DeviceFromDXGIDevice");
    proxies::CreateDirect3D11SurfaceFromDXGISurface =
        get_proc_address<proxies::CreateDirect3D11SurfaceFromDXGISurfaceType>("CreateDirect3D11SurfaceFromDXGISurface");
    proxies::D3D11CoreCreateDevice = get_proc_address<proxies::D3D11CoreCreateDeviceType>("D3D11CoreCreateDevice");
    proxies::D3D11CoreCreateLayeredDevice =
        get_proc_address<proxies::D3D11CoreCreateLayeredDeviceType>("D3D11CoreCreateLayeredDevice");
    proxies::D3D11CoreGetLayeredDeviceSize =
        get_proc_address<proxies::D3D11CoreGetLayeredDeviceSizeType>("D3D11CoreGetLayeredDeviceSize");
    proxies::D3D11CoreRegisterLayers =
        get_proc_address<proxies::D3D11CoreRegisterLayersType>("D3D11CoreRegisterLayers");
    proxies::D3D11CreateDevice = get_proc_address<proxies::D3D11CreateDeviceType>("D3D11CreateDevice");
    proxies::D3D11CreateDeviceAndSwapChain =
        get_proc_address<proxies::D3D11CreateDeviceAndSwapChainType>("D3D11CreateDeviceAndSwapChain");
    proxies::D3D11CreateDeviceForD3D12 =
        get_proc_address<proxies::D3D11CreateDeviceForD3D12Type>("D3D11CreateDeviceForD3D12");
    proxies::D3D11On12CreateDevice = get_proc_address<proxies::D3D11On12CreateDeviceType>("D3D11On12CreateDevice");
    proxies::D3DKMTCloseAdapter = get_proc_address<proxies::D3DKMTCloseAdapterType>("D3DKMTCloseAdapter");
    proxies::D3DKMTCreateAllocation = get_proc_address<proxies::D3DKMTCreateAllocationType>("D3DKMTCreateAllocation");
    proxies::D3DKMTCreateContext = get_proc_address<proxies::D3DKMTCreateContextType>("D3DKMTCreateContext");
    proxies::D3DKMTCreateDevice = get_proc_address<proxies::D3DKMTCreateDeviceType>("D3DKMTCreateDevice");
    proxies::D3DKMTCreateSynchronizationObject =
        get_proc_address<proxies::D3DKMTCreateSynchronizationObjectType>("D3DKMTCreateSynchronizationObject");
    proxies::D3DKMTDestroyAllocation =
        get_proc_address<proxies::D3DKMTDestroyAllocationType>("D3DKMTDestroyAllocation");
    proxies::D3DKMTDestroyContext = get_proc_address<proxies::D3DKMTDestroyContextType>("D3DKMTDestroyContext");
    proxies::D3DKMTDestroyDevice = get_proc_address<proxies::D3DKMTDestroyDeviceType>("D3DKMTDestroyDevice");
    proxies::D3DKMTDestroySynchronizationObject =
        get_proc_address<proxies::D3DKMTDestroySynchronizationObjectType>("D3DKMTDestroySynchronizationObject");
    proxies::D3DKMTEscape = get_proc_address<proxies::D3DKMTEscapeType>("D3DKMTEscape");
    proxies::D3DKMTGetContextSchedulingPriority =
        get_proc_address<proxies::D3DKMTGetContextSchedulingPriorityType>("D3DKMTGetContextSchedulingPriority");
    proxies::D3DKMTGetDeviceState = get_proc_address<proxies::D3DKMTGetDeviceStateType>("D3DKMTGetDeviceState");
    proxies::D3DKMTGetDisplayModeList =
        get_proc_address<proxies::D3DKMTGetDisplayModeListType>("D3DKMTGetDisplayModeList");
    proxies::D3DKMTGetMultisampleMethodList =
        get_proc_address<proxies::D3DKMTGetMultisampleMethodListType>("D3DKMTGetMultisampleMethodList");
    proxies::D3DKMTGetRuntimeData = get_proc_address<proxies::D3DKMTGetRuntimeDataType>("D3DKMTGetRuntimeData");
    proxies::D3DKMTGetSharedPrimaryHandle =
        get_proc_address<proxies::D3DKMTGetSharedPrimaryHandleType>("D3DKMTGetSharedPrimaryHandle");
    proxies::D3DKMTLock = get_proc_address<proxies::D3DKMTLockType>("D3DKMTLock");
    proxies::D3DKMTOpenAdapterFromHdc =
        get_proc_address<proxies::D3DKMTOpenAdapterFromHdcType>("D3DKMTOpenAdapterFromHdc");
    proxies::D3DKMTOpenResource = get_proc_address<proxies::D3DKMTOpenResourceType>("D3DKMTOpenResource");
    proxies::D3DKMTPresent = get_proc_address<proxies::D3DKMTPresentType>("D3DKMTPresent");
    proxies::D3DKMTQueryAdapterInfo = get_proc_address<proxies::D3DKMTQueryAdapterInfoType>("D3DKMTQueryAdapterInfo");
    proxies::D3DKMTQueryAllocationResidency =
        get_proc_address<proxies::D3DKMTQueryAllocationResidencyType>("D3DKMTQueryAllocationResidency");
    proxies::D3DKMTQueryResourceInfo =
        get_proc_address<proxies::D3DKMTQueryResourceInfoType>("D3DKMTQueryResourceInfo");
    proxies::D3DKMTRender = get_proc_address<proxies::D3DKMTRenderType>("D3DKMTRender");
    proxies::D3DKMTSetAllocationPriority =
        get_proc_address<proxies::D3DKMTSetAllocationPriorityType>("D3DKMTSetAllocationPriority");
    proxies::D3DKMTSetContextSchedulingPriority =
        get_proc_address<proxies::D3DKMTSetContextSchedulingPriorityType>("D3DKMTSetContextSchedulingPriority");
    proxies::D3DKMTSetDisplayMode = get_proc_address<proxies::D3DKMTSetDisplayModeType>("D3DKMTSetDisplayMode");
    proxies::D3DKMTSetDisplayPrivateDriverFormat =
        get_proc_address<proxies::D3DKMTSetDisplayPrivateDriverFormatType>("D3DKMTSetDisplayPrivateDriverFormat");
    proxies::D3DKMTSetGammaRamp = get_proc_address<proxies::D3DKMTSetGammaRampType>("D3DKMTSetGammaRamp");
    proxies::D3DKMTSetVidPnSourceOwner =
        get_proc_address<proxies::D3DKMTSetVidPnSourceOwnerType>("D3DKMTSetVidPnSourceOwner");
    proxies::D3DKMTSignalSynchronizationObject =
        get_proc_address<proxies::D3DKMTSignalSynchronizationObjectType>("D3DKMTSignalSynchronizationObject");
    proxies::D3DKMTUnlock = get_proc_address<proxies::D3DKMTUnlockType>("D3DKMTUnlock");
    proxies::D3DKMTWaitForSynchronizationObject =
        get_proc_address<proxies::D3DKMTWaitForSynchronizationObjectType>("D3DKMTWaitForSynchronizationObject");
    proxies::D3DKMTWaitForVerticalBlankEvent =
        get_proc_address<proxies::D3DKMTWaitForVerticalBlankEventType>("D3DKMTWaitForVerticalBlankEvent");
    proxies::D3DPerformance_BeginEvent =
        get_proc_address<proxies::D3DPerformance_BeginEventType>("D3DPerformance_BeginEvent");
    proxies::D3DPerformance_EndEvent =
        get_proc_address<proxies::D3DPerformance_EndEventType>("D3DPerformance_EndEvent");
    proxies::D3DPerformance_GetStatus =
        get_proc_address<proxies::D3DPerformance_GetStatusType>("D3DPerformance_GetStatus");
    proxies::D3DPerformance_SetMarker =
        get_proc_address<proxies::D3DPerformance_SetMarkerType>("D3DPerformance_SetMarker");
    proxies::EnableFeatureLevelUpgrade =
        get_proc_address<proxies::EnableFeatureLevelUpgradeType>("EnableFeatureLevelUpgrade");
    proxies::OpenAdapter10 = get_proc_address<proxies::OpenAdapter10Type>("OpenAdapter10");
    proxies::OpenAdapter10_2 = get_proc_address<proxies::OpenAdapter10_2Type>("OpenAdapter10_2");
}

void geecore::detail::D3d11Proxy::clear_resolved_exports() const
{
    proxies::CreateDirect3D11DeviceFromDXGIDevice = nullptr;
    proxies::CreateDirect3D11SurfaceFromDXGISurface = nullptr;
    proxies::D3D11CoreCreateDevice = nullptr;
    proxies::D3D11CoreCreateLayeredDevice = nullptr;
    proxies::D3D11CoreGetLayeredDeviceSize = nullptr;
    proxies::D3D11CoreRegisterLayers = nullptr;
    proxies::D3D11CreateDevice = nullptr;
    proxies::D3D11CreateDeviceAndSwapChain = nullptr;
    proxies::D3D11CreateDeviceForD3D12 = nullptr;
    proxies::D3D11On12CreateDevice = nullptr;
    proxies::D3DKMTCloseAdapter = nullptr;
    proxies::D3DKMTCreateAllocation = nullptr;
    proxies::D3DKMTCreateContext = nullptr;
    proxies::D3DKMTCreateDevice = nullptr;
    proxies::D3DKMTCreateSynchronizationObject = nullptr;
    proxies::D3DKMTDestroyAllocation = nullptr;
    proxies::D3DKMTDestroyContext = nullptr;
    proxies::D3DKMTDestroyDevice = nullptr;
    proxies::D3DKMTDestroySynchronizationObject = nullptr;
    proxies::D3DKMTEscape = nullptr;
    proxies::D3DKMTGetContextSchedulingPriority = nullptr;
    proxies::D3DKMTGetDeviceState = nullptr;
    proxies::D3DKMTGetDisplayModeList = nullptr;
    proxies::D3DKMTGetMultisampleMethodList = nullptr;
    proxies::D3DKMTGetRuntimeData = nullptr;
    proxies::D3DKMTGetSharedPrimaryHandle = nullptr;
    proxies::D3DKMTLock = nullptr;
    proxies::D3DKMTOpenAdapterFromHdc = nullptr;
    proxies::D3DKMTOpenResource = nullptr;
    proxies::D3DKMTPresent = nullptr;
    proxies::D3DKMTQueryAdapterInfo = nullptr;
    proxies::D3DKMTQueryAllocationResidency = nullptr;
    proxies::D3DKMTQueryResourceInfo = nullptr;
    proxies::D3DKMTRender = nullptr;
    proxies::D3DKMTSetAllocationPriority = nullptr;
    proxies::D3DKMTSetContextSchedulingPriority = nullptr;
    proxies::D3DKMTSetDisplayMode = nullptr;
    proxies::D3DKMTSetDisplayPrivateDriverFormat = nullptr;
    proxies::D3DKMTSetGammaRamp = nullptr;
    proxies::D3DKMTSetVidPnSourceOwner = nullptr;
    proxies::D3DKMTSignalSynchronizationObject = nullptr;
    proxies::D3DKMTUnlock = nullptr;
    proxies::D3DKMTWaitForSynchronizationObject = nullptr;
    proxies::D3DKMTWaitForVerticalBlankEvent = nullptr;
    proxies::D3DPerformance_BeginEvent = nullptr;
    proxies::D3DPerformance_EndEvent = nullptr;
    proxies::D3DPerformance_GetStatus = nullptr;
    proxies::D3DPerformance_SetMarker = nullptr;
    proxies::EnableFeatureLevelUpgrade = nullptr;
    proxies::OpenAdapter10 = nullptr;
    proxies::OpenAdapter10_2 = nullptr;
}
