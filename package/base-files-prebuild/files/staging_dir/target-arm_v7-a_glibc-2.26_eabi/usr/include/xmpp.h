#ifndef __XMPP_H__
#define __XMPP_H__
/*Parameter*/
extern tr98Parameter_t para_Xmpp[];
extern tr98Parameter_t para_XmppConn[];
extern tr98Parameter_t para_XmppConnSrv[];

/* InternetGatewayDevice.XMPP */
/* InternetGatewayDevice.XMPP.Connection.i */
extern zcfgRet_t xmppObjGet(char *tr98FullPathName, int handler, struct json_object **tr98Jobj, struct json_object *multiJobj, char *paramfault);
extern zcfgRet_t xmppObjSet(char *tr98FullPathName, int handler, struct json_object *tr98Jobj, struct json_object *multiJobj, char *paramfault);

/* InternetGatewayDevice.XMPP.Connection.i.Server.i */
extern zcfgRet_t xmppConnSrvObjGet(char *tr98FullPathName, int handler, struct json_object **tr98Jobj, struct json_object *multiJobj, char *paramfault);
extern zcfgRet_t xmppConnSrvObjSet(char *tr98FullPathName, int handler, struct json_object *tr98Jobj, struct json_object *multiJobj, char *paramfault);

#endif
