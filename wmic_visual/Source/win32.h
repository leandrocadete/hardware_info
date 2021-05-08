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
class Win32_Wmi
{
public:
    Win32_Wmi(){}
    ~Win32_Wmi(){
		cout << "Win32 DELETED" << endl;
	}
	static char* BstrToString(BSTR bstr) {
		if(bstr == NULL) return "";
		return _com_util::ConvertBSTRToString(bstr);
	}
	
};
class Win32Objs {
protected:
	IWbemLocator *gpLoc;
	IWbemServices *gpSvc;

	IEnumWbemClassObject* init(const char *win32_class, HRESULT &hres) {
		IEnumWbemClassObject *pEnumerator;
		//process = new Process();
		// Initialize COM. 
		hres = CoInitializeEx(0, COINIT_MULTITHREADED);
		if (FAILED(hres)) {
			cout << "Failed to initialize COM library. Error code = 0x" << hex << hres << endl;
			return NULL;
		}
		// Initialize
		hres = CoInitializeSecurity(NULL,
			-1, // COM negotiate service
			NULL, // Authentication services
			NULL, // Reserved
		RPC_C_AUTHN_LEVEL_DEFAULT, // Authentication
		RPC_C_IMP_LEVEL_IMPERSONATE, // Impersonation
		NULL, // Authentication info
		EOAC_NONE, // Additional Capabilities
		NULL);
		if (FAILED(hres)) {
			cout << "Failed to initialize security. Erro code 0x" << hex << hres << endl;
			CoUninitialize();
			return NULL; // Program has failed.
		}
		// Obtain the initial locator to Windows Management
		// on a particular host computer
		gpLoc = 0;
		hres = CoCreateInstance(CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER, IID_IWbemLocator, (LPVOID *) &gpLoc);

		if (FAILED(hres)) {
			cout << "Failed to create IWbemLocator object. Error code = 0x" << hex << hres << endl;
			CoUninitialize();
			return NULL; // Programa has failed.
		}
		gpSvc = NULL;

		// Connect to the root\cimv2 namespace with the
		// current user and obtain pointer pSvc
		// to make IWbemService calls.
		hres = gpLoc->ConnectServer(_bstr_t(L"ROOT\\CIMV2"), // WMI namespace
			NULL, // User name
			NULL, // User password
			0, // Locale
			NULL, // Security flags
			0, // Authority
			0, // Context object
			&gpSvc);
		if (FAILED(hres)) {
			cout << "Could not connect. Error code = 0x" << hex << hres << endl;
			gpLoc->Release();
			CoUninitialize();
			return NULL;	// Program has failed.
		}
		cout << "Connect to ROOT\\CIMV2 WMI namespace" << endl;
		// Set the IWbemServices proxy so that impersonation
		// of the user (client) occurs.
		hres = CoSetProxyBlanket(
			gpSvc, // The proxy to set
			RPC_C_AUTHN_WINNT, // Authentication service
			RPC_C_AUTHZ_NONE, // Authorization service
			NULL, // Serve principal name			
			RPC_C_AUTHN_LEVEL_CALL, // Impersonation level
			RPC_C_IMP_LEVEL_IMPERSONATE,
			NULL, // Client identity
			EOAC_NONE // proxy capabilities
		);
		if (FAILED(hres)) {
			cout << "Could not set proxy blanket. Error code = 0x" << hex << hres << endl;
			gpSvc->Release();
			gpLoc->Release();
			CoUninitialize();
			return NULL; // Program has failed
		}
		// Use the IWbemServices pointer to make request of WMI.
		// Make request here:
		// For example, query for all the running processes				
		hres = gpSvc->ExecQuery(bstr_t("WQL"), bstr_t(win32_class), WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, NULL, &pEnumerator);
		if (FAILED(hres)) {
			cout << "Query for process failed. Error code = 0x" << hex << hres << endl;
			gpSvc->Release();
			gpLoc->Release();
			CoUninitialize();
			return NULL; // Program has failed.
		} 
		return pEnumerator;
	}

	HRESULT getString(BSTR field, VARIANT *vtProp, IWbemClassObject *pclsObj, string &str) {
		HRESULT hres;
		hres = pclsObj->Get(field, 0, vtProp, 0, 0);
		if(vtProp->vt == 1)
			str = "";
		else 
			str = _com_util::ConvertBSTRToString(vtProp->bstrVal);
		return hres;
	}

	char** getStringCarrays(BSTR field, VARIANT *vtProp, IWbemClassObject *pclsObj, HRESULT &hres)  {
		char** str;
		SAFEARRAY* s_array;
		BSTR* ptr_bstr;
		hres = pclsObj->Get(field, 0, vtProp, 0, 0);
		if(vtProp->vt == 1) {
			str = NULL;
		} else {
			unsigned long int rgsabound = vtProp->parray->rgsabound[0].cElements;
			s_array = vtProp->parray;
			str = new char*[rgsabound];

			for(int i = 0; i < rgsabound; i++) {
				ptr_bstr = static_cast<BSTR*>(s_array->pvData);
				auto v = ptr_bstr[i];
				str[i] = new char[39];
				char temp[39];
				strcpy(temp, _com_util::ConvertBSTRToString(v));
				strcpy(str[i], temp);
			}
		}
		return str;
	}

