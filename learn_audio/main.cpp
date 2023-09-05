//
// Created by Seedking on 2023/9/9.
//
#include "iostream"
#include "mmdeviceapi.h"
#include "Audioclient.h"
#include "Audiopolicy.h"
#include "Devicetopology.h"
#include "Endpointvolume.h"
#include "AudioSessionTypes.h"

int main() {
    void** pEnumerator;
    HRESULT hr;
    const CLSID CLSID_MMDeviceEnumerator = __uuidof(MMDeviceEnumerator);
    const IID IID_IMMDeviceEnumerator = __uuidof(IMMDeviceEnumerator);
    hr = CoCreateInstance(
         CLSID_MMDeviceEnumerator, NULL,
         CLSCTX_ALL, IID_IMMDeviceEnumerator,
         (void**)&pEnumerator);

    std::cout<<IID_IMMDeviceEnumerator.Data1<<std::endl;
    std::cout<<IID_IMMDeviceEnumerator.Data2;
    return 0;
}
