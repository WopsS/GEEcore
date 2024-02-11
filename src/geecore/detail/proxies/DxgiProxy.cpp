#include <geecore/detail/proxies/DxgiProxy.hpp>

#include <geecore/detail/proxies/DxgiProxy.functions.hpp>

std::wstring_view geecore::detail::DxgiProxy::name() const
{
    return L"dxgi";
}

void geecore::detail::DxgiProxy::resolve_exports() const
{
    proxies::ApplyCompatResolutionQuirking =
        get_proc_address<proxies::ApplyCompatResolutionQuirkingType>("ApplyCompatResolutionQuirking");
    proxies::CompatString = get_proc_address<proxies::CompatStringType>("CompatString");
    proxies::CompatValue = get_proc_address<proxies::CompatValueType>("CompatValue");
    proxies::CreateDXGIFactory = get_proc_address<proxies::CreateDXGIFactoryType>("CreateDXGIFactory");
    proxies::CreateDXGIFactory1 = get_proc_address<proxies::CreateDXGIFactory1Type>("CreateDXGIFactory1");
    proxies::CreateDXGIFactory2 = get_proc_address<proxies::CreateDXGIFactory2Type>("CreateDXGIFactory2");
    proxies::DXGID3D10CreateDevice = get_proc_address<proxies::DXGID3D10CreateDeviceType>("DXGID3D10CreateDevice");
    proxies::DXGID3D10CreateLayeredDevice =
        get_proc_address<proxies::DXGID3D10CreateLayeredDeviceType>("DXGID3D10CreateLayeredDevice");
    proxies::DXGID3D10GetLayeredDeviceSize =
        get_proc_address<proxies::DXGID3D10GetLayeredDeviceSizeType>("DXGID3D10GetLayeredDeviceSize");
    proxies::DXGID3D10RegisterLayers =
        get_proc_address<proxies::DXGID3D10RegisterLayersType>("DXGID3D10RegisterLayers");
    proxies::DXGIDeclareAdapterRemovalSupport =
        get_proc_address<proxies::DXGIDeclareAdapterRemovalSupportType>("DXGIDeclareAdapterRemovalSupport");
    proxies::DXGIDumpJournal = get_proc_address<proxies::DXGIDumpJournalType>("DXGIDumpJournal");
    proxies::DXGIGetDebugInterface1 = get_proc_address<proxies::DXGIGetDebugInterface1Type>("DXGIGetDebugInterface1");
    proxies::DXGIReportAdapterConfiguration =
        get_proc_address<proxies::DXGIReportAdapterConfigurationType>("DXGIReportAdapterConfiguration");
    proxies::PIXBeginCapture = get_proc_address<proxies::PIXBeginCaptureType>("PIXBeginCapture");
    proxies::PIXEndCapture = get_proc_address<proxies::PIXEndCaptureType>("PIXEndCapture");
    proxies::PIXGetCaptureState = get_proc_address<proxies::PIXGetCaptureStateType>("PIXGetCaptureState");
    proxies::SetAppCompatStringPointer =
        get_proc_address<proxies::SetAppCompatStringPointerType>("SetAppCompatStringPointer");
    proxies::UpdateHMDEmulationStatus =
        get_proc_address<proxies::UpdateHMDEmulationStatusType>("UpdateHMDEmulationStatus");
}

void geecore::detail::DxgiProxy::clear_resolved_exports() const
{
    proxies::ApplyCompatResolutionQuirking = nullptr;
    proxies::CompatString = nullptr;
    proxies::CompatValue = nullptr;
    proxies::CreateDXGIFactory = nullptr;
    proxies::CreateDXGIFactory1 = nullptr;
    proxies::CreateDXGIFactory2 = nullptr;
    proxies::DXGID3D10CreateDevice = nullptr;
    proxies::DXGID3D10CreateLayeredDevice = nullptr;
    proxies::DXGID3D10GetLayeredDeviceSize = nullptr;
    proxies::DXGID3D10RegisterLayers = nullptr;
    proxies::DXGIDeclareAdapterRemovalSupport = nullptr;
    proxies::DXGIDumpJournal = nullptr;
    proxies::DXGIGetDebugInterface1 = nullptr;
    proxies::DXGIReportAdapterConfiguration = nullptr;
    proxies::PIXBeginCapture = nullptr;
    proxies::PIXEndCapture = nullptr;
    proxies::PIXGetCaptureState = nullptr;
    proxies::SetAppCompatStringPointer = nullptr;
    proxies::UpdateHMDEmulationStatus = nullptr;
}
