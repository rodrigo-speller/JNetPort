#ifndef JNETPORT_LIB_SYSTEM

#include "jni.h"

#include "System.h"

System::System(JNIEnv* env)
{
    auto system_clz = env->FindClass("java/lang/System");
    auto getProperty_methodID = env->GetStaticMethodID(system_clz, "getProperty", "(Ljava/lang/String;)Ljava/lang/String;");

    this->_env = env;
    this->_system_clz = system_clz;
    this->_getProperty_methodID = getProperty_methodID;
}

jstring System::getProperty(jstring key)
{
    auto value = reinterpret_cast<jstring>(_env->CallStaticObjectMethod(_system_clz, _getProperty_methodID, key));
    return value;
}

const char* System::getProperty(const char* key)
{
    auto value = getProperty(_env->NewStringUTF(key));
    return _env->GetStringUTFChars(value, false);
}

#endif // !JNETPORT_LIB_SYSTEM