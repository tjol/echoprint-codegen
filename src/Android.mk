LOCAL_PATH := $(call my-dir)
MY_BOOST_PATH := $(LOCAL_PATH)/../../boost

include $(CLEAR_VARS)

LOCAL_MODULE := codegen
LOCAL_CPP_EXTENSION := .cxx
LOCAL_CPP_FEATURES := rtti exceptions
LOCAL_C_INCLUDES := $(MY_BOOST_PATH)/include/boost-1_49
LOCAL_LDLIBS := -L$(MY_BOOST_PATH)/lib -lboost_system-gcc-mt-1_49 -lz

LOCAL_SRC_FILES := AudioBufferInput.cxx \
		   AudioStreamInput.cxx \
		   Base64.cxx \
		   Codegen.cxx \
		   Fingerprint.cxx \
		   MatrixUtility.cxx \
		   SubbandAnalysis.cxx \
		   Whitening.cxx \
		   Java_Codegen.cxx

include $(BUILD_SHARED_LIBRARY)
