package of.addons.ofxOsc;

import cpp.Lib;

class OscSender 
{

	public function new():Void {
		__handle = _ofxOscSender_new();
	}
	
	public function setup(ip:String,port:Int):Void {
		_ofxOscSender_setup(__handle,ip,port);
	}

	public function sendMessage(m:OscMessage):Void {
		_ofxOscSender_sendMessage(__handle,m.__handle);
	}

	public function sendBundle(b:OscBundle):Void {
		_ofxOscSender_sendBundle(__handle,b.__handle);
	}

	
	public var __handle(default, null):Dynamic;
	
	static var _ofxOscSender_new = Lib.load("hxOpenFrameworks", "_ofxOscSender_new", 0);
	static var _ofxOscSender_setup = Lib.load("hxOpenFrameworks", "_ofxOscSender_setup", 3);
	static var _ofxOscSender_sendMessage = Lib.load("hxOpenFrameworks", "_ofxOscSender_sendMessage", 2);
	static var _ofxOscSender_sendBundle = Lib.load("hxOpenFrameworks", "_ofxOscSender_sendBundle", 2);
}
