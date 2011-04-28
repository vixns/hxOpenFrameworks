
#include <hx/CFFI.h>

#include "ofMain.h"
#include "ofxOsc.h"

DEFINE_KIND(_ofxOscMessage);

void delete_ofxOscMessage(value a) {
	ofxOscMessage* oscMessage = (ofxOscMessage*) val_data(a);
	delete oscMessage;
}

value _ofxOscMessage_new() {
	value ret = alloc_abstract(_ofxOscMessage, new ofxOscMessage());
	val_gc(ret, delete_ofxOscMessage);
	return ret;
}
DEFINE_PRIM(_ofxOscMessage_new,0);

void _ofxOscMessage_clear(value a) {
	ofxOscMessage* oscMessage = (ofxOscMessage*) val_data(a);
	oscMessage->clear();
}
DEFINE_PRIM(_ofxOscMessage_clear,1);

value _ofxOscMessage_getAddress(value a) {
	ofxOscMessage* oscMessage = (ofxOscMessage*) val_data(a);
	return alloc_string(oscMessage->getAddress().c_str());
}
DEFINE_PRIM(_ofxOscMessage_getAddress,1);

value _ofxOscMessage_getRemoteIp(value a) {
	ofxOscMessage* oscMessage = (ofxOscMessage*) val_data(a);
	return alloc_string(oscMessage->getRemoteIp().c_str());
}
DEFINE_PRIM(_ofxOscMessage_getRemoteIp,1);

value _ofxOscMessage_getRemotePort(value a) {
	ofxOscMessage* oscMessage = (ofxOscMessage*) val_data(a);
	return alloc_int(oscMessage->getRemotePort());
}
DEFINE_PRIM(_ofxOscMessage_getRemotePort,1);

value _ofxOscMessage_getNumArgs(value a) {
	ofxOscMessage* oscMessage = (ofxOscMessage*) val_data(a);
	return alloc_int(oscMessage->getNumArgs());
}
DEFINE_PRIM(_ofxOscMessage_getNumArgs,1);

//TODO getArgType()

value _ofxOscMessage_getArgTypeName(value a,value b) {
	ofxOscMessage* oscMessage = (ofxOscMessage*) val_data(a);
	return alloc_string(oscMessage->getArgTypeName(val_int(b)).c_str());
}
DEFINE_PRIM(_ofxOscMessage_getArgTypeName,2);

value _ofxOscMessage_getArgAsInt(value a,value b) {
	ofxOscMessage* oscMessage = (ofxOscMessage*) val_data(a);
	return alloc_int32(oscMessage->getArgAsInt32(val_int(b)));
}
DEFINE_PRIM(_ofxOscMessage_getArgAsInt,2);

value _ofxOscMessage_getArgAsFloat(value a,value b) {
	ofxOscMessage* oscMessage = (ofxOscMessage*) val_data(a);
	return alloc_float(oscMessage->getArgAsFloat(val_int(b)));
}
DEFINE_PRIM(_ofxOscMessage_getArgAsFloat,2);

value _ofxOscMessage_getArgAsString(value a,value b) {
	ofxOscMessage* oscMessage = (ofxOscMessage*) val_data(a);
	return alloc_string(oscMessage->getArgAsString(val_int(b)).c_str());
}
DEFINE_PRIM(_ofxOscMessage_getArgAsString,2);

void _ofxOscMessage_setAddress(value a,value b) {
	ofxOscMessage* oscMessage = (ofxOscMessage*) val_data(a);
	oscMessage->setAddress(val_string(b));
}
DEFINE_PRIM(_ofxOscMessage_setAddress,2);

void _ofxOscMessage_setRemoteEndpoint(value a,value b,value c) {
	ofxOscMessage* oscMessage = (ofxOscMessage*) val_data(a);
	oscMessage->setRemoteEndpoint(val_string(b),val_int(c));
}
DEFINE_PRIM(_ofxOscMessage_setRemoteEndpoint,3);

void _ofxOscMessage_addIntArg(value a,value b) {
	ofxOscMessage* oscMessage = (ofxOscMessage*) val_data(a);
	oscMessage->addIntArg(val_int(b));
}
DEFINE_PRIM(_ofxOscMessage_addIntArg,2);

void _ofxOscMessage_addFloatArg(value a,value b) {
	ofxOscMessage* oscMessage = (ofxOscMessage*) val_data(a);
	oscMessage->addFloatArg(val_float(b));
}
DEFINE_PRIM(_ofxOscMessage_addFloatArg,2);

void _ofxOscMessage_addStringArg(value a,value b) {
	ofxOscMessage* oscMessage = (ofxOscMessage*) val_data(a);
	oscMessage->addStringArg(val_string(b));
}
DEFINE_PRIM(_ofxOscMessage_addStringArg,2);




DEFINE_KIND(_ofxOscBundle);

void delete_ofxOscBundle(value a) {
	ofxOscBundle* oscBundle = (ofxOscBundle*) val_data(a);
	delete oscBundle;
}

