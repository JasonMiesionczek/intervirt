
#ifndef COMMON_WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_H
#define COMMON_WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_H

#include <common/util.h>
#include <drivers/hyperv/wmi/AbstractWmiObject.h>

namespace Drivers {
namespace Hyperv {
namespace Wmi {
namespace Classes {
namespace Common {
typedef struct _Win32_PerfRawData_HvStats_HyperVHypervisorVirtualProcessor_Data {
    XML_TYPE_UINT64 AddressDomainFlushesPersec;
    XML_TYPE_UINT64 AddressSpaceEvictionsPersec;
    XML_TYPE_UINT64 AddressSpaceFlushesPersec;
    XML_TYPE_UINT64 AddressSpaceSwitchesPersec;
    XML_TYPE_UINT64 APICEOIAccessesPersec;
    XML_TYPE_UINT64 APICIPIsSentPersec;
    XML_TYPE_UINT64 APICMMIOAccessesPersec;
    XML_TYPE_UINT64 APICSelfIPIsSentPersec;
    XML_TYPE_UINT64 APICTPRAccessesPersec;
    XML_TYPE_STR Caption;
    XML_TYPE_UINT64 ControlRegisterAccessesCost;
    XML_TYPE_UINT64 ControlRegisterAccessesCost_Base;
    XML_TYPE_UINT64 ControlRegisterAccessesPersec;
    XML_TYPE_UINT64 CPUIDInstructionsCost;
    XML_TYPE_UINT64 CPUIDInstructionsCost_Base;
    XML_TYPE_UINT64 CPUIDInstructionsPersec;
    XML_TYPE_UINT64 CPUWaitTimePerDispatch;
    XML_TYPE_UINT64 CPUWaitTimePerDispatch_Base;
    XML_TYPE_UINT64 DebugRegisterAccessesCost;
    XML_TYPE_UINT64 DebugRegisterAccessesCost_Base;
    XML_TYPE_UINT64 DebugRegisterAccessesPersec;
    XML_TYPE_STR Description;
    XML_TYPE_UINT64 EmulatedInstructionsCost;
    XML_TYPE_UINT64 EmulatedInstructionsCost_Base;
    XML_TYPE_UINT64 EmulatedInstructionsPersec;
    XML_TYPE_UINT64 ExternalInterruptsCost;
    XML_TYPE_UINT64 ExternalInterruptsCost_Base;
    XML_TYPE_UINT64 ExternalInterruptsPersec;
    XML_TYPE_UINT64 Frequency_Object;
    XML_TYPE_UINT64 Frequency_PerfTime;
    XML_TYPE_UINT64 Frequency_Sys100NS;
    XML_TYPE_UINT64 GlobalGVARangeFlushesPersec;
    XML_TYPE_UINT64 GPASpaceHypercallsPersec;
    XML_TYPE_UINT64 GuestPageTableMapsPersec;
    XML_TYPE_UINT64 HardwareInterruptsPersec;
    XML_TYPE_UINT64 HLTInstructionsCost;
    XML_TYPE_UINT64 HLTInstructionsCost_Base;
    XML_TYPE_UINT64 HLTInstructionsPersec;
    XML_TYPE_UINT64 HypercallsCost;
    XML_TYPE_UINT64 HypercallsCost_Base;
    XML_TYPE_UINT64 HypercallsPersec;
    XML_TYPE_UINT64 IOInstructionsCost;
    XML_TYPE_UINT64 IOInstructionsCost_Base;
    XML_TYPE_UINT64 IOInstructionsPersec;
    XML_TYPE_UINT64 IOInterceptMessagesPersec;
    XML_TYPE_UINT64 LargePageTLBFillsPersec;
    XML_TYPE_UINT64 LocalFlushedGVARangesPersec;
    XML_TYPE_UINT64 LogicalProcessorDispatchesPersec;
    XML_TYPE_UINT64 LogicalProcessorHypercallsPersec;
    XML_TYPE_UINT64 LogicalProcessorMigrationsPersec;
    XML_TYPE_UINT64 LongSpinWaitHypercallsPersec;
    XML_TYPE_UINT64 MemoryInterceptMessagesPersec;
    XML_TYPE_UINT64 MSRAccessesCost;
    XML_TYPE_UINT64 MSRAccessesCost_Base;
    XML_TYPE_UINT64 MSRAccessesPersec;
    XML_TYPE_UINT64 MWAITInstructionsCost;
    XML_TYPE_UINT64 MWAITInstructionsCost_Base;
    XML_TYPE_UINT64 MWAITInstructionsPersec;
    XML_TYPE_STR Name;
    XML_TYPE_UINT64 NestedPageFaultInterceptsCost;
    XML_TYPE_UINT64 NestedPageFaultInterceptsCost_Base;
    XML_TYPE_UINT64 NestedPageFaultInterceptsPersec;
    XML_TYPE_UINT64 OtherHypercallsPersec;
    XML_TYPE_UINT64 OtherInterceptsCost;
    XML_TYPE_UINT64 OtherInterceptsCost_Base;
    XML_TYPE_UINT64 OtherInterceptsPersec;
    XML_TYPE_UINT64 OtherMessagesPersec;
    XML_TYPE_UINT64 PageFaultInterceptsCost;
    XML_TYPE_UINT64 PageFaultInterceptsCost_Base;
    XML_TYPE_UINT64 PageFaultInterceptsPersec;
    XML_TYPE_UINT64 PageInvalidationsCost;
    XML_TYPE_UINT64 PageInvalidationsCost_Base;
    XML_TYPE_UINT64 PageInvalidationsPersec;
    XML_TYPE_UINT64 PageTableAllocationsPersec;
    XML_TYPE_UINT64 PageTableEvictionsPersec;
    XML_TYPE_UINT64 PageTableReclamationsPersec;
    XML_TYPE_UINT64 PageTableResetsPersec;
    XML_TYPE_UINT64 PageTableValidationsPersec;
    XML_TYPE_UINT64 PageTableWriteInterceptsPersec;
    XML_TYPE_UINT64 PendingInterruptsCost;
    XML_TYPE_UINT64 PendingInterruptsCost_Base;
    XML_TYPE_UINT64 PendingInterruptsPersec;
    XML_TYPE_UINT64 PercentGuestRunTime;
    XML_TYPE_UINT64 PercentGuestRunTime_Base;
    XML_TYPE_UINT64 PercentHypervisorRunTime;
    XML_TYPE_UINT64 PercentHypervisorRunTime_Base;
    XML_TYPE_UINT64 PercentRemoteRunTime;
    XML_TYPE_UINT64 PercentRemoteRunTime_Base;
    XML_TYPE_UINT64 PercentTotalRunTime;
    XML_TYPE_UINT64 PercentTotalRunTime_Base;
    XML_TYPE_UINT64 ReflectedGuestPageFaultsPersec;
    XML_TYPE_UINT64 SmallPageTLBFillsPersec;
    XML_TYPE_UINT64 SyntheticInterruptHypercallsPersec;
    XML_TYPE_UINT64 SyntheticInterruptsPersec;
    XML_TYPE_UINT64 Timestamp_Object;
    XML_TYPE_UINT64 Timestamp_PerfTime;
    XML_TYPE_UINT64 Timestamp_Sys100NS;
    XML_TYPE_UINT64 TotalInterceptsCost;
    XML_TYPE_UINT64 TotalInterceptsCost_Base;
    XML_TYPE_UINT64 TotalInterceptsPersec;
    XML_TYPE_UINT64 TotalMessagesPersec;
    XML_TYPE_UINT64 VirtualInterruptHypercallsPersec;
    XML_TYPE_UINT64 VirtualInterruptsPersec;
    XML_TYPE_UINT64 VirtualMMUHypercallsPersec;
    XML_TYPE_UINT64 VirtualProcessorHypercallsPersec;

} Win32_PerfRawData_HvStats_HyperVHypervisorVirtualProcessor_Data;
SER_DECLARE_TYPE(Win32_PerfRawData_HvStats_HyperVHypervisorVirtualProcessor_Data);
typedef struct _Win32_PerfRawData_HvStats_HyperVHypervisorVirtualProcessor {
    XmlSerializerInfo *serializerInfo;
    Win32_PerfRawData_HvStats_HyperVHypervisorVirtualProcessor_Data *data;
} Win32_PerfRawData_HvStats_HyperVHypervisorVirtualProcessor;

#define WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI \
    "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/cimv2/Win32_PerfRawData_HvStats_HyperVHypervisorVirtualProcessor"

#define WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_CLASSNAME \
    "Win32_PerfRawData_HvStats_HyperVHypervisorVirtualProcessor"

#define WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_WQL_SELECT \
    "select * from Win32_PerfRawData_HvStats_HyperVHypervisorVirtualProcessor "

class Win32PerfRawDataHvStatsHyperVHypervisorVirtualProcessor : public AbstractWmiObject
{
public:
  Win32PerfRawDataHvStatsHyperVHypervisorVirtualProcessor();
};
}
}
}
}
}
#endif /* COMMON_WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_H */

