#include "EsxFactory.h"

namespace Drivers {
    namespace Esx {

        EsxFactory::~EsxFactory() {}

        IDriverPtr EsxFactory::create(Connection::ConnectionPtr conn) {
            return MKSHRD(EsxDriver, conn);
        }
    }
}