	vector<char*> getVectorChars(BSTR field, VARIANT *vtProp, IWbemClassObject *pclsObj, HRESULT &hres)  {
		vector<char*> vet_str;
		SAFEARRAY* s_array;
		BSTR* ptr_bstr;
		char** temp;
		unsigned long int rgsabound;

		hres = pclsObj->Get(field, 0, vtProp, 0, 0);
		if(vtProp->vt == 1) {
			return vet_str;
		} else {
			rgsabound = vtProp->parray->rgsabound[0].cElements;
			s_array = vtProp->parray;
			temp = new char*[rgsabound];
			for(int i = 0; i < rgsabound; i++) {
				ptr_bstr = static_cast<BSTR*>(s_array->pvData);
				auto v = ptr_bstr[i];
				temp[i] = new char[39];
				strcpy(temp[i], _com_util::ConvertBSTRToString(v));				
				vet_str.push_back(temp[i]);
				
			}
		}
		//for (int i = 0; i < rgsabound; i++) {
		//	delete [] temp[i];
		//}		
		//delete [] temp;
		return vet_str;
	}

    vector<uint16_t> getVectorU16(BSTR field, VARIANT *vtProp, IWbemClassObject *pclsObj, HRESULT &hres)  {
        vector<uint16_t> vet_uint32;
//        SAFEARRAY* s_array;
//        uint16_t* pt_u16;
//        uint16_t temp;
//        unsigned long int rgsabound;

//        hres = pclsObj->Get(field, 0, vtProp, 0, 0);
//        if(vtProp->vt == 1) {
//            return vet_str;
//        } else {
//            rgsabound = vtProp->parray->rgsabound[0].cElements;
//            s_array = vtProp->parray;
//            //temp = new char*[rgsabound];
//            for(int i = 0; i < rgsabound; i++) {
//                pt_u16 = static_cast<uint16_t>(s_array->pvData);
//                auto v = pt_u16[i];
//                temp[i] = new char[39];
//                strcpy(temp[i], _com_util::ConvertBSTRToString(v));
//                vet_str.push_back(temp[i]);

//            }
//        }
//        //for (int i = 0; i < rgsabound; i++) {
//        //	delete [] temp[i];
//        //}
//        //delete [] temp;
//        return vet_str;

        return vet_uint32;
    }

	HRESULT getBoolean(BSTR field, VARIANT *vtProp, IWbemClassObject *pclsObj, bool &b) {
		HRESULT hres;
		hres = pclsObj->Get(field, 0, vtProp, 0, 0);
		if(vtProp->vt == 1)
			b = false;
		else 
			b = vtProp->boolVal;
		return hres;
	}

	HRESULT getuInt16(BSTR field, VARIANT *vtProp, IWbemClassObject *pclsObj, uint16_t &value) {
		HRESULT hres;
		hres = pclsObj->Get(field, 0, vtProp, 0, 0);
		if(vtProp->vt == 1)
			value = 0;
		else 
			value = vtProp->uiVal;
		return hres;
	}

	HRESULT getuInt32(BSTR field, VARIANT *vtProp, IWbemClassObject *pclsObj, uint32_t &value) {
		HRESULT hres;
		hres = pclsObj->Get(field, 0, vtProp, 0, 0);
		if(vtProp->vt == 1)
			value = 0;
		else 
			value = vtProp->uintVal;
		return hres;
	}

	HRESULT getInt32(BSTR field, VARIANT *vtProp, IWbemClassObject *pclsObj, int32_t &value) {
		HRESULT hres;
		hres = pclsObj->Get(field, 0, vtProp, 0, 0);
		if(vtProp->vt == 1)
			value = 0;
		else 
			value = vtProp->intVal;
		return hres;
	}

	HRESULT getInt64(BSTR field, VARIANT *vtProp, IWbemClassObject *pclsObj, uint64_t &value) {
		HRESULT hres;
		hres = pclsObj->Get(field, 0, vtProp, 0, 0);
		if(vtProp->vt == 1)
			value = 0;
		else 
			value = vtProp->llVal;
		return hres;
	}

	HRESULT getuInt64(BSTR field, VARIANT *vtProp, IWbemClassObject *pclsObj, uint64_t &value) {
		HRESULT hres;
		hres = pclsObj->Get(field, 0, vtProp, 0, 0);
		if(vtProp->vt == 1)
			value = 0;
		else 
			value = vtProp->ullVal;
		return hres;
	}

	void release() {
		gpSvc->Release();
		gpLoc->Release();
		CoUninitialize();
	}
};

#endif
