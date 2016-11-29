
#ifndef V1_MSVM_CONCRETEJOB_H
#define V1_MSVM_CONCRETEJOB_H

#include <common/util.h>
#include <drivers/hyperv/wmi/AbstractWmiObject.h>

namespace Drivers {
namespace Hyperv {
namespace Wmi {
namespace Classes {
namespace V1 {
typedef struct _Msvm_ConcreteJob_Data {
    XML_TYPE_STR Caption;
    XML_TYPE_STR Description;
    XML_TYPE_STR ElementName;
    XML_TYPE_STR InstallDate;
    XML_TYPE_DYN_ARRAY OperationalStatus;
    XML_TYPE_DYN_ARRAY StatusDescriptions;
    XML_TYPE_STR Status;
    XML_TYPE_UINT16 HealthState;
    XML_TYPE_STR JobStatus;
    XML_TYPE_STR TimeSubmitted;
    XML_TYPE_STR ScheduledStartTime;
    XML_TYPE_STR StartTime;
    XML_TYPE_STR ElapsedTime;
    XML_TYPE_UINT32 JobRunTimes;
    XML_TYPE_UINT8 RunMonth;
    XML_TYPE_INT8 RunDay;
    XML_TYPE_INT8 RunDayOfWeek;
    XML_TYPE_STR RunStartInterval;
    XML_TYPE_UINT16 LocalOrUtcTime;
    XML_TYPE_STR UntilTime;
    XML_TYPE_STR Notify;
    XML_TYPE_STR Owner;
    XML_TYPE_UINT32 Priority;
    XML_TYPE_UINT16 PercentComplete;
    XML_TYPE_BOOL DeleteOnCompletion;
    XML_TYPE_UINT16 ErrorCode;
    XML_TYPE_STR ErrorDescription;
    XML_TYPE_STR ErrorSummaryDescription;
    XML_TYPE_UINT16 RecoveryAction;
    XML_TYPE_STR OtherRecoveryAction;
    XML_TYPE_STR InstanceID;
    XML_TYPE_STR Name;
    XML_TYPE_UINT16 JobState;
    XML_TYPE_STR TimeOfLastStateChange;
    XML_TYPE_STR TimeBeforeRemoval;
    XML_TYPE_BOOL Cancellable;

} Msvm_ConcreteJob_Data;
SER_DECLARE_TYPE(Msvm_ConcreteJob_Data);
typedef struct _Msvm_ConcreteJob {
    XmlSerializerInfo *serializerInfo;
    Msvm_ConcreteJob_Data *data;
} Msvm_ConcreteJob;

#define V1_MSVM_CONCRETEJOB_RESOURCE_URI \
    "http://schemas.microsoft.com/wbem/wsman/1/wmi/root/virtualization/Msvm_ConcreteJob"

#define V1_MSVM_CONCRETEJOB_CLASSNAME \
    "Msvm_ConcreteJob"

#define V1_MSVM_CONCRETEJOB_WQL_SELECT \
    "select * from Msvm_ConcreteJob "

class MsvmConcreteJob : public AbstractWmiObject
{
public:
  MsvmConcreteJob();
};
}
}
}
}
}
#endif /* V1_MSVM_CONCRETEJOB_H */

