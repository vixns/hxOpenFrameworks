package of.addons.ofxOsc;

import cpp.Lib;

class OscBundle 
{

	public function new():Void {
		__handle = _ofxOscBundle_new();
	}
	
	public function clear():Void {
		_ofxOscBundle_clear(__handle);
	}

	public function addBundle(b:OscBundle):Void {
		_ofxOscBundle_addBundle(__handle,b.__handle);
	}

	public function addMessage(m:OscMessage):Void {
		_ofxOscBundle_addMessage(__handle,m.__handle);
	}

	public function getBundleCount():Int {
		return _ofxOscBundle_getBundleCount(__handle);
	}

	public function getMessageCount():Int {
		return _ofxOscBundle_getMessageCount(__handle);
	}

	public function getBundleAt(id:Int):OscBundle {
		return _ofxOscBundle_getBundleAt(__handle,id);
	}

	public function getMessageAt(id:Int):OscMessage {
		return _ofxOscBundle_getMessageAt(__handle,id);
	}
	
	public var __handle(default, null):Dynamic;
	
	static var _ofxOscBundle_new = Lib.load("hxOpenFrameworks", "_ofxOscBundle_new", 0);
	static var _ofxOscBundle_clear = Lib.load("hxOpenFrameworks", "_ofxOscBundle_clear", 1);
	static var _ofxOscBundle_addBundle = Lib.load("hxOpenFrameworks", "_ofxOscBundle_addBundle", 2);
	static var _ofxOscBundle_addMessage = Lib.load("hxOpenFrameworks", "_ofxOscBundle_addMessage", 2);
	static var _ofxOscBundle_getBundleCount = Lib.load("hxOpenFrameworks", "_ofxOscBundle_getBundleCount", 1);
	static var _ofxOscBundle_getMessageCount = Lib.load("hxOpenFrameworks", "_ofxOscBundle_getMessageCount", 1);
	static var _ofxOscBundle_getBundleAt = Lib.load("hxOpenFrameworks", "_ofxOscBundle_getBundleAt", 2);
	static var _ofxOscBundle_getMessageAt = Lib.load("hxOpenFrameworks", "_ofxOscBundle_getMessageAt", 2);
}
