#ifndef JSON_CPP
#define JSON_CPP

//#include "json.h"
//
//BOOL wmi_run()
//{
//     HRESULT hres;
//
//    // Step 1: --------------------------------------------------
//    // Initialize COM. ------------------------------------------
//
//    hres =  CoInitializeEx(0, COINIT_MULTITHREADED);
//    if (FAILED(hres))
//    {
//        cout << "Failed to initialize COM library. Error code = 0x"
//            << hex << hres << endl;
//        return 1;                  // Program has failed.
//    }
//
//    // Step 2: --------------------------------------------------
//    // Set general COM security levels --------------------------
//    // Note: If you are using Windows 2000, you need to specify -
//    // the default authentication credentials for a user by using
//    // a SOLE_AUTHENTICATION_LIST structure in the pAuthList ----
//    // parameter of CoInitializeSecurity ------------------------
//
//    hres =  CoInitializeSecurity(
//        NULL,
//        -1,                          // COM authentication
//        NULL,                        // Authentication services
//        NULL,                        // Reserved
//        RPC_C_AUTHN_LEVEL_DEFAULT,   // Default authentication
//        RPC_C_IMP_LEVEL_IMPERSONATE, // Default Impersonation
//        NULL,                        // Authentication info
//        EOAC_NONE,                   // Additional capabilities
//        NULL                         // Reserved
//        );
//
//
//
//    if (FAILED(hres))
//    {
//        cout << "Failed to initialize security. Error code = 0x"
//            << hex << hres << endl;
//        CoUninitialize();
//        return 1;                    // Program has failed.
//    }
//
//    // Step 3: ---------------------------------------------------
//    // Obtain the initial locator to WMI -------------------------
//
//    //IWbemLocator *pLoc = NULL;
//
//    hres = CoCreateInstance(CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER, IID_IWbemLocator, (LPVOID *) &pLoc);
//    if (FAILED(hres))
//    {
//        cout << "Failed to create IWbemLocator object."
//            << " Err code = 0x"
//            << hex << hres << endl;
//        CoUninitialize();
//        return 1;                 // Program has failed.
//    }
//
//    // Step 4: -----------------------------------------------------
//    // Connect to WMI through the IWbemLocator::ConnectServer method
//
//    //IWbemServices *pSvc = NULL;
//
//    // Connect to the root\cimv2 namespace with
//    // the current user and obtain pointer pSvc
//    // to make IWbemServices calls.
//    hres = pLoc->ConnectServer(
//         _bstr_t(L"ROOT\\CIMV2"), // Object path of WMI namespace
//         NULL,                    // User name. NULL = current user
//         NULL,                    // User password. NULL = current
//         0,                       // Locale. NULL indicates current
//         NULL,                    // Security flags.
//         0,                       // Authority (e.g. Kerberos)
//         0,                       // Context object
//         &pSvc                    // pointer to IWbemServices proxy
//         );
//
//    if (FAILED(hres))
//    {
//        cout << "Could not connect. Error code = 0x"
//             << hex << hres << endl;
//        pLoc->Release();
//        CoUninitialize();
//        return 1;                // Program has failed.
//    }
//
//    cout << "Connected to ROOT\\CIMV2 WMI namespace" << endl;
//
//    // Step 5: --------------------------------------------------
//    // Set security levels on the proxy -------------------------
//
//    hres = CoSetProxyBlanket(
//       pSvc,                        // Indicates the proxy to set
//       RPC_C_AUTHN_WINNT,           // RPC_C_AUTHN_xxx
//       RPC_C_AUTHZ_NONE,            // RPC_C_AUTHZ_xxx
//       NULL,                        // Server principal name
//       RPC_C_AUTHN_LEVEL_CALL,      // RPC_C_AUTHN_LEVEL_xxx
//       RPC_C_IMP_LEVEL_IMPERSONATE, // RPC_C_IMP_LEVEL_xxx
//       NULL,                        // client identity
//       EOAC_NONE                    // proxy capabilities
//    );
//
//    if (FAILED(hres))
//    {
//        cout << "Could not set proxy blanket. Error code = 0x"
//            << hex << hres << endl;
//        pSvc->Release();
//        pLoc->Release();
//        CoUninitialize();
//        return 1;               // Program has failed.
//    }
// return 0;
//}
//
//
//BOOL wmi_getDriveLetters()
//{
//
//    // Use the IWbemServices pointer to make requests of WMI.
//    // Make requests here:
//    HRESULT hres;
//    IEnumWbemClassObject* pEnumerator = NULL;
//
//    // get localdrives
//    hres = pSvc->ExecQuery(
//                    bstr_t("WQL"),
//                    bstr_t("SELECT * FROM Win32_DiskDrive"),
//                    WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
//                    NULL,
//                    &pEnumerator);
//
//    if (FAILED(hres)) {
//        cout << "Query for processes failed. "
//             << "Error code = 0x"
//             << hex << hres << endl;
//        pSvc->Release();
//        pLoc->Release();
//        CoUninitialize();
//        return FALSE;               // Program has failed.
//    }
//    else {
//
//        IWbemClassObject *pclsObj;
//        ULONG uReturn = 0;
//        while (pEnumerator) {
//           hres = pEnumerator->Next(WBEM_INFINITE, 1,
//                                 &pclsObj, &uReturn);
//           if(0 == uReturn) break;
//
//           VARIANT vtProp;
//           hres = pclsObj->Get(_bstr_t(L"DeviceID"), 0, &vtProp, 0, 0);
//
//           // adjust string
//           wstring tmp = vtProp.bstrVal;
//           hres = pclsObj->Get(L"Index", 0, &vtProp, 0, 0);
//           signed int index = vtProp.intVal; // index
//           tmp = tmp.substr(4);
//
//           wstring wstrQuery = L"Associators of {Win32_DiskDrive.DeviceID='\\\\.\\";
//           wstrQuery += tmp;
//           wstrQuery += L"'} where AssocClass=Win32_DiskDriveToDiskPartition";
//
//           // reference drive to partition
//           IEnumWbemClassObject* pEnumerator1 = NULL;
//           hres = pSvc->ExecQuery(
//                             bstr_t("WQL"),
//                             bstr_t( wstrQuery.c_str()),
//                             WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
//                             NULL,
//                             &pEnumerator1 );
//
//           if ( FAILED(hres) ) {
//            cout << "Query for processes failed. "
//                          << "Error code = 0x"
//                          << hex << hres << endl;
//            pSvc->Release();
//            pLoc->Release();
//            CoUninitialize();
//            return FALSE;               // Program has failed.
//           } else {
//
//                IWbemClassObject *pclsObj1;
//                ULONG uReturn1 = 0;
//                while( pEnumerator1 ) {
//                     hres = pEnumerator1->Next( WBEM_INFINITE, 1,
//                     &pclsObj1, &uReturn1 );
//                     if(0 == uReturn1) break;
//
//                     // reference logical drive to partition
//                     VARIANT vtProp1;
//                     hres = pclsObj1->Get( _bstr_t(L"DeviceID"), 0, &vtProp1, 0, 0 );
//                     wstring wstrQuery = L"Associators of {Win32_DiskPartition.DeviceID='";
//                     wstrQuery += vtProp1.bstrVal;
//                     wstrQuery += L"'} where AssocClass=Win32_LogicalDiskToPartition";
//
//
//
//                     IEnumWbemClassObject* pEnumerator2 = NULL;
//                     hres = pSvc->ExecQuery(
//                                       bstr_t("WQL"),
//                                       bstr_t(wstrQuery.c_str()),
//                                       WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
//                                       NULL,
//                                       &pEnumerator2 );
//
//
//
//
//
//                    if ( FAILED(hres) ) {
//                        cout << "Query for processes failed. "
//                                << "Error code = 0x"
//                                << hex << hres << endl;
//                        pSvc->Release();
//                        pLoc->Release();
//                        CoUninitialize();
//                        return FALSE;               // Program has failed.
//                     } else {
//
//                        // get driveletter
//                        IWbemClassObject *pclsObj2;
//                        ULONG uReturn2 = 0;
//                        while( pEnumerator2 ) {
//                            hres = pEnumerator2->Next( WBEM_INFINITE, 1,
//                            &pclsObj2, &uReturn2 );
//                            if(0 == uReturn2) break;
//
//                            VARIANT vtProp2;
//                            hres = pclsObj2->Get(_bstr_t(L"DeviceID"), 0, &vtProp2, 0, 0 );
//
//
//
//                            // print result
//                            printf("%ls\n", vtProp2.bstrVal);
//
//                            hres = pclsObj2->Get(_bstr_t(L"FileSystem"), 0, &vtProp2, 0, 0);
//                            cout << " FileSystem: " << _com_util::ConvertBSTRToString(vtProp2.bstrVal) << endl;
//                            hres = pclsObj2->Get(_bstr_t(L"FreeSpace"), 0, &vtProp2, 0, 0);
//                            string str = _com_util::ConvertBSTRToString(vtProp2.bstrVal);
//                            cout << " FreeSpace: " << str.c_str() << endl;
//                            cout << " FreeSpace: " << _strtoi64(str.c_str(), NULL, 10) << endl;
//                            cout << " FreeSpace: " << _strtoi64(str.c_str(), NULL, 10) / 1024 << " KB" << endl;
//                            cout << " FreeSpace: " << _strtoi64(str.c_str(), NULL, 10) / (1024*1024) << " MB" << endl;
//                            cout << " FreeSpace: " << _strtoi64(str.c_str(), NULL, 10) / (1024*1024*1024) << " GB" << endl;
//                            cout << " FreeSpace: " << _atoi64(str.c_str()) / (1024*1024*1024) << " GB" << endl;
//                            hres = pclsObj2->Get(_bstr_t(L"Size"), 0, &vtProp2, 0, 0);
//                            cout << " Size: " << _com_util::ConvertBSTRToString(vtProp2.bstrVal) << endl;
//
//                            hres = pclsObj2->Get(_bstr_t(L"VolumeName"), 0, &vtProp2, 0, 0);
//                            cout << " Unknow: " << _com_util::ConvertBSTRToString(vtProp2.bstrVal) << endl;
//
//                            VariantClear(&vtProp2);
//                        }
//                        pclsObj1->Release();
//                    }
//                    VariantClear(&vtProp1);
//                    pEnumerator2->Release();
//                }
//                pclsObj->Release();
//            }
//            VariantClear(&vtProp);
//            pEnumerator1->Release();
//        }
//     }
//     pEnumerator->Release();
//     return TRUE;
//}
//
//
//BOOL wmi_close()
//{
// // Cleanup
//    // ========
//
//    pSvc->Release();
//    pLoc->Release();
//    CoUninitialize();
//
//    return 0;   // Program successfully completed.
//}


#endif