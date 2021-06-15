#ifndef WIN_32
#define WIN_32

#include <Windows.h>
#include <comdef.h>
#include <WbemIdl.h>
#include <iostream>
#include <stdint.h>
#include <ctime>
#include <vector>

using namespace std;

class Win32Objs {
protected:
	IWbemLocator *gpLoc;
	IWbemServices *gpSvc;

	IEnumWbemClassObject* init(const char* win32_class, HRESULT& hres);
	HRESULT getString(BSTR field, VARIANT* vtProp, IWbemClassObject* pclsObj, string& str);
	char** getStringCarrays(BSTR field, VARIANT* vtProp, IWbemClassObject* pclsObj, HRESULT& hres);
	vector<char*> getVectorChars(BSTR field, VARIANT* vtProp, IWbemClassObject* pclsObj, HRESULT& hres);
	vector<uint16_t> getVectorU16(BSTR field, VARIANT* vtProp, IWbemClassObject* pclsObj, HRESULT& hres);
	HRESULT getBoolean(BSTR field, VARIANT* vtProp, IWbemClassObject* pclsObj, bool& b);
	HRESULT getuInt16(BSTR field, VARIANT* vtProp, IWbemClassObject* pclsObj, uint16_t& value);
	HRESULT getuInt32(BSTR field, VARIANT* vtProp, IWbemClassObject* pclsObj, uint32_t& value);
	HRESULT getInt32(BSTR field, VARIANT* vtProp, IWbemClassObject* pclsObj, int32_t& value);
	HRESULT getInt64(BSTR field, VARIANT* vtProp, IWbemClassObject* pclsObj, uint64_t& value);
	HRESULT getuInt64(BSTR field, VARIANT* vtProp, IWbemClassObject* pclsObj, uint64_t& value);
	void release();
};

#endif
