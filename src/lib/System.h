#ifndef JNETPORT_LIB_SYSTEM
#define JNETPORT_LIB_SYSTEM

class System
{
    private:
        JNIEnv* _env;
        jclass _system_clz;
        jmethodID _getProperty_methodID;

    public:
        System(JNIEnv* env);
        jstring getProperty(jstring key);
        const char* getProperty(const char* key);
};

#endif // !JNETPORT_LIB_SYSTEM