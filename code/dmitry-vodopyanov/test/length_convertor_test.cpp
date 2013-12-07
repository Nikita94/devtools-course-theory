// Copyright 2013 Dmitry Vodopyanov

#include <gtest/gtest.h>
#include <float.h>
#include <string>
#include "library/LengthConvertor.h"

class LengthConvertorTest : public ::testing::Test {
 protected:
    // NOTE: here you can put your init/deinit code
    // virtual void SetUp() {}
    // virtual void TearDown() {}

    LengthConvertor convertor;
};

TEST_F(LengthConvertorTest, Can_Convert_KMeters_to_Meters) {
    EXPECT_EQ(1300.000000, convertor.Convert({1.3, KMeter}, Meter).value);
}

TEST_F(LengthConvertorTest,
       Do_Throw_Exception_When_Value_Is_Larger_Than_DBL_MAX) {
    EXPECT_THROW(convertor.Convert({DBL_MAX+9999999999, KMeter}, Meter).value,
                 std::string);
}

TEST_F(LengthConvertorTest,
       Do_Throw_Exception_When_Value_Is_Less_Than_Minus_DBL_MAX) {
    EXPECT_EQ(-1.000000, convertor.Convert({-DBL_MAX, KMeter}, Meter).value,
                 std::string);
}

TEST_F(LengthConvertorTest, Can_Detect_Negative_Number) {
    EXPECT_EQ(-1.000000, convertor.Convert({-5, Inch}, Meter).value);
}
