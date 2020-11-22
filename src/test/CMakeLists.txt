find_package(GTest REQUIRED)

add_executable(CoreLibTests "unit-test-module.cc" "network/secure/ecdh-key-helper-tests.cc" 
"network/secure/clinet-data-encoder-tests.cc" "network/secure/base64-encoder-tests.cc")

target_link_libraries(CoreLibTests PRIVATE GTest::GTest GTest::Main)
target_link_libraries(CoreLibTests PRIVATE CoreLib)
target_include_directories(CoreLibTests PRIVATE ../core)

gtest_add_tests(TARGET CoreLibTests)
