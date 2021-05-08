#ifndef CPU_H
#define CPU_H

#include <vector>
#include "win32.h"
class CPU {
private:
    uint16_t AddressWidth;
    uint16_t Architecture;
    string AssetTag;
    uint16_t Availability;
    string Caption;
    uint32_t Characteristics;
    uint32_t ConfigManagerErrorCode;
    bool  ConfigManagerUserConfig;
    uint16_t CpuStatus;
    string CreationClassName;
    uint32_t CurrentClockSpeed;
    uint16_t CurrentVoltage;
    uint16_t DataWidth;
    string Description;
    string DeviceID;
    bool  ErrorCleared;
    string ErrorDescription;
    uint32_t ExtClock;
    uint16_t Family;
    uint32_t L2CacheSize;
    uint32_t L2CacheSpeed;
    uint32_t L3CacheSize;
    uint32_t L3CacheSpeed;
    uint32_t LastErrorCode;
    uint16_t Level;
    uint16_t LoadPercentage;
    string Manufacturer;
    uint32_t MaxClockSpeed;
    string Name;
    uint32_t NumberOfCores;
    uint32_t NumberOfEnabledCore;
    uint32_t NumberOfLogicalProcessors;
    string OtherFamilyDescription;
    string PartNumber;
    string PNPDeviceID;
    vector<uint16_t> PowerManagementCapabilities;
    bool  PowerManagementSupported;
    string ProcessorId;
    uint16_t ProcessorType;
    uint16_t Revision;
    string Role;
    bool  SecondLevelAddressTranslationExtensions;
    string SerialNumber;
    string SocketDesignation;
    string Status;
    uint16_t StatusInfo;
    string Stepping;
    string SystemCreationClassName;
    string SystemName;
    uint32_t ThreadCount;
    string UniqueId;
    uint16_t UpgradeMethod; // discarted
    string Version; // discarted
    bool  VirtualizationFirmwareEnabled;
    bool  VMMonitorModeExtensions;
    uint32_t VoltageCaps;
public:
    uint16_t getArchitecture() { return Architecture;}
    void setArchitecture(uint16_t v) { Architecture = v; }

    string getAssetTag() { return AssetTag; }
    void setAssetTag(string v) { AssetTag = v; }

    uint16_t getAvailability() { return Availability; }
    void setAvailability(uint16_t v) { Availability = v; }

    string getCaption() { return Caption; }
    void setCaption(string v) { Caption = v; }

    uint32_t getCharacteristics() { return Characteristics; }
    void setCharacteristics(uint32_t v) { Characteristics = v; }

    uint32_t getConfigManagerErrorCode() { return ConfigManagerErrorCode; }
    void setConfigManagerErrorCode(uint32_t v) { ConfigManagerErrorCode = v; }

    bool getConfigManagerUserConfig() { return ConfigManagerUserConfig; }
    void setConfigManageruserConfig(bool v) { ConfigManagerUserConfig = v; }

    string getCreationClassName() const
    {
        return CreationClassName;
    }

    void setCreationClassName(const string &value)
    {
        CreationClassName = value;
    }

    uint32_t getCurrentClockSpeed() const
    {
    return CurrentClockSpeed;
    }

    void setCurrentClockSpeed(const uint32_t &value)
    {
    CurrentClockSpeed = value;
    }

    uint16_t getCurrentVoltage() const
    {
    return CurrentVoltage;
    }

    void setCurrentVoltage(const uint16_t &value)
    {
    CurrentVoltage = value;
    }

    uint16_t getDataWidth() const
    {
    return DataWidth;
    }

    void setDataWidth(const uint16_t &value)
    {
    DataWidth = value;
    }

    string getDescription() const
    {
    return Description;
    }

    void setDescription(const string &value)
    {
    Description = value;
    }

    string getDeviceID() const
    {
    return DeviceID;
    }

    void setDeviceID(const string &value)
    {
    DeviceID = value;
    }

    bool getErrorCleared() const
    {
        return ErrorCleared;
    }

    void setErrorCleared(bool value)
    {
        ErrorCleared = value;
    }

    string getErrorDescription() const
    {
    return ErrorDescription;
    }

    void setErrorDescription(const string &value)
    {
    ErrorDescription = value;
    }

    uint32_t getExtClock() const
    {
    return ExtClock;
    }

    void setExtClock(const uint32_t &value)
    {
    ExtClock = value;
    }

    uint16_t getFamily() const
    {
    return Family;
    }

    void setFamily(const uint16_t &value)
    {
    Family = value;
    }

    uint32_t getL2CacheSize() const
    {
    return L2CacheSize;
    }

    void setL2CacheSize(const uint32_t &value)
    {
    L2CacheSize = value;
    }

    uint32_t getL2CacheSpeed() const
    {
    return L2CacheSpeed;
    }

    void setL2CacheSpeed(const uint32_t &value)
    {
    L2CacheSpeed = value;
    }

    uint32_t getL3CacheSize() const
    {
    return L3CacheSize;
    }

    void setL3CacheSize(const uint32_t &value)
    {
    L3CacheSize = value;
    }

    uint32_t getL3CacheSpeed() const
    {
    return L3CacheSpeed;
    }

    void setL3CacheSpeed(const uint32_t &value)
    {
    L3CacheSpeed = value;
    }

    uint32_t getLastErrorCode() const
    {
    return LastErrorCode;
    }

    void setLastErrorCode(const uint32_t &value)
    {
    LastErrorCode = value;
    }

