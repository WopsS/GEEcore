#include <geecore/detail/proxies/DxgiProxy.functions.hpp>

geecore::detail::proxies::ApplyCompatResolutionQuirkingType geecore::detail::proxies::ApplyCompatResolutionQuirking;
geecore::detail::proxies::CompatStringType geecore::detail::proxies::CompatString;
geecore::detail::proxies::CompatValueType geecore::detail::proxies::CompatValue;
geecore::detail::proxies::CreateDXGIFactoryType geecore::detail::proxies::CreateDXGIFactory;
geecore::detail::proxies::CreateDXGIFactory1Type geecore::detail::proxies::CreateDXGIFactory1;
geecore::detail::proxies::CreateDXGIFactory2Type geecore::detail::proxies::CreateDXGIFactory2;
geecore::detail::proxies::DXGID3D10CreateDeviceType geecore::detail::proxies::DXGID3D10CreateDevice;
geecore::detail::proxies::DXGID3D10CreateLayeredDeviceType geecore::detail::proxies::DXGID3D10CreateLayeredDevice;
geecore::detail::proxies::DXGID3D10GetLayeredDeviceSizeType geecore::detail::proxies::DXGID3D10GetLayeredDeviceSize;
geecore::detail::proxies::DXGID3D10RegisterLayersType geecore::detail::proxies::DXGID3D10RegisterLayers;
geecore::detail::proxies::DXGIDeclareAdapterRemovalSupportType
    geecore::detail::proxies::DXGIDeclareAdapterRemovalSupport;
geecore::detail::proxies::DXGIDumpJournalType geecore::detail::proxies::DXGIDumpJournal;
geecore::detail::proxies::DXGIGetDebugInterface1Type geecore::detail::proxies::DXGIGetDebugInterface1;
geecore::detail::proxies::DXGIReportAdapterConfigurationType geecore::detail::proxies::DXGIReportAdapterConfiguration;
geecore::detail::proxies::PIXBeginCaptureType geecore::detail::proxies::PIXBeginCapture;
geecore::detail::proxies::PIXEndCaptureType geecore::detail::proxies::PIXEndCapture;
geecore::detail::proxies::PIXGetCaptureStateType geecore::detail::proxies::PIXGetCaptureState;
geecore::detail::proxies::SetAppCompatStringPointerType geecore::detail::proxies::SetAppCompatStringPointer;
geecore::detail::proxies::UpdateHMDEmulationStatusType geecore::detail::proxies::UpdateHMDEmulationStatus;

void geecore_ApplyCompatResolutionQuirking()
{
    geecore::detail::proxies::ApplyCompatResolutionQuirking();
}

void geecore_CompatString()
{
    geecore::detail::proxies::CompatString();
}

void geecore_CompatValue()
{
    geecore::detail::proxies::CompatValue();
}

HRESULT WINAPI geecore_CreateDXGIFactory(REFIID riid, _COM_Outptr_ void** ppFactory)
{
    return geecore::detail::proxies::CreateDXGIFactory(riid, ppFactory);
}

HRESULT WINAPI geecore_CreateDXGIFactory1(REFIID riid, _COM_Outptr_ void** ppFactory)
{
    return geecore::detail::proxies::CreateDXGIFactory1(riid, ppFactory);
}

HRESULT WINAPI geecore_CreateDXGIFactory2(UINT Flags, REFIID riid, _COM_Outptr_ void** ppFactory)
{
    return geecore::detail::proxies::CreateDXGIFactory2(Flags, riid, ppFactory);
}

void geecore_DXGID3D10CreateDevice()
{
    geecore::detail::proxies::DXGID3D10CreateDevice();
}

void geecore_DXGID3D10CreateLayeredDevice()
{
    geecore::detail::proxies::DXGID3D10CreateLayeredDevice();
}

void geecore_DXGID3D10GetLayeredDeviceSize()
{
    geecore::detail::proxies::DXGID3D10GetLayeredDeviceSize();
}

void geecore_DXGID3D10RegisterLayers()
{
    geecore::detail::proxies::DXGID3D10RegisterLayers();
}

HRESULT WINAPI geecore_DXGIDeclareAdapterRemovalSupport()
{
    return geecore::detail::proxies::DXGIDeclareAdapterRemovalSupport();
}

void geecore_DXGIDumpJournal()
{
    geecore::detail::proxies::DXGIDumpJournal();
}

HRESULT WINAPI geecore_DXGIGetDebugInterface1(UINT Flags, REFIID riid, _COM_Outptr_ void** pDebug)
{
    return geecore::detail::proxies::DXGIGetDebugInterface1(Flags, riid, pDebug);
}

void geecore_DXGIReportAdapterConfiguration()
{
    geecore::detail::proxies::DXGIReportAdapterConfiguration();
}

void geecore_PIXBeginCapture()
{
    geecore::detail::proxies::PIXBeginCapture();
}

void geecore_PIXEndCapture()
{
    geecore::detail::proxies::PIXEndCapture();
}

void geecore_PIXGetCaptureState()
{
    geecore::detail::proxies::PIXGetCaptureState();
}

void geecore_SetAppCompatStringPointer()
{
    geecore::detail::proxies::SetAppCompatStringPointer();
}

void geecore_UpdateHMDEmulationStatus()
{
    geecore::detail::proxies::UpdateHMDEmulationStatus();
}
