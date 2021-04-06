#include <iostream>
#include "jni.h"

#include "lib/System.cpp"

void program(JNIEnv* env);

int main()
{
    using namespace std;

    JavaVM* jvm;    // Pointer to the JVM (Java Virtual Machine)
    JNIEnv* env;    // Pointer to native interface
    jint res;       // JNI function result

    // PARAMETERS

    auto options = new JavaVMOption[1];
    options[0].optionString = "-Djava.class.path=.";

    JavaVMInitArgs vm_args;
    vm_args.version = JNI_VERSION_10;
    vm_args.nOptions = 1;
    vm_args.options = options;
    vm_args.ignoreUnrecognized = false; // invalid options make the JVM init fail

    // Load and initialize Java VM and JNI interface

    res = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);
    delete options;

    if (res != JNI_OK) {
        cout << "Error: " << res;
        exit(EXIT_FAILURE);
    }

    // Execute the program

    program(env);

    // Unload Java VM

    jvm->DestroyJavaVM();
}

void program(JNIEnv* env)
{
    using namespace std;

    auto system = new System(env);
    cout << "Java version: " << system->getProperty("java.version") << endl;
}