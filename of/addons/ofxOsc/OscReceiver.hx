package of.addons.ofxOsc;

import cpp.Lib;

class OscReceiver 
{

	public function new():Void {
		__handle = _ofxOscReceiver_new();
	}
	
	public function setup(port:Int):Void {
		_ofxOscReceiver_setup(__handle,port);
	}

	public function hasWaitingMessages():Bool {
		return _ofxOscReceiver_hasWaitingMessages(__handle);
	}

	public function getNextMessage(m:OscMessage):Bool {
		return _ofxOscReceiver_getNextMessage(__handle,m.__handle);
	}

	
	public var __handle(default, null):Dynamic;
	
	static var _ofxOscReceiver_new = Lib.load("hxOpenFrameworks", "_ofxOscReceiver_new", 0);
	static var _ofxOscReceiver_setup = Lib.load("hxOpenFrameworks", "_ofxOscReceiver_setup", 2);
	static var _ofxOscReceiver_hasWaitingMessages = Lib.load("hxOpenFrameworks", "_ofxOscReceiver_hasWaitingMessages", 1);
	static var _ofxOscReceiver_getNextMessage = Lib.load("hxOpenFrameworks", "_ofxOscReceiver_getNextMessage", 2);
}
