find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(CoreLibTests UnitTestModule.cc misc/SessionConfigurationParserTests.cc)

target_link_libraries(CoreLibTests PRIVATE ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(CoreLibTests PRIVATE CoreLib)
target_include_directories(CoreLibTests PRIVATE ${Boost_INCLUDE_DIR})
target_include_directories(CoreLibTests PRIVATE ../core)

add_test(NAME CoreLibTests COMMAND CoreLibTests)
