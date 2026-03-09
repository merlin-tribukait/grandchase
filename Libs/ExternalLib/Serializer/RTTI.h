#ifndef RTTI_H
#define RTTI_H

// RTTI stub macros
#define NiDeclareRootRTTI(classname) \
    public: \
        static const char* GetClassName() { return #classname; } \
        virtual const char* GetRuntimeClassName() const { return GetClassName(); }

#define NiImplementRootRTTI(classname) \
    const char* classname::GetClassName() { return #classname; }

#define SERIALIZE_DEFINE_TAG(classname, tag) \
    static const int eTAG_USERCLASS = tag;

#define SERIALIZE_DECLARE_PUTGET(classname) \
    void Serialize(); \
    void Deserialize();

#define SmartPointer(classname) \
    using classname##Ptr = std::shared_ptr<classname>;

#endif // RTTI_H
