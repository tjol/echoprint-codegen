//
// echoprint-codegen Android JNI binding
//
// Copyright (c) 2012 Thomas Jollans
// 
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:
// 
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// 

#include <jni.h>
#include "Codegen.h"

extern "C" {

JNIEXPORT jlong 
JNICALL Java_me_echoprint_Codegen_newCodegen
    (JNIEnv *env, jobject self, jfloatArray pcm, jint start_offset)
{
    float *pcm_array;
    unsigned int num_samples;

    pcm_array = env->GetFloatArrayElements (pcm, NULL);
    num_samples = (unsigned int) env->GetArrayLength (pcm);

    Codegen* codegen = new Codegen (pcm_array, num_samples, start_offset);

    env->ReleaseFloatArrayElements (pcm, pcm_array, 0);

    return (jlong) codegen;

}

JNIEXPORT void 
JNICALL Java_me_echoprint_Codegen_deleteCodegen
    (JNIEnv *env, jobject self, jlong codegen_ptr)
{
    Codegen *codegen = (Codegen*) codegen_ptr;

    delete codegen;
}

JNIEXPORT jstring 
JNICALL Java_me_echoprint_Codegen_getCodeStringInternal
    (JNIEnv *env, jobject self, jlong codegen_ptr)
{
    Codegen *codegen = (Codegen*) codegen_ptr;

    std::string code_string = codegen->getCodeString ();
    return env->NewStringUTF (code_string.c_str());
}

JNIEXPORT jint 
JNICALL Java_me_echoprint_Codegen_getNumCodesInternal
    (JNIEnv *env, jobject self, jlong codegen_ptr)
{
    Codegen *codegen = (Codegen*) codegen_ptr;
    return codegen->getNumCodes ();
}

JNIEXPORT jdouble 
JNICALL Java_me_echoprint_Codegen_getVersion
    (JNIEnv *env, jclass cls)
{
    return Codegen::getVersion ();
}

}

