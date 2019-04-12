/*
 * Copyright (C) 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <gtest/gtest.h>

#include "HalInterfaces.h"
#include "Manager.h"
#include "NeuralNetworks.h"
#include "NeuralNetworksExtensions.h"
#include "SampleDriver.h"
#include "TypeManager.h"

namespace {

using DeviceManager = ::android::nn::DeviceManager;
using SampleDriver = ::android::nn::sample_driver::SampleDriver;
using TypeManager = ::android::nn::TypeManager;

const char* kTestDriverName = "extensions-test-driver";
const char* kTestExtension1 = "vendor.test.one";
const char* kTestExtension2 = "vendor.test.two";
const char* kTestExtension3 = "vendor.test.three";

class TestDriver : public SampleDriver {
   public:
    TestDriver() : SampleDriver(kTestDriverName) {}
    ~TestDriver() override {}

    Return<void> getSupportedExtensions(getSupportedExtensions_cb cb) override {
        cb(ErrorStatus::NONE, {
                                      {.name = kTestExtension1},
                                      {.name = kTestExtension2},
                                      {.name = kTestExtension3},
                              });
        return Void();
    }

    Return<void> getCapabilities_1_2(getCapabilities_1_2_cb cb) override {
        cb(ErrorStatus::NONE, {/* Dummy zero-filled capabilities. */});
        return Void();
    }

    Return<void> getSupportedOperations_1_2(const Model&, getSupportedOperations_cb) override {
        CHECK(false) << "not implemented";
        return Void();
    }
};

class ExtensionsTest : public ::testing::Test {
   protected:
    virtual void SetUp() {
        // This is needed before we have the CPU fallback path being treated as a Device.
        // TODO(miaowang): remove once b/72506261 is fixed.
        if (DeviceManager::get()->getUseCpuOnly()) {
            GTEST_SKIP();
        }

        DeviceManager::get()->forTest_registerDevice(kTestDriverName, new TestDriver());
        // Discover extensions provided by registered devices.
        TypeManager::get()->forTest_reset();
        mDevice = getDeviceByName(kTestDriverName);
        ASSERT_NE(mDevice, nullptr);
    }

    virtual void TearDown() {
        DeviceManager::get()->forTest_reInitializeDeviceList();
        TypeManager::get()->forTest_reset();
    }

    ANeuralNetworksDevice* getDeviceByName(const std::string& name) {
        ANeuralNetworksDevice* result = nullptr;
        uint32_t numDevices = 0;
        EXPECT_EQ(ANeuralNetworks_getDeviceCount(&numDevices), ANEURALNETWORKS_NO_ERROR);
        EXPECT_GE(numDevices, 1u);
        for (uint32_t i = 0; i < numDevices; i++) {
            ANeuralNetworksDevice* device = nullptr;
            EXPECT_EQ(ANeuralNetworks_getDevice(i, &device), ANEURALNETWORKS_NO_ERROR);
            const char* buffer = nullptr;
            EXPECT_EQ(ANeuralNetworksDevice_getName(device, &buffer), ANEURALNETWORKS_NO_ERROR);
            if (name.compare(buffer) == 0) {
                EXPECT_EQ(result, nullptr) << "multiple devices named " << name;
                result = device;
            }
        }
        return result;
    }

    bool testDriverSupportsExtension(const char* extensionName) {
        bool result;
        EXPECT_EQ(ANeuralNetworksDevice_getExtensionSupport(mDevice, extensionName, &result),
                  ANEURALNETWORKS_NO_ERROR);
        return result;
    }

   private:
    ANeuralNetworksDevice* mDevice;
};

TEST_F(ExtensionsTest, DeviceReportsSupportedExtensions) {
    EXPECT_TRUE(testDriverSupportsExtension(kTestExtension1));
    EXPECT_FALSE(testDriverSupportsExtension("vendor.test.unknown"));
    EXPECT_FALSE(testDriverSupportsExtension("asdfasdfas"));
    EXPECT_TRUE(testDriverSupportsExtension(kTestExtension2));
    EXPECT_TRUE(testDriverSupportsExtension(kTestExtension3));
}

