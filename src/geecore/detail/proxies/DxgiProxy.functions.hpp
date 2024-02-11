#pragma once

#include <dxgi.h>
#include <dxgi1_6.h>

namespace geecore::detail::proxies
{
using ApplyCompatResolutionQuirkingType = void (*)();
using CompatStringType = void (*)();
using CompatValueType = void (*)();
using CreateDXGIFactoryType = decltype(&::CreateDXGIFactory);
using CreateDXGIFactory1Type = decltype(&::CreateDXGIFactory1);
using CreateDXGIFactory2Type = decltype(&::CreateDXGIFactory2);
using DXGID3D10CreateDeviceType = void (*)();
using DXGID3D10CreateLayeredDeviceType = void (*)();
using DXGID3D10GetLayeredDeviceSizeType = void (*)();
using DXGID3D10RegisterLayersType = void (*)();
using DXGIDeclareAdapterRemovalSupportType = decltype(&::DXGIDeclareAdapterRemovalSupport);
using DXGIDumpJournalType = void (*)();
using DXGIGetDebugInterface1Type = decltype(&::DXGIGetDebugInterface1);
using DXGIReportAdapterConfigurationType = void (*)();
using PIXBeginCaptureType = void (*)();
using PIXEndCaptureType = void (*)();
using PIXGetCaptureStateType = void (*)();
using SetAppCompatStringPointerType = void (*)();
using UpdateHMDEmulationStatusType = void (*)();

extern ApplyCompatResolutionQuirkingType ApplyCompatResolutionQuirking;
extern CompatStringType CompatString;
extern CompatValueType CompatValue;
extern CreateDXGIFactoryType CreateDXGIFactory;
extern CreateDXGIFactory1Type CreateDXGIFactory1;
extern CreateDXGIFactory2Type CreateDXGIFactory2;
extern DXGID3D10CreateDeviceType DXGID3D10CreateDevice;
extern DXGID3D10CreateLayeredDeviceType DXGID3D10CreateLayeredDevice;
extern DXGID3D10GetLayeredDeviceSizeType DXGID3D10GetLayeredDeviceSize;
extern DXGID3D10RegisterLayersType DXGID3D10RegisterLayers;
extern DXGIDeclareAdapterRemovalSupportType DXGIDeclareAdapterRemovalSupport;
extern DXGIDumpJournalType DXGIDumpJournal;
extern DXGIGetDebugInterface1Type DXGIGetDebugInterface1;
extern DXGIReportAdapterConfigurationType DXGIReportAdapterConfiguration;
extern PIXBeginCaptureType PIXBeginCapture;
extern PIXEndCaptureType PIXEndCapture;
extern PIXGetCaptureStateType PIXGetCaptureState;
extern SetAppCompatStringPointerType SetAppCompatStringPointer;
extern UpdateHMDEmulationStatusType UpdateHMDEmulationStatus;
} // namespace geecore::detail::proxies
