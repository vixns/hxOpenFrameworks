package of.addons.ofxOsc;

import cpp.Lib;

class OscMessage 
{

	public function new():Void {
		__handle = _ofxOscMessage_new();
	}

	public static function create(h:Dynamic):OscMessage {
		var o:OscMessage = Type.createEmptyInstance(OscMessage);
		o.__handle = h;
		return o;
	}

	public function clear():Void {
		_ofxOscMessage_clear(__handle);
	}

	public function getAddress():String {
		return _ofxOscMessage_getAddress(__handle);
	}
	
	public function getRemoteIp():String {
		return _ofxOscMessage_getRemoteIp(__handle);
	}

	public function getRemotePort():Int {
		return _ofxOscMessage_getRemotePort(__handle);
	}
	
	public function getNumArgs():Int {
		return _ofxOscMessage_getNumArgs(__handle);
	}

	public function getArgTypeName(id:Int):String {
		return _ofxOscMessage_getArgTypeName(__handle,id);
	}

	public function getArgAt(id:Int):Dynamic {
		switch(getArgTypeName(id)) {
			case "int","int32":
				return _ofxOscMessage_getArgAsInt(__handle,id);
			case "float":
				return _ofxOscMessage_getArgAsFloat(__handle,id);
			case "string":
				return _ofxOscMessage_getArgAsString(__handle,id);
			default:
				trace(getArgTypeName(id));
				return null;
		}
	}
	
	public function setAddress(a:String):Void {
		_ofxOscMessage_setAddress(__handle,a);
	}
	
	public function setRemoteEndpoint(a:String,p:Int):Void {
		_ofxOscMessage_setRemoteEndpoint(__handle,a,p);
	}
	
	public function addArg(a:Dynamic):Void {
		switch(Type.typeof(a)) {
			case TInt:
				addIntArg(a);
			case TFloat:
				addFloatArg(a);
			default:
				addStringArg(Std.string(a));
		}	
	}

	function addIntArg(a:Int):Void {
		_ofxOscMessage_addIntArg(__handle,a);
	}
	
	function addFloatArg(a:Float):Void {
		_ofxOscMessage_addFloatArg(__handle,a);
	}
	
	function addStringArg(a:String):Void {
		_ofxOscMessage_addStringArg(__handle,a);
	}
	
	public var __handle(default, null):Dynamic;
	
	static var _ofxOscMessage_new = Lib.load("hxOpenFrameworks", "_ofxOscMessage_new", 0);
	static var _ofxOscMessage_clear = Lib.load("hxOpenFrameworks", "_ofxOscMessage_clear", 1);
	static var _ofxOscMessage_getAddress = Lib.load("hxOpenFrameworks", "_ofxOscMessage_getAddress", 1);
	static var _ofxOscMessage_getRemoteIp = Lib.load("hxOpenFrameworks", "_ofxOscMessage_getRemoteIp", 1);
	static var _ofxOscMessage_getRemotePort = Lib.load("hxOpenFrameworks", "_ofxOscMessage_getRemotePort", 1);
	static var _ofxOscMessage_getNumArgs = Lib.load("hxOpenFrameworks", "_ofxOscMessage_getNumArgs", 1);
	static var _ofxOscMessage_getArgTypeName = Lib.load("hxOpenFrameworks", "_ofxOscMessage_getArgTypeName", 2);
	static var _ofxOscMessage_getArgAsInt = Lib.load("hxOpenFrameworks", "_ofxOscMessage_getArgAsInt", 2);
	static var _ofxOscMessage_getArgAsFloat = Lib.load("hxOpenFrameworks", "_ofxOscMessage_getArgAsFloat", 2);
	static var _ofxOscMessage_getArgAsString = Lib.load("hxOpenFrameworks", "_ofxOscMessage_getArgAsString", 2);
	static var _ofxOscMessage_setAddress = Lib.load("hxOpenFrameworks", "_ofxOscMessage_setAddress", 2);
	static var _ofxOscMessage_setRemoteEndpoint = Lib.load("hxOpenFrameworks", "_ofxOscMessage_setRemoteEndpoint", 3);
	static var _ofxOscMessage_addIntArg = Lib.load("hxOpenFrameworks", "_ofxOscMessage_addIntArg", 2);
	static var _ofxOscMessage_addFloatArg = Lib.load("hxOpenFrameworks", "_ofxOscMessage_addFloatArg", 2);
	static var _ofxOscMessage_addStringArg = Lib.load("hxOpenFrameworks", "_ofxOscMessage_addStringArg", 2);
}