TEST_F(ExtensionsTest, TestAllowedNativeBinaries) {
    EXPECT_FALSE(TypeManager::isExtensionsUseAllowed("",
                                                     /* productEnabled= */ false,
                                                     /* isSystemApp= */ false,
                                                     /* isAppOnVendorImage= */ false,
                                                     /* isAppOnProductImage= */ false));

    EXPECT_FALSE(TypeManager::isExtensionsUseAllowed("/foobar/foo",
                                                     /* productEnabled= */ false,
                                                     /* isSystemApp= */ false,
                                                     /* isAppOnVendorImage= */ false,
                                                     /* isAppOnProductImage= */ false));

    EXPECT_TRUE(TypeManager::isExtensionsUseAllowed("/data/foo",
                                                    /* productEnabled= */ false,
                                                    /* isSystemApp= */ false,
                                                    /* isAppOnVendorImage= */ false,
                                                    /* isAppOnProductImage= */ false));

    EXPECT_TRUE(TypeManager::isExtensionsUseAllowed("/vendor/foo",
                                                    /* productEnabled= */ false,
                                                    /* isSystemApp= */ false,
                                                    /* isAppOnVendorImage= */ false,
                                                    /* isAppOnProductImage= */ false));

    EXPECT_TRUE(TypeManager::isExtensionsUseAllowed("/odm/foo",
                                                    /* productEnabled= */ false,
                                                    /* isSystemApp= */ false,
                                                    /* isAppOnVendorImage= */ false,
                                                    /* isAppOnProductImage= */ false));

    EXPECT_FALSE(TypeManager::isExtensionsUseAllowed("/system/foo",
                                                     /* productEnabled= */ false,
                                                     /* isSystemApp= */ false,
                                                     /* isAppOnVendorImage= */ false,
                                                     /* isAppOnProductImage= */ false));

    EXPECT_FALSE(TypeManager::isExtensionsUseAllowed("/product/foo",
                                                     /* productEnabled= */ false,
                                                     /* isSystemApp= */ false,
                                                     /* isAppOnVendorImage= */ false,
                                                     /* isAppOnProductImage= */ false));

    EXPECT_TRUE(TypeManager::isExtensionsUseAllowed("/product/foo",
                                                    /* productEnabled= */ true,
                                                    /* isSystemApp= */ false,
                                                    /* isAppOnVendorImage= */ false,
                                                    /* isAppOnProductImage= */ false));
}

TEST_F(ExtensionsTest, TestAllowedApps) {
    std::string app_process32 = "/system/bin/app_process32";
    std::string app_process64 = "/system/bin/app_process64";
    std::string other_binary = "/system/bin/foo";

    auto test_app_process = [](const std::string& binary) {
        // /data app
        EXPECT_TRUE(TypeManager::isExtensionsUseAllowed(binary,
                                                        /* productEnabled= */ false,
                                                        /* isSystemApp= */ false,
                                                        /* isAppOnVendorImage= */ false,
                                                        /* isAppOnProductImage= */ false));

        // /system app
        EXPECT_FALSE(TypeManager::isExtensionsUseAllowed(binary,
                                                         /* productEnabled= */ false,
                                                         /* isSystemApp= */ true,
                                                         /* isAppOnVendorImage= */ false,
                                                         /* isAppOnProductImage= */ false));

        // /vendor || /odm app
        EXPECT_TRUE(TypeManager::isExtensionsUseAllowed(binary,
                                                        /* productEnabled= */ false,
                                                        /* isSystemApp= */ true,
                                                        /* isAppOnVendorImage= */ true,
                                                        /* isAppOnProductImage= */ false));

        // /product app, disabled
        EXPECT_FALSE(TypeManager::isExtensionsUseAllowed(binary,
                                                         /* productEnabled= */ false,
                                                         /* isSystemApp= */ true,
                                                         /* isAppOnVendorImage= */ false,
                                                         /* isAppOnProductImage= */ true));

        // /product app, enabled
        EXPECT_TRUE(TypeManager::isExtensionsUseAllowed(binary,
                                                        /* productEnabled= */ true,
                                                        /* isSystemApp= */ true,
                                                        /* isAppOnVendorImage= */ false,
                                                        /* isAppOnProductImage= */ true));
    };
    test_app_process(app_process64);
    test_app_process(app_process32);

    // Test all positive cases fail if binary is not app_process32|64
    EXPECT_FALSE(TypeManager::isExtensionsUseAllowed(other_binary,
                                                     /* productEnabled= */ false,
                                                     /* isSystemApp= */ false,
                                                     /* isAppOnVendorImage= */ false,
                                                     /* isAppOnProductImage= */ false));
    EXPECT_FALSE(TypeManager::isExtensionsUseAllowed(other_binary,
                                                     /* productEnabled= */ false,
                                                     /* isSystemApp= */ true,
                                                     /* isAppOnVendorImage= */ true,
                                                     /* isAppOnProductImage= */ false));
    EXPECT_FALSE(TypeManager::isExtensionsUseAllowed(other_binary,
                                                     /* productEnabled= */ true,
                                                     /* isSystemApp= */ true,
                                                     /* isAppOnVendorImage= */ false,
                                                     /* isAppOnProductImage= */ true));
}

}  // namespace
