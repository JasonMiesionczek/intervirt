#include <drivers/hyperv/HypervCommon.h>

HypervCommon::HypervCommon(Connection::ConnectionPtr conn)
{
    auto host = conn->getHost();
    auto user = conn->getUsername();
    auto pw = conn->getPassword();
    this->client = wsmc_create(host.c_str(), 5985, "/wsman", "http", user.c_str(), pw.c_str());
    wsmc_transport_init(this->client, NULL);
    wsman_transport_set_auth_method(this->client, "basic");
    // this->client = new OpenWsmanClient(
    //         host,
    //         5985,
    //         "/wsman",
    //         "http",
    //         "basic",
    //         user,
    //         pw
    //     );
}

int HypervCommon::verifyResponse(WsXmlDocH response, const char *detail)
{
    int lastError = wsmc_get_last_error(this->client);
    int responseCode = wsmc_get_response_code(this->client);

    WsManFault *fault;
    if (lastError != WS_LASTERR_OK) {
        return -1;
    }

    if (responseCode != 200 && responseCode != 400 && responseCode != 500) {
        return -1;
    }

    if (response == NULL) {
        return -1;
    }

    if (wsmc_check_for_fault(response)) {
        fault = wsmc_fault_new();
        if (fault == NULL) {
            return -1;
        }

        wsmc_get_fault_data(response, fault);
        wsmc_fault_destroy(fault);
        return -1;
    }

    return 0;
}