value _ofxOscBundle_new() {
	value ret = alloc_abstract(_ofxOscBundle, new ofxOscBundle());
	val_gc(ret, delete_ofxOscBundle);
	return ret;
}
DEFINE_PRIM(_ofxOscBundle_new,0);

void _ofxOscBundle_clear(value a) {
	ofxOscBundle* oscBundle = (ofxOscBundle*) val_data(a);
	oscBundle->clear();
}
DEFINE_PRIM(_ofxOscBundle_clear,1);

void _ofxOscBundle_addBundle(value a,value b) {
	val_check_kind(b,_ofxOscBundle);
	ofxOscBundle* oscBundle = (ofxOscBundle*) val_data(a);
	oscBundle->addBundle(*(ofxOscBundle*) val_data(b));
}
DEFINE_PRIM(_ofxOscBundle_addBundle,2);

void _ofxOscBundle_addMessage(value a,value b) {
	val_check_kind(b,_ofxOscMessage);
	ofxOscBundle* oscBundle = (ofxOscBundle*) val_data(a);
	oscBundle->addMessage(*(ofxOscMessage*) val_data(b));
}
DEFINE_PRIM(_ofxOscBundle_addMessage,2);

value _ofxOscBundle_getBundleCount(value a) {
	ofxOscBundle* oscBundle = (ofxOscBundle*) val_data(a);
	return alloc_int(oscBundle->getBundleCount());
}
DEFINE_PRIM(_ofxOscBundle_getBundleCount,1);

value _ofxOscBundle_getMessageCount(value a) {
	ofxOscBundle* oscBundle = (ofxOscBundle*) val_data(a);
	return alloc_int(oscBundle->getMessageCount());
}
DEFINE_PRIM(_ofxOscBundle_getMessageCount,1);

value _ofxOscBundle_getBundleAt(value a,value b) {
	ofxOscBundle* oscBundle = (ofxOscBundle*) val_data(a);
	return alloc_abstract(_ofxOscBundle,&oscBundle->getBundleAt(val_int(b)));
}
DEFINE_PRIM(_ofxOscBundle_getBundleAt,2);

value _ofxOscBundle_getMessageAt(value a,value b) {
	ofxOscBundle* oscBundle = (ofxOscBundle*) val_data(a);
	return alloc_abstract(_ofxOscMessage,&oscBundle->getMessageAt(val_int(b)));
}
DEFINE_PRIM(_ofxOscBundle_getMessageAt,2);




DEFINE_KIND(_ofxOscSender);

void delete_ofxOscSender(value a) {
	ofxOscSender* oscSender = (ofxOscSender*) val_data(a);
	delete oscSender;
}

value _ofxOscSender_new() {
	value ret = alloc_abstract(_ofxOscSender, new ofxOscSender());
	val_gc(ret, delete_ofxOscSender);
	return ret;
}
DEFINE_PRIM(_ofxOscSender_new,0);

void _ofxOscSender_setup(value a,value b,value c) {
	ofxOscSender* oscSender = (ofxOscSender*) val_data(a);
	oscSender->setup(val_string(b),val_int(c));
}
DEFINE_PRIM(_ofxOscSender_setup,3);

void _ofxOscSender_sendMessage(value a,value b) {
	ofxOscSender* oscSender = (ofxOscSender*) val_data(a);
	oscSender->sendMessage(*(ofxOscMessage*)val_data(b));
}
DEFINE_PRIM(_ofxOscSender_sendMessage,2);

void _ofxOscSender_sendBundle(value a,value b) {
	ofxOscSender* oscSender = (ofxOscSender*) val_data(a);
	oscSender->sendBundle(*(ofxOscBundle*)val_data(b));
}
DEFINE_PRIM(_ofxOscSender_sendBundle,2);

DEFINE_KIND(_ofxOscReceiver);

void delete_ofxOscReceiver(value a) {
	ofxOscReceiver* oscReceiver = (ofxOscReceiver*) val_data(a);
	delete oscReceiver;
}

value _ofxOscReceiver_new() {
	value ret = alloc_abstract(_ofxOscReceiver, new ofxOscReceiver());
	val_gc(ret, delete_ofxOscReceiver);
	return ret;
}
DEFINE_PRIM(_ofxOscReceiver_new,0);

void _ofxOscReceiver_setup(value a,value b) {
	ofxOscReceiver* oscReceiver = (ofxOscReceiver*) val_data(a);
	oscReceiver->setup(val_int(b));
}
DEFINE_PRIM(_ofxOscReceiver_setup,2);

value _ofxOscReceiver_hasWaitingMessages(value a) {
	ofxOscReceiver* oscReceiver = (ofxOscReceiver*) val_data(a);
	return alloc_bool(oscReceiver->hasWaitingMessages());
}
DEFINE_PRIM(_ofxOscReceiver_hasWaitingMessages,1);

value _ofxOscReceiver_getNextMessage(value a,value b) {
	ofxOscReceiver* oscReceiver = (ofxOscReceiver*) val_data(a);
	ofxOscMessage* oscMessage = (ofxOscMessage*) val_data(b);
	return alloc_bool(oscReceiver->getNextMessage(oscMessage));
}
DEFINE_PRIM(_ofxOscReceiver_getNextMessage,2);