    uint16_t getLevel() const
    {
    return Level;
    }

    void setLevel(const uint16_t &value)
    {
    Level = value;
    }

    uint16_t getLoadPercentage() const
    {
    return LoadPercentage;
    }

    void setLoadPercentage(const uint16_t &value)
    {
    LoadPercentage = value;
    }

    string getManufacturer() const
    {
    return Manufacturer;
    }

    void setManufacturer(const string &value)
    {
    Manufacturer = value;
    }

    uint32_t getMaxClockSpeed() const
    {
    return MaxClockSpeed;
    }

    void setMaxClockSpeed(const uint32_t &value)
    {
    MaxClockSpeed = value;
    }

    string getName() const
    {
    return Name;
    }

    void setName(const string &value)
    {
    Name = value;
    }

    uint32_t getNumberOfCores() const
    {
    return NumberOfCores;
    }

    void setNumberOfCores(const uint32_t &value)
    {
    NumberOfCores = value;
    }

    uint32_t getNumberOfEnabledCore() const
    {
    return NumberOfEnabledCore;
    }

    void setNumberOfEnabledCore(const uint32_t &value)
    {
    NumberOfEnabledCore = value;
    }

    uint32_t getNumberOfLogicalProcessors() const
    {
    return NumberOfLogicalProcessors;
    }

    void setNumberOfLogicalProcessors(const uint32_t &value)
    {
    NumberOfLogicalProcessors = value;
    }

    string getOtherFamilyDescription() const
    {
    return OtherFamilyDescription;
    }

    void setOtherFamilyDescription(const string &value)
    {
    OtherFamilyDescription = value;
    }

    string getPartNumber() const
    {
    return PartNumber;
    }

    void setPartNumber(const string &value)
    {
    PartNumber = value;
    }

    string getPNPDeviceID() const
    {
    return PNPDeviceID;
    }

    void setPNPDeviceID(const string &value)
    {
    PNPDeviceID = value;
    }

    vector<uint16_t> getPowerManagementCapabilities() const
    {
    return PowerManagementCapabilities;
    }

    void setPowerManagementCapabilities(const vector<uint16_t> &value)
    {
    PowerManagementCapabilities = value;
    }

    bool getPowerManagementSupported() const
    {
    return PowerManagementSupported;
    }

    void setPowerManagementSupported(bool value)
    {
    PowerManagementSupported = value;
    }

    string getProcessorId() const
    {
    return ProcessorId;
    }

    void setProcessorId(const string &value)
    {
    ProcessorId = value;
    }

    uint16_t getProcessorType() const
    {
    return ProcessorType;
    }

    void setProcessorType(const uint16_t &value)
    {
    ProcessorType = value;
    }

    uint16_t getRevision() const
    {
    return Revision;
    }

    void setRevision(const uint16_t &value)
    {
    Revision = value;
    }

    string getRole() const
    {
    return Role;
    }

    void setRole(const string &value)
    {
    Role = value;
    }

    bool getSecondLevelAddressTranslationExtensions() const
    {
    return SecondLevelAddressTranslationExtensions;
    }

    void setSecondLevelAddressTranslationExtensions(bool value)
    {
    SecondLevelAddressTranslationExtensions = value;
    }

    string getSerialNumber() const
    {
    return SerialNumber;
    }

    void setSerialNumber(const string &value)
    {
    SerialNumber = value;
    }

    string getSocketDesignation() const
    {
    return SocketDesignation;
    }

    void setSocketDesignation(const string &value)
    {
    SocketDesignation = value;
    }

    string getStatus() const
    {
    return Status;
    }

    void setStatus(const string &value)
    {
    Status = value;
    }

    uint16_t getStatusInfo() const
    {
    return StatusInfo;
    }

    void setStatusInfo(const uint16_t &value)
    {
    StatusInfo = value;
    }

    string getStepping() const
    {
    return Stepping;
    }

    void setStepping(const string &value)
    {
    Stepping = value;
    }

    string getSystemCreationClassName() const
    {
    return SystemCreationClassName;
    }

    void setSystemCreationClassName(const string &value)
    {
    SystemCreationClassName = value;
    }

    string getSystemName() const
    {
    return SystemName;
    }

    void setSystemName(const string &value)
    {
    SystemName = value;
    }

    uint32_t getThreadCount() const
    {
    return ThreadCount;
    }

    void setThreadCount(const uint32_t &value)
    {
    ThreadCount = value;
    }

    string getUniqueId() const
    {
    return UniqueId;
    }

    void setUniqueId(const string &value)
    {
    UniqueId = value;
    }

    bool getVirtualizationFirmwareEnabled() const
    {
    return VirtualizationFirmwareEnabled;
    }

    void setVirtualizationFirmwareEnabled(bool value)
    {
    VirtualizationFirmwareEnabled = value;
    }

    bool getVMMonitorModeExtensions() const
    {
    return VMMonitorModeExtensions;
    }

    void setVMMonitorModeExtensions(bool value)
    {
    VMMonitorModeExtensions = value;
    }

    uint32_t getVoltageCaps() const
    {
    return VoltageCaps;
    }

    void setVoltageCaps(const uint32_t &value)
    {
    VoltageCaps = value;
    }

    uint16_t getCpuStatus() const
    {
        return CpuStatus;
    }

    void setCpuStatus(const uint16_t &value)
    {
        CpuStatus = value;
    }

};


#endif
