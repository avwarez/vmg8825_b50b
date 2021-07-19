#ifndef __XMPP_PARAMETER_H__
#define __XMPP_PARAMETER_H__

tr98Parameter_t para_Xmpp[] = {
        { "ConnectionNumberOfEntries", PARAMETER_ATTR_READONLY, 0, json_type_uint32},
        { NULL, 0, 0, 0}
};

tr98Parameter_t para_XmppConn[] = {
        { "Enable",                 PARAMETER_ATTR_WRITE,    0,     json_type_boolean},
        { "Alias",                  PARAMETER_ATTR_WRITE,    65,    json_type_string},
        { "Username",               PARAMETER_ATTR_WRITE,    257,   json_type_string},
        { "Password",               PARAMETER_ATTR_WRITE,    257,   json_type_string},
        { "Domain",                 PARAMETER_ATTR_WRITE,    65,    json_type_string},
        { "Resource",               PARAMETER_ATTR_WRITE,    65,    json_type_string},
        { "JabberID",               PARAMETER_ATTR_READONLY, 257,   json_type_string},
        { "Status",                 PARAMETER_ATTR_READONLY, 257,   json_type_string},
        { "LastChangeDate",         PARAMETER_ATTR_READONLY, 32,    json_type_string},
        { "KeepAliveInterval",      PARAMETER_ATTR_WRITE,    0,     json_type_int},
        { "UseTLS",                 PARAMETER_ATTR_WRITE,    0,     json_type_boolean},
        { "TLSEstablished",         PARAMETER_ATTR_READONLY, 0,     json_type_boolean},
        { "ServerNumberOfEntries",  PARAMETER_ATTR_READONLY, 0,     json_type_uint32},
        { NULL, 0, 0, 0}
};

tr98Parameter_t para_XmppConnSrv[] = {
        { "Enable",                 PARAMETER_ATTR_WRITE,  0,   json_type_boolean},
        { "Alias",                  PARAMETER_ATTR_WRITE,  65,  json_type_string},
        { "Priority",               PARAMETER_ATTR_WRITE,  0,   json_type_uint32},
        { "Weight",                 PARAMETER_ATTR_WRITE,  0,   json_type_int},
        { "ServerAddress",          PARAMETER_ATTR_WRITE,  257, json_type_string},
        { "Port",                   PARAMETER_ATTR_WRITE,  0,   json_type_uint32},
        { NULL, 0, 0, 0}
};
#endif
