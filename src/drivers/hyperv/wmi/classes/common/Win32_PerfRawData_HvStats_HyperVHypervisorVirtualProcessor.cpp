
#include "Win32_PerfRawData_HvStats_HyperVHypervisorVirtualProcessor.h"

namespace Drivers {
namespace Hyperv {
namespace Wmi {
namespace Classes {
namespace Common {


SER_START_ITEMS(Win32_PerfRawData_HvStats_HyperVHypervisorVirtualProcessor_Data)
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "AddressDomainFlushesPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "AddressSpaceEvictionsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "AddressSpaceFlushesPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "AddressSpaceSwitchesPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "APICEOIAccessesPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "APICIPIsSentPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "APICMMIOAccessesPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "APICSelfIPIsSentPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "APICTPRAccessesPersec", 1),
    SER_NS_STR(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "Caption", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "ControlRegisterAccessesCost", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "ControlRegisterAccessesCost_Base", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "ControlRegisterAccessesPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "CPUIDInstructionsCost", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "CPUIDInstructionsCost_Base", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "CPUIDInstructionsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "CPUWaitTimePerDispatch", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "CPUWaitTimePerDispatch_Base", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "DebugRegisterAccessesCost", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "DebugRegisterAccessesCost_Base", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "DebugRegisterAccessesPersec", 1),
    SER_NS_STR(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "Description", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "EmulatedInstructionsCost", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "EmulatedInstructionsCost_Base", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "EmulatedInstructionsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "ExternalInterruptsCost", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "ExternalInterruptsCost_Base", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "ExternalInterruptsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "Frequency_Object", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "Frequency_PerfTime", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "Frequency_Sys100NS", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "GlobalGVARangeFlushesPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "GPASpaceHypercallsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "GuestPageTableMapsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "HardwareInterruptsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "HLTInstructionsCost", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "HLTInstructionsCost_Base", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "HLTInstructionsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "HypercallsCost", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "HypercallsCost_Base", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "HypercallsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "IOInstructionsCost", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "IOInstructionsCost_Base", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "IOInstructionsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "IOInterceptMessagesPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "LargePageTLBFillsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "LocalFlushedGVARangesPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "LogicalProcessorDispatchesPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "LogicalProcessorHypercallsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "LogicalProcessorMigrationsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "LongSpinWaitHypercallsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "MemoryInterceptMessagesPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "MSRAccessesCost", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "MSRAccessesCost_Base", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "MSRAccessesPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "MWAITInstructionsCost", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "MWAITInstructionsCost_Base", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "MWAITInstructionsPersec", 1),
    SER_NS_STR(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "Name", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "NestedPageFaultInterceptsCost", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "NestedPageFaultInterceptsCost_Base", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "NestedPageFaultInterceptsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "OtherHypercallsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "OtherInterceptsCost", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "OtherInterceptsCost_Base", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "OtherInterceptsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "OtherMessagesPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "PageFaultInterceptsCost", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "PageFaultInterceptsCost_Base", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "PageFaultInterceptsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "PageInvalidationsCost", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "PageInvalidationsCost_Base", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "PageInvalidationsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "PageTableAllocationsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "PageTableEvictionsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "PageTableReclamationsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "PageTableResetsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "PageTableValidationsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "PageTableWriteInterceptsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "PendingInterruptsCost", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "PendingInterruptsCost_Base", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "PendingInterruptsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "PercentGuestRunTime", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "PercentGuestRunTime_Base", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "PercentHypervisorRunTime", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "PercentHypervisorRunTime_Base", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "PercentRemoteRunTime", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "PercentRemoteRunTime_Base", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "PercentTotalRunTime", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "PercentTotalRunTime_Base", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "ReflectedGuestPageFaultsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "SmallPageTLBFillsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "SyntheticInterruptHypercallsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "SyntheticInterruptsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "Timestamp_Object", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "Timestamp_PerfTime", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "Timestamp_Sys100NS", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "TotalInterceptsCost", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "TotalInterceptsCost_Base", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "TotalInterceptsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "TotalMessagesPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "VirtualInterruptHypercallsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "VirtualInterruptsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "VirtualMMUHypercallsPersec", 1),
    SER_NS_UINT64(WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI, "VirtualProcessorHypercallsPersec", 1),

SER_END_ITEMS(Win32_PerfRawData_HvStats_HyperVHypervisorVirtualProcessor_Data);

Win32PerfRawDataHvStatsHyperVHypervisorVirtualProcessor::Win32PerfRawDataHvStatsHyperVHypervisorVirtualProcessor()
        :AbstractWmiObject(
            WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_WQL_SELECT,
            WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_CLASSNAME,
            "",
            WIN32_PERFRAWDATA_HVSTATS_HYPERVHYPERVISORVIRTUALPROCESSOR_RESOURCE_URI,
            Win32_PerfRawData_HvStats_HyperVHypervisorVirtualProcessor_Data_TypeInfo
        ) {}

}
}
}
}
}
