
#include "Msvm_ConcreteJob.h"

namespace Drivers {
    namespace Hyperv {
        namespace Wmi {
            namespace Classes {
                namespace V2 {

                    SER_START_ITEMS(Msvm_ConcreteJob_Data)
                        SER_NS_STR(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "InstanceID", 1),
                        SER_NS_STR(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "Caption", 1),
                        SER_NS_STR(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "Description", 1),
                        SER_NS_STR(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "ElementName", 1),
                        SER_NS_STR(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "InstallDate", 1),
                        SER_NS_STR(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "Name", 1),
                        SER_NS_DYN_ARRAY(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "OperationalStatus", 0, 0, uint16),
                        SER_NS_DYN_ARRAY(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "StatusDescriptions", 0, 0, string),
                        SER_NS_STR(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "Status", 1),
                        SER_NS_UINT16(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "HealthState", 1),
                        SER_NS_UINT16(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "CommunicationStatus", 1),
                        SER_NS_UINT16(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "DetailedStatus", 1),
                        SER_NS_UINT16(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "OperatingStatus", 1),
                        SER_NS_UINT16(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "PrimaryStatus", 1),
                        SER_NS_STR(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "JobStatus", 1),
                        SER_NS_STR(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "TimeSubmitted", 1),
                        SER_NS_STR(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "ScheduledStartTime", 1),
                        SER_NS_STR(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "StartTime", 1),
                        SER_NS_STR(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "ElapsedTime", 1),
                        SER_NS_UINT32(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "JobRunTimes", 1),
                        SER_NS_UINT8(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "RunMonth", 1),
                        SER_NS_INT8(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "RunDay", 1),
                        SER_NS_INT8(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "RunDayOfWeek", 1),
                        SER_NS_STR(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "RunStartInterval", 1),
                        SER_NS_UINT16(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "LocalOrUtcTime", 1),
                        SER_NS_STR(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "UntilTime", 1),
                        SER_NS_STR(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "Notify", 1),
                        SER_NS_STR(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "Owner", 1),
                        SER_NS_UINT32(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "Priority", 1),
                        SER_NS_UINT16(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "PercentComplete", 1),
                        SER_NS_BOOL(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "DeleteOnCompletion", 1),
                        SER_NS_UINT16(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "ErrorCode", 1),
                        SER_NS_STR(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "ErrorDescription", 1),
                        SER_NS_STR(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "ErrorSummaryDescription", 1),
                        SER_NS_UINT16(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "RecoveryAction", 1),
                        SER_NS_STR(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "OtherRecoveryAction", 1),
                        SER_NS_UINT16(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "JobState", 1),
                        SER_NS_STR(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "TimeOfLastStateChange", 1),
                        SER_NS_STR(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "TimeBeforeRemoval", 1),
                        SER_NS_BOOL(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "Cancellable", 1),
                        SER_NS_UINT16(V2_MSVM_CONCRETEJOB_RESOURCE_URI, "JobType", 1),

                    SER_END_ITEMS(Msvm_ConcreteJob_Data);
                    
                    MsvmConcreteJobMeta::MsvmConcreteJobMeta()
                            :AbstractWmiObject(
                                V2_MSVM_CONCRETEJOB_WQL_SELECT,
                                V2_MSVM_CONCRETEJOB_CLASSNAME,
                                "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/virtualization/v2/*",
                                V2_MSVM_CONCRETEJOB_RESOURCE_URI,
                                Msvm_ConcreteJob_Data_TypeInfo
                            ) {}

                }
            }
        }
    }
}
